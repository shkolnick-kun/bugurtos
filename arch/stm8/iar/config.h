#ifndef _CONFIG_H_
/// This is example config file
#define _CONFIG_H_
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

#define SYSCALL_TABLE(a) const code_t a
#define SYSCALL_TABLE_READ(a) a

#define WEAK __weak
#define NOP __no_operation
#define disable_interrupts __disable_interrupt
#define enable_interrupts __enable_interrupt

#if (__DATA_MODEL__==__LARGE_DATA_MODEL__)
typedef unsigned char __near stack_t;
#else
typedef unsigned char stack_t;
#endif

///==================================================================
///               Edit this part carefully!!!
///==================================================================

// Max priority levels are defined by index_t,
// you must specify BITS_IN_INDEX_T to show
// how many levels you actually are going to use.
typedef unsigned char index_t;
#define BITS_IN_INDEX_T (8)

// Even if index_t is unsigned long long,
// there will be only 64 priority levels available,
// so unsigned char is allways enough.
typedef unsigned char prio_t;

// Unsigned char is enough.
typedef unsigned char flag_t;

// For STM8 only 64Kib of stack space
// may be available, so count_t can be
// unsigned char or unsigned short.
// Unsigned short is enough.
typedef unsigned short count_t;

// You can specify any unsigned type here.
typedef unsigned short timer_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char bool_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char syscall_t;

// Unsigned long is enough
// to handle data and pointers.
// There is no reason to make it bigger
// or smaller.
typedef unsigned long ipc_data_t;
///=================================================================
//     BuguRTOS behavior compilation flags, edit carefully!!!
///=================================================================
#define CONFIG_USE_O1_SEARCH
#define CONFIG_USE_HIGHEST_LOCKER
#define CONFIG_HARD_RT
#define CONFIG_PREEMPTIVE_KERNEL
///=================================================================
///     Project stecific stuff, you are welcome to edit it!!!
///=================================================================
#include <iostm8s208mb.h>///STM8 include!!!!
#include <intrinsics.h>
/// porject specific define of system timer ISR
#define SYSTEM_TIMER_VECTOR TIM4_OVR_UIF_vector
#define SYSTEM_TIMER_INTERRUPT_CLEAR() (TIM4_SR = 0x00)
#define STOP_SCHEDULER() (TIM4_IER = 0x00)
#define START_SCHEDULER() (TIM4_IER = 0x01)

#define PROC_STACK_SIZE 128

#define LOWEST (BITS_IN_INDEX_T - 1)

#define SVH0 (code_t)0
#define RSH0 (code_t)0

#define SVH1 (code_t)0
#define RSH1 (code_t)0

#define SVH2 (code_t)0
#define RSH2 (code_t)0

#define SVH3 (code_t)0
#define RSH3 (code_t)0

#define SVH4 (code_t)0
#define RSH4 (code_t)0

#define SVH5 (code_t)0
#define RSH5 (code_t)0

///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

#ifdef CONFIG_PREEMPTIVE_KERNEL
#define KERNEL_PREEMPT() enable_interrupts(); disable_interrupts()
#else // CONFIG_PREEMPTIVE_KERNEL
#define KERNEL_PREEMPT()
#endif // CONFIG_PREEMPTIVE_KERNEL

#endif //_CONFIG_H_
