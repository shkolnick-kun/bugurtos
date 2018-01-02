#include <test_func.h>

bgrt_proc_t proc[6];
bgrt_stack_t bgrt_proc_stack[6][BGRT_PROC_STACK_SIZE];

bgrt_sync_t bgrt_sync_1, bgrt_sync_2, bgrt_sync_3, bgrt_sync_4;
bgrt_bool_t test;
bgrt_st_t status[7];
BGRT_PID_T bgrt_proc_buff = BGRT_PID_NOTHING;
unsigned char test_num = 1;

void prio_propagate_hook_0(void)
{
    if (BGRT_PROC_STATE_PI_PEND == BGRT_PROC_GET_STATE((PR1)))
    {
        test_kernel_preempt = test_do_nothing;
        BGRT_PROC_SET_STATE((PR1), BGRT_PROC_STATE_PI_DONE);
    }
}

void prio_propagate_hook_1(void)
{
    if (BGRT_PROC_STATE_PI_PEND == BGRT_PROC_GET_STATE((PR2)))
    {
        test_kernel_preempt = test_do_nothing;
        status[6] = bgrt_priv_sync_wake(&bgrt_sync_1, PR2, 1); //chown
    }
}

void prio_propagate_hook_2(void)
{
    if (BGRT_PROC_STATE_PI_PEND == BGRT_PROC_GET_STATE((PR2)))
    {
        test_kernel_preempt = test_do_nothing;
        status[6] = bgrt_priv_sync_wake(&bgrt_sync_1, PR2, 0);
    }
}

void sync_timeout_hook_1(void)
{
    if (BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)))
    {
        test_kernel_preempt = test_do_nothing;
        status[6] = bgrt_priv_sync_wake(&bgrt_sync_1, (bgrt_proc_t *)0, 0);
    }
}
void sync_timeout_hook_2(void)
{
    if (BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)))
    {
        test_kernel_preempt = test_do_nothing;
        status[4] = bgrt_priv_sync_wake(&bgrt_sync_1, (bgrt_proc_t *)0, 0);
        status[5] = bgrt_priv_sync_wake(&bgrt_sync_1, (bgrt_proc_t *)0, 0);
        status[6] = bgrt_priv_sync_wake(&bgrt_sync_1, (bgrt_proc_t *)0, 0);
    }
}
//BGRT_SYNC_SLEEP
static inline bgrt_st_t _test_sync_sleep(bgrt_sync_t * sync, bgrt_flag_t touch)
{
    bgrt_flag_t touch_state;
    touch_state = touch;
    return BGRT_SYNC_SLEEP(sync,&touch_state);
}

void main_0(void * arg)
{
    (void)arg;
    test_start();
    // 1 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    BGRT_PROC_SET_PRIO(PID1, 5);
    test = (5 == proc[1].base_prio);
    test_output(test, test_num++);
    // 2 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (5 == proc[1].parent.prio);
    test_output(test, test_num++);

    //3 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    BGRT_PROC_SET_PRIO(PID0, 6);
    test = (6 == proc[0].base_prio);
    test_output(test, test_num++);
    // 4 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (6 == proc[0].parent.prio);
    test_output(test, test_num++);

    // 5 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    status[1] = BGRT_ST_ESTAT;
    BGRT_PROC_SET_STATE((PR1), BGRT_PROC_STATE_SYNC_WAIT);
    BGRT_PROC_SET_PRIO(PID1, 4);
    bgrt_wait_time(5);
    test = (4 == proc[1].base_prio);
    test_output(test, test_num++);
    // 6 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (4 == proc[1].parent.prio);
    test_output(test, test_num++);
    // 7 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (BGRT_ST_OK == status[1]);
    test_output(test, test_num++);

    // 8 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    status[1] = BGRT_ST_ESTAT;
    BGRT_PROC_SET_STATE((PR1), BGRT_PROC_STATE_SYNC_SLEEP);
    BGRT_PROC_SET_PRIO(PID1, 5);
    bgrt_wait_time(5);
    test = (5 == proc[1].base_prio);
    test_output(test, test_num++);
    // 9 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (5 == proc[1].parent.prio);
    test_output(test, test_num++);
    // 10 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (BGRT_ST_OK == status[1]);
    test_output(test, test_num++);

    // 11 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    BGRT_PROC_SET_STATE((PR1), BGRT_PROC_STATE_SYNC_SLEEP);
    bgrt_pitem_insert((bgrt_pitem_t *)(PR1), (bgrt_xlist_t *)(&bgrt_sync_1));
    proc[1].sync = &bgrt_sync_1;
    BGRT_PROC_SET_PRIO(PID1, 4);
    bgrt_wait_time(5);
    test = (4 == proc[1].base_prio);
    test_output(test, test_num++);
    // 12 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (4 == proc[1].parent.prio);
    test_output(test, test_num++);
    // 13 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);

    // 14 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    status[1] = BGRT_ST_ESTAT;
    bgrt_sync_1.owner = PR2;
    BGRT_PROC_LRES_INC((PR2), BGRT_SYNC_PRIO(&bgrt_sync_1));
    BGRT_PROC_SET_PRIO(PID1, 5);
    bgrt_wait_time(5);
    test = (5 == proc[1].base_prio);
    test_output(test, test_num++);
    // 15 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (0 == proc[1].parent.prio);
    test_output(test, test_num++);
    // 16 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (BGRT_ST_OK == status[1]);
    test_output(test, test_num++);
    // 17 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (1 == bgrt_sync_1.dirty);
    test_output(test, test_num++);
    // 18 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (1 == proc[2].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);

    // 19 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    status[1] = BGRT_ST_ESTAT;

    BGRT_PROC_SET_STATE((PR1), BGRT_PROC_STATE_SYNC_SLEEP);
    proc[1].sync = &bgrt_sync_1;
    BGRT_PROC_LRES_DEC((PR1), 0);
    proc[1].parent.prio = proc[1].base_prio;

    bgrt_sync_1.dirty = (bgrt_cnt_t)0;
    BGRT_PROC_LRES_DEC((PR2), BGRT_SYNC_PRIO(&bgrt_sync_1));
    bgrt_pitem_insert((bgrt_pitem_t *)(PR1), (bgrt_xlist_t *)(&bgrt_sync_1));
    BGRT_PROC_LRES_INC((PR2), BGRT_SYNC_PRIO(&bgrt_sync_1));

    kernel_preemt_hook_add(prio_propagate_hook_0);

    BGRT_PROC_SET_PRIO(PID1, 4);
    bgrt_wait_time(5);
    test = (4 == proc[1].base_prio);
    test_output(test, test_num++);
    // 20 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (0 == proc[1].parent.prio);
    test_output(test, test_num++);
    // 21 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (BGRT_ST_OK == status[1]);
    test_output(test, test_num++);
    // 22 bgrt_priv_proc_prio_propagate BGRT_PROC_SET_PRIO
    test = (1 == proc[2].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    /// bgrt_priv_proc_prio_propagate covered!!!
    //cleanup
    BGRT_PROC_LRES_DEC((PR2), BGRT_SYNC_PRIO(&bgrt_sync_1));
    bgrt_sync_1.owner = (bgrt_proc_t *)0;
    BGRT_PROC_LRES_DEC((PR1), 0);
    // 23 BGRT_SYNC_SET_OWNER
    status[0] = BGRT_SYNC_SET_OWNER((bgrt_sync_t *)0, BGRT_PID_NOTHING);
    test = (BGRT_ST_ENULL == status[0]);
    test_output(test, test_num++);

    // 24 BGRT_SYNC_SET_OWNER
    status[0] = BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID1);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    // 25 BGRT_SYNC_SET_OWNER
    test = ((PR1) == bgrt_sync_1.owner);
    test_output(test, test_num++);
    // 26 BGRT_SYNC_SET_OWNER
    test = (1 == proc[1].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);

    // 27 BGRT_SYNC_SET_OWNER
    status[0] = BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID1);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    // 28 BGRT_SYNC_SET_OWNER
    test = ((PR1) == bgrt_sync_1.owner);
    test_output(test, test_num++);
    // 29 BGRT_SYNC_SET_OWNER
    test = (1 == proc[1].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);

    // 30 BGRT_SYNC_SET_OWNER
    status[0] = BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID2);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    // 31 BGRT_SYNC_SET_OWNER
    test = ((PR2) == bgrt_sync_1.owner);
    test_output(test, test_num++);
    // 32 BGRT_SYNC_SET_OWNER
    test = (1 == proc[2].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    // 33 BGRT_SYNC_SET_OWNER
    test = (0 == proc[1].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);

    // 34 BGRT_SYNC_SET_OWNER
    status[0] = BGRT_SYNC_SET_OWNER(&bgrt_sync_1, BGRT_PID_NOTHING);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    // 35 BGRT_SYNC_SET_OWNER
    test = (((bgrt_proc_t *)0) == bgrt_sync_1.owner);
    test_output(test, test_num++);
    // 36 BGRT_SYNC_SET_OWNER
    test = (0 == proc[2].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    /// BGRT_SYNC_SET_OWNER covered !!!
    // 37 BGRT_SYNC_OWN
    status[0] = BGRT_SYNC_OWN((bgrt_sync_t *)0, (bgrt_flag_t)0);
    test = (BGRT_ST_ENULL == status[0]);
    test_output(test, test_num++);

    // 38 BGRT_SYNC_OWN
    status[0] = BGRT_SYNC_OWN(&bgrt_sync_1, (bgrt_flag_t)0);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    // 39 BGRT_SYNC_OWN
    test = ((PR0) == bgrt_sync_1.owner);
    test_output(test, test_num++);
    // 40 BGRT_SYNC_OWN
    test = (1 == proc[0].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    // 41 BGRT_SYNC_OWN
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR0));
    test = (BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)));
    //BGRT_SPIN_FREE((PR0));
    BGRT_INT_FREE();
    test_output(test, test_num++);

    // 42 BGRT_SYNC_OWN
    status[0] = BGRT_SYNC_OWN(&bgrt_sync_1, (bgrt_flag_t)0);
    test = (BGRT_ST_EOWN == status[0]);
    test_output(test, test_num++);
    // 43 BGRT_SYNC_OWN
    test = ((PR0) == bgrt_sync_1.owner);
    test_output(test, test_num++);
    // 44 BGRT_SYNC_OWN
    test = (1 == proc[0].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    // 45 BGRT_SYNC_OWN
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR0));
    test = (BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)));
    //BGRT_SPIN_FREE((PR0));
    BGRT_INT_FREE();
    test_output(test, test_num++);

    // 46 BGRT_SYNC_OWN
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, BGRT_PID_NOTHING);
    status[0] = BGRT_SYNC_OWN(&bgrt_sync_1, (bgrt_flag_t)1);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    // 47 BGRT_SYNC_OWN
    test = ((PR0) == bgrt_sync_1.owner);
    test_output(test, test_num++);
    // 48 BGRT_SYNC_OWN
    test = (1 == proc[0].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    // 49 BGRT_SYNC_OWN
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR0));
    test = (BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)));
    //BGRT_SPIN_FREE((PR0));
    BGRT_INT_FREE();
    test_output(test, test_num++);

    // 50 BGRT_SYNC_OWN
    status[0] = BGRT_SYNC_OWN(&bgrt_sync_1, (bgrt_flag_t)1);
    test = (BGRT_ST_EOWN == status[0]);
    test = test && (0 == bgrt_sync_1.dirty);
    test_output(test, test_num++);
    // 51 BGRT_SYNC_OWN
    test = ((PR0) == bgrt_sync_1.owner);
    test_output(test, test_num++);
    // 52 BGRT_SYNC_OWN
    test = (1 == proc[0].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    // 53 BGRT_SYNC_OWN
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR0));
    test = (BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)));
    //BGRT_SPIN_FREE((PR0));
    BGRT_INT_FREE();
    test_output(test, test_num++);

    // 54 BGRT_SYNC_OWN
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID1);
    status[0] = BGRT_SYNC_OWN(&bgrt_sync_1, (bgrt_flag_t)0);
    test = (BGRT_ST_EOWN == status[0]);
    test_output(test, test_num++);
    // 55 BGRT_SYNC_OWN
    test = ((PR1) == bgrt_sync_1.owner);
    test_output(test, test_num++);
    // 56 BGRT_SYNC_OWN
    test = (1 == proc[1].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    // 57 BGRT_SYNC_OWN
    test = (0 == proc[0].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    // 58 BGRT_SYNC_OWN
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR0));
    test = (BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)));
    //BGRT_SPIN_FREE((PR0));
    BGRT_INT_FREE();
    test_output(test, test_num++);

    // 59 BGRT_SYNC_OWN
    status[0] = BGRT_SYNC_OWN(&bgrt_sync_1, (bgrt_flag_t)1);
    test = (BGRT_ST_EOWN == status[0]);
    test_output(test, test_num++);
    // 60 BGRT_SYNC_OWN
    test = ((PR1) == bgrt_sync_1.owner);
    test_output(test, test_num++);
    // 61 BGRT_SYNC_OWN
    test = (1 == proc[1].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    // 62 BGRT_SYNC_OWN
    test = (0 == proc[0].lres.counter[BGRT_PRIO_LOWEST]);
    test_output(test, test_num++);
    // 63 BGRT_SYNC_OWN
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR0));
    test = (BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)));
    if (test)
    {
        BGRT_PROC_SET_STATE((PR0), BGRT_PROC_STATE_RUNNING);
        BGRT_PROC_LRES_DEC(PR0, 0);
        proc[0].sync = (bgrt_sync_t *)0;
    }
    //BGRT_SPIN_FREE((PR0));
    BGRT_INT_FREE();
    test_output(test, test_num++);
    /// BGRT_SYNC_OWN covered!!!
    //cleanup
    BGRT_PROC_SET_PRIO(PID0, 6);
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, BGRT_PID_NOTHING);
    bgrt_sync_1.dirty = 0;
    bgrt_sync_1.snum  = 0;

    //64 BGRT_SYNC_TOUCH
    status[0] = BGRT_SYNC_TOUCH((bgrt_sync_t *)0);
    test = (BGRT_ST_ENULL == status[0]);
    test_output(test, test_num++);
    //65 BGRT_SYNC_TOUCH
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR0));
    test = (BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)));
    //BGRT_SPIN_FREE((PR0));
    BGRT_INT_FREE();
    test_output(test, test_num++);

    //66 BGRT_SYNC_TOUCH
    status[0] = BGRT_SYNC_TOUCH(&bgrt_sync_1);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    //67 BGRT_SYNC_TOUCH
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR0));
    test = (BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)));
    if (test)
    {
        BGRT_PROC_SET_STATE((PR0), BGRT_PROC_STATE_RUNNING);
        BGRT_PROC_LRES_DEC(PR0, 0);
        proc[0].sync = (bgrt_sync_t *)0;
    }
    //BGRT_SPIN_FREE((PR0));
    BGRT_INT_FREE();
    test_output(test, test_num++);
    /// BGRT_SYNC_TOUCH covered!!!
    //cleanup
    BGRT_PROC_SET_PRIO(PID0, LOWEST);
    bgrt_sync_1.dirty = 0;
    bgrt_sync_1.snum  = 0;
    //68 BGRT_SYNC_SLEEP
    test = (BGRT_ST_ENULL == _test_sync_sleep((bgrt_sync_t *)0, (bgrt_flag_t)0));
    test_output(test, test_num++);
    //69 BGRT_SYNC_SLEEP
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    test = (BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //70 BGRT_SYNC_SLEEP BGRT_SYNC_WAKE
    test = (BGRT_ST_OK == BGRT_SYNC_WAKE(&bgrt_sync_1, 0, 0));
    test_output(test, test_num++);
    //71 BGRT_SYNC_SLEEP
    bgrt_wait_time(5);
    test = (BGRT_ST_OK == status[2]);
    test_output(test, test_num++);

    //72 BGRT_SYNC_SLEEP
    BGRT_PROC_SET_PRIO(PID1, LOWEST);
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID1);
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    test = (BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //73 BGRT_SYNC_SLEEP
    test = (4 == proc[1].parent.prio);
    test_output(test, test_num++);

    //74 BGRT_SYNC_SLEEP
    BGRT_PROC_SET_PRIO(PID2, 5);
    bgrt_wait_time(5);
    test = (BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //75 BGRT_SYNC_SLEEP
    test = (5 == proc[1].parent.prio);
    test_output(test, test_num++);

    //76 BGRT_SYNC_SLEEP BGRT_SYNC_PROC_TIMEOUT
    status[0] = BGRT_SYNC_PROC_TIMEOUT(PID2);
    bgrt_wait_time(5);
    test = (BGRT_ST_OK == status[0]);
    test = test && (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //77 BGRT_SYNC_SLEEP BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_ETIMEOUT == status[2]);
    test_output(test, test_num++);
    //78 BGRT_SYNC_SLEEP BGRT_SYNC_PROC_TIMEOUT
    test = (LOWEST == proc[1].parent.prio);
    test_output(test, test_num++);

    //79 BGRT_SYNC_SLEEP BGRT_SYNC_WAIT
    BGRT_PROC_SET_PRIO(PID2, LOWEST);
    BGRT_PROC_RUN(PID1);
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    test = (BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //80 BGRT_SYNC_SLEEP BGRT_SYNC_WAIT
    test = (BGRT_ST_OK == status[1]);
    test_output(test, test_num++);
    //81 BGRT_SYNC_SLEEP BGRT_SYNC_WAIT
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);

    //82 BGRT_SYNC_SLEEP BGRT_SYNC_WAKE
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, BGRT_PID_NOTHING);
    status[0] = BGRT_SYNC_WAKE(&bgrt_sync_1, 0, 0);
    bgrt_wait_time(10);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    //83 BGRT_SYNC_SLEEP BGRT_SYNC_WAKE
    test = (BGRT_ST_OK == status[1]);
    test_output(test, test_num++);
    //84 BGRT_SYNC_SLEEP BGRT_SYNC_WAKE
    test = (BGRT_ST_EEMPTY == status[3]);
    test_output(test, test_num++);
    //85 BGRT_SYNC_SLEEP
    test = (BGRT_ST_OK == status[2]);
    test_output(test, test_num++);
    //86 BGRT_SYNC_SLEEP
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //cleanup
    BGRT_PROC_SET_PRIO(PID2, 4);
    //87 BGRT_SYNC_SLEEP
    BGRT_SYNC_OWN(&bgrt_sync_1, (bgrt_flag_t)0);
    test = (BGRT_ST_EOWN == _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0));
    test_output(test, test_num++);
    /// BGRT_SYNC_SLEEP is almost covered!!!

    //88 BGRT_SYNC_WAIT
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID1);
    test = (BGRT_ST_EOWN == BGRT_SYNC_WAIT(&bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 0));
    test_output(test, test_num++);
    //89 BGRT_SYNC_WAIT
    test = (BGRT_ST_ENULL == BGRT_SYNC_WAIT((bgrt_sync_t *)0, (BGRT_PID_T *)&bgrt_proc_buff, 0));
    test_output(test, test_num++);
    //90 BGRT_SYNC_WAIT
    test = (BGRT_ST_ENULL == BGRT_SYNC_WAIT(&bgrt_sync_1, (BGRT_PID_T *)0, 0));
    test_output(test, test_num++);

    //91 BGRT_SYNC_WAIT BGRT_SYNC_WAKE
    //BGRT_SYNC_TOUCH(&bgrt_sync_1);
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    test = (BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);
    //92 BGRT_SYNC_WAIT BGRT_SYNC_WAKE
    bgrt_wait_time(20);
    test = (BGRT_ST_OK == status[1]);
    test_output(test, test_num++);
    //93 BGRT_SYNC_WAIT BGRT_SYNC_WAKE
    test = (BGRT_ST_OK == status[2]);
    test_output(test, test_num++);
    //94 BGRT_SYNC_WAIT BGRT_SYNC_WAKE
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);
    //95 BGRT_SYNC_WAIT BGRT_SYNC_WAKE
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);

    //96 BGRT_SYNC_WAIT
    BGRT_PROC_RUN(PID1);
    bgrt_wait_time(5);
    test = (BGRT_ST_EEMPTY == status[1]);
    test_output(test, test_num++);
    //97 BGRT_SYNC_WAIT
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);

    //97 BGRT_SYNC_WAIT
    BGRT_PROC_RUN(PID1);
    bgrt_wait_time(5);
    test = (BGRT_PROC_STATE_SYNC_WAIT == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);
    //98 BGRT_SYNC_WAIT BGRT_SYNC_PROC_TIMEOUT
    status[0] = BGRT_SYNC_PROC_TIMEOUT(PID1);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    //99 BGRT_SYNC_WAIT BGRT_SYNC_PROC_TIMEOUT
    bgrt_wait_time(5);
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);
    //100 BGRT_SYNC_WAIT BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_ETIMEOUT == status[1]);
    test_output(test, test_num++);
    /// BGRT_SYNC_WAIT covered!!!

    //101 BGRT_SYNC_WAKE
    test = (BGRT_ST_ENULL == BGRT_SYNC_WAKE((bgrt_sync_t *)0, BGRT_PID_NOTHING, 0));
    test_output(test, test_num++);

    //103 BGRT_SYNC_WAKE
    test = (BGRT_ST_EOWN == BGRT_SYNC_WAKE(&bgrt_sync_1, BGRT_PID_NOTHING, 0));
    test_output(test, test_num++);

    //104 BGRT_SYNC_WAKE
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID0);
    test = (BGRT_ST_EEMPTY == BGRT_SYNC_WAKE(&bgrt_sync_1, BGRT_PID_NOTHING, 0));
    test_output(test, test_num++);

    //105 BGRT_SYNC_WAKE
    test = (BGRT_ST_ESYNC == BGRT_SYNC_WAKE(&bgrt_sync_1, PID2, 0));
    test_output(test, test_num++);

    //106 BGRT_SYNC_WAKE
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID1);
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(10);
    test = (BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);
    //107 BGRT_SYNC_WAKE
    test = ((bgrt_sync_t *)0 == proc[1].sync);
    test_output(test, test_num++);

    BGRT_PROC_RUN(PID2);
    //108 BGRT_SYNC_WAKE
    bgrt_wait_time(20);
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);
    //109 BGRT_SYNC_WAKE
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //110 BGRT_SYNC_WAKE
    test = (BGRT_ST_OK == status[1]);
    test_output(test, test_num++);

    //111 BGRT_SYNC_WAKE
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID0);
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    status[6] = BGRT_ST_ESTAT;
    kernel_preemt_hook_add(prio_propagate_hook_1);
    BGRT_PROC_SET_PRIO(PID2, 4);
    bgrt_wait_time(5);
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //112 BGRT_SYNC_WAKE
    test = (BGRT_ST_OK == status[6]);
    test_output(test, test_num++);
    //113 BGRT_SYNC_WAKE
    test = (PR2 == bgrt_sync_1.owner);
    test_output(test, test_num++);

    //114 BGRT_SYNC_WAKE
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID0);
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    status[6] = BGRT_ST_ESTAT;
    kernel_preemt_hook_add(prio_propagate_hook_2);
    BGRT_PROC_SET_PRIO(PID2, 4);
    bgrt_wait_time(5);
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //115 BGRT_SYNC_WAKE
    test = (BGRT_ST_OK == status[6]);
    test_output(test, test_num++);
    //116 BGRT_SYNC_WAKE
    test = (PR0 == bgrt_sync_1.owner);
    test_output(test, test_num++);

    //117 BGRT_SYNC_WAKE
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    status[0] = BGRT_SYNC_WAKE(&bgrt_sync_1, BGRT_PID_NOTHING, 1);
    bgrt_wait_time(5);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    //118 BGRT_SYNC_WAKE
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //119 BGRT_SYNC_WAKE
    test = (PR2 == bgrt_sync_1.owner);
    test_output(test, test_num++);
    /// BGRT_SYNC_WAIT and bgrt_priv_sync_do_wake covered!!!

    //120 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_ENULL == BGRT_SYNC_PROC_TIMEOUT(BGRT_PID_NOTHING));
    test_output(test, test_num++);
    //121 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_ESYNC == BGRT_SYNC_PROC_TIMEOUT(PID0));
    test_output(test, test_num++);

    //122 BGRT_SYNC_PROC_TIMEOUT
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, BGRT_PID_NOTHING);
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    test = (BGRT_ST_OK == BGRT_SYNC_PROC_TIMEOUT(PID2));
    test_output(test, test_num++);
    //123 BGRT_SYNC_PROC_TIMEOUT
    bgrt_wait_time(5);
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);

    //124 BGRT_SYNC_PROC_TIMEOUT
    BGRT_INT_LOCK();
    BGRT_PROC_SET_STATE((PR2), BGRT_PROC_STATE_PI_PEND);
    PR2->sync = &bgrt_sync_1;
    BGRT_INT_FREE();

    status[0] = BGRT_SYNC_PROC_TIMEOUT(PID2);
    test = (BGRT_ST_EAGAIN == status[0]);
    test_output(test, test_num++);
    //cleanup
    BGRT_INT_LOCK();
    BGRT_PROC_SET_STATE((PR2), BGRT_PROC_STATE_STOPED);
    PR2->sync = 0;
    BGRT_INT_FREE();
    //125 BGRT_SYNC_PROC_TIMEOUT
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID1);
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    status[0] =  BGRT_SYNC_PROC_TIMEOUT(PID1);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    //126 BGRT_SYNC_PROC_TIMEOUT
    bgrt_wait_time(20);
    test = (BGRT_ST_OK == status[1]);
    test_output(test, test_num++);
    //127 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);
    //128 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    /// BGRT_SYNC_PROC_TIMEOUT tested but not covered!!!

    // 129 priority inheritance/ceiling
    BGRT_SYNC_SET_OWNER(&bgrt_sync_2, PID2);
    BGRT_SYNC_SET_OWNER(&bgrt_sync_3, PID3);
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(10);
    test = (4 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 130 priority inheritance/ceiling
    BGRT_PROC_RUN(PID3);
    bgrt_wait_time(10);
    test = (3 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 131 priority inheritance/ceiling
    test = (3 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 132 priority inheritance/ceiling
    BGRT_PROC_RUN(PID4);
    bgrt_wait_time(10);
    test = (2 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 133 priority inheritance/ceiling
    test = (2 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 134 priority inheritance/ceiling
    test = (2 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 135 priority inheritance/ceiling
    BGRT_PROC_RUN(PID5);
    bgrt_wait_time(5);

    test = (2 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 136 priority inheritance/ceiling
    test = (1 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 137 priority inheritance/ceiling
    test = (1 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 138 priority inheritance/ceiling
    BGRT_PROC_SET_PRIO(PID5, 0);
    bgrt_wait_time(5);
    test = (0 == proc[5].parent.prio);
    test_output(test, test_num++);
    // 139 priority inheritance/ceiling
    test = (2 == proc[4].parent.prio);
    test_output(test, test_num++);
    // 140 priority inheritance/ceiling
    test = (2 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 141 priority inheritance/ceiling
    test = (0 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 142 priority inheritance/ceiling
    test = (0 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 143 priority inheritance/ceiling
    BGRT_PROC_SET_PRIO(PID5, 1);
    bgrt_wait_time(5);
    test = (1 == proc[5].parent.prio);
    test_output(test, test_num++);
    // 144 priority inheritance/ceiling
    test = (2 == proc[4].parent.prio);
    test_output(test, test_num++);
    // 145 priority inheritance/ceiling
    test = (2 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 146 priority inheritance/ceiling
    test = (1 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 147 priority inheritance/ceiling
    test = (1 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 148 priority inheritance/ceiling
    BGRT_PROC_SET_PRIO(PID2, 0);
    bgrt_wait_time(5);
    test = (1 == proc[5].parent.prio);
    test_output(test, test_num++);
    // 149 priority inheritance/ceiling
    test = (2 == proc[4].parent.prio);
    test_output(test, test_num++);
    // 150 priority inheritance/ceiling
    test = (2 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 151 priority inheritance/ceiling
    test = (0 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 152 priority inheritance/ceiling
    test = (0 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 153 priority inheritance/ceiling
    BGRT_PROC_SET_PRIO(PID2, 1);
    bgrt_wait_time(5);
    test = (1 == proc[5].parent.prio);
    test_output(test, test_num++);
    // 154 priority inheritance/ceiling
    test = (2 == proc[4].parent.prio);
    test_output(test, test_num++);
    // 155 priority inheritance/ceiling
    test = (2 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 156 priority inheritance/ceiling
    test = (1 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 157 priority inheritance/ceiling
    test = (1 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 158 priority inheritance/ceiling
    BGRT_PROC_SET_PRIO(PID2, 4);
    bgrt_wait_time(5);
    test = (1 == proc[5].parent.prio);
    test_output(test, test_num++);
    // 159 priority inheritance/ceiling
    test = (2 == proc[4].parent.prio);
    test_output(test, test_num++);
    // 160 priority inheritance/ceiling
    test = (2 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 161 priority inheritance/ceiling
    test = (1 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 162 priority inheritance/ceiling
    test = (1 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 163 priority inheritance/ceiling
    BGRT_PROC_SET_PRIO(PID4, 4);
    bgrt_wait_time(5);
    test = (1 == proc[5].parent.prio);
    test_output(test, test_num++);
    // 164 priority inheritance/ceiling
    test = (4 == proc[4].parent.prio);
    test_output(test, test_num++);
    // 165 priority inheritance/ceiling
    test = (3 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 166 priority inheritance/ceiling
    test = (1 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 167 priority inheritance/ceiling
    test = (1 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 168 priority inheritance/ceiling
    BGRT_PROC_SET_PRIO(PID4, 2);
    bgrt_wait_time(5);
    test = (1 == proc[5].parent.prio);
    test_output(test, test_num++);
    // 169 priority inheritance/ceiling
    test = (2 == proc[4].parent.prio);
    test_output(test, test_num++);
    // 170 priority inheritance/ceiling
    test = (2 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 171 priority inheritance/ceiling
    test = (1 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 172 priority inheritance/ceiling
    test = (1 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 173 priority inheritance/ceiling
    BGRT_PROC_SET_PRIO(PID5, LOWEST);
    bgrt_wait_time(5);
    test = (LOWEST == proc[5].parent.prio);
    test_output(test, test_num++);
    // 174 priority inheritance/ceiling
    test = (2 == proc[4].parent.prio);
    test_output(test, test_num++);
    // 175 priority inheritance/ceiling
    test = (2 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 176 priority inheritance/ceiling
    test = (2 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 177 priority inheritance/ceiling
    test = (2 == proc[1].parent.prio);
    test_output(test, test_num++);

    // 178 priority inheritance/ceiling
    BGRT_SYNC_SET_OWNER(&bgrt_sync_4, PID5);
    bgrt_wait_time(5);
    test = (0 == proc[5].parent.prio);
    test_output(test, test_num++);
    // 179 priority inheritance/ceiling
    test = (2 == proc[4].parent.prio);
    test_output(test, test_num++);
    // 180 priority inheritance/ceiling
    test = (2 == proc[3].parent.prio);
    test_output(test, test_num++);
    // 181 priority inheritance/ceiling
    test = (0 == proc[2].parent.prio);
    test_output(test, test_num++);
    // 182 priority inheritance/ceiling
    test = (0 == proc[1].parent.prio);
    test_output(test, test_num++);
    /// priority inheritance/ceiling tested!!!

    ///Additional tests
    ///BGRT_SYNC_SLEEP
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID0);
    BGRT_SYNC_WAKE(&bgrt_sync_1, PID2, 0);
    bgrt_wait_time(5);
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, PID2);
    bgrt_wait_time(10);
    //183 BGRT_SYNC_SLEEP
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)));
    test_output(test, test_num++);
    //184 BGRT_SYNC_SLEEP
    test = (BGRT_ST_EOWN == status[2]);
    test_output(test, test_num++);
    ///BGRT_SYNC_PROC_TIMEOUT
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, BGRT_PID_NOTHING);
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    kernel_preemt_hook_add(sync_timeout_hook_1);
    status[0] = BGRT_SYNC_PROC_TIMEOUT(PID2);
    bgrt_wait_time(5);
    //185 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //186 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_ESYNC == status[0]);
    test_output(test, test_num++);
    //187 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_OK == status[2]);
    test_output(test, test_num++);
    //188 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_OK == status[6]);
    test_output(test, test_num++);

    ///BGRT_SYNC_PROC_TIMEOUT
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(5);
    kernel_preemt_hook_add(sync_timeout_hook_2);
    status[0] = BGRT_SYNC_PROC_TIMEOUT(PID2);
    //189 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //190 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    //191 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_ESTAT == status[2]);
    test_output(test, test_num++);
    //192 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_OK == status[4]);
    test_output(test, test_num++);
    //193 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_OK == status[5]);
    test_output(test, test_num++);
    //194 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_EEMPTY == status[6]);
    test_output(test, test_num++);

    ///BGRT_SYNC_SLEEP
    //PR2 called BGRT_SYNC_TOUCH, don't panic!!!
    BGRT_PROC_LRES_INC(PR0,0); //Yes, this is a dirty hack!
    status[0] = _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)1);
    bgrt_wait_time(5);
    //195 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)));
    test_output(test, test_num++);
    //196 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    //197 BGRT_SYNC_PROC_TIMEOUT
    test = (BGRT_ST_OK == status[2]);
    test_output(test, test_num++);

    ///BGRT_SYNC_WAKE
    //198
    BGRT_SYNC_SET_OWNER(&bgrt_sync_1, BGRT_PID_NOTHING);
    status[0] = BGRT_SYNC_WAKE(&bgrt_sync_1, PID2, 0);
    test = (BGRT_ST_EOWN == status[0]);
    test_output(test, test_num++);

    ///BGRT_SYNC_SLEEP
    //199
    BGRT_PROC_RUN(PID2);
    bgrt_wait_time(10);
    status[0] = BGRT_SYNC_WAKE(&bgrt_sync_1, BGRT_PID_NOTHING, 0);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);
    //200 Null pointer arg in BGRT_SYNC_SLEEP
    bgrt_wait_time(10);
    test = (BGRT_ST_OK == status[0]);
    test_output(test, test_num++);

    tests_end();
}

void main_1(void * arg)
{
    bgrt_flag_t state;
    (void)arg;
    // 5,6,7
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR1));
    state = BGRT_PROC_GET_STATE((PR1));
    //BGRT_SPIN_FREE((PR1));
    BGRT_INT_FREE();
    status[1] = (BGRT_PROC_STATE_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    BGRT_PROC_SELF_STOP();
    // 8,9,10
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR1));
    state = BGRT_PROC_GET_STATE((PR1));
    //BGRT_SPIN_FREE((PR1));
    BGRT_INT_FREE();
    status[1] = (BGRT_PROC_STATE_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    BGRT_PROC_SELF_STOP();
    // 14,15,16,17,18
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR1));
    state = BGRT_PROC_GET_STATE((PR1));
    //BGRT_SPIN_FREE((PR1));
    BGRT_INT_FREE();
    status[1] = (BGRT_PROC_STATE_PI_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    BGRT_PROC_SELF_STOP();
    // 19,20,21,22,23
    BGRT_INT_LOCK();
    //BGRT_SPIN_LOCK((PR1));
    state = BGRT_PROC_GET_STATE((PR1));
    //BGRT_SPIN_FREE((PR1));
    BGRT_INT_FREE();
    status[1] = (BGRT_PROC_STATE_SYNC_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    BGRT_PROC_SELF_STOP();

    //79,80,81,82
    status[1] = BGRT_ST_ESTAT;
    status[1] = BGRT_SYNC_WAIT(&bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 1);
    BGRT_PROC_SELF_STOP();

    //91,92,93,94,95
    bgrt_proc_buff = BGRT_PID_NOTHING;
    status[1] = BGRT_ST_ESTAT;
    status[1] = BGRT_SYNC_WAIT(&bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 1);
    status[2] = BGRT_ST_ESTAT;
    status[2] = BGRT_SYNC_WAKE(&bgrt_sync_1, (BGRT_PID_T)bgrt_proc_buff, 0);
    BGRT_PROC_SELF_STOP();

    //96,97
    bgrt_proc_buff = BGRT_PID_NOTHING;
    status[1] = BGRT_ST_ESTAT;
    status[1] = BGRT_SYNC_WAIT(&bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 0);
    BGRT_PROC_SELF_STOP();

    //98,99,100
    status[1] = BGRT_ST_ESTAT;
    status[1] = BGRT_SYNC_WAIT(&bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 1);
    BGRT_PROC_SELF_STOP();

    //106,107,108,109,110
    status[1] = BGRT_ST_ESTAT;
    status[1] = BGRT_SYNC_WAKE(&bgrt_sync_1, 0, 0);
    BGRT_PROC_SELF_STOP();

    //124,125,126,127
    bgrt_proc_buff = BGRT_PID_NOTHING;
    status[1] = BGRT_ST_ESTAT;
    status[1] = BGRT_SYNC_WAIT(&bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 1);
    BGRT_SYNC_WAKE(&bgrt_sync_1, bgrt_proc_buff, 0);
    BGRT_PROC_SELF_STOP();
}

void main_2(void * arg)
{
    (void)arg;
    //69,70,71
    status[2] = BGRT_ST_ESTAT;
    status[2] = _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();
    //72,73,74,75,76,77,78
    status[2] = BGRT_ST_ESTAT;
    status[2] = _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();
    //79,80,81,82
    status[2] = BGRT_ST_ESTAT;
    status[2] = _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0);
    // 82,83,84,85,86
    BGRT_SYNC_TOUCH(&bgrt_sync_1);
    status[2] = BGRT_ST_ESTAT;
    status[1] = BGRT_SYNC_WAKE(&bgrt_sync_1, 0, 0); /// status[1] is used!!!
    status[3] = BGRT_SYNC_WAKE(&bgrt_sync_1, 0, 0); /// status[3] is used!!!
    //status[3] = (2 == bgrt_sync_1.pwake);        /// status[3] is used!!!
    status[2] = BGRT_ST_ESTAT;
    status[2] = _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)1);
    BGRT_PROC_SELF_STOP();

    //91,92,93,94,95
    BGRT_SYNC_TOUCH(&bgrt_sync_1);
    BGRT_PROC_RUN(PID1);
    bgrt_wait_time(10);
    _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)1);
    BGRT_PROC_SELF_STOP();

    //106,107,108,109,110
    BGRT_SYNC_TOUCH(&bgrt_sync_1);
    BGRT_PROC_RUN(PID1);
    BGRT_PROC_SELF_STOP();
    _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)1);
    BGRT_PROC_SELF_STOP();

    //111,112,113
    _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();

    //114,115,116
    _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();

    //117,118,119
    _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();

    //122,123
    _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();

    //124,125,126,127
    BGRT_SYNC_TOUCH(&bgrt_sync_1);
    BGRT_PROC_RUN(PID1);
    bgrt_wait_time(10);
    _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)1);
    BGRT_PROC_SELF_STOP();

    // priority inheritance/ceiling
    _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0);
    //BGRT_PROC_SELF_STOP();

    ///Additional tests
    //183, 184
    BGRT_SYNC_TOUCH(&bgrt_sync_1);
    bgrt_wait_time(10);
    status[2] = BGRT_ST_ESTAT;
    status[2] = _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)1);
    BGRT_PROC_SELF_STOP();
    //185,186,187,188
    status[2] = BGRT_ST_ESTAT;
    status[2] = _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();
    //189,190,191,192,193,194
    status[2] = BGRT_ST_ESTAT;
    // bgrt_sync_1 must be dirty on sync_timeout_hook_1 call
    BGRT_SYNC_TOUCH(&bgrt_sync_1);
    status[2] = _test_sync_sleep(&bgrt_sync_1, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();

    //199, 200 null pointer as argument.
    status[2] = BGRT_ST_ESTAT;
    status[2] = BGRT_SYNC_SLEEP(&bgrt_sync_1,0);
    BGRT_PROC_SELF_STOP();
}

void main_3(void * arg)
{
    (void)arg;
    // priority inheritance/ceiling
    _test_sync_sleep(&bgrt_sync_2, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();
}

void main_4(void * arg)
{
    (void)arg;
    // priority inheritance/ceiling
    _test_sync_sleep(&bgrt_sync_3, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();
}

void main_5(void * arg)
{
    (void)arg;
    // priority inheritance/ceiling
    _test_sync_sleep(&bgrt_sync_2, (bgrt_flag_t)0);
    BGRT_PROC_SELF_STOP();
}

int main(void)
{
    /**************************************************
    *          For test purposes only!!!              *
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

    bgrt_priv_proc_init(PR0, main_0, SVH0, RSH0, 0, &bgrt_proc_stack[0][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 ARG_END);
    bgrt_priv_proc_init(PR1, main_1, SVH1, RSH1, 0, &bgrt_proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 ARG_END);
    bgrt_priv_proc_init(PR2, main_2, SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 4,      1, 0 ARG_END);
    bgrt_priv_proc_init(PR3, main_3, SVH3, RSH3, 0, &bgrt_proc_stack[3][BGRT_PROC_STACK_SIZE-1], 3,      1, 0 ARG_END);
    bgrt_priv_proc_init(PR4, main_4, SVH4, RSH4, 0, &bgrt_proc_stack[4][BGRT_PROC_STACK_SIZE-1], 2,      1, 0 ARG_END);
    bgrt_priv_proc_init(PR5, main_5, SVH5, RSH5, 0, &bgrt_proc_stack[5][BGRT_PROC_STACK_SIZE-1], 1,      1, 0 ARG_END);

    bgrt_priv_sync_init(&bgrt_sync_1, LOWEST);
    bgrt_priv_sync_init(&bgrt_sync_2, LOWEST);
    bgrt_priv_sync_init(&bgrt_sync_3, LOWEST);
    bgrt_priv_sync_init(&bgrt_sync_4, 0);

    bgrt_priv_proc_run(PR0);

    bgrt_start();
    return 0;
}
