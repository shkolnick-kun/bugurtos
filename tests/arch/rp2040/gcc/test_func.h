#include <bugurt.h>

#include "pico/stdlib.h"

#ifndef PICO_DEFAULT_LED_PIN
#error "BuguRTOS tests require a board with a regular LED"
#endif

extern void(*test_kernel_preempt)(void);
extern bgrt_proc_t proc[6];
extern bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

// Generic bgrt_proc_init argument terminator.
#define ARG_END ,(bgrt_aff_t)0x3
// Scheduler test bgrt_proc_init argument terminator
#if (BGRT_CONFIG_LB_SCHEME != 0)
#define BGRT_SCHED_ARG_END ,(bgrt_aff_t)0x2
#else
#define BGRT_SCHED_ARG_END ,(bgrt_aff_t)0x3
#endif

#define BGRT_SCHED_LOCAL_LOAD_BALANCER()
#define BGRT_SCHED_IDLE_LOAD_BALANCER()

extern void sched_lb_test_start(void);
#define BGRT_SCHED_LB_TEST_START()     sched_lb_test_start()

#define BGRT_SCHED_SYSTICK_HOOK_ADD() (bgrt_kernel.timer.tick = systick_hook)

#define BGRT_SCHED_FIX_PROC_2() sched_fix_bgrt_proc_2()

#define GREEN PICO_DEFAULT_LED_PIN
#define RED   PICO_DEFAULT_LED_PIN

#define LED_ON(CL)  gpio_put(CL, 1)
#define LED_OFF(CL) gpio_put(CL, 0)

void kernel_preemt_hook_add(void(*arg)(void));
void kernel_preemt_hook(void);
void test_do_nothing(void);

void init_hardware(void);
void sched_fix_bgrt_proc_2(void);

// proc test functions
void test_output(bgrt_bool_t test_result, bgrt_cnt_t test_mun);
void test_start(void);
void tests_end(void);

// signal test functions
extern unsigned char test_var_sig;
void test_clear(void);
void test_inc(void);

void systick_hook(void);
