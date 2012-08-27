#include <bugurt_kernel.h>

extern proc_t proc[6];
extern stack_t proc_stack[6][PROC_STACK_SIZE];

// No load balancing, single core!
#define SCHED_LOCAL_LOAD_BALANCER()
#define SCHED_IDLE_LOAD_BALANCER()
#define SCHED_ARG_END
#define SCHED_LB_TEST_START()
#define SCHED_SYSTICK_HOOK_ADD()
#define SCHED_FIX_PROC_2() sched_fix_proc_2()

void init_hardware(void);
void sched_fix_proc_2(void);

void blink_1(void);
void blink_2(void);
void blink_3(void);
void blink_4(void);
void blink_5(void);
void blink_6(void);
