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
    Verilated::stackCheck(262);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_UART_RX_tl = new VerilatedScope{this, "UART_RX_tl", "UART_RX_tl", "UART_RX_tl", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_UART_RX_tl__baud_gen_inst = new VerilatedScope{this, "UART_RX_tl.baud_gen_inst", "baud_gen_inst", "baud_gen", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_UART_RX_tl__uart_rx_inst = new VerilatedScope{this, "UART_RX_tl.uart_rx_inst", "uart_rx_inst", "UART_RX", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_UART_RX_tl);
    __Vhier.add(__Vscopep_UART_RX_tl, __Vscopep_UART_RX_tl__baud_gen_inst);
    __Vhier.add(__Vscopep_UART_RX_tl, __Vscopep_UART_RX_tl__uart_rx_inst);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rx", &(TOP.rx), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rx_busy", &(TOP.rx_busy), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rx_byte", &(TOP.rx_byte), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("rx_done", &(TOP.rx_done), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rx_error", &(TOP.rx_error), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl->varInsert("clk", &(TOP.UART_RX_tl__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl->varInsert("rst_n", &(TOP.UART_RX_tl__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl->varInsert("rx", &(TOP.UART_RX_tl__DOT__rx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl->varInsert("rx_busy", &(TOP.UART_RX_tl__DOT__rx_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl->varInsert("rx_byte", &(TOP.UART_RX_tl__DOT__rx_byte), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART_RX_tl->varInsert("rx_done", &(TOP.UART_RX_tl__DOT__rx_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl->varInsert("rx_error", &(TOP.UART_RX_tl__DOT__rx_error), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl->varInsert("tick", &(TOP.UART_RX_tl__DOT__tick), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__baud_gen_inst->varInsert("BAUD_RATE", const_cast<void*>(static_cast<const void*>(&(TOP.UART_RX_tl__DOT__baud_gen_inst__DOT__BAUD_RATE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART_RX_tl__baud_gen_inst->varInsert("CLK_FREQ", const_cast<void*>(static_cast<const void*>(&(TOP.UART_RX_tl__DOT__baud_gen_inst__DOT__CLK_FREQ))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART_RX_tl__baud_gen_inst->varInsert("CNT_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.UART_RX_tl__DOT__baud_gen_inst__DOT__CNT_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART_RX_tl__baud_gen_inst->varInsert("DIVISOR", const_cast<void*>(static_cast<const void*>(&(TOP.UART_RX_tl__DOT__baud_gen_inst__DOT__DIVISOR))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART_RX_tl__baud_gen_inst->varInsert("clk", &(TOP.UART_RX_tl__DOT__baud_gen_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__baud_gen_inst->varInsert("count", &(TOP.UART_RX_tl__DOT__baud_gen_inst__DOT__count), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,8,0);
    __Vscopep_UART_RX_tl__baud_gen_inst->varInsert("rst_n", &(TOP.UART_RX_tl__DOT__baud_gen_inst__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__baud_gen_inst->varInsert("tick", &(TOP.UART_RX_tl__DOT__baud_gen_inst__DOT__tick), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("bit_index", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__bit_index), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("clk", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("rst_n", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("rx", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__rx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("rx_busy", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__rx_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("rx_byte", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__rx_byte), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("rx_done", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__rx_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("rx_error", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__rx_error), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("rx_prev", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__rx_prev), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("rx_shift_reg", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__rx_shift_reg), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("state", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("tick", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__tick), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_RX_tl__uart_rx_inst->varInsert("tick_count", &(TOP.UART_RX_tl__DOT__uart_rx_inst__DOT__tick_count), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_UART_RX_tl);
    __Vhier.remove(__Vscopep_UART_RX_tl, __Vscopep_UART_RX_tl__baud_gen_inst);
    __Vhier.remove(__Vscopep_UART_RX_tl, __Vscopep_UART_RX_tl__uart_rx_inst);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART_RX_tl, __Vscopep_UART_RX_tl = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART_RX_tl__baud_gen_inst, __Vscopep_UART_RX_tl__baud_gen_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART_RX_tl__uart_rx_inst, __Vscopep_UART_RX_tl__uart_rx_inst = nullptr);
    // Tear down sub module instances
}
