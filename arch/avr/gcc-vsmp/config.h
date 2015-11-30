#ifndef _BGRT_CONFIG_H_
// Example config file for avr-vsmp test architecture.
#define _BGRT_CONFIG_H_
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef __ASSEMBLER__

//vsmp is a test architecture for multicore code testing!
#define BGRT_CONFIG_MP

/// Syscall table is allocated in FLASH.
#include <avr/pgmspace.h>
#define BGRT_SCL_TBL(a) const PROGMEM bgrt_code_t a
#define BGRT_SCL_TBL_READ(a) (bgrt_code_t)pgm_read_word(&a)

/// Another option is to allocate it in RAM.
//#define BGRT_SCL_TBL(a) const bgrt_code_t a
//#define BGRT_SCL_TBL_READ(a) a

#define INLINE __attribute__((__always_inline__))
#define WEAK __attribute__(( __weak__ ))

#define NOP() __asm__ __volatile__("nop"::)

typedef unsigned char bgrt_stack_t;

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

// unsigned char is enough.
typedef unsigned char bgrt_flag_t;

// unsigned char is enough.
typedef unsigned char bgrt_st_t;

// For AVR only 64Kib of RAM
// may be available, so bgrt_cnt_t can be
// unsigned char or unsigned short.
// Unsigned short is enough.
typedef unsigned short bgrt_cnt_t;

// You can specify any volatile unsigned type here.
typedef volatile unsigned short bgrt_tmr_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char bgrt_bool_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char bgrt_syscall_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char bgrt_cpuid_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char bgrt_aff_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char bgrt_lock_t;

// Unsigned char is enough for test purposes.
typedef unsigned char bgrt_ls_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char load_t;

///=================================================================
///     BuguRTOS behavior compilation flags, edit carefully!!!
///=================================================================

// Use constant time index search.
#define BGRT_CONFIG_USE_O1_SEARCH

// Use "Highest locker" protocol for mutex handling.
#define BGRT_CONFIG_USE_HIGHEST_LOCKER

// Use "Hard real time" scheduling. RT processes a stopped
// on watchdog expire, locked mutexes DO DNOT matter.
#define BGRT_CONFIG_HARD_RT

//#define BGRT_CONFIG_LB_SCHEME 0 // No load balancing during runtime
#define BGRT_CONFIG_LB_SCHEME 1 // Active load balancing
//#define BGRT_CONFIG_LB_SCHEME 2 // Lazy local load balancing
//#define BGRT_CONFIG_LB_SCHEME 3 // Lazy global load balancing

#if (BGRT_CONFIG_LB_SCHEME == 1)
// Use "Active Load Balancing",
// bgrt_sched_schedule() function is responsible for load balancing.
#define BGRT_CONFIG_USE_ALB
#endif

///=================================================================
///     Project specific stuff, you are welcome to edit it!!!
///=================================================================

#define BGRT_CONFIG_USER_IDLE

extern void(*test_kernel_preempt)(void);
#define BGRT_KERNEL_PREEMPT() test_kernel_preempt()

//Atmega328p CAN NOT afford more!
#define BGRT_MAX_CPU (2)

// Real system timer interrupt vector.
#define BGRT_SYSTEM_TIMER_ISR TIMER2_COMPA_vect

// System timer virtual interrupt counter threshold.
#define BGRT_CONFIG_SYSTIMER_HOOK_THR 100 // Every 100 REAL ticks.

// Virtual machine main stack size.
// Main stacks are used by idle processes.
#define VM_STACK_SIZE (128)

//Virtual machine interrupt stack size.
#define VM_INT_STACK_SIZE (160)

#define PROC_STACK_SIZE 128

#define LOWEST (BGRT_BITS_IN_INDEX_T - 1)

#define BGRT_CONFIG_SAVE_POWER test_do_nothing
extern void test_do_nothing(void);

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

#endif //__ASSEMBLER__
#endif //_BGRT_CONFIG_H_
