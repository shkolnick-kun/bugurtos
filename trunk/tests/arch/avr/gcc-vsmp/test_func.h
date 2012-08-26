#include <bugurt_kernel.h>

extern proc_t proc[6];
extern stack_t proc_stack[6][PROC_STACK_SIZE];
//======================================================================
#if (CONFIG_LB_SCHEME != 0)
    #define SCHED_ARG_END ,(affinity_t)0x2
#else
    #define SCHED_ARG_END ,(affinity_t)0x3
#endif
//======================================================================
#if (CONFIG_LB_SCHEME == 2)
    #define SCHED_LOCAL_LOAD_BALANCER() proc_lazy_local_load_balancer()
#else  //CONFIG_LB_SCHEME == 2
    #define SCHED_LOCAL_LOAD_BALANCER()
#endif //CONFIG_LB_SCHEME == 2
//======================================================================
#if (CONFIG_LB_SCHEME == 2)
    #define SCHED_IDLE_LOAD_BALANCER() proc_lazy_local_load_balancer()
#else  //CONFIG_LB_SCHEME == 2
#if (CONFIG_LB_SCHEME == 3)
    #define SCHED_IDLE_LOAD_BALANCER() proc_lazy_global_load_balancer()
#else  //CONFIG_LB_SCHEME == 3
    #define SCHED_IDLE_LOAD_BALANCER()
#endif //CONFIG_LB_SCHEME == 3
#endif //CONFIG_LB_SCHEME == 2
//======================================================================

#define SCHED_LB_TEST_START() sched_lb_test_start()
#define SCHED_SYSTICK_HOOK_ADD() sched_systick_hook_add()
#define SCHED_FIX_PROC_2() sched_fix_proc_2()

void init_hardware(void);
void sched_fix_proc_2(void);
void sched_lb_test_start(void);
void sched_systick_hook_add(void);
