#include <test_func.h>

proc_t proc[6];
stack_t proc_stack[6][PROC_STACK_SIZE];

sem_t test_sem;

void main_with_return( void * arg )
{
    proc_run( &proc[1] );

    test_start();

    //sem_try_lock test 1
    //test_output( (test_var_sig == 1), 1 );
    test_output( sem_try_lock( &test_sem ), 1 );
    //sem_try_lock test 2
    test_output( (test_sem.counter == 0), 2 );
    //sem_lock test 3
    proc_run( &proc[2] );
    wait_time( 2 );
    test_output( (test_sem.counter == 0), 3 );

    // proc[2] must wait on test_sem.
    //sem_lock test 4
    test_output( ((PROC_FLG_SEM|PROC_STATE_W_SEM) == (proc[2].flags & (PROC_FLG_SEM|PROC_STATE_MASK) ) ), 4 );
    //sem_lock test 5
    test_output( !PROC_RUN_TEST( (&proc[2]) ), 5 );
    //sem_lock test 6
    test_output( (proc[2].parent.group->link == (void *)&test_sem.wait), 6 );
    //sem_try_lock test 7
    // must not lock
    test_output( !sem_try_lock( &test_sem ), 7 );
    //sem_try_lock test 8
    test_output( (test_sem.counter == 0), 8 );
    //sem_free test 9
    // proc[2] must get semaphore and self stop
    sem_free( &test_sem );
    wait_time( 2 );
    test_output( (test_sem.counter == 0), 9 );
    //sem_free test 10
    // proc[2] must free semaphore and self stop
    proc_run( &proc[2] );
    wait_time( 2 );
    test_output( (test_sem.counter == 1), 10 );
    // sem_lock test 11
    // proc[2] must lock a test_sem and self ctop
    proc_run( &proc[2] );
    wait_time( 2 );
    test_output( (test_sem.counter == 0), 10 );
    //sem_lock test 11
    test_output( (PROC_FLG_SEM == ( proc[2].flags & PROC_FLG_SEM ) ), 11 );
    //sem_lock test 12
    test_output( (proc[2].flags & PROC_STATE_MASK) != PROC_STATE_W_SEM, 12 );

    proc_run( &proc[2] );

    tests_end();
}
void main_lb( void * arg )
{
    while(1)
    {
        wait_time(10);
        // Run local load balancer on multicore system with local load balancing.
        SCHED_LOCAL_LOAD_BALANCER();
    }
}
void main_sem( void * arg )
{
    while(1)
    {
        sem_lock( &test_sem );
        proc_self_stop();
        sem_free( &test_sem );
        proc_flag_stop( PROC_FLG_SEM );
        proc_self_stop();
    }
}
void idle_main( void * arg )
{
    while(1)
    {
        wait_time(10);
        // Run local/global load balancer on multicore system with local/global lazy load balancing.
        SCHED_IDLE_LOAD_BALANCER();
    }
}

int main(void)
{
    /**************************************************
    *          For test purposes only!!!              *
    *  It is strongly recomended to initiate hardware *
    *         AFTER init_bugurt() call!!!             *
    **************************************************/
    /*
     * This function disables interrupts
     * and initiates hardware.
     */
    init_hardware();
    init_bugurt();

    SCHED_SYSTICK_HOOK_ADD();

    proc_init_isr( &proc[0], main_with_return,   SVH0, RSH0, 0, &proc_stack[0][PROC_STACK_SIZE-1], 1,      1, 0 ARG_END );
    proc_init_isr( &proc[1], main_lb,            SVH1, RSH1, 0, &proc_stack[1][PROC_STACK_SIZE-1], LOWEST, 1, 0 SCHED_ARG_END );
    proc_init_isr( &proc[2], main_sem,           SVH2, RSH2, 0, &proc_stack[2][PROC_STACK_SIZE-1], 2,      2, 0 ARG_END );

    sem_init_isr( &test_sem, 1 );

    proc_run_isr( &proc[0] );

    start_bugurt();
    return 0;
}