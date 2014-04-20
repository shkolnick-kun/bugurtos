#include <bugurt_kernel.h>
#include <util/delay.h>
extern proc_t proc[6];
extern stack_t proc_stack[6][PROC_STACK_SIZE];
//======================================================================
// Generick proc_init argument terminator.
#define ARG_END ,(affinity_t)0x3
// Scheduler test proc_init argument terminator
#if (CONFIG_LB_SCHEME != 0)
    #define SCHED_ARG_END ,(affinity_t)0x2
#else
    #define SCHED_ARG_END ,(affinity_t)0x3
#endif
//======================================================================
#if (CONFIG_LB_SCHEME == 2)
    #define SCHED_LOCAL_LOAD_BALANCER() sched_lazy_local_load_balancer()
#else  //CONFIG_LB_SCHEME == 2
    #define SCHED_LOCAL_LOAD_BALANCER()
#endif //CONFIG_LB_SCHEME == 2
//======================================================================
#if (CONFIG_LB_SCHEME == 2)
    #define SCHED_IDLE_LOAD_BALANCER() sched_lazy_local_load_balancer()
#else  //CONFIG_LB_SCHEME == 2
#if (CONFIG_LB_SCHEME == 3)
    #define SCHED_IDLE_LOAD_BALANCER() sched_lazy_global_load_balancer()
#else  //CONFIG_LB_SCHEME == 3
    #define SCHED_IDLE_LOAD_BALANCER()
#endif //CONFIG_LB_SCHEME == 3
#endif //CONFIG_LB_SCHEME == 2
//======================================================================

#define SCHED_LB_TEST_START() sched_lb_test_start()

#define SCHED_SYSTICK_HOOK_ADD() sched_systick_hook_add()
#define SCHED_FIX_PROC_2() sched_fix_proc_2()

void init_hardware(void);

// Scheduler test functions
void sched_fix_proc_2(void);
void sched_lb_test_start(void);
void sched_systick_hook_add(void);

void main_lb( void * arg );

void blink_1(void);
void blink_2(void);
void blink_3(void);
void blink_4(void);
void blink_5(void);
void blink_6(void);
void load_bar_graph(void);

// proc test functions
void test_output( bool_t test_result, count_t test_mun );
void test_start(void);
void tests_end(void);

// signal test functions
extern unsigned char test_var_sig;
void test_clear(void);
void test_inc(void);
