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
    if( BGRT_PROC_STATE_PI_PEND == BGRT_PROC_GET_STATE( (PR1) ) )
    {
        test_kernel_preempt = test_do_nothing;
        BGRT_PROC_SET_STATE( (PR1), BGRT_PROC_STATE_PI_DONE );
    }
}

void prio_propagate_hook_1(void)
{
    if( BGRT_PROC_STATE_PI_PEND == BGRT_PROC_GET_STATE( (PR2) ) )
    {
        test_kernel_preempt = test_do_nothing;
        status[6] = _bgrt_sync_wake(&bgrt_sync_1, PR2, 1 ); //chown
    }
}

void prio_propagate_hook_2(void)
{
    if( BGRT_PROC_STATE_PI_PEND == BGRT_PROC_GET_STATE( (PR2) ) )
    {
        test_kernel_preempt = test_do_nothing;
        status[6] = _bgrt_sync_wake(&bgrt_sync_1, PR2, 0 );
    }
}

void sync_timeout_hook_1(void)
{
    if( BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE( (PR2) ) )
    {
        test_kernel_preempt = test_do_nothing;
        status[6] = _bgrt_sync_wake(&bgrt_sync_1, PR2, 0 );
    }
}
void sync_timeout_hook_2(void)
{
    if( BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE( (PR2) ) )
    {
        test_kernel_preempt = test_do_nothing;
        status[4] = _bgrt_sync_wake(&bgrt_sync_1, PR2, 0 );
        status[5] = _bgrt_sync_wake(&bgrt_sync_1, PR2, 0 );
        status[6] = _bgrt_sync_wake(&bgrt_sync_1, PR2, 0 );
    }
}

void main_0( void * arg )
{
    test_start();
    // 1 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    bgrt_proc_set_prio( PID1, 5 );
    test = ( 5 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 2 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( 5 == proc[1].parent.prio);
    test_output( test, test_num++ );

    //3 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    bgrt_proc_set_prio( PID0, 6 );
    test = ( 6 == proc[0].base_prio);
    test_output( test, test_num++ );
    // 4 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( 6 == proc[0].parent.prio );
    test_output( test, test_num++ );

    // 5 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    status[1] = BGRT_ST_ESTAT;
    BGRT_PROC_SET_STATE( (PR1), BGRT_PROC_STATE_SYNC_WAIT );
    bgrt_proc_set_prio( PID1, 4 );
    bgrt_wait_time(5);
    test = ( 4 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 6 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( 4 == proc[1].parent.prio);
    test_output( test, test_num++ );
    // 7 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );

    // 8 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    status[1] = BGRT_ST_ESTAT;
    BGRT_PROC_SET_STATE( (PR1), BGRT_PROC_STATE_SYNC_SLEEP );
    bgrt_proc_set_prio( PID1, 5 );
    bgrt_wait_time(5);
    test = ( 5 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 9 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( 5 == proc[1].parent.prio);
    test_output( test, test_num++ );
    // 10 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );

    // 11 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    BGRT_PROC_SET_STATE( (PR1), BGRT_PROC_STATE_SYNC_SLEEP );
    bgrt_pitem_insert( (bgrt_pitem_t *)(PR1), (bgrt_xlist_t *)(&bgrt_sync_1) );
    proc[1].sync = &bgrt_sync_1;
    bgrt_proc_set_prio( PID1, 4 );
    bgrt_wait_time(5);
    test = ( 4 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 12 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( 4 == proc[1].parent.prio);
    test_output( test, test_num++ );
    // 13 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );

    // 14 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    status[1] = BGRT_ST_ESTAT;
    bgrt_sync_1.owner = PR2;
    BGRT_PROC_LRES_INC( (PR2), BGRT_SYNC_PRIO(&bgrt_sync_1) );
    bgrt_proc_set_prio( PID1, 5 );
    bgrt_wait_time(5);
    test = ( 5 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 15 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( 0 == proc[1].parent.prio);
    test_output( test, test_num++ );
    // 16 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    // 17 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( 1 == bgrt_sync_1.dirty );
    test_output( test, test_num++ );
    // 18 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( 1 == proc[2].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );

    // 19 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    status[1] = BGRT_ST_ESTAT;

    BGRT_PROC_SET_STATE( (PR1), BGRT_PROC_STATE_SYNC_SLEEP );
    proc[1].sync = &bgrt_sync_1;
    BGRT_PROC_LRES_DEC( (PR1), 0 );
    proc[1].parent.prio = proc[1].base_prio;

    bgrt_sync_1.dirty = (bgrt_cnt_t)0;
    BGRT_PROC_LRES_DEC( (PR2), BGRT_SYNC_PRIO(&bgrt_sync_1) );
    bgrt_pitem_insert( (bgrt_pitem_t *)(PR1), (bgrt_xlist_t *)(&bgrt_sync_1) );
    BGRT_PROC_LRES_INC( (PR2), BGRT_SYNC_PRIO(&bgrt_sync_1) );

    kernel_preemt_hook_add( prio_propagate_hook_0 );

    bgrt_proc_set_prio( PID1, 4 );
    bgrt_wait_time(5);
    test = ( 4 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 20 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( 0 == proc[1].parent.prio);
    test_output( test, test_num++ );
    // 21 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    // 22 _bgrt_proc_prio_propagate bgrt_proc_set_prio
    test = ( 1 == proc[2].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    /// _bgrt_proc_prio_propagate covered!!!
    //cleanup
    BGRT_PROC_LRES_DEC( (PR2), BGRT_SYNC_PRIO(&bgrt_sync_1) );
    bgrt_sync_1.owner = (bgrt_proc_t *)0;
    BGRT_PROC_LRES_DEC( (PR1), 0 );
    // 23 bgrt_sync_set_owner
    status[0] = bgrt_sync_set_owner( (bgrt_sync_t *)0, BGRT_PID_NOTHING );
    test = (BGRT_ST_ENULL == status[0]);
    test_output( test, test_num++ );

    // 24 bgrt_sync_set_owner
    status[0] = bgrt_sync_set_owner( &bgrt_sync_1, PID1 );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 25 bgrt_sync_set_owner
    test = ( (PR1) == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    // 26 bgrt_sync_set_owner
    test = ( 1 == proc[1].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );

    // 27 bgrt_sync_set_owner
    status[0] = bgrt_sync_set_owner( &bgrt_sync_1, PID1 );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 28 bgrt_sync_set_owner
    test = ( (PR1) == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    // 29 bgrt_sync_set_owner
    test = ( 1 == proc[1].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );

    // 30 bgrt_sync_set_owner
    status[0] = bgrt_sync_set_owner( &bgrt_sync_1, PID2 );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 31 bgrt_sync_set_owner
    test = ( (PR2) == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    // 32 bgrt_sync_set_owner
    test = ( 1 == proc[2].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 33 bgrt_sync_set_owner
    test = ( 0 == proc[1].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );

    // 34 bgrt_sync_set_owner
    status[0] = bgrt_sync_set_owner( &bgrt_sync_1, BGRT_PID_NOTHING );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 35 bgrt_sync_set_owner
    test = ( ((bgrt_proc_t *)0) == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    // 36 bgrt_sync_set_owner
    test = ( 0 == proc[2].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    /// bgrt_sync_set_owner covered !!!
    // 37 bgrt_sync_own
    status[0] = bgrt_sync_own( (bgrt_sync_t *)0, (bgrt_flag_t)0 );
    test = (BGRT_ST_ENULL == status[0]);
    test_output( test, test_num++ );

    // 38 bgrt_sync_own
    status[0] = bgrt_sync_own( &bgrt_sync_1, (bgrt_flag_t)0 );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 39 bgrt_sync_own
    test = ( (PR0) == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    // 40 bgrt_sync_own
    test = ( 1 == proc[0].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 41 bgrt_sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR0) );
    test = ( BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)) );
    //BGRT_SPIN_FREE( (PR0) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    // 42 bgrt_sync_own
    status[0] = bgrt_sync_own( &bgrt_sync_1, (bgrt_flag_t)0 );
    test = (BGRT_ST_EOWN == status[0]);
    test_output( test, test_num++ );
    // 43 bgrt_sync_own
    test = ( (PR0) == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    // 44 bgrt_sync_own
    test = ( 1 == proc[0].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 45 bgrt_sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR0) );
    test = ( BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)) );
    //BGRT_SPIN_FREE( (PR0) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    // 46 bgrt_sync_own
    bgrt_sync_set_owner( &bgrt_sync_1, BGRT_PID_NOTHING );
    status[0] = bgrt_sync_own( &bgrt_sync_1, (bgrt_flag_t)1 );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 47 bgrt_sync_own
    test = ( (PR0) == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    // 48 bgrt_sync_own
    test = ( 1 == proc[0].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 49 bgrt_sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR0) );
    test = ( BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)) );
    //BGRT_SPIN_FREE( (PR0) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    // 50 bgrt_sync_own
    status[0] = bgrt_sync_own( &bgrt_sync_1, (bgrt_flag_t)1 );
    test = (BGRT_ST_EOWN == status[0]);
    test = test && ( 0 == bgrt_sync_1.dirty );
    test_output( test, test_num++ );
    // 51 bgrt_sync_own
    test = ( (PR0) == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    // 52 bgrt_sync_own
    test = ( 1 == proc[0].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 53 bgrt_sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR0) );
    test = ( BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)) );
    //BGRT_SPIN_FREE( (PR0) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    // 54 bgrt_sync_own
    bgrt_sync_set_owner( &bgrt_sync_1, PID1 );
    status[0] = bgrt_sync_own( &bgrt_sync_1, (bgrt_flag_t)0 );
    test = (BGRT_ST_EOWN == status[0]);
    test_output( test, test_num++ );
    // 55 bgrt_sync_own
    test = ( (PR1) == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    // 56 bgrt_sync_own
    test = ( 1 == proc[1].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 57 bgrt_sync_own
    test = ( 0 == proc[0].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 58 bgrt_sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR0) );
    test = ( BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)) );
    //BGRT_SPIN_FREE( (PR0) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    // 59 bgrt_sync_own
    status[0] = bgrt_sync_own( &bgrt_sync_1, (bgrt_flag_t)1 );
    test = (BGRT_ST_EOWN == status[0]);
    test_output( test, test_num++ );
    // 60 bgrt_sync_own
    test = ( (PR1) == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    // 61 bgrt_sync_own
    test = ( 1 == proc[1].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 62 bgrt_sync_own
    test = ( 0 == proc[0].lres.counter[BGRT_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 63 bgrt_sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR0) );
    test = ( BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)) );
    if(test)
    {
        BGRT_PROC_SET_STATE( (PR0), BGRT_PROC_STATE_RUNNING );
        BGRT_PROC_LRES_DEC(PR0, 0);
        proc[0].sync = (bgrt_sync_t *)0;
    }
    //BGRT_SPIN_FREE( (PR0) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );
    /// bgrt_sync_own covered!!!
    //cleanup
    bgrt_proc_set_prio( PID0, 6 );
    bgrt_sync_set_owner( &bgrt_sync_1, BGRT_PID_NOTHING );
    bgrt_sync_1.dirty = 0;
    bgrt_sync_1.snum  = 0;

    //64 bgrt_sync_touch
    status[0] = bgrt_sync_touch( (bgrt_sync_t *)0 );
    test = (BGRT_ST_ENULL == status[0]);
    test_output( test, test_num++ );
    //65 bgrt_sync_touch
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR0) );
    test = ( BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)) );
    //BGRT_SPIN_FREE( (PR0) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    //66 bgrt_sync_touch
    status[0] = bgrt_sync_touch( &bgrt_sync_1 );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    //67 bgrt_sync_touch
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR0) );
    test = ( BGRT_PROC_STATE_RUNNING == BGRT_PROC_GET_STATE((PR0)) );
    if(test)
    {
        BGRT_PROC_SET_STATE( (PR0), BGRT_PROC_STATE_RUNNING );
        BGRT_PROC_LRES_DEC(PR0, 0);
        proc[0].sync = (bgrt_sync_t *)0;
    }
    //BGRT_SPIN_FREE( (PR0) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );
    /// bgrt_sync_touch covered!!!
    //cleanup
    bgrt_proc_set_prio( PID0, LOWEST );
    bgrt_sync_1.dirty = 0;
    bgrt_sync_1.snum  = 0;
    //68 bgrt_sync_sleep
    test = ( BGRT_ST_ENULL == bgrt_sync_sleep( (bgrt_sync_t *)0, (bgrt_flag_t)0 ) );
    test_output( test, test_num++ );
    //69 bgrt_sync_sleep
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    test = ( BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //70 bgrt_sync_sleep bgrt_sync_wake
    test = ( BGRT_ST_OK == bgrt_sync_wake( &bgrt_sync_1, 0, 0 ) );
    test_output( test, test_num++ );
    //71 bgrt_sync_sleep
    bgrt_wait_time(5);
    test = ( BGRT_ST_OK == status[2] );
    test_output( test, test_num++ );

    //72 bgrt_sync_sleep
    bgrt_proc_set_prio( PID1, LOWEST );
    bgrt_sync_set_owner( &bgrt_sync_1, PID1 );
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    test = ( BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //73 bgrt_sync_sleep
    test = ( 4 == proc[1].parent.prio );
    test_output( test, test_num++ );

    //74 bgrt_sync_sleep
    bgrt_proc_set_prio( PID2, 5 );
    bgrt_wait_time(5);
    test = ( BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //75 bgrt_sync_sleep
    test = ( 5 == proc[1].parent.prio );
    test_output( test, test_num++ );

    //76 bgrt_sync_sleep bgrt_sync_proc_timeout
    status[0] = bgrt_sync_proc_timeout( PID2 );
    bgrt_wait_time(5);
    test = (BGRT_ST_OK == status[0]);
    test = test && ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //77 bgrt_sync_sleep bgrt_sync_proc_timeout
    test = ( BGRT_ST_ETIMEOUT == status[2] );
    test_output( test, test_num++ );
    //78 bgrt_sync_sleep bgrt_sync_proc_timeout
    test = ( LOWEST == proc[1].parent.prio );
    test_output( test, test_num++ );

    //79 bgrt_sync_sleep bgrt_sync_wait
    bgrt_proc_set_prio( PID2, LOWEST );
    bgrt_proc_run( PID1 );
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    test = ( BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //80 bgrt_sync_sleep bgrt_sync_wait
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    //81 bgrt_sync_sleep bgrt_sync_wait
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );

    //82 bgrt_sync_sleep bgrt_sync_wake
    bgrt_sync_set_owner( &bgrt_sync_1, BGRT_PID_NOTHING );
    status[0] = bgrt_sync_wake( &bgrt_sync_1, 0, 0 );
    bgrt_wait_time(10);
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    //83 bgrt_sync_sleep bgrt_sync_wake
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    //84 bgrt_sync_sleep bgrt_sync_wake
    test = ( BGRT_ST_EEMPTY == status[3] );
    test_output( test, test_num++ );
    //85 bgrt_sync_sleep
    test = ( BGRT_ST_OK == status[2] );
    test_output( test, test_num++ );
    //86 bgrt_sync_sleep
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //cleanup
    bgrt_proc_set_prio( PID2, 4 );
    //87 bgrt_sync_sleep
    bgrt_sync_own( &bgrt_sync_1, (bgrt_flag_t)0 );
    test = ( BGRT_ST_EOWN == bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 ) );
    test_output( test, test_num++ );
    /// bgrt_sync_sleep is almost covered!!!

    //88 bgrt_sync_wait
    bgrt_sync_set_owner( &bgrt_sync_1, PID1 );
    test = ( BGRT_ST_EOWN == bgrt_sync_wait( &bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 0 ) );
    test_output( test, test_num++ );
    //89 bgrt_sync_wait
    test = ( BGRT_ST_ENULL == bgrt_sync_wait( (bgrt_sync_t *)0, (BGRT_PID_T *)&bgrt_proc_buff, 0 ) );
    test_output( test, test_num++ );
    //90 bgrt_sync_wait
    test = ( BGRT_ST_ENULL == bgrt_sync_wait( &bgrt_sync_1, (BGRT_PID_T *)0, 0 ) );
    test_output( test, test_num++ );

    //91 bgrt_sync_wait bgrt_sync_wake
    //bgrt_sync_touch( &bgrt_sync_1 );
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    test = ( BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );
    //92 bgrt_sync_wait bgrt_sync_wake
    bgrt_wait_time(20);
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    //93 bgrt_sync_wait bgrt_sync_wake
    test = ( BGRT_ST_OK == status[2] );
    test_output( test, test_num++ );
    //94 bgrt_sync_wait bgrt_sync_wake
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );
    //95 bgrt_sync_wait bgrt_sync_wake
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );

    //96 bgrt_sync_wait
    bgrt_proc_run( PID1 );
    bgrt_wait_time(5);
    test = ( BGRT_ST_EEMPTY == status[1] );
    test_output( test, test_num++ );
    //97 bgrt_sync_wait
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );

    //97 bgrt_sync_wait
    bgrt_proc_run( PID1 );
    bgrt_wait_time(5);
    test = ( BGRT_PROC_STATE_SYNC_WAIT == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );
    //98 bgrt_sync_wait bgrt_sync_proc_timeout
    status[0] = bgrt_sync_proc_timeout( PID1 );
    test = ( BGRT_ST_OK == status[0] );
    test_output( test, test_num++ );
    //99 bgrt_sync_wait bgrt_sync_proc_timeout
    bgrt_wait_time(5);
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );
    //100 bgrt_sync_wait bgrt_sync_proc_timeout
    test = ( BGRT_ST_ETIMEOUT == status[1] );
    test_output( test, test_num++ );
    /// bgrt_sync_wait covered!!!

    //101 bgrt_sync_wake
    test = ( BGRT_ST_ENULL == bgrt_sync_wake( (bgrt_sync_t *)0, BGRT_PID_NOTHING, 0) );
    test_output( test, test_num++ );

    //103 bgrt_sync_wake
    test = ( BGRT_ST_EOWN == bgrt_sync_wake( &bgrt_sync_1, BGRT_PID_NOTHING, 0) );
    test_output( test, test_num++ );

    //104 bgrt_sync_wake
    bgrt_sync_set_owner( &bgrt_sync_1, PID0 );
    test = ( BGRT_ST_EEMPTY == bgrt_sync_wake( &bgrt_sync_1, BGRT_PID_NOTHING, 0) );
    test_output( test, test_num++ );

    //105 bgrt_sync_wake
    test = ( BGRT_ST_ESYNC == bgrt_sync_wake( &bgrt_sync_1, PID2, 0) );
    test_output( test, test_num++ );

    //106 bgrt_sync_wake
    bgrt_sync_set_owner( &bgrt_sync_1, PID1 );
    bgrt_proc_run( PID2 );
    bgrt_wait_time(10);
    test = ( BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );
    //107 bgrt_sync_wake
    test = ( (bgrt_sync_t *)0 == proc[1].sync );
    test_output( test, test_num++ );

    bgrt_proc_run( PID2 );
    //108 bgrt_sync_wake
    bgrt_wait_time(20);
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );
    //109 bgrt_sync_wake
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //110 bgrt_sync_wake
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );

    //111 bgrt_sync_wake
    bgrt_sync_set_owner( &bgrt_sync_1, PID0 );
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    status[6] = BGRT_ST_ESTAT;
    kernel_preemt_hook_add( prio_propagate_hook_1 );
    bgrt_proc_set_prio( PID2, 4 );
    bgrt_wait_time(5);
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //112 bgrt_sync_wake
    test = ( BGRT_ST_OK == status[6] );
    test_output( test, test_num++ );
    //113 bgrt_sync_wake
    test = ( PR2 == bgrt_sync_1.owner );
    test_output( test, test_num++ );

    //114 bgrt_sync_wake
    bgrt_sync_set_owner( &bgrt_sync_1, PID0 );
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    status[6] = BGRT_ST_ESTAT;
    kernel_preemt_hook_add( prio_propagate_hook_2 );
    bgrt_proc_set_prio( PID2, 4 );
    bgrt_wait_time(5);
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //115 bgrt_sync_wake
    test = ( BGRT_ST_OK == status[6] );
    test_output( test, test_num++ );
    //116 bgrt_sync_wake
    test = ( PR0 == bgrt_sync_1.owner );
    test_output( test, test_num++ );

    //117 bgrt_sync_wake
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    status[0] = bgrt_sync_wake( &bgrt_sync_1, BGRT_PID_NOTHING, 1 );
    bgrt_wait_time(5);
    test = ( BGRT_ST_OK == status[0] );
    test_output( test, test_num++ );
    //118 bgrt_sync_wake
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //119 bgrt_sync_wake
    test = ( PR2 == bgrt_sync_1.owner );
    test_output( test, test_num++ );
    /// bgrt_sync_wait and _bgrt_sync_do_wake covered!!!

    //120 bgrt_sync_proc_timeout
    test = ( BGRT_ST_ENULL == bgrt_sync_proc_timeout( BGRT_PID_NOTHING ) );
    test_output( test, test_num++ );
    //121 bgrt_sync_proc_timeout
    test = ( BGRT_ST_ESYNC == bgrt_sync_proc_timeout( PID0 ) );
    test_output( test, test_num++ );

    //122 bgrt_sync_proc_timeout
    bgrt_sync_set_owner( &bgrt_sync_1, BGRT_PID_NOTHING );
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    test = ( BGRT_ST_OK == bgrt_sync_proc_timeout( PID2 ) );
    test_output( test, test_num++ );
    //123 bgrt_sync_proc_timeout
    bgrt_wait_time(5);
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );

    //124 bgrt_sync_proc_timeout
    bgrt_disable_interrupts();
    BGRT_PROC_SET_STATE( (PR2), BGRT_PROC_STATE_PI_PEND );
    PR2->sync = &bgrt_sync_1;
    bgrt_enable_interrupts();

    status[0] = bgrt_sync_proc_timeout( PID2 );
    test = ( BGRT_ST_EAGAIN == status[0] );
    test_output( test, test_num++ );
    //cleanup
    bgrt_disable_interrupts();
    BGRT_PROC_SET_STATE( (PR2), BGRT_PROC_STATE_STOPED );
    PR2->sync = 0;
    bgrt_enable_interrupts();
    //125 bgrt_sync_proc_timeout
    bgrt_sync_set_owner( &bgrt_sync_1, PID1 );
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    status[0] =  bgrt_sync_proc_timeout( PID1 );
    test = ( BGRT_ST_OK == status[0] );
    test_output( test, test_num++ );
    //126 bgrt_sync_proc_timeout
    bgrt_wait_time(20);
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    //127 bgrt_sync_proc_timeout
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );
    //128 bgrt_sync_proc_timeout
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    /// bgrt_sync_proc_timeout tested but not covered!!!

    // 129 priority inheritance/ceiling
    bgrt_sync_set_owner( &bgrt_sync_2, PID2 );
    bgrt_sync_set_owner( &bgrt_sync_3, PID3 );
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    test = ( 4 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 130 priority inheritance/ceiling
    bgrt_proc_run( PID3 );
    bgrt_wait_time(5);
    test = ( 3 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 131 priority inheritance/ceiling
    test = ( 3 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 132 priority inheritance/ceiling
    bgrt_proc_run( PID4 );
    bgrt_wait_time(5);
    test = ( 2 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 133 priority inheritance/ceiling
    test = ( 2 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 134 priority inheritance/ceiling
    test = ( 2 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 135 priority inheritance/ceiling
    bgrt_proc_run( PID5 );
    bgrt_wait_time(5);
    test = ( 2 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 136 priority inheritance/ceiling
    test = ( 1 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 137 priority inheritance/ceiling
    test = ( 1 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 138 priority inheritance/ceiling
    bgrt_proc_set_prio( PID5, 0 );
    bgrt_wait_time(5);
    test = ( 0 == proc[5].parent.prio);
    test_output( test, test_num++ );
    // 139 priority inheritance/ceiling
    test = ( 2 == proc[4].parent.prio);
    test_output( test, test_num++ );
    // 140 priority inheritance/ceiling
    test = ( 2 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 141 priority inheritance/ceiling
    test = ( 0 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 142 priority inheritance/ceiling
    test = ( 0 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 143 priority inheritance/ceiling
    bgrt_proc_set_prio( PID5, 1 );
    bgrt_wait_time(5);
    test = ( 1 == proc[5].parent.prio);
    test_output( test, test_num++ );
    // 144 priority inheritance/ceiling
    test = ( 2 == proc[4].parent.prio);
    test_output( test, test_num++ );
    // 145 priority inheritance/ceiling
    test = ( 2 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 146 priority inheritance/ceiling
    test = ( 1 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 147 priority inheritance/ceiling
    test = ( 1 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 148 priority inheritance/ceiling
    bgrt_proc_set_prio( PID2, 0 );
    bgrt_wait_time(5);
    test = ( 1 == proc[5].parent.prio);
    test_output( test, test_num++ );
    // 149 priority inheritance/ceiling
    test = ( 2 == proc[4].parent.prio);
    test_output( test, test_num++ );
    // 150 priority inheritance/ceiling
    test = ( 2 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 151 priority inheritance/ceiling
    test = ( 0 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 152 priority inheritance/ceiling
    test = ( 0 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 153 priority inheritance/ceiling
    bgrt_proc_set_prio( PID2, 1 );
    bgrt_wait_time(5);
    test = ( 1 == proc[5].parent.prio);
    test_output( test, test_num++ );
    // 154 priority inheritance/ceiling
    test = ( 2 == proc[4].parent.prio);
    test_output( test, test_num++ );
    // 155 priority inheritance/ceiling
    test = ( 2 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 156 priority inheritance/ceiling
    test = ( 1 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 157 priority inheritance/ceiling
    test = ( 1 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 158 priority inheritance/ceiling
    bgrt_proc_set_prio( PID2, 4 );
    bgrt_wait_time(5);
    test = ( 1 == proc[5].parent.prio);
    test_output( test, test_num++ );
    // 159 priority inheritance/ceiling
    test = ( 2 == proc[4].parent.prio);
    test_output( test, test_num++ );
    // 160 priority inheritance/ceiling
    test = ( 2 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 161 priority inheritance/ceiling
    test = ( 1 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 162 priority inheritance/ceiling
    test = ( 1 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 163 priority inheritance/ceiling
    bgrt_proc_set_prio( PID4, 4 );
    bgrt_wait_time(5);
    test = ( 1 == proc[5].parent.prio);
    test_output( test, test_num++ );
    // 164 priority inheritance/ceiling
    test = ( 4 == proc[4].parent.prio);
    test_output( test, test_num++ );
    // 165 priority inheritance/ceiling
    test = ( 3 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 166 priority inheritance/ceiling
    test = ( 1 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 167 priority inheritance/ceiling
    test = ( 1 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 168 priority inheritance/ceiling
    bgrt_proc_set_prio( PID4, 2 );
    bgrt_wait_time(5);
    test = ( 1 == proc[5].parent.prio);
    test_output( test, test_num++ );
    // 169 priority inheritance/ceiling
    test = ( 2 == proc[4].parent.prio);
    test_output( test, test_num++ );
    // 170 priority inheritance/ceiling
    test = ( 2 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 171 priority inheritance/ceiling
    test = ( 1 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 172 priority inheritance/ceiling
    test = ( 1 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 173 priority inheritance/ceiling
    bgrt_proc_set_prio( PID5, LOWEST );
    bgrt_wait_time(5);
    test = ( LOWEST == proc[5].parent.prio);
    test_output( test, test_num++ );
    // 174 priority inheritance/ceiling
    test = ( 2 == proc[4].parent.prio);
    test_output( test, test_num++ );
    // 175 priority inheritance/ceiling
    test = ( 2 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 176 priority inheritance/ceiling
    test = ( 2 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 177 priority inheritance/ceiling
    test = ( 2 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 178 priority inheritance/ceiling
    bgrt_sync_set_owner( &bgrt_sync_4, PID5 );
    bgrt_wait_time(5);
    test = ( 0 == proc[5].parent.prio);
    test_output( test, test_num++ );
    // 179 priority inheritance/ceiling
    test = ( 2 == proc[4].parent.prio);
    test_output( test, test_num++ );
    // 180 priority inheritance/ceiling
    test = ( 2 == proc[3].parent.prio);
    test_output( test, test_num++ );
    // 181 priority inheritance/ceiling
    test = ( 0 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 182 priority inheritance/ceiling
    test = ( 0 == proc[1].parent.prio);
    test_output( test, test_num++ );
    /// priority inheritance/ceiling tested!!!

    ///Additional tests
    ///bgrt_sync_sleep
    bgrt_sync_set_owner( &bgrt_sync_1, PID0 );
    bgrt_sync_wake( &bgrt_sync_1, PID2, 0);
    bgrt_wait_time(5);
    bgrt_sync_set_owner( &bgrt_sync_1, PID2 );
    bgrt_wait_time(10);
    //183 bgrt_sync_sleep
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR1)) );
    test_output( test, test_num++ );
    //184 bgrt_sync_sleep
    test = ( BGRT_ST_EOWN == status[2] );
    test_output( test, test_num++ );
    ///bgrt_sync_proc_timeout
    bgrt_sync_set_owner( &bgrt_sync_1, BGRT_PID_NOTHING );
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    kernel_preemt_hook_add( sync_timeout_hook_1 );
    status[0] = bgrt_sync_proc_timeout( PID2 );
    bgrt_wait_time(5);
    //185 bgrt_sync_proc_timeout
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //186 bgrt_sync_proc_timeout
    test = ( BGRT_ST_ESYNC == status[0] );
    test_output( test, test_num++ );
    //187 bgrt_sync_proc_timeout
    test = ( BGRT_ST_OK == status[2] );
    test_output( test, test_num++ );
    //188 bgrt_sync_proc_timeout
    test = ( BGRT_ST_OK == status[6] );
    test_output( test, test_num++ );

    ///bgrt_sync_proc_timeout
    bgrt_proc_run( PID2 );
    bgrt_wait_time(5);
    kernel_preemt_hook_add( sync_timeout_hook_2 );
    status[0] = bgrt_sync_proc_timeout( PID2 );
    //189 bgrt_sync_proc_timeout
    test = ( BGRT_PROC_STATE_SYNC_SLEEP == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //190 bgrt_sync_proc_timeout
    test = ( BGRT_ST_OK == status[0] );
    test_output( test, test_num++ );
    //191 bgrt_sync_proc_timeout
    test = ( BGRT_ST_ESTAT == status[2] );
    test_output( test, test_num++ );
    //192 bgrt_sync_proc_timeout
    test = ( BGRT_ST_OK == status[4] );
    test_output( test, test_num++ );
    //193 bgrt_sync_proc_timeout
    test = ( BGRT_ST_OK == status[5] );
    test_output( test, test_num++ );
    //194 bgrt_sync_proc_timeout
    test = ( BGRT_ST_EEMPTY == status[6] );
    test_output( test, test_num++ );

    ///bgrt_sync_sleep
    //PR2 called bgrt_sync_touch, don't panic!!!
    BGRT_PROC_LRES_INC(PR0,0); //Yes, this is a dirty hack!
    status[0] = bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)1 );
    bgrt_wait_time(5);
    //195 bgrt_sync_proc_timeout
    test = ( BGRT_PROC_STATE_STOPED == BGRT_PROC_GET_STATE((PR2)) );
    test_output( test, test_num++ );
    //196 bgrt_sync_proc_timeout
    test = ( BGRT_ST_OK == status[0] );
    test_output( test, test_num++ );
    //197 bgrt_sync_proc_timeout
    test = ( BGRT_ST_OK == status[2] );
    test_output( test, test_num++ );

    tests_end();
}

void main_1( void * arg )
{
    bgrt_flag_t state;
    // 5,6,7
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR1) );
    state = BGRT_PROC_GET_STATE((PR1));
    //BGRT_SPIN_FREE( (PR1) );
    bgrt_enable_interrupts();
    status[1] = (BGRT_PROC_STATE_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    bgrt_proc_self_stop();
    // 8,9,10
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR1) );
    state = BGRT_PROC_GET_STATE((PR1));
    //BGRT_SPIN_FREE( (PR1) );
    bgrt_enable_interrupts();
    status[1] = (BGRT_PROC_STATE_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    bgrt_proc_self_stop();
    // 14,15,16,17,18
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR1) );
    state = BGRT_PROC_GET_STATE((PR1));
    //BGRT_SPIN_FREE( (PR1) );
    bgrt_enable_interrupts();
    status[1] = (BGRT_PROC_STATE_PI_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    bgrt_proc_self_stop();
    // 19,20,21,22,23
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (PR1) );
    state = BGRT_PROC_GET_STATE((PR1));
    //BGRT_SPIN_FREE( (PR1) );
    bgrt_enable_interrupts();
    status[1] = (BGRT_PROC_STATE_SYNC_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    bgrt_proc_self_stop();

    //79,80,81,82
    status[1] = BGRT_ST_ESTAT;
    status[1] = bgrt_sync_wait( &bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 1 );
    bgrt_proc_self_stop();

    //91,92,93,94,95
    bgrt_proc_buff = BGRT_PID_NOTHING;
    status[1] = BGRT_ST_ESTAT;
    status[1] = bgrt_sync_wait( &bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 1 );
    status[2] = BGRT_ST_ESTAT;
    status[2] = bgrt_sync_wake( &bgrt_sync_1, (BGRT_PID_T)bgrt_proc_buff, 0);
    bgrt_proc_self_stop();

    //96,97
    bgrt_proc_buff = BGRT_PID_NOTHING;
    status[1] = BGRT_ST_ESTAT;
    status[1] = bgrt_sync_wait( &bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 0 );
    bgrt_proc_self_stop();

    //98,99,100
    status[1] = BGRT_ST_ESTAT;
    status[1] = bgrt_sync_wait( &bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 1 );
    bgrt_proc_self_stop();

    //106,107,108,109,110
    status[1] = BGRT_ST_ESTAT;
    status[1] = bgrt_sync_wake( &bgrt_sync_1, 0, 0);
    bgrt_proc_self_stop();

    //124,125,126,127
    bgrt_proc_buff = BGRT_PID_NOTHING;
    status[1] = BGRT_ST_ESTAT;
    status[1] = bgrt_sync_wait( &bgrt_sync_1, (BGRT_PID_T *)&bgrt_proc_buff, 1 );
    bgrt_sync_wake( &bgrt_sync_1, bgrt_proc_buff, 0);
    bgrt_proc_self_stop();
}

void main_2( void * arg )
{
    //69,70,71
    status[2] = BGRT_ST_ESTAT;
    status[2] = bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();
    //72,73,74,75,76,77,78
    status[2] = BGRT_ST_ESTAT;
    status[2] = bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();
    //79,80,81,82
    status[2] = BGRT_ST_ESTAT;
    status[2] = bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 );
    // 82,83,84,85,86
    bgrt_sync_touch( &bgrt_sync_1 );
    status[2] = BGRT_ST_ESTAT;
    status[1] = bgrt_sync_wake( &bgrt_sync_1, 0, 0 ); /// status[1] is used!!!
    status[3] = bgrt_sync_wake( &bgrt_sync_1, 0, 0 ); /// status[3] is used!!!
    //status[3] = (2 == bgrt_sync_1.pwake);        /// status[3] is used!!!
    status[2] = BGRT_ST_ESTAT;
    status[2] = bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)1 );
    bgrt_proc_self_stop();

    //91,92,93,94,95
    bgrt_sync_touch( &bgrt_sync_1 );
    bgrt_proc_run( PID1 );
    bgrt_wait_time(10);
    bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)1 );
    bgrt_proc_self_stop();

    //106,107,108,109,110
    bgrt_sync_touch( &bgrt_sync_1 );
    bgrt_proc_run( PID1 );
    bgrt_proc_self_stop();
    bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)1 );
    bgrt_proc_self_stop();

    //111,112,113
    bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();

    //114,115,116
    bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();

    //117,118,119
    bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();

    //122,123
    bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();

    //124,125,126,127
    bgrt_sync_touch( &bgrt_sync_1 );
    bgrt_proc_run( PID1 );
    bgrt_wait_time(10);
    bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)1 );
    bgrt_proc_self_stop();

    // priority inheritance/ceiling
    bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 );
    //bgrt_proc_self_stop();

    ///Additional tests
    //183, 184
    bgrt_sync_touch( &bgrt_sync_1 );
    bgrt_wait_time(10);
    status[2] = BGRT_ST_ESTAT;
    status[2] = bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)1 );
    bgrt_proc_self_stop();
    //185,186,187,188
    status[2] = BGRT_ST_ESTAT;
    status[2] = bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();
    //189,190,191,192,193,194
    status[2] = BGRT_ST_ESTAT;
    // bgrt_sync_1 must be dirty on sync_timeout_hook_1 call
    bgrt_sync_touch( &bgrt_sync_1 );
    status[2] = bgrt_sync_sleep( &bgrt_sync_1, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();
}

void main_3( void * arg )
{
    // priority inheritance/ceiling
    bgrt_sync_sleep( &bgrt_sync_2, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();
}

void main_4( void * arg )
{
    // priority inheritance/ceiling
    bgrt_sync_sleep( &bgrt_sync_3, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();
}

void main_5( void * arg )
{
    // priority inheritance/ceiling
    bgrt_sync_sleep( &bgrt_sync_2, (bgrt_flag_t)0 );
    bgrt_proc_self_stop();
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

    _bgrt_proc_init( PR0, main_0, SVH0, RSH0, 0, &bgrt_proc_stack[0][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 ARG_END );
    _bgrt_proc_init( PR1, main_1, SVH1, RSH1, 0, &bgrt_proc_stack[1][BGRT_PROC_STACK_SIZE-1], LOWEST, 1, 0 ARG_END );
    _bgrt_proc_init( PR2, main_2, SVH2, RSH2, 0, &bgrt_proc_stack[2][BGRT_PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    _bgrt_proc_init( PR3, main_3, SVH3, RSH3, 0, &bgrt_proc_stack[3][BGRT_PROC_STACK_SIZE-1], 3,      1, 0 ARG_END );
    _bgrt_proc_init( PR4, main_4, SVH4, RSH4, 0, &bgrt_proc_stack[4][BGRT_PROC_STACK_SIZE-1], 2,      1, 0 ARG_END );
    _bgrt_proc_init( PR5, main_5, SVH5, RSH5, 0, &bgrt_proc_stack[5][BGRT_PROC_STACK_SIZE-1], 1,      1, 0 ARG_END );

    _bgrt_sync_init( &bgrt_sync_1, LOWEST );
    _bgrt_sync_init( &bgrt_sync_2, LOWEST );
    _bgrt_sync_init( &bgrt_sync_3, LOWEST );
    _bgrt_sync_init( &bgrt_sync_4, 0 );

    _bgrt_proc_run( PR0 );

    bgrt_start();
    return 0;
}
