#include <test_func.h>

proc_t proc[6];
bgrt_stack_t proc_stack[6][BGRT_PROC_STACK_SIZE];

void main_with_return( void * arg )
{
    proc_run( &proc[1] );
    proc_run( &proc[2] );
    proc_run( &proc[3] );
    proc_run( &proc[4] );
    proc_run( &proc[5] );

    bgrt_wait_time(100);
    // Reset proc[2] BGRT_PROC_FLG_RT and BGRT_PROC_STATE_WD_STOP before second run.
    BGRT_SCHED_FIX_BGRT_PROC_2();
    proc_run( &proc[2] );

    bgrt_wait_time(100);
    // Start load balancing test on multicore system (chnges affinity of running processes).
    BGRT_SCHED_LB_TEST_START();

    bgrt_wait_time(100);
}
void main_lb( void * arg )
{
    while(1)
    {
        bgrt_wait_time(10);
        // Run local load balancer on multicore system with local load balancing.
        BGRT_SCHED_LOCAL_LOAD_BALANCER();
    }
}
void main_no_return( void * arg )
{
    while(1)
    {
        bgrt_wait_time(10);
    }
}
void bgrt_idle_main( void * arg )
{
    while(1)
    {
        bgrt_wait_time(10);
        // Run local/global load balancer on multicore system with local/global lazy load balancing.
        BGRT_SCHED_IDLE_LOAD_BALANCER();
    }
}
int main(void)
{
    /**************************************************
    *          For test purposes only!!!              *
    *  It is strongly recomended to initiate hardware *
    *         AFTER bgrt_init() call!!!             *
    **************************************************/
    /*
     * This function disables interrupts
     * and initiates hardware.
     */
    init_hardware();
    bgrt_init();

    BGRT_SCHED_SYSTICK_HOOK_ADD();

    proc_init_isr( &proc[0], main_with_return,   SVH0, RSH0, 0, &proc_stack[0][BGRT_PROC_STACK_SIZE-1], 1,      1, 0 BGRT_SCHED_ARG_END );
    proc_init_isr( &proc[1], main_lb,            SVH1, RSH1, 0, &proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 BGRT_SCHED_ARG_END );
    proc_init_isr( &proc[2], main_no_return,     SVH2, RSH2, 0, &proc_stack[2][BGRT_PROC_STACK_SIZE-1], 2,      2, 1 BGRT_SCHED_ARG_END );
    proc_init_isr( &proc[3], main_no_return,     SVH3, RSH3, 0, &proc_stack[3][BGRT_PROC_STACK_SIZE-1], 3,      3, 0 BGRT_SCHED_ARG_END );
    proc_init_isr( &proc[4], main_no_return,     SVH4, RSH4, 0, &proc_stack[4][BGRT_PROC_STACK_SIZE-1], 3,      4, 0 BGRT_SCHED_ARG_END );
    proc_init_isr( &proc[5], main_no_return,     SVH5, RSH5, 0, &proc_stack[5][BGRT_PROC_STACK_SIZE-1], 3,      5, 0 BGRT_SCHED_ARG_END );

    proc[5].flags &= ~BGRT_PROC_FLG_RR;

    proc_run_isr( &proc[0] );

    bgrt_start();
    return 0;
}
