#include <test_func.h>
#include <ipc.h>
proc_t proc[6];
stack_t proc_stack[6][PROC_STACK_SIZE];

ipc_t test_ep;

typedef struct
{
    int send;
    int reply;
}
ipc_msg_t;

ipc_msg_t msg_2, msg_3;

void (*test_hook)(void);

void main_proc_test( void * arg )
{
    proc_t * wait_for = 0;
    ipc_msg_t * in;

    proc_run( &proc[1] );

    test_start();
    SYNC_SET_OWNER( &test_ep, 0 );

    test_output( SYNC_ST_EEMPTY == ipc_wait( &test_ep, &wait_for, 0), 1 );
    //priority inheritance tests
    proc_run( &proc[3] );
    test_output( proc[0].parent.prio == 1, 2 );
    proc_run( &proc[2] );
    test_output( proc[0].parent.prio == 0, 3 );
    // ipc_send tests
    test_output( PROC_STATE_SYNC_SLEEP == PROC_GET_STATE( (&proc[2]) ), 4 );
    test_output( PROC_STATE_SYNC_SLEEP == PROC_GET_STATE( (&proc[3]) ), 5 );
    // ipc_send  ipc_wait test 6
    wait_for = &proc[3];
    test_output( SYNC_ST_OK == ipc_wait( &test_ep, &wait_for, 1), 6 );
    // ipc_send  ipc_wait test 7
    test_output( proc[0].parent.prio == 0, 7 );
    // ipc_send  ipc_wait test 8
    in = (ipc_msg_t *)test_ep.msg;
    test_output( 3 == in->send, 8 );
    // ipc_send  ipc_reply test 9
    in->reply = 9;
    test_output( SYNC_ST_OK == ipc_reply( &test_ep, wait_for ), 9 );
    // ipc_send ipc_wait test 10
    wait_for = (proc_t *)0;
    test_output( SYNC_ST_OK == ipc_wait( &test_ep, &wait_for, 1), 10 );
    // ipc_send ipc_wait test 11
    in = (ipc_msg_t *)test_ep.msg;
    test_output( 2 == in->send, 11 );
    // ipc_send  ipc_reply test 11
    in->reply = 11;
    test_output( SYNC_ST_OK == ipc_reply( &test_ep, wait_for ), 12 );
    wait_time(20);

    tests_end();
}

void main_2( void * arg )
{
    while(1)
    {
        msg_2.send = 2;
        msg_2.reply = 0;
        ipc_send( &test_ep, (void *)&msg_2 );
        test_output( 11 == msg_2.reply , 13 );
        wait_time(1);
    }
}

void main_3( void * arg )
{
    while(1)
    {
        msg_3.send = 3;
        msg_3.reply = 0;
        ipc_send( &test_ep, (void *)&msg_3 );
        test_output( 9 == msg_3.reply , 14 );
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

    SCHED_SYSTICK_HOOK_ADD();

    proc_init_isr( &proc[0], main_proc_test, SVH0, RSH0, 0, &proc_stack[0][PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    proc_init_isr( &proc[1], main_lb,        SVH1, RSH1, 0, &proc_stack[1][PROC_STACK_SIZE-1], LOWEST, 1, 0 SCHED_ARG_END );
    proc_init_isr( &proc[2], main_2,         SVH2, RSH2, 0, &proc_stack[2][PROC_STACK_SIZE-1], 0,      2, 0 ARG_END );
    proc_init_isr( &proc[3], main_3,         SVH3, RSH3, 0, &proc_stack[3][PROC_STACK_SIZE-1], 1,      2, 0 ARG_END );

    ipc_init_isr( &test_ep );

    proc_run_isr( &proc[0] );

    start_bugurt();
    return 0;
}
