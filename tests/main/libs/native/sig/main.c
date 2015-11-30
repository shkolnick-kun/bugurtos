#include <test_func.h>
#include <sig.h>

bgrt_proc_t proc[6];
bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

sig_t test_sig;
void (*test_hook)(void);

void test_running(void)
{
    test_output( (proc[2].flags & BGRT_PROC_STATE_MASK) == BGRT_PROC_STATE_RUNNING, 5 );
    test_inc();
}

bgrt_flag_t status;

void main_bgrt_proc_test( void * arg )
{
    bgrt_proc_run( &proc[1] );

    test_start();

    // sig_signal test 1
    // No processes are waiting for signal, test must not
    test_var_sig = 1;
    test_hook = test_clear;
    sig_signal( &test_sig );
    test_output( (1 == test_var_sig), 1 );

    // sig_broadcast test 2
    // No process must start
    sig_broadcast( &test_sig );
    test_output( test_var_sig, 2 );

    bgrt_proc_run( &proc[2] );
    bgrt_proc_run( &proc[3] );
    bgrt_proc_run( &proc[4] );
    bgrt_proc_run( &proc[5] );

    bgrt_wait_time( 20 );
    // All processes of interest are waiting for signal now!
    // sig_signal test 6
    test_var_sig = 0;
    test_hook = test_running;


    sig_signal( &test_sig );
    bgrt_wait_time( 20 );
    test_output( (1 == test_var_sig), 6 );

    bgrt_wait_time( 20 );

    // sig_broadcast test 7
    test_var_sig = 0;
    test_hook = test_inc;
    status = sig_broadcast( &test_sig );
    test_output( BGRT_ST_EEMPTY == status, 7);

    bgrt_wait_time( 20 );
    test_output( (4 == test_var_sig), 8 );

    tests_end();
}

void main_sig( void * arg )
{
    while(1)
    {
        bgrt_flag_t status;
        status = sig_wait( &test_sig );
        test_output( BGRT_ST_OK == status, 9 );
        test_hook();
        bgrt_wait_time(1);
    }
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
    /***************************************************
    *          For test purposes only!!!               *
    *  It is strongly recommended to initiate hardware *
    *         AFTER bgrt_init() call!!!              *
    ***************************************************/
    /*
     * This function disables interrupts
     * and initiates hardware.
     */
    init_hardware();
    bgrt_init();

    BGRT_SCHED_SYSTICK_HOOK_ADD();

    bgrt_proc_init_isr( &proc[0], main_bgrt_proc_test, SVH0, RSH0, 0, &bgrt_proc_stack[0][BGRT_PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    bgrt_proc_init_isr( &proc[1], main_lb,        SVH1, RSH1, 0, &bgrt_proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 BGRT_SCHED_ARG_END );
    bgrt_proc_init_isr( &proc[2], main_sig,       SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 0,      2, 0 ARG_END );
    bgrt_proc_init_isr( &proc[3], main_sig,       SVH3, RSH3, 0, &bgrt_proc_stack[3][BGRT_PROC_STACK_SIZE-1], 1,      2, 0 ARG_END );
    bgrt_proc_init_isr( &proc[4], main_sig,       SVH4, RSH4, 0, &bgrt_proc_stack[4][BGRT_PROC_STACK_SIZE-1], 2,      2, 0 ARG_END );
    bgrt_proc_init_isr( &proc[5], main_sig,       SVH5, RSH5, 0, &bgrt_proc_stack[5][BGRT_PROC_STACK_SIZE-1], 3,      2, 0 ARG_END );

    sig_init_isr( &test_sig );

    bgrt_proc_run_isr( &proc[0] );

    bgrt_start();
    return 0;
}
