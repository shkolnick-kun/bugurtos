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
// so unsigned char is allways enough.
typedef unsigned char prio_t;

// unsigned char is enough.
typedef unsigned char flag_t;

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

// Unsigned short is enough
// to handle data and pointers.
// There is no reason to make it bigger
// or smaller.
typedef unsigned short ipc_data_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char core_id_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char affinity_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char lock_t;

// Unsigned char is enough for test purposes.
typedef unsigned char stat_t;

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char load_t;

///=================================================================
//     BuguRTOS behavior compilation flags, edit carefully!!!
///=================================================================

// Use constant time index search.
#define CONFIG_USE_O1_SEARCH

// Use "Highest locker" protocol for mutex handling.
#define CONFIG_USE_HIGHEST_LOCKER

// Use "Hard real time" scheduling. RT processes a stoped
// on watchdog expire, locked mutexes DO DNOT matter.
#define CONFIG_HARD_RT

// Use "Active Load Balancing",
// sched_schedule() function is responsible for load balancing.
#define CONFIG_USE_ALB

///=================================================================
///     Project stecific stuff, you are welcome to edit it!!!
///=================================================================

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
#define VM_INT_STACK_SIZE (128)

#endif //__ASSEMBLER__
#endif //_CONFIG_H_
