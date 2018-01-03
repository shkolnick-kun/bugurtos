#ifndef BGRT_CONFIG_H
/*Тестовый конфиг-файл, впоследствии будет заменён*/
#define BGRT_CONFIG_H
/**================================================================*/
/**               Don't edit this part of the file!!!              */
/**================================================================*/

#define BGRT_SC_TBL(a) const bgrt_scsr_t a
#define BGRT_SC_TBL_READ(a) a

#define WEAK __weak
#define NOP __no_operation
#define BGRT_INT_LOCK __disable_interrupt
#define BGRT_INT_FREE __enable_interrupt

#if (__DATA_MODEL__==__LARGE_DATA_MODEL__)
typedef unsigned char __near bgrt_stack_t;
#else
typedef unsigned char bgrt_stack_t;
#endif

/**================================================================*/
/**               Edit this part carefully!!!                                     */
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
/**===============================================================*/
/**     BuguRTOS behavior compilation flags, edit carefully!!!    */
/**===============================================================*/
#define BGRT_CONFIG_HARD_RT
/**===============================================================*/
/**     Project specific stuff, you are welcome to edit it!!!   */
/**===============================================================*/
#define BGRT_CONFIG_TEST  /*This is test project*/.
#include <iostm8s208mb.h>/*STM8 include!!!!*/
#include <intrinsics.h>
/*project specific define of system timer ISR*/
#define BGRT_SYSTEM_TIMER_VECTOR TIM4_OVR_UIF_vector
#define BGRT_SYSTEM_TIMER_INTERRUPT_CLEAR() (TIM4_SR = 0x00)
#define BGRT_STOP_SCHEDULER() (TIM4_IER = 0x00)
#define BGRT_START_SCHEDULER() (TIM4_IER = 0x01)

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

#endif /*BGRT_CONFIG_H*/
