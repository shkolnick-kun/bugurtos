#include <test_func.h>
#include <ipc.h>
bgrt_proc_t proc[6];
bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

bgrt_ipc_t test_ep;

typedef struct
{
    int send;
    int reply;
}
bgrt_ipc_msg_t;

bgrt_ipc_msg_t msg_2, msg_3;

void (*test_hook)(void);

void main_bgrt_proc_test(void * arg)
{
    BGRT_PID_T wait_for = BGRT_PID_NOTHING;
    bgrt_ipc_msg_t * in;

    (void)arg;

    BGRT_PROC_RUN(PID1);

    test_start();
    BGRT_SYNC_SET_OWNER(&test_ep, PID0);

    test_output(BGRT_ST_EEMPTY == bgrt_ipc_wait(&test_ep, &wait_for, 0), 1);
    //priority inheritance tests
    BGRT_PROC_RUN(PID3);
    test_output(proc[0].parent.prio == 1, 2);
    BGRT_PROC_RUN(PID2);
    test_output(proc[0].parent.prio == 0, 3);
    // bgrt_ipc_send tests
    test_output(BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((&proc[2])), 4);
    test_output(BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((&proc[3])), 5);
    // bgrt_ipc_send  bgrt_ipc_wait test 6
    wait_for = PID3;
    test_output(BGRT_ST_OK == bgrt_ipc_wait(&test_ep, &wait_for, 1), 6);
    // bgrt_ipc_send  bgrt_ipc_wait test 7
    test_output(0 == proc[0].parent.prio, 7);
    // bgrt_ipc_send  bgrt_ipc_wait test 8
    in = (bgrt_ipc_msg_t *)test_ep.msg;
    test_output(3 == in->send, 8);
    // bgrt_ipc_send  bgrt_ipc_reply test 9
    in->reply = 9;
    test_output(BGRT_ST_OK == bgrt_ipc_reply(&test_ep, wait_for), 9);
    // bgrt_ipc_send bgrt_ipc_wait test 10
    wait_for = BGRT_PID_NOTHING;
    test_output(BGRT_ST_OK == bgrt_ipc_wait(&test_ep, &wait_for, 1), 10);
    // bgrt_ipc_send bgrt_ipc_wait test 11
    in = (bgrt_ipc_msg_t *)test_ep.msg;
    test_output(2 == in->send, 11);
    // bgrt_ipc_send  bgrt_ipc_reply test 11
    in->reply = 11;
    test_output(BGRT_ST_OK == bgrt_ipc_reply(&test_ep, wait_for), 12);
    bgrt_wait_time(20);

    tests_end();
}

void main_2(void * arg)
{
    (void)arg;
    while (1)
    {
        msg_2.send = 2;
        msg_2.reply = 0;
        bgrt_ipc_send(&test_ep, (void *)&msg_2);
        test_output(11 == msg_2.reply , 13);
        bgrt_wait_time(1);
    }
}

void main_3(void * arg)
{
    (void)arg;
    while (1)
    {
        msg_3.send = 3;
        msg_3.reply = 0;
        bgrt_ipc_send(&test_ep, (void *)&msg_3);
        test_output(9 == msg_3.reply , 14);
        bgrt_wait_time(1);
    }
}

void main_lb(void * arg)
{
    (void)arg;
    while (1)
    {
        bgrt_wait_time(10);
        // Run local load balancer on multicore system with local load balancing.
        BGRT_SCHED_LOCAL_LOAD_BALANCER();
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

    bgrt_priv_proc_init(PR0, main_bgrt_proc_test, SVH0, RSH0, 0, &bgrt_proc_stack[0][BGRT_PROC_STACK_SIZE-1], 4,      1, 0 ARG_END);
    bgrt_priv_proc_init(PR1, main_lb,        SVH1, RSH1, 0, &bgrt_proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 BGRT_SCHED_ARG_END);
    bgrt_priv_proc_init(PR2, main_2,         SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 0,      2, 0 ARG_END);
    bgrt_priv_proc_init(PR3, main_3,         SVH3, RSH3, 0, &bgrt_proc_stack[3][BGRT_PROC_STACK_SIZE-1], 1,      2, 0 ARG_END);

    bgrt_ipc_init_cs(&test_ep);

    bgrt_priv_proc_run(PR0);

    bgrt_start();
    return 0;
}
