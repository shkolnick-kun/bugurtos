#ifndef _CONFIG_H_
// Тестовый конфиг-файл, в последствии будет заменен
#define _CONFIG_H_
///==================================================================
///               Don't edit this part of the file!!!
///==================================================================
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

// Unsigned char is enough.
// There is no reason to make it bigger.
typedef unsigned char ipc_data_t;
///=================================================================
//     BuguRTOS behavior compilation flags, edit carefully!!!
///=================================================================
#define CONFIG_USE_O1_SEARCH
#define CONFIG_USE_HIGHEST_LOCKER
#define CONFIG_HARD_RT
///=================================================================
///     Project stecific stuff, you are welcome to edit it!!!
///=================================================================
#include <iostm8s105c6.h>///STM8 include!!!!
#include <intrinsics.h>
/// porject specific define of system timer ISR
#define SYSTEM_TIMER_VECTOR TIM4_OVR_UIF_vector
#define SYSTEM_TIMER_INTERRUPT_CLEAR() (TIM4_SR = 0x00)
#endif //_CONFIG_H_
