#include <test_func.h>

proc_t proc[6];
bgrt_stack_t proc_stack[6][PROC_STACK_SIZE];

bgrt_bool_t test;

void main_proc_test( void * arg )
{
    proc_run( &proc[1] );

    test_start();
    // No other processes are running,
    // so it's not necessary to disable interrupts or to bgrt_spin_lock something.

    // proc_run test 1
    proc[2].flags |= PROC_STATE_DEAD;
    // Must NOT run the process.
    test = ( BGRT_ST_ROLL == proc_run( &proc[2] ) );
    test_output( test , 1 );

    // proc_run test 2
    proc[2].flags &= PROC_STATE_CLEAR_MASK;
    proc[2].flags |= PROC_FLG_LOCK;
    // Must run the process
    test = ( BGRT_ST_OK == proc_run( &proc[2] ) );
    test_output( test , 2 );

    // proc_terminate test 3
    bgrt_wait_time( 10 );
    // proc[2] has higher priority, so it must BE DEAD now!
    test = (bgrt_bool_t)( PROC_STATE_DEAD == ( proc[2].flags & PROC_STATE_MASK ) );
    test_output( test , 3 );

    // proc_terminate test 4
    proc_run( &proc[3] );
    bgrt_wait_time( 10 );
    test = (bgrt_bool_t)( PROC_STATE_END == ( proc[3].flags & PROC_STATE_MASK ) );
    test_output( test , 4 );

    // proc_restart test 5
    // Must NOT restart!
    test = ( BGRT_ST_ESTAT == proc_restart( &proc[2] ) );
    test_output( test , 5 );

    // proc_restart test 6
    // Must restart!
    test = ( BGRT_ST_OK == proc_restart( &proc[3] ) );
    test_output( test , 6 );

    // proc_stop test 7
    // Must return 1, process is not running now!
    proc[2].flags &= ~PROC_FLG_LOCK;
    proc[2].flags &= PROC_STATE_CLEAR_MASK;
    test = ( BGRT_ST_OK == proc_stop( &proc[2] ) );
    test_output( test , 7 );


    proc_run( &proc[4] );

    // proc_free test 8
    // Must NOT stop the process!
    bgrt_wait_time(2); // let proc[4] to call proc_free!
    test = (bgrt_bool_t)PROC_RUN_TEST( (&proc[4]) );
    test_output( test , 8 );

    // proc_stop test 9
    // Must stop the process!
    test = ( BGRT_ST_OK == proc_stop( &proc[4] ) );
    test_output( test , 9 );

    // proc_stop test 10
    // Must NOT stop the process!
    // proc[4] is stopped, we can work with it,s properties!
    proc[4].flags |= PROC_FLG_LOCK;
    proc[4].cnt_lock = (bgrt_cnt_t)1;

    proc_run( &proc[4] );
    test = ( BGRT_ST_ROLL == proc_stop( &proc[4] ) );
    test = test && !!( proc[4].flags & PROC_FLG_PRE_STOP );
    test_output( test , 10 );

    // proc_free test 11
    // Must stop the process!
    bgrt_wait_time(20); // let proc[4] to call proc_free!
    test = !PROC_RUN_TEST( (&proc[4]) );
    test_output( test , 11 );

    // proc_reset_watchdog test 12
    test = 0;
    proc_run( &proc[5] );
    bgrt_wait_time(10); // let proc[5] test proc_reset_watchdog!
    test_output( test , 12 );

    // proc_self_stop test 13
    bgrt_wait_time(10); // let proc[4] to call proc_self_stop!
    test = !PROC_RUN_TEST( (&proc[4]) );
    test_output( test , 13 );

    // proc_yeld test 14
    test = 0;
    proc_run( &proc[5] );
    bgrt_wait_time(10);
    test_output( test , 14 );

    // proc_reset_watchdog test 15
    test = 0;
    proc[5].flags &= ~PROC_FLG_RT;
    proc_run( &proc[5] );
    bgrt_wait_time(10); // let proc[5] test proc_reset_watchdog!
    test_output( test , 15 );

    // proc_reset_watchdog test 16
    proc_run( &proc[5] );
    bgrt_wait_time(10); // let proc[5] test proc_reset_watchdog!
    test_output( test , 16 );

    tests_end();
}

void main_with_return( void * arg )
{
    bgrt_wait_time(1);
}

void main_wd_ss( void * arg )
{
    // proc_reset_watchdog test 12
    bgrt_wait_time(1);
    proc_reset_watchdog();
    bgrt_wait_time(1);
    proc_reset_watchdog();
    bgrt_wait_time(1);
    proc_reset_watchdog();
    bgrt_wait_time(1);
    proc_reset_watchdog();
    test = 1; // If wathdog has been reset then test must pass.
    proc_self_stop();

    bgrt_wait_time(1);
    sched_proc_yeld();
    bgrt_wait_time(1);
    sched_proc_yeld();
    bgrt_wait_time(1);
    sched_proc_yeld();
    bgrt_wait_time(1);
    sched_proc_yeld();
    test = 1; // If wathdog has been reset then test must pass.
    proc_self_stop();

    // proc_reset_watchdog test 14
    bgrt_wait_time(1);
    proc_reset_watchdog();
    test = (proc[5].timer != proc[5].time_quant);
    proc_self_stop();

    bgrt_wait_time(1);
    sched_proc_yeld();
    test = (proc[5].timer == proc[5].time_quant);
}

void main_fs( void * arg )
{
    // For proc_free tests 8 and 11
    proc_free();
    bgrt_wait_time(10);
    proc_free();
    while(1)
    {
        //Panic !!1
    }
}

#ifdef BGRT_CONFIG_SAVE_POWER

#define IDLE_YELD() if( sched_proc_yeld() )BGRT_CONFIG_SAVE_POWER()

#else //BGRT_CONFIG_SAVE_POWER

#define IDLE_YELD() sched_proc_yeld()

#endif//BGRT_CONFIG_SAVE_POWER

void main_lb( void * arg )
{
    while(1)
    {
        // Run local load balancer on multicore system with local load balancing.
        BGRT_SCHED_LOCAL_LOAD_BALANCER();
        IDLE_YELD();
    }
}

void bgrt_idle_main( void * arg )
{
    while(1)
    {
        // Run local/global load balancer on multicore system with local/global lazy load balancing.
        BGRT_SCHED_IDLE_LOAD_BALANCER();
        IDLE_YELD();
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

    proc_init_isr( &proc[0], main_proc_test,     SVH0, RSH0, 0, &proc_stack[0][PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    proc_init_isr( &proc[1], main_lb,            SVH1, RSH1, 0, &proc_stack[1][PROC_STACK_SIZE-1], LOWEST, 1, 0 BGRT_SCHED_ARG_END );
    proc_init_isr( &proc[2], main_with_return,   SVH2, RSH2, 0, &proc_stack[2][PROC_STACK_SIZE-1], 0,      2, 0 ARG_END );
    proc_init_isr( &proc[3], main_with_return,   SVH3, RSH3, 0, &proc_stack[3][PROC_STACK_SIZE-1], 1,      2, 0 ARG_END );
    proc_init_isr( &proc[4], main_fs,            SVH4, RSH4, 0, &proc_stack[4][PROC_STACK_SIZE-1], 2,      2, 0 ARG_END );
    proc_init_isr( &proc[5], main_wd_ss,         SVH5, RSH5, 0, &proc_stack[5][PROC_STACK_SIZE-1], 3,      2, 1 ARG_END );

    proc_run_isr( &proc[0] );

    bgrt_start();
    return 0;
}
