#ifndef BGRT_CONFIG_H
/* Example config file */
#define BGRT_CONFIG_H
/**================================================================*/
/**               Don't edit this part of the file!!!              */
/**================================================================*/

#ifndef __ASSEMBLER__

#define BGRT_SC_TBL(a) const bgrt_scsr_t a
#define BGRT_SC_TBL_READ(a) a

#ifndef NOP
#define NOP() __asm__ __volatile__ ("nop":::)
#endif

typedef unsigned long bgrt_stack_t;

/**================================================================*/
/**               Edit this part carefully!!!                   */
/**================================================================*/

/* Max priority levels are defined by bgrt_map_t,*/
/* you must specify BGRT_BITS_IN_INDEX_T to show*/
/* how many levels you actually are going to use.*/
/* data types*/
typedef unsigned long bgrt_map_t;
#define BGRT_BITS_IN_INDEX_T (32)
#define BGRT_CONFIG_USER_SEARCH(map) (__builtin_ctzl(map))

/* Even if bgrt_map_t is unsigned long long,*/
/* there will be only 64 priority levels available,*/
/* so unsigned char is always enough.*/
typedef unsigned char bgrt_prio_t;

/* unsigned char is enough.*/
typedef unsigned char bgrt_flag_t;
/* unsigned char is enough.*/
typedef unsigned char bgrt_st_t;

#define BGRT_CONFIG_CNT_MAX (0xffffffff)
typedef unsigned long bgrt_cnt_t;

typedef volatile unsigned long bgrt_tmr_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef unsigned char bgrt_bool_t;

/* Unsigned char is enough.*/
/* There is no reason to make it bigger.*/
typedef volatile unsigned char bgrt_syscall_t;
/**===============================================================*/
/**     BuguRTOS behavior compilation flags, edit carefully!!!    */
/**===============================================================*/
#define BGRT_CONFIG_HARD_RT
/**===============================================================*/
/**     Project specific stuff, you are welcome to edit it!!!*/
/**===============================================================*/
#define BGRT_CONFIG_TEST  /*This is test project*/.
#define STM32F4
#include <libopencmsis/core_cm3.h>
/*These macros needed to interface cstartup code.*/
#define BGRT_SYSTEM_TIMER_ISR 	    sys_tick_handler
#define BGRT_SYSCALL_ISR			pend_sv_handler

#define BGRT_CONFIG_FCPU_HZ 			(168000000ul)
#define BGRT_CONFIG_FSYSTICK_HZ 		(1000ul)

#define BGRT_CONFIG_PRIO_BITS        4  /*Used upper priority bits*/
#define BGRT_CONFIG_SYSCALL_PRIO 	16 /*SysCall priority*/
#define BGRT_CONFIG_CRITSEC_PRIO 	17 /*Critical section priority*/
#define BGRT_CONFIG_SCHED_PRIO 		17 /*Scheduler priority*/

#define BGRT_PROC_STACK_SIZE 128

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

/**================================================================*/
/**               Don't edit this part of the file!!!              */
/**================================================================*/

extern void kernel_preemt_hook(void);
#define BGRT_KERNEL_PREEMPT() kernel_preemt_hook()

#endif /*__ASSEMBLER__*/
#endif /*BGRT_CONFIG_H*/
