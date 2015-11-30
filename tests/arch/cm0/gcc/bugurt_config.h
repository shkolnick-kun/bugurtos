#ifndef _BGRT_CONFIG_H_
// Example config file
#define _BGRT_CONFIG_H_
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

#ifndef __ASSEMBLER__

#define BGRT_SCL_TBL(a) const bgrt_code_t a
#define BGRT_SCL_TBL_READ(a) a

#ifndef NOP
#define NOP() __asm__ __volatile__ ("nop":::)
#endif

typedef unsigned long bgrt_stack_t;

///==================================================================
///               Edit this part carefully!!!
///==================================================================

// Max priority levels are defined by bgrt_index_t,
// you must specify BGRT_BITS_IN_INDEX_T to show
// how many levels you actually are going to use.
// data types
typedef unsigned long bgrt_index_t;
#define BGRT_BITS_IN_INDEX_T (32)

// Even if bgrt_index_t is unsigned long long,
// there will be only 64 priority levels available,
// so unsigned char is always enough.
typedef unsigned char bgrt_prio_t;

// unsigned char is enough.
typedef unsigned char bgrt_flag_t;

// unsigned char is enough.
typedef unsigned char bgrt_st_t;

typedef unsigned long bgrt_cnt_t;

typedef volatile unsigned long bgrt_tmr_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char bgrt_bool_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char bgrt_syscall_t;
///=================================================================
//     BuguRTOS behavior compilation flags, edit carefully!!!
///=================================================================
#define BGRT_CONFIG_USE_O1_SEARCH
#define BGRT_CONFIG_HARD_RT
#define BGRT_CONFIG_PREEMPTIVE_KERNEL

///=================================================================
///     Project specific stuff, you are welcome to edit it!!!
///=================================================================
#define BGRT_CONFIG_TEST  //This is test project.
#define STM32F0
#include <libopencmsis/core_cm3.h>

// These macros needed to interface cstartup code.
#define BGRT_SYSTEM_TIMER_ISR 	sys_tick_handler
#define SYSCALL_ISR			pend_sv_handler

#define BGRT_CONFIG_FCPU_HZ 			( 32000000ul )
#define BGRT_CONFIG_FSYSTICK_HZ 		( 1000ul )

#define BGRT_CONFIG_PRIO_BITS        2  // Used upper priority bits
#define BGRT_CONFIG_SYSCALL_PRIO 	3 // SysCall priority
#define BGRT_CONFIG_SCHED_PRIO 		3 // Scheduler priority

#define PROC_STACK_SIZE 128

#define LOWEST (BGRT_BITS_IN_INDEX_T - 1)

#define SVH0 (bgrt_code_t)0
#define RSH0 (bgrt_code_t)0

#define SVH1 (bgrt_code_t)0
#define RSH1 (bgrt_code_t)0

#define SVH2 (bgrt_code_t)0
#define RSH2 (bgrt_code_t)0

#define SVH3 (bgrt_code_t)0
#define RSH3 (bgrt_code_t)0

#define SVH4 (bgrt_code_t)0
#define RSH4 (bgrt_code_t)0

#define SVH5 (bgrt_code_t)0
#define RSH5 (bgrt_code_t)0

///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

extern void kernel_preemt_hook(void);
#ifdef BGRT_CONFIG_PREEMPTIVE_KERNEL
#define BGRT_KERNEL_PREEMPT() bgrt_enable_interrupts(); bgrt_disable_interrupts(); kernel_preemt_hook()
#else // BGRT_CONFIG_PREEMPTIVE_KERNEL
#define BGRT_KERNEL_PREEMPT() kernel_preemt_hook()
#endif // BGRT_CONFIG_PREEMPTIVE_KERNEL

#endif //__ASSEMBLER__
#endif //_BGRT_CONFIG_H_
