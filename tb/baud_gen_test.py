import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

@cocotb.test()
async def test_reset(dut):
    #Create clock object: 20ns period = 50MHz, matches Clock Frequency Parameter
    clock = Clock(dut.clk, 20, unit = "ns")
    cocotb.start_soon(clock.start()) #lauch clock as background task
    #Assert reset value (active-low, so 0 = reset asserted)
    dut.rst_n.value = 0
    await RisingEdge(dut.clk) #let reset take effect for at last one clock edge

    #while reset is asserted, tick should be forced low
    assert dut.tick.value == 0, "tick should be 0 during reset"

    #deassert reset
    dut.rst_n.value = 1
    await RisingEdge(dut.clk) #give one cycle for the module to resume normal operation

    #right after reset releases, tick should still be low
    #(takes DIVISOR cycles before the first tick fires)

    assert dut.tick.value == 0, "tick should not fire immediately after reset"
    #ONCE RESET IS RELEASED, 325 CYCLES ARE NEEDED TO REACH THE FIRST TICK

@cocotb.test()
async def test_tick_period(dut): #####verify time between two ticks is exactly 325 cycles
    clock = Clock(dut.clk, 20, unit="ns")
    cocotb.start_soon(clock.start())

    #reset sequence: assert reset, wait a cycle, then release it
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    #wait for first tick to appear
    #keep advancing one clock cycle as long as tick is still 0
    while dut.tick.value == 0:
        await RisingEdge(dut.clk)
    
    #at this point: dut.tick.value == 1
    #start counting cycles from here to measure the period to the NEXT tick
    cycle_count = 1

    #move past this current tick cycle first, so we don't immediately
    #re-detect the same tick pulse in the loop below
    await RisingEdge(dut.clk)

    #keep counting cycles until tick fires again
    while dut.tick.value ==0:
        cycle_count +=1    #count this cycle since tick hasn't fired yet
        await RisingEdge(dut.clk) #advance to next cycle

    #cycle_count now holds the number of cycles between the two ticks
    #This should equal DIVISOR (325 for 50MHz/9600baud/16x)
    assert cycle_count == 325, f"expected 325 cycles between ticks, got {cycle_count}"


@cocotb.test()
async def test_tick_width(dut): #####verify that tick is exactly one cycle wide
    #create a clock object: 20ns period = 50MHz
    clock = Clock(dut.clk, 20, unit="ns")
    cocotb.start_soon(clock.start()) #launch clock as background task

    # reset sequence
    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    #wait for tick to go high
    #keep advancing while tick is still 0
    while dut.tick.value == 0:
        await RisingEdge(dut.clk)

    #tick is high on this current cycle (loop just exited because tick==1)
    #advance exactly one more cycle to check if it drops back to 0
    await RisingEdge(dut.clk)

    #if tick is still 1 here, the pulse lasted more than 1 cycle - bug detected
    assert dut.tick.value == 0, "tick should be low again after 1 cycle"


#test_reset: proves safe startup
#test_tick_period: proves timing accuracy
#test_tick_width: proves pulse shape