#ifndef _CONFIG_H_
// Example config file
#define _CONFIG_H_
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef __ASSEMBLER__

// Syscall table is allocated in FLASH
#include <avr/pgmspace.h>
#define SYSCALL_TABLE(a) const PROGMEM code_t a
#define SYSCALL_TABLE_READ(a) (code_t)pgm_read_word(&a)
// Another option is to allocate it in RAM
//#define SYSCALL_TABLE(a) const code_t a
//#define SYSCALL_TABLE_READ(a) a

#define INLINE __attribute__((__always_inline__))
#define WEAK __attribute__(( __weak__ ))

#define SYS_TMR_ISR_ATTR __attribute__ (( signal, naked ))
#define RESCHED_ISR_ATTR __attribute__ (( signal, naked ))

#define NOP() __asm__ __volatile__("nop"::)
#define SYSCALL_DELLAY() NOP();NOP();NOP()

typedef unsigned char stack_t;

///==================================================================
///               Edit this part carefully!!!
///==================================================================

// Max priority levels are defined by index_t,
// you must specify BITS_IN_INDEX_T to show
// how many levels you actually are going to use.
// data types
typedef unsigned char index_t;
#define BITS_IN_INDEX_T (8)

// Even if index_t is unsigned long long,
// there will be only 64 priority levels available,
// so unsigned char is allways enough.
typedef unsigned char prio_t;

// Unsigned char is too small,
// unsigned short is enough.
typedef unsigned short flag_t;

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

typedef unsigned char core_id_t;
typedef unsigned char affinity_t;
typedef unsigned char lock_t;
typedef unsigned char stat_t;
typedef unsigned char load_t;
///=================================================================
//     BuguRTOS behavior compilation flags, edit carefully!!!
///=================================================================
#define CONFIG_USE_O1_SEARCH
#define CONFIG_USE_HIGHEST_LOCKER
//#define CONFIG_HARD_RT
#define CONFIG_MP
//#define CONFIG_USE_ALB
#define MAX_CORES (2)
#define VM_STACK_SIZE (256)
///=================================================================
///     Project stecific stuff, you are welcome to edit it!!!
///=================================================================
#define SYSTEM_TIMER_ISR TIMER2_COMPA_vect

#endif //__ASSEMBLER__

#endif //_CONFIG_H_
