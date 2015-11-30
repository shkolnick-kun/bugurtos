#include <bugurt.h>
#include <util/delay.h>
extern proc_t proc[6];
extern bgrt_stack_t proc_stack[6][BGRT_PROC_STACK_SIZE];
//======================================================================
// Generic proc_init argument terminator.
#define ARG_END ,(bgrt_aff_t)0x3
// Scheduler test proc_init argument terminator
#if (BGRT_CONFIG_LB_SCHEME != 0)
    #define BGRT_SCHED_ARG_END ,(bgrt_aff_t)0x2
#else
    #define BGRT_SCHED_ARG_END ,(bgrt_aff_t)0x3
#endif
//======================================================================
#if (BGRT_CONFIG_LB_SCHEME == 2)
    #define BGRT_SCHED_LOCAL_LOAD_BALANCER() bgrt_sched_lazy_local_load_balancer()
#else  //BGRT_CONFIG_LB_SCHEME == 2
    #define BGRT_SCHED_LOCAL_LOAD_BALANCER()
#endif //BGRT_CONFIG_LB_SCHEME == 2
//======================================================================
#if (BGRT_CONFIG_LB_SCHEME == 2)
    #define BGRT_SCHED_IDLE_LOAD_BALANCER() bgrt_sched_lazy_local_load_balancer()
#else  //BGRT_CONFIG_LB_SCHEME == 2
#if (BGRT_CONFIG_LB_SCHEME == 3)
    #define BGRT_SCHED_IDLE_LOAD_BALANCER() bgrt_sched_lazy_global_load_balancer()
#else  //BGRT_CONFIG_LB_SCHEME == 3
    #define BGRT_SCHED_IDLE_LOAD_BALANCER()
#endif //BGRT_CONFIG_LB_SCHEME == 3
#endif //BGRT_CONFIG_LB_SCHEME == 2
//======================================================================

#define BGRT_SCHED_LB_TEST_START() sched_lb_test_start()

#define BGRT_SCHED_SYSTICK_HOOK_ADD() sched_systick_hook_add()
#define BGRT_SCHED_FIX_BGRT_PROC_2() sched_fix_proc_2()

void init_hardware(void);

// Scheduler test functions
void sched_fix_proc_2(void);
void sched_lb_test_start(void);
void sched_systick_hook_add(void);

void kernel_preemt_hook_add( void(*arg)(void) );

void main_lb( void * arg );

void test_do_nothing(void);

void blink_1(void);
void blink_2(void);
void blink_3(void);
void blink_4(void);
void blink_5(void);
void blink_6(void);
void load_bar_graph(void);

// proc test functions
void test_output( bgrt_bool_t test_result, bgrt_cnt_t test_mun );
void test_start(void);
void tests_end(void);

// signal test functions
extern unsigned char test_var_sig;
void test_clear(void);
void test_inc(void);
