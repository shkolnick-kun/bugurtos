#include <test_func.h>

proc_t proc[6];
stack_t proc_stack[6][PROC_STACK_SIZE];

sync_t sync_1, sync_2, sync_3, sync_4;
bool_t test;
flag_t status;
proc_t * proc_buff = (proc_t *)0;
unsigned char test_num = 1;

void prio_propagate_hook_0(void)
{
    if( PROC_GET_STATE( (&proc[3]) ) == PROC_STATE_PI_PEND )
    {
        test_kernel_preempt = test_do_nothing;
        status = _sync_wake(&sync_2, &proc[3], 0 );
        test = (status == BGRT_ST_OK);
        test_output( test, test_num++ );
    }
}

void prio_propagate_hook_2(void)
{
    if( PROC_GET_STATE( (&proc[3]) ) == PROC_STATE_PI_PEND )
    {
        test_kernel_preempt = test_do_nothing;
        status = _sync_wake(&sync_2, &proc[3], 1 ); //chown
        test = (status == BGRT_ST_OK);
        test_output( test, test_num++ );
    }
}

void main_0( void * arg )
{
    test_start();
    // 1 _proc_prio_propagate proc_set_prio
    proc_set_prio( &proc[1], 6 );
    test = (proc[1].base_prio == 6);
    test_output( test, test_num++ );
    // 2 _proc_prio_propagate proc_set_prio
    test = (proc[1].parent.prio == 6);
    test_output( test, test_num++ );
    //3 _proc_prio_propagate proc_set_prio
    proc_set_prio( &proc[0], 6 );
    test = (proc[0].base_prio == 6);
    test_output( test, test_num++ );
    // 4 _proc_prio_propagate proc_set_prio
    test = (proc[0].parent.prio == 6);
    test_output( test, test_num++ );
    // 5 _proc_prio_propagate sync_set_owner
    sync_set_owner( &sync_1, &proc[1] );//proc[1] must be an owner of sync_1
    test = ( & proc[1] == sync_1.owner );
    //test = ((proc[1].flags & PROC_FLG_LOCK) == PROC_FLG_LOCK );
    test_output( test, test_num++ );
    // 6 _proc_prio_propagate sync_set_owner
    test = (sync_1.owner == &proc[1] );
    test_output( test, test_num++ );
    // 7 bsynk_wake
    sync_1.dirty = 1;
    proc_run( &proc[1] ); // Must sleep on dirty sync
    wait_time(5);
    test = (PROC_GET_STATE((&proc[1])) == PROC_STATE_SYNC_SLEEP);
    test_output( test, test_num++ );
    // 8 _proc_prio_propagate proc_set_prio
    sync_1.dirty = 0;
    proc_set_prio( &proc[1], 5 ); //Must run and self stop
    wait_time(5);
    test = (proc[1].base_prio == 5);
    test_output( test, test_num++ );
    // 9 _proc_prio_propagate proc_set_prio
    test = (proc[1].parent.prio == 5);
    test_output( test, test_num++ );
    // 10 sync_wake
    test = ( BGRT_ST_EOWN == sync_wake( &sync_1, (proc_t *)0, 0 ) ); // Must fail on ownership!
    test_output( test, test_num++ );
    // 11 sync_sleep proc_set_prio _proc_prio_propagate
    proc_run( &proc[3] );
    wait_time(5);
    test = (PROC_GET_STATE((&proc[3]))== PROC_STATE_SYNC_SLEEP);
    test_output( test, test_num++ );
    //12 sync_sleep proc_set_prio _proc_prio_propagate
    proc_set_prio( &proc[3], LOWEST );
    wait_time(5);
    test = (PROC_GET_STATE((&proc[3]))== PROC_STATE_SYNC_SLEEP);
    test_output( test, test_num++ );
    //13 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[3].sync == &sync_2);
    test_output( test, test_num++ );
    //14 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[3].base_prio == LOWEST);
    test_output( test, test_num++ );
    //15 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[3].parent.prio == LOWEST);
    test_output( test, test_num++ );
    //16 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[3].parent.list == &sync_2.sleep);
    test_output( test, test_num++ );
    //17 sync_sleep proc_set_prio _proc_prio_propagate
    sync_set_owner( &sync_2, &proc[2] );
    wait_time(5);
    //test = ((proc[2].flags & PROC_FLG_LOCK) == PROC_FLG_LOCK );
    test = ( &proc[2] == sync_2.owner );
    test_output( test, test_num++ );
    //18 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[2].lres.index == (1<<LOWEST));
    test_output( test, test_num++ );
    //19 sync_sleep proc_set_prio _proc_prio_propagate

    proc_set_prio( &proc[3], 3 );
    wait_time(5);
    test = ( proc[2].lres.index == (1<<3));
    test_output( test, test_num++ );
    //20 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[3].base_prio == 3);
    test_output( test, test_num++ );
    //21 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[3].parent.prio == 3);
    test_output( test, test_num++ );
    //22 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[2].parent.prio == 3);
    test_output( test, test_num++ );
    //23 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[3].sync == &sync_2);
    test_output( test, test_num++ );
    //24 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[3].parent.list == &sync_2.sleep);
    test_output( test, test_num++ );
    //25 sync_sleep proc_set_prio _proc_prio_propagate

    sync_clear_owner( &sync_2 );
    test = (sync_2.owner == (proc_t *)0 );
    test_output( test, test_num++ );
    //26 sync_sleep proc_set_prio _proc_prio_propagate
    //test = ((proc[2].flags & PROC_FLG_LOCK) != PROC_FLG_LOCK );

    test_output( test, test_num++ );
    //27 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[2].lres.index == 0);
    test_output( test, test_num++ );
    //28 sync_sleep proc_set_prio _proc_prio_propagate
    test = ( proc[2].parent.prio == 4);
    test_output( test, test_num++ );
    //29 sync_clear_owner
    sync_clear_owner( &sync_2 );
    test = (sync_2.owner == (proc_t *)0 );
    test_output( test, test_num++ );
    //30 sync_clear_owner
    sync_clear_owner((sync_t *)0);
    test_num++;
    /// sync_clear_owner covered!!!
    //31 (watch prio_propagate_hook_0 ) _proc_prio_propagate _sync_wake
    kernel_preemt_hook_add( prio_propagate_hook_0 );
    proc_set_prio( &proc[3], LOWEST );
    wait_time(5);
    //32 _proc_prio_propagate _sync_wake
    test = (PROC_GET_STATE((&proc[3]))== PROC_STATE_STOPED);
    test_output( test, test_num++ );
    //33 _sync_wait _proc_prio_propagate
    status = BGRT_ST_OK;
    proc_run( &proc[2] ); //Must fail on ownership;
    wait_time(5);
    test = (status == BGRT_ST_EOWN);
    test_output( test, test_num++ );
    //34 _sync_wait _proc_prio_propagate
    sync_set_owner( &sync_2, &proc[2] );
    proc_run( &proc[2] ); //Must wait for sleeping process;
    wait_time(5);
    test = (PROC_GET_STATE((&proc[2]))== PROC_STATE_SYNC_WAIT);
    test_output( test, test_num++ );
    //35 _proc_prio_propagate
    proc_set_prio( &proc[2], LOWEST );
    test = ( proc[2].base_prio == LOWEST);
    test_output( test, test_num++ );
    //36 _proc_prio_propagate
    test = ( proc[2].parent.prio == LOWEST);
    test_output( test, test_num++ );

    /// _proc_prio_propagate covered!!!
    proc_set_prio( &proc[2], 4 );
    //37
    proc_run( &proc[3] ); //Must launch proc[2] and sleep.
    wait_time(5);
    test = (PROC_GET_STATE((&proc[3]))== PROC_STATE_SYNC_SLEEP);
    test_output( test, test_num++ );
    //38
    test = (PROC_GET_STATE((&proc[2]))== PROC_STATE_STOPED);
    test_output( test, test_num++ );
    //39 _proc_prio_propagate
    test = ( proc[2].parent.prio == 3);
    test_output( test, test_num++ );
    /// proc_set_prio_covered!!!
    //40
    sync_clear_owner( &sync_2 );
    test_output( BGRT_ST_ENULL == sync_set_owner( (sync_t *)0, (proc_t *)0 ), test_num++); //Must not set
    //41
    sync_set_owner( &sync_2, (proc_t *)0 );//Must set!
    test = (sync_2.owner == &proc[0]);
    test_output( test, test_num++ );
    //42
    //test = ((proc[0].flags & PROC_FLG_LOCK) == PROC_FLG_LOCK );
    test_output( test, test_num++ );
    //43
    //test = ((proc[2].flags & PROC_FLG_LOCK) != PROC_FLG_LOCK );
    test_output( test, test_num++ );
    //44
    sync_set_owner( &sync_2, &proc[2] );//Must NOT set!
    test = (sync_2.owner == &proc[0]);
    test_output( test, test_num++ );
    //45
    //test = ((proc[0].flags & PROC_FLG_LOCK) == PROC_FLG_LOCK );
    test_output( test, test_num++ );
    //46
    //test = ((proc[2].flags & PROC_FLG_LOCK) != PROC_FLG_LOCK );
    test_output( test, test_num++ );
    //47
    sync_clear_owner( &sync_2 );
    sync_set_owner( &sync_2, &proc[2] );//Cleanup
    test = (sync_get_owner( &sync_2 ) == &proc[2]);
    test_output( test, test_num++ );
    //48
    //test = ((proc[2].flags & PROC_FLG_LOCK) == PROC_FLG_LOCK );
    test_output( test, test_num++ );
    //49
    //test = ((proc[0].flags & PROC_FLG_LOCK) != PROC_FLG_LOCK );
    test_output( test, test_num++ );
    /// sync_set_owner + sync_get_owner covered!!!
    //50 sync_sleep sync_wake
    proc_run( &proc[2] );
    wait_time(5);
    test = (status == BGRT_ST_EOWN);
    test_output( test, test_num++ );
    //51 sync_sleep sync_wake
    proc_run( &proc[2] );
    wait_time(5);
    test = (status == BGRT_ST_ENULL);
    test_output( test, test_num++ );
    //52 sync_sleep sync_wake
    proc_run( &proc[2] ); //Must wake proc[3];
    wait_time(5);
    test = (status == BGRT_ST_OK);
    test_output( test, test_num++ );
    //53 sync_sleep sync_wake
    test = (PROC_GET_STATE( (&proc[3]) ) == PROC_STATE_STOPED );
    test_output( test, test_num++ );
    //54 sync_sleep sync_wake
    proc_run( &proc[5] );
    wait_time(5);
    proc_run( &proc[3] );
    wait_time(5);
    test = (PROC_GET_STATE( (&proc[3]) ) == PROC_STATE_SYNC_SLEEP );
    test_output( test, test_num++ );
    //55 sync_sleep sync_wake
    test = (PROC_GET_STATE( (&proc[5]) ) == PROC_STATE_SYNC_SLEEP );
    test_output( test, test_num++ );
    //56 sync_sleep sync_wake
    test = ( proc[2].parent.prio == 1 );
    test_output( test, test_num++ );
    /// sync_sleep covered!!!
    //57 sync_wake
    status = sync_wake( (sync_t *)0, (proc_t *)0, 0 ); // Must fail on zero pointer
    test = (status == BGRT_ST_ENULL);
    test_output( test, test_num++ );
    //58 sync_wake
    proc_run( &proc[2] ); //proc[2] must fail, calling sync_wake
    wait_time(5);
    test = (status == BGRT_ST_ESYNC);
    test_output( test, test_num++ );
    //59 Priority inheritance protocol!!!
    proc_run( &proc[2] );
    wait_time(5);
    test = ( PROC_GET_STATE( (&proc[2]) ) == PROC_STATE_SYNC_SLEEP );
    test_output( test, test_num++ );
    //60 Priority inheritance protocol!!!
    test = ( proc[1].parent.prio == 1 );
    test_output( test, test_num++ );
    //61 Priority inheritance protocol!!!
    proc_set_prio( &proc[5], LOWEST );
    wait_time(5);
    test = ( proc[1].parent.prio == 3 );
    test_output( test, test_num++ );
    //62 Priority inheritance protocol!!!
    proc_run( &proc[4] );
    wait_time(5);
    test = ( proc[1].parent.prio == 3 );
    test_output( test, test_num++ );
    //63 Priority inheritance protocol!!!
    sync_set_owner( &sync_3, &proc[3] );
    wait_time(5);
    test = ( proc[1].parent.prio == 2 );
    test_output( test, test_num++ );
    //64 Priority inheritance protocol!!!
    proc_set_prio( &proc[4], LOWEST );
    wait_time(5);
    test = ( proc[1].parent.prio == 3 );
    test_output( test, test_num++ );
    //65 Priority inheritance protocol!!!
    proc_set_prio( &proc[4], 2 );
    wait_time(5);
    test = ( proc[1].parent.prio == 2 );
    test_output( test, test_num++ );
    //66 Priority inheritance protocol!!!
    proc_set_prio( &proc[5], 1 );
    wait_time(5);
    test = ( proc[1].parent.prio == 1 );
    test_output( test, test_num++ );
    //67
    proc_run( &proc[1] );
    wait_time(5);
    test = ( proc[1].parent.prio == 5 );
    test_output( test, test_num++ );
    //68
    test = ( proc[2].parent.prio == 1 );
    test_output( test, test_num++ );
    //69
    test = ( PROC_GET_STATE( (&proc[2]) ) == PROC_STATE_STOPED );
    test_output( test, test_num++ );
    //70
    sync_clear_owner( &sync_3 );
    wait_time(5);
    test = ( proc[2].parent.prio == 1 );
    test_output( test, test_num++ );
    //71
    test = ( proc[3].parent.prio == 3 );
    test_output( test, test_num++ );
    ///Priority inheritance protocol covered!!!
    //72
    //proc[2].flags |= PROC_FLG_PRE_STOP;
    proc_run( &proc[2] );
    wait_time(5);
    //73
    //Must self stop after proc_set_prio call
    test = ( PROC_GET_STATE( (&proc[2]) ) == PROC_STATE_STOPED );
    test_output( test, test_num++ );
    //74
    test = ( PROC_GET_STATE( (&proc[3]) ) == PROC_STATE_STOPED );
    test_output( test, test_num++ );
    //75
    test = ( proc[3].base_prio = LOWEST );
    test_output( test, test_num++ );
    //76
    test = ( proc[3].parent.prio = 1 );
    test_output( test, test_num++ );
    //77
    test = (sync_2.owner == &proc[3]);
    test_output( test, test_num++ );
    //78
    proc_run( &proc[3] );//Must chown sync_2 to proc[5];
    wait_time(5);
    test = ( status == BGRT_ST_OK );
    test_output( test, test_num++ );
    //79
    test = ( PROC_GET_STATE( (&proc[3]) ) == PROC_STATE_STOPED );
    test_output( test, test_num++ );
    //80
    test = ( PROC_GET_STATE( (&proc[5]) ) == PROC_STATE_STOPED );
    test_output( test, test_num++ );
    //81
    test = ( proc[3].base_prio = LOWEST );
    test_output( test, test_num++ );
    //82
    test = ( proc[3].parent.prio = LOWEST );
    test_output( test, test_num++ );
    //83
    test = (sync_2.owner == &proc[5]);
    test_output( test, test_num++ );
    //84
    proc_run( &proc[5] );
    wait_time(5);
    test = ( status == BGRT_ST_EEMPTY ); // No process to wake.
    test_output( test, test_num++ );
    //85
    test = (sync_2.owner == (proc_t *)0);
    test_output( test, test_num++ );
    /// sync_wake covered!!!
    //86
    status = sync_wait( (sync_t *)0, (proc_t **)0, 0 ); //Must fail.
    test = ( status == BGRT_ST_ENULL );
    test_output( test, test_num++ );
    //87
    status = sync_wait( (sync_t *)0, &proc_buff, 0 ); //Must fail.
    test = ( status == BGRT_ST_ENULL );
    test_output( test, test_num++ );
    //88
    sync_1.dirty = 1;
    proc_run( &proc[1] );
    wait_time(5);
    test = ( PROC_GET_STATE( (&proc[1]) ) == PROC_STATE_SYNC_SLEEP );
    test_output( test, test_num++ );
    ///sync_wait covered!!!
    //89
    sync_set_owner(&sync_3, (proc_t *)0);
    wait_time(5);
    sync_set_owner(&sync_4, &proc[4]);
    wait_time(5);
    test = ( proc[0].parent.prio == 0);
    test_output( test, test_num++ );
    //90
    test = ( proc[4].parent.prio == 0);
    test_output( test, test_num++ );
    ///Priority ceiling protocol covered.
    //91
    test = (BGRT_ST_OK == sync_proc_timeout( &proc[1] ));
    test_output( test, test_num++ );
    //92
    sync_1.dirty = 0;
    proc_set_prio( &proc[1], proc[1].base_prio );
    wait_time(5);
    test = (BGRT_ST_ESYNC == sync_proc_timeout( &proc[1] ));
    test_output( test, test_num++ );
    //93
    proc_run( &proc[1] );
    wait_time(5);
    test = (BGRT_ST_OK == sync_proc_timeout( &proc[1] ));
    test_output( test, test_num++ );
    //94
    wait_time(5);
    test = (BGRT_ST_ETIMEOUT == status);
    test_output( test, test_num++ );
    //95
    PROC_SET_STATE( (&proc[4]), PROC_STATE_PI_PEND );
    test = (BGRT_ST_ROLL == sync_proc_timeout( &proc[4] ));
    test_output( test, test_num++ );
    //96
    PROC_SET_STATE( (&proc[4]), PROC_STATE_STOPED );
    test = (BGRT_ST_OK == sync_proc_timeout( &proc[4] ));
    test_output( test, test_num++ );
    //97
    PROC_SET_STATE( (&proc[4]), PROC_STATE_SYNC_SLEEP );
    test = (BGRT_ST_OK == sync_proc_timeout( &proc[4] ));
    test_output( test, test_num++ );
    //98
    wait_time(5);
    test = (BGRT_ST_ETIMEOUT == status);
    test_output( test, test_num++ );
    //99
    /// sync_proc_timeout covered
    tests_end();
}

void main_1( void * arg )
{
    sync_wake( &sync_1, (proc_t *)0, 0 );
    proc_self_stop();

    sync_wake( &sync_1, (proc_t *)0, 0 );
    proc_self_stop();

    status = sync_wait( &sync_1, &proc_buff, 0 );
    proc_self_stop();

    status = sync_wait( &sync_1, &proc_buff, 1 );
    proc_self_stop();
}

void main_2( void * arg )
{
    status = sync_wait( &sync_2, &proc_buff, 1 );  //Must fail on ownership.
    proc_self_stop();

    status = sync_wait( &sync_2, &proc_buff, 1 );  //Must wait
    proc_self_stop();

    status = sync_sleep( &sync_2 ); //Must fail.
    proc_self_stop();

    status = sync_sleep( (sync_t *)0 ); //Must fail.
    proc_self_stop();

    status = sync_wake( &sync_2, proc_buff, 0 );   //Must wake proc[3].
    proc_self_stop();

    status = sync_wake( &sync_2, &proc[4], 0 );   //Must fail on wrong process.
    proc_self_stop();

    status = sync_sleep( &sync_1 ); //Must succeed.
    proc_self_stop();

    //This will wakeup proc[3];
    kernel_preemt_hook_add( prio_propagate_hook_2 );
    proc_set_prio( &proc[3], LOWEST );
    proc_self_stop();

    proc_buff  = (proc_t *)0;
    status = sync_wait( &sync_2, &proc_buff, 1 );
}

void main_3( void * arg )
{
    sync_sleep( &sync_2 );
    proc_self_stop();

    proc_set_prio( (proc_t *)0, 3 );
    sync_sleep( &sync_2 );
    proc_self_stop();

    sync_sleep( &sync_2 );
    proc_self_stop();

    status = sync_wake( &sync_2, (proc_t *)0, 1 );//Chown to proc[5];
    proc_self_stop();
}

void main_4( void * arg )
{
    status = sync_sleep( &sync_3 );
    proc_self_stop();
}

void main_5( void * arg )
{
    sync_sleep( &sync_2 );
    proc_self_stop();

    status = sync_wake( &sync_2, (proc_t *)0, 1 );//Must fail;
    proc_self_stop();
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

    start_bugurt();
    return 0;
}
