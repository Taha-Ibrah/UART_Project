// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(278);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_UART = new VerilatedScope{this, "UART", "UART", "UART", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_UART__baud_gen_inst = new VerilatedScope{this, "UART.baud_gen_inst", "baud_gen_inst", "baud_gen", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_UART__rx_fifo_inst = new VerilatedScope{this, "UART.rx_fifo_inst", "rx_fifo_inst", "FIFO", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_UART__tx_fifo_inst = new VerilatedScope{this, "UART.tx_fifo_inst", "tx_fifo_inst", "FIFO", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_UART__uart_rx_inst = new VerilatedScope{this, "UART.uart_rx_inst", "uart_rx_inst", "UART_RX", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_UART__uart_tx_inst = new VerilatedScope{this, "UART.uart_tx_inst", "uart_tx_inst", "UART_TX", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_UART);
    __Vhier.add(__Vscopep_UART, __Vscopep_UART__baud_gen_inst);
    __Vhier.add(__Vscopep_UART, __Vscopep_UART__rx_fifo_inst);
    __Vhier.add(__Vscopep_UART, __Vscopep_UART__tx_fifo_inst);
    __Vhier.add(__Vscopep_UART, __Vscopep_UART__uart_rx_inst);
    __Vhier.add(__Vscopep_UART, __Vscopep_UART__uart_tx_inst);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("data_bus_in", &(TOP.data_bus_in), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("data_bus_out", &(TOP.data_bus_out), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rx", &(TOP.rx), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rx_empty", &(TOP.rx_empty), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rx_error", &(TOP.rx_error), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rx_rd_en", &(TOP.rx_rd_en), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("tx", &(TOP.tx), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("tx_full", &(TOP.tx_full), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("tx_wr_en", &(TOP.tx_wr_en), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("clk", &(TOP.UART__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("data_bus_in", &(TOP.UART__DOT__data_bus_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART->varInsert("data_bus_out", &(TOP.UART__DOT__data_bus_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART->varInsert("rst_n", &(TOP.UART__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("rx", &(TOP.UART__DOT__rx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("rx_busy", &(TOP.UART__DOT__rx_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("rx_byte", &(TOP.UART__DOT__rx_byte), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART->varInsert("rx_done", &(TOP.UART__DOT__rx_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("rx_empty", &(TOP.UART__DOT__rx_empty), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("rx_error", &(TOP.UART__DOT__rx_error), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("rx_fifo_full", &(TOP.UART__DOT__rx_fifo_full), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("rx_rd_en", &(TOP.UART__DOT__rx_rd_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("tick", &(TOP.UART__DOT__tick), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("tx", &(TOP.UART__DOT__tx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("tx_busy", &(TOP.UART__DOT__tx_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("tx_fifo_empty", &(TOP.UART__DOT__tx_fifo_empty), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("tx_fifo_rd_data", &(TOP.UART__DOT__tx_fifo_rd_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART->varInsert("tx_full", &(TOP.UART__DOT__tx_full), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART->varInsert("tx_rd_en", &(TOP.UART__DOT__tx_rd_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_UART->varInsert("tx_start", &(TOP.UART__DOT__tx_start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_UART->varInsert("tx_wr_en", &(TOP.UART__DOT__tx_wr_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__baud_gen_inst->varInsert("BAUD_RATE", const_cast<void*>(static_cast<const void*>(&(TOP.UART__DOT__baud_gen_inst__DOT__BAUD_RATE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART__baud_gen_inst->varInsert("CLK_FREQ", const_cast<void*>(static_cast<const void*>(&(TOP.UART__DOT__baud_gen_inst__DOT__CLK_FREQ))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART__baud_gen_inst->varInsert("CNT_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.UART__DOT__baud_gen_inst__DOT__CNT_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART__baud_gen_inst->varInsert("DIVISOR", const_cast<void*>(static_cast<const void*>(&(TOP.UART__DOT__baud_gen_inst__DOT__DIVISOR))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART__baud_gen_inst->varInsert("clk", &(TOP.UART__DOT__baud_gen_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__baud_gen_inst->varInsert("count", &(TOP.UART__DOT__baud_gen_inst__DOT__count), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,8,0);
    __Vscopep_UART__baud_gen_inst->varInsert("rst_n", &(TOP.UART__DOT__baud_gen_inst__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__baud_gen_inst->varInsert("tick", &(TOP.UART__DOT__baud_gen_inst__DOT__tick), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__rx_fifo_inst->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.UART__DOT__rx_fifo_inst__DOT__ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART__rx_fifo_inst->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.UART__DOT__rx_fifo_inst__DOT__DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART__rx_fifo_inst->varInsert("DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.UART__DOT__rx_fifo_inst__DOT__DEPTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART__rx_fifo_inst->varInsert("clk", &(TOP.UART__DOT__rx_fifo_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__rx_fifo_inst->varInsert("count", &(TOP.UART__DOT__rx_fifo_inst__DOT__count), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_UART__rx_fifo_inst->varInsert("empty", &(TOP.UART__DOT__rx_fifo_inst__DOT__empty), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_UART__rx_fifo_inst->varInsert("full", &(TOP.UART__DOT__rx_fifo_inst__DOT__full), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_UART__rx_fifo_inst->varInsert("mem", &(TOP.UART__DOT__rx_fifo_inst__DOT__mem), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,15 ,7,0);
    __Vscopep_UART__rx_fifo_inst->varInsert("rd_data", &(TOP.UART__DOT__rx_fifo_inst__DOT__rd_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,7,0);
    __Vscopep_UART__rx_fifo_inst->varInsert("rd_en", &(TOP.UART__DOT__rx_fifo_inst__DOT__rd_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__rx_fifo_inst->varInsert("rd_ptr", &(TOP.UART__DOT__rx_fifo_inst__DOT__rd_ptr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_UART__rx_fifo_inst->varInsert("rst_n", &(TOP.UART__DOT__rx_fifo_inst__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__rx_fifo_inst->varInsert("wr_data", &(TOP.UART__DOT__rx_fifo_inst__DOT__wr_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART__rx_fifo_inst->varInsert("wr_en", &(TOP.UART__DOT__rx_fifo_inst__DOT__wr_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__rx_fifo_inst->varInsert("wr_ptr", &(TOP.UART__DOT__rx_fifo_inst__DOT__wr_ptr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_UART__tx_fifo_inst->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.UART__DOT__tx_fifo_inst__DOT__ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART__tx_fifo_inst->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.UART__DOT__tx_fifo_inst__DOT__DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART__tx_fifo_inst->varInsert("DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.UART__DOT__tx_fifo_inst__DOT__DEPTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART__tx_fifo_inst->varInsert("clk", &(TOP.UART__DOT__tx_fifo_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__tx_fifo_inst->varInsert("count", &(TOP.UART__DOT__tx_fifo_inst__DOT__count), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_UART__tx_fifo_inst->varInsert("empty", &(TOP.UART__DOT__tx_fifo_inst__DOT__empty), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_UART__tx_fifo_inst->varInsert("full", &(TOP.UART__DOT__tx_fifo_inst__DOT__full), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_UART__tx_fifo_inst->varInsert("mem", &(TOP.UART__DOT__tx_fifo_inst__DOT__mem), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,15 ,7,0);
    __Vscopep_UART__tx_fifo_inst->varInsert("rd_data", &(TOP.UART__DOT__tx_fifo_inst__DOT__rd_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,7,0);
    __Vscopep_UART__tx_fifo_inst->varInsert("rd_en", &(TOP.UART__DOT__tx_fifo_inst__DOT__rd_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__tx_fifo_inst->varInsert("rd_ptr", &(TOP.UART__DOT__tx_fifo_inst__DOT__rd_ptr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_UART__tx_fifo_inst->varInsert("rst_n", &(TOP.UART__DOT__tx_fifo_inst__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__tx_fifo_inst->varInsert("wr_data", &(TOP.UART__DOT__tx_fifo_inst__DOT__wr_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART__tx_fifo_inst->varInsert("wr_en", &(TOP.UART__DOT__tx_fifo_inst__DOT__wr_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__tx_fifo_inst->varInsert("wr_ptr", &(TOP.UART__DOT__tx_fifo_inst__DOT__wr_ptr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_UART__uart_rx_inst->varInsert("bit_index", &(TOP.UART__DOT__uart_rx_inst__DOT__bit_index), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_UART__uart_rx_inst->varInsert("clk", &(TOP.UART__DOT__uart_rx_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_rx_inst->varInsert("rst_n", &(TOP.UART__DOT__uart_rx_inst__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_rx_inst->varInsert("rx", &(TOP.UART__DOT__uart_rx_inst__DOT__rx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_rx_inst->varInsert("rx_busy", &(TOP.UART__DOT__uart_rx_inst__DOT__rx_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_rx_inst->varInsert("rx_byte", &(TOP.UART__DOT__uart_rx_inst__DOT__rx_byte), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART__uart_rx_inst->varInsert("rx_done", &(TOP.UART__DOT__uart_rx_inst__DOT__rx_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_rx_inst->varInsert("rx_error", &(TOP.UART__DOT__uart_rx_inst__DOT__rx_error), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_rx_inst->varInsert("rx_prev", &(TOP.UART__DOT__uart_rx_inst__DOT__rx_prev), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_rx_inst->varInsert("rx_shift_reg", &(TOP.UART__DOT__uart_rx_inst__DOT__rx_shift_reg), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART__uart_rx_inst->varInsert("state", &(TOP.UART__DOT__uart_rx_inst__DOT__state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_UART__uart_rx_inst->varInsert("tick", &(TOP.UART__DOT__uart_rx_inst__DOT__tick), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_rx_inst->varInsert("tick_count", &(TOP.UART__DOT__uart_rx_inst__DOT__tick_count), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_UART__uart_tx_inst->varInsert("bit_index", &(TOP.UART__DOT__uart_tx_inst__DOT__bit_index), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_UART__uart_tx_inst->varInsert("clk", &(TOP.UART__DOT__uart_tx_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_tx_inst->varInsert("rst_n", &(TOP.UART__DOT__uart_tx_inst__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_tx_inst->varInsert("state", &(TOP.UART__DOT__uart_tx_inst__DOT__state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_UART__uart_tx_inst->varInsert("tick", &(TOP.UART__DOT__uart_tx_inst__DOT__tick), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_tx_inst->varInsert("tick_count", &(TOP.UART__DOT__uart_tx_inst__DOT__tick_count), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_UART__uart_tx_inst->varInsert("tx", &(TOP.UART__DOT__uart_tx_inst__DOT__tx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_tx_inst->varInsert("tx_busy", &(TOP.UART__DOT__uart_tx_inst__DOT__tx_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART__uart_tx_inst->varInsert("tx_data", &(TOP.UART__DOT__uart_tx_inst__DOT__tx_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART__uart_tx_inst->varInsert("tx_shift_reg", &(TOP.UART__DOT__uart_tx_inst__DOT__tx_shift_reg), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART__uart_tx_inst->varInsert("tx_start", &(TOP.UART__DOT__uart_tx_inst__DOT__tx_start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_UART);
    __Vhier.remove(__Vscopep_UART, __Vscopep_UART__baud_gen_inst);
    __Vhier.remove(__Vscopep_UART, __Vscopep_UART__rx_fifo_inst);
    __Vhier.remove(__Vscopep_UART, __Vscopep_UART__tx_fifo_inst);
    __Vhier.remove(__Vscopep_UART, __Vscopep_UART__uart_rx_inst);
    __Vhier.remove(__Vscopep_UART, __Vscopep_UART__uart_tx_inst);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART, __Vscopep_UART = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART__baud_gen_inst, __Vscopep_UART__baud_gen_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART__rx_fifo_inst, __Vscopep_UART__rx_fifo_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART__tx_fifo_inst, __Vscopep_UART__tx_fifo_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART__uart_rx_inst, __Vscopep_UART__uart_rx_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART__uart_tx_inst, __Vscopep_UART__uart_tx_inst = nullptr);
    // Tear down sub module instances
}
