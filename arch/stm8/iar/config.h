#ifndef _BGRT_CONFIG_H_
// Тестовый конфиг-файл, в последствии будет заменен
#define _BGRT_CONFIG_H_
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

#define BGRT_SCL_TBL(a) const bgrt_code_t a
#define BGRT_SCL_TBL_READ(a) a

#define WEAK __weak
#define NOP __no_operation
#define bgrt_disable_interrupts __disable_interrupt
#define bgrt_enable_interrupts __enable_interrupt

#if (__DATA_MODEL__==__LARGE_DATA_MODEL__)
typedef unsigned char __near bgrt_stack_t;
#else
typedef unsigned char bgrt_stack_t;
#endif

///==================================================================
///               Edit this part carefully!!!
///==================================================================

// Max priority levels are defined by bgrt_index_t,
// you must specify BGRT_BITS_IN_INDEX_T to show
// how many levels you actually are going to use.
typedef unsigned char bgrt_index_t;
#define BGRT_BITS_IN_INDEX_T (8)

// Even if bgrt_index_t is unsigned long long,
// there will be only 64 priority levels available,
// so unsigned char is always enough.
typedef unsigned char bgrt_prio_t;

// Unsigned char is enough.
typedef unsigned char bgrt_flag_t;

// unsigned char is enough.
typedef unsigned char bgrt_st_t;

// For STM8 only 64Kib of stack space
// may be available, so bgrt_cnt_t can be
// unsigned char or unsigned short.
// Unsigned short is enough.
typedef unsigned short bgrt_cnt_t;

// You can specify any unsigned type here.
typedef unsigned short bgrt_tmr_t;

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
#define BGRT_CONFIG_USE_HIGHEST_LOCKER
#define BGRT_CONFIG_HARD_RT
#define BGRT_CONFIG_PREEMPTIVE_KERNEL
///=================================================================
///     Project specific stuff, you are welcome to edit it!!!
///=================================================================
#include <iostm8s208mb.h>///STM8 include!!!!
#include <intrinsics.h>
/// project specific define of system timer ISR
#define BGRT_SYSTEM_TIMER_VECTOR TIM4_OVR_UIF_vector
#define BGRT_SYSTEM_TIMER_INTERRUPT_CLEAR() (TIM4_SR = 0x00)
#define BGRT_STOP_SCHEDULER() (TIM4_IER = 0x00)
#define BGRT_START_SCHEDULER() (TIM4_IER = 0x01)

#define BGRT_PROC_STACK_SIZE 128

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

#endif //_BGRT_CONFIG_H_
