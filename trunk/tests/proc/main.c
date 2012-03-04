#define _TIME_H
#include <stdio.h>
#include <stdlib.h>
#include "../../include/bugurt.h"

void spin_init(lock_t * lock)
{
    *lock=1;
}
void spin_lock(lock_t * lock)
{
    *lock=0;
}
void spin_unlock(lock_t * lock)
{
    *lock=1;
}

core_id_t _enter_crit_sec(void){return (core_id_t)0;}
void _exit_crit_sec(core_id_t core){}

void disable_interrupts(void){}
void enable_interrupts(void){}

void entner_crit_sec(void){}
void exit_crit_sec(void){}

// Инициацция статистики
void stat_init(stat_t * stat)
{
    stat->total_proc_count = 0;
    stat->total_time_quant = 0;
}
// Обновление статистики при запуске процесса/ всатвки процесса в очередь сигнала
void stat_inc(proc_t * proc, stat_t * stat){

}
// Обновление статистики при останове процесса/ удаления процесса из очереди сигнала
void stat_dec(proc_t * proc, stat_t * stat){

}
void stat_merge(stat_t * src, stat_t * dst){

}
load_t stat_calc_load(prio_t prio, stat_t * stat)
{
 return 0;
}
stack_t * proc_stack_init(stack_t * sstart, code_t code, void * arg)
{
    return (stack_t)0;
}
#ifdef CONFIG_MP
void resched(core_id_t core_id)
{

}
#else
void resched(void)
{

}
#endif
proc_t * current_proc(void)
{
    return 0;
}
core_id_t current_core(void)
{
    return 0;
}

void syscall_bugurt( syscall_t num, void * arg )
{
    do_syscall(num, arg);
}

proc_t proc;
int main()
{
    kernel_init();
    proc_init(&proc,idle_main,0,0,0,0,1,1,1,1);

    proc.flags |= PROC_FLG_QUEUE;
    // Тест запуска, должен не пройти
    bool_t test = proc_run(&proc);
    proc.flags &= ~PROC_FLG_QUEUE;

    proc.flags |= PROC_FLG_END;
    // Тест запуска, должен не пройти
    test = proc_run(&proc);
    proc.flags &= ~PROC_FLG_END;

    proc.flags |= PROC_FLG_DEAD;
    // Тест запуска, должен не пройти
    test = proc_run(&proc);
    proc.flags &= ~PROC_FLG_DEAD;

    // Тест запуска
    test = proc_run(&proc);
    // Тест запуска, должен не пройти
    test = proc_run(&proc);


     proc.flags |= PROC_FLG_QUEUE;
    // Тест останова, должен выставиться флаг PROC_FLAG_PRE_END
    test = proc_stop(&proc);
    proc.flags &= ~PROC_FLG_QUEUE;
    proc.flags &= ~PROC_FLG_PRE_END;

    proc.flags |= PROC_FLG_WAIT;
    // Тест останова, должен выставиться флаг PROC_FLAG_PRE_END
    test = proc_stop(&proc);
    proc.flags &= ~PROC_FLG_WAIT;
    proc.flags &= ~PROC_FLG_PRE_END;

    // Типа захватили ресурс;
#ifdef CONFIG_USE_HIGHEST_LOCKER
    _proc_lres_inc(&proc, 0);
#else
    _proc_lres_inc(&proc);
#endif
    // Тест останова, должен выставиться флаг PROC_FLAG_PRE_END
    test = proc_stop(&proc);
    proc.flags &= ~PROC_FLG_PRE_END;
    //Типа освободили ресурс
#ifdef CONFIG_USE_HIGHEST_LOCKER
    _proc_lres_dec(&proc, 0);
#else
    _proc_lres_dec(&proc);
#endif
    // Тест останова, должен произойти останов
    test = proc_stop(&proc);
    // Тест останова, должен выдать 0ж
    test = proc_stop(&proc);

    proc.flags |= PROC_FLG_QUEUE;
    // Тест рестарта, не должен рестартануть
    test = proc_restart(&proc);
    proc.flags &= ~PROC_FLG_QUEUE;
    proc.flags &= ~PROC_FLG_RUN;

    proc.flags |= PROC_FLG_DEAD;
    // Тест рестарта, не должен рестартануть
    test = proc_restart(&proc);
    proc.flags &= ~PROC_FLG_DEAD;
    proc.flags &= ~PROC_FLG_RUN;

    // Тест рестарта, должен произойти рестарт
    test = proc_restart(&proc);
    // Тест рестарта, не должен рестартануть
    test = proc_restart(&proc);

    return 0;
}
