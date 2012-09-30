#include <test_func.h>

proc_t proc[6];
stack_t proc_stack[6][PROC_STACK_SIZE];

mutex_t test_mutex;
bool_t test_var_mutex;

void main_with_return( void * arg )
{
    proc_run( &proc[1] );

    test_start();

    //mutex_try_lock test 1
    //test_output( (test_var_sig == 1), 1 );
    test_var_mutex = mutex_try_lock( &test_mutex );
    test_output( test_var_mutex, 1 );
    //mutex_try_lock test 2
    test_output( (test_mutex.free == 0), 2 );
    //mutex_try_lock test 3
    test_output( (proc[0].parent.prio == 1), 3 );
    //mutex_lock test 4
    proc_run( &proc[2] );
    wait_time( 2 );
    test_output( (test_mutex.free == 0), 4 );

    // proc[2] must wait on test_mutex.
    //mutex_lock test 5
    test_output( ((PROC_FLG_MUTEX|PROC_FLG_QUEUE) == (proc[2].flags & (PROC_FLG_MUTEX|PROC_FLG_QUEUE) ) ), 5 );
    //mutex_lock test 6
    test_output( !(proc[2].flags & PROC_FLG_RUN), 6 );
    //mutex_lock test 7
    test_output( (proc[2].parent.list == &test_mutex.mutex_list), 7 );

    if( test_var_mutex )
    {
        //mutex_try_lock test 8
        // must not lock
        test_output( !mutex_try_lock( &test_mutex ), 8 );
        //mutex_try_lock test 9
        test_output( (test_mutex.free == 0), 9 );
        //mutex_unlock test 10
        // proc[2] must get mutex and self stop
        mutex_unlock( &test_mutex );
        test_output( (proc[0].parent.prio == 1), 10 );
        //mutex_unlock test 11
        wait_time( 2 );
        test_output( (test_mutex.free == 0), 11 );
        //mutex_lock test 12
        test_output( (proc[2].parent.prio == 1), 12 );
        //mutex_unlock test 13
        // proc[2] must unlock mutex and self stop
        proc_run( &proc[2] );
        wait_time( 2 );
        test_output( (test_mutex.free == 1), 13 );
        //mutex_lock test 14
        test_output( (proc[2].parent.prio == 2), 14 );
    }
    // mutex_lock test 15
    // proc[2] must lock a test_mutex and self ctop
    proc_run( &proc[2] );
    wait_time( 2 );
    test_output( (test_mutex.free == 0), 15 );
    // mutex_lock test 16
    test_output( (proc[2].parent.prio == 1), 16 );
    //mutex_lock test 17
    test_output( (PROC_FLG_MUTEX == ( proc[2].flags & PROC_FLG_MUTEX ) ), 17 );
    //mutex_lock test 18
    test_output( !(proc[2].flags & PROC_FLG_QUEUE), 18 );

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
void main_mutex( void * arg )
{
    while(1)
    {
        mutex_lock( &test_mutex );
        proc_self_stop();
        mutex_unlock( &test_mutex );
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
    proc_init_isr( &proc[2], main_mutex,         SVH2, RSH2, 0, &proc_stack[2][PROC_STACK_SIZE-1], 2,      2, 0 ARG_END );

    mutex_init_isr( &test_mutex, 1 );

    proc_run_isr( &proc[0] );

    start_bugurt();
    return 0;
}
