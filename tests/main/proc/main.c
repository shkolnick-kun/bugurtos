#include <test_func.h>

bgrt_proc_t proc[6];
bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

bgrt_bool_t test;

void main_proc_test( void * arg )
{
    bgrt_proc_run( PID1 );

    test_start();
    // No other processes are running,
    // so it's not necessary to disable interrupts or to bgrt_spin_lock something.

    // bgrt_proc_run test 1
    proc[2].flags |= BGRT_PROC_STATE_DEAD;
    // Must NOT run the process.
    test = ( BGRT_ST_EAGAIN == bgrt_proc_run( PID2 ) );
    test_output( test , 1 );

    // bgrt_proc_run test 2
    proc[2].flags &= BGRT_PROC_STATE_CLEAR_MASK;
    proc[2].flags |= BGRT_PROC_FLG_LOCK;
    // Must run the process
    test = ( BGRT_ST_OK == bgrt_proc_run( PID2 ) );
    test_output( test , 2 );

    // bgrt_proc_terminate test 3
    bgrt_wait_time( 10 );
    // proc[2] has higher priority, so it must BE DEAD now!
    test = (bgrt_bool_t)( BGRT_PROC_STATE_DEAD == ( proc[2].flags & BGRT_PROC_STATE_MASK ) );
    test_output( test , 3 );

    // bgrt_proc_terminate test 4
    bgrt_proc_run( PID3 );
    bgrt_wait_time( 10 );
    test = (bgrt_bool_t)( BGRT_PROC_STATE_END == ( proc[3].flags & BGRT_PROC_STATE_MASK ) );
    test_output( test , 4 );

    // bgrt_proc_restart test 5
    // Must NOT restart!
    test = ( BGRT_ST_ESTAT == bgrt_proc_restart( PID2 ) );
    test_output( test , 5 );

    // bgrt_proc_restart test 6
    // Must restart!
    test = ( BGRT_ST_OK == bgrt_proc_restart( PID3 ) );
    test_output( test , 6 );

    // bgrt_proc_stop test 7
    // Must return 1, process is not running now!
    proc[2].flags &= ~BGRT_PROC_FLG_LOCK;
    proc[2].flags &= BGRT_PROC_STATE_CLEAR_MASK;
    test = ( BGRT_ST_OK == bgrt_proc_stop( PID2 ) );
    test_output( test , 7 );

    proc[4].flags |= BGRT_PROC_FLG_LOCK;
    proc[4].cnt_lock = (bgrt_cnt_t)1;
    bgrt_proc_run( PID4 );

    // bgrt_proc_free test 8
    // Must NOT stop the process!
    bgrt_wait_time(2); // let proc[4] to call bgrt_proc_free!
    test = (bgrt_bool_t)BGRT_PROC_RUN_TEST( (PR4) );
    test_output( test , 8 );

    // bgrt_proc_stop test 9
    // Must stop the process!
    test = ( BGRT_ST_OK == bgrt_proc_stop( PID4 ) );
    test_output( test , 9 );

    // bgrt_proc_stop test 10
    // Must NOT stop the process!
    // proc[4] is stopped, we can work with it,s properties!
    proc[4].flags |= BGRT_PROC_FLG_LOCK;
    proc[4].cnt_lock = (bgrt_cnt_t)1;

    bgrt_proc_run( PID4 );
    test = ( BGRT_ST_EAGAIN == bgrt_proc_stop( PID4 ) );
    test = test && !!( proc[4].flags & BGRT_PROC_FLG_PRE_STOP );
    test_output( test , 10 );

    // bgrt_proc_free test 11
    // Must stop the process!
    bgrt_wait_time(20); // let proc[4] to call bgrt_proc_free!
    test = !BGRT_PROC_RUN_TEST( (PR4) );
    test_output( test , 11 );

    // bgrt_proc_reset_watchdog test 12
    test = 0;
    bgrt_proc_run( PID5 );
    bgrt_wait_time(10); // let proc[5] test bgrt_proc_reset_watchdog!
    test_output( test , 12 );

    // bgrt_proc_self_stop test 13
    bgrt_wait_time(10); // let proc[4] to call bgrt_proc_self_stop!
    test = !BGRT_PROC_RUN_TEST( (PR4) );
    test_output( test , 13 );

    // bgrt_proc_yeld test 14
    test = 0;
    bgrt_proc_run( PID5 );
    bgrt_wait_time(10);
    test_output( test , 14 );

    // bgrt_proc_reset_watchdog test 15
    test = 0;
    proc[5].flags &= ~BGRT_PROC_FLG_RT;
    bgrt_proc_run( PID5 );
    bgrt_wait_time(10); // let proc[5] test bgrt_proc_reset_watchdog!
    test_output( test , 15 );

    // bgrt_proc_reset_watchdog test 16
    bgrt_proc_run( PID5 );
    bgrt_wait_time(10); // let proc[5] test bgrt_proc_reset_watchdog!
    test_output( test , 16 );

    tests_end();
}

void main_with_return( void * arg )
{
    bgrt_wait_time(1);
}

void main_wd_ss( void * arg )
{
    // bgrt_proc_reset_watchdog test 12
    bgrt_wait_time(1);
    bgrt_proc_reset_watchdog();
    bgrt_wait_time(1);
    bgrt_proc_reset_watchdog();
    bgrt_wait_time(1);
    bgrt_proc_reset_watchdog();
    bgrt_wait_time(1);
    bgrt_proc_reset_watchdog();
    test = 1; // If watchdog has been reset then test must pass.
    bgrt_proc_self_stop();

    bgrt_wait_time(1);
    bgrt_sched_proc_yeld();
    bgrt_wait_time(1);
    bgrt_sched_proc_yeld();
    bgrt_wait_time(1);
    bgrt_sched_proc_yeld();
    bgrt_wait_time(1);
    bgrt_sched_proc_yeld();
    test = 1; // If watchdog has been reset then test must pass.
    bgrt_proc_self_stop();

    // bgrt_proc_reset_watchdog test 14
    bgrt_wait_time(1);
    bgrt_proc_reset_watchdog();
    test = (proc[5].timer != proc[5].time_quant);
    bgrt_proc_self_stop();

    bgrt_wait_time(1);
    bgrt_sched_proc_yeld();
    test = (proc[5].timer == proc[5].time_quant);
}

void main_fs( void * arg )
{
    // For bgrt_proc_free tests 8 and 11
    bgrt_proc_free();
    bgrt_wait_time(10);
    bgrt_proc_free();
    while(1)
    {
        //Panic !!1
    }
}

#ifdef BGRT_CONFIG_SAVE_POWER

#define IDLE_YELD() if( bgrt_sched_proc_yeld() )BGRT_CONFIG_SAVE_POWER()

#else //BGRT_CONFIG_SAVE_POWER

#define IDLE_YELD() bgrt_sched_proc_yeld()

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

    _bgrt_proc_init( PR0, main_proc_test,     SVH0, RSH0, 0, &bgrt_proc_stack[0][BGRT_PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    _bgrt_proc_init( PR1, main_lb,            SVH1, RSH1, 0, &bgrt_proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 BGRT_SCHED_ARG_END );
    _bgrt_proc_init( PR2, main_with_return,   SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 0,      2, 0 ARG_END );
    _bgrt_proc_init( PR3, main_with_return,   SVH3, RSH3, 0, &bgrt_proc_stack[3][BGRT_PROC_STACK_SIZE-1], 1,      2, 0 ARG_END );
    _bgrt_proc_init( PR4, main_fs,            SVH4, RSH4, 0, &bgrt_proc_stack[4][BGRT_PROC_STACK_SIZE-1], 2,      2, 0 ARG_END );
    _bgrt_proc_init( PR5, main_wd_ss,         SVH5, RSH5, 0, &bgrt_proc_stack[5][BGRT_PROC_STACK_SIZE-1], 3,      2, 1 ARG_END );

    _bgrt_proc_run( PR0 );

    bgrt_start();
    return 0;
}
