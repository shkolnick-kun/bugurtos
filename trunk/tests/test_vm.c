#include "test_vm.h"

// Тестовая виртуальная машина
pthread_mutex_t start_mutex, console_mutex;
pthread_cond_t start_cond;
pthread_t test_vm_core[MAX_CORES]; // Каждый поток - отдельный виртуальный процессор
test_vm_t idle_vm[MAX_CORES];
test_vm_t current_vm[MAX_CORES];

lock_t test_vm_lock[MAX_CORES];
bool_t test_vm_resched[MAX_CORES];

lock_t stop_lock;
bool_t stop = 0;

void * retval;
void * retval_store;

// Сигналы
sig_t sig[2];
sem_t sem;
mutex_t mut[2];

void spin_init(lock_t * lock)
{
    pthread_spin_init( lock,0 );
}

void spin_lock(lock_t * lock)
{
    pthread_spin_lock(lock);
}
void spin_unlock(lock_t * lock)
{
    int i;
    for(i = 0; i < 100000; i++);
    pthread_spin_unlock(lock);
}

core_id_t _enter_crit_sec(void)
{
    pthread_t current_thread = pthread_self();
    core_id_t i;
    for( i = 0; i < MAX_CORES; i++ )if(current_thread == test_vm_core[i])return i;
    return 0;
}
void _exit_crit_sec(core_id_t core) {}

void disable_interrupts(void) {}
void enable_interrupts(void) {}

void enter_crit_sec(void) {}
void exit_crit_sec(void) {}

// Инициация статистики
void stat_init(stat_t * stat)
{
    stat->total_proc_count = 0;
    stat->total_time_quant = 0;
}
// Обновление статистики при запуске процесса/ всатвки процесса в очередь сигнала
void stat_inc(proc_t * proc, stat_t * stat)
{
    stat->total_proc_count++;
    stat->total_time_quant += proc->time_quant;
}
// Обновление статистики при останове процесса/ удаления процесса из очереди сигнала
void stat_dec(proc_t * proc, stat_t * stat)
{
    stat->total_proc_count--;
    stat->total_time_quant -= proc->time_quant;
}
// Обновление статистики при останове процесса/ удаления процесса из очереди сигнала
void stat_merge(stat_t * src_stat, stat_t * dst_stat)
{
    dst_stat->total_proc_count += src_stat->total_proc_count;
    src_stat->total_proc_count = 0;
    dst_stat->total_time_quant += src_stat->total_time_quant;
    src_stat->total_time_quant = 0;
}
load_t stat_calc_load(prio_t prio, stat_t * stat)
{
    load_t ret = (load_t)stat->total_proc_count;
    return ret;
}
void * proc_stack_init(stack_t * sstart, code_t code, void * arg)
{
    return (stack_t)0;
}
#ifdef CONFIG_MP
void resched(core_id_t core_id)
{
    pthread_spin_lock(test_vm_lock + core_id);
    test_vm_resched[core_id] = 1;
    pthread_spin_unlock(test_vm_lock + core_id);
}
#else
void resched(void)
{
    sched_reschedule( 0, &kernel.sched);
}
#endif

proc_t * current_proc(void)
{
    pthread_t current_thread = pthread_self();
    core_id_t i;
    for(i = 0; i < MAX_CORES; i++ )if(current_thread == test_vm_core[i])return kernel.sched[i].current_proc;
    return 0;
}

core_id_t current_core(void)
{
    pthread_t current_thread = pthread_self();
    core_id_t i;
    for(i = 0; i < MAX_CORES; i++ )if(current_thread == test_vm_core[i])return i;
    return 0;
}

void print_op_result(core_id_t core, char *name, char *inst, int result)
{
    // Распечатка в консоль будет идти атомарно
    int n,m,t;
    char c;

    pthread_spin_lock(&kernel.stat_lock);
    n = kernel.stat[core].total_proc_count;
    pthread_spin_unlock(&kernel.stat_lock);

    pthread_spin_lock(&kernel.sched[core].current_proc->lock);
    m = (int)kernel.sched[core].current_proc->parent.group->prio;
    c = ( kernel.sched[core].current_proc->flags & PROC_FLG_RT )?'x':'0';
    t = (int)kernel.sched[core].current_proc->timer;
    pthread_spin_unlock(&kernel.sched[core].current_proc->lock);

    pthread_mutex_lock(&console_mutex);
    printf("\n core%d: %d proc: %c%c%c%c%c prio: %d timer: %d rt:%c inst: %s res: %d\n",
           (int)core,
           n,
           name[0], name[1], name[2], name[3], name[4],
           m,
           t,
           c,
           inst,
           result
          );
    pthread_mutex_unlock(&console_mutex);
}

// В качестве параметра передаем current_vm[core_id]
void * test_vm( void * arg )
{
    core_id_t core_id = (core_id_t)((test_vm_t *)arg - current_vm);
    while(1)
    {

        /// Ожидаем сигнала от main (main симулирует работу системного таймера)
        pthread_mutex_lock( &start_mutex );
        pthread_cond_wait( &start_cond, &start_mutex );
        pthread_mutex_unlock( &start_mutex );

        /// Собственно виртуальная машина
        // Обработчик "прерывания" перепланирования
        pthread_spin_lock(test_vm_lock + core_id);
        bool_t rflg = test_vm_resched[core_id];
        test_vm_resched[core_id] = 0;
        pthread_spin_unlock(test_vm_lock + core_id);

        if(rflg)
        {
            sched_t * sched = kernel.sched + core_id;
            test_vm_t * vm = (test_vm_t *)(sched->current_proc->arg);
            *vm = current_vm[core_id];// Сохранение контекста
            // Перепланирование
            sched_reschedule( 0 );
            vm = (test_vm_t *)(sched->current_proc->arg);
            current_vm[core_id] = *vm;// Восстановление контекста
        }
        // Интерпретатор байт-кода
        switch(*current_vm[core_id].pcounter)
        {
        case TVM_NOP:
            current_vm[core_id].pcounter++;
            print_op_result(core_id,current_vm[core_id].name,"NOP",0);
            break;
        case TVM_LOOP:
            current_vm[core_id].loop_start = current_vm[core_id].pcounter++;
            print_op_result(core_id,current_vm[core_id].name,"LOOP",0);
            break;
        case TVM_END:
            current_vm[core_id].pcounter = current_vm[core_id].loop_start;
            print_op_result(core_id,current_vm[core_id].name,"END",0);
            break;
// Балансировка нагрузкт
#if defined(CONFIG_MP) && (!defined(CONFIG_USE_ALB))
        case TVM_LLB:
            current_vm[core_id].pcounter++;
            proc_lazy_local_load_balancer();
            print_op_result(core_id,current_vm[core_id].name,"LLB",0);
            break;
        case TVM_GLB:
            current_vm[core_id].pcounter++;
            proc_lazy_global_load_balancer();
            print_op_result(core_id,current_vm[core_id].name,"GLB",0);
            break;
#endif
// Сигналы
        case TVM_SWAIT1:
            current_vm[core_id].pcounter++;
            switch(*current_vm[core_id].pcounter++)
            {
                case 0:
                    sig_wait_stage_1((sig_t *)sig);
                    print_op_result(core_id,current_vm[core_id].name,"SW1",0);
                    break;
                case 1:
                    sig_wait_stage_1((sig_t *)sig+1);
                    print_op_result(core_id,current_vm[core_id].name,"SW1",1);
                    break;
                default:
                    print_op_result(core_id,current_vm[core_id].name,"SW1",2);//Низачет
                    break;
            }
            break;
        case TVM_SWAIT2:
            current_vm[core_id].pcounter++;
            switch(*current_vm[core_id].pcounter++)
            {
                case 0:
                    _proc_flag_stop(~PROC_FLG_WAIT);
                    print_op_result(core_id,current_vm[core_id].name,"SW2",0);
                    break;
                case 1:
                    _proc_flag_stop(~PROC_FLG_WAIT);
                    print_op_result(core_id,current_vm[core_id].name,"SW2",1);
                    break;
                default:
                    print_op_result(core_id,current_vm[core_id].name,"SW2",2);//Низачет
                    break;
            }
            break;
        case TVM_SSIG:
            current_vm[core_id].pcounter++;
            switch(*current_vm[core_id].pcounter++)
            {
                case 0:
                    sig_signal((sig_t *)sig);
                    print_op_result(core_id,current_vm[core_id].name,"SIG",0);
                    break;
                case 1:
                    sig_signal((sig_t *)sig+1);
                    print_op_result(core_id,current_vm[core_id].name,"SIG",1);
                    break;
                default:
                    print_op_result(core_id,current_vm[core_id].name,"SIG",2);//Низачет
                    break;
            }
            break;
        case TVM_SBRCST:
            current_vm[core_id].pcounter++;
            switch(*current_vm[core_id].pcounter++)
            {
                case 0:
                    sig_broadcast((sig_t *)sig);
                    print_op_result(core_id,current_vm[core_id].name,"BRC",0);
                    break;
                case 1:
                    sig_broadcast((sig_t *)sig+1);
                    print_op_result(core_id,current_vm[core_id].name,"BRC",1);
                    break;
                default:
                    print_op_result(core_id,current_vm[core_id].name,"BRC",2);//Низачет
                    break;
            }
            break;
        case TVM_SLOCK1:
            current_vm[core_id].pcounter++;
            {
                bool_t test = _sem_lock_stage_1(&sem);
                print_op_result(core_id,current_vm[core_id].name,"SL1",(int)test);
            }
            break;
        case TVM_SLOCK2:
            current_vm[core_id].pcounter++;
            _proc_flag_stop(~PROC_FLG_QUEUE);
            print_op_result(core_id,current_vm[core_id].name,"SL2", 0);
            break;
        case TVM_SULOCK:
            current_vm[core_id].pcounter++;
            sem_unlock(&sem, 0);
            print_op_result(core_id,current_vm[core_id].name,"SUL", (int)sem.counter);
            break;
        case TVM_MLOCK:
            current_vm[core_id].pcounter++;
            switch(*current_vm[core_id].pcounter++)
            {
                case 0:
                    {
                        bool_t test = mutex_lock((mutex_t *)mut);
                        print_op_result(core_id,current_vm[core_id].name,"MLK",(int)test);
                    }
                    break;
                case 1:
                    {
                        bool_t test = mutex_lock((mutex_t *)mut+1);
                        print_op_result(core_id,current_vm[core_id].name,"MLK",(int)test);
                    }
                    break;
                default:
                    print_op_result(core_id,current_vm[core_id].name,"MLK",2);//Низачет
                    break;
            }
            break;
        case TVM_MULOCK:
            current_vm[core_id].pcounter++;
            switch(*current_vm[core_id].pcounter++)
            {
                case 0:
                    mutex_unlock((mutex_t *)mut);
                    print_op_result(core_id,current_vm[core_id].name,"MUL",(int)0);
                    break;
                case 1:
                    mutex_unlock((mutex_t *)mut+1);
                    print_op_result(core_id,current_vm[core_id].name,"MUL",(int)1);
                    break;
                default:
                    print_op_result(core_id,current_vm[core_id].name,"MUL",2);//Низачет
                    break;
            }
            break;
        default:
            current_vm[core_id].pcounter++;
            print_op_result(core_id,current_vm[core_id].name,"XXX",0);
            break;
        }
        // Обработчик "прерывания" системмного таймера
        {
            sched_t * sched = kernel.sched + core_id;
            test_vm_t * vm = (test_vm_t *)(sched->current_proc->arg);
            *vm = current_vm[core_id];// Сохранение контекста
            // Планирование
            sched_schedule(0);
            vm = (test_vm_t *)(sched->current_proc->arg);
            current_vm[core_id] = *vm;// Восстановление контекста
        }

        pthread_spin_lock(&stop_lock);
        bool_t stpflg = stop;
        pthread_spin_unlock(&stop_lock);
        if(stpflg)pthread_exit(arg);
    }
}

int idle_prorgam[] =
{
    TVM_LOOP,
    TVM_END
};

void test_vm_init( test_vm_t * tvm, int * program, char * name)
{
    int i;
    tvm->pstart = program;
    tvm->pcounter = program;
    for(i = 0; i < 5; i++)tvm->name[i] = name[i];
}

void test_system_init(void)
{
    core_id_t i;
    kernel_init();
    // Инициация сигналов
    sig_init((sig_t *)sig);
    sig_init((sig_t *)sig+1);
    sem_init(&sem,1);
    mutex_init((mutex_t *)mut, 1);
    mutex_init((mutex_t *)mut + 1, 0);

    pthread_mutex_init( &start_mutex, 0);
    pthread_mutex_init( &console_mutex, 0);
    pthread_cond_init( &start_cond, 0);
    spin_init(&stop_lock);

    for(i = 0; i < MAX_CORES; i++)
    {
        char name[10];
        sprintf(name,"idle%d",(int)i);
        test_vm_init(idle_vm + i, idle_prorgam, name );
        current_vm[i] = idle_vm[i];
        spin_init(test_vm_lock+i);
        test_vm_resched[i] = 0;
        kernel.idle[i].arg = (void *)(idle_vm + i);
        pthread_create(test_vm_core+i,0,test_vm,(void *)(current_vm+i));
    }
}
void test_system_timer_interrupt(void)
{
    int d;
    pthread_cond_broadcast( &start_cond );
    for(d = 0; d < 50000000; d++);
}
void test_system_join(void)
{
    core_id_t i;
    pthread_spin_lock(&stop_lock);
    stop = 1;
    pthread_spin_unlock(&stop_lock);

    for(i = 0; i < MAX_CORES; i++)test_system_timer_interrupt();
    test_system_timer_interrupt();
    for(i = 0; i < MAX_CORES; i++)
    {
        pthread_join(test_vm_core[i], &retval_store);
    }
}
