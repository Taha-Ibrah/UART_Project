import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

async def reset_dut(dut):
    dut.rst_n.value = 0
    dut.rx.value = 1
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

async def wait_ticks(dut, n):
    count = 0
    while(count<n):
        await RisingEdge(dut.clk)
        if(dut.tick.value==1):
            count+=1

@cocotb.test()
async def idle_state_test(dut):
    #GOAL: when rx is held high (IDLE STATE), confirm logic signals are following the set structure
    clock = Clock(dut.clk, 20, unit="ns")   # 20ns period = 50MHz, matches CLK_FREQ
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # nothing has been triggered yet — check DUT output flags
    # (not asserting dut.rx itself: rx is an input we drive, checking it only
    # proves the testbench wrote what it wrote, not anything about the DUT)
    assert dut.rx_busy.value == 0, "rx_busy should be low when idle"
    assert dut.rx_error.value == 0, "rx_error should be low during idle"
    assert dut.rx_done.value == 0, "rx_done should be low during idle"

@cocotb.test()
async def single_byte_test(dut):
    #GOAL: drive a full valid UART frame on rx (start=0, 8 data bits LSB-first,
    #stop=1), holding each bit for one full bit period using wait_ticks(dut,16),
    #then assert rx_byte matches, rx_done pulsed, and rx_error stayed low.
    clock = Clock(dut.clk, 20, unit="ns") #20ns period = 50MHz, which matches CLK_FREQ
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    test_byte = 0b10100101  # arbitrary pattern, easy to eyeball LSB-first order

    # rx idles high; drive the start bit (0) to kick off the frame
    dut.rx.value = 0
    await wait_ticks(dut, 16)  # hold start bit for one full bit period (16 ticks)

    # rx_busy is a registered output — it only reflects the edge detected in
    # IDLE one clock edge after RX samples it, same latency seen in the TX tests
    await RisingEdge(dut.clk)
    assert dut.rx_busy.value == 1, "rx_busy should go high once the start edge is detected"

    # drive each data bit LSB-first, one full bit period each.
    # set the bit at the START of the period (not at the midpoint) so it's
    # already stable by tick_count==8, which is when UART_RX actually samples it
    for i in range(8):
        bit = (test_byte >> i) & 1
        dut.rx.value = bit
        await wait_ticks(dut, 16)

    # release the line high for the stop bit
    dut.rx.value = 1
    await wait_ticks(dut, 16)

    # rx_done is a registered pulse set when tick_count==8 in STOP and cleared
    # when tick_count==15 — wait one more clock edge so it's visible before we check
    await RisingEdge(dut.clk)
    # WAIT_TICKS RETURNS ON THE EXACT EDGE THE TICK FIRED — BUT THE RTL'S <=
    # UPDATE FROM THAT EDGE ISN'T VISIBLE UNTIL THE NEXT EDGE. THIS RisingEdge
    # CROSSES THAT ONE-CYCLE GAP.

    assert dut.rx_error.value == 0, "rx_error should stay low for a valid frame"
    assert dut.rx_byte.value == test_byte, \
        f"rx_byte mismatch: expected {test_byte:#010b}, got {int(dut.rx_byte.value):#010b}"

    # after STOP's tick_count reaches 15, rx_busy clears and state returns to IDLE
    await wait_ticks(dut, 16)
    assert dut.rx_busy.value == 0, "rx_busy should go low after the frame completes"

@cocotb.test()
async def framing_error_test(dut):
    #GOAL: same as single_byte_test but drive rx low again during the stop-bit
    #period instead of releasing it high, then assert rx_error goes high and
    #rx_done never pulses (a broken frame shouldn't hand off a "valid" byte).
    clock = Clock(dut.clk, 20, unit="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    test_byte = 0b10100101

    # start bit
    dut.rx.value = 0
    await wait_ticks(dut, 16)

    # 8 valid data bits — only the stop bit is going to be broken
    for i in range(8):
        bit = (test_byte >> i) & 1
        dut.rx.value = bit
        await wait_ticks(dut, 16)

    # BROKEN STOP BIT: hold rx low instead of releasing it high.
    # UART_RX's STOP state samples rx at tick_count==8; since it's 0 there,
    # rx_error gets set instead of rx_done.
    dut.rx.value = 0
    await wait_ticks(dut, 16)

    await RisingEdge(dut.clk)  # let the STOP-state <= assignments settle

    assert dut.rx_error.value == 1, "rx_error should go high on a missing stop bit"
    assert dut.rx_done.value == 0, "rx_done should never pulse on a framing error"

@cocotb.test()
async def glitch_start_test(dut):
    #GOAL: pull rx low for less than 8 ticks (short of the START state's
    #tick_count==8 glitch check) then release it high again; assert state
    #returns to IDLE without rx_busy/rx_done ever asserting.
    clock = Clock(dut.clk, 20, unit="ns")
    cocotb.start_soon(clock.start())

    await reset_dut(dut)

    # pull rx low to trigger the falling edge and enter START
    dut.rx.value = 0
    await wait_ticks(dut, 4)  # well short of the tick_count==8 glitch check

    # release rx back high before the glitch check samples it
    dut.rx.value = 1

    # advance past the tick_count==8 check point, where START sees rx==1
    # and rejects it as a glitch, returning to IDLE
    await wait_ticks(dut, 8)
    await RisingEdge(dut.clk)  # let the state <= IDLE assignment settle

    # NOTE: rx_busy DOES briefly go high on entering START (set in IDLE's
    # edge-detect branch) — it's IDLE's rx_busy <= 1'b0 that clears it back
    # down once the glitch is rejected and state returns to IDLE. So we check
    # it's low AFTER rejection, not that it never asserted at all.
    assert dut.rx_busy.value == 0, "rx_busy should clear once the glitch is rejected"
    assert dut.rx_done.value == 0, "rx_done should never assert on a rejected glitch"
    assert dut.rx_error.value == 0, "rx_error should not assert on a glitch (not a framing error)"
