#ifndef _CONFIG_H_
// Example config file
#define _CONFIG_H_
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

#ifndef __ASSEMBLER__

#define SYSCALL_TABLE(a) const code_t a
#define SYSCALL_TABLE_READ(a) a

#ifndef WEAK
#define WEAK __attribute__(( __weak__ ))
#endif

#ifndef NOP
#define NOP() __asm__ __volatile__ ("nop":::)
#endif

typedef unsigned long stack_t;

///==================================================================
///               Edit this part carefully!!!
///==================================================================

// Max priority levels are defined by index_t,
// you must specify BITS_IN_INDEX_T to show
// how many levels you actually are going to use.
// data types
typedef unsigned long index_t;
#define BITS_IN_INDEX_T (32)

// Even if index_t is unsigned long long,
// there will be only 64 priority levels available,
// so unsigned char is allways enough.
typedef unsigned char prio_t;

// unsigned char is enough.
typedef unsigned char flag_t;

typedef unsigned long count_t;

typedef volatile unsigned long timer_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char bool_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char syscall_t;

// Unsigned short is enough
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
// These macros needed to interface cstartup code.
#define SYSTEM_TIMER_ISR 	SysTick_Handler
#define SYSCALL_ISR			PendSV_Handler

#define CONFIG_FCPU_HZ 			( 32000000ul )
#define CONFIG_FSYSTICK_HZ 		( 1000ul )

#define CONFIG_PRIO_BITS        2  // Used upper priority bits
#define CONFIG_SYSCALL_PRIO 	3 // SysCall prioity
#define CONFIG_SCHED_PRIO 		3 // Scheduler priority

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

#endif //__ASSEMBLER__
#endif //_CONFIG_H_