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
const code_t syscall_routine[] =
{
    // Упавление процессами
    scall_proc_init,
    scall_proc_run,
    scall_proc_restart,
    scall_proc_stop,
    scall_proc_self_stop,
    scall_proc_terminate,
    scall_proc_flag_stop,
    scall_proc_reset_watchdog,
    // Сигналы
    scall_sig_init,
    scall_sig_wait,
    scall_sig_wakeup,
    scall_sig_signal,
    scall_sig_broadcast,
    // Семафоры
    scall_sem_init,
    scall_sem_lock,
    scall_sem_try_lock,
    scall_sem_unlock,
    // Мьютексы
    scall_mutex_init,
    scall_mutex_lock,
    scall_mutex_try_lock,
    scall_mutex_unlock,
    // IPC
    scall_ipc_wait,
    scall_ipc_send,
    scall_ipc_exchange
};

#ifdef CONFIG_MP
// In MP system do_syscall must be reentrant.
void do_syscall( syscall_t syscall_num, void * syscall_arg )
#else
//In single processor system reentrancy is not necessary.
syscall_t syscall_num = (syscall_t)0;
void * syscall_arg = (void *)0;

void do_syscall( void )
#endif // CONFIG_MP
{
    if( syscall_num != (syscall_t)0 )
    {
        syscall_num--;
        syscall_routine[syscall_num](syscall_arg);
        syscall_num = (syscall_t)0;
    }
}

/**********************************************************************************************
                                  System call handlers !!!
***********************************************************************************************
                                    Process control !!!
**********************************************************************************************/
/// SYSCALL_PROC_INIT
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
    proc_init_arg_t scarg;
#else
    static proc_init_arg_t scarg;
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
/**********************************************************************************************
                                       SYSCALL_PROC_RUN
**********************************************************************************************/
void scall_proc_run( void * arg )
{
    ((proc_runtime_arg_t *)arg)->ret = proc_run_isr( ((proc_runtime_arg_t *)arg)->proc );
}
bool_t proc_run( proc_t * proc )
{
    proc_runtime_arg_t scarg;
    scarg.proc = proc;
    syscall_bugurt( SYSCALL_PROC_RUN, (void *)&scarg );
    return scarg.ret;
}
/**********************************************************************************************
                                       SYSCALL_PROC_RESTART
**********************************************************************************************/
void scall_proc_restart( void * arg )
{
    ((proc_runtime_arg_t *)arg)->ret = proc_restart_isr( ((proc_runtime_arg_t *)arg)->proc );
}
bool_t proc_restart( proc_t * proc )
{
    proc_runtime_arg_t scarg;
    scarg.proc = proc;
    syscall_bugurt( SYSCALL_PROC_RESTART, (void *)&scarg );
    return scarg.ret;
}
/**********************************************************************************************
                                        SYSCALL_PROC_STOP
**********************************************************************************************/
void scall_proc_stop( void * arg )
{
    ((proc_runtime_arg_t *)arg)->ret = proc_stop_isr( ((proc_runtime_arg_t *)arg)->proc );
}
bool_t proc_stop( proc_t * proc )
{
    proc_runtime_arg_t scarg;
    scarg.proc = proc;
    syscall_bugurt( SYSCALL_PROC_STOP, (void *)&scarg);
    return scarg.ret;
}
/**********************************************************************************************
                                    SYSCALL_PROC_SELF_STOP
**********************************************************************************************/
void scall_proc_self_stop( void * arg )
{
    proc_t * proc = current_proc();
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif
    _proc_stop( proc );
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
}
void proc_self_stop(void)
{
    syscall_bugurt( SYSCALL_PROC_SELF_STOP, (void *)1 );
}
/**********************************************************************************************
                                    SYSCALL_PROC_TERMINATE
**********************************************************************************************/
// Останов процесса после выхода из pmain, для обертки proc_run_wrapper
void scall_proc_terminate( void * arg )
{
    _proc_terminate((proc_t *)arg);
}
void proc_run_wrapper( proc_t * proc )
{
    code_t pmain;
    void * arg;
    //Атомарно читаем pmain и arg
    disable_interrupts();
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif // CONFIG_MP
    pmain = proc->pmain;
    arg = proc->arg;
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif // CONFIG_MP
    enable_interrupts();
    //Выполняем pmain
    pmain( arg );
    // Завершаем процесс
    syscall_bugurt( SYSCALL_PROC_TERMINATE, (void *)proc );
}
/**********************************************************************************************
                                       SYSCALL_PROC_FLAG_STOP
**********************************************************************************************/
void scall_proc_flag_stop( void * arg )
{
    _proc_flag_stop( *((flag_t *)arg) );
}
void proc_flag_stop( flag_t mask )
{
    flag_t msk;
    msk = mask;
    syscall_bugurt( SYSCALL_PROC_FLAG_STOP, (void *)&msk );
}
/**********************************************************************************************
                                       SYSCALL_PROC_RESET_WATCHDOG
**********************************************************************************************/
void scall_proc_reset_watchdog( void * arg )
{
    _proc_reset_watchdog();
}
void proc_reset_watchdog(void)
{
    syscall_bugurt( SYSCALL_PROC_RESET_WATCHDOG, (void *)0 );
}
/**********************************************************************************************
                                            Сигналы
***********************************************************************************************
                                      SYSCALL_PROC_RESTART
**********************************************************************************************/
void scall_sig_init( void * arg )
{
    sig_init_isr( (sig_t *)arg );
}
void sig_init( sig_t * sig )
{
    syscall_bugurt( SYSCALL_SIG_INIT, (void *)sig );
}
/**********************************************************************************************
                                       SYSCALL_SIG_WAIT
**********************************************************************************************/
void scall_sig_wait( void * arg )
{
    _sig_wait_prologue( (sig_t *)arg );
}
/**********************************************************************************************
                                       SYSCALL_SIG_WAKEUP
**********************************************************************************************/
void scall_sig_wakeup( void *arg )
{
    _sig_wait_epilogue();
    _proc_flag_stop( PROC_FLG_WAIT );
}

void sig_wait( sig_t * sig )
{
    syscall_bugurt( SYSCALL_SIG_WAIT, (void *)sig );
    syscall_bugurt( SYSCALL_SIG_WAKEUP, (void *)0 );// Останов в случае необходимости
}
/**********************************************************************************************
                                       SYSCALL_SIG_SIGNAL
**********************************************************************************************/
void scall_sig_signal( void * arg )
{
    sig_signal_isr( (sig_t *)arg );
}
void sig_signal( sig_t * sig )
{
    syscall_bugurt( SYSCALL_SIG_SIGNAL, (void *)sig );
}
/**********************************************************************************************
                                       SYSCALL_SIG_BROADCAST
**********************************************************************************************/
void scall_sig_broadcast( void * arg )
{
    sig_broadcast_isr( (sig_t *)arg );
}
void sig_broadcast( sig_t * sig )
{
    syscall_bugurt( SYSCALL_SIG_BROADCAST, (void *)sig );
}
/**********************************************************************************************
                                           Семафоры
***********************************************************************************************
                                       SYSCALL_SEM_INIT
**********************************************************************************************/
void scall_sem_init( void * arg )
{
    sem_init_isr( ((sem_init_arg_t *)arg)->sem, ((sem_init_arg_t *)arg)->count );
}
void sem_init( sem_t * sem, count_t count )
{
    sem_init_arg_t scarg;
    scarg.sem = sem;
    scarg.count = count;
    syscall_bugurt( SYSCALL_SEM_INIT, (void *)&scarg );
}
/**********************************************************************************************
                                         SYSCALL_SEM_LOCK
**********************************************************************************************/
void scall_sem_lock( void * arg )
{
    ((sem_lock_arg_t *)arg)->ret = _sem_lock( ((sem_lock_arg_t *)arg)->sem );
}
bool_t sem_lock( sem_t * sem )
{

    sem_lock_arg_t scarg;
    scarg.sem = sem;
    syscall_bugurt( SYSCALL_SEM_LOCK, (void *)&scarg );
    return scarg.ret;
}
/**********************************************************************************************
                                       SYSCALL_SEM_TRY_LOCK
**********************************************************************************************/
void scall_sem_try_lock( void * arg )
{
    ((sem_lock_arg_t *)arg)->ret = _sem_try_lock( ((sem_lock_arg_t *)arg)->sem );
}
bool_t sem_try_lock( sem_t * sem )
{

    sem_lock_arg_t scarg;
    scarg.sem = sem;
    syscall_bugurt( SYSCALL_SEM_TRY_LOCK, (void *)&scarg );
    return scarg.ret;
}
/**********************************************************************************************
                                       SYSCALL_SEM_UNLOCK
**********************************************************************************************/
void scall_sem_unlock( void * arg )
{
    sem_unlock_isr( (sem_t *)arg );
}
void sem_unlock( sem_t * sem )
{
    syscall_bugurt( SYSCALL_SEM_UNLOCK, (void *)sem );
}
/**********************************************************************************************
                                          Мьютексы
***********************************************************************************************
                                     SYSCALL_MUTEX_INIT
**********************************************************************************************/
void scall_mutex_init(void * arg)
{
    mutex_init_isr(
               ((mutex_init_arg_t *)arg)->mutex
#ifdef CONFIG_USE_HIGHEST_LOCKER
               ,((mutex_init_arg_t *)arg)->prio
#endif // CONFIG_USE_HIGHEST_LOCKER
               );
}
void mutex_init(
                        mutex_t * mutex
#ifdef CONFIG_USE_HIGHEST_LOCKER
                        ,prio_t prio
#endif // CONFIG_USE_HIGHEST_LOCKER
                        )
{
    mutex_init_arg_t scarg;
    scarg.mutex = mutex;
#ifdef CONFIG_USE_HIGHEST_LOCKER
    scarg.prio = prio;
#endif // CONFIG_USE_HIGHEST_LOCKER
    syscall_bugurt( SYSCALL_MUTEX_INIT, (void *)&scarg );
}
/**********************************************************************************************
                                    SYSCALL_MUTEX_LOCK
**********************************************************************************************/
void scall_mutex_lock(void * arg)
{
    ((mutex_lock_arg_t *)arg)->ret = _mutex_lock( ((mutex_lock_arg_t *)arg)->mutex );
}
bool_t mutex_lock( mutex_t * mutex )
{
    mutex_lock_arg_t scarg;
    scarg.mutex = mutex;
    syscall_bugurt( SYSCALL_MUTEX_LOCK, (void *)&scarg );
    return scarg.ret;
}
// Захват
/**********************************************************************************************
                                    SYSCALL_MUTEX_TRY_LOCK
**********************************************************************************************/
void scall_mutex_try_lock(void * arg)
{
    ((mutex_lock_arg_t *)arg)->ret = _mutex_try_lock( ((mutex_lock_arg_t *)arg)->mutex );
}
// Попытка захвата
bool_t mutex_try_lock( mutex_t * mutex )
{
    mutex_lock_arg_t scarg;
    scarg.mutex = mutex;
    syscall_bugurt( SYSCALL_MUTEX_TRY_LOCK, (void *)&scarg );
    return scarg.ret;
}
/**********************************************************************************************
                                   SYSCALL_MUTEX_UNLOCK
**********************************************************************************************/
void scall_mutex_unlock(void * arg)
{
    _mutex_unlock( (mutex_t *)arg );
}
// Освобождение
void mutex_unlock( mutex_t * mutex )
{
    syscall_bugurt( SYSCALL_MUTEX_UNLOCK, (void *)mutex );
}
/**********************************************************************************************
                                           IPC
***********************************************************************************************
                                       SYSCALL_IPC_WAIT
**********************************************************************************************/
void scall_ipc_wait(void * arg)
{
    _ipc_wait( arg );
}
ipc_data_t ipc_wait( void )
{
    ipc_data_t ret = (ipc_data_t)0;
    syscall_bugurt( SYSCALL_IPC_WAIT, (void *)&ret );
    return ret;
}
/**********************************************************************************************
                                       SYSCALL_IPC_SEND
**********************************************************************************************/
void scall_ipc_send(void * arg)
{
    ((ipc_send_arg_t *)arg)->ret = ipc_send_isr( ((ipc_send_arg_t *)arg)->proc, ((ipc_send_arg_t *)arg)->data );
}
bool_t ipc_send( proc_t * proc, ipc_data_t data )
{
    volatile ipc_send_arg_t arg;
    arg.proc = proc;
    arg.data = data;
    syscall_bugurt( SYSCALL_IPC_SEND, (void *)&arg );
    return arg.ret;
}
/**********************************************************************************************
                                    SYSCALL_IPC_EXCHANGE
**********************************************************************************************/
void scall_ipc_exchange(void * arg)
{
    ((ipc_send_arg_t *)arg)->ret = _ipc_exchange( ((ipc_send_arg_t *)arg)->proc, ((ipc_send_arg_t *)arg)->data, ((ipc_exchange_arg_t *)arg)->receive );
}
bool_t ipc_exchange( proc_t * proc, ipc_data_t send, ipc_data_t * receive )
{
    volatile ipc_exchange_arg_t arg;
    arg.send.proc = proc;
    arg.send.data = send;
    arg.receive = receive;
    syscall_bugurt( SYSCALL_IPC_EXCHANGE, (void *)&arg );
    return arg.send.ret;
}

