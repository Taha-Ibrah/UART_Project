// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__UART_TX_tl__DOT__baud_gen_inst__DOT__clk__0 
        = vlSelfRef.UART_TX_tl__DOT__baud_gen_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__UART_TX_tl__DOT__uart_tx_inst__DOT__clk__0 
        = vlSelfRef.UART_TX_tl__DOT__uart_tx_inst__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/taha.ibrah/Downloads/UART_Project/tb/../rtl/UART_TX_tl.sv", 6, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtop___024root___eval_triggers_vec__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        vlSelfRef.UART_TX_tl__DOT__tx_data = vlSelfRef.tx_data;
        vlSelfRef.UART_TX_tl__DOT__tx_start = vlSelfRef.tx_start;
        vlSelfRef.UART_TX_tl__DOT__tx_busy = vlSelfRef.UART_TX_tl__DOT__uart_tx_inst__DOT__tx_busy;
        vlSelfRef.UART_TX_tl__DOT__tx = vlSelfRef.UART_TX_tl__DOT__uart_tx_inst__DOT__tx;
        vlSelfRef.UART_TX_tl__DOT__tick = vlSelfRef.UART_TX_tl__DOT__baud_gen_inst__DOT__tick;
        vlSelfRef.UART_TX_tl__DOT__clk = vlSelfRef.clk;
        vlSelfRef.UART_TX_tl__DOT__rst_n = vlSelfRef.rst_n;
        vlSelfRef.UART_TX_tl__DOT__uart_tx_inst__DOT__tx_data 
            = vlSelfRef.UART_TX_tl__DOT__tx_data;
        vlSelfRef.UART_TX_tl__DOT__uart_tx_inst__DOT__tx_start 
            = vlSelfRef.UART_TX_tl__DOT__tx_start;
        vlSelfRef.tx_busy = vlSelfRef.UART_TX_tl__DOT__tx_busy;
        vlSelfRef.tx = vlSelfRef.UART_TX_tl__DOT__tx;
        vlSelfRef.UART_TX_tl__DOT__uart_tx_inst__DOT__tick 
            = vlSelfRef.UART_TX_tl__DOT__tick;
        vlSelfRef.UART_TX_tl__DOT__baud_gen_inst__DOT__clk 
            = vlSelfRef.UART_TX_tl__DOT__clk;
        vlSelfRef.UART_TX_tl__DOT__uart_tx_inst__DOT__clk 
            = vlSelfRef.UART_TX_tl__DOT__clk;
        vlSelfRef.UART_TX_tl__DOT__baud_gen_inst__DOT__rst_n 
            = vlSelfRef.UART_TX_tl__DOT__rst_n;
        vlSelfRef.UART_TX_tl__DOT__uart_tx_inst__DOT__rst_n 
            = vlSelfRef.UART_TX_tl__DOT__rst_n;
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge UART_TX_tl.baud_gen_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge UART_TX_tl.uart_tx_inst.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14770307426006424685ull);
    vlSelf->tx_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10922211238440073863ull);
    vlSelf->tx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1130330860826808631ull);
    vlSelf->tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16692943634734642928ull);
    vlSelf->UART_TX_tl__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 299462285131561756ull);
    vlSelf->UART_TX_tl__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7487145708249675002ull);
    vlSelf->UART_TX_tl__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9397851294191442034ull);
    vlSelf->UART_TX_tl__DOT__tx_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9279529511606038465ull);
    vlSelf->UART_TX_tl__DOT__tx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4659712127542606951ull);
    vlSelf->UART_TX_tl__DOT__tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7606628845044827503ull);
    vlSelf->UART_TX_tl__DOT__tick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3630211519264204153ull);
    vlSelf->UART_TX_tl__DOT__baud_gen_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 679320614941863281ull);
    vlSelf->UART_TX_tl__DOT__baud_gen_inst__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2826962515821966381ull);
    vlSelf->UART_TX_tl__DOT__baud_gen_inst__DOT__tick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13235269076068873106ull);
    vlSelf->UART_TX_tl__DOT__baud_gen_inst__DOT__count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 14709037978016052878ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10941430173834459298ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4893108086116217668ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__tick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2401408898833249685ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 292298311589304651ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__tx_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12003004562952219299ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__tx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18073227068560703188ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9860952088368657272ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5790311637302239492ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__tick_count = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13666936059712303579ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14762643386084336195ull);
    vlSelf->UART_TX_tl__DOT__uart_tx_inst__DOT__tx_shift_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1576877034243658636ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__UART_TX_tl__DOT__baud_gen_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__UART_TX_tl__DOT__uart_tx_inst__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
