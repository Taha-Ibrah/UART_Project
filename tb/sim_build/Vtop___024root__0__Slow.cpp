// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
            VL_FATAL_MT("/Users/taha.ibrah/Downloads/UART_Project/tb/../rtl/UART.sv", 25, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge UART.baud_gen_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge UART.tx_fifo_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge UART.uart_tx_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge UART.uart_rx_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge UART.rx_fifo_inst.clk)\n");
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
    vlSelf->data_bus_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17517678984707000776ull);
    vlSelf->tx_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12110635537856617549ull);
    vlSelf->tx_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16419730764986402093ull);
    vlSelf->data_bus_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10323532109391045698ull);
    vlSelf->rx_rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2252678262178621154ull);
    vlSelf->rx_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6200756749769513441ull);
    vlSelf->rx_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6308253193954522356ull);
    vlSelf->rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7329251852453572689ull);
    vlSelf->tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16692943634734642928ull);
    vlSelf->UART__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10718144993132547485ull);
    vlSelf->UART__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6458512157828196818ull);
    vlSelf->UART__DOT__data_bus_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18438416272044403143ull);
    vlSelf->UART__DOT__tx_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14115129011798436409ull);
    vlSelf->UART__DOT__tx_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10736383962385639996ull);
    vlSelf->UART__DOT__data_bus_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14230214191645156513ull);
    vlSelf->UART__DOT__rx_rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3746337047605607377ull);
    vlSelf->UART__DOT__rx_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16295545308359533354ull);
    vlSelf->UART__DOT__rx_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14483656599361080478ull);
    vlSelf->UART__DOT__rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14748060041013185031ull);
    vlSelf->UART__DOT__tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14263054788494195976ull);
    vlSelf->UART__DOT__tick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10166929491858603140ull);
    vlSelf->UART__DOT__tx_fifo_rd_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16578174000137899039ull);
    vlSelf->UART__DOT__tx_fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10067075354335770203ull);
    vlSelf->UART__DOT__tx_rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7935804805592235920ull);
    vlSelf->UART__DOT__tx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5010821106375367269ull);
    vlSelf->UART__DOT__tx_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16828849677950079681ull);
    vlSelf->UART__DOT__rx_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7357872316286247393ull);
    vlSelf->UART__DOT__rx_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15260114614712193243ull);
    vlSelf->UART__DOT__rx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12872773371468503603ull);
    vlSelf->UART__DOT__rx_fifo_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14223069219353854221ull);
    vlSelf->UART__DOT__baud_gen_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11913340817906379059ull);
    vlSelf->UART__DOT__baud_gen_inst__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12432599720094281216ull);
    vlSelf->UART__DOT__baud_gen_inst__DOT__tick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4801461039008751779ull);
    vlSelf->UART__DOT__baud_gen_inst__DOT__count = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4928299148110396903ull);
    vlSelf->UART__DOT__tx_fifo_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9655268114768683685ull);
    vlSelf->UART__DOT__tx_fifo_inst__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2022039105073077913ull);
    vlSelf->UART__DOT__tx_fifo_inst__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8642926402621462113ull);
    vlSelf->UART__DOT__tx_fifo_inst__DOT__wr_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13562973112393101416ull);
    vlSelf->UART__DOT__tx_fifo_inst__DOT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8735954674708210418ull);
    vlSelf->UART__DOT__tx_fifo_inst__DOT__rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5033810060291959573ull);
    vlSelf->UART__DOT__tx_fifo_inst__DOT__rd_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1290191371856385486ull);
    vlSelf->UART__DOT__tx_fifo_inst__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11212073512876764525ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->UART__DOT__tx_fifo_inst__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9290454734081152843ull);
    }
    vlSelf->UART__DOT__tx_fifo_inst__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7467673637308519056ull);
    vlSelf->UART__DOT__tx_fifo_inst__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 864497592981997167ull);
    vlSelf->UART__DOT__tx_fifo_inst__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12009241755425131999ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6832556370645419418ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12524046999875268983ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__tick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2593924705676030552ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__tx_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5386242633257777014ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__tx_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13170539025949337075ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__tx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15508052284825434793ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__tx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12675944323137375077ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16848493013997574505ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__tick_count = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14483771740192526620ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10717753334293534868ull);
    vlSelf->UART__DOT__uart_tx_inst__DOT__tx_shift_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3942891643436075864ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6658529536626553542ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1412663028543234931ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__tick = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9453820645736971388ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__rx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3272992616558768501ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__rx_byte = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12322495361460268144ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__rx_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15425227735841542614ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__rx_error = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10905021090335833547ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__rx_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9359679447037314105ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12686028516315669622ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__tick_count = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13221849614965356119ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__bit_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1541297723206955277ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__rx_shift_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9616611072751170002ull);
    vlSelf->UART__DOT__uart_rx_inst__DOT__rx_prev = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17797535058472900457ull);
    vlSelf->UART__DOT__rx_fifo_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1142874785503376992ull);
    vlSelf->UART__DOT__rx_fifo_inst__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2751298876049296907ull);
    vlSelf->UART__DOT__rx_fifo_inst__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16575921834000660793ull);
    vlSelf->UART__DOT__rx_fifo_inst__DOT__wr_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6936244938962070592ull);
    vlSelf->UART__DOT__rx_fifo_inst__DOT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14615045048908524517ull);
    vlSelf->UART__DOT__rx_fifo_inst__DOT__rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 756099588389474213ull);
    vlSelf->UART__DOT__rx_fifo_inst__DOT__rd_data = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4353041515039784275ull);
    vlSelf->UART__DOT__rx_fifo_inst__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10406443387109792577ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->UART__DOT__rx_fifo_inst__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2842908722991588224ull);
    }
    vlSelf->UART__DOT__rx_fifo_inst__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18415975571261219469ull);
    vlSelf->UART__DOT__rx_fifo_inst__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15492194966401916849ull);
    vlSelf->UART__DOT__rx_fifo_inst__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8090785041759526409ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__UART__DOT__baud_gen_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__UART__DOT__tx_fifo_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__UART__DOT__uart_tx_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__UART__DOT__uart_rx_inst__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__UART__DOT__rx_fifo_inst__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
