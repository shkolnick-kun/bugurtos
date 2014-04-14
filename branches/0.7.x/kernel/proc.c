/**************************************************************************
    BuguRTOS-0.6.x(Bugurt real time operating system)
    Copyright (C) 2013  anonimous

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
                              Internal Usage functions!!!
*****************************************************************************************/
void _proc_lres_inc( proc_t * proc, prio_t prio )
{
    if( proc->lres.index == (index_t)0 )proc->flags |= PROC_FLG_MUTEX;
    pcounter_inc( &proc->lres, prio );
}
//========================================================================================
void _proc_lres_dec( proc_t * proc ,prio_t prio )
{
    pcounter_dec( &proc->lres, prio );
    if( proc->lres.index == (index_t)0 )proc->flags &= ~PROC_FLG_MUTEX;
}
//========================================================================================
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
//========================================================================================
void _proc_run( proc_t * proc, flag_t state )
{
    sched_t * sched;
    //Set new state
    proc->flags &= PROC_STATE_CLEAR_MASK;
    proc->flags |= state;
#ifdef CONFIG_MP
    spin_lock( &kernel.stat_lock );
    proc->core_id = sched_load_balancer( proc, (stat_t *)kernel.stat );
    stat_inc( proc, (stat_t *)kernel.stat+proc->core_id );
    spin_unlock( &kernel.stat_lock );

    sched = (sched_t *)kernel.sched + proc->core_id;
#else
    sched = &kernel.sched;
#endif

    SPIN_LOCK( sched );
    gitem_insert( (gitem_t *)proc, sched->ready );
    SPIN_UNLOCK( sched );

    RESCHED_PROC( proc );
}
//========================================================================================
void _proc_stop(proc_t * proc)
{
#ifdef CONFIG_MP
    lock_t * xlist_lock;
    xlist_lock = &((sched_t *)kernel.sched + proc->core_id)->lock;

    spin_lock( &kernel.stat_lock );
    stat_dec( proc, (stat_t *)kernel.stat + proc->core_id );
    spin_unlock( &kernel.stat_lock );

    spin_lock( xlist_lock );
#endif // CONFIG_MP

    proc->flags &= PROC_STATE_CLEAR_MASK;
    gitem_cut( (gitem_t *)proc );

#ifdef CONFIG_MP
    spin_unlock( xlist_lock );
#endif // CONFIG_MP
    RESCHED_PROC( proc );
}
//========================================================================================
static void _proc_stop_ensure( proc_t * proc )
{
    if( PROC_RUN_TEST( proc ) )
    {
        _proc_stop( proc );
    }
}
//========================================================================================
void _proc_stop_flags_set( proc_t * proc, flag_t mask )
{
    // Проверяем, не был ли процесс остановлен где-нибудь еще.
    if( PROC_RUN_TEST( proc ) )
    {
        // Не был, можно и нужно остановить.
        _proc_stop( proc );
        proc->flags |= mask;
    }
    else
    {
        // Был, останавливать не нужно, надо выставить флаг PROC_FLG_PRE_STOP
        proc->flags |= (flag_t)(mask|PROC_FLG_PRE_STOP);
    }
}
/**********************************************************************************************
                                    Process control !!!
**********************************************************************************************/
// Инициация, тут все понятно.
/// SYSCALL_PROC_INIT

/*!
\~russian
\brief
Параметр системного вызова #SYSCALL_PROC_INIT.

Содержит информацию о процессе, и его свойствах.

\~english
\brief
An argument for #SYSCALL_PROC_INIT.

A process initialization structure.
Contents an information about a process.
*/
typedef struct {
    proc_t * proc;      /*!< \~russian Указатель на инициируемый процесс. \~english A ponter to a initialized process.*/
    code_t pmain;       /*!< \~russian Указатель на главную функцию процесса. \~english A pointer to a process "main" routine.*/
    code_t sv_hook;     /*!< \~russian Указатель на хук proc->sv_hook. \~english A context save hook pointer.*/
    code_t rs_hook;     /*!< \~russian Указатель на хук proc->rs_hook. \~english A context save hook pointer.*//*!< Хук, исполняется планировщиком перед восстановлением контекста процесса. */
    void * arg;         /*!< \~russian Указатель на аргумент. \~english An argument pointer.*/
    stack_t *sstart;    /*!< \~russian Указатель на дно стека процесса. \~english A process stack bottom pointer.*/
    prio_t prio;        /*!< \~russian Приоритет. \~english A process priority.*/
    timer_t time_quant; /*!< \~russian Квант времени. \~english A process time slice.*/
    bool_t is_rt;       /*! \~russian Флаг реального времени, если true, значит процесс будет иметь поведение RT. \~english A real time flag. If frue, then a process is scheduled in a real time manner.*/
#ifdef CONFIG_MP
    affinity_t affinity;/*!< \~russian Афинность. \~english A process affinity.*/
#endif // CONFIG_MP
} proc_init_arg_t;

void proc_init(
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
#ifdef CONFIG_MP
    volatile proc_init_arg_t scarg;
#else
    static volatile  proc_init_arg_t scarg;
    disable_interrupts(); // прерывания будут разрешены на выходе из syscall_bugurt()
#endif
    scarg.proc = proc;
    scarg.pmain = pmain;
    scarg.sv_hook = sv_hook;
    scarg.rs_hook = rs_hook;
    scarg.arg = arg;
    scarg.sstart = sstart;
    scarg.prio = prio;
    scarg.time_quant = time_quant;
    scarg.is_rt = is_rt;
#ifdef CONFIG_MP
    scarg.affinity = affinity;
#endif
    syscall_bugurt( SYSCALL_PROC_INIT, (void *)&scarg );
}
//========================================================================================
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

    proc->base_prio = prio;
    proc->time_quant = time_quant;
    proc->timer = time_quant;
    proc->buf = (void *)0;
#ifdef CONFIG_MP
    proc->core_id = (core_id_t)0;
    proc->affinity = affinity;
#endif // CONFIG_MP
    proc->pmain = pmain;
    proc->sv_hook = sv_hook;
    proc->rs_hook = rs_hook;
    proc->arg = arg;
    proc->sstart = sstart;
    if( sstart )proc->spointer = proc_stack_init(sstart, (code_t)pmain, (void *)arg, (void (*)(void))proc_terminate);

    SPIN_UNLOCK( proc );
}
//========================================================================================
void scall_proc_init( void * arg )
{
    proc_init_isr(
              ((proc_init_arg_t *)arg)->proc,
              ((proc_init_arg_t *)arg)->pmain,
              ((proc_init_arg_t *)arg)->sv_hook,
              ((proc_init_arg_t *)arg)->rs_hook,
              ((proc_init_arg_t *)arg)->arg,
              ((proc_init_arg_t *)arg)->sstart,
              ((proc_init_arg_t *)arg)->prio,
              ((proc_init_arg_t *)arg)->time_quant,
              ((proc_init_arg_t *)arg)->is_rt
#ifdef CONFIG_MP
              ,((proc_init_arg_t *)arg)-> affinity
#endif // CONFIG_MP
              );
}
/**********************************************************************************************
                                       SYSCALL_PROC_RUN
**********************************************************************************************/
/*!
\~russian
\brief
Параметр системных вызовов #SYSCALL_PROC_RUN, #SYSCALL_PROC_RESTART, #SYSCALL_PROC_STOP.

\~english
\brief
An argument for system calls #SYSCALL_PROC_RUN, #SYSCALL_PROC_RESTART, #SYSCALL_PROC_STOP.
*/
typedef struct{
    proc_t * proc;      /*!< \~russian Указатель на процесс. \~english A pointer to a process. */
    bool_t ret;         /*!< \~russian Результат выполнения системного вызова. \~english A result storage. */
}proc_runtime_arg_t;


bool_t proc_run( proc_t * proc )
{
    volatile proc_runtime_arg_t scarg;
    scarg.proc = proc;
    syscall_bugurt( SYSCALL_PROC_RUN, (void *)&scarg );
    return scarg.ret;
}
//========================================================================================
// Функция общего пользования - запуск процесса из обработчика прерывания, прерывания должны быть запрещены во время запуска
bool_t proc_run_isr(proc_t * proc)
{
    bool_t ret = (bool_t)1;

    SPIN_LOCK( proc );

    if( (proc->flags & PROC_STATE_MASK) != PROC_STATE_STOPED )
    {
        ret = (bool_t)0;
        goto end;
    }
    _proc_run( proc, PROC_STATE_READY );
end:

    SPIN_UNLOCK( proc );

    return ret;
}
//========================================================================================
void scall_proc_run( void * arg )
{
    ((proc_runtime_arg_t *)arg)->ret = proc_run_isr( ((proc_runtime_arg_t *)arg)->proc );
}
/**********************************************************************************************
                                       SYSCALL_PROC_RESTART
**********************************************************************************************/
bool_t proc_restart( proc_t * proc )
{
    volatile proc_runtime_arg_t scarg;
    scarg.proc = proc;
    syscall_bugurt( SYSCALL_PROC_RESTART, (void *)&scarg );
    return scarg.ret;
}
//========================================================================================
// Перезепуск процесса из обработчика прерываний, прерывания должны быть запрещены
bool_t proc_restart_isr(proc_t * proc)
{
    bool_t ret = (bool_t)1;

    SPIN_LOCK( proc );

    if( proc->flags & (PROC_FLG_LOCK_MASK|PROC_STATE_RESTART_MASK) )
    {
        ret = (bool_t)0;
        goto end;
    }
    proc->flags = ( proc->flags & PROC_FLG_RT )?PROC_FLG_RT:(flag_t)0;

    PROC_LRES_INIT( proc );

    proc->timer = proc->time_quant;

    if( proc->sstart )proc->spointer = proc_stack_init( proc->sstart, (code_t)proc->pmain, (void *)proc->arg, (void (*)(void))proc_terminate );
    _proc_run( proc, PROC_STATE_READY );
end:

    SPIN_UNLOCK( proc );

    return ret;
}
//========================================================================================
void scall_proc_restart( void * arg )
{
    ((proc_runtime_arg_t *)arg)->ret = proc_restart_isr( ((proc_runtime_arg_t *)arg)->proc );
}
/**********************************************************************************************
                                        SYSCALL_PROC_STOP
**********************************************************************************************/
bool_t proc_stop( proc_t * proc )
{
    volatile proc_runtime_arg_t scarg;
    scarg.proc = proc;
    syscall_bugurt( SYSCALL_PROC_STOP, (void *)&scarg);
    return scarg.ret;
}
//========================================================================================
// Останов процесса из обработчика прерываний, прерывания должны быть запрещены
bool_t proc_stop_isr(proc_t * proc)
{
    bool_t ret = (bool_t)0;

    SPIN_LOCK( proc );
    //Проверка флагов
    //В случае PROC_FLG_MUTEX или PROC_FLG_SEM будем обрабатывать PROC_FLG_PRE_STOP при освобождении общего ресурса.
    if( proc->flags & (PROC_FLG_LOCK_MASK|PROC_FLG_PRE_STOP|PROC_STATE_WAIT_MASK) )proc->flags |= PROC_FLG_PRE_STOP;
    else
    {
        _proc_stop_ensure( proc );
        ret = (bool_t)1;
    }

    SPIN_UNLOCK( proc );

    return ret;
}
//========================================================================================
void scall_proc_stop( void * arg )
{
    ((proc_runtime_arg_t *)arg)->ret = proc_stop_isr( ((proc_runtime_arg_t *)arg)->proc );
}
/**********************************************************************************************
                                       SYSCALL_PROC_FLAG_STOP
**********************************************************************************************/
void proc_flag_stop( flag_t mask )
{
    flag_t msk;
    msk = mask;
    syscall_bugurt( SYSCALL_PROC_FLAG_STOP, (void *)&msk );
}
//========================================================================================
// Обработка флага останова процесса, для использования с семафорами, мьютексами и сигналами.
void _proc_flag_stop( flag_t mask )
{
    proc_t * proc;
    proc = current_proc();

    SPIN_LOCK( proc );

    if(  PROC_PRE_STOP_TEST(proc)  )
    {
        /*
        Если был запрошен останов целевого процесса,
        и целевой процесс не удерживает общие ресурсы,
        то мы остановим процесс
        */
        _proc_stop_ensure( proc );
        proc->flags &= ~PROC_FLG_PRE_STOP;
    }
    proc->flags &= ~mask;

    SPIN_UNLOCK( proc );
}
//========================================================================================
void scall_proc_flag_stop( void * arg )
{
    _proc_flag_stop( *((flag_t *)arg) );
}
/**********************************************************************************************
                                    SYSCALL_PROC_SELF_STOP
**********************************************************************************************/
void proc_self_stop(void)
{
    syscall_bugurt( SYSCALL_PROC_SELF_STOP, (void *)1 );
}
//========================================================================================
void _proc_self_stop(void)
{
    proc_t * proc;
    proc = current_proc();

    SPIN_LOCK( proc );

    _proc_stop_ensure( proc );

    SPIN_UNLOCK( proc );
}
//========================================================================================
void scall_proc_self_stop( void * arg )
{
    _proc_self_stop();
}
/**********************************************************************************************
                                    SYSCALL_PROC_TERMINATE
**********************************************************************************************/
// Останов процесса после выхода из pmain, для обертки proc_run_wrapper
void proc_terminate( void )
{
    syscall_bugurt( SYSCALL_PROC_TERMINATE, (void *)0 );
}
//========================================================================================
void _proc_terminate( void )
{
    proc_t * proc;
    proc = current_proc();

    SPIN_LOCK( proc );

    _proc_stop_ensure( proc );
    // Обрабатываем флаги
    // Нельзя выходить из pmain не освободив все захваченные ресурсы, за это процесс будет "убит"!
    if( proc->flags & PROC_FLG_LOCK_MASK ) proc->flags |= PROC_STATE_DEAD;
    // В противном случае - просто завершаем процесс
    else proc->flags |= PROC_STATE_END;
    proc->flags &= ~PROC_FLG_PRE_STOP;

    SPIN_UNLOCK( proc );
}
//========================================================================================
void scall_proc_terminate( void * arg )
{
    _proc_terminate();
}
/**********************************************************************************************
                                       SYSCALL_PROC_RESET_WATCHDOG
**********************************************************************************************/
void proc_reset_watchdog(void)
{
    syscall_bugurt( SYSCALL_PROC_RESET_WATCHDOG, (void *)0 );
}
//========================================================================================
void _proc_reset_watchdog( void )
{
    proc_t * proc;
    proc = current_proc();

    SPIN_LOCK( proc );

    if( proc->flags & PROC_FLG_RT )proc->timer = proc->time_quant;

    SPIN_UNLOCK( proc );
}
//========================================================================================
void scall_proc_reset_watchdog( void * arg )
{
    _proc_reset_watchdog();
}
/**********************************************************************************************/
