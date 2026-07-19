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
    Verilated::stackCheck(258);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_UART_TX_tl = new VerilatedScope{this, "UART_TX_tl", "UART_TX_tl", "UART_TX_tl", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_UART_TX_tl__baud_gen_inst = new VerilatedScope{this, "UART_TX_tl.baud_gen_inst", "baud_gen_inst", "baud_gen", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_UART_TX_tl__uart_tx_inst = new VerilatedScope{this, "UART_TX_tl.uart_tx_inst", "uart_tx_inst", "UART_TX", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_UART_TX_tl);
    __Vhier.add(__Vscopep_UART_TX_tl, __Vscopep_UART_TX_tl__baud_gen_inst);
    __Vhier.add(__Vscopep_UART_TX_tl, __Vscopep_UART_TX_tl__uart_tx_inst);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("tx", &(TOP.tx), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("tx_busy", &(TOP.tx_busy), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("tx_data", &(TOP.tx_data), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("tx_start", &(TOP.tx_start), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl->varInsert("clk", &(TOP.UART_TX_tl__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl->varInsert("rst_n", &(TOP.UART_TX_tl__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl->varInsert("tick", &(TOP.UART_TX_tl__DOT__tick), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl->varInsert("tx", &(TOP.UART_TX_tl__DOT__tx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl->varInsert("tx_busy", &(TOP.UART_TX_tl__DOT__tx_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl->varInsert("tx_data", &(TOP.UART_TX_tl__DOT__tx_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART_TX_tl->varInsert("tx_start", &(TOP.UART_TX_tl__DOT__tx_start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl__baud_gen_inst->varInsert("BAUD_RATE", const_cast<void*>(static_cast<const void*>(&(TOP.UART_TX_tl__DOT__baud_gen_inst__DOT__BAUD_RATE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART_TX_tl__baud_gen_inst->varInsert("CLK_FREQ", const_cast<void*>(static_cast<const void*>(&(TOP.UART_TX_tl__DOT__baud_gen_inst__DOT__CLK_FREQ))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART_TX_tl__baud_gen_inst->varInsert("CNT_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.UART_TX_tl__DOT__baud_gen_inst__DOT__CNT_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART_TX_tl__baud_gen_inst->varInsert("DIVISOR", const_cast<void*>(static_cast<const void*>(&(TOP.UART_TX_tl__DOT__baud_gen_inst__DOT__DIVISOR))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_UART_TX_tl__baud_gen_inst->varInsert("clk", &(TOP.UART_TX_tl__DOT__baud_gen_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl__baud_gen_inst->varInsert("count", &(TOP.UART_TX_tl__DOT__baud_gen_inst__DOT__count), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,8,0);
    __Vscopep_UART_TX_tl__baud_gen_inst->varInsert("rst_n", &(TOP.UART_TX_tl__DOT__baud_gen_inst__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl__baud_gen_inst->varInsert("tick", &(TOP.UART_TX_tl__DOT__baud_gen_inst__DOT__tick), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("bit_index", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__bit_index), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("clk", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("rst_n", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("state", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("tick", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__tick), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("tick_count", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__tick_count), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("tx", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__tx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("tx_busy", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__tx_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("tx_data", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__tx_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("tx_shift_reg", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__tx_shift_reg), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_UART_TX_tl__uart_tx_inst->varInsert("tx_start", &(TOP.UART_TX_tl__DOT__uart_tx_inst__DOT__tx_start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_UART_TX_tl);
    __Vhier.remove(__Vscopep_UART_TX_tl, __Vscopep_UART_TX_tl__baud_gen_inst);
    __Vhier.remove(__Vscopep_UART_TX_tl, __Vscopep_UART_TX_tl__uart_tx_inst);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART_TX_tl, __Vscopep_UART_TX_tl = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART_TX_tl__baud_gen_inst, __Vscopep_UART_TX_tl__baud_gen_inst = nullptr);
    VL_DO_CLEAR(delete __Vscopep_UART_TX_tl__uart_tx_inst, __Vscopep_UART_TX_tl__uart_tx_inst = nullptr);
    // Tear down sub module instances
}
