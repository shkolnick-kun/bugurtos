#ifndef BGRT_CONFIG_H
/*This is example config file*/
#define BGRT_CONFIG_H
/**================================================================*/
/**               Don't edit this part of the file!!!              */
/**================================================================*/
#define BGRT_SC_TBL(a) const bgrt_scsr_t a
#define BGRT_SC_TBL_READ(a) a

#define WEAK
#define NOP()                     __asm__("nop")

typedef unsigned char bgrt_stack_t;

/**================================================================*/
/**               Edit this part carefully!!!                   */
/**================================================================*/

/* Max priority levels are defined by bgrt_map_t,*/
/* you must specify BGRT_BITS_IN_INDEX_T to show*/
/* how many levels you actually are going to use.*/
typedef unsigned char bgrt_map_t;
#define BGRT_BITS_IN_INDEX_T (8)

/* Even if bgrt_map_t is unsigned long long,*/
/* there will be only 64 priority levels available,*/
/* so unsigned char is always enough.*/
typedef unsigned char bgrt_prio_t;

/* Unsigned char is enough.*/
typedef unsigned char bgrt_flag_t;
/* unsigned char is enough.*/
typedef unsigned char bgrt_st_t;
/*For STM8 only 64Kib of stack space*/
/* may be available, so bgrt_cnt_t can be*/
/* unsigned char or unsigned short.*/
/* Unsigned short is enough.*/
#define BGRT_CONFIG_CNT_MAX (0xffff)
typedef unsigned short bgrt_cnt_t;

/* You can specify any unsigned type here. */
typedef unsigned short bgrt_tmr_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef unsigned char bgrt_bool_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef volatile unsigned char bgrt_syscall_t;
/*=================================================================*/
/**     BuguRTOS behavior compilation flags, edit carefully!!!    */
/*=================================================================*/
#define BGRT_CONFIG_HARD_RT
/*=================================================================*/
/*     Project specific stuff, you are welcome to edit it!!!*/
/*=================================================================*/
#define BGRT_CONFIG_TEST  /*This is test project*/.
#include <libstm8/stm8l.h>/*STM8 include!!!!*/
/*project specific define of system timer ISR*/
#define SPI_TXE_VECTOR INT_SPI1
#define BGRT_SYSTEM_TIMER_VECTOR INT_TIM4_CHANGE

#define BGRT_SYSTEM_TIMER_INTERRUPT_CLEAR() (TIM4_SR1 = 0x00)
#define BGRT_STOP_SCHEDULER() (TIM4_IER = 0x00)
#define BGRT_START_SCHEDULER() (TIM4_IER = 0x01)

#define BGRT_PROC_STACK_SIZE (160)

#define LOWEST (BGRT_BITS_IN_INDEX_T - 1)

#define PID0 BGRT_PROC_TO_PID(&proc[0])
#define PID1 BGRT_PROC_TO_PID(&proc[1])
#define PID2 BGRT_PROC_TO_PID(&proc[2])
#define PID3 BGRT_PROC_TO_PID(&proc[3])
#define PID4 BGRT_PROC_TO_PID(&proc[4])
#define PID5 BGRT_PROC_TO_PID(&proc[5])

#define PR0 (&proc[0])
#define PR1 (&proc[1])
#define PR2 (&proc[2])
#define PR3 (&proc[3])
#define PR4 (&proc[4])
#define PR5 (&proc[5])

extern void blink_1(void);
extern void blink_2(void);
extern void blink_3(void);
extern void blink_4(void);
extern void blink_5(void);
extern void blink_6(void);

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

/**================================================================*/
/**               Don't edit this part of the file!!!              */
/**================================================================*/

extern void kernel_preemt_hook(void);
#define BGRT_KERNEL_PREEMPT() kernel_preemt_hook()

#endif /*BGRT_CONFIG_H*/
