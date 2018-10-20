#ifndef BGRT_CONFIG_H
/* Example config file for avr-vsmp test architecture. */
#define BGRT_CONFIG_H
/**================================================================*/
/**               Don't edit this part of the file!!!              */
/**================================================================*/

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef __ASSEMBLER__

/*vsmp is a test architecture for multicore code testing!*/
#define BGRT_CONFIG_MP

/* Syscall table is allocated in FLASH.*/
#include <avr/pgmspace.h>
#define BGRT_SC_TBL(a) const PROGMEM bgrt_scsr_t a
#define BGRT_SC_TBL_READ(a) (bgrt_scsr_t)pgm_read_word(&a)

/* A nother option is to allocate it in RAM. */
/*#define BGRT_SC_TBL(a) const bgrt_scsr_t a*/
/*#define BGRT_SC_TBL_READ(a) a*/

#define INLINE __attribute__((__always_inline__))
#define WEAK __attribute__((__weak__))

#define NOP() __asm__ __volatile__("nop"::)

#define BGRT_VINT_CS_START() cli()
#define BGRT_VINT_CS_END() sei()

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

/* unsigned char is enough.*/
typedef unsigned char bgrt_flag_t;

/* unsigned char is enough.*/
typedef unsigned char bgrt_st_t;

/* For AVR only 64Kib of RAM*/
/* may be available, so bgrt_cnt_t can be*/
/* unsigned char or unsigned short.*/
/* Unsigned short is enough.*/
#define BGRT_CONFIG_CNT_MAX (0xff)
typedef unsigned short bgrt_cnt_t;

/* You can specify any volatile unsigned type here. */
typedef volatile unsigned short bgrt_tmr_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef unsigned char bgrt_bool_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef volatile unsigned char bgrt_syscall_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef unsigned char bgrt_cpuid_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef unsigned char bgrt_aff_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef volatile unsigned char bgrt_lock_t;

/*Unsigned char is enough for test purposes.*/
typedef unsigned char bgrt_ls_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef unsigned char bgrt_load_t;

/**===============================================================*/
/**     BuguRTOS behavior compilation flags, edit carefully!!!    */
/**===============================================================*/
/* Use "Hard real time" scheduling. RT processes a stopped*/
/* on watchdog expire, locked mutexes DO DNOT matter.*/
#define BGRT_CONFIG_HARD_RT

/* No load balancing during runtime*/
//#define BGRT_CONFIG_LB_SCHEME 0
/* Active load balancing */
//#define BGRT_CONFIG_LB_SCHEME 1
/* Lazy load balancing */
#define BGRT_CONFIG_LB_SCHEME 2

#if (BGRT_CONFIG_LB_SCHEME == 1)
/* Use "Active Load Balancing",*/
/* bgrt_sched_schedule() function is responsible for load balancing.*/
#define BGRT_CONFIG_USE_ALB
#endif

#if (BGRT_CONFIG_LB_SCHEME == 2)
#define BGRT_CONFIG_USE_LLB
#endif

/**===============================================================*/
/**     Project specific stuff, you are welcome to edit it!!!*/
/**===============================================================*/
#define BGRT_CONFIG_TEST  /*This is test project*/

extern const struct bgrt_priv_proc_t * proc_base;
#define BGRT_PID_T bgrt_cnt_t
#define BGRT_PID_NOTHING ((BGRT_PID_T)0)
#define BGRT_PID_TO_PROC(p) ((BGRT_PID_NOTHING!=p)?((bgrt_proc_t *)proc_base + (p-1)):((bgrt_proc_t *)0))
#define BGRT_PROC_TO_PID(p) ((p)?(1 + (bgrt_cnt_t)(p - (bgrt_proc_t *)proc_base)):(BGRT_PID_NOTHING))

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

extern void(*test_kernel_preempt)(void);
#define BGRT_KERNEL_PREEMPT() test_kernel_preempt()

/*Atmega328p CAN NOT afford more!*/
#define BGRT_MAX_CPU (2)

/*Real system timer interrupt vector.*/
#define BGRT_START_TIMER() (TIMSK2 |= 0x02)
#define BGRT_STOP_TIMER() (TIMSK2 &= ~0x02)
#define BGRT_SYSTEM_TIMER_ISR TIMER2_COMPA_vect

/*System timer virtual interrupt counter threshold.*/
#define BGRT_CONFIG_SYSTIMER_HOOK_THR 100 /*Every 100 REAL ticks.*/

/*Virtual machine main stack size.*/
/* Main stacks are used by idle processes.*/
#define VM_STACK_SIZE (256)

/*Virtual machine interrupt stack size.*/
/*#define VM_INT_STACK_SIZE (160)*/

#define BGRT_PROC_STACK_SIZE 128

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

#endif /*__ASSEMBLER__*/
#endif /*BGRT_CONFIG_H*/
