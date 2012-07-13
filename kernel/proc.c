/**************************************************************************
    BuguRTOS-0.4.x(Bugurt real time operating system)
    Copyright (C) 2011  anonimous

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
/*****************************************************************************************
                               Internal usage functions !!!
*****************************************************************************************/
// Инициация, тут все понятно.
void proc_init_isr(
    proc_t * proc, //Указатель на инициируемый процесс
    code_t pmain,
    code_t sv_hook,
    code_t rs_hook,
    void * arg,
    stack_t *sstart,
    prio_t prio,
    timer_t time_quant,
    bool_t is_rt // если true, значит процесс будет иметть поведение RT
#ifdef CONFIG_MP
    ,affinity_t affinity
#endif // CONFIG_MP
)
{
    SPIN_INIT( proc );
    SPIN_LOCK( proc );

    gitem_init( (gitem_t *)proc, prio );
    proc->flags = ( is_rt )?PROC_FLG_RT:(flag_t)0;

    PROC_LRES_INIT( proc );
#ifdef CONFIG_USE_HIGHEST_LOCKER
    proc->base_prio = prio;
#endif
    proc->time_quant = time_quant;
    proc->timer = time_quant;
#ifdef CONFIG_MP
    proc->core_id = (core_id_t)0;
    proc->affinity = affinity;
#endif // CONFIG_MP
    proc->pmain = pmain;
    proc->sv_hook = sv_hook;
    proc->rs_hook = rs_hook;
    proc->arg = arg;
    proc->sstart = sstart;
    if( sstart )proc->spointer = proc_stack_init(sstart, (code_t)proc_run_wrapper, (void *)proc);

    SPIN_UNLOCK( proc );
}
//  Функция для внутреннего использования - собственно запуск процесса
#ifdef CONFIG_MP
void _proc_run_( proc_t * proc )
{
    sched_t * proc_sched;
    proc_sched = (sched_t *)kernel.sched + proc->core_id;
    SPIN_LOCK( proc_sched );
    gitem_insert( (gitem_t *)proc, proc_sched->ready );
    SPIN_UNLOCK( proc_sched );
}
#endif // CONFIG_MP

void _proc_run( proc_t * proc )
{
    proc->flags |= PROC_FLG_RUN;
#ifdef CONFIG_MP
    spin_lock( &kernel.stat_lock );
    proc->core_id = sched_load_balancer( proc, (stat_t *)kernel.stat );
    stat_inc( proc, (stat_t *)kernel.stat+proc->core_id );
    spin_unlock( &kernel.stat_lock );
#endif
    _proc_run_( proc );

    RESCHED_PROC( proc );
}
// Функция общего пользования - запуск процесса из обработчика прерывания, прерывания должны быть запрещены во время запуска
bool_t proc_run_isr(proc_t * proc)
{
    bool_t ret = (bool_t)1;

    SPIN_LOCK( proc );

    if( proc->flags & (PROC_FLG_RUN|PROC_FLG_QUEUE|PROC_FLG_WAIT|PROC_FLG_IPCW|PROC_FLG_END|PROC_FLG_DEAD|PROC_FLG_WD_STOP) )
    {
        ret = (bool_t)0;
        goto end;
    }
    _proc_run( proc );
end:

    SPIN_UNLOCK( proc );

    return ret;
}
// Перезепуск процесса из обработчика прерываний, прерывания должны быть запрещены
bool_t proc_restart_isr(proc_t * proc)
{
    bool_t ret = (bool_t)1;

    SPIN_LOCK( proc );

    if( proc->flags & (PROC_FLG_RUN|PROC_FLG_MUTEX|PROC_FLG_SEM|PROC_FLG_QUEUE|PROC_FLG_WAIT|PROC_FLG_IPCW|PROC_FLG_DEAD) )
    {
        ret = (bool_t)0;
        goto end;
    }
    proc->flags = ( proc->flags & PROC_FLG_RT )?PROC_FLG_RT:(flag_t)0;

    PROC_LRES_INIT( proc );

    proc->timer = proc->time_quant;

    if( proc->sstart )proc->spointer = proc_stack_init( proc->sstart, (code_t)proc_run_wrapper, (void *)proc );
    _proc_run( proc );
end:

    SPIN_UNLOCK( proc );

    return ret;
}
// Функция для внутреннего использования, останов процесса

#ifdef CONFIG_MP
void _proc_stop_(proc_t * proc)
{
    spin_lock( &kernel.stat_lock );
    stat_dec( proc, (stat_t *)kernel.stat + proc->core_id );
    spin_unlock( &kernel.stat_lock );
    {
        lock_t * xlist_lock;
        xlist_lock = &((sched_t *)kernel.sched + proc->core_id)->lock;
        spin_lock( xlist_lock );
        gitem_cut( (gitem_t *)proc );
        spin_unlock( xlist_lock );
    }
}
#endif // CONFIG_MP

void _proc_stop(proc_t * proc)
{
    proc->flags &= ~PROC_FLG_RUN;
    _proc_stop_( proc );
    RESCHED_PROC( proc );
}
// Останов процесса из обработчика прерываний, прерывания должны быть запрещены
bool_t proc_stop_isr(proc_t * proc)
{
    bool_t ret = (bool_t)0;

    SPIN_LOCK( proc );
    //Проверка флагов
    //В случчае PROC_FLG_WAIT будем обрабатывать PROC_FLG_PRE_END на выходе из sig_wait.
    //В случае PROC_FLG_MUTEX или PROC_FLG_SEM будем обрабатывать PROC_FLG_PRE_STOP при освобождении общего ресурса.
    //В случае ожидания IPC флаг будем обрабатывать при попытке передать данные или указатель целевому процессу.
    if( proc->flags & (PROC_FLG_MUTEX|PROC_FLG_SEM|PROC_FLG_QUEUE|PROC_FLG_WAIT|PROC_FLG_IPCW) )proc->flags |= PROC_FLG_PRE_STOP;
    else if( proc->flags & PROC_FLG_RUN )
    {
        _proc_stop( proc );
        ret = (bool_t)1;
    }

    SPIN_UNLOCK( proc );

    return ret;
}
// Обработка флага останова процесса, для использования с семафорами, мьютексами и сигналами.
void _proc_flag_stop( flag_t mask )
{
    proc_t * proc;
    proc = current_proc();

    SPIN_LOCK( proc );

    proc->flags &= ~mask;
    if(  ( proc->flags & PROC_FLG_PRE_STOP ) && (!(proc->flags & PROC_FLG_MUTEX))  )
    {
        /*
        Если был запрошен останов целевого процесса,
        и целевой процесс не удерживает общие ресурсы,
        то мы остановим процесс
        */
        proc->flags &= ~PROC_FLG_PRE_STOP;
        _proc_stop( proc );
    }

    SPIN_UNLOCK( proc );

}

void _proc_terminate( proc_t * proc )
{

    SPIN_LOCK( proc );

    // Обрабатываем флаги
    // Нельзя выходить из pmain не освободив все захваченные ресурсы, за это процесс будет "убит"!
    if( proc->flags & PROC_FLG_MUTEX ) proc->flags |= PROC_FLG_DEAD;
    // В противном случае - просто завершаем процесс
    else proc->flags |= PROC_FLG_END;
    proc->flags &= ~(PROC_FLG_PRE_STOP|PROC_FLG_RUN);
    // Останов
    _proc_stop_( proc );
    // Выполнить перепланировку
    RESCHED_PROC( proc );

    SPIN_UNLOCK( proc );
}

void _proc_reset_watchdog( void )
{
    proc_t * proc;
    proc = current_proc();

    SPIN_LOCK( proc );

    if( proc->flags & PROC_FLG_RT )proc->timer = proc->time_quant;

    SPIN_UNLOCK( proc );
}

void _proc_lres_inc(
    proc_t * proc
#ifdef CONFIG_USE_HIGHEST_LOCKER
    ,prio_t prio
#endif
)
{
#ifdef CONFIG_USE_HIGHEST_LOCKER
    if( proc->lres.index == (index_t)0 )proc->flags |= PROC_FLG_MUTEX;
    pcounter_inc( &proc->lres, prio );
#else
    if( proc->lres == (count_t)0 )proc->flags |= PROC_FLG_MUTEX;
    proc->lres++;
#endif
}

void _proc_lres_dec(
    proc_t * proc
#ifdef CONFIG_USE_HIGHEST_LOCKER
    ,prio_t prio
#endif
)
{
#ifdef CONFIG_USE_HIGHEST_LOCKER
    pcounter_dec( &proc->lres, prio );
    if( proc->lres.index == (index_t)0 )proc->flags &= ~PROC_FLG_MUTEX;
#else
    if( proc->lres!= (count_t)0 )proc->lres--;
    if( proc->lres == (count_t)0 )proc->flags &= ~PROC_FLG_MUTEX;
#endif
}

#ifdef CONFIG_USE_HIGHEST_LOCKER
// Будет использоваться в mutex-ах и т.п., процесс должен сам вызывать эту функцию, при этом он должен быть вырезан из списка выполняющихся.
void _proc_prio_control_stoped( proc_t * proc )
{
    if(proc->lres.index != (index_t)0)
    {
        prio_t locker_prio;
        locker_prio = index_search( proc->lres.index );
        ((gitem_t *)proc)->group->prio = ( locker_prio < proc->base_prio )?locker_prio:proc->base_prio;
    }
    else
    {
        ((gitem_t *)proc)->group->prio = proc->base_prio;
    }
}
void _proc_prio_control_running( proc_t * proc )
{
    prio_t new_prio;
    if(proc->lres.index != (index_t)0)
    {
        prio_t locker_prio;
        locker_prio = index_search( proc->lres.index );
        new_prio = ( locker_prio < proc->base_prio )?locker_prio:proc->base_prio;
    }
    else
    {
        new_prio = proc->base_prio;
    }
    if(((gitem_t *)proc)->group->prio != new_prio)
    {
        _proc_stop_( proc );
        ((gitem_t *)proc)->group->prio = new_prio;
#ifdef CONFIG_MP
        spin_lock( &kernel.stat_lock );
        stat_inc( proc, (stat_t *)kernel.stat+proc->core_id );
        spin_unlock( &kernel.stat_lock );
#endif
        _proc_run_( proc );
        RESCHED_PROC( proc );
    }
}
#endif

#if defined(CONFIG_MP) && (!defined(CONFIG_USE_ALB))
/************************************
  "Ленивые" балансировщики нагрузки

,предназначены для запуска из тел
процессов, если не используется
активная схема балансировки нагрузки.

Можно использовать только один,
или оба в различных комбинациях

************************************/
void _proc_lazy_load_balancer(core_id_t object_core)
{
    sched_t * sched;
    proc_t * proc;
    sched = (sched_t *)kernel.sched + object_core;

    //Смотрим, есть чи что в списке expired, если есть, будем переносить нагрузку, если нет - выход
    disable_interrupts();
    SPIN_LOCK( sched );
    if(sched->expired->index == (index_t)0)
    {
        SPIN_UNLOCK( sched );
        enable_interrupts();
        return;
    }
    proc = (proc_t *)xlist_head( sched->expired );// Процесс, который будем переносить на другой процессор. Требования реального времени этот процесс не выполняет.
    SPIN_UNLOCK( sched );
    enable_interrupts();

    disable_interrupts();
    SPIN_LOCK( proc );
    // Пока захватывалась блокировка процесса, его могли остановить, подстраховываемся.
    if( proc->flags & PROC_FLG_RUN )
    {
        // Остановили выполнение процесса на старом процессоре
        SPIN_LOCK( sched );
        gitem_fast_cut( (gitem_t *)proc );
        SPIN_UNLOCK( sched );
        resched(object_core); // Процесс мог быть поставлен на выполнение, пока мы захватывали его блокировку, перепланируем

        // Проводим операции над статистикой
        spin_lock( &kernel.stat_lock );

        stat_dec( proc, (stat_t *)kernel.stat + object_core );

        object_core = sched_load_balancer( proc, (stat_t *)kernel.stat );// Теперь, это тот процессор, на который будем переносить процесс
        sched = (sched_t *)kernel.sched + object_core;//Теперь это планировщик, на который мы переносим процесс
        stat_inc( proc, (stat_t *)kernel.stat + object_core );

        spin_unlock( &kernel.stat_lock );

        // Переносим процесс на новый процессор, продолжаем выполнение там. Перепланировку не делаем, проуесс не выполняет требования реального времени.
        proc->core_id = object_core;
        SPIN_LOCK( sched );
        gitem_insert( (gitem_t *)proc, sched->expired );
        SPIN_UNLOCK( sched );
    }
    SPIN_UNLOCK( proc );
    enable_interrupts();
}
// Глобальный
void proc_lazy_global_load_balancer(void)
{
    core_id_t object_core;
    // Поиск самого нагруженного процессора
    disable_interrupts();
    spin_lock( &kernel.stat_lock );
    object_core = sched_highest_load_core( (stat_t *)kernel.stat );
    spin_unlock( &kernel.stat_lock );
    enable_interrupts();
    // Перенос нагрузки на самый не нагруженный процессор
    _proc_lazy_load_balancer( object_core );
}

// Локальный
void proc_lazy_local_load_balancer(void)
{
    _proc_lazy_load_balancer( current_core() );
}
#endif // CONFIG_MP CONFIG_USE_ALB
