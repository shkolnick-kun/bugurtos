#include <test_func.h>
#include <sem.h>

bgrt_proc_t proc[6];
bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

sem_t test_sem;

void main_with_return( void * arg )
{
    bgrt_proc_run( &proc[1] );

    test_start();

    //sem_try_lock test 1
    test_output( (BGRT_ST_OK == sem_try_lock( &test_sem )), 1 );
    //sem_try_lock test 2
    test_output( (0 == test_sem.counter), 2 );
    //sem_lock test 3
    bgrt_proc_run( &proc[2] );
    bgrt_wait_time( 2 );
    test_output( (0 == test_sem.counter), 3 );

    // proc[2] must wait on test_sem.
    //sem_lock test 4
    test_output( ((BGRT_PROC_STATE_SYNC_SLEEP) == (proc[2].flags & (BGRT_PROC_STATE_MASK) ) ), 4 );
    //sem_lock test 5
    test_output( !BGRT_PROC_RUN_TEST( (&proc[2]) ), 5 );
    //sem_lock test 6
    test_output( ( ((void *)&test_sem.wait) == proc[2].parent.list ), 6 );
    //sem_try_lock test 7
    // must not lock
    test_output( (BGRT_ST_ROLL == sem_try_lock( &test_sem )), 7 );
    //sem_try_lock test 8
    test_output( ( 0 == test_sem.counter ), 8 );
    //sem_free test 9
    // proc[2] must get semaphore and self stop
    sem_free( &test_sem );
    bgrt_wait_time( 2 );
    test_output( ( 0 == test_sem.counter ), 9 );
    //sem_free test 10
    // proc[2] must free semaphore and self stop
    bgrt_proc_run( &proc[2] );
    bgrt_wait_time( 2 );
    test_output( ( 1 == test_sem.counter ), 10 );
    // sem_lock test 11
    // proc[2] must lock a test_sem and self ctop
    bgrt_proc_run( &proc[2] );
    bgrt_wait_time( 2 );
    test_output( ( 0 == test_sem.counter ), 11 );
    //sem_lock test 11
    test_output( (BGRT_PROC_STATE_SYNC_SLEEP) != (proc[2].flags & BGRT_PROC_STATE_MASK) , 12 );

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
void main_sem( void * arg )
{
    while(1)
    {
        sem_lock( &test_sem );
        bgrt_proc_self_stop();
        sem_free( &test_sem );
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

    bgrt_proc_init_isr( &proc[0], main_with_return,   SVH0, RSH0, 0, &bgrt_proc_stack[0][BGRT_PROC_STACK_SIZE-1], 1,      1, 0 ARG_END );
    bgrt_proc_init_isr( &proc[1], main_lb,            SVH1, RSH1, 0, &bgrt_proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 BGRT_SCHED_ARG_END );
    bgrt_proc_init_isr( &proc[2], main_sem,           SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 2,      2, 0 ARG_END );

    sem_init_isr( &test_sem, 1 );

    _bgrt_proc_run( &proc[0] );

    bgrt_start();
    return 0;
}
