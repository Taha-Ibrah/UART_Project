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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(data_bus_in,7,0);
        VL_IN8(tx_wr_en,0,0);
        VL_OUT8(tx_full,0,0);
        VL_OUT8(data_bus_out,7,0);
        VL_IN8(rx_rd_en,0,0);
        VL_OUT8(rx_empty,0,0);
        VL_OUT8(rx_error,0,0);
        VL_IN8(rx,0,0);
        VL_OUT8(tx,0,0);
        CData/*0:0*/ UART__DOT__clk;
        CData/*0:0*/ UART__DOT__rst_n;
        CData/*7:0*/ UART__DOT__data_bus_in;
        CData/*0:0*/ UART__DOT__tx_wr_en;
        CData/*0:0*/ UART__DOT__tx_full;
        CData/*7:0*/ UART__DOT__data_bus_out;
        CData/*0:0*/ UART__DOT__rx_rd_en;
        CData/*0:0*/ UART__DOT__rx_empty;
        CData/*0:0*/ UART__DOT__rx_error;
        CData/*0:0*/ UART__DOT__rx;
        CData/*0:0*/ UART__DOT__tx;
        CData/*0:0*/ UART__DOT__tick;
        CData/*7:0*/ UART__DOT__tx_fifo_rd_data;
        CData/*0:0*/ UART__DOT__tx_fifo_empty;
        CData/*0:0*/ UART__DOT__tx_rd_en;
        CData/*0:0*/ UART__DOT__tx_busy;
        CData/*0:0*/ UART__DOT__tx_start;
        CData/*7:0*/ UART__DOT__rx_byte;
        CData/*0:0*/ UART__DOT__rx_done;
        CData/*0:0*/ UART__DOT__rx_busy;
        CData/*0:0*/ UART__DOT__rx_fifo_full;
        CData/*0:0*/ UART__DOT__baud_gen_inst__DOT__clk;
        CData/*0:0*/ UART__DOT__baud_gen_inst__DOT__rst_n;
        CData/*0:0*/ UART__DOT__baud_gen_inst__DOT__tick;
        CData/*0:0*/ UART__DOT__tx_fifo_inst__DOT__clk;
        CData/*0:0*/ UART__DOT__tx_fifo_inst__DOT__rst_n;
        CData/*0:0*/ UART__DOT__tx_fifo_inst__DOT__wr_en;
        CData/*7:0*/ UART__DOT__tx_fifo_inst__DOT__wr_data;
        CData/*0:0*/ UART__DOT__tx_fifo_inst__DOT__full;
        CData/*0:0*/ UART__DOT__tx_fifo_inst__DOT__rd_en;
        CData/*7:0*/ UART__DOT__tx_fifo_inst__DOT__rd_data;
        CData/*0:0*/ UART__DOT__tx_fifo_inst__DOT__empty;
        CData/*3:0*/ UART__DOT__tx_fifo_inst__DOT__wr_ptr;
        CData/*3:0*/ UART__DOT__tx_fifo_inst__DOT__rd_ptr;
        CData/*4:0*/ UART__DOT__tx_fifo_inst__DOT__count;
        CData/*0:0*/ UART__DOT__uart_tx_inst__DOT__clk;
        CData/*0:0*/ UART__DOT__uart_tx_inst__DOT__rst_n;
        CData/*0:0*/ UART__DOT__uart_tx_inst__DOT__tick;
        CData/*7:0*/ UART__DOT__uart_tx_inst__DOT__tx_data;
        CData/*0:0*/ UART__DOT__uart_tx_inst__DOT__tx_start;
        CData/*0:0*/ UART__DOT__uart_tx_inst__DOT__tx_busy;
        CData/*0:0*/ UART__DOT__uart_tx_inst__DOT__tx;
        CData/*1:0*/ UART__DOT__uart_tx_inst__DOT__state;
        CData/*3:0*/ UART__DOT__uart_tx_inst__DOT__tick_count;
        CData/*2:0*/ UART__DOT__uart_tx_inst__DOT__bit_index;
        CData/*7:0*/ UART__DOT__uart_tx_inst__DOT__tx_shift_reg;
        CData/*0:0*/ UART__DOT__uart_rx_inst__DOT__clk;
        CData/*0:0*/ UART__DOT__uart_rx_inst__DOT__rst_n;
        CData/*0:0*/ UART__DOT__uart_rx_inst__DOT__tick;
        CData/*0:0*/ UART__DOT__uart_rx_inst__DOT__rx;
        CData/*7:0*/ UART__DOT__uart_rx_inst__DOT__rx_byte;
        CData/*0:0*/ UART__DOT__uart_rx_inst__DOT__rx_done;
        CData/*0:0*/ UART__DOT__uart_rx_inst__DOT__rx_error;
    };
    struct {
        CData/*0:0*/ UART__DOT__uart_rx_inst__DOT__rx_busy;
        CData/*1:0*/ UART__DOT__uart_rx_inst__DOT__state;
        CData/*3:0*/ UART__DOT__uart_rx_inst__DOT__tick_count;
        CData/*2:0*/ UART__DOT__uart_rx_inst__DOT__bit_index;
        CData/*7:0*/ UART__DOT__uart_rx_inst__DOT__rx_shift_reg;
        CData/*0:0*/ UART__DOT__uart_rx_inst__DOT__rx_prev;
        CData/*0:0*/ UART__DOT__rx_fifo_inst__DOT__clk;
        CData/*0:0*/ UART__DOT__rx_fifo_inst__DOT__rst_n;
        CData/*0:0*/ UART__DOT__rx_fifo_inst__DOT__wr_en;
        CData/*7:0*/ UART__DOT__rx_fifo_inst__DOT__wr_data;
        CData/*0:0*/ UART__DOT__rx_fifo_inst__DOT__full;
        CData/*0:0*/ UART__DOT__rx_fifo_inst__DOT__rd_en;
        CData/*7:0*/ UART__DOT__rx_fifo_inst__DOT__rd_data;
        CData/*0:0*/ UART__DOT__rx_fifo_inst__DOT__empty;
        CData/*3:0*/ UART__DOT__rx_fifo_inst__DOT__wr_ptr;
        CData/*3:0*/ UART__DOT__rx_fifo_inst__DOT__rd_ptr;
        CData/*4:0*/ UART__DOT__rx_fifo_inst__DOT__count;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__UART__DOT__baud_gen_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__UART__DOT__tx_fifo_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__UART__DOT__uart_tx_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__UART__DOT__uart_rx_inst__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__UART__DOT__rx_fifo_inst__DOT__clk__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*8:0*/ UART__DOT__baud_gen_inst__DOT__count;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*7:0*/, 16> UART__DOT__tx_fifo_inst__DOT__mem;
        VlUnpacked<CData/*7:0*/, 16> UART__DOT__rx_fifo_inst__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ UART__DOT__baud_gen_inst__DOT__CLK_FREQ = 0x02faf080U;
    static constexpr IData/*31:0*/ UART__DOT__baud_gen_inst__DOT__BAUD_RATE = 0x00002580U;
    static constexpr IData/*31:0*/ UART__DOT__baud_gen_inst__DOT__DIVISOR = 0x00000145U;
    static constexpr IData/*31:0*/ UART__DOT__baud_gen_inst__DOT__CNT_WIDTH = 9U;
    static constexpr IData/*31:0*/ UART__DOT__tx_fifo_inst__DOT__DATA_WIDTH = 8U;
    static constexpr IData/*31:0*/ UART__DOT__tx_fifo_inst__DOT__DEPTH = 0x00000010U;
    static constexpr IData/*31:0*/ UART__DOT__tx_fifo_inst__DOT__ADDR_WIDTH = 4U;
    static constexpr IData/*31:0*/ UART__DOT__rx_fifo_inst__DOT__DATA_WIDTH = 8U;
    static constexpr IData/*31:0*/ UART__DOT__rx_fifo_inst__DOT__DEPTH = 0x00000010U;
    static constexpr IData/*31:0*/ UART__DOT__rx_fifo_inst__DOT__ADDR_WIDTH = 4U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
