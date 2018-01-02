#include <test_func.h>
#include <mutex.h>

bgrt_proc_t proc[6];
bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

bgrt_mtx_t test_mutex;

void main_with_return(void * arg)
{
    BGRT_PID_T pid_buf;

    (void)arg;

    BGRT_PROC_RUN(PID1);

    test_start();

    //bgrt_mtx_try_lock test 1
    test_output((BGRT_ST_OK == bgrt_mtx_try_lock(&test_mutex)), 1);
    // bgrt_mtx_try_lock test 2
    BGRT_SYNC_GET_OWNER(&test_mutex, &pid_buf);
    test_output((PID0 == pid_buf), 2);
    // bgrt_mtx_try_lock test 3
    test_output((proc[0].parent.prio == 3), 3);
    //bgrt_mtx_try_lock test 3
    //bgrt_mtx_lock test 4
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(2);
    test_output(((BGRT_PROC_STATE_SYNC_SLEEP) == (proc[2].flags & (BGRT_PROC_STATE_MASK))), 4);
    //bgrt_mtx_lock test 7
    test_output(!BGRT_PROC_RUN_TEST((&proc[2])), 5);
    //bgrt_mtx_lock test 8
    test_output((proc[2].parent.list == (void *)&test_mutex.wait), 6);
    //bgrt_mtx_lock test 9
    test_output((proc[0].parent.prio == 1), 7);
    //bgrt_mtx_try_lock test 8
    // must not lock
    test_output((BGRT_ST_EOWN == bgrt_mtx_try_lock(&test_mutex)), 8);
    //bgrt_mtx_try_lock test 9
    bgrt_mtx_free(&test_mutex);
    bgrt_wait_time(2);
    test_output((proc[0].parent.prio == 4), 9);
    //bgrt_mtx_free test 10
    BGRT_SYNC_GET_OWNER(&test_mutex, &pid_buf);
    test_output((PID2 == pid_buf), 10);
    //bgrt_mtx_free test 11
    // proc[2] must free mutexaphore and self stop
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(2);
    BGRT_SYNC_GET_OWNER(&test_mutex, &pid_buf);
    test_output ((BGRT_PID_NOTHING == pid_buf), 11);
    // bgrt_mtx_lock test 12
    // proc[2] must lock a test_mutex and self ctop
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(2);
    BGRT_SYNC_GET_OWNER(&test_mutex, &pid_buf);
    test_output((PID2 == pid_buf), 12);
    //bgrt_mtx_lock test 13
    test_output((proc[2].flags & BGRT_PROC_STATE_MASK) != BGRT_PROC_STATE_SYNC_SLEEP, 13);

    BGRT_PROC_RUN(PID2);

    tests_end();
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
void main_mutex(void * arg)
{
    (void)arg;
    while (1)
    {
        bgrt_mtx_lock(&test_mutex);
        BGRT_PROC_SELF_STOP();
        bgrt_mtx_free(&test_mutex);
        BGRT_PROC_SELF_STOP();
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

    bgrt_priv_proc_init(PR0, main_with_return,   SVH0, RSH0, 0, &bgrt_proc_stack[0][BGRT_PROC_STACK_SIZE-1], 4,      1, 0 ARG_END);
    bgrt_priv_proc_init(PR1, main_lb,            SVH1, RSH1, 0, &bgrt_proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 BGRT_SCHED_ARG_END);
    bgrt_priv_proc_init(PR2, main_mutex,         SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 1,      2, 0 ARG_END);

    bgrt_mtx_init_cs(&test_mutex, 3);

    bgrt_priv_proc_run(PR0);

    bgrt_start();
    return 0;
}
