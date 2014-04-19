#include <test_func.h>

proc_t proc[6];
stack_t proc_stack[6][PROC_STACK_SIZE];

mutex_t mutex_0;
sem_t   sem_0;
sig_t   sig_0;

mutex_t mutex_1;
mutex_t mutex_2;
mutex_t mutex_3;

void main_1( void * arg )
{
    //==================================================
    // 1st set of tests: proc[1] is stoped.
    mutex_lock( &mutex_1 );

    proc_self_stop();

    mutex_unlock( &mutex_1 );
    proc_self_stop();

    //==================================================
    // 2hd set of tests: proc[1] is running
    mutex_lock( &mutex_1 );

    wait_time( 200 ); // Adjuct wait time!!!

    mutex_unlock( &mutex_1 );
    proc_self_stop();

    //==================================================
    // 3rd set of tests: proc[1] is waiting for sig_0
    mutex_lock( &mutex_1 );

    sig_wait( &sig_0 );

    mutex_unlock( &mutex_1 );
    proc_self_stop();

    //==================================================
    // 4th set of tests: proc[1] is waiting for sem_0
    mutex_lock( &mutex_1 );

    sem_lock( &sem_0 );
    sem_unlock( &sem_0 );
    proc_flag_stop( PROC_FLG_SEM );

    mutex_unlock( &mutex_1 );
    proc_self_stop();

    //==================================================
    // 5th set of tests: proc[1] is waiting for mutex_0
    mutex_lock( &mutex_1 );

    mutex_lock( &mutex_0 );
    mutex_unlock( &mutex_0 );

    mutex_unlock( &mutex_1 );
    proc_self_stop();
    //==================================================
}

void main_2( void * arg )
{
    while(1)
    {
        mutex_lock( &mutex_2 );
        mutex_lock( &mutex_1 );
        proc_self_stop();
        mutex_unlock( &mutex_1 );
        mutex_unlock( &mutex_2 );
        proc_self_stop();
    }
}

void main_3( void * arg )
{
    while(1)
    {
        mutex_lock( &mutex_2 );
        proc_self_stop();
        mutex_unlock( &mutex_2 );
        proc_self_stop();
    }
}

void main_4( void * arg )
{
    while(1)
    {
        mutex_lock( &mutex_3 );
        mutex_lock( &mutex_2 );
        proc_self_stop();
        mutex_unlock( &mutex_2 );
        mutex_unlock( &mutex_3 );
        proc_self_stop();
    }
}

void main_5( void * arg )
{
    while(1)
    {
        mutex_lock( &mutex_3 );
        proc_self_stop();
        mutex_unlock( &mutex_3 );
        proc_self_stop();
    }
}

#define MUTEX_IDLE_DELAY() \
    SCHED_IDLE_LOAD_BALANCER();\
    wait_time(10)

void idle_main( void * arg )
{
    int test;
    test_start();
    //==================================================
    // 1st set of tests: proc[1] is stoped.
    proc_run( &proc[1] );
    MUTEX_IDLE_DELAY();

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 1 );

    test = (0 != (proc[1].flags & PROC_FLG_MUTEX));
    test_output( test, 2 );

    proc_run( &proc[2] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[2].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 3 );

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[2].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 4 );

    test = ( proc[2].buf == (void *)&mutex_1 );
    test_output( test, 5 );

    test = ( proc[2].parent.group->link == (void *)&mutex_1.wait );
    test_output( test, 6 );

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 7 );

    test = ( proc[1].parent.group->prio == 6);
    test_output( test, 8 );

    proc_run( &proc[3] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[3].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 9 );

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[3].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 10 );

    test = ( proc[3].buf == (void *)&mutex_2 );
    test_output( test, 11 );

    test = ( proc[3].parent.group->link == (void *)&mutex_2.wait );
    test_output( test, 12 );

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 13 );

    test = ( proc[1].parent.group->prio == 5);
    test_output( test, 14 );

    proc_run( &proc[4] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[4].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 15 );

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[4].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 16 );

    test = ( proc[4].buf == (void *)&mutex_2 );
    test_output( test, 17 );

    test = ( proc[4].parent.group->link == (void *)&mutex_2.wait );
    test_output( test, 18 );

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 19 );

    test = ( proc[1].parent.group->prio == 4 );
    test_output( test, 20 );

    proc_run( &proc[5] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[5].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 21 );

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[5].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 22 );

    test = ( proc[5].buf == (void *)&mutex_3 );
    test_output( test, 23 );

    test = ( proc[5].parent.group->link == (void *)&mutex_3.wait );
    test_output( test, 24 );

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 25 );

    test = ( proc[1].parent.group->prio == 3 );
    test_output( test, 26 );

    proc_set_prio( &proc[5], 2 );
    MUTEX_IDLE_DELAY();

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 27 );

    test = ( proc[1].parent.group->prio == 2 );
    test_output( test, 28 );

    proc_set_prio( &proc[5], 3 );
    MUTEX_IDLE_DELAY();

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 29 );

    test = ( proc[1].parent.group->prio == 3 );
    test_output( test, 30 );

    proc_run( &proc[1] );
    MUTEX_IDLE_DELAY();

    test = ( (proc[5].flags & PROC_STATE_MASK) == PROC_STATE_STOPED );
    test_output( test, 31 );
    test = ( (proc[4].flags & PROC_STATE_MASK) == PROC_STATE_STOPED );
    test_output( test, 32 );
    test = ( (proc[3].flags & PROC_STATE_MASK) == PROC_STATE_STOPED );
    test_output( test, 33 );
    test = ( (proc[2].flags & PROC_STATE_MASK) == PROC_STATE_STOPED );
    test_output( test, 34 );
    MUTEX_IDLE_DELAY();

    //==================================================
    // 2hd set of tests: proc[1] is running
    proc_run( &proc[1] );
    MUTEX_IDLE_DELAY();

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 1 );

    test = (0 != (proc[1].flags & PROC_FLG_MUTEX));
    test_output( test, 2 );

    proc_run( &proc[2] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[2].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 3 );

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[2].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 4 );

    test = ( proc[2].buf == (void *)&mutex_1 );
    test_output( test, 5 );

    test = ( proc[2].parent.group->link == (void *)&mutex_1.wait );
    test_output( test, 6 );

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 7 );

    test = ( proc[1].parent.group->prio == 6);
    test_output( test, 8 );

    proc_run( &proc[3] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[3].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 9 );

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[3].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 10 );

    test = ( proc[3].buf == (void *)&mutex_2 );
    test_output( test, 11 );

    test = ( proc[3].parent.group->link == (void *)&mutex_2.wait );
    test_output( test, 12 );

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 13 );

    test = ( proc[1].parent.group->prio == 5);
    test_output( test, 14 );

    proc_run( &proc[4] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[4].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 15 );

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[4].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 16 );

    test = ( proc[4].buf == (void *)&mutex_2 );
    test_output( test, 17 );

    test = ( proc[4].parent.group->link == (void *)&mutex_2.wait );
    test_output( test, 18 );

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 19 );

    test = ( proc[1].parent.group->prio == 4 );
    test_output( test, 20 );

    proc_run( &proc[5] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[5].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 21 );

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[5].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, 22 );

    test = ( proc[5].buf == (void *)&mutex_3 );
    test_output( test, 23 );

    test = ( proc[5].parent.group->link == (void *)&mutex_3.wait );
    test_output( test, 24 );

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 25 );

    test = ( proc[1].parent.group->prio == 3 );
    test_output( test, 26 );

    proc_set_prio( &proc[5], 2 );
    MUTEX_IDLE_DELAY();

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 27 );

    test = ( proc[1].parent.group->prio == 2 );
    test_output( test, 28 );

    proc_set_prio( &proc[5], 3 );
    MUTEX_IDLE_DELAY();

    test = (mutex_1.owner == &proc[1]);
    test_output( test, 29 );

    test = ( proc[1].parent.group->prio == 3 );
    test_output( test, 30 );

    proc_run( &proc[1] );
    MUTEX_IDLE_DELAY();

    test = ( (proc[5].flags & PROC_STATE_MASK) == PROC_STATE_STOPED );
    test_output( test, 31 );
    test = ( (proc[4].flags & PROC_STATE_MASK) == PROC_STATE_STOPED );
    test_output( test, 32 );
    test = ( (proc[3].flags & PROC_STATE_MASK) == PROC_STATE_STOPED );
    test_output( test, 33 );
    test = ( (proc[2].flags & PROC_STATE_MASK) == PROC_STATE_STOPED );
    test_output( test, 34 );
    MUTEX_IDLE_DELAY();

    //==================================================
    // 3rd set of tests: proc[1] is waiting for sig_0
    //==================================================
    // 4th set of tests: proc[1] is waiting for sem_0
    //==================================================
    // 5th set of tests: proc[1] is waiting for mutex_0


    tests_end();
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

    proc_init_isr( &proc[0], main_lb, SVH0, RSH0, 0, &proc_stack[0][PROC_STACK_SIZE-1], LOWEST, 1, 0 SCHED_ARG_END );

    proc_init_isr( &proc[1], main_1,  SVH1, RSH1, 0, &proc_stack[1][PROC_STACK_SIZE-1], 7,      1, 0 ARG_END );
    proc_init_isr( &proc[2], main_2,  SVH2, RSH2, 0, &proc_stack[2][PROC_STACK_SIZE-1], 6,      1, 0 ARG_END );
    proc_init_isr( &proc[3], main_3,  SVH0, RSH0, 0, &proc_stack[3][PROC_STACK_SIZE-1], 5,      1, 0 ARG_END );
    proc_init_isr( &proc[4], main_4,  SVH1, RSH1, 0, &proc_stack[4][PROC_STACK_SIZE-1], 4,      1, 0 ARG_END );
    proc_init_isr( &proc[5], main_5,  SVH2, RSH2, 0, &proc_stack[5][PROC_STACK_SIZE-1], 3,      1, 0 ARG_END );

    mutex_init_isr( &mutex_0 );
    sem_init_isr( &sem_0, 1 );
    sig_init_isr( &sig_0 );

    mutex_init_isr( &mutex_1 );
    mutex_init_isr( &mutex_2 );
    mutex_init_isr( &mutex_3 );

    proc_run_isr( &proc[0] );

    start_bugurt();
    return 0;
}
