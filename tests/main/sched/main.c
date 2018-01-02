#include <test_func.h>

bgrt_proc_t proc[6];
unsigned char barrier[10];
bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

void main_with_return(void * arg)
{
    (void)arg;
    BGRT_PROC_RUN(PID1);
    BGRT_PROC_RUN(PID2);
    BGRT_PROC_RUN(PID3);
    BGRT_PROC_RUN(PID4);
    BGRT_PROC_RUN(PID5);

    bgrt_wait_time(100);

    // Reset proc[2] BGRT_PROC_FLG_RT and BGRT_PROC_STATE_WD_STOP before second run.
    BGRT_SCHED_FIX_PROC_2();
    BGRT_PROC_RUN(PID2);

    bgrt_wait_time(100);
    // Start load balancing test on multicore system (changes affinity of running processes).
    BGRT_SCHED_LB_TEST_START();

    bgrt_wait_time(100);
}
void main_lb(void * arg)
{
    (void)arg;
    while (1)
    {
        bgrt_wait_time(10);
        // Run local load balancer on multicore system with local load balancing.
        BGRT_SCHED_LOCAL_LOAD_BALANCER();
    }
}
void main_no_return(void * arg)
{
    (void)arg;
    while (1)
    {
        bgrt_wait_time(10);
    }
}

int main(void)
{
    /***************************************************
    *          For test purposes only!!!               *
    *  It is strongly recommended to initiate hardware *
    *         AFTER bgrt_init() call!!!                *
    ***************************************************/
    /*
     * This function disables interrupts
     * and initiates hardware.
     */
    init_hardware();
    bgrt_init();

    BGRT_SCHED_SYSTICK_HOOK_ADD();

    bgrt_priv_proc_init(PR0, main_with_return,   SVH0, RSH0, 0, &bgrt_proc_stack[0][BGRT_PROC_STACK_SIZE-1], 1,      1, 0 BGRT_SCHED_ARG_END);
    bgrt_priv_proc_init(PR1, main_lb,            SVH1, RSH1, 0, &bgrt_proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 BGRT_SCHED_ARG_END);
    bgrt_priv_proc_init(PR2, main_no_return,     SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 2,      2, 1 BGRT_SCHED_ARG_END);
    bgrt_priv_proc_init(PR3, main_no_return,     SVH3, RSH3, 0, &bgrt_proc_stack[3][BGRT_PROC_STACK_SIZE-1], 3,      3, 0 BGRT_SCHED_ARG_END);
    bgrt_priv_proc_init(PR4, main_no_return,     SVH4, RSH4, 0, &bgrt_proc_stack[4][BGRT_PROC_STACK_SIZE-1], 3,      4, 0 BGRT_SCHED_ARG_END);
    bgrt_priv_proc_init(PR5, main_no_return,     SVH5, RSH5, 0, &bgrt_proc_stack[5][BGRT_PROC_STACK_SIZE-1], 3,      5, 0 BGRT_SCHED_ARG_END);

    proc[5].flags &= ~BGRT_PROC_FLG_RR;

    bgrt_priv_proc_run(PR0);

    bgrt_start();
    return 0;
}
