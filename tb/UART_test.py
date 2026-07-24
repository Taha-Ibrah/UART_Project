import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, NextTimeStep


async def reset_dut(dut):
    # helper: run the same reset sequence in every test, avoid repeating it
    dut.rst_n.value = 0        # assert active-low reset
    dut.tx_wr_en.value = 0     # keep tx_wr_en low during reset
    dut.data_bus_in.value = 0  # clear the TX-side data bus
    dut.rx_rd_en.value = 0     # keep rx_rd_en low during reset
    dut.rx.value = 1           # rx idles high (no incoming frame yet)
    await RisingEdge(dut.clk)  # let reset take effect for at least 1 cycle
    dut.rst_n.value = 1        # release reset
    await RisingEdge(dut.clk)  # give 1 cycle for submodules to settle post-reset


async def wait_ticks(dut, n):
    # helper: wait for exactly n rising edges of the 'tick' signal
    # (not clk edges — tick edges, since that's what UART_TX/UART_RX actually count)
    count = 0
    while count < n:
        await RisingEdge(dut.clk)
        if dut.tick.value == 1:
            count += 1


async def loopback_clk(dut):
    # helper: continuously mirror the tx pin onto the rx pin, every clock edge.
    # This is what makes the top-level UART talk to itself — tx shifts a byte
    # out serially, and this coroutine feeds that exact same serial stream
    # straight into rx, so UART_RX inside the DUT reassembles what UART_TX sent.
    while True:
        await RisingEdge(dut.clk)
        await ReadOnly()           # let tx settle this cycle before sampling it
        tx_val = dut.tx.value      # ReadOnly forbids writes — just read here
        await NextTimeStep()       # move into a writable phase before driving rx
        dut.rx.value = tx_val


# WHAT THIS TESTBENCH PROVES: the whole buffered UART pipeline works end to end —
# push a byte into the TX FIFO, it drains into UART_TX, shifts out on tx, loops
# back onto rx, UART_RX reassembles it, and it lands in the RX FIFO ready to pop —
# not just that TX or RX work in isolation (already covered by their own testbenches).


@cocotb.test()
async def test_idle_state(dut):
    # GOAL: verify the whole module idles cleanly before anything is pushed in —
    # tx sits high, both FIFOs report empty/not-full, no framing error.
    # This is the baseline sanity check — if the top-level doesn't idle correctly,
    # nothing downstream (the loopback framing test) can be trusted either.

    clock = Clock(dut.clk, 20, units="ns")   # 20ns period = 50MHz, matches CLK_FREQ
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # nothing has been pushed yet — check idle line level and FIFO status flags
    assert dut.tx.value == 1, "tx should idle high"
    assert dut.tx_full.value == 0, "tx_full should be low — TX FIFO starts empty"
    assert dut.rx_empty.value == 1, "rx_empty should be high — RX FIFO starts empty"
    assert dut.rx_error.value == 0, "rx_error should be low when idle"

# WHAT THIS TEST PROVES: UART starts in a correct, known resting state — line high,
# both queues empty, no spurious error — before any byte has ever been pushed.


@cocotb.test()
async def test_loopback_single_byte(dut):
    # GOAL: push one byte into the TX FIFO, let it drain out through UART_TX,
    # loop tx back onto rx, let UART_RX reassemble it into the RX FIFO, then pop
    # it back out and confirm it matches what was originally pushed in.
    # This is the main functional test — proves the FIFOs and both state machines
    # are wired together correctly, not just that each piece works alone.

    clock = Clock(dut.clk, 20, units="ns")
    cocotb.start_soon(clock.start())
    cocotb.start_soon(loopback_clk(dut))  # start mirroring tx -> rx immediately

    await reset_dut(dut)

    test_byte = 0b10100101   # arbitrary test pattern, easy to eyeball LSB-first order

    # push the byte into the TX FIFO with a single-cycle wr_en pulse
    dut.data_bus_in.value = test_byte
    dut.tx_wr_en.value = 1
    await RisingEdge(dut.clk)
    dut.tx_wr_en.value = 0     # tx_wr_en must only be a 1-cycle pulse, not held high

    # give the glue logic one more cycle to notice the FIFO is non-empty and
    # launch tx_start into UART_TX (tx_full/tx_start are registered/combinational
    # off of FIFO state, so allow settling before we start counting bit periods)
    await RisingEdge(dut.clk)

    # wait out the full 10-bit-period frame (1 start + 8 data + 1 stop) as it
    # shifts out of UART_TX, loops back through rx, and UART_RX reassembles it.
    # 16 ticks per bit period, 10 bit periods total.
    for _ in range(10):
        await wait_ticks(dut, 16)

    # UART_RX's rx_done pulse (which pushes into the RX FIFO) and the FIFO's
    # own registered empty flag both need a settling edge before we trust them
    await RisingEdge(dut.clk)

    assert dut.rx_error.value == 0, "rx_error should stay low for a valid frame"
    assert dut.rx_empty.value == 0, "rx_empty should go low once the byte lands in the RX FIFO"

    # pop the byte back out with a single-cycle rd_en pulse
    received_byte = int(dut.data_bus_out.value)
    dut.rx_rd_en.value = 1
    await RisingEdge(dut.clk)
    dut.rx_rd_en.value = 0     # rx_rd_en must only be a 1-cycle pulse, not held high

    assert received_byte == test_byte, \
        f"loopback mismatch: pushed {test_byte:#010b}, popped {received_byte:#010b}"

    # after the single pop, the RX FIFO should be empty again
    await RisingEdge(dut.clk)
    assert dut.rx_empty.value == 1, "rx_empty should go back high after popping the only byte"

# WHAT THIS TEST PROVES: a byte survives the entire round trip — TX FIFO push,
# UART_TX framing, the serial line, UART_RX reassembly, and RX FIFO pop — landing
# back exactly as it started, with no framing error along the way.


@cocotb.test()
async def test_tx_full_backpressure(dut):
    # GOAL: push bytes into the TX FIFO faster than UART_TX can drain them (the
    # whole reason the FIFO exists — see FIFO.sv's header) and confirm tx_full
    # correctly asserts once the queue's 16 slots are exhausted, rather than
    # silently dropping or corrupting data.

    clock = Clock(dut.clk, 20, units="ns")
    cocotb.start_soon(clock.start())
    cocotb.start_soon(loopback_clk(dut))

    await reset_dut(dut)

    # push bytes back-to-back, one per cycle. UART_TX only drains 1 byte per
    # ~10 bit periods (very slow relative to clk), so the FIFO's 16 slots fill
    # almost immediately — DEPTH=16 in both FIFO instances in UART.sv.
    #
    # NOTE: right after reset, UART.sv's drain glue (tx_start = !tx_busy &&
    # !tx_fifo_empty) fires the instant the FIRST byte lands, one cycle before
    # tx_busy has a chance to register high. That one byte gets popped straight
    # back out to UART_TX almost immediately, so pushing 16 bytes only leaves
    # 15 sitting in the FIFO — we push 17 to actually drive count up to 16 and
    # see tx_full assert.
    for i in range(17):
        assert dut.tx_full.value == 0, f"tx_full asserted early, after only {i} pushes"
        dut.data_bus_in.value = i
        dut.tx_wr_en.value = 1
        await RisingEdge(dut.clk)
    dut.tx_wr_en.value = 0

    # one more settling edge for the FIFO's registered 'full' flag (driven off
    # its internal 'count' register) to reflect the last push
    await RisingEdge(dut.clk)

    assert dut.tx_full.value == 1, "tx_full should assert once the TX FIFO is genuinely full"

# WHAT THIS TEST PROVES: the TX FIFO's full flag is a reliable signal the caller
# can check before pushing — it doesn't lag or fail to assert once genuinely full,
# which is exactly the overrun protection the FIFO was added to provide.
