// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_triggers_vec__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.UART__DOT__rx_busy = vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_busy;
    vlSelfRef.UART__DOT__data_bus_in = vlSelfRef.data_bus_in;
    vlSelfRef.UART__DOT__tx_wr_en = vlSelfRef.tx_wr_en;
    vlSelfRef.UART__DOT__rx_rd_en = vlSelfRef.rx_rd_en;
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full = 
        (0x10U == (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count));
    vlSelfRef.UART__DOT__rx_error = vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_error;
    vlSelfRef.UART__DOT__rx = vlSelfRef.rx;
    vlSelfRef.UART__DOT__tx = vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx;
    vlSelfRef.UART__DOT__rx_byte = vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_byte;
    vlSelfRef.UART__DOT__rx_done = vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_done;
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full = 
        (0x10U == (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count));
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty = 
        (0U == (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count));
    vlSelfRef.UART__DOT__tick = vlSelfRef.UART__DOT__baud_gen_inst__DOT__tick;
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_data 
        = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__mem
        [vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_ptr];
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_data 
        = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__mem
        [vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_ptr];
    vlSelfRef.UART__DOT__tx_busy = vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_busy;
    vlSelfRef.UART__DOT__clk = vlSelfRef.clk;
    vlSelfRef.UART__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty = 
        (0U == (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count));
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_data 
        = vlSelfRef.UART__DOT__data_bus_in;
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_en = vlSelfRef.UART__DOT__tx_wr_en;
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_en = vlSelfRef.UART__DOT__rx_rd_en;
    vlSelfRef.UART__DOT__rx_fifo_full = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full;
    vlSelfRef.rx_error = vlSelfRef.UART__DOT__rx_error;
    vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx = vlSelfRef.UART__DOT__rx;
    vlSelfRef.tx = vlSelfRef.UART__DOT__tx;
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_data 
        = vlSelfRef.UART__DOT__rx_byte;
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_en = vlSelfRef.UART__DOT__rx_done;
    vlSelfRef.UART__DOT__tx_full = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full;
    vlSelfRef.UART__DOT__rx_empty = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty;
    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick = vlSelfRef.UART__DOT__tick;
    vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick = vlSelfRef.UART__DOT__tick;
    vlSelfRef.UART__DOT__data_bus_out = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_data;
    vlSelfRef.UART__DOT__tx_fifo_rd_data = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_data;
    vlSelfRef.UART__DOT__baud_gen_inst__DOT__clk = vlSelfRef.UART__DOT__clk;
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__clk = vlSelfRef.UART__DOT__clk;
    vlSelfRef.UART__DOT__uart_tx_inst__DOT__clk = vlSelfRef.UART__DOT__clk;
    vlSelfRef.UART__DOT__uart_rx_inst__DOT__clk = vlSelfRef.UART__DOT__clk;
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__clk = vlSelfRef.UART__DOT__clk;
    vlSelfRef.UART__DOT__baud_gen_inst__DOT__rst_n 
        = vlSelfRef.UART__DOT__rst_n;
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rst_n = vlSelfRef.UART__DOT__rst_n;
    vlSelfRef.UART__DOT__uart_tx_inst__DOT__rst_n = vlSelfRef.UART__DOT__rst_n;
    vlSelfRef.UART__DOT__uart_rx_inst__DOT__rst_n = vlSelfRef.UART__DOT__rst_n;
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rst_n = vlSelfRef.UART__DOT__rst_n;
    vlSelfRef.UART__DOT__tx_fifo_empty = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty;
    vlSelfRef.tx_full = vlSelfRef.UART__DOT__tx_full;
    vlSelfRef.rx_empty = vlSelfRef.UART__DOT__rx_empty;
    vlSelfRef.data_bus_out = vlSelfRef.UART__DOT__data_bus_out;
    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_data 
        = vlSelfRef.UART__DOT__tx_fifo_rd_data;
    vlSelfRef.UART__DOT__tx_start = (1U & (~ ((IData)(vlSelfRef.UART__DOT__tx_busy) 
                                              | (IData)(vlSelfRef.UART__DOT__tx_fifo_empty))));
    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_start 
        = vlSelfRef.UART__DOT__tx_start;
    vlSelfRef.UART__DOT__tx_rd_en = vlSelfRef.UART__DOT__tx_start;
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_en = vlSelfRef.UART__DOT__tx_rd_en;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__clk) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__UART__DOT__rx_fifo_inst__DOT__clk__0))) 
                                                      << 4U) 
                                                     | (((((IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__UART__DOT__uart_rx_inst__DOT__clk__0))) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__UART__DOT__uart_tx_inst__DOT__clk__0))) 
                                                            << 2U)) 
                                                        | ((((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__UART__DOT__tx_fifo_inst__DOT__clk__0))) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.UART__DOT__baud_gen_inst__DOT__clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__UART__DOT__baud_gen_inst__DOT__clk__0))))))));
    vlSelfRef.__Vtrigprevexpr___TOP__UART__DOT__baud_gen_inst__DOT__clk__0 
        = vlSelfRef.UART__DOT__baud_gen_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__UART__DOT__tx_fifo_inst__DOT__clk__0 
        = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__UART__DOT__uart_tx_inst__DOT__clk__0 
        = vlSelfRef.UART__DOT__uart_tx_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__UART__DOT__uart_rx_inst__DOT__clk__0 
        = vlSelfRef.UART__DOT__uart_rx_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__UART__DOT__rx_fifo_inst__DOT__clk__0 
        = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__clk;
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*8:0*/ __Vdly__UART__DOT__baud_gen_inst__DOT__count;
    __Vdly__UART__DOT__baud_gen_inst__DOT__count = 0;
    // Body
    __Vdly__UART__DOT__baud_gen_inst__DOT__count = vlSelfRef.UART__DOT__baud_gen_inst__DOT__count;
    if (vlSelfRef.UART__DOT__baud_gen_inst__DOT__rst_n) {
        if ((0x0144U == (IData)(vlSelfRef.UART__DOT__baud_gen_inst__DOT__count))) {
            __Vdly__UART__DOT__baud_gen_inst__DOT__count = 0U;
            vlSelfRef.UART__DOT__baud_gen_inst__DOT__tick = 1U;
        } else {
            __Vdly__UART__DOT__baud_gen_inst__DOT__count 
                = (0x000001ffU & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__baud_gen_inst__DOT__count)));
            vlSelfRef.UART__DOT__baud_gen_inst__DOT__tick = 0U;
        }
    } else {
        __Vdly__UART__DOT__baud_gen_inst__DOT__count = 0U;
        vlSelfRef.UART__DOT__baud_gen_inst__DOT__tick = 0U;
    }
    vlSelfRef.UART__DOT__baud_gen_inst__DOT__count 
        = __Vdly__UART__DOT__baud_gen_inst__DOT__count;
    vlSelfRef.UART__DOT__tick = vlSelfRef.UART__DOT__baud_gen_inst__DOT__tick;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __VdlyVal__UART__DOT__rx_fifo_inst__DOT__mem__v0;
    __VdlyVal__UART__DOT__rx_fifo_inst__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__UART__DOT__rx_fifo_inst__DOT__mem__v0;
    __VdlyDim0__UART__DOT__rx_fifo_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__UART__DOT__rx_fifo_inst__DOT__mem__v0;
    __VdlySet__UART__DOT__rx_fifo_inst__DOT__mem__v0 = 0;
    // Body
    __VdlySet__UART__DOT__rx_fifo_inst__DOT__mem__v0 = 0U;
    if (vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rst_n) {
        if (((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_en) 
             & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty)))) {
            vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_ptr)));
        }
        vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count 
            = (0x0000001fU & ((2U == ((((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_en) 
                                        & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full))) 
                                       << 1U) | ((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_en) 
                                                 & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty)))))
                               ? ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count))
                               : ((1U == ((((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_en) 
                                            & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full))) 
                                           << 1U) | 
                                          ((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_en) 
                                           & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty)))))
                                   ? ((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count) 
                                      - (IData)(1U))
                                   : (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count))));
        if (((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_en) 
             & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full)))) {
            __VdlyVal__UART__DOT__rx_fifo_inst__DOT__mem__v0 
                = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_data;
            __VdlyDim0__UART__DOT__rx_fifo_inst__DOT__mem__v0 
                = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_ptr;
            __VdlySet__UART__DOT__rx_fifo_inst__DOT__mem__v0 = 1U;
            vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_ptr)));
        }
    } else {
        vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_ptr = 0U;
        vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count = 0U;
        vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_ptr = 0U;
    }
    if (__VdlySet__UART__DOT__rx_fifo_inst__DOT__mem__v0) {
        vlSelfRef.UART__DOT__rx_fifo_inst__DOT__mem[__VdlyDim0__UART__DOT__rx_fifo_inst__DOT__mem__v0] 
            = __VdlyVal__UART__DOT__rx_fifo_inst__DOT__mem__v0;
    }
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full = 
        (0x10U == (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count));
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty = 
        (0U == (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count));
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_data 
        = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__mem
        [vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_ptr];
    vlSelfRef.UART__DOT__rx_fifo_full = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full;
    vlSelfRef.UART__DOT__rx_empty = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty;
    vlSelfRef.UART__DOT__data_bus_out = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_data;
    vlSelfRef.rx_empty = vlSelfRef.UART__DOT__rx_empty;
    vlSelfRef.data_bus_out = vlSelfRef.UART__DOT__data_bus_out;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __VdlyVal__UART__DOT__tx_fifo_inst__DOT__mem__v0;
    __VdlyVal__UART__DOT__tx_fifo_inst__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__UART__DOT__tx_fifo_inst__DOT__mem__v0;
    __VdlyDim0__UART__DOT__tx_fifo_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__UART__DOT__tx_fifo_inst__DOT__mem__v0;
    __VdlySet__UART__DOT__tx_fifo_inst__DOT__mem__v0 = 0;
    // Body
    __VdlySet__UART__DOT__tx_fifo_inst__DOT__mem__v0 = 0U;
    if (vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rst_n) {
        if (((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_en) 
             & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty)))) {
            vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_ptr)));
        }
        if (((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_en) 
             & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full)))) {
            __VdlyVal__UART__DOT__tx_fifo_inst__DOT__mem__v0 
                = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_data;
            __VdlyDim0__UART__DOT__tx_fifo_inst__DOT__mem__v0 
                = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_ptr;
            __VdlySet__UART__DOT__tx_fifo_inst__DOT__mem__v0 = 1U;
            vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_ptr 
                = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_ptr)));
        }
        vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count 
            = (0x0000001fU & ((2U == ((((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_en) 
                                        & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full))) 
                                       << 1U) | ((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_en) 
                                                 & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty)))))
                               ? ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count))
                               : ((1U == ((((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_en) 
                                            & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full))) 
                                           << 1U) | 
                                          ((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_en) 
                                           & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty)))))
                                   ? ((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count) 
                                      - (IData)(1U))
                                   : (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count))));
    } else {
        vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_ptr = 0U;
        vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_ptr = 0U;
        vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count = 0U;
    }
    if (__VdlySet__UART__DOT__tx_fifo_inst__DOT__mem__v0) {
        vlSelfRef.UART__DOT__tx_fifo_inst__DOT__mem[__VdlyDim0__UART__DOT__tx_fifo_inst__DOT__mem__v0] 
            = __VdlyVal__UART__DOT__tx_fifo_inst__DOT__mem__v0;
    }
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_data 
        = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__mem
        [vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_ptr];
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full = 
        (0x10U == (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count));
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty = 
        (0U == (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count));
    vlSelfRef.UART__DOT__tx_fifo_rd_data = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_data;
    vlSelfRef.UART__DOT__tx_full = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full;
    vlSelfRef.UART__DOT__tx_fifo_empty = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty;
    vlSelfRef.tx_full = vlSelfRef.UART__DOT__tx_full;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count;
    __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0;
    CData/*1:0*/ __Vdly__UART__DOT__uart_tx_inst__DOT__state;
    __Vdly__UART__DOT__uart_tx_inst__DOT__state = 0;
    // Body
    __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count 
        = vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count;
    __Vdly__UART__DOT__uart_tx_inst__DOT__state = vlSelfRef.UART__DOT__uart_tx_inst__DOT__state;
    if (vlSelfRef.UART__DOT__uart_tx_inst__DOT__rst_n) {
        if ((2U & (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__state))) {
                vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx = 1U;
                if (vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick) {
                    if ((0x0fU == (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count))) {
                        __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0U;
                        vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_busy = 0U;
                        __Vdly__UART__DOT__uart_tx_inst__DOT__state = 0U;
                    } else {
                        __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count)));
                    }
                }
            } else {
                vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx 
                    = (1U & ((IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_shift_reg) 
                             >> (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index)));
                if (vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick) {
                    if ((0x0fU == (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count))) {
                        __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0U;
                        if ((7U == (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index))) {
                            __Vdly__UART__DOT__uart_tx_inst__DOT__state = 3U;
                        } else {
                            vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index)));
                        }
                    } else {
                        __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count)));
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__state))) {
            vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx = 0U;
            if (vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick) {
                if ((0x0fU == (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count))) {
                    __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0U;
                    vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index = 0U;
                    __Vdly__UART__DOT__uart_tx_inst__DOT__state = 2U;
                } else {
                    __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count)));
                }
            }
        } else {
            vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx = 1U;
            if (vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_start) {
                __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0U;
                vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_shift_reg 
                    = vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_data;
                vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_busy = 1U;
                __Vdly__UART__DOT__uart_tx_inst__DOT__state = 1U;
            }
        }
    } else {
        __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0U;
        vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index = 0U;
        __Vdly__UART__DOT__uart_tx_inst__DOT__state = 0U;
        vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx = 1U;
        vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_busy = 0U;
    }
    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count 
        = __Vdly__UART__DOT__uart_tx_inst__DOT__tick_count;
    vlSelfRef.UART__DOT__uart_tx_inst__DOT__state = __Vdly__UART__DOT__uart_tx_inst__DOT__state;
    vlSelfRef.UART__DOT__tx = vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx;
    vlSelfRef.UART__DOT__tx_busy = vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_busy;
    vlSelfRef.tx = vlSelfRef.UART__DOT__tx;
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count;
    __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count = 0;
    CData/*1:0*/ __Vdly__UART__DOT__uart_rx_inst__DOT__state;
    __Vdly__UART__DOT__uart_rx_inst__DOT__state = 0;
    CData/*7:0*/ __Vdly__UART__DOT__uart_rx_inst__DOT__rx_shift_reg;
    __Vdly__UART__DOT__uart_rx_inst__DOT__rx_shift_reg = 0;
    CData/*2:0*/ __Vdly__UART__DOT__uart_rx_inst__DOT__bit_index;
    __Vdly__UART__DOT__uart_rx_inst__DOT__bit_index = 0;
    // Body
    __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count 
        = vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count;
    __Vdly__UART__DOT__uart_rx_inst__DOT__state = vlSelfRef.UART__DOT__uart_rx_inst__DOT__state;
    __Vdly__UART__DOT__uart_rx_inst__DOT__rx_shift_reg 
        = vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_shift_reg;
    __Vdly__UART__DOT__uart_rx_inst__DOT__bit_index 
        = vlSelfRef.UART__DOT__uart_rx_inst__DOT__bit_index;
    if (vlSelfRef.UART__DOT__uart_rx_inst__DOT__rst_n) {
        if ((2U & (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__state))) {
                vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_done = 0U;
                vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_error = 0U;
                if (vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick) {
                    if ((8U == (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count))) {
                        __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count)));
                        if (vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx) {
                            vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_done = 1U;
                        } else {
                            vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_error = 1U;
                        }
                    } else if ((0x0fU == (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count))) {
                        __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count = 0U;
                        vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_busy = 0U;
                        __Vdly__UART__DOT__uart_rx_inst__DOT__state = 0U;
                    } else {
                        __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count)));
                    }
                }
            } else if (vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick) {
                if ((7U == (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__bit_index))) {
                    if ((8U == (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count))) {
                        __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count)));
                        __Vdly__UART__DOT__uart_rx_inst__DOT__rx_shift_reg 
                            = (((~ ((IData)(1U) << (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__bit_index))) 
                                & (IData)(__Vdly__UART__DOT__uart_rx_inst__DOT__rx_shift_reg)) 
                               | (0x00ffU & ((IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx) 
                                             << (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__bit_index))));
                    } else if ((0x0fU == (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count))) {
                        __Vdly__UART__DOT__uart_rx_inst__DOT__bit_index 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__bit_index)));
                        __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count = 0U;
                        vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_byte 
                            = vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_shift_reg;
                        __Vdly__UART__DOT__uart_rx_inst__DOT__state = 3U;
                    } else {
                        __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count)));
                    }
                } else if ((8U == (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count))) {
                    __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count)));
                    __Vdly__UART__DOT__uart_rx_inst__DOT__rx_shift_reg 
                        = (((~ ((IData)(1U) << (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__bit_index))) 
                            & (IData)(__Vdly__UART__DOT__uart_rx_inst__DOT__rx_shift_reg)) 
                           | (0x00ffU & ((IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx) 
                                         << (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__bit_index))));
                } else if ((0x0fU == (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count))) {
                    __Vdly__UART__DOT__uart_rx_inst__DOT__bit_index 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__bit_index)));
                    __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count = 0U;
                } else {
                    __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count)));
                }
            }
        } else if ((1U & (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__state))) {
            if (vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick) {
                if ((0x0fU == (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count))) {
                    __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count = 0U;
                    __Vdly__UART__DOT__uart_rx_inst__DOT__state = 2U;
                } else if ((8U == (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count))) {
                    if (vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx) {
                        __Vdly__UART__DOT__uart_rx_inst__DOT__state = 0U;
                    } else {
                        __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count)));
                    }
                } else {
                    __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count)));
                }
            }
        } else {
            vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_busy = 0U;
            vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_done = 0U;
            vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_error = 0U;
            if (((~ (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx)) 
                 & (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_prev))) {
                __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count = 0U;
                __Vdly__UART__DOT__uart_rx_inst__DOT__bit_index = 0U;
                vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_busy = 1U;
                __Vdly__UART__DOT__uart_rx_inst__DOT__state = 1U;
            }
        }
    } else {
        __Vdly__UART__DOT__uart_rx_inst__DOT__bit_index = 0U;
        __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count = 0U;
        __Vdly__UART__DOT__uart_rx_inst__DOT__state = 0U;
        vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_error = 0U;
        vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_busy = 0U;
        vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_done = 0U;
    }
    vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick_count 
        = __Vdly__UART__DOT__uart_rx_inst__DOT__tick_count;
    vlSelfRef.UART__DOT__uart_rx_inst__DOT__state = __Vdly__UART__DOT__uart_rx_inst__DOT__state;
    vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_shift_reg 
        = __Vdly__UART__DOT__uart_rx_inst__DOT__rx_shift_reg;
    vlSelfRef.UART__DOT__uart_rx_inst__DOT__bit_index 
        = __Vdly__UART__DOT__uart_rx_inst__DOT__bit_index;
    vlSelfRef.UART__DOT__rx_busy = vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_busy;
    vlSelfRef.UART__DOT__rx_done = vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_done;
    vlSelfRef.UART__DOT__rx_error = vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_error;
    vlSelfRef.UART__DOT__rx_byte = vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_byte;
    vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx_prev 
        = ((1U & (~ (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__rst_n))) 
           || (IData)(vlSelfRef.UART__DOT__uart_rx_inst__DOT__rx));
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_en = vlSelfRef.UART__DOT__rx_done;
    vlSelfRef.rx_error = vlSelfRef.UART__DOT__rx_error;
    vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_data 
        = vlSelfRef.UART__DOT__rx_byte;
}

void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick = vlSelfRef.UART__DOT__tick;
    vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick = vlSelfRef.UART__DOT__tick;
}

void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__6\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_data 
        = vlSelfRef.UART__DOT__tx_fifo_rd_data;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.UART__DOT__tx_start = (1U & (~ ((IData)(vlSelfRef.UART__DOT__tx_busy) 
                                              | (IData)(vlSelfRef.UART__DOT__tx_fifo_empty))));
    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_start 
        = vlSelfRef.UART__DOT__tx_start;
    vlSelfRef.UART__DOT__tx_rd_en = vlSelfRef.UART__DOT__tx_start;
    vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_en = vlSelfRef.UART__DOT__tx_rd_en;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*8:0*/ __Vinline__nba_sequent__TOP__0___Vdly__UART__DOT__baud_gen_inst__DOT__count;
    __Vinline__nba_sequent__TOP__0___Vdly__UART__DOT__baud_gen_inst__DOT__count = 0;
    CData/*7:0*/ __Vinline__nba_sequent__TOP__1___VdlyVal__UART__DOT__rx_fifo_inst__DOT__mem__v0;
    __Vinline__nba_sequent__TOP__1___VdlyVal__UART__DOT__rx_fifo_inst__DOT__mem__v0 = 0;
    CData/*3:0*/ __Vinline__nba_sequent__TOP__1___VdlyDim0__UART__DOT__rx_fifo_inst__DOT__mem__v0;
    __Vinline__nba_sequent__TOP__1___VdlyDim0__UART__DOT__rx_fifo_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__1___VdlySet__UART__DOT__rx_fifo_inst__DOT__mem__v0;
    __Vinline__nba_sequent__TOP__1___VdlySet__UART__DOT__rx_fifo_inst__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vinline__nba_sequent__TOP__2___VdlyVal__UART__DOT__tx_fifo_inst__DOT__mem__v0;
    __Vinline__nba_sequent__TOP__2___VdlyVal__UART__DOT__tx_fifo_inst__DOT__mem__v0 = 0;
    CData/*3:0*/ __Vinline__nba_sequent__TOP__2___VdlyDim0__UART__DOT__tx_fifo_inst__DOT__mem__v0;
    __Vinline__nba_sequent__TOP__2___VdlyDim0__UART__DOT__tx_fifo_inst__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vinline__nba_sequent__TOP__2___VdlySet__UART__DOT__tx_fifo_inst__DOT__mem__v0;
    __Vinline__nba_sequent__TOP__2___VdlySet__UART__DOT__tx_fifo_inst__DOT__mem__v0 = 0;
    CData/*3:0*/ __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count;
    __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0;
    CData/*1:0*/ __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__state;
    __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__state = 0;
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__0___Vdly__UART__DOT__baud_gen_inst__DOT__count 
            = vlSelfRef.UART__DOT__baud_gen_inst__DOT__count;
        if (vlSelfRef.UART__DOT__baud_gen_inst__DOT__rst_n) {
            if ((0x0144U == (IData)(vlSelfRef.UART__DOT__baud_gen_inst__DOT__count))) {
                __Vinline__nba_sequent__TOP__0___Vdly__UART__DOT__baud_gen_inst__DOT__count = 0U;
                vlSelfRef.UART__DOT__baud_gen_inst__DOT__tick = 1U;
            } else {
                __Vinline__nba_sequent__TOP__0___Vdly__UART__DOT__baud_gen_inst__DOT__count 
                    = (0x000001ffU & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__baud_gen_inst__DOT__count)));
                vlSelfRef.UART__DOT__baud_gen_inst__DOT__tick = 0U;
            }
        } else {
            __Vinline__nba_sequent__TOP__0___Vdly__UART__DOT__baud_gen_inst__DOT__count = 0U;
            vlSelfRef.UART__DOT__baud_gen_inst__DOT__tick = 0U;
        }
        vlSelfRef.UART__DOT__baud_gen_inst__DOT__count 
            = __Vinline__nba_sequent__TOP__0___Vdly__UART__DOT__baud_gen_inst__DOT__count;
        vlSelfRef.UART__DOT__tick = vlSelfRef.UART__DOT__baud_gen_inst__DOT__tick;
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__1___VdlySet__UART__DOT__rx_fifo_inst__DOT__mem__v0 = 0U;
        if (vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rst_n) {
            if (((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_en) 
                 & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty)))) {
                vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_ptr 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_ptr)));
            }
            vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count 
                = (0x0000001fU & ((2U == ((((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_en) 
                                            & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full))) 
                                           << 1U) | 
                                          ((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_en) 
                                           & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty)))))
                                   ? ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count))
                                   : ((1U == ((((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_en) 
                                                & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full))) 
                                               << 1U) 
                                              | ((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_en) 
                                                 & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty)))))
                                       ? ((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count) 
                                          - (IData)(1U))
                                       : (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count))));
            if (((IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_en) 
                 & (~ (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full)))) {
                __Vinline__nba_sequent__TOP__1___VdlyVal__UART__DOT__rx_fifo_inst__DOT__mem__v0 
                    = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_data;
                __Vinline__nba_sequent__TOP__1___VdlyDim0__UART__DOT__rx_fifo_inst__DOT__mem__v0 
                    = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_ptr;
                __Vinline__nba_sequent__TOP__1___VdlySet__UART__DOT__rx_fifo_inst__DOT__mem__v0 = 1U;
                vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_ptr 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_ptr)));
            }
        } else {
            vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_ptr = 0U;
            vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count = 0U;
            vlSelfRef.UART__DOT__rx_fifo_inst__DOT__wr_ptr = 0U;
        }
        if (__Vinline__nba_sequent__TOP__1___VdlySet__UART__DOT__rx_fifo_inst__DOT__mem__v0) {
            vlSelfRef.UART__DOT__rx_fifo_inst__DOT__mem[__Vinline__nba_sequent__TOP__1___VdlyDim0__UART__DOT__rx_fifo_inst__DOT__mem__v0] 
                = __Vinline__nba_sequent__TOP__1___VdlyVal__UART__DOT__rx_fifo_inst__DOT__mem__v0;
        }
        vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full 
            = (0x10U == (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count));
        vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty 
            = (0U == (IData)(vlSelfRef.UART__DOT__rx_fifo_inst__DOT__count));
        vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_data 
            = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__mem
            [vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_ptr];
        vlSelfRef.UART__DOT__rx_fifo_full = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__full;
        vlSelfRef.UART__DOT__rx_empty = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__empty;
        vlSelfRef.UART__DOT__data_bus_out = vlSelfRef.UART__DOT__rx_fifo_inst__DOT__rd_data;
        vlSelfRef.rx_empty = vlSelfRef.UART__DOT__rx_empty;
        vlSelfRef.data_bus_out = vlSelfRef.UART__DOT__data_bus_out;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__2___VdlySet__UART__DOT__tx_fifo_inst__DOT__mem__v0 = 0U;
        if (vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rst_n) {
            if (((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_en) 
                 & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty)))) {
                vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_ptr 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_ptr)));
            }
            if (((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_en) 
                 & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full)))) {
                __Vinline__nba_sequent__TOP__2___VdlyVal__UART__DOT__tx_fifo_inst__DOT__mem__v0 
                    = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_data;
                __Vinline__nba_sequent__TOP__2___VdlyDim0__UART__DOT__tx_fifo_inst__DOT__mem__v0 
                    = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_ptr;
                __Vinline__nba_sequent__TOP__2___VdlySet__UART__DOT__tx_fifo_inst__DOT__mem__v0 = 1U;
                vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_ptr 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_ptr)));
            }
            vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count 
                = (0x0000001fU & ((2U == ((((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_en) 
                                            & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full))) 
                                           << 1U) | 
                                          ((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_en) 
                                           & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty)))))
                                   ? ((IData)(1U) + (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count))
                                   : ((1U == ((((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_en) 
                                                & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full))) 
                                               << 1U) 
                                              | ((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_en) 
                                                 & (~ (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty)))))
                                       ? ((IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count) 
                                          - (IData)(1U))
                                       : (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count))));
        } else {
            vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_ptr = 0U;
            vlSelfRef.UART__DOT__tx_fifo_inst__DOT__wr_ptr = 0U;
            vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count = 0U;
        }
        if (__Vinline__nba_sequent__TOP__2___VdlySet__UART__DOT__tx_fifo_inst__DOT__mem__v0) {
            vlSelfRef.UART__DOT__tx_fifo_inst__DOT__mem[__Vinline__nba_sequent__TOP__2___VdlyDim0__UART__DOT__tx_fifo_inst__DOT__mem__v0] 
                = __Vinline__nba_sequent__TOP__2___VdlyVal__UART__DOT__tx_fifo_inst__DOT__mem__v0;
        }
        vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_data 
            = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__mem
            [vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_ptr];
        vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full 
            = (0x10U == (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count));
        vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty 
            = (0U == (IData)(vlSelfRef.UART__DOT__tx_fifo_inst__DOT__count));
        vlSelfRef.UART__DOT__tx_fifo_rd_data = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_data;
        vlSelfRef.UART__DOT__tx_full = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__full;
        vlSelfRef.UART__DOT__tx_fifo_empty = vlSelfRef.UART__DOT__tx_fifo_inst__DOT__empty;
        vlSelfRef.tx_full = vlSelfRef.UART__DOT__tx_full;
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count 
            = vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count;
        __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__state 
            = vlSelfRef.UART__DOT__uart_tx_inst__DOT__state;
        if (vlSelfRef.UART__DOT__uart_tx_inst__DOT__rst_n) {
            if ((2U & (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__state))) {
                    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx = 1U;
                    if (vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick) {
                        if ((0x0fU == (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count))) {
                            __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0U;
                            vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_busy = 0U;
                            __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__state = 0U;
                        } else {
                            __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count)));
                        }
                    }
                } else {
                    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx 
                        = (1U & ((IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_shift_reg) 
                                 >> (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index)));
                    if (vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick) {
                        if ((0x0fU == (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count))) {
                            __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0U;
                            if ((7U == (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index))) {
                                __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__state = 3U;
                            } else {
                                vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index 
                                    = (7U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index)));
                            }
                        } else {
                            __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count 
                                = (0x0000000fU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count)));
                        }
                    }
                }
            } else if ((1U & (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__state))) {
                vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx = 0U;
                if (vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick) {
                    if ((0x0fU == (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count))) {
                        __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0U;
                        vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index = 0U;
                        __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__state = 2U;
                    } else {
                        __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count)));
                    }
                }
            } else {
                vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx = 1U;
                if (vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_start) {
                    __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0U;
                    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_shift_reg 
                        = vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_data;
                    vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_busy = 1U;
                    __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__state = 1U;
                }
            }
        } else {
            __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count = 0U;
            vlSelfRef.UART__DOT__uart_tx_inst__DOT__bit_index = 0U;
            __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__state = 0U;
            vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx = 1U;
            vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_busy = 0U;
        }
        vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick_count 
            = __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__tick_count;
        vlSelfRef.UART__DOT__uart_tx_inst__DOT__state 
            = __Vinline__nba_sequent__TOP__3___Vdly__UART__DOT__uart_tx_inst__DOT__state;
        vlSelfRef.UART__DOT__tx = vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx;
        vlSelfRef.UART__DOT__tx_busy = vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_busy;
        vlSelfRef.tx = vlSelfRef.UART__DOT__tx;
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.UART__DOT__uart_tx_inst__DOT__tick 
            = vlSelfRef.UART__DOT__tick;
        vlSelfRef.UART__DOT__uart_rx_inst__DOT__tick 
            = vlSelfRef.UART__DOT__tick;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_data 
            = vlSelfRef.UART__DOT__tx_fifo_rd_data;
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.UART__DOT__tx_start = (1U & (~ ((IData)(vlSelfRef.UART__DOT__tx_busy) 
                                                  | (IData)(vlSelfRef.UART__DOT__tx_fifo_empty))));
        vlSelfRef.UART__DOT__uart_tx_inst__DOT__tx_start 
            = vlSelfRef.UART__DOT__tx_start;
        vlSelfRef.UART__DOT__tx_rd_en = vlSelfRef.UART__DOT__tx_start;
        vlSelfRef.UART__DOT__tx_fifo_inst__DOT__rd_en 
            = vlSelfRef.UART__DOT__tx_rd_en;
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/Users/taha.ibrah/Downloads/UART_Project/tb/../rtl/UART.sv", 25, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/taha.ibrah/Downloads/UART_Project/tb/../rtl/UART.sv", 25, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/taha.ibrah/Downloads/UART_Project/tb/../rtl/UART.sv", 25, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.tx_wr_en & 0xfeU)))) {
        Verilated::overWidthError("tx_wr_en");
    }
    if (VL_UNLIKELY(((vlSelfRef.rx_rd_en & 0xfeU)))) {
        Verilated::overWidthError("rx_rd_en");
    }
    if (VL_UNLIKELY(((vlSelfRef.rx & 0xfeU)))) {
        Verilated::overWidthError("rx");
    }
}
#endif  // VL_DEBUG
