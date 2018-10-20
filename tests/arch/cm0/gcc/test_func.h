#include <bugurt.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/cm3/dwt.h>

extern void(*test_kernel_preempt)(void);
extern bgrt_proc_t proc[6];
extern bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

#define ARG_END

// No load balancing, single core!
#define BGRT_SCHED_LOCAL_LOAD_BALANCER()
#define BGRT_SCHED_IDLE_LOAD_BALANCER()
#define BGRT_SCHED_ARG_END
#define BGRT_SCHED_LB_TEST_START()

#define BGRT_SCHED_SYSTICK_HOOK_ADD() (bgrt_kernel.timer.tick = systick_hook)

#define BGRT_SCHED_FIX_PROC_2() sched_fix_bgrt_proc_2()

#define GREEN GPIO9
#define RED   GPIO8

#define LED_ON(CL)  gpio_set(GPIOC, CL)
#define LED_OFF(CL) gpio_clear(GPIOC, CL)

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


