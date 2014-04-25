#include <test_func.h>

#define CONFIG_SET_1
#define CONFIG_SET_2
#define CONFIG_SET_3
#define CONFIG_SET_4
//#define CONFIG_SET_5

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
#ifdef CONFIG_SET_1
    //==================================================
    // 1st set of tests: proc[1] is stoped.
    mutex_lock( &mutex_1 );

    proc_self_stop();

    mutex_free( &mutex_1 );
    proc_self_stop();
#endif
#ifdef CONFIG_SET_2
    //==================================================
    // 2hd set of tests: proc[1] is running
    mutex_lock( &mutex_1 );

    wait_time( 200 ); // Adjuct wait time!!!

    mutex_free( &mutex_1 );
    proc_self_stop();
#endif
#ifdef CONFIG_SET_3
    //==================================================
    // 3rd set of tests: proc[1] is waiting for sig_0
    mutex_lock( &mutex_1 );

    //proc_self_stop();
    sig_wait( &sig_0 );

    mutex_free( &mutex_1 );
    proc_self_stop();
#endif
#ifdef CONFIG_SET_4
    //==================================================
    // 4th set of tests: proc[1] is waiting for sem_0
    mutex_lock( &mutex_1 );

    sem_lock( &sem_0 );
    sem_free( &sem_0 );
    proc_flag_stop( PROC_FLG_SEM );

    mutex_free( &mutex_1 );
    proc_self_stop();
#endif
#ifdef CONFIG_SET_5
    //==================================================
    // 5th set of tests: proc[1] is waiting for mutex_0
    mutex_lock( &mutex_1 );

    mutex_lock( &mutex_0 );
    mutex_free( &mutex_0 );

    mutex_free( &mutex_1 );
    proc_self_stop();
#endif
    //==================================================
}

void main_2( void * arg )
{
    while(1)
    {
        mutex_lock( &mutex_2 );
        mutex_lock( &mutex_1 );
        mutex_free( &mutex_1 );
        mutex_free( &mutex_2 );
        proc_self_stop();
    }
}

void main_3( void * arg )
{
    while(1)
    {
        mutex_lock( &mutex_2 );
        mutex_free( &mutex_2 );
        proc_self_stop();
    }
}

void main_4( void * arg )
{
    while(1)
    {
        mutex_lock( &mutex_3 );
        mutex_lock( &mutex_2 );
        mutex_free( &mutex_2 );
        mutex_free( &mutex_3 );
        proc_self_stop();
    }
}

void main_5( void * arg )
{
    while(1)
    {
        mutex_lock( &mutex_3 );
        mutex_free( &mutex_3 );
        proc_self_stop();
    }
}

#define MUTEX_IDLE_DELAY() \
    SCHED_IDLE_LOAD_BALANCER();\
    wait_time(10)
static int test_num = 0;
static void test_run_1(void)
{
    int test;
    proc_run( &proc[1] );
    MUTEX_IDLE_DELAY();

    test = (mutex_1.owner == &proc[1]);
    test_output( test, test_num++ );//1

    test = (0 != (proc[1].flags & PROC_FLG_MUTEX));
    test_output( test, test_num++ );//2

    proc_run( &proc[2] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[2].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, test_num++ );//3

    test = ( proc[2].buf == (void *)&mutex_1 );
    test_output( test, test_num++ );//4

    test = ( proc[2].parent.group->link == (void *)&mutex_1.wait );
    test_output( test, test_num++ );//5

    test = (mutex_1.owner == &proc[1]);
    test_output( test, test_num++ );//6

    test = ( proc[1].parent.group->prio == 6);
    test_output( test, test_num++ );//7

    proc_run( &proc[3] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[3].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, test_num++ );//8

    test = ( proc[3].buf == (void *)&mutex_2 );
    test_output( test, test_num++ );//9

    test = ( proc[3].parent.group->link == (void *)&mutex_2.wait );
    test_output( test, test_num++ );//10

    test = (mutex_1.owner == &proc[1]);
    test_output( test, test_num++ );//11

    test = ( proc[1].parent.group->prio == 5);
    test_output( test, test_num++ );//12

    proc_run( &proc[4] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[4].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, test_num++ );//13

    test = ( proc[4].buf == (void *)&mutex_2 );
    test_output( test, test_num++ );//14

    test = ( proc[4].parent.group->link == (void *)&mutex_2.wait );
    test_output( test, test_num++ );//15

    test = (mutex_1.owner == &proc[1]);
    test_output( test, test_num++ );//16

    test = ( proc[1].parent.group->prio == 4 );
    test_output( test, test_num++ );//17

    proc_run( &proc[5] );
    MUTEX_IDLE_DELAY();

    test = ( (PROC_FLG_MUTEX|PROC_STATE_W_MUT) == (proc[5].flags & (PROC_FLG_MUTEX|PROC_STATE_MASK)));
    test_output( test, test_num++ );//18

    test = ( proc[5].buf == (void *)&mutex_3 );
    test_output( test, test_num++ );//19

    test = ( proc[5].parent.group->link == (void *)&mutex_3.wait );
    test_output( test, test_num++ );//20

    test = (mutex_1.owner == &proc[1]);
    test_output( test, test_num++ );//21

    test = ( proc[1].parent.group->prio == 3 );
    test_output( test, test_num++ );//22

    proc_set_prio( &proc[5], 2 );
    MUTEX_IDLE_DELAY();

    test = (mutex_1.owner == &proc[1]);
    test_output( test, test_num++ );//23

    test = ( proc[1].parent.group->prio == 2 );
    test_output( test, test_num++ );//24

    proc_set_prio( &proc[5], 3 );
    MUTEX_IDLE_DELAY();

    test = (mutex_1.owner == &proc[1]);
    test_output( test, test_num++ );//25

    test = ( proc[1].parent.group->prio == 3 );
    test_output( test, test_num++ );//26

    test = (mutex_0.dirty == 0);
    test_output( test, test_num++ );//27

    test = (mutex_1.dirty == 0);
    test_output( test, test_num++ );//28

    test = (mutex_2.dirty == 0);
    test_output( test, test_num++ );//29

    test = (mutex_3.dirty == 0);
    test_output( test, test_num++ );//30
}
static void test_run_2(void)
{
    int test;
    test = ( (proc[5].flags & PROC_STATE_MASK) == PROC_STATE_STOPED )&&( proc[5].parent.group->prio == 3 );
    test_output( test, test_num++ );//31
    test = ( (proc[4].flags & PROC_STATE_MASK) == PROC_STATE_STOPED )&&( proc[4].parent.group->prio == 4 );
    test_output( test, test_num++ );//32
    test = ( (proc[3].flags & PROC_STATE_MASK) == PROC_STATE_STOPED )&&( proc[3].parent.group->prio == 5 );
    test_output( test, test_num++ );//33
    test = ( (proc[2].flags & PROC_STATE_MASK) == PROC_STATE_STOPED )&&( proc[2].parent.group->prio == 6 );
    test_output( test, test_num++ );//34

    test = (mutex_0.dirty == 0);
    test_output( test, test_num++ );//35

    test = (mutex_1.dirty == 0);
    test_output( test, test_num++ );//36

    test = (mutex_2.dirty == 0);
    test_output( test, test_num++ );//37

    test = (mutex_3.dirty == 0);
    test_output( test, test_num++ );//38
}
void idle_main( void * arg )
{
    int test;
    test_start();
#ifdef CONFIG_SET_1
    test_num = 1;
    //==================================================
    // 1st set of tests: proc[1] is stoped.
    // Tests 1...38
    test_run_1();

    proc_run( &proc[1] );
    MUTEX_IDLE_DELAY();

    test_run_2();
    MUTEX_IDLE_DELAY();
#endif
#ifdef CONFIG_SET_2
    //==================================================
    // 2hd set of tests: proc[1] is running
    // Tests 39...76
    test_num = 31;
    test_run_1();


    for(test = 20; test != 0; test-- )
    {
        MUTEX_IDLE_DELAY();
    }

    test_run_2();
    MUTEX_IDLE_DELAY();
#endif
#ifdef CONFIG_SET_3
    //==================================================
    // 3rd set of tests: proc[1] is waiting for sig_0
    // Tests 77...114
    test_num = 61;
    test_run_1();

    sig_broadcast( &sig_0 );
    //proc_run( &proc[1] );
    MUTEX_IDLE_DELAY();

    test_run_2();
    MUTEX_IDLE_DELAY();
#endif
#ifdef CONFIG_SET_4
    //==================================================
    // 4th set of tests: proc[1] is waiting for sem_0
    // Tests 115...152
    test_num = 91;
    test_run_1();

    sem_free( &sem_0 );
    MUTEX_IDLE_DELAY();

    test_run_2();
    MUTEX_IDLE_DELAY();
#endif
#ifdef CONFIG_SET_5
    //==================================================
    // 5th set of tests: proc[1] is waiting for mutex_0
    // Tests 153...190
    test_num = 121;
    mutex_try_lock( &mutex_0 );

    test_run_1();

    mutex_free( &mutex_0 );
    MUTEX_IDLE_DELAY();

    test_run_2();
#endif
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
    sem_init_isr( &sem_0, 0 );
    sig_init_isr( &sig_0 );

    mutex_init_isr( &mutex_1 );
    mutex_init_isr( &mutex_2 );
    mutex_init_isr( &mutex_3 );

    proc_run_isr( &proc[0] );

    start_bugurt();
    return 0;
}
