#include <test_func.h>

proc_t proc[6];
stack_t proc_stack[6][PROC_STACK_SIZE];

ipc_data_t test;

void (*test_hook)(void);

void main_proc_test( void * arg )
{
    proc_run( &proc[1] );

    test_start();

    // ipc_send test 1
    test = 1;
    test_output( !ipc_send( &proc[2], 0 ), 1 );
    // ipc_send test 2
    test_output( test, 2 );

    // ipc_wait test 3
    proc_run( &proc[2] );
    wait_time( 10 );
    test_output( (proc[2].flags & PROC_FLG_IPCW), 3 );

    // ipc_send test 4
    test = 0;
    test_output( ipc_send( &proc[2], 1 ), 4 );
    // ipc_send test 5
    wait_time( 10 );
    test_output( test, 5 );

    // ipc_send test 6
    proc[2].flags |= PROC_FLG_PRE_STOP;
    test = 1;
    test_output( !ipc_send( &proc[2], 0 ), 6 );
    wait_time( 10 );
    // ipc_send test 7
    test_output( test, 7 );

    // ipc_exchange test 8
    test = 1;
    test_output( !ipc_exchange( &proc[3], 0, &test ), 8 );
    // ipc_exchange test 9
    test_output( test, 9 );

    // ipc_exchange test 10
    proc_run( &proc[3] );
    wait_time( 10 );
    test = 0;
    test_output( ipc_exchange( &proc[3], 1, &test ), 10 );
    // ipc_exchange test 11
    wait_time( 10 );
    test_output( test, 11 );

    // ipc_exchange test 12
    proc[3].flags |= PROC_FLG_PRE_STOP;
    test = 1;
    test_output( !ipc_exchange( &proc[3], 0, &test ), 12 );
    // ipc_exchange test 13
    test_output( test, 13 );

    tests_end();
}

void main_ipc_wait( void * arg )
{
    while(1)
    {
        test = ipc_wait();
        wait_time(1);
    }
}

void main_ipc_xch( void * arg )
{
    while(1)
    {
        ipc_send( &proc[0], ipc_wait() );
        wait_time(1);
    }
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

    proc_init_isr( &proc[0], main_proc_test, SVH0, RSH0, 0, &proc_stack[0][PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    proc_init_isr( &proc[1], main_lb,        SVH1, RSH1, 0, &proc_stack[1][PROC_STACK_SIZE-1], LOWEST, 1, 0 SCHED_ARG_END );
    proc_init_isr( &proc[2], main_ipc_wait,  SVH2, RSH2, 0, &proc_stack[2][PROC_STACK_SIZE-1], 0,      2, 0 ARG_END );
    proc_init_isr( &proc[3], main_ipc_xch,   SVH3, RSH3, 0, &proc_stack[3][PROC_STACK_SIZE-1], 1,      2, 0 ARG_END );

    proc_run_isr( &proc[0] );

    start_bugurt();
    return 0;
}
