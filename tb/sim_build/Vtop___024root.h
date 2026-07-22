// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(rx,0,0);
    VL_OUT8(rx_byte,7,0);
    VL_OUT8(rx_done,0,0);
    VL_OUT8(rx_error,0,0);
    VL_OUT8(rx_busy,0,0);
    CData/*0:0*/ UART_RX_tl__DOT__clk;
    CData/*0:0*/ UART_RX_tl__DOT__rst_n;
    CData/*0:0*/ UART_RX_tl__DOT__rx;
    CData/*7:0*/ UART_RX_tl__DOT__rx_byte;
    CData/*0:0*/ UART_RX_tl__DOT__rx_done;
    CData/*0:0*/ UART_RX_tl__DOT__rx_error;
    CData/*0:0*/ UART_RX_tl__DOT__rx_busy;
    CData/*0:0*/ UART_RX_tl__DOT__tick;
    CData/*0:0*/ UART_RX_tl__DOT__baud_gen_inst__DOT__clk;
    CData/*0:0*/ UART_RX_tl__DOT__baud_gen_inst__DOT__rst_n;
    CData/*0:0*/ UART_RX_tl__DOT__baud_gen_inst__DOT__tick;
    CData/*0:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__clk;
    CData/*0:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__rst_n;
    CData/*0:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__tick;
    CData/*0:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__rx;
    CData/*7:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__rx_byte;
    CData/*0:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__rx_done;
    CData/*0:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__rx_error;
    CData/*0:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__rx_busy;
    CData/*1:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__state;
    CData/*3:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__tick_count;
    CData/*2:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__bit_index;
    CData/*7:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__rx_shift_reg;
    CData/*0:0*/ UART_RX_tl__DOT__uart_rx_inst__DOT__rx_prev;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__UART_RX_tl__DOT__baud_gen_inst__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__UART_RX_tl__DOT__uart_rx_inst__DOT__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    SData/*8:0*/ UART_RX_tl__DOT__baud_gen_inst__DOT__count;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ UART_RX_tl__DOT__baud_gen_inst__DOT__CLK_FREQ = 0x02faf080U;
    static constexpr IData/*31:0*/ UART_RX_tl__DOT__baud_gen_inst__DOT__BAUD_RATE = 0x00002580U;
    static constexpr IData/*31:0*/ UART_RX_tl__DOT__baud_gen_inst__DOT__DIVISOR = 0x00000145U;
    static constexpr IData/*31:0*/ UART_RX_tl__DOT__baud_gen_inst__DOT__CNT_WIDTH = 9U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
