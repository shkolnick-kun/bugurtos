#ifndef _CONFIG_H_
/// This is example config file
#define _CONFIG_H_
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

#include <intrins.h>

#define SYSCALL_TABLE(a) code_t code a
#define SYSCALL_TABLE_READ(a) a

#define WEAK
#define NOP _nop_
#define disable_interrupts _sim_
#define enable_interrupts _rim_

typedef unsigned char stack_t;

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
//=================================================================
//     BuguRTOS behavior compilation flags, edit carefully!!!
//=================================================================
//#define CONFIG_USE_O1_SEARCH
#define CONFIG_HARD_RT
#define CONFIG_PREEMPTIVE_KERNEL
#define CONFIG_USER_IDLE
//=================================================================
//     Project stecific stuff, you are welcome to edit it!!!
//=================================================================
#include <STM8\STM8S208RB.h>//STM8 include!!!!
// porject specific define of system timer ISR
#define SPI_TXE_vector 10
#define SYSTEM_TIMER_VECTOR 23
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
