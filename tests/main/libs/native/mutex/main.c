#include <test_func.h>
#include <mutex.h>

proc_t proc[6];
bgrt_stack_t proc_stack[6][PROC_STACK_SIZE];

mutex_t test_mutex;

void main_with_return( void * arg )
{
    proc_run( &proc[1] );

    test_start();

    //mutex_try_lock test 1
    test_output( (BGRT_ST_OK == mutex_try_lock( &test_mutex )), 1 );
    // mutex_try_lock test 2
    test_output( ( (&proc[0]) == SYNC_GET_OWNER( &test_mutex )), 2 );
    // mutex_try_lock test 3
    test_output( ( proc[0].parent.prio == 3 ), 3 );
    //mutex_try_lock test 3
    //mutex_lock test 4
    proc_run( &proc[2] );
    bgrt_wait_time( 2 );
    test_output( ((PROC_STATE_SYNC_SLEEP) == (proc[2].flags & (PROC_STATE_MASK) ) ), 4 );
    //mutex_lock test 7
    test_output( !PROC_RUN_TEST( (&proc[2]) ), 5 );
    //mutex_lock test 8
    test_output( (proc[2].parent.list == (void *)&test_mutex.wait), 6 );
    //mutex_lock test 9
    test_output( ( proc[0].parent.prio == 1 ), 7 );
    //mutex_try_lock test 8
    // must not lock
    test_output( (BGRT_ST_ROLL == mutex_try_lock( &test_mutex )), 8 );
    //mutex_try_lock test 9
    mutex_free( &test_mutex );
    bgrt_wait_time( 2 );
    test_output( ( proc[0].parent.prio == 4 ), 9 );
    //mutex_free test 10
    test_output( ( (&proc[2]) == SYNC_GET_OWNER( &test_mutex )), 10 );
    //mutex_free test 11
    // proc[2] must free mutexaphore and self stop
    proc_run( &proc[2] );
    bgrt_wait_time( 2 );
    test_output( ( ((proc_t *)0) == SYNC_GET_OWNER( &test_mutex )), 11 );
    // mutex_lock test 12
    // proc[2] must lock a test_mutex and self ctop
    proc_run( &proc[2] );
    bgrt_wait_time( 2 );
    test_output( ( (&proc[2]) == SYNC_GET_OWNER( &test_mutex )), 12 );
    //mutex_lock test 13
    test_output( (proc[2].flags & PROC_STATE_MASK) != PROC_STATE_SYNC_SLEEP, 13 );

    proc_run( &proc[2] );

    tests_end();
}
void main_lb( void * arg )
{
    while(1)
    {
        bgrt_wait_time(10);
        // Run local load balancer on multicore system with local load balancing.
        SCHED_LOCAL_LOAD_BALANCER();
    }
}
void main_mutex( void * arg )
{
    while(1)
    {
        mutex_lock( &test_mutex );
        proc_self_stop();
        mutex_free( &test_mutex );
        proc_self_stop();
    }
}
void bgrt_idle_main( void * arg )
{
    while(1)
    {
        bgrt_wait_time(10);
        // Run local/global load balancer on multicore system with local/global lazy load balancing.
        SCHED_IDLE_LOAD_BALANCER();
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

    SCHED_SYSTICK_HOOK_ADD();

    proc_init_isr( &proc[0], main_with_return,   SVH0, RSH0, 0, &proc_stack[0][PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    proc_init_isr( &proc[1], main_lb,            SVH1, RSH1, 0, &proc_stack[1][PROC_STACK_SIZE-1], LOWEST, 1, 0 SCHED_ARG_END );
    proc_init_isr( &proc[2], main_mutex,         SVH2, RSH2, 0, &proc_stack[2][PROC_STACK_SIZE-1], 1,      2, 0 ARG_END );

    mutex_init_isr( &test_mutex, 3 );

    proc_run_isr( &proc[0] );

    bgrt_start();
    return 0;
}