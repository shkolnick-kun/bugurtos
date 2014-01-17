#include <bugurt.h>
#include <LPC11xx.h>
#include <gpio.h>
#include <cr_section_macros.h>
#include <NXP/crp.h>
extern proc_t proc[6];
extern stack_t proc_stack[6][PROC_STACK_SIZE];

#define ARG_END

// No load balancing, single core!
#define SCHED_LOCAL_LOAD_BALANCER()
#define SCHED_IDLE_LOAD_BALANCER()
#define SCHED_ARG_END
#define SCHED_LB_TEST_START()

#define SCHED_SYSTICK_HOOK_ADD() (kernel.timer_tick = systick_hook)

#define SCHED_FIX_PROC_2() sched_fix_proc_2()

#define LED_PORT 0
#define LED_BIT 7
#define LED_ON()  GPIOSetValue( LED_PORT, LED_BIT, 1 )
#define LED_OFF() GPIOSetValue( LED_PORT, LED_BIT, 0 )

void init_hardware(void);
void sched_fix_proc_2(void);

// proc test functions
void test_output( bool_t test_result, count_t test_mun );
void test_start(void);
void tests_end(void);

// signal test functions
extern unsigned char test_var_sig;
void test_clear(void);
void test_inc(void);


void systick_hook(void);


