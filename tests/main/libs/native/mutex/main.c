#include <test_func.h>
#include <mutex.h>

bgrt_proc_t proc[6];
bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

mutex_t test_mutex;

void main_with_return( void * arg )
{
    bgrt_proc_run( &proc[1] );

    test_start();

    //mutex_try_lock test 1
    test_output( (BGRT_ST_OK == mutex_try_lock( &test_mutex )), 1 );
    // mutex_try_lock test 2
    test_output( ( (&proc[0]) == BGRT_SYNC_GET_OWNER( &test_mutex )), 2 );
    // mutex_try_lock test 3
    test_output( ( proc[0].parent.prio == 3 ), 3 );
    //mutex_try_lock test 3
    //mutex_lock test 4
    bgrt_proc_run( &proc[2] );
    bgrt_wait_time( 2 );
    test_output( ((BGRT_PROC_STATE_SYNC_SLEEP) == (proc[2].flags & (BGRT_PROC_STATE_MASK) ) ), 4 );
    //mutex_lock test 7
    test_output( !BGRT_PROC_RUN_TEST( (&proc[2]) ), 5 );
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
    test_output( ( (&proc[2]) == BGRT_SYNC_GET_OWNER( &test_mutex )), 10 );
    //mutex_free test 11
    // proc[2] must free mutexaphore and self stop
    bgrt_proc_run( &proc[2] );
    bgrt_wait_time( 2 );
    test_output( ( ((bgrt_proc_t *)0) == BGRT_SYNC_GET_OWNER( &test_mutex )), 11 );
    // mutex_lock test 12
    // proc[2] must lock a test_mutex and self ctop
    bgrt_proc_run( &proc[2] );
    bgrt_wait_time( 2 );
    test_output( ( (&proc[2]) == BGRT_SYNC_GET_OWNER( &test_mutex )), 12 );
    //mutex_lock test 13
    test_output( (proc[2].flags & BGRT_PROC_STATE_MASK) != BGRT_PROC_STATE_SYNC_SLEEP, 13 );

    bgrt_proc_run( &proc[2] );

    tests_end();
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
void main_mutex( void * arg )
{
    while(1)
    {
        mutex_lock( &test_mutex );
        bgrt_proc_self_stop();
        mutex_free( &test_mutex );
        bgrt_proc_self_stop();
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

    bgrt_proc_init_isr( &proc[0], main_with_return,   SVH0, RSH0, 0, &bgrt_proc_stack[0][BGRT_PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    bgrt_proc_init_isr( &proc[1], main_lb,            SVH1, RSH1, 0, &bgrt_proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 BGRT_SCHED_ARG_END );
    bgrt_proc_init_isr( &proc[2], main_mutex,         SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 1,      2, 0 ARG_END );

    mutex_init_isr( &test_mutex, 3 );

    _bgrt_proc_run( &proc[0] );

    bgrt_start();
    return 0;
}
