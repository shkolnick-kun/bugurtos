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
///=================================================================
//     BuguRTOS behavior compilation flags, edit carefully!!!
///=================================================================
#define CONFIG_USE_O1_SEARCH
#define CONFIG_HARD_RT
#define CONFIG_USER_IDLE
#define CONFIG_PREEMPTIVE_KERNEL
///=================================================================
///     Project specific stuff, you are welcome to edit it!!!
///=================================================================
#define CONFIG_TEST  //This is test project
#define SYSTEM_TIMER_ISR TIMER2_COMPA_vect
#define START_SCHEDULER() (TIMSK2 |= 0x02)
#define STOP_SCHEDULER() (TIMSK2 &= ~0x02)

extern void test_do_nothing(void);
#define CONFIG_SAVE_POWER test_do_nothing

extern void(*test_kernel_preempt)(void);
#ifdef CONFIG_PREEMPTIVE_KERNEL
#define KERNEL_PREEMPT() sei(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); cli(); test_kernel_preempt()
#else // CONFIG_PREEMPTIVE_KERNEL
#define KERNEL_PREEMPT() test_kernel_preempt()
#endif //CONFIG_PREEMPTIVE_KERNEL


#define PROC_STACK_SIZE 128

#define LOWEST (BITS_IN_INDEX_T - 1)

#define SVH0 (code_t)blink_1
#define RSH0 (code_t)blink_1

#define SVH1 (code_t)blink_2
#define RSH1 (code_t)blink_2

#define SVH2 (code_t)blink_3
#define RSH2 (code_t)blink_3

#define SVH3 (code_t)blink_4
#define RSH3 (code_t)blink_4

#define SVH4 (code_t)blink_5
#define RSH4 (code_t)blink_5

#define SVH5 (code_t)blink_6
#define RSH5 (code_t)blink_6

#define blink_R1() (PORTC ^= 0x20)
#define R1_on() (PORTC |= 0x20)
#define R1_off() (PORTC &= ~0x20)

#define blink_G1() (PORTD ^= 0x10)
#define G1_on() (PORTD |= 0x10)
#define G1_off() (PORTD &= ~0x10)

#define blink_R2() (PORTD ^= 0x04)
#define R2_on() (PORTD |= 0x04)
#define R2_off() (PORTD &= ~0x04)

#define blink_G2() (PORTD ^= 0x08)
#define G2_on() (PORTD |= 0x08)
#define G2_off() (PORTD &= ~0x08)

#define blink_R3() (PORTD ^= 0x20)
#define R3_on() (PORTD |= 0x20)
#define R3_off() (PORTD &= ~0x20)

#define blink_G3() (PORTD ^= 0x40)
#define G3_on() (PORTD |= 0x40)
#define G3_off() (PORTD &= ~0x40)
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================


#endif //__ASSEMBLER__
#endif //_CONFIG_H_
