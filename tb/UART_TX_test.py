import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


async def reset_dut(dut):
    # helper: run the same reset sequence in every test, avoid repeating it
    dut.rst_n.value = 0        # assert active-low reset
    dut.tx_start.value = 0     # keep tx_start low during reset
    dut.tx_data.value = 0      # clear data bus
    await RisingEdge(dut.clk)  # let reset take effect for at least 1 cycle
    dut.rst_n.value = 1        # release reset
    await RisingEdge(dut.clk)  # give 1 cycle for module to settle post-reset


async def wait_ticks(dut, n):
    # helper: wait for exactly n rising edges of the 'tick' signal
    # (not clk edges — tick edges, since that's what UART_TX actually counts)
    count = 0
    while count < n:
        await RisingEdge(dut.clk)
        if dut.tick.value == 1:
            count += 1


@cocotb.test()
async def test_idle_state(dut):
    # GOAL: verify tx sits high and tx_busy is low before any transmission starts
    # This is the baseline sanity check — if TX doesn't idle correctly, nothing
    # downstream (framing, timing) can be trusted either.

    clock = Clock(dut.clk, 20, units="ns")   # 20ns period = 50MHz, matches CLK_FREQ
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # nothing has been triggered yet — check idle line level and busy flag
    assert dut.tx.value == 1, "tx should idle high"
    assert dut.tx_busy.value == 0, "tx_busy should be low when idle"

# WHAT THIS TEST PROVES: TX starts in a correct, known resting state — line high,
# not busy — before any byte has ever been sent.


@cocotb.test()
async def test_tx_single_byte(dut):
    # GOAL: send one byte, sample tx mid-bit for every bit period,
    # and check the full frame matches: start(0) -> 8 data bits LSB-first -> stop(1)
    # This is the main functional test — proves TX implements UART framing correctly,
    # not just that it idles correctly.

    clock = Clock(dut.clk, 20, units="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    test_byte = 0b10100101   # arbitrary test pattern, easy to eyeball LSB-first order

    # drive tx_data and pulse tx_start for exactly 1 cycle
    dut.tx_data.value = test_byte
    dut.tx_start.value = 1
    await RisingEdge(dut.clk)
    dut.tx_start.value = 0    # tx_start must only be a 1-cycle pulse, not held high

    # tx_busy is a registered output, so it only reflects tx_start one clock
    # edge after the edge that sampled it — wait one more cycle before checking
    await RisingEdge(dut.clk)

    # busy should now be asserted — TX has latched the byte and started sending
    assert dut.tx_busy.value == 1, "tx_busy should go high once transmission starts"

    sampled_bits = []  # will hold each bit we observe, in transmission order

    # there are 10 bit periods total: 1 start + 8 data + 1 stop
    for bit_period in range(10):
        # wait 8 ticks to land roughly in the middle of this bit period
        # (16 ticks per bit period, so tick 8 is the midpoint)
        await wait_ticks(dut, 8)
        sampled_bits.append(int(dut.tx.value))

        # wait the remaining 8 ticks to reach the start of the next bit period
        await wait_ticks(dut, 8)

    # build the expected frame: start bit (0), then LSB-first data bits, then stop bit (1)
    expected_bits = [0]  # start bit = 0, stop bit = 1 --> standard UART convention
    for i in range(8):
        expected_bits.append((test_byte >> i) & 1)  # bit i of test_byte, LSB first
    expected_bits.append(1)  # stop bit

    assert sampled_bits == expected_bits, \
        f"frame mismatch: expected {expected_bits}, got {sampled_bits}"

    # tx_busy is a registered output: it only clears on the clock edge after
    # the one where tick_count hits 15 in STOP, so wait one more cycle
    await RisingEdge(dut.clk)

    # after the stop bit completes, tx_busy should drop back to 0
    assert dut.tx_busy.value == 0, "tx_busy should go low after transmission completes"

# WHAT THIS TEST PROVES: the entire framing sequence is correct for a real byte —
# start bit low, all 8 data bits in correct LSB-first order matching the input,
# stop bit high — and tx_busy correctly brackets the whole transmission.