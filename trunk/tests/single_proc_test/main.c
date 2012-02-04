#include <stdio.h>
#include <stdlib.h>
#include "../../include/bugurt.h"

proc_t proc[12];

bool_t rt[12] =
{
    0,0,0,0,0,0,
    1,1,1,1,1,1
};

prio_t pr[12] =
{
    3,4,4,5,5,5,
    0,1,1,2,2,2
};
timer_t tq[12] =
{
    2,2,2,2,2,2,
    2,2,2,2,2,2
};

void spin_init(lock_t * lock)
{
}

void spin_lock(lock_t * lock)
{
}
void spin_unlock(lock_t * lock)
{
}

void enter_crit_sec(void)
{
}
void exit_crit_sec(void)
{
}

void disable_interrupts(void) {}
void enable_interrupts(void) {}

stack_t * proc_stack_init(stack_t * sstart, code_t code, void * arg)
{
    return (stack_t)0;
}
void resched(void)
{
}

proc_t * current_proc(void)
{
    return kernel.sched.current_proc;
}

// Сигналы
sig_t sig[1];
sem_t sem;
mutex_t mut[1];

int main()
{
    kernel_init();
    // Инициация сигналов
    sig_init((sig_t *)sig);
    sem_init(&sem,1);
#ifdef CONFIG_USE_HIGHEST_LOCKER
    mutex_init((mutex_t *)mut, (prio_t)(BITS_IN_INDEX_T-1));//
#else
    mutex_init( (mutex_t *)mut );
#endif // CONFIG_USE_HIGHEST_LOCKER
    for(int i = 0; i < 12; i++)
    {
        char name[10];
        sprintf(name,"prc%d ",(int)i);
        proc_init(proc+i,idle_main,0,0,0,0,pr[i],tq[i],rt[i]);
        proc_run(proc+i);
    }
    /// Тест планировщика
    // Текущий процесс idle
    sched_schedule();
    // Текущий процесс prc6
    sched_schedule();
    // Текущий процесс prc6
    sched_schedule();
    // Текущий процесс prc7
    sched_schedule();
    // Текущий процесс prc8
    sched_schedule();
    // Текущий процесс prc7
    sched_schedule();
    // Текущий процесс prc8
    sched_schedule();
    // Текущий процесс prc9
    sched_schedule();
    // Текущий процесс prc10
    sched_schedule();
    // Текущий процесс prc11
    sched_schedule();
    // Текущий процесс prc9
    sched_schedule();
    // Текущий процесс prc10
    sched_schedule();
    // Текущий процесс prc11
    sched_schedule();
    // Текущий процесс prc0
    sched_schedule();
    // Текущий процесс prc0
    sched_schedule();
    // Текущий процесс prc1
    sched_schedule();
    // Текущий процесс prc2
    sched_schedule();
    // Текущий процесс prc1
    sched_schedule();
    // Текущий процесс prc2
    sched_schedule();
    // Текущий процесс prc3
    sched_schedule();
    // Текущий процесс prc4
    sched_schedule();
    // Текущий процесс prc5
    sched_schedule();
    // Текущий процесс prc3
    sched_schedule();
    // Текущий процесс prc4
    sched_schedule();
    // Текущий процесс prc5
    sched_schedule();
    // Текущий процесс prc0
    sched_schedule();
    // Текущий процесс prc0
    sched_schedule();
    // Текущий процесс prc1
    sched_schedule();
    // Текущий процесс prc2
    sched_schedule();
    // Текущий процесс prc1
    sched_schedule();
    // Текущий процесс prc2
    sched_schedule();
    // Текущий процесс prc3
    sched_schedule();
    // Текущий процесс prc4
    sched_schedule();
    // Текущий процесс prc5
    sched_schedule();
    // Текущий процесс prc3
    sched_schedule();
    // Текущий процесс prc4
    sched_schedule();
    // Текущий процесс prc5
    sched_schedule();
    // Текущий процесс idle
    sched_schedule();
    // Текущий процесс prc0
    ///-------------------------------------------------
    /// Тест сигналов
    sig_wait_stage_1((sig_t *)sig);
    sched_reschedule();
    // Текущий процесс prc1
    sig_wait_stage_1((sig_t *)sig);
    sched_reschedule();
    // Текущий процесс prc2
    sig_wait_stage_1((sig_t *)sig);
    sched_reschedule();
    // Текущий процесс prc3
    sig_signal((sig_t *)sig);
    sig_signal((sig_t *)sig);
    sig_signal((sig_t *)sig);
    sched_reschedule();
    // Текущий процесс prc0
    sig_wait_stage_1((sig_t *)sig);
    sched_reschedule();
    // Текущий процесс prc1
    sig_wait_stage_1((sig_t *)sig);
    sched_reschedule();
    // Текущий процесс prc2
    sig_wait_stage_1((sig_t *)sig);
    sched_reschedule();
    // Текущий процесс prc3
    sig_broadcast((sig_t *)sig);
    ///----------------------------------------
    /// Тест семафоров
    _sem_lock( &sem );
    sched_reschedule();
    // Текущий процесс prc0
    _sem_lock( &sem );
    sched_reschedule();
    // Текущий процесс prc1
    _sem_lock( &sem );
    sched_reschedule();
    // Текущий процесс prc2
    _sem_lock( &sem );
    sched_reschedule();
    // Текущий процесс prc3

    _sem_unlock( &sem );
    sched_reschedule();
    // Текущий процесс prc0

    _sem_unlock( &sem );
    sched_schedule();
    // Текущий процесс prc0
    sched_schedule();
    // Текущий процесс prc0
     sched_schedule();
    // Текущий процесс prc1

    _sem_unlock( &sem );
    sched_schedule();
    // Текущий процесс prc1
    sched_schedule();
    // Текущий процесс prc2

    _sem_unlock( &sem );
    sched_schedule();
    ///---------------------------------------------
    /// Тест мьютексов
    // Текущий процесс prc3

    mutex_lock(mut);//win
    sched_schedule();
    // Текущий процесс prc4
    sched_schedule();
    // Текущий процесс prc5
    sched_schedule();
    // Текущий процесс prc3
    sched_schedule();
    // Текущий процесс prc4
    sched_schedule();
    // Текущий процесс prc5
    sched_schedule();
    // Текущий процесс idle
    sched_schedule();

    // Текущий процесс prc0
    mutex_lock(mut); //fail
    sched_reschedule();
    // Текущий процесс prc1
    mutex_lock(mut); //fail
    sched_reschedule();
    // Текущий процесс prc2
    mutex_lock(mut); //fail
    sched_reschedule();
    // Текущий процесс prc3
    mutex_unlock(mut);
    sched_reschedule();

    // Текущий процесс prc0
    mutex_unlock(mut);
    sched_schedule();
    // Текущий процесс prc0
    sched_schedule();
    // Текущий процесс prc0
    sched_schedule();
    // Текущий процесс prc1

    mutex_unlock(mut);
    sched_schedule();
    // Текущий процесс prc1
    sched_schedule();
    // Текущий процесс prc2

    mutex_unlock(mut);
    sched_schedule();
    // Текущий процесс prc3

    printf("Hello world!\n");
    return 0;
}
