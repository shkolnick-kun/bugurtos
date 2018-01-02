#include <test_func.h>

#include <bugurt.h>
#include "cond.h"
//Сигнал
typedef struct _sig_t sig_t;

struct _sig_t
{
    bgrt_cond_t wakeup;
    bgrt_mtx_t wait;
};

bgrt_st_t sig_init_cs(sig_t * sig);

bgrt_st_t sig_init(sig_t * sig)
{
    bgrt_st_t ret;
    BGRT_INT_LOCK();
    ret = sig_init_cs(sig);
    BGRT_INT_FREE();
    return ret;
}

bgrt_st_t sig_init_cs(sig_t * sig)
{
    if (!sig)
    {
        return BGRT_ST_ENULL;
    }
    bgrt_cond_init_cs((bgrt_cond_t *)sig);
    BGRT_KERNEL_PREEMPT();
    bgrt_mtx_init_cs(&sig->wait, BGRT_PRIO_LOWEST);
    return BGRT_ST_OK;
}

bgrt_st_t sig_wait(sig_t * sig)
{
    bgrt_st_t ret;
    if (!sig)
    {
        return BGRT_ST_ENULL;
    }
    ret = bgrt_mtx_lock(&sig->wait);
    if (BGRT_ST_OK != ret)
    {
        return ret;
    }
    ret = bgrt_cond_wait((bgrt_cond_t *)sig, &sig->wait);
    bgrt_mtx_free(&sig->wait);
    return ret;
}

bgrt_st_t sig_signal(sig_t * sig)
{
    bgrt_st_t ret;
    if (!sig)
    {
        return BGRT_ST_ENULL;
    }
    ret = bgrt_mtx_lock(&sig->wait);
    if (BGRT_ST_OK != ret)
    {
        return ret;
    }
    ret = bgrt_cond_signal((bgrt_cond_t *)sig);
    bgrt_mtx_free(&sig->wait);
    return ret;
}

bgrt_st_t sig_broadcast(sig_t * sig)
{
    bgrt_st_t ret;
    if (!sig)
    {
        return BGRT_ST_ENULL;
    }
    ret = bgrt_mtx_lock(&sig->wait);
    if (BGRT_ST_OK != ret)
    {
        return ret;
    }
    ret = bgrt_cond_broadcast((bgrt_cond_t *)sig);
    bgrt_mtx_free(&sig->wait);
    return ret;
}

bgrt_proc_t proc[6];
bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

sig_t test_sig;
void (*test_hook)(void);

void test_running(void)
{
    test_output((proc[2].flags & BGRT_PROC_STATE_MASK) == BGRT_PROC_STATE_RUNNING, 5);
    test_inc();
}

bgrt_flag_t status;

void main_bgrt_proc_test(void * arg)
{
    (void)arg;

    BGRT_PROC_RUN(PID1);

    test_start();

    // sig_signal test 1
    // No processes are waiting for signal, test must not
    test_var_sig = 1;
    test_hook = test_clear;
    sig_signal(&test_sig);
    test_output((1 == test_var_sig), 1);

    // sig_broadcast test 2
    // No process must start
    sig_broadcast(&test_sig);
    test_output(test_var_sig, 2);

    BGRT_PROC_RUN(PID2);
    BGRT_PROC_RUN(PID3);
    BGRT_PROC_RUN(PID4);
    BGRT_PROC_RUN(PID5);

    bgrt_wait_time(20);
    /* All processes of interest are waiting for signal now! */
    // sig_signal test 6
    test_var_sig = 0;
    test_hook = test_running;


    sig_signal(&test_sig);
    bgrt_wait_time(20);
    test_output((1 == test_var_sig), 6);

    bgrt_wait_time(20);

    // sig_broadcast test 7
    test_var_sig = 0;
    test_hook = test_inc;
    status = sig_broadcast(&test_sig);
    test_output(BGRT_ST_OK == status, 7);

    bgrt_wait_time(20);
    test_output((4 == test_var_sig), 8);

    tests_end();
}

void main_sig(void * arg)
{
    (void)arg;

    while (1)
    {
        bgrt_flag_t status;
        status = sig_wait(&test_sig);
        test_output(BGRT_ST_OK == status, 9);
        test_hook();
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
    bgrt_priv_proc_init(PR2, main_sig,       SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 0,      2, 0 ARG_END);
    bgrt_priv_proc_init(PR3, main_sig,       SVH3, RSH3, 0, &bgrt_proc_stack[3][BGRT_PROC_STACK_SIZE-1], 1,      2, 0 ARG_END);
    bgrt_priv_proc_init(PR4, main_sig,       SVH4, RSH4, 0, &bgrt_proc_stack[4][BGRT_PROC_STACK_SIZE-1], 2,      2, 0 ARG_END);
    bgrt_priv_proc_init(PR5, main_sig,       SVH5, RSH5, 0, &bgrt_proc_stack[5][BGRT_PROC_STACK_SIZE-1], 3,      2, 0 ARG_END);

    sig_init_cs(&test_sig);

    bgrt_priv_proc_run(PR0);

    bgrt_start();
    return 0;
}
