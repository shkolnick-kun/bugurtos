#include <test_func.h>
#include <sem.h>

bgrt_proc_t proc[6];
bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

bgrt_sem_t test_sem;

void main_with_return(void * arg)
{
    (void)arg;

    BGRT_PROC_RUN(PID1);

    test_start();

    //bgrt_sem_try_lock test 1
    test_output((BGRT_ST_OK == bgrt_sem_try_lock(&test_sem)), 1);
    //bgrt_sem_try_lock test 2
    test_output((0 == test_sem.counter), 2);
    //bgrt_sem_lock test 3
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(2);
    test_output((0 == test_sem.counter), 3);

    // proc[2] must wait on test_sem.
    //bgrt_sem_lock test 4
    test_output(((BGRT_PROC_STATE_SYNC_SLEEP) == (proc[2].flags & (BGRT_PROC_STATE_MASK))), 4);
    //bgrt_sem_lock test 5
    test_output(!BGRT_PROC_RUN_TEST((&proc[2])), 5);
    //bgrt_sem_lock test 6
    test_output((((void *)&test_sem.wait) == proc[2].parent.list), 6);
    //bgrt_sem_try_lock test 7
    // must not lock
    test_output((BGRT_ST_ROLL == bgrt_sem_try_lock(&test_sem)), 7);
    //bgrt_sem_try_lock test 8
    test_output((0 == test_sem.counter), 8);
    //bgrt_sem_free test 9
    // proc[2] must get semaphore and self stop
    bgrt_sem_free(&test_sem);
    bgrt_wait_time(2);
    test_output((0 == test_sem.counter), 9);
    //bgrt_sem_free test 10
    // proc[2] must free semaphore and self stop
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(2);
    test_output((1 == test_sem.counter), 10);
    // bgrt_sem_lock test 11
    // proc[2] must lock a test_sem and self ctop
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(2);
    test_output((0 == test_sem.counter), 11);
    //bgrt_sem_lock test 11
    test_output((BGRT_PROC_STATE_SYNC_SLEEP) != (proc[2].flags & BGRT_PROC_STATE_MASK) , 12);

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
void main_sem(void * arg)
{
    (void)arg;
    while (1)
    {
        bgrt_sem_lock(&test_sem);
        BGRT_PROC_SELF_STOP();
        bgrt_sem_free(&test_sem);
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

    bgrt_priv_proc_init(PR0, main_with_return,   SVH0, RSH0, 0, &bgrt_proc_stack[0][BGRT_PROC_STACK_SIZE-1], 1,      1, 0 ARG_END);
    bgrt_priv_proc_init(PR1, main_lb,            SVH1, RSH1, 0, &bgrt_proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 BGRT_SCHED_ARG_END);
    bgrt_priv_proc_init(PR2, main_sem,           SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 0,      2, 0 ARG_END);

    bgrt_sem_init_cs(&test_sem, 1);

    bgrt_priv_proc_run(PR0);

    bgrt_start();
    return 0;
}
