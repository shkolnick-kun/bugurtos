#include <test_func.h>

proc_t proc[6];
bgrt_stack_t proc_stack[6][PROC_STACK_SIZE];

sync_t sync_1, sync_2, sync_3, sync_4;
bgrt_bool_t test;
bgrt_st_t status[7];
proc_t * proc_buff = (proc_t *)0;
unsigned char test_num = 1;

void prio_propagate_hook_0(void)
{
    if( PROC_STATE_PI_PEND == PROC_GET_STATE( (&proc[1]) ) )
    {
        test_kernel_preempt = test_do_nothing;
        PROC_SET_STATE( (&proc[1]), PROC_STATE_PI_DONE );
    }
}

void prio_propagate_hook_1(void)
{
    if( PROC_STATE_PI_PEND == PROC_GET_STATE( (&proc[2]) ) )
    {
        test_kernel_preempt = test_do_nothing;
        status[6] = _sync_wake(&sync_1, &proc[2], 1 ); //chown
    }
}

void prio_propagate_hook_2(void)
{
    if( PROC_STATE_PI_PEND == PROC_GET_STATE( (&proc[2]) ) )
    {
        test_kernel_preempt = test_do_nothing;
        status[6] = _sync_wake(&sync_1, &proc[2], 0 );
    }
}

void main_0( void * arg )
{
    test_start();
    // 1 _proc_prio_propagate proc_set_prio
    proc_set_prio( &proc[1], 5 );
    test = ( 5 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 2 _proc_prio_propagate proc_set_prio
    test = ( 5 == proc[1].parent.prio);
    test_output( test, test_num++ );

    //3 _proc_prio_propagate proc_set_prio
    proc_set_prio( &proc[0], 6 );
    test = ( 6 == proc[0].base_prio);
    test_output( test, test_num++ );
    // 4 _proc_prio_propagate proc_set_prio
    test = ( 6 == proc[0].parent.prio );
    test_output( test, test_num++ );

    // 5 _proc_prio_propagate proc_set_prio
    status[1] = BGRT_ST_ESTAT;
    PROC_SET_STATE( (&proc[1]), PROC_STATE_SYNC_WAIT );
    proc_set_prio( &proc[1], 4 );
    bgrt_wait_time(5);
    test = ( 4 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 6 _proc_prio_propagate proc_set_prio
    test = ( 4 == proc[1].parent.prio);
    test_output( test, test_num++ );
    // 7 _proc_prio_propagate proc_set_prio
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );

    // 8 _proc_prio_propagate proc_set_prio
    status[1] = BGRT_ST_ESTAT;
    PROC_SET_STATE( (&proc[1]), PROC_STATE_SYNC_SLEEP );
    proc_set_prio( &proc[1], 5 );
    bgrt_wait_time(5);
    test = ( 5 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 9 _proc_prio_propagate proc_set_prio
    test = ( 5 == proc[1].parent.prio);
    test_output( test, test_num++ );
    // 10 _proc_prio_propagate proc_set_prio
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );

    // 11 _proc_prio_propagate proc_set_prio
    PROC_SET_STATE( (&proc[1]), PROC_STATE_SYNC_SLEEP );
    bgrt_prit_insert( (bgrt_prit_t *)(&proc[1]), (bgrt_xlist_t *)(&sync_1) );
    proc[1].sync = &sync_1;
    proc_set_prio( &proc[1], 4 );
    bgrt_wait_time(5);
    test = ( 4 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 12 _proc_prio_propagate proc_set_prio
    test = ( 4 == proc[1].parent.prio);
    test_output( test, test_num++ );
    // 13 _proc_prio_propagate proc_set_prio
    test = ( PROC_STATE_SYNC_SLEEP == PROC_GET_STATE((&proc[1])) );
    test_output( test, test_num++ );

    // 14 _proc_prio_propagate proc_set_prio
    status[1] = BGRT_ST_ESTAT;
    sync_1.owner = &proc[2];
    PROC_LRES_INC( (&proc[2]), SYNC_PRIO(&sync_1) );
    proc_set_prio( &proc[1], 5 );
    bgrt_wait_time(5);
    test = ( 5 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 15 _proc_prio_propagate proc_set_prio
    test = ( 5 == proc[1].parent.prio);
    test_output( test, test_num++ );
    // 16 _proc_prio_propagate proc_set_prio
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    // 17 _proc_prio_propagate proc_set_prio
    test = ( 1 == sync_1.dirty );
    test_output( test, test_num++ );
    // 18 _proc_prio_propagate proc_set_prio
    test = ( 1 == proc[2].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );

    // 19 _proc_prio_propagate proc_set_prio
    status[1] = BGRT_ST_ESTAT;

    PROC_SET_STATE( (&proc[1]), PROC_STATE_SYNC_SLEEP );
    proc[1].sync = &sync_1;
    sync_1.dirty = (bgrt_cnt_t)0;
    PROC_LRES_DEC( (&proc[2]), SYNC_PRIO(&sync_1) );
    bgrt_prit_insert( (bgrt_prit_t *)(&proc[1]), (bgrt_xlist_t *)(&sync_1) );
    PROC_LRES_INC( (&proc[2]), SYNC_PRIO(&sync_1) );

    kernel_preemt_hook_add( prio_propagate_hook_0 );

    proc_set_prio( &proc[1], 4 );
    bgrt_wait_time(5);
    test = ( 4 == proc[1].base_prio );
    test_output( test, test_num++ );
    // 20 _proc_prio_propagate proc_set_prio
    test = ( 4 == proc[1].parent.prio);
    test_output( test, test_num++ );
    // 21 _proc_prio_propagate proc_set_prio
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    // 22 _proc_prio_propagate proc_set_prio
    test = ( 1 == proc[2].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    /// _proc_prio_propagate covered!!!
    //cleanup
    PROC_LRES_DEC( (&proc[2]), SYNC_PRIO(&sync_1) );
    sync_1.owner = (proc_t *)0;
    // 23 sync_set_owner
    status[0] = sync_set_owner( (sync_t *)0, (proc_t *)0 );
    test = (BGRT_ST_ENULL == status[0]);
    test_output( test, test_num++ );

    // 24 sync_set_owner
    status[0] = sync_set_owner( &sync_1, &proc[1] );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 25 sync_set_owner
    test = ( (&proc[1]) == sync_1.owner );
    test_output( test, test_num++ );
    // 26 sync_set_owner
    test = ( 1 == proc[1].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );

    // 27 sync_set_owner
    status[0] = sync_set_owner( &sync_1, &proc[1] );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 28 sync_set_owner
    test = ( (&proc[1]) == sync_1.owner );
    test_output( test, test_num++ );
    // 29 sync_set_owner
    test = ( 1 == proc[1].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );

    // 30 sync_set_owner
    status[0] = sync_set_owner( &sync_1, &proc[2] );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 31 sync_set_owner
    test = ( (&proc[2]) == sync_1.owner );
    test_output( test, test_num++ );
    // 32 sync_set_owner
    test = ( 1 == proc[2].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 33 sync_set_owner
    test = ( 0 == proc[1].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );

    // 34 sync_set_owner
    status[0] = sync_set_owner( &sync_1, (proc_t *)0 );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 35 sync_set_owner
    test = ( ((proc_t *)0) == sync_1.owner );
    test_output( test, test_num++ );
    // 36 sync_set_owner
    test = ( 0 == proc[2].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    /// sync_set_owner covered !!!
    // 37 sync_own
    status[0] = sync_own( (sync_t *)0, (bgrt_flag_t)0 );
    test = (BGRT_ST_ENULL == status[0]);
    test_output( test, test_num++ );

    // 38 sync_own
    status[0] = sync_own( &sync_1, (bgrt_flag_t)0 );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 39 sync_own
    test = ( (&proc[0]) == sync_1.owner );
    test_output( test, test_num++ );
    // 40 sync_own
    test = ( 1 == proc[0].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 41 sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[0]) );
    test = ( PROC_STATE_RUNNING == PROC_GET_STATE((&proc[0])) );
    //BGRT_SPIN_FREE( (&proc[0]) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    // 42 sync_own
    status[0] = sync_own( &sync_1, (bgrt_flag_t)0 );
    test = (BGRT_ST_ROLL == status[0]);
    test_output( test, test_num++ );
    // 43 sync_own
    test = ( (&proc[0]) == sync_1.owner );
    test_output( test, test_num++ );
    // 44 sync_own
    test = ( 1 == proc[0].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 45 sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[0]) );
    test = ( PROC_STATE_RUNNING == PROC_GET_STATE((&proc[0])) );
    //BGRT_SPIN_FREE( (&proc[0]) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    // 46 sync_own
    sync_set_owner( &sync_1, (proc_t *)0 );
    status[0] = sync_own( &sync_1, (bgrt_flag_t)1 );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    // 47 sync_own
    test = ( (&proc[0]) == sync_1.owner );
    test_output( test, test_num++ );
    // 48 sync_own
    test = ( 1 == proc[0].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 49 sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[0]) );
    test = ( PROC_STATE_RUNNING == PROC_GET_STATE((&proc[0])) );
    //BGRT_SPIN_FREE( (&proc[0]) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    // 50 sync_own
    status[0] = sync_own( &sync_1, (bgrt_flag_t)1 );
    test = (BGRT_ST_ROLL == status[0]);
    test = test && ( 0 == sync_1.dirty );
    test_output( test, test_num++ );
    // 51 sync_own
    test = ( (&proc[0]) == sync_1.owner );
    test_output( test, test_num++ );
    // 52 sync_own
    test = ( 1 == proc[0].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 53 sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[0]) );
    test = ( PROC_STATE_RUNNING == PROC_GET_STATE((&proc[0])) );
    //BGRT_SPIN_FREE( (&proc[0]) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    // 54 sync_own
    sync_set_owner( &sync_1, (&proc[1]) );
    status[0] = sync_own( &sync_1, (bgrt_flag_t)0 );
    test = (BGRT_ST_ROLL == status[0]);
    test_output( test, test_num++ );
    // 55 sync_own
    test = ( (&proc[1]) == sync_1.owner );
    test_output( test, test_num++ );
    // 56 sync_own
    test = ( 1 == proc[1].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 57 sync_own
    test = ( 0 == proc[0].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 58 sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[0]) );
    test = ( PROC_STATE_RUNNING == PROC_GET_STATE((&proc[0])) );
    //BGRT_SPIN_FREE( (&proc[0]) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    // 59 sync_own
    status[0] = sync_own( &sync_1, (bgrt_flag_t)1 );
    test = (BGRT_ST_ROLL == status[0]);
    test_output( test, test_num++ );
    // 60 sync_own
    test = ( (&proc[1]) == sync_1.owner );
    test_output( test, test_num++ );
    // 61 sync_own
    test = ( 1 == proc[1].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 62 sync_own
    test = ( 0 == proc[0].lres.counter[PROC_PRIO_LOWEST] );
    test_output( test, test_num++ );
    // 63 sync_own
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[0]) );
    test = ( PROC_STATE_PI_RUNNING == PROC_GET_STATE((&proc[0])) );
    if(test)
    {
        PROC_SET_STATE( (&proc[0]), PROC_STATE_RUNNING );
        proc[0].sync = (sync_t *)0;
    }
    //BGRT_SPIN_FREE( (&proc[0]) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );
    /// sync_own covered!!!
    //cleanup
    sync_set_owner( &sync_1, (proc_t *)0 );
    sync_1.dirty = 0;

    //64 sync_touch
    status[0] = sync_touch( (sync_t *)0 );
    test = (BGRT_ST_ENULL == status[0]);
    test_output( test, test_num++ );
    //65 sync_touch
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[0]) );
    test = ( PROC_STATE_RUNNING == PROC_GET_STATE((&proc[0])) );
    //BGRT_SPIN_FREE( (&proc[0]) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );

    //66 sync_touch
    status[0] = sync_touch( &sync_1 );
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    //67 sync_touch
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[0]) );
    test = ( PROC_STATE_PI_RUNNING == PROC_GET_STATE((&proc[0])) );
    if(test)
    {
        PROC_SET_STATE( (&proc[0]), PROC_STATE_RUNNING );
        proc[0].sync = (sync_t *)0;
    }
    //BGRT_SPIN_FREE( (&proc[0]) );
    bgrt_enable_interrupts();
    test_output( test, test_num++ );
    /// sync_touch covered!!!
    //cleanup
    sync_1.dirty = 0;
    //68 sync_sleep
    test = ( BGRT_ST_ENULL == sync_sleep( (sync_t *)0 ) );
    test_output( test, test_num++ );
    //69 sync_sleep
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    test = ( PROC_STATE_SYNC_SLEEP == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    //70 sync_sleep sync_wake
    test = ( BGRT_ST_OK == sync_wake( &sync_1, 0, 0 ) );
    test_output( test, test_num++ );
    //71 sync_sleep
    bgrt_wait_time(5);
    test = ( BGRT_ST_OK == status[2] );
    test_output( test, test_num++ );

    //72 sync_sleep
    proc_set_prio( &proc[1], LOWEST );
    sync_set_owner( &sync_1, &proc[1] );
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    test = ( PROC_STATE_SYNC_SLEEP == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    //73 sync_sleep
    test = ( 4 == proc[1].parent.prio );
    test_output( test, test_num++ );

    //74 sync_sleep
    proc_set_prio( &proc[2], 5 );
    bgrt_wait_time(5);
    test = ( PROC_STATE_SYNC_SLEEP == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    //75 sync_sleep
    test = ( 5 == proc[1].parent.prio );
    test_output( test, test_num++ );

    //76 sync_sleep sync_proc_timeout
    status[0] = sync_proc_timeout( &proc[2] );
    bgrt_wait_time(5);
    test = (BGRT_ST_OK == status[0]);
    test = test && ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    //77 sync_sleep sync_proc_timeout
    test = ( BGRT_ST_ETIMEOUT == status[2] );
    test_output( test, test_num++ );
    //78 sync_sleep sync_proc_timeout
    test = ( LOWEST == proc[1].parent.prio );
    test_output( test, test_num++ );

    //79 sync_sleep sync_wait
    proc_set_prio( &proc[2], LOWEST );
    proc_run( &proc[1] );
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    test = ( PROC_STATE_SYNC_SLEEP == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    //80 sync_sleep sync_wait
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    //81 sync_sleep sync_wait
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[1])) );
    test_output( test, test_num++ );

    //82 sync_sleep sync_wake
    sync_set_owner( &sync_1, (proc_t *)0 );
    status[0] = sync_wake( &sync_1, 0, 0 );
    bgrt_wait_time(5);
    test = (BGRT_ST_OK == status[0]);
    test_output( test, test_num++ );
    //83 sync_sleep sync_wake
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    //84 sync_sleep sync_wake
    test = ( status[3] );
    test_output( test, test_num++ );
    //85 sync_sleep
    test = ( BGRT_ST_OK == status[2] );
    test_output( test, test_num++ );
    //86 sync_sleep
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    //cleanup
    proc_set_prio( &proc[2], 4 );
    //87 sync_sleep
    sync_own( &sync_1, (bgrt_flag_t)0 );
    test = ( BGRT_ST_EOWN == sync_sleep( &sync_1 ) );
    test_output( test, test_num++ );
    /// sync_sleep covered!!!

    //88 sync_wait
    sync_set_owner( &sync_1, &proc[1] );
    test = ( BGRT_ST_EOWN == sync_wait( &sync_1, &proc_buff, 0 ) );
    test_output( test, test_num++ );
    //89 sync_wait
    test = ( BGRT_ST_ENULL == sync_wait( (sync_t *)0, &proc_buff, 0 ) );
    test_output( test, test_num++ );
    //90 sync_wait
    test = ( BGRT_ST_ENULL == sync_wait( &sync_1, (proc_t **)0, 0 ) );
    test_output( test, test_num++ );

    //91 sync_wait sync_wake
    //sync_touch( &sync_1 );
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    test = ( PROC_STATE_SYNC_SLEEP == PROC_GET_STATE((&proc[1])) );
    test_output( test, test_num++ );
    //92 sync_wait sync_wake
    bgrt_wait_time(20);
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    //93 sync_wait sync_wake
    test = ( BGRT_ST_OK == status[2] );
    test_output( test, test_num++ );
    //94 sync_wait sync_wake
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[1])) );
    test_output( test, test_num++ );
    //95 sync_wait sync_wake
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );

    //96 sync_wait
    proc_run( &proc[1] );
    bgrt_wait_time(5);
    test = ( BGRT_ST_EEMPTY == status[1] );
    test_output( test, test_num++ );
    //97 sync_wait
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[1])) );
    test_output( test, test_num++ );

    //97 sync_wait
    proc_run( &proc[1] );
    bgrt_wait_time(5);
    test = ( PROC_STATE_SYNC_WAIT == PROC_GET_STATE((&proc[1])) );
    test_output( test, test_num++ );
    //98 sync_wait sync_proc_timeout
    status[0] = sync_proc_timeout( &proc[1] );
    test = ( BGRT_ST_OK == status[0] );
    test_output( test, test_num++ );
    //99 sync_wait sync_proc_timeout
    bgrt_wait_time(5);
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[1])) );
    test_output( test, test_num++ );
    //100 sync_wait sync_proc_timeout
    test = ( BGRT_ST_ETIMEOUT == status[1] );
    test_output( test, test_num++ );
    /// sync_wait covered!!!

    //101 sync_wake
    test = ( BGRT_ST_ENULL == sync_wake( (sync_t *)0, (proc_t *)0, 0) );
    test_output( test, test_num++ );

    //103 sync_wake
    test = ( BGRT_ST_EOWN == sync_wake( &sync_1, (proc_t *)0, 0) );
    test_output( test, test_num++ );

    //104 sync_wake
    sync_set_owner( &sync_1, &proc[0] );
    test = ( BGRT_ST_EEMPTY == sync_wake( &sync_1, (proc_t *)0, 0) );
    test_output( test, test_num++ );

    //105 sync_wake
    test = ( BGRT_ST_ESYNC == sync_wake( &sync_1, &proc[2], 0) );
    test_output( test, test_num++ );

    //106 sync_wake
    sync_set_owner( &sync_1, &proc[1] );
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    test = ( PROC_STATE_SYNC_SLEEP == PROC_GET_STATE((&proc[1])) );
    test_output( test, test_num++ );
    //107 sync_wake
    test = ( (sync_t *)0 == proc[1].sync );
    test_output( test, test_num++ );
    //108 sync_wake
    bgrt_wait_time(20);
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[1])) );
    test_output( test, test_num++ );
    //109 sync_wake
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    //110 sync_wake
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );

    //111 sync_wake
    sync_set_owner( &sync_1, &proc[0] );
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    status[6] = BGRT_ST_ESTAT;
    kernel_preemt_hook_add( prio_propagate_hook_1 );
    proc_set_prio( &proc[2], 4 );
    bgrt_wait_time(5);
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    //112 sync_wake
    test = ( BGRT_ST_OK == status[6] );
    test_output( test, test_num++ );
    //113 sync_wake
    test = ( &proc[2] == sync_1.owner );
    test_output( test, test_num++ );

    //114 sync_wake
    sync_set_owner( &sync_1, &proc[0] );
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    status[6] = BGRT_ST_ESTAT;
    kernel_preemt_hook_add( prio_propagate_hook_2 );
    proc_set_prio( &proc[2], 4 );
    bgrt_wait_time(5);
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    //115 sync_wake
    test = ( BGRT_ST_OK == status[6] );
    test_output( test, test_num++ );
    //116 sync_wake
    test = ( &proc[0] == sync_1.owner );
    test_output( test, test_num++ );

    //117 sync_wake
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    status[0] = sync_wake( &sync_1, (proc_t *)0, 1 );
    bgrt_wait_time(5);
    test = ( BGRT_ST_OK == status[0] );
    test_output( test, test_num++ );
    //118 sync_wake
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    //119 sync_wake
    test = ( &proc[2] == sync_1.owner );
    test_output( test, test_num++ );
    /// sync_wait and _sync_do_wake covered!!!

    //120 sync_proc_timeout
    test = ( BGRT_ST_ENULL == sync_proc_timeout( (proc_t *)0 ) );
    test_output( test, test_num++ );
    //121 sync_proc_timeout
    test = ( BGRT_ST_ESYNC == sync_proc_timeout( &proc[0] ) );
    test_output( test, test_num++ );

    //122 sync_proc_timeout
    sync_set_owner( &sync_1, (proc_t *)0 );
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    test = ( BGRT_ST_OK == sync_proc_timeout( &proc[2] ) );
    test_output( test, test_num++ );
    //123 sync_proc_timeout
    bgrt_wait_time(5);
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );

    //124 sync_proc_timeout
    sync_set_owner( &sync_1, &proc[1] );
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    status[0] = sync_proc_timeout( &proc[1] );
    test = ( BGRT_ST_OK == status[0] );
    test_output( test, test_num++ );
    //125 sync_proc_timeout
    status[0] =  sync_proc_timeout( &proc[2] );
    test = ( BGRT_ST_ROLL == status[0] );
    test_output( test, test_num++ );
    //126 sync_proc_timeout
    bgrt_wait_time(20);
    test = ( BGRT_ST_OK == status[1] );
    test_output( test, test_num++ );
    //127 sync_proc_timeout
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[1])) );
    test_output( test, test_num++ );
    //128 sync_proc_timeout
    test = ( PROC_STATE_STOPED == PROC_GET_STATE((&proc[2])) );
    test_output( test, test_num++ );
    /// sync_proc_timeout tested but not covered!!!

    // 129 priority inheritance/ceiling
    sync_set_owner( &sync_2, &proc[2] );
    sync_set_owner( &sync_3, &proc[3] );
    proc_run( &proc[2] );
    bgrt_wait_time(5);
    test = ( 4 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 130 priority inheritance/ceiling
    proc_run( &proc[3] );
    bgrt_wait_time(5);
    test = ( 3 == proc[2].parent.prio);
    test_output( test, test_num++ );
    // 131 priority inheritance/ceiling
    test = ( 3 == proc[1].parent.prio);
    test_output( test, test_num++ );

    // 132 priority inheritance/ceiling
    proc_run( &proc[4] );
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
    proc_run( &proc[5] );
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
    proc_set_prio( &proc[5], 0 );
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
    proc_set_prio( &proc[5], 1 );
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
    proc_set_prio( &proc[2], 0 );
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
    proc_set_prio( &proc[2], 1 );
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
    proc_set_prio( &proc[2], 4 );
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
    proc_set_prio( &proc[4], 4 );
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
    proc_set_prio( &proc[4], 2 );
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
    proc_set_prio( &proc[5], LOWEST );
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
    sync_set_owner( &sync_4, &proc[5] );
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

    tests_end();
}

void main_1( void * arg )
{
    bgrt_flag_t state;
    // 5,6,7
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[1]) );
    state = PROC_GET_STATE((&proc[1]));
    //BGRT_SPIN_FREE( (&proc[1]) );
    bgrt_enable_interrupts();
    status[1] = (PROC_STATE_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    proc_self_stop();
    // 8,9,10
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[1]) );
    state = PROC_GET_STATE((&proc[1]));
    //BGRT_SPIN_FREE( (&proc[1]) );
    bgrt_enable_interrupts();
    status[1] = (PROC_STATE_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    proc_self_stop();
    // 14,15,16,17,18
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[1]) );
    state = PROC_GET_STATE((&proc[1]));
    //BGRT_SPIN_FREE( (&proc[1]) );
    bgrt_enable_interrupts();
    status[1] = (PROC_STATE_PI_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    proc_self_stop();
    // 19,20,21,22,23
    bgrt_disable_interrupts();
    //BGRT_SPIN_LOCK( (&proc[1]) );
    state = PROC_GET_STATE((&proc[1]));
    //BGRT_SPIN_FREE( (&proc[1]) );
    bgrt_enable_interrupts();
    status[1] = (PROC_STATE_SYNC_RUNNING == state)?BGRT_ST_OK:BGRT_ST_ESTAT;
    proc_self_stop();

    //79,80,81,82
    status[1] = BGRT_ST_ESTAT;
    status[1] = sync_wait( &sync_1, &proc_buff, 1 );
    proc_self_stop();

    //91,92,93,94,95
    proc_buff = (proc_t *)0;
    status[1] = BGRT_ST_ESTAT;
    status[1] = sync_wait( &sync_1, &proc_buff, 1 );
    status[2] = BGRT_ST_ESTAT;
    status[2] = sync_wake( &sync_1, proc_buff, 0);
    proc_self_stop();

    //96,97
    proc_buff = (proc_t *)0;
    status[1] = BGRT_ST_ESTAT;
    status[1] = sync_wait( &sync_1, &proc_buff, 0 );
    proc_self_stop();

    //98,99,100
    status[1] = BGRT_ST_ESTAT;
    status[1] = sync_wait( &sync_1, &proc_buff, 1 );
    proc_self_stop();

    //106,107,108,109,110
    status[1] = BGRT_ST_ESTAT;
    status[1] = sync_wake( &sync_1, 0, 0);
    proc_self_stop();

    //124,125,126,127
    proc_buff = (proc_t *)0;
    status[1] = BGRT_ST_ESTAT;
    status[1] = sync_wait( &sync_1, &proc_buff, 1 );
    sync_wake( &sync_1, proc_buff, 0);
    proc_self_stop();
}

void main_2( void * arg )
{
    //69,70,71
    status[2] = BGRT_ST_ESTAT;
    status[2] = sync_sleep( &sync_1 );
    proc_self_stop();
    //72,73,74,75,76,77,78
    status[2] = BGRT_ST_ESTAT;
    status[2] = sync_sleep( &sync_1 );
    proc_self_stop();
    //79,80,81,82
    status[2] = BGRT_ST_ESTAT;
    status[2] = sync_sleep( &sync_1 );
    // 82,83,84,85,86
    sync_touch( &sync_1 );
    status[2] = BGRT_ST_ESTAT;
    status[1] = sync_wake( &sync_1, 0, 0 ); /// staus[1] is used!!!
    sync_wake( &sync_1, 0, 0 );
    status[3] = (2 == sync_1.pwake);        /// staus[3] is used!!!
    status[2] = BGRT_ST_ESTAT;
    status[2] = sync_sleep( &sync_1 );
    proc_self_stop();

    //91,92,93,94,95
    sync_touch( &sync_1 );
    proc_run( &proc[1] );
    bgrt_wait_time(10);
    sync_sleep( &sync_1 );
    proc_self_stop();

    //106,107,108,109,110
    sync_touch( &sync_1 );
    proc_run( &proc[1] );
    bgrt_wait_time(10);
    sync_sleep( &sync_1 );
    proc_self_stop();

    //111,112,113
    sync_sleep( &sync_1 );
    proc_self_stop();

    //114,115,116
    sync_sleep( &sync_1 );
    proc_self_stop();

    //117,118,119
    sync_sleep( &sync_1 );
    proc_self_stop();

    //122,123
    sync_sleep( &sync_1 );
    proc_self_stop();

    //124,125,126,127
    sync_touch( &sync_1 );
    proc_run( &proc[1] );
    bgrt_wait_time(10);
    sync_sleep( &sync_1 );
    proc_self_stop();

    // priority inheritance/ceiling
    sync_sleep( &sync_1 );
    proc_self_stop();
}

void main_3( void * arg )
{
    // priority inheritance/ceiling
    sync_sleep( &sync_2 );
    proc_self_stop();
}

void main_4( void * arg )
{
    // priority inheritance/ceiling
    sync_sleep( &sync_3 );
    proc_self_stop();
}

void main_5( void * arg )
{
    // priority inheritance/ceiling
    sync_sleep( &sync_2 );
    proc_self_stop();
}

void bgrt_idle_main( void * arg )
{
    while(1)
    {
        bgrt_wait_time(5);
        // Run local/global load balancer on multicore system with local/global lazy load balancing.
        BGRT_SCHED_IDLE_LOAD_BALANCER();
    }
}
int main(void)
{
    /**************************************************
    *          For test purposes only!!!              *
    *  It is strongly recomended to initiate hardware *
    *         AFTER bgrt_init() call!!!             *
    **************************************************/
    /*
     * This function disables interrupts
     * and initiates hardware.
     */
    init_hardware();
    bgrt_init();

    BGRT_SCHED_SYSTICK_HOOK_ADD();

    proc_init_isr( &proc[0], main_0, SVH0, RSH0, 0, &proc_stack[0][PROC_STACK_SIZE-1], LOWEST, 1, 0 ARG_END );
    proc_init_isr( &proc[1], main_1, SVH1, RSH1, 0, &proc_stack[1][PROC_STACK_SIZE-1], LOWEST, 1, 0 ARG_END );
    proc_init_isr( &proc[2], main_2, SVH2, RSH2, 0, &proc_stack[2][PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    proc_init_isr( &proc[3], main_3, SVH3, RSH3, 0, &proc_stack[3][PROC_STACK_SIZE-1], 3,      1, 0 ARG_END );
    proc_init_isr( &proc[4], main_4, SVH4, RSH4, 0, &proc_stack[4][PROC_STACK_SIZE-1], 2,      1, 0 ARG_END );
    proc_init_isr( &proc[5], main_5, SVH5, RSH5, 0, &proc_stack[5][PROC_STACK_SIZE-1], 1,      1, 0 ARG_END );

    sync_init_isr( &sync_1, LOWEST );
    sync_init_isr( &sync_2, LOWEST );
    sync_init_isr( &sync_3, LOWEST );
    sync_init_isr( &sync_4, 0 );

    proc_run_isr( &proc[0] );

    bgrt_start();
    return 0;
}
