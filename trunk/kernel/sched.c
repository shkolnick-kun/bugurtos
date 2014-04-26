/**************************************************************************
    BuguRTOS-0.7.x(Bugurt real time operating system)
    Copyright (C) 2014  anonimous

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Please contact with me by E-mail: shkolnick.kun@gmail.com

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes BuguRTOS, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
**************************************************************************/

/*****************************************************************************************
```````````````````````````````..:+oyhdmNNMMMMMMNmmdhyo+:..```````````````````````````````
``````````````````````````.:oydNMMMMMMMMMNNNNNNNNMMMMMMMMMNdy+:.``````````````````````````
```````````````````````:sdNMMMMMNdys+/::----------::/osydNMMMMMNds:```````````````````````
```````````````````.+hNMMMMmho/-..........................-/shmMMMMNh/.```````````````````
````````````````./hNMMMNho:...................................-:ohNMMMNh/`````````````````
``````````````.smMMMNy/-.......:////ss++/+-.......................-+yNMMMmo.``````````````
````````````-sNMMMd+-.....:////:-...-/s::..............+o/-..........-odMMMNs.````````````
``````````.sNMMNh/....................................-o:--............./hMMMNo.``````````
`````````+mMMMh:-........................................-...............-/dMMMm/`````````
```````.yMMMm/...................-::--..................:-........--........+mMMMy.```````
``````:mMMMy-.......................-::-...............-:.........-::........-yMMMd:``````
`````/NMMN+-..................::-.....-:-............../--.........-:/-.......-+NMMN:`````
````+NMMm::o/-..--/+o+o+++++o+osys+//::-::.............:/....-:-::-..-++-.......:NMMN/````
```/NMMm:.-++-+yhs/-``       `dMMMMMmho+:-..............:-/+yho/:/+oyo//o-......./mMMN:```
``-NMMm/....-/--::/o+o+oo+oo++oosyss+smyo/.............:yyho-`     smMMddh-......./NMMN.``
`.hMMM/......-++:-.-:oooooooooosyyhhys/...............-+osyyyyysssssooo+ohhs-......+MMMh.`
`+MMMy.......-::/++:-.....-:/++++o+o/--................--/oooo+o++o+++////-y/.......hMMM/`
.mMMN:.........--:---...-::/+//::--.......................--//+//-...-.....+/......./NMMd`
/MMMy............-::----------....----/+-.....................-++/:---....-o-........hMMN:
yMMM/.............--:://///oo+++/+++oo+-.......................-://+/:--::::.........+MMMs
mMMN:................----:/h:::/:/::---.........................--/osss+++:..........:NMMd
MMMd-....................:mNs:-....................................--:odo:-..........:mMMN
MMMd-....................yoshyoso:--................................../mm/...........:mMMM
MMMm:..................../-o/h.y-:+dooo+/:--....................-/osydddmh...........:mMMN
mMMN:........................+mNs `h.  -d/:/+h++ooooy+++s++y+++mo+y` yh.do...........:NMMh
sMMM+........................-hmMo/ds  oMo`.-o     :h   s:`h` `Nysd.-Ny-h:...........+MMMo
/MMMh........................./smMMMMd+NMMNNMh`    sN: .mNNMddNMMMMNmN+..............hMMN:
.dMMN/........................./+hMMMMMMMMMMMMmhyyyNMNNMMMMMMMMMMMNsoo-............./NMMd`
`+MMMh.........................-/+omMMMMMMMMMMMMMMMMMMMMMMMMMMMMms-/+...............hMMM/`
`.hMMM+..........................:/-omMMMMMMMMMMMMMMMdmMdhMMMds/-..-...............oMMMy``
``.NMMN/............................--/hNN/h.`ys:dmsd:-syos+--+.................../NMMN.``
```/NMMm:...........................:+/--:+s++oo+osoo+/:-..-/+::-................/mMMN:```
````/NMMN:............................-/++/:-..........-//+/-..:+.--............/NMMN/````
`````:NMMN+-.............../+-.............-://////////:-.......+s+::.........-oNMMN:`````
``````:mMMMy-..............:/o-.................................:yo//........-hMMMd-``````
```````.yMMMm+.............:o:++-...............................+y+o-......-+mMMMs.```````
`````````/mMMMd/-...........-++:+/-.---........................-ho+/.....-/dMMMm/`````````
``````````.oNMMMh/............-++:++/////:....................-yo:o-...-+hMMMNo.``````````
````````````.sNMMMdo-...........-++::++:-:/+//:..............:o:/o-..-omMMMNo.````````````
``````````````.omMMMNy+-..........-/+-.:/+/:--:+++/++//:/::/+/-+/.-+hMMMMmo```````````````
`````````````````/hNMMMNho:-...............-:/:-....--::::--..-/ohNMMMNy:`````````````````
```````````````````./hNMMMMmhs/-..........................-/shNMMMMNy/.```````````````````
```````````````````````:sdNMMMMMNdhso+/:----------:/+oshdNMMMMMNho:```````````````````````
``````````````````````````.:+ydNMMMMMMMMMMNNNNNNMMMMMMMMMMmds+:```````````````````````````
````````````````````````````````.:/osyhdmNNMMMMNNmdhyso/:.````````````````````````````````
******************************************************************************************
*                                                                                        *
*                   This logo was graciously delivered by 10003-kun ITT:                 *
*                                                                                        *
*                           http://www.0chan.ru/r/res/9996.html                          *
*                                                                                        *
*****************************************************************************************/
#include "../include/bugurt.h"

#ifdef CONFIG_MP
//========================================================================================
// Балансировщик нагрузки
WEAK core_id_t sched_load_balancer(proc_t * proc, stat_t * stat)
{
    core_id_t core = (core_id_t)0, ret;
    affinity_t mask = (affinity_t)1;
    while( core < (core_id_t)MAX_CORES )
    {
        if( proc->affinity & mask )break;
        mask<<=1;
        core++;
    }
    // Начальное предположение
    stat += (core_id_t)core;
    ret = core++;
    mask<<=1;
    {
        prio_t proc_prio;
        load_t current_load, min_load;

        proc_prio = ((gitem_t *)proc)->group->prio;
        min_load = stat_calc_load( proc_prio, stat++ );
        // Проверка всего остального, тупой поиск минимума
        while( core < (core_id_t)MAX_CORES )
        {
            current_load = stat_calc_load( proc_prio, stat++ );
            if( (proc->affinity & mask) && (current_load < min_load) )
            {
                min_load = current_load;
                ret = core;
            }
            mask<<=1;
            core++;
        }
    }
    return ret;
}
//========================================================================================
//Поиск самой нагруженной структуры stat_t в массиве
WEAK core_id_t sched_highest_load_core( stat_t * stat )
{
    // Начальное предположение
    load_t max_load;
    core_id_t object_core = (core_id_t)0; //процессор с максимальной нагрузкой, с которого эту нагрузку будем снимать
    core_id_t core = (core_id_t)1;
    max_load  = stat_calc_load( (prio_t)BITS_IN_INDEX_T, stat ); // максимальная нагрузка

    while( core < (core_id_t)MAX_CORES )
    {
        load_t current_load;
        current_load = stat_calc_load( (prio_t)BITS_IN_INDEX_T, stat + core );
        if( current_load > max_load )
        {
            max_load = current_load;
            object_core = core;
        }
        core++;
    }

    return object_core;
}
#endif // CONFIG_MP
//========================================================================================
// Инициация
void sched_init(sched_t * sched, proc_t * idle)
{
#ifdef CONFIG_MP
    lock_t * sched_lock;
    sched_lock = &sched->lock;
    spin_init( sched_lock );
    spin_lock( sched_lock );
#endif // CONFIG_MP
    sched->ready = (xlist_t *)sched->plst;
    xlist_init( sched->ready );
    sched->expired = (xlist_t *)sched->plst + 1;
    xlist_init( sched->expired );
    gitem_insert( (gitem_t *)idle, sched->ready );
    idle->flags = PROC_STATE_RUNNING;
    sched->current_proc = idle;
    sched->nested_crit_sec = (count_t)0;//вообще это выполняется при запрещенных прерываниях, но не известно, на этом ли процессоре
#ifdef CONFIG_MP
    spin_free( sched_lock );
    stat_inc( idle, (stat_t *)kernel.stat + idle->core_id );
#endif // CONFIG_MP
}
//========================================================================================
void sched_proc_run( proc_t * proc, flag_t state )
{
    sched_t * sched;
    //Set new state
    proc->flags &= PROC_STATE_CLEAR_MASK;
    proc->flags |= state;
#ifdef CONFIG_MP
    spin_lock( &kernel.stat_lock );
    proc->core_id = sched_load_balancer( proc, (stat_t *)kernel.stat );
    stat_inc( proc, (stat_t *)kernel.stat+proc->core_id );
    spin_free( &kernel.stat_lock );

    sched = (sched_t *)kernel.sched + proc->core_id;
#else
    sched = &kernel.sched;
#endif

    SPIN_LOCK( sched );
    gitem_insert( (gitem_t *)proc, sched->ready );
    SPIN_FREE( sched );

    RESCHED_PROC( proc );
}
//========================================================================================
void sched_proc_stop(proc_t * proc)
{
#ifdef CONFIG_MP
    lock_t * xlist_lock;
    xlist_lock = &((sched_t *)kernel.sched + proc->core_id)->lock;

    spin_lock( &kernel.stat_lock );
    stat_dec( proc, (stat_t *)kernel.stat + proc->core_id );
    spin_free( &kernel.stat_lock );

    spin_lock( xlist_lock );
#endif // CONFIG_MP

    proc->flags &= PROC_STATE_CLEAR_MASK;
    gitem_cut( (gitem_t *)proc );

#ifdef CONFIG_MP
    spin_free( xlist_lock );
#endif // CONFIG_MP
    RESCHED_PROC( proc );
}
//========================================================================================
static void _sched_switch_current( sched_t * sched, proc_t * current_proc )
{
    SPIN_LOCK( current_proc );
    // Хук "сохранение контекста"
    if( current_proc->sv_hook )current_proc->sv_hook( current_proc->arg );
    SPIN_FREE( current_proc );

    SPIN_LOCK( sched );
    // Если список ready опустел, - переключаем списки
    while( sched->ready->index == (index_t)0 )
    {
        // Программа зависнет здесь, если юзер остановит процесс холостого хода.
        xlist_t * buf;
        buf = sched->ready;
        sched->ready = sched->expired;
        sched->expired = buf;
    }
    // Изменять указатель будем при захваченной блокировке,
    // чтобы процессы на других процессорах не прочитали неизвестно что.
    current_proc = (proc_t *)xlist_head( sched->ready ); // Вытесняющая многозадачность же!
    sched->current_proc = current_proc;
    SPIN_FREE( sched );

    SPIN_LOCK( current_proc );
    /***************************************************************************
    Если процесс был в состоянии READY, то он перейдет в состояние RUNNING,
    а если в состоянии W_READY, то он перейдет в состояние W_RUNNING!!!
    ***************************************************************************/
    current_proc->flags &= PROC_STATE_CLEAR_RUN_MASK;
    current_proc->flags |= PROC_STATE_RUNNING;
    //Хук "восстановление контекста"
    if( current_proc->rs_hook )current_proc->rs_hook( current_proc->arg );
    SPIN_FREE( current_proc );
}
/******************************************************************************************
Если у нас есть процессор и отвечающий за управление этим процессором объект типа sched_t,
то изменять поля current_proc, ready, expired мы будем только
с этого самого процессора во время вызовов функций sched_schedule sched_reschedule.

Отсюда правила использования этих функций:

1) Выполнение их должно быть атомарно (иначе будут гонки,
   между обработчиками прерываний системмного таймера и перепланирования).

2) В качестве аргумента передаем только тот объект, который управляет процессами
на исполняющем функции процессоре.
******************************************************************************************/
// Функция планирования, переключает процессы в обработчике системмного таймера
void sched_schedule(void)
{
    proc_t * current_proc;
    sched_t * sched;
    sched = _SCHED_INIT();
    // Меняем только с локального процессора, блокировку sched->lock можно не захватывать!
    current_proc = sched->current_proc;
    // А вот эту блокировку обязательно надо захватить!
    SPIN_LOCK( current_proc );
    // Проверяем, что процесс находится в списке ready
    if( (xlist_t *)((gitem_t *)current_proc)->group->link == sched->ready )
    {
        /***************************************************************************
        Если процесс был в состоянии RUNNING, то он перейдет в состояние STOPED,
        а если в состоянии W_RUNNING, то он перейдет в состояние W_MUT!!!
        ***************************************************************************/
        current_proc->flags &= PROC_STATE_CLEAR_RUN_MASK;
        // Переключаем cписок на следующий за текущим процесс
        SPIN_LOCK( sched );

        xlist_switch( sched->ready, ((gitem_t *)current_proc)->group->prio );

        SPIN_FREE( sched );
        //Проверяем, не истек ли квант времени процесса
        if( current_proc->timer > (timer_t)1 )
        {
            current_proc->timer--;// Не истек, уменьшаем таймер
            /**********************************************************************
            Если процесс был в состоянии STOPED, то он перейдет в состояние READY,
            а если в состоянии W_MUT, то он перейдет в состояние W_READY!!!
            **********************************************************************/
            current_proc->flags |= PROC_STATE_READY;
        }
        else
        {
            flag_t flags;
            // Истек, вырезаем процесс из списка
            SPIN_LOCK( sched );

            gitem_fast_cut( (gitem_t *)current_proc );

            SPIN_FREE( sched );
#if defined(CONFIG_MP) && defined(CONFIG_USE_ALB)
            /***********************************************************************
            Захватываем тут, если используется активная схема балансировки нагрузки.
            В этом случае освобождение этой спин блокировки нужно в обеих ветвях
            оператора if, проверяющего флаги процесса.
            ***********************************************************************/
            spin_lock( &kernel.stat_lock );
            // Обновили статистику после удаления процесса из списка ready
            stat_dec( current_proc, (stat_t *)kernel.stat + current_proc->core_id );
#endif // CONFIG_USE_ALB
            // А что за процесс собственно?
            flags = current_proc->flags;
            if(
                (!(flags & PROC_FLG_RT))
#ifndef CONFIG_HARD_RT
                ||(flags & PROC_FLG_LOCK_MASK)
#endif // CONFIG_HARD_RT

            )
            {
                //Процесс общего назначения, либо он удерживает общий ресурс, переносим в очередь expired и сбрасываем таймер
#if defined(CONFIG_MP) && defined(CONFIG_USE_ALB)
                sched_t * new_sched;
                // Балансировка нагрузки
                current_proc->core_id = sched_load_balancer( current_proc, (stat_t *)kernel.stat );
                // Получаем указатель на новый планиировщик
                new_sched = (sched_t *)kernel.sched + current_proc->core_id;
                // Обновляем нагрузку на новом ядре
                stat_inc( current_proc, (stat_t *)kernel.stat + current_proc->core_id );
                /******************************************************
                В этой ветви освобождение блокировки нужно только
                при использовании активной схемы балансировки нагрузки.
                ******************************************************/
                spin_free( &kernel.stat_lock );

                // Вставляем процесс в список  expired
                SPIN_LOCK( new_sched );
                gitem_insert( (gitem_t *)current_proc, new_sched->expired );
                SPIN_FREE( new_sched );
#else // CONFIG_MP CONFIG_USE_ALB
                // Тупо переносим процесс в список expired
                SPIN_LOCK( sched );

                gitem_insert( (gitem_t *)current_proc, sched->expired );

                SPIN_FREE( sched );

#endif // CONFIG_MP CONFIG_USE_ALB
                current_proc->timer = current_proc->time_quant; // Сбросили таймер!
                /**********************************************************************
                Если процесс был в состоянии STOPED, то он перейдет в состояние READY,
                а если в состоянии W_MUT, то он перейдет в состояние W_READY!!!
                **********************************************************************/
                current_proc->flags |= PROC_STATE_READY;
            }
            else
            {
                // Процесс жесткого реального времени без захваченных ресурсов, тупо снимаем с выполнения, watchdog надо было сбрасыввать
#ifdef CONFIG_MP
#ifndef CONFIG_USE_ALB
                // Обновили статистику после удаления процесса из списка ready
                /*********************************************************
                Если не используется активная схема балансировки нагрузки,
                то захват нужно делать тут, блокировка захватывается только
                в этой ветви оператора if.
                *********************************************************/
                spin_lock( &kernel.stat_lock );
                stat_dec( current_proc, (stat_t *)kernel.stat + current_proc->core_id );
#endif // nCONFIG_USE_ALB
                /*********************************************************
                В этой ветви блокировку в любом случае надо освободить:
                 - если используется активная схема балансировки нагрузки,
                то блокировка была захвачена до входа в if;
                 - если не используется активная схема балансировки нагрузки,
                то блокировка была захвачена в этой ветви if.
                *********************************************************/
                spin_free( &kernel.stat_lock );
#endif // CONFIG_MP
                ((gitem_t *)current_proc)->group->link = (void *)0;// Просто вырезали из списка, как в gitem_cut
#ifdef CONFIG_HARD_RT
                /**********************************************************************
                Если не удерживает общие ресурсы, то он перейдет в состояние W_WD_STOPED,
                иначе перейдет в состояние DEAD/W_DEAD.
                **********************************************************************/
                if( (flags & PROC_FLG_LOCK_MASK) == (flag_t)0 )
                {
                    current_proc->flags = (PROC_FLG_RT|PROC_STATE_WD_STOPED);
                }
                else
                {
                    // переход в состояние DEAD/W_DEAD
                    current_proc->flags |= PROC_STATE_DEAD;
                }
#else // CONFIG_HARD_RT
                /**********************************************************************
                В этой ветке #ifdef CONFIG_HARD_RT, сюда может попасть только процесс
                реального времени, не удерживающий общие ресурсы.

                Если он находится в состоянии W_MUT, то он перейдет в состояние W_WD_STOPED,
                иначе он перейдет в состояние WD_STOPED.
                **********************************************************************/
                if( flags & PROC_STATE_WAIT_MASK )
                {
                    current_proc->flags = (PROC_FLG_RT|PROC_STATE_W_WD_STOPED);
                }
                else
                {
                    current_proc->flags = (PROC_FLG_RT|PROC_STATE_WD_STOPED);
                }
#endif // CONFIG_HARD_RT
            }
        }
    }
    //Текущий процесс более не нужен, освобождаем его блокировку
    SPIN_FREE( current_proc );

    KERNEL_PREEMPT(); // KERNEL_PREEMPT

    _sched_switch_current( sched, current_proc );
}
//========================================================================================
// Функция перепланирования, переключает процессы в обработчике прерывания resched
void sched_reschedule(void)
{
    proc_t * current_proc;
    sched_t * sched;
    sched = _SCHED_INIT();
    // Меняем только с локального процессора, блокировку sched->lock можно не захватывать!
    current_proc = sched->current_proc;
    // А вот эту блокировку обязательно надо захватить!
    SPIN_LOCK( current_proc );

    if( ( current_proc->flags & PROC_STATE_RUN_MASK ) == PROC_STATE_RUNNING )
    {
        current_proc->flags &= PROC_STATE_CLEAR_RUN_MASK;
        current_proc->flags |= PROC_STATE_READY;
    }

    SPIN_FREE( current_proc );
    _sched_switch_current( sched, current_proc );
}
/**********************************************************************************************
                                      SYSCALL_PROC_YELD
**********************************************************************************************/
index_t sched_yeld(void)
{
    volatile index_t ret;
    syscall_bugurt( SYSCALL_PROC_YELD, (void *)&ret );
    return ret;
}
//========================================================================================
index_t _sched_yeld( void )
{
    index_t ret,mask;
    sched_t * sched;
    proc_t * proc;

    sched = _SCHED_INIT();
    proc = sched->current_proc;

    SPIN_LOCK( sched );
    ret = sched->expired->index;
    SPIN_FREE( sched );

    KERNEL_PREEMPT();// KERNEL_PREEMPT

    SPIN_LOCK( proc );

    if( PROC_RUN_TEST( proc ) )
    {
        SPIN_LOCK( sched );

        if( proc->flags & PROC_FLG_RT )
        {
            xlist_switch( (xlist_t *)((gitem_t *)proc)->group->link, ((gitem_t *)proc)->group->prio );
        }
        else
        {
            gitem_cut( (gitem_t *)proc );
            gitem_insert( (gitem_t *)proc, sched->expired );
        }
        SPIN_FREE( sched );
    }
    proc->timer = proc->time_quant; // reset timer
    RESCHED_PROC( proc );
    SPIN_FREE( proc );

    KERNEL_PREEMPT(); // KERNEL_PREEMPT

    SPIN_LOCK( sched );
    ret |= sched->ready->index;
    SPIN_FREE( sched );

    KERNEL_PREEMPT(); // KERNEL_PREEMPT

    mask = ~(index_t)1;
    mask <<= ((gitem_t *)proc)->group->prio;

    return (ret & (~mask)); // Mask all lower prio processes
}
//========================================================================================
void scall_sched_yeld( void * arg )
{
    *((index_t *)arg) = _sched_yeld();
}

#if defined(CONFIG_MP) && (!defined(CONFIG_USE_ALB))
/************************************
  "Ленивые" балансировщики нагрузки

,предназначены для запуска из тел
процессов, если не используется
активная схема балансировки нагрузки.

Можно использовать только один,
или оба в различных комбинациях

************************************/
void _sched_lazy_load_balancer(core_id_t object_core)
{
    sched_t * sched;
    proc_t * proc;
    sched = (sched_t *)kernel.sched + object_core;

    //Смотрим, есть чи что в списке expired, если есть, будем переносить нагрузку, если нет - выход
    disable_interrupts();

    SPIN_LOCK( sched );

    if(sched->expired->index == (index_t)0)
    {
        SPIN_FREE( sched );
        enable_interrupts();
        return;
    }
    proc = (proc_t *)xlist_head( sched->expired );// Процесс, который будем переносить на другой процессор. Требования реального времени этот процесс не выполняет.

    SPIN_FREE( sched );
    enable_interrupts();

    disable_interrupts();
    SPIN_LOCK( proc );
    // Пока захватывалась блокировка процесса, его могли остановить, подстраховываемся.
    if( PROC_RUN_TEST( proc ) )
    {
        // Остановили выполнение процесса на старом процессоре
        SPIN_LOCK( sched );

        gitem_fast_cut( (gitem_t *)proc );

        SPIN_FREE( sched );

        resched(object_core); // Процесс мог быть поставлен на выполнение, пока мы захватывали его блокировку, перепланируем

        // Проводим операции над статистикой
        spin_lock( &kernel.stat_lock );

        stat_dec( proc, (stat_t *)kernel.stat + object_core );

        object_core = sched_load_balancer( proc, (stat_t *)kernel.stat );// Теперь, это тот процессор, на который будем переносить процесс
        sched = (sched_t *)kernel.sched + object_core;//Теперь это планировщик, на который мы переносим процесс
        stat_inc( proc, (stat_t *)kernel.stat + object_core );

        spin_free( &kernel.stat_lock );

        // Переносим процесс на новый процессор, продолжаем выполнение там. Перепланировку не делаем, проуесс не выполняет требования реального времени.
        proc->core_id = object_core;

        SPIN_LOCK( sched );

        gitem_insert( (gitem_t *)proc, sched->expired );

        SPIN_FREE( sched );
    }
    SPIN_FREE( proc );
    enable_interrupts();
}
//========================================================================================
// Глобальный
void sched_lazy_global_load_balancer(void)
{
    core_id_t object_core;
    // Поиск самого нагруженного процессора
    disable_interrupts();
    spin_lock( &kernel.stat_lock );

    object_core = sched_highest_load_core( (stat_t *)kernel.stat );

    spin_free( &kernel.stat_lock );
    enable_interrupts();
    // Перенос нагрузки на самый не нагруженный процессор
    _sched_lazy_load_balancer( object_core );
}
//========================================================================================
// Локальный
void sched_lazy_local_load_balancer(void)
{
    _sched_lazy_load_balancer( current_core() );
}
#endif // CONFIG_MP CONFIG_USE_ALB
