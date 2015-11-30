#ifndef _BGRT_CONFIG_H_
// Example config file
#define _BGRT_CONFIG_H_
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef __ASSEMBLER__

// Syscall table is allocated in FLASH
#include <avr/pgmspace.h>
#define BGRT_SCL_TBL(a) const PROGMEM bgrt_code_t a
#define BGRT_SCL_TBL_READ(a) (bgrt_code_t)pgm_read_word(&a)
// Another option is to allocate it in RAM
//#define BGRT_SCL_TBL(a) const bgrt_code_t a
//#define BGRT_SCL_TBL_READ(a) a

#define INLINE __attribute__((__always_inline__))
#define WEAK __attribute__(( __weak__ ))

#define SYS_TMR_ISR_ATTR __attribute__ (( signal, naked ))
#define RESCHED_ISR_ATTR __attribute__ (( signal, naked ))

#define NOP() __asm__ __volatile__("nop"::)
#define SYSCALL_DELLAY() NOP();NOP();NOP()

typedef unsigned char bgrt_stack_t;

///==================================================================
///               Edit this part carefully!!!
///==================================================================

// Max priority levels are defined by bgrt_index_t,
// you must specify BGRT_BITS_IN_INDEX_T to show
// how many levels you actually are going to use.
// data types
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
///=================================================================
//     BuguRTOS behavior compilation flags, edit carefully!!!
///=================================================================
#define BGRT_CONFIG_USE_O1_SEARCH
#define BGRT_CONFIG_HARD_RT
#define BGRT_CONFIG_USER_IDLE
#define BGRT_CONFIG_PREEMPTIVE_KERNEL
///=================================================================
///     Project specific stuff, you are welcome to edit it!!!
///=================================================================
#define BGRT_CONFIG_TEST  //This is test project
#define BGRT_SYSTEM_TIMER_ISR TIMER2_COMPA_vect
#define BGRT_START_SCHEDULER() (TIMSK2 |= 0x02)
#define BGRT_STOP_SCHEDULER() (TIMSK2 &= ~0x02)

extern void test_do_nothing(void);
#define BGRT_CONFIG_SAVE_POWER test_do_nothing

extern void(*test_kernel_preempt)(void);
#ifdef BGRT_CONFIG_PREEMPTIVE_KERNEL
#define BGRT_KERNEL_PREEMPT() sei(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); cli(); test_kernel_preempt()
#else // BGRT_CONFIG_PREEMPTIVE_KERNEL
#define BGRT_KERNEL_PREEMPT() test_kernel_preempt()
#endif //BGRT_CONFIG_PREEMPTIVE_KERNEL


#define PROC_STACK_SIZE 128

#define LOWEST (BGRT_BITS_IN_INDEX_T - 1)

#define SVH0 (bgrt_code_t)blink_1
#define RSH0 (bgrt_code_t)blink_1

#define SVH1 (bgrt_code_t)blink_2
#define RSH1 (bgrt_code_t)blink_2

#define SVH2 (bgrt_code_t)blink_3
#define RSH2 (bgrt_code_t)blink_3

#define SVH3 (bgrt_code_t)blink_4
#define RSH3 (bgrt_code_t)blink_4

#define SVH4 (bgrt_code_t)blink_5
#define RSH4 (bgrt_code_t)blink_5

#define SVH5 (bgrt_code_t)blink_6
#define RSH5 (bgrt_code_t)blink_6

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
#endif //_BGRT_CONFIG_H_
