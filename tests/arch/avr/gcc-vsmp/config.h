#ifndef _CONFIG_H_
// Example config file for avr-vsmp test architecture.
#define _CONFIG_H_
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef __ASSEMBLER__

//vsmp is a test architecture for multicore code testing!
#define CONFIG_MP

/// Syscall table is allocated in FLASH.
#include <avr/pgmspace.h>
#define SYSCALL_TABLE(a) const PROGMEM code_t a
#define SYSCALL_TABLE_READ(a) (code_t)pgm_read_word(&a)

/// Another option is to allocate it in RAM.
//#define SYSCALL_TABLE(a) const code_t a
//#define SYSCALL_TABLE_READ(a) a

#define INLINE __attribute__((__always_inline__))
#define WEAK __attribute__(( __weak__ ))

#define NOP() __asm__ __volatile__("nop"::)

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
// so unsigned char is always enough.
typedef unsigned char prio_t;

// unsigned char is enough.
typedef unsigned char flag_t;

// unsigned char is enough.
typedef unsigned char status_t;

// For AVR only 64Kib of RAM
// may be available, so count_t can be
// unsigned char or unsigned short.
// Unsigned short is enough.
typedef unsigned short count_t;

// You can specify any volatile unsigned type here.
typedef volatile unsigned short timer_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char bool_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char syscall_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char core_id_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char affinity_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef volatile unsigned char lock_t;

// Unsigned char is enough for test purposes.
typedef unsigned char stat_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char load_t;

///=================================================================
///     BuguRTOS behavior compilation flags, edit carefully!!!
///=================================================================

// Use constant time index search.
#define CONFIG_USE_O1_SEARCH

// Use "Highest locker" protocol for mutex handling.
#define CONFIG_USE_HIGHEST_LOCKER

// Use "Hard real time" scheduling. RT processes a stopped
// on watchdog expire, locked mutexes DO DNOT matter.
#define CONFIG_HARD_RT

//#define CONFIG_LB_SCHEME 0 // No load balancing during runtime
#define CONFIG_LB_SCHEME 1 // Active load balancing
//#define CONFIG_LB_SCHEME 2 // Lazy local load balancing
//#define CONFIG_LB_SCHEME 3 // Lazy global load balancing

#if (CONFIG_LB_SCHEME == 1)
// Use "Active Load Balancing",
// sched_schedule() function is responsible for load balancing.
#define CONFIG_USE_ALB
#endif

///=================================================================
///     Project specific stuff, you are welcome to edit it!!!
///=================================================================

#define CONFIG_USER_IDLE

extern void(*test_kernel_preempt)(void);
#define KERNEL_PREEMPT() test_kernel_preempt()

//Atmega328p CAN NOT afford more!
#define MAX_CORES (2)

// Real system timer interrupt vector.
#define SYSTEM_TIMER_ISR TIMER2_COMPA_vect

// System timer virtual interrupt counter threshold.
#define CONFIG_SYSTIMER_HOOK_THR 100 // Every 100 REAL ticks.

// Virtual machine main stack size.
// Main stacks are used by idle processes.
#define VM_STACK_SIZE (128)

//Virtual machine interrupt stack size.
#define VM_INT_STACK_SIZE (160)

#define PROC_STACK_SIZE 128

#define LOWEST (BITS_IN_INDEX_T - 1)

#define CONFIG_SAVE_POWER test_do_nothing
extern void test_do_nothing(void);

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

#endif //__ASSEMBLER__
#endif //_CONFIG_H_
