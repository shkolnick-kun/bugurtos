#ifndef _CONFIG_H_
// Тестовый конфиг-файл, в последствии будет заменен
#define _CONFIG_H_

#include <avr/io.h>
#include <avr/interrupt.h>

/// porject specific define of system timer ISR
#define SYSTEM_TIMER_ISR TIMER2_COMPA_vect
#define SYSCALL_ISR INT1_vect
/// ===========================================

#ifndef __ASSEMBLER__

#define INLINE __attribute__((__always_inline__))
#define WEAK __attribute__((__weak__))

#define SYS_TMR_ISR_ATTR __attribute__ (( signal, naked ))
#define RESCHED_ISR_ATTR __attribute__ (( signal, naked ))

// data types
typedef unsigned char index_t;
#define BITS_IN_INDEX_T (8)

typedef unsigned char prio_t;
typedef unsigned char stack_t;

typedef unsigned char flag_t;

typedef unsigned short count_t;

//#define timer_t unsigned long
typedef unsigned short timer_t;

typedef unsigned char bool_t;

typedef unsigned char core_id_t;

// defines
#define CONFIG_USE_O1_SEARCH
#define CONFIG_USE_HIGHEST_LOCKER
//#define MAX_CORES (4)
//#define CONFIG_USE_ALB
#define CONFIG_HARD_RT

#define NOP() __asm__ __volatile__("nop"::)
#define SYSCALL_DELLAY() NOP();NOP();NOP();NOP();NOP();NOP()

///=================================================================
/// project stecific stuff
///=================================================================

#define CONFIG_IDLE_STACK_SIZE 128

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

#endif //__ASSEMBLER__

#endif //_CONFIG_H_
