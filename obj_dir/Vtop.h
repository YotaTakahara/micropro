// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated.h"

class Vtop__Syms;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(sysclk,0,0);
    VL_IN8(cpu_resetn,0,0);
    VL_OUT8(uart_tx,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(top__DOT__reg_we,0,0);
    VL_SIG8(top__DOT__srcreg1_num,4,0);
    VL_SIG8(top__DOT__srcreg2_num,4,0);
    VL_SIG8(top__DOT__dstreg_num,4,0);
    VL_SIG8(top__DOT__aluop1_type,1,0);
    VL_SIG8(top__DOT__aluop2_type,1,0);
    VL_SIG8(top__DOT__alucode,5,0);
    VL_SIG8(top__DOT__we,3,0);
    VL_SIG8(top__DOT__is_store,0,0);
    VL_SIG8(top__DOT__is_load,0,0);
    VL_SIG8(top__DOT__br_taken,0,0);
    VL_SIG8(top__DOT__uart_OUT_data,0,0);
    VL_SIG8(top__DOT__uart0__DOT__bitcount,3,0);
    VL_SIG8(top__DOT__uart0__DOT__uart_busy,0,0);
    VL_SIG8(top__DOT__uart0__DOT__sending,0,0);
    VL_SIG16(top__DOT__uart0__DOT__shifter,8,0);
    VL_SIG(top__DOT__pc,31,0);
    VL_SIG(top__DOT__ir,31,0);
    VL_SIG(top__DOT__alu_result,31,0);
    VL_SIG(top__DOT__imm,31,0);
    VL_SIG(top__DOT__rs2_data,31,0);
    VL_SIG(top__DOT__w_data,31,0);
    VL_SIG(top__DOT__w_data_memo,31,0);
    VL_SIG(top__DOT__data_memory,31,0);
    VL_SIG(top__DOT__nextPc,31,0);
    VL_SIG(top__DOT__op1,31,0);
    VL_SIG(top__DOT__op2,31,0);
    VL_SIG(top__DOT__uart0__DOT__d,28,0);
    VL_SIG(top__DOT__uart0__DOT__dNxt,28,0);
    VL_SIG(top__DOT__hardware_counter0__DOT__cycles,31,0);
    VL_SIG(top__DOT__instuction1__DOT__mem[32768],31,0);
    VL_SIG(top__DOT__reg_file1__DOT__mem[32],31,0);
    VL_SIG(top__DOT__data_mem1__DOT__mem[32768],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__cpu_resetn,0,0);
    VL_SIG8(__Vclklast__TOP__sysclk,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vtop& operator= (const Vtop&);  ///< Copying not allowed
    Vtop(const Vtop&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vtop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__8(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__6(Vtop__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
