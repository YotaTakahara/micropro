// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp1,511,0,16);
    // Body
    // INITIAL at reg_file.v:37
    vlTOPp->top__DOT__reg_file1__DOT__mem[0U] = 0U;
    // INITIAL at instruction.v:33
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x636f6465U;
    __Vtemp1[2U] = 0x6172742fU;
    __Vtemp1[3U] = 0x74732f55U;
    __Vtemp1[4U] = 0x2f746573U;
    __Vtemp1[5U] = 0x61726b73U;
    __Vtemp1[6U] = 0x6e63686dU;
    __Vtemp1[7U] = 0x702f6265U;
    __Vtemp1[8U] = 0x62336578U;
    __Vtemp1[9U] = 0x6573732fU;
    __Vtemp1[0xaU] = 0x70726f63U;
    __Vtemp1[0xbU] = 0x6963726fU;
    __Vtemp1[0xcU] = 0x6a6f2f6dU;
    __Vtemp1[0xdU] = 0x2f64656eU;
    __Vtemp1[0xeU] = 0x686f6d65U;
    __Vtemp1[0xfU] = 0x2fU;
    VL_READMEM_W (true,32,32768, 0,16, __Vtemp1, vlTOPp->top__DOT__instuction1__DOT__mem
		  ,0,~0);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__top__DOT__uart0__DOT__bitcount,3,0);
    VL_SIG16(__Vdly__top__DOT__uart0__DOT__shifter,8,0);
    VL_SIG(__Vdly__top__DOT__hardware_counter0__DOT__cycles,31,0);
    // Body
    __Vdly__top__DOT__hardware_counter0__DOT__cycles 
	= vlTOPp->top__DOT__hardware_counter0__DOT__cycles;
    __Vdly__top__DOT__uart0__DOT__shifter = vlTOPp->top__DOT__uart0__DOT__shifter;
    __Vdly__top__DOT__uart0__DOT__bitcount = vlTOPp->top__DOT__uart0__DOT__bitcount;
    // ALWAYS at hardware_counter.v:14
    __Vdly__top__DOT__hardware_counter0__DOT__cycles 
	= ((IData)(vlTOPp->cpu_resetn) ? ((IData)(1U) 
					  + vlTOPp->top__DOT__hardware_counter0__DOT__cycles)
	    : 0U);
    // ALWAYS at uart.v:41
    if (vlTOPp->cpu_resetn) {
	if ((((0xf6fff070U == vlTOPp->top__DOT__alu_result) 
	      & (IData)(vlTOPp->top__DOT__is_store)) 
	     & (~ (IData)(vlTOPp->top__DOT__uart0__DOT__uart_busy)))) {
	    __Vdly__top__DOT__uart0__DOT__shifter = 
		(0x1feU & (vlTOPp->top__DOT__w_data_memo 
			   << 1U));
	    __Vdly__top__DOT__uart0__DOT__bitcount = 0xbU;
	}
	if (((IData)(vlTOPp->top__DOT__uart0__DOT__sending) 
	     & (~ (vlTOPp->top__DOT__uart0__DOT__d 
		   >> 0x1cU)))) {
	    __Vdly__top__DOT__uart0__DOT__shifter = 
		(0x100U | (0xffU & ((IData)(vlTOPp->top__DOT__uart0__DOT__shifter) 
				    >> 1U)));
	    __Vdly__top__DOT__uart0__DOT__bitcount 
		= (0xfU & ((IData)(vlTOPp->top__DOT__uart0__DOT__bitcount) 
			   - (IData)(1U)));
	    vlTOPp->top__DOT__uart_OUT_data = (1U & (IData)(vlTOPp->top__DOT__uart0__DOT__shifter));
	}
    } else {
	__Vdly__top__DOT__uart0__DOT__bitcount = 0U;
	__Vdly__top__DOT__uart0__DOT__shifter = 0U;
	vlTOPp->top__DOT__uart_OUT_data = 1U;
    }
    vlTOPp->top__DOT__hardware_counter0__DOT__cycles 
	= __Vdly__top__DOT__hardware_counter0__DOT__cycles;
    vlTOPp->top__DOT__uart0__DOT__shifter = __Vdly__top__DOT__uart0__DOT__shifter;
    vlTOPp->top__DOT__uart0__DOT__bitcount = __Vdly__top__DOT__uart0__DOT__bitcount;
    vlTOPp->uart_tx = vlTOPp->top__DOT__uart_OUT_data;
    vlTOPp->top__DOT__uart0__DOT__uart_busy = (0U != 
					       (7U 
						& ((IData)(vlTOPp->top__DOT__uart0__DOT__bitcount) 
						   >> 1U)));
    vlTOPp->top__DOT__uart0__DOT__sending = (0U != (IData)(vlTOPp->top__DOT__uart0__DOT__bitcount));
    // ALWAYS at uart.v:32
    vlTOPp->top__DOT__uart0__DOT__d = ((IData)(vlTOPp->cpu_resetn)
				        ? vlTOPp->top__DOT__uart0__DOT__dNxt
				        : 0U);
    vlTOPp->top__DOT__uart0__DOT__dNxt = (0x1fffffffU 
					  & (vlTOPp->top__DOT__uart0__DOT__d 
					     + ((0x10000000U 
						 & vlTOPp->top__DOT__uart0__DOT__d)
						 ? 0x1c200U
						 : 0xff692b80U)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at top.v:53
    vlTOPp->top__DOT__pc = ((IData)(vlTOPp->cpu_resetn)
			     ? 0x8000U : vlTOPp->top__DOT__nextPc);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at data_mem.v:23
    if ((0x20U & (IData)(vlTOPp->top__DOT__alucode))) {
	vlTOPp->top__DOT__data_memory = vlTOPp->top__DOT__data_mem1__DOT__mem
	    [(0x7fffU & (vlTOPp->top__DOT__alu_result 
			 >> 2U))];
    } else {
	if ((0x10U & (IData)(vlTOPp->top__DOT__alucode))) {
	    vlTOPp->top__DOT__data_memory = vlTOPp->top__DOT__data_mem1__DOT__mem
		[(0x7fffU & (vlTOPp->top__DOT__alu_result 
			     >> 2U))];
	} else {
	    if ((8U & (IData)(vlTOPp->top__DOT__alucode))) {
		if ((4U & (IData)(vlTOPp->top__DOT__alucode))) {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			vlTOPp->top__DOT__data_memory 
			    = vlTOPp->top__DOT__data_mem1__DOT__mem
			    [(0x7fffU & (vlTOPp->top__DOT__alu_result 
					 >> 2U))];
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    if ((0U == (3U & vlTOPp->top__DOT__alu_result))) {
				vlTOPp->top__DOT__data_memory 
				    = (0xffffU & vlTOPp->top__DOT__data_mem1__DOT__mem
				       [(0x7fffU & 
					 (vlTOPp->top__DOT__alu_result 
					  >> 2U))]);
			    } else {
				if ((1U == (3U & vlTOPp->top__DOT__alu_result))) {
				    vlTOPp->top__DOT__data_memory 
					= (0xffffU 
					   & (vlTOPp->top__DOT__data_mem1__DOT__mem
					      [(0x7fffU 
						& (vlTOPp->top__DOT__alu_result 
						   >> 2U))] 
					      >> 8U));
				} else {
				    if ((2U == (3U 
						& vlTOPp->top__DOT__alu_result))) {
					vlTOPp->top__DOT__data_memory 
					    = (0xffffU 
					       & (vlTOPp->top__DOT__data_mem1__DOT__mem
						  [
						  (0x7fffU 
						   & (vlTOPp->top__DOT__alu_result 
						      >> 2U))] 
						  >> 0x10U));
				    }
				}
			    }
			} else {
			    vlTOPp->top__DOT__data_memory 
				= ((0U == (3U & vlTOPp->top__DOT__alu_result))
				    ? (0xffU & vlTOPp->top__DOT__data_mem1__DOT__mem
				       [(0x7fffU & 
					 (vlTOPp->top__DOT__alu_result 
					  >> 2U))])
				    : ((1U == (3U & vlTOPp->top__DOT__alu_result))
				        ? (0xffU & 
					   (vlTOPp->top__DOT__data_mem1__DOT__mem
					    [(0x7fffU 
					      & (vlTOPp->top__DOT__alu_result 
						 >> 2U))] 
					    >> 8U))
				        : ((2U == (3U 
						   & vlTOPp->top__DOT__alu_result))
					    ? (0xffU 
					       & (vlTOPp->top__DOT__data_mem1__DOT__mem
						  [
						  (0x7fffU 
						   & (vlTOPp->top__DOT__alu_result 
						      >> 2U))] 
						  >> 0x10U))
					    : (0xffU 
					       & (vlTOPp->top__DOT__data_mem1__DOT__mem
						  [
						  (0x7fffU 
						   & (vlTOPp->top__DOT__alu_result 
						      >> 2U))] 
						  >> 0x18U)))));
			}
		    }
		} else {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__data_memory 
				= vlTOPp->top__DOT__data_mem1__DOT__mem
				[(0x7fffU & (vlTOPp->top__DOT__alu_result 
					     >> 2U))];
			} else {
			    if ((0U == (3U & vlTOPp->top__DOT__alu_result))) {
				vlTOPp->top__DOT__data_memory 
				    = ((0xffff0000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__data_mem1__DOT__mem
								   [
								   (0x7fffU 
								    & (vlTOPp->top__DOT__alu_result 
								       >> 2U))] 
								   >> 0xfU)))) 
					   << 0x10U)) 
				       | (0xffffU & 
					  vlTOPp->top__DOT__data_mem1__DOT__mem
					  [(0x7fffU 
					    & (vlTOPp->top__DOT__alu_result 
					       >> 2U))]));
			    } else {
				if ((1U == (3U & vlTOPp->top__DOT__alu_result))) {
				    vlTOPp->top__DOT__data_memory 
					= ((0xffff0000U 
					    & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlTOPp->top__DOT__data_mem1__DOT__mem
								       [
								       (0x7fffU 
									& (vlTOPp->top__DOT__alu_result 
									   >> 2U))] 
								       >> 0x17U)))) 
					       << 0x10U)) 
					   | (0xffffU 
					      & (vlTOPp->top__DOT__data_mem1__DOT__mem
						 [(0x7fffU 
						   & (vlTOPp->top__DOT__alu_result 
						      >> 2U))] 
						 >> 8U)));
				} else {
				    if ((2U == (3U 
						& vlTOPp->top__DOT__alu_result))) {
					vlTOPp->top__DOT__data_memory 
					    = ((0xffff0000U 
						& (VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->top__DOT__data_mem1__DOT__mem
									   [
									   (0x7fffU 
									    & (vlTOPp->top__DOT__alu_result 
									       >> 2U))] 
									   >> 0x1fU)))) 
						   << 0x10U)) 
					       | (0xffffU 
						  & (vlTOPp->top__DOT__data_mem1__DOT__mem
						     [
						     (0x7fffU 
						      & (vlTOPp->top__DOT__alu_result 
							 >> 2U))] 
						     >> 0x10U)));
				    }
				}
			    }
			}
		    } else {
			vlTOPp->top__DOT__data_memory 
			    = ((1U & (IData)(vlTOPp->top__DOT__alucode))
			        ? ((0U == (3U & vlTOPp->top__DOT__alu_result))
				    ? ((0xffffff00U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__data_mem1__DOT__mem
								   [
								   (0x7fffU 
								    & (vlTOPp->top__DOT__alu_result 
								       >> 2U))] 
								   >> 7U)))) 
					   << 8U)) 
				       | (0xffU & vlTOPp->top__DOT__data_mem1__DOT__mem
					  [(0x7fffU 
					    & (vlTOPp->top__DOT__alu_result 
					       >> 2U))]))
				    : ((1U == (3U & vlTOPp->top__DOT__alu_result))
				        ? ((0xffffff00U 
					    & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlTOPp->top__DOT__data_mem1__DOT__mem
								       [
								       (0x7fffU 
									& (vlTOPp->top__DOT__alu_result 
									   >> 2U))] 
								       >> 0xfU)))) 
					       << 8U)) 
					   | (0xffU 
					      & (vlTOPp->top__DOT__data_mem1__DOT__mem
						 [(0x7fffU 
						   & (vlTOPp->top__DOT__alu_result 
						      >> 2U))] 
						 >> 8U)))
				        : ((2U == (3U 
						   & vlTOPp->top__DOT__alu_result))
					    ? ((0xffffff00U 
						& (VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->top__DOT__data_mem1__DOT__mem
									   [
									   (0x7fffU 
									    & (vlTOPp->top__DOT__alu_result 
									       >> 2U))] 
									   >> 0x17U)))) 
						   << 8U)) 
					       | (0xffU 
						  & (vlTOPp->top__DOT__data_mem1__DOT__mem
						     [
						     (0x7fffU 
						      & (vlTOPp->top__DOT__alu_result 
							 >> 2U))] 
						     >> 0x10U)))
					    : ((0xffffff00U 
						& (VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->top__DOT__data_mem1__DOT__mem
									   [
									   (0x7fffU 
									    & (vlTOPp->top__DOT__alu_result 
									       >> 2U))] 
									   >> 0x1fU)))) 
						   << 8U)) 
					       | (0xffU 
						  & (vlTOPp->top__DOT__data_mem1__DOT__mem
						     [
						     (0x7fffU 
						      & (vlTOPp->top__DOT__alu_result 
							 >> 2U))] 
						     >> 0x18U))))))
			        : vlTOPp->top__DOT__data_mem1__DOT__mem
			       [(0x7fffU & (vlTOPp->top__DOT__alu_result 
					    >> 2U))]);
		    }
		}
	    } else {
		vlTOPp->top__DOT__data_memory = vlTOPp->top__DOT__data_mem1__DOT__mem
		    [(0x7fffU & (vlTOPp->top__DOT__alu_result 
				 >> 2U))];
	    }
	}
    }
    if ((0U == (3U & vlTOPp->top__DOT__alu_result))) {
	if ((1U & (IData)(vlTOPp->top__DOT__we))) {
	    vlTOPp->top__DOT__data_mem1__DOT__mem[(0x7fffU 
						   & (vlTOPp->top__DOT__alu_result 
						      >> 2U))] 
		= ((0xffffff00U & vlTOPp->top__DOT__data_mem1__DOT__mem
		    [(0x7fffU & (vlTOPp->top__DOT__alu_result 
				 >> 2U))]) | (0xffU 
					      & vlTOPp->top__DOT__w_data_memo));
	}
	if ((2U & (IData)(vlTOPp->top__DOT__we))) {
	    vlTOPp->top__DOT__data_mem1__DOT__mem[(0x7fffU 
						   & (vlTOPp->top__DOT__alu_result 
						      >> 2U))] 
		= ((0xffff00ffU & vlTOPp->top__DOT__data_mem1__DOT__mem
		    [(0x7fffU & (vlTOPp->top__DOT__alu_result 
				 >> 2U))]) | (0xff00U 
					      & vlTOPp->top__DOT__w_data_memo));
	}
	if ((4U & (IData)(vlTOPp->top__DOT__we))) {
	    vlTOPp->top__DOT__data_mem1__DOT__mem[(0x7fffU 
						   & (vlTOPp->top__DOT__alu_result 
						      >> 2U))] 
		= ((0xff00ffffU & vlTOPp->top__DOT__data_mem1__DOT__mem
		    [(0x7fffU & (vlTOPp->top__DOT__alu_result 
				 >> 2U))]) | (0xff0000U 
					      & vlTOPp->top__DOT__w_data_memo));
	}
	if ((8U & (IData)(vlTOPp->top__DOT__we))) {
	    vlTOPp->top__DOT__data_mem1__DOT__mem[(0x7fffU 
						   & (vlTOPp->top__DOT__alu_result 
						      >> 2U))] 
		= ((0xffffffU & vlTOPp->top__DOT__data_mem1__DOT__mem
		    [(0x7fffU & (vlTOPp->top__DOT__alu_result 
				 >> 2U))]) | (0xff000000U 
					      & vlTOPp->top__DOT__w_data_memo));
	}
    } else {
	if ((1U == (3U & vlTOPp->top__DOT__alu_result))) {
	    if ((1U & (IData)(vlTOPp->top__DOT__we))) {
		vlTOPp->top__DOT__data_mem1__DOT__mem[(0x7fffU 
						       & (vlTOPp->top__DOT__alu_result 
							  >> 2U))] 
		    = ((0xffff00ffU & vlTOPp->top__DOT__data_mem1__DOT__mem
			[(0x7fffU & (vlTOPp->top__DOT__alu_result 
				     >> 2U))]) | (0xff00U 
						  & (vlTOPp->top__DOT__w_data_memo 
						     << 8U)));
	    }
	    if ((2U & (IData)(vlTOPp->top__DOT__we))) {
		vlTOPp->top__DOT__data_mem1__DOT__mem[(0x7fffU 
						       & (vlTOPp->top__DOT__alu_result 
							  >> 2U))] 
		    = ((0xff00ffffU & vlTOPp->top__DOT__data_mem1__DOT__mem
			[(0x7fffU & (vlTOPp->top__DOT__alu_result 
				     >> 2U))]) | (0xff0000U 
						  & (vlTOPp->top__DOT__w_data_memo 
						     << 8U)));
	    }
	    if ((4U & (IData)(vlTOPp->top__DOT__we))) {
		vlTOPp->top__DOT__data_mem1__DOT__mem[(0x7fffU 
						       & (vlTOPp->top__DOT__alu_result 
							  >> 2U))] 
		    = ((0xffffffU & vlTOPp->top__DOT__data_mem1__DOT__mem
			[(0x7fffU & (vlTOPp->top__DOT__alu_result 
				     >> 2U))]) | (0xff000000U 
						  & (vlTOPp->top__DOT__w_data_memo 
						     << 8U)));
	    }
	} else {
	    if ((2U == (3U & vlTOPp->top__DOT__alu_result))) {
		if ((1U & (IData)(vlTOPp->top__DOT__we))) {
		    vlTOPp->top__DOT__data_mem1__DOT__mem[(0x7fffU 
							   & (vlTOPp->top__DOT__alu_result 
							      >> 2U))] 
			= ((0xff00ffffU & vlTOPp->top__DOT__data_mem1__DOT__mem
			    [(0x7fffU & (vlTOPp->top__DOT__alu_result 
					 >> 2U))]) 
			   | (0xff0000U & (vlTOPp->top__DOT__w_data_memo 
					   << 0x10U)));
		}
		if ((2U & (IData)(vlTOPp->top__DOT__we))) {
		    vlTOPp->top__DOT__data_mem1__DOT__mem[(0x7fffU 
							   & (vlTOPp->top__DOT__alu_result 
							      >> 2U))] 
			= ((0xffffffU & vlTOPp->top__DOT__data_mem1__DOT__mem
			    [(0x7fffU & (vlTOPp->top__DOT__alu_result 
					 >> 2U))]) 
			   | (0xff000000U & (vlTOPp->top__DOT__w_data_memo 
					     << 0x10U)));
		}
	    } else {
		if ((3U == (3U & vlTOPp->top__DOT__alu_result))) {
		    if ((1U & (IData)(vlTOPp->top__DOT__we))) {
			vlTOPp->top__DOT__data_mem1__DOT__mem[(0x7fffU 
							       & (vlTOPp->top__DOT__alu_result 
								  >> 2U))] 
			    = ((0xffffffU & vlTOPp->top__DOT__data_mem1__DOT__mem
				[(0x7fffU & (vlTOPp->top__DOT__alu_result 
					     >> 2U))]) 
			       | (0xff000000U & (vlTOPp->top__DOT__w_data_memo 
						 << 0x18U)));
		    }
		}
	    }
	}
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at reg_file.v:41
    if (vlTOPp->top__DOT__reg_we) {
	if ((0U != (IData)(vlTOPp->top__DOT__dstreg_num))) {
	    vlTOPp->top__DOT__reg_file1__DOT__mem[vlTOPp->top__DOT__dstreg_num] 
		= vlTOPp->top__DOT__w_data;
	}
    }
    // ALWAYS at instruction.v:39
    vlTOPp->top__DOT__ir = vlTOPp->top__DOT__instuction1__DOT__mem
	[(0x7fffU & (vlTOPp->top__DOT__nextPc >> 2U))];
    // ALWAYS at decoder.v:51
    if ((0x40U & vlTOPp->top__DOT__ir)) {
	if ((0x20U & vlTOPp->top__DOT__ir)) {
	    if ((1U & (~ (vlTOPp->top__DOT__ir >> 4U)))) {
		if ((8U & vlTOPp->top__DOT__ir)) {
		    if ((4U & vlTOPp->top__DOT__ir)) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__imm 
				    = ((0xffe00000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__ir 
								   >> 0x1fU)))) 
					   << 0x15U)) 
				       | ((0x100000U 
					   & (vlTOPp->top__DOT__ir 
					      >> 0xbU)) 
					  | ((0xff000U 
					      & vlTOPp->top__DOT__ir) 
					     | ((0x800U 
						 & (vlTOPp->top__DOT__ir 
						    >> 9U)) 
						| (0x7feU 
						   & (vlTOPp->top__DOT__ir 
						      >> 0x14U))))));
				vlTOPp->top__DOT__srcreg1_num = 0U;
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__alucode = 1U;
				vlTOPp->top__DOT__aluop1_type = 0U;
				vlTOPp->top__DOT__aluop2_type = 3U;
				vlTOPp->top__DOT__reg_we 
				    = (0U != (IData)(vlTOPp->top__DOT__dstreg_num));
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
			    }
			}
		    }
		} else {
		    if ((4U & vlTOPp->top__DOT__ir)) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__imm 
				    = ((0xfffff000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__ir 
								   >> 0x1fU)))) 
					   << 0xcU)) 
				       | (0xfffU & 
					  (vlTOPp->top__DOT__ir 
					   >> 0x14U)));
				vlTOPp->top__DOT__alucode = 2U;
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__aluop2_type = 3U;
				if ((0U == (IData)(vlTOPp->top__DOT__dstreg_num))) {
				    vlTOPp->top__DOT__reg_we = 0U;
				} else {
				    if ((1U == (IData)(vlTOPp->top__DOT__dstreg_num))) {
					vlTOPp->top__DOT__reg_we = 1U;
				    }
				}
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
			    }
			}
		    } else {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__imm 
				    = ((0xffffe000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__ir 
								   >> 0x1fU)))) 
					   << 0xdU)) 
				       | ((0x1000U 
					   & (vlTOPp->top__DOT__ir 
					      >> 0x13U)) 
					  | ((0x800U 
					      & (vlTOPp->top__DOT__ir 
						 << 4U)) 
					     | ((0x7e0U 
						 & (vlTOPp->top__DOT__ir 
						    >> 0x14U)) 
						| (0x1eU 
						   & (vlTOPp->top__DOT__ir 
						      >> 7U))))));
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0x14U));
				vlTOPp->top__DOT__dstreg_num = 0U;
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__aluop2_type = 1U;
				vlTOPp->top__DOT__reg_we = 0U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
				if ((0x4000U & vlTOPp->top__DOT__ir)) {
				    vlTOPp->top__DOT__alucode 
					= ((0x2000U 
					    & vlTOPp->top__DOT__ir)
					    ? ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 8U
					        : 7U)
					    : ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 6U
					        : 5U));
				} else {
				    if ((1U & (~ (vlTOPp->top__DOT__ir 
						  >> 0xdU)))) {
					vlTOPp->top__DOT__alucode 
					    = ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 4U
					        : 3U);
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((0x20U & vlTOPp->top__DOT__ir)) {
	    if ((0x10U & vlTOPp->top__DOT__ir)) {
		if ((1U & (~ (vlTOPp->top__DOT__ir 
			      >> 3U)))) {
		    if ((4U & vlTOPp->top__DOT__ir)) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__srcreg1_num = 0U;
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__imm 
				    = (0xfffff000U 
				       & vlTOPp->top__DOT__ir);
				vlTOPp->top__DOT__alucode = 0U;
				vlTOPp->top__DOT__aluop1_type = 0U;
				vlTOPp->top__DOT__aluop2_type = 2U;
				vlTOPp->top__DOT__reg_we = 1U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
			    }
			}
		    } else {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0x14U));
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__imm = 0U;
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__aluop2_type = 1U;
				vlTOPp->top__DOT__reg_we = 1U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
				if ((0x4000U & vlTOPp->top__DOT__ir)) {
				    if ((0x2000U & vlTOPp->top__DOT__ir)) {
					vlTOPp->top__DOT__alucode 
					    = ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 0x17U
					        : 0x16U);
				    } else {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    if ((0x40000000U 
						 & vlTOPp->top__DOT__ir)) {
						if (
						    (0x40000000U 
						     & vlTOPp->top__DOT__ir)) {
						    vlTOPp->top__DOT__alucode = 0x1aU;
						}
					    } else {
						vlTOPp->top__DOT__alucode = 0x19U;
					    }
					} else {
					    vlTOPp->top__DOT__alucode = 0x15U;
					}
				    }
				} else {
				    if ((0x2000U & vlTOPp->top__DOT__ir)) {
					vlTOPp->top__DOT__alucode 
					    = ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 0x14U
					        : 0x13U);
				    } else {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    vlTOPp->top__DOT__alucode = 0x18U;
					} else {
					    if ((0x40000000U 
						 & vlTOPp->top__DOT__ir)) {
						if (
						    (0x40000000U 
						     & vlTOPp->top__DOT__ir)) {
						    vlTOPp->top__DOT__alucode = 0x12U;
						}
					    } else {
						vlTOPp->top__DOT__alucode = 0x11U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if ((1U & (~ (vlTOPp->top__DOT__ir 
			      >> 3U)))) {
		    if ((1U & (~ (vlTOPp->top__DOT__ir 
				  >> 2U)))) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__imm 
				    = ((0xfffff000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__ir 
								   >> 0x1fU)))) 
					   << 0xcU)) 
				       | ((0xfe0U & 
					   (vlTOPp->top__DOT__ir 
					    >> 0x14U)) 
					  | (0x1fU 
					     & (vlTOPp->top__DOT__ir 
						>> 7U))));
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0x14U));
				vlTOPp->top__DOT__dstreg_num = 0U;
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__aluop2_type = 2U;
				vlTOPp->top__DOT__reg_we = 0U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 1U;
				if ((0U == (7U & (vlTOPp->top__DOT__ir 
						  >> 0xcU)))) {
				    vlTOPp->top__DOT__alucode = 0xeU;
				} else {
				    if ((1U == (7U 
						& (vlTOPp->top__DOT__ir 
						   >> 0xcU)))) {
					vlTOPp->top__DOT__alucode = 0xfU;
				    } else {
					if ((2U == 
					     (7U & 
					      (vlTOPp->top__DOT__ir 
					       >> 0xcU)))) {
					    vlTOPp->top__DOT__alucode = 0x10U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if ((0x10U & vlTOPp->top__DOT__ir)) {
		if ((1U & (~ (vlTOPp->top__DOT__ir 
			      >> 3U)))) {
		    if ((4U & vlTOPp->top__DOT__ir)) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__srcreg1_num = 0U;
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__imm 
				    = (0xfffff000U 
				       & vlTOPp->top__DOT__ir);
				vlTOPp->top__DOT__alucode = 0x11U;
				vlTOPp->top__DOT__aluop1_type = 2U;
				vlTOPp->top__DOT__aluop2_type = 3U;
				vlTOPp->top__DOT__reg_we = 1U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
			    }
			}
		    } else {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__reg_we = 1U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
				if ((0x4000U & vlTOPp->top__DOT__ir)) {
				    if ((0x2000U & vlTOPp->top__DOT__ir)) {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    vlTOPp->top__DOT__alucode = 0x17U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					} else {
					    vlTOPp->top__DOT__alucode = 0x16U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					}
				    } else {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xffffffe0U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x18U)))) 
						       << 5U)) 
						   | (0x1fU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					    if ((0x40000000U 
						 & vlTOPp->top__DOT__ir)) {
						if (
						    (0x40000000U 
						     & vlTOPp->top__DOT__ir)) {
						    vlTOPp->top__DOT__alucode = 0x1aU;
						}
					    } else {
						vlTOPp->top__DOT__alucode = 0x19U;
					    }
					} else {
					    vlTOPp->top__DOT__alucode = 0x15U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					}
				    }
				} else {
				    if ((0x2000U & vlTOPp->top__DOT__ir)) {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    vlTOPp->top__DOT__alucode = 0x14U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					} else {
					    vlTOPp->top__DOT__alucode = 0x13U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					}
				    } else {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    vlTOPp->top__DOT__alucode = 0x18U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xffffffe0U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 5U)) 
						   | (0x1fU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					} else {
					    vlTOPp->top__DOT__alucode = 0x11U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if ((1U & (~ (vlTOPp->top__DOT__ir 
			      >> 3U)))) {
		    if ((1U & (~ (vlTOPp->top__DOT__ir 
				  >> 2U)))) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__imm 
				    = ((0xfffff000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__ir 
								   >> 0x1fU)))) 
					   << 0xcU)) 
				       | (0xfffU & 
					  (vlTOPp->top__DOT__ir 
					   >> 0x14U)));
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__aluop2_type = 2U;
				vlTOPp->top__DOT__reg_we = 1U;
				vlTOPp->top__DOT__is_load = 1U;
				vlTOPp->top__DOT__is_store = 0U;
				if ((0x4000U & vlTOPp->top__DOT__ir)) {
				    if ((1U & (~ (vlTOPp->top__DOT__ir 
						  >> 0xdU)))) {
					vlTOPp->top__DOT__alucode 
					    = ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 0xdU
					        : 0xcU);
				    }
				} else {
				    if ((0x2000U & vlTOPp->top__DOT__ir)) {
					if ((1U & (~ 
						   (vlTOPp->top__DOT__ir 
						    >> 0xcU)))) {
					    vlTOPp->top__DOT__alucode = 0xbU;
					}
				    } else {
					vlTOPp->top__DOT__alucode 
					    = ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 0xaU
					        : 9U);
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at store_load.v:13
    if ((0xeU == (IData)(vlTOPp->top__DOT__alucode))) {
	vlTOPp->top__DOT__we = (1U | (IData)(vlTOPp->top__DOT__we));
	vlTOPp->top__DOT__we = (0xdU & (IData)(vlTOPp->top__DOT__we));
	vlTOPp->top__DOT__we = (0xbU & (IData)(vlTOPp->top__DOT__we));
	vlTOPp->top__DOT__we = (7U & (IData)(vlTOPp->top__DOT__we));
    } else {
	if ((0xfU == (IData)(vlTOPp->top__DOT__alucode))) {
	    vlTOPp->top__DOT__we = (1U | (IData)(vlTOPp->top__DOT__we));
	    vlTOPp->top__DOT__we = (2U | (IData)(vlTOPp->top__DOT__we));
	    vlTOPp->top__DOT__we = (0xbU & (IData)(vlTOPp->top__DOT__we));
	    vlTOPp->top__DOT__we = (7U & (IData)(vlTOPp->top__DOT__we));
	} else {
	    if ((0x10U == (IData)(vlTOPp->top__DOT__alucode))) {
		vlTOPp->top__DOT__we = (1U | (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (2U | (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (4U | (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (8U | (IData)(vlTOPp->top__DOT__we));
	    } else {
		vlTOPp->top__DOT__we = (0xeU & (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (0xdU & (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (0xbU & (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (7U & (IData)(vlTOPp->top__DOT__we));
	    }
	}
    }
    // ALWAYS at multiplexer.v:43
    vlTOPp->top__DOT__op1 = ((1U == (IData)(vlTOPp->top__DOT__aluop1_type))
			      ? vlTOPp->top__DOT__reg_file1__DOT__mem
			     [vlTOPp->top__DOT__srcreg1_num]
			      : ((2U == (IData)(vlTOPp->top__DOT__aluop1_type))
				  ? vlTOPp->top__DOT__imm
				  : 0U));
    vlTOPp->top__DOT__rs2_data = vlTOPp->top__DOT__reg_file1__DOT__mem
	[vlTOPp->top__DOT__srcreg2_num];
}

void Vtop::_settle__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->uart_tx = vlTOPp->top__DOT__uart_OUT_data;
    vlTOPp->top__DOT__uart0__DOT__uart_busy = (0U != 
					       (7U 
						& ((IData)(vlTOPp->top__DOT__uart0__DOT__bitcount) 
						   >> 1U)));
    vlTOPp->top__DOT__uart0__DOT__sending = (0U != (IData)(vlTOPp->top__DOT__uart0__DOT__bitcount));
    // ALWAYS at decoder.v:51
    if ((0x40U & vlTOPp->top__DOT__ir)) {
	if ((0x20U & vlTOPp->top__DOT__ir)) {
	    if ((1U & (~ (vlTOPp->top__DOT__ir >> 4U)))) {
		if ((8U & vlTOPp->top__DOT__ir)) {
		    if ((4U & vlTOPp->top__DOT__ir)) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__imm 
				    = ((0xffe00000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__ir 
								   >> 0x1fU)))) 
					   << 0x15U)) 
				       | ((0x100000U 
					   & (vlTOPp->top__DOT__ir 
					      >> 0xbU)) 
					  | ((0xff000U 
					      & vlTOPp->top__DOT__ir) 
					     | ((0x800U 
						 & (vlTOPp->top__DOT__ir 
						    >> 9U)) 
						| (0x7feU 
						   & (vlTOPp->top__DOT__ir 
						      >> 0x14U))))));
				vlTOPp->top__DOT__srcreg1_num = 0U;
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__alucode = 1U;
				vlTOPp->top__DOT__aluop1_type = 0U;
				vlTOPp->top__DOT__aluop2_type = 3U;
				vlTOPp->top__DOT__reg_we 
				    = (0U != (IData)(vlTOPp->top__DOT__dstreg_num));
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
			    }
			}
		    }
		} else {
		    if ((4U & vlTOPp->top__DOT__ir)) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__imm 
				    = ((0xfffff000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__ir 
								   >> 0x1fU)))) 
					   << 0xcU)) 
				       | (0xfffU & 
					  (vlTOPp->top__DOT__ir 
					   >> 0x14U)));
				vlTOPp->top__DOT__alucode = 2U;
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__aluop2_type = 3U;
				if ((0U == (IData)(vlTOPp->top__DOT__dstreg_num))) {
				    vlTOPp->top__DOT__reg_we = 0U;
				} else {
				    if ((1U == (IData)(vlTOPp->top__DOT__dstreg_num))) {
					vlTOPp->top__DOT__reg_we = 1U;
				    }
				}
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
			    }
			}
		    } else {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__imm 
				    = ((0xffffe000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__ir 
								   >> 0x1fU)))) 
					   << 0xdU)) 
				       | ((0x1000U 
					   & (vlTOPp->top__DOT__ir 
					      >> 0x13U)) 
					  | ((0x800U 
					      & (vlTOPp->top__DOT__ir 
						 << 4U)) 
					     | ((0x7e0U 
						 & (vlTOPp->top__DOT__ir 
						    >> 0x14U)) 
						| (0x1eU 
						   & (vlTOPp->top__DOT__ir 
						      >> 7U))))));
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0x14U));
				vlTOPp->top__DOT__dstreg_num = 0U;
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__aluop2_type = 1U;
				vlTOPp->top__DOT__reg_we = 0U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
				if ((0x4000U & vlTOPp->top__DOT__ir)) {
				    vlTOPp->top__DOT__alucode 
					= ((0x2000U 
					    & vlTOPp->top__DOT__ir)
					    ? ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 8U
					        : 7U)
					    : ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 6U
					        : 5U));
				} else {
				    if ((1U & (~ (vlTOPp->top__DOT__ir 
						  >> 0xdU)))) {
					vlTOPp->top__DOT__alucode 
					    = ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 4U
					        : 3U);
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    } else {
	if ((0x20U & vlTOPp->top__DOT__ir)) {
	    if ((0x10U & vlTOPp->top__DOT__ir)) {
		if ((1U & (~ (vlTOPp->top__DOT__ir 
			      >> 3U)))) {
		    if ((4U & vlTOPp->top__DOT__ir)) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__srcreg1_num = 0U;
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__imm 
				    = (0xfffff000U 
				       & vlTOPp->top__DOT__ir);
				vlTOPp->top__DOT__alucode = 0U;
				vlTOPp->top__DOT__aluop1_type = 0U;
				vlTOPp->top__DOT__aluop2_type = 2U;
				vlTOPp->top__DOT__reg_we = 1U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
			    }
			}
		    } else {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0x14U));
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__imm = 0U;
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__aluop2_type = 1U;
				vlTOPp->top__DOT__reg_we = 1U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
				if ((0x4000U & vlTOPp->top__DOT__ir)) {
				    if ((0x2000U & vlTOPp->top__DOT__ir)) {
					vlTOPp->top__DOT__alucode 
					    = ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 0x17U
					        : 0x16U);
				    } else {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    if ((0x40000000U 
						 & vlTOPp->top__DOT__ir)) {
						if (
						    (0x40000000U 
						     & vlTOPp->top__DOT__ir)) {
						    vlTOPp->top__DOT__alucode = 0x1aU;
						}
					    } else {
						vlTOPp->top__DOT__alucode = 0x19U;
					    }
					} else {
					    vlTOPp->top__DOT__alucode = 0x15U;
					}
				    }
				} else {
				    if ((0x2000U & vlTOPp->top__DOT__ir)) {
					vlTOPp->top__DOT__alucode 
					    = ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 0x14U
					        : 0x13U);
				    } else {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    vlTOPp->top__DOT__alucode = 0x18U;
					} else {
					    if ((0x40000000U 
						 & vlTOPp->top__DOT__ir)) {
						if (
						    (0x40000000U 
						     & vlTOPp->top__DOT__ir)) {
						    vlTOPp->top__DOT__alucode = 0x12U;
						}
					    } else {
						vlTOPp->top__DOT__alucode = 0x11U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if ((1U & (~ (vlTOPp->top__DOT__ir 
			      >> 3U)))) {
		    if ((1U & (~ (vlTOPp->top__DOT__ir 
				  >> 2U)))) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__imm 
				    = ((0xfffff000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__ir 
								   >> 0x1fU)))) 
					   << 0xcU)) 
				       | ((0xfe0U & 
					   (vlTOPp->top__DOT__ir 
					    >> 0x14U)) 
					  | (0x1fU 
					     & (vlTOPp->top__DOT__ir 
						>> 7U))));
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0x14U));
				vlTOPp->top__DOT__dstreg_num = 0U;
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__aluop2_type = 2U;
				vlTOPp->top__DOT__reg_we = 0U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 1U;
				if ((0U == (7U & (vlTOPp->top__DOT__ir 
						  >> 0xcU)))) {
				    vlTOPp->top__DOT__alucode = 0xeU;
				} else {
				    if ((1U == (7U 
						& (vlTOPp->top__DOT__ir 
						   >> 0xcU)))) {
					vlTOPp->top__DOT__alucode = 0xfU;
				    } else {
					if ((2U == 
					     (7U & 
					      (vlTOPp->top__DOT__ir 
					       >> 0xcU)))) {
					    vlTOPp->top__DOT__alucode = 0x10U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if ((0x10U & vlTOPp->top__DOT__ir)) {
		if ((1U & (~ (vlTOPp->top__DOT__ir 
			      >> 3U)))) {
		    if ((4U & vlTOPp->top__DOT__ir)) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__srcreg1_num = 0U;
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__imm 
				    = (0xfffff000U 
				       & vlTOPp->top__DOT__ir);
				vlTOPp->top__DOT__alucode = 0x11U;
				vlTOPp->top__DOT__aluop1_type = 2U;
				vlTOPp->top__DOT__aluop2_type = 3U;
				vlTOPp->top__DOT__reg_we = 1U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
			    }
			}
		    } else {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__reg_we = 1U;
				vlTOPp->top__DOT__is_load = 0U;
				vlTOPp->top__DOT__is_store = 0U;
				if ((0x4000U & vlTOPp->top__DOT__ir)) {
				    if ((0x2000U & vlTOPp->top__DOT__ir)) {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    vlTOPp->top__DOT__alucode = 0x17U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					} else {
					    vlTOPp->top__DOT__alucode = 0x16U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					}
				    } else {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xffffffe0U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x18U)))) 
						       << 5U)) 
						   | (0x1fU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					    if ((0x40000000U 
						 & vlTOPp->top__DOT__ir)) {
						if (
						    (0x40000000U 
						     & vlTOPp->top__DOT__ir)) {
						    vlTOPp->top__DOT__alucode = 0x1aU;
						}
					    } else {
						vlTOPp->top__DOT__alucode = 0x19U;
					    }
					} else {
					    vlTOPp->top__DOT__alucode = 0x15U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					}
				    }
				} else {
				    if ((0x2000U & vlTOPp->top__DOT__ir)) {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    vlTOPp->top__DOT__alucode = 0x14U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					} else {
					    vlTOPp->top__DOT__alucode = 0x13U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					}
				    } else {
					if ((0x1000U 
					     & vlTOPp->top__DOT__ir)) {
					    vlTOPp->top__DOT__alucode = 0x18U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xffffffe0U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 5U)) 
						   | (0x1fU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					} else {
					    vlTOPp->top__DOT__alucode = 0x11U;
					    vlTOPp->top__DOT__aluop2_type = 2U;
					    vlTOPp->top__DOT__imm 
						= (
						   (0xfffff000U 
						    & (VL_NEGATE_I((IData)(
									   (1U 
									    & (vlTOPp->top__DOT__ir 
									       >> 0x1fU)))) 
						       << 0xcU)) 
						   | (0xfffU 
						      & (vlTOPp->top__DOT__ir 
							 >> 0x14U)));
					}
				    }
				}
			    }
			}
		    }
		}
	    } else {
		if ((1U & (~ (vlTOPp->top__DOT__ir 
			      >> 3U)))) {
		    if ((1U & (~ (vlTOPp->top__DOT__ir 
				  >> 2U)))) {
			if ((2U & vlTOPp->top__DOT__ir)) {
			    if ((1U & vlTOPp->top__DOT__ir)) {
				vlTOPp->top__DOT__srcreg1_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 0xfU));
				vlTOPp->top__DOT__srcreg2_num = 0U;
				vlTOPp->top__DOT__dstreg_num 
				    = (0x1fU & (vlTOPp->top__DOT__ir 
						>> 7U));
				vlTOPp->top__DOT__imm 
				    = ((0xfffff000U 
					& (VL_NEGATE_I((IData)(
							       (1U 
								& (vlTOPp->top__DOT__ir 
								   >> 0x1fU)))) 
					   << 0xcU)) 
				       | (0xfffU & 
					  (vlTOPp->top__DOT__ir 
					   >> 0x14U)));
				vlTOPp->top__DOT__aluop1_type = 1U;
				vlTOPp->top__DOT__aluop2_type = 2U;
				vlTOPp->top__DOT__reg_we = 1U;
				vlTOPp->top__DOT__is_load = 1U;
				vlTOPp->top__DOT__is_store = 0U;
				if ((0x4000U & vlTOPp->top__DOT__ir)) {
				    if ((1U & (~ (vlTOPp->top__DOT__ir 
						  >> 0xdU)))) {
					vlTOPp->top__DOT__alucode 
					    = ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 0xdU
					        : 0xcU);
				    }
				} else {
				    if ((0x2000U & vlTOPp->top__DOT__ir)) {
					if ((1U & (~ 
						   (vlTOPp->top__DOT__ir 
						    >> 0xcU)))) {
					    vlTOPp->top__DOT__alucode = 0xbU;
					}
				    } else {
					vlTOPp->top__DOT__alucode 
					    = ((0x1000U 
						& vlTOPp->top__DOT__ir)
					        ? 0xaU
					        : 9U);
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    vlTOPp->top__DOT__uart0__DOT__dNxt = (0x1fffffffU 
					  & (vlTOPp->top__DOT__uart0__DOT__d 
					     + ((0x10000000U 
						 & vlTOPp->top__DOT__uart0__DOT__d)
						 ? 0x1c200U
						 : 0xff692b80U)));
    // ALWAYS at store_load.v:13
    if ((0xeU == (IData)(vlTOPp->top__DOT__alucode))) {
	vlTOPp->top__DOT__we = (1U | (IData)(vlTOPp->top__DOT__we));
	vlTOPp->top__DOT__we = (0xdU & (IData)(vlTOPp->top__DOT__we));
	vlTOPp->top__DOT__we = (0xbU & (IData)(vlTOPp->top__DOT__we));
	vlTOPp->top__DOT__we = (7U & (IData)(vlTOPp->top__DOT__we));
    } else {
	if ((0xfU == (IData)(vlTOPp->top__DOT__alucode))) {
	    vlTOPp->top__DOT__we = (1U | (IData)(vlTOPp->top__DOT__we));
	    vlTOPp->top__DOT__we = (2U | (IData)(vlTOPp->top__DOT__we));
	    vlTOPp->top__DOT__we = (0xbU & (IData)(vlTOPp->top__DOT__we));
	    vlTOPp->top__DOT__we = (7U & (IData)(vlTOPp->top__DOT__we));
	} else {
	    if ((0x10U == (IData)(vlTOPp->top__DOT__alucode))) {
		vlTOPp->top__DOT__we = (1U | (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (2U | (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (4U | (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (8U | (IData)(vlTOPp->top__DOT__we));
	    } else {
		vlTOPp->top__DOT__we = (0xeU & (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (0xdU & (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (0xbU & (IData)(vlTOPp->top__DOT__we));
		vlTOPp->top__DOT__we = (7U & (IData)(vlTOPp->top__DOT__we));
	    }
	}
    }
    // ALWAYS at multiplexer.v:43
    vlTOPp->top__DOT__op1 = ((1U == (IData)(vlTOPp->top__DOT__aluop1_type))
			      ? vlTOPp->top__DOT__reg_file1__DOT__mem
			     [vlTOPp->top__DOT__srcreg1_num]
			      : ((2U == (IData)(vlTOPp->top__DOT__aluop1_type))
				  ? vlTOPp->top__DOT__imm
				  : 0U));
    vlTOPp->top__DOT__rs2_data = vlTOPp->top__DOT__reg_file1__DOT__mem
	[vlTOPp->top__DOT__srcreg2_num];
    // ALWAYS at multiplexer.v:43
    vlTOPp->top__DOT__op2 = ((2U & (IData)(vlTOPp->top__DOT__aluop2_type))
			      ? ((1U & (IData)(vlTOPp->top__DOT__aluop2_type))
				  ? vlTOPp->top__DOT__pc
				  : vlTOPp->top__DOT__imm)
			      : ((1U & (IData)(vlTOPp->top__DOT__aluop2_type))
				  ? vlTOPp->top__DOT__rs2_data
				  : 0U));
    // ALWAYS at alu.v:33
    if ((0x20U & (IData)(vlTOPp->top__DOT__alucode))) {
	vlTOPp->top__DOT__alu_result = 0U;
	vlTOPp->top__DOT__br_taken = 0U;
    } else {
	if ((0x10U & (IData)(vlTOPp->top__DOT__alucode))) {
	    if ((8U & (IData)(vlTOPp->top__DOT__alucode))) {
		if ((4U & (IData)(vlTOPp->top__DOT__alucode))) {
		    vlTOPp->top__DOT__alu_result = 0U;
		    vlTOPp->top__DOT__br_taken = 0U;
		} else {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= ((0x1fU >= (0x3fU 
					      & vlTOPp->top__DOT__op2))
				    ? VL_SHIFTRS_III(32,32,6, vlTOPp->top__DOT__op1, 
						     (0x3fU 
						      & vlTOPp->top__DOT__op2))
				    : VL_NEGATE_I((vlTOPp->top__DOT__op1 
						   >> 0x1fU)));
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= ((0x1fU >= (0x3fU 
					      & vlTOPp->top__DOT__op2))
				    ? (vlTOPp->top__DOT__op1 
				       >> (0x3fU & vlTOPp->top__DOT__op2))
				    : 0U);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= ((0x1fU >= (0x3fU 
					      & vlTOPp->top__DOT__op2))
				    ? (vlTOPp->top__DOT__op1 
				       << (0x3fU & vlTOPp->top__DOT__op2))
				    : 0U);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    }
		}
	    } else {
		if ((4U & (IData)(vlTOPp->top__DOT__alucode))) {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   & vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   | vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   ^ vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= ((vlTOPp->top__DOT__op1 
				    < vlTOPp->top__DOT__op2)
				    ? 1U : 0U);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    }
		} else {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (VL_LTS_III(1,32,32, vlTOPp->top__DOT__op1, vlTOPp->top__DOT__op2)
				    ? 1U : 0U);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   - vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    }
		}
	    }
	} else {
	    if ((8U & (IData)(vlTOPp->top__DOT__alucode))) {
		if ((4U & (IData)(vlTOPp->top__DOT__alucode))) {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    }
		} else {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= (vlTOPp->top__DOT__op2 
				   <= vlTOPp->top__DOT__op1);
			}
		    }
		}
	    } else {
		if ((4U & (IData)(vlTOPp->top__DOT__alucode))) {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= (vlTOPp->top__DOT__op1 
				   < vlTOPp->top__DOT__op2);
			} else {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= VL_LTES_III(1,32,32, vlTOPp->top__DOT__op2, vlTOPp->top__DOT__op1);
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= VL_LTS_III(1,32,32, vlTOPp->top__DOT__op1, vlTOPp->top__DOT__op2);
			} else {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= (vlTOPp->top__DOT__op1 
				   != vlTOPp->top__DOT__op2);
			}
		    }
		} else {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= (vlTOPp->top__DOT__op1 
				   == vlTOPp->top__DOT__op2);
			} else {
			    vlTOPp->top__DOT__alu_result 
				= ((IData)(4U) + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 1U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= ((IData)(4U) + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 1U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= vlTOPp->top__DOT__op2;
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at npc.v:35
    vlTOPp->top__DOT__nextPc = ((IData)(vlTOPp->top__DOT__br_taken)
				 ? (vlTOPp->top__DOT__pc 
				    + vlTOPp->top__DOT__imm)
				 : ((IData)(4U) + vlTOPp->top__DOT__pc));
    // ALWAYS at multiplxer2.v:18
    if (vlTOPp->top__DOT__is_load) {
	vlTOPp->top__DOT__w_data = (((0xbU == (IData)(vlTOPp->top__DOT__alucode)) 
				     & (0xffffff00U 
					== vlTOPp->top__DOT__alu_result))
				     ? vlTOPp->top__DOT__hardware_counter0__DOT__cycles
				     : vlTOPp->top__DOT__data_memory);
	vlTOPp->top__DOT__w_data_memo = 0U;
    } else {
	if (vlTOPp->top__DOT__is_store) {
	    vlTOPp->top__DOT__w_data = vlTOPp->top__DOT__alu_result;
	    vlTOPp->top__DOT__w_data_memo = vlTOPp->top__DOT__rs2_data;
	} else {
	    vlTOPp->top__DOT__w_data = vlTOPp->top__DOT__alu_result;
	}
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at multiplexer.v:43
    vlTOPp->top__DOT__op2 = ((2U & (IData)(vlTOPp->top__DOT__aluop2_type))
			      ? ((1U & (IData)(vlTOPp->top__DOT__aluop2_type))
				  ? vlTOPp->top__DOT__pc
				  : vlTOPp->top__DOT__imm)
			      : ((1U & (IData)(vlTOPp->top__DOT__aluop2_type))
				  ? vlTOPp->top__DOT__rs2_data
				  : 0U));
    // ALWAYS at alu.v:33
    if ((0x20U & (IData)(vlTOPp->top__DOT__alucode))) {
	vlTOPp->top__DOT__alu_result = 0U;
	vlTOPp->top__DOT__br_taken = 0U;
    } else {
	if ((0x10U & (IData)(vlTOPp->top__DOT__alucode))) {
	    if ((8U & (IData)(vlTOPp->top__DOT__alucode))) {
		if ((4U & (IData)(vlTOPp->top__DOT__alucode))) {
		    vlTOPp->top__DOT__alu_result = 0U;
		    vlTOPp->top__DOT__br_taken = 0U;
		} else {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= ((0x1fU >= (0x3fU 
					      & vlTOPp->top__DOT__op2))
				    ? VL_SHIFTRS_III(32,32,6, vlTOPp->top__DOT__op1, 
						     (0x3fU 
						      & vlTOPp->top__DOT__op2))
				    : VL_NEGATE_I((vlTOPp->top__DOT__op1 
						   >> 0x1fU)));
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= ((0x1fU >= (0x3fU 
					      & vlTOPp->top__DOT__op2))
				    ? (vlTOPp->top__DOT__op1 
				       >> (0x3fU & vlTOPp->top__DOT__op2))
				    : 0U);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= ((0x1fU >= (0x3fU 
					      & vlTOPp->top__DOT__op2))
				    ? (vlTOPp->top__DOT__op1 
				       << (0x3fU & vlTOPp->top__DOT__op2))
				    : 0U);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    }
		}
	    } else {
		if ((4U & (IData)(vlTOPp->top__DOT__alucode))) {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   & vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   | vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   ^ vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= ((vlTOPp->top__DOT__op1 
				    < vlTOPp->top__DOT__op2)
				    ? 1U : 0U);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    }
		} else {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (VL_LTS_III(1,32,32, vlTOPp->top__DOT__op1, vlTOPp->top__DOT__op2)
				    ? 1U : 0U);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   - vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    }
		}
	    }
	} else {
	    if ((8U & (IData)(vlTOPp->top__DOT__alucode))) {
		if ((4U & (IData)(vlTOPp->top__DOT__alucode))) {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    }
		} else {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= (vlTOPp->top__DOT__op1 
				   + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 0U;
			} else {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= (vlTOPp->top__DOT__op2 
				   <= vlTOPp->top__DOT__op1);
			}
		    }
		}
	    } else {
		if ((4U & (IData)(vlTOPp->top__DOT__alucode))) {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= (vlTOPp->top__DOT__op1 
				   < vlTOPp->top__DOT__op2);
			} else {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= VL_LTES_III(1,32,32, vlTOPp->top__DOT__op2, vlTOPp->top__DOT__op1);
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= VL_LTS_III(1,32,32, vlTOPp->top__DOT__op1, vlTOPp->top__DOT__op2);
			} else {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= (vlTOPp->top__DOT__op1 
				   != vlTOPp->top__DOT__op2);
			}
		    }
		} else {
		    if ((2U & (IData)(vlTOPp->top__DOT__alucode))) {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result = 0U;
			    vlTOPp->top__DOT__br_taken 
				= (vlTOPp->top__DOT__op1 
				   == vlTOPp->top__DOT__op2);
			} else {
			    vlTOPp->top__DOT__alu_result 
				= ((IData)(4U) + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 1U;
			}
		    } else {
			if ((1U & (IData)(vlTOPp->top__DOT__alucode))) {
			    vlTOPp->top__DOT__alu_result 
				= ((IData)(4U) + vlTOPp->top__DOT__op2);
			    vlTOPp->top__DOT__br_taken = 1U;
			} else {
			    vlTOPp->top__DOT__alu_result 
				= vlTOPp->top__DOT__op2;
			    vlTOPp->top__DOT__br_taken = 0U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at npc.v:35
    vlTOPp->top__DOT__nextPc = ((IData)(vlTOPp->top__DOT__br_taken)
				 ? (vlTOPp->top__DOT__pc 
				    + vlTOPp->top__DOT__imm)
				 : ((IData)(4U) + vlTOPp->top__DOT__pc));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__8\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at multiplxer2.v:18
    if (vlTOPp->top__DOT__is_load) {
	vlTOPp->top__DOT__w_data = (((0xbU == (IData)(vlTOPp->top__DOT__alucode)) 
				     & (0xffffff00U 
					== vlTOPp->top__DOT__alu_result))
				     ? vlTOPp->top__DOT__hardware_counter0__DOT__cycles
				     : vlTOPp->top__DOT__data_memory);
	vlTOPp->top__DOT__w_data_memo = 0U;
    } else {
	if (vlTOPp->top__DOT__is_store) {
	    vlTOPp->top__DOT__w_data = vlTOPp->top__DOT__alu_result;
	    vlTOPp->top__DOT__w_data_memo = vlTOPp->top__DOT__rs2_data;
	} else {
	    vlTOPp->top__DOT__w_data = vlTOPp->top__DOT__alu_result;
	}
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((~ (IData)(vlTOPp->cpu_resetn)) & (IData)(vlTOPp->__Vclklast__TOP__cpu_resetn)) 
	 | ((IData)(vlTOPp->sysclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sysclk))))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->cpu_resetn) & (~ (IData)(vlTOPp->__Vclklast__TOP__cpu_resetn))) 
	 | ((IData)(vlTOPp->sysclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sysclk))))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->sysclk)) & (IData)(vlTOPp->__Vclklast__TOP__sysclk))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->sysclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sysclk)))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((IData)(vlTOPp->cpu_resetn) & (~ (IData)(vlTOPp->__Vclklast__TOP__cpu_resetn))) 
	 | ((IData)(vlTOPp->sysclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sysclk))))) {
	vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if ((((IData)(vlTOPp->cpu_resetn) ^ (IData)(vlTOPp->__Vclklast__TOP__cpu_resetn)) 
	 | ((IData)(vlTOPp->sysclk) ^ (IData)(vlTOPp->__Vclklast__TOP__sysclk)))) {
	vlTOPp->_multiclk__TOP__8(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__cpu_resetn = vlTOPp->cpu_resetn;
    vlTOPp->__Vclklast__TOP__sysclk = vlTOPp->sysclk;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__6(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((sysclk & 0xfeU))) {
	Verilated::overWidthError("sysclk");}
    if (VL_UNLIKELY((cpu_resetn & 0xfeU))) {
	Verilated::overWidthError("cpu_resetn");}
}
#endif // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    sysclk = VL_RAND_RESET_I(1);
    cpu_resetn = VL_RAND_RESET_I(1);
    uart_tx = VL_RAND_RESET_I(1);
    top__DOT__reg_we = VL_RAND_RESET_I(1);
    top__DOT__pc = VL_RAND_RESET_I(32);
    top__DOT__ir = VL_RAND_RESET_I(32);
    top__DOT__srcreg1_num = VL_RAND_RESET_I(5);
    top__DOT__srcreg2_num = VL_RAND_RESET_I(5);
    top__DOT__alu_result = VL_RAND_RESET_I(32);
    top__DOT__dstreg_num = VL_RAND_RESET_I(5);
    top__DOT__imm = VL_RAND_RESET_I(32);
    top__DOT__aluop1_type = VL_RAND_RESET_I(2);
    top__DOT__aluop2_type = VL_RAND_RESET_I(2);
    top__DOT__rs2_data = VL_RAND_RESET_I(32);
    top__DOT__w_data = VL_RAND_RESET_I(32);
    top__DOT__alucode = VL_RAND_RESET_I(6);
    top__DOT__we = VL_RAND_RESET_I(4);
    top__DOT__w_data_memo = VL_RAND_RESET_I(32);
    top__DOT__data_memory = VL_RAND_RESET_I(32);
    top__DOT__is_store = VL_RAND_RESET_I(1);
    top__DOT__is_load = VL_RAND_RESET_I(1);
    top__DOT__nextPc = VL_RAND_RESET_I(32);
    top__DOT__br_taken = VL_RAND_RESET_I(1);
    top__DOT__op1 = VL_RAND_RESET_I(32);
    top__DOT__op2 = VL_RAND_RESET_I(32);
    top__DOT__uart_OUT_data = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32768; ++__Vi0) {
	    top__DOT__instuction1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    top__DOT__reg_file1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<32768; ++__Vi0) {
	    top__DOT__data_mem1__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top__DOT__uart0__DOT__bitcount = VL_RAND_RESET_I(4);
    top__DOT__uart0__DOT__shifter = VL_RAND_RESET_I(9);
    top__DOT__uart0__DOT__uart_busy = VL_RAND_RESET_I(1);
    top__DOT__uart0__DOT__sending = VL_RAND_RESET_I(1);
    top__DOT__uart0__DOT__d = VL_RAND_RESET_I(29);
    top__DOT__uart0__DOT__dNxt = VL_RAND_RESET_I(29);
    top__DOT__hardware_counter0__DOT__cycles = VL_RAND_RESET_I(32);
    __Vclklast__TOP__cpu_resetn = VL_RAND_RESET_I(1);
    __Vclklast__TOP__sysclk = VL_RAND_RESET_I(1);
}
