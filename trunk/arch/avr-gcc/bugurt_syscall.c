/**************************************************************************
    BuguRTOS-0.3.x(Bugurt real time operating system)
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
#include "bugurt_kernel.h"

#include <avr/pgmspace.h>
///=================================================================
///        ОБРАБОТЧИКИ СИСТЕМНЫХ ВЫЗОВОВ, МАССИВ УКАЗАТЕЛЕЙ
///=================================================================
unsigned char syscall_num = 0;
void * syscall_arg = (void *)0;

const code_t syscall_routine[] PROGMEM =
{
    // Упавление процессами
    scall_proc_init,
    scall_proc_run,
    scall_proc_restart,
    scall_proc_stop,
    scall_proc_self_stop,
    scall_proc_terminate,
    scall_proc_flag_stop,
    // Сигналы
    scall_sig_init,
    scall_sig_wait,
    scall_sig_signal,
    scall_sig_broadcast,
    // Семафоры
    scall_sem_init,
    scall_sem_lock,
    scall_sem_unlock,
    // Мьютексы
    scall_mutex_init,
    scall_mutex_lock,
    scall_mutex_try_lock,
    scall_mutex_unlock
};

void do_syscall(void)
{
    if( syscall_num != (unsigned char)0 )
    {
        code_t syscall_func;
        syscall_func = (code_t)pgm_read_word(syscall_routine + syscall_num);
        syscall_func(syscall_arg);
        syscall_num = (unsigned char)0;
    }
}

#ifdef SYSCALL_ISR
/// Если используется программное прерывание - вот его обработчик
#ifdef RAMPZ
#define PROC_STACK_OFFSET 8
#else
#define PROC_STACK_OFFSET 7
#endif
static unsigned char * tos;
static unsigned short temp;

typedef struct
{
    unsigned char num;
    void * arg;
} syscall_data_t;

BUGURT_INTERRUPT(SYSCALL_ISR)
{
    /// Извлечение syscall_num и syscall_arg из стека процесса
    tos = (unsigned char *)proc_sp + PROC_STACK_OFFSET;
    temp = (unsigned short)*tos++;
    temp <<= 8;
    temp |= (unsigned short)*tos;

    syscall_num = ((syscall_data_t *)temp)->num;
    syscall_arg = ((syscall_data_t *)temp)->arg;

    do_syscall();
}

syscall_data_t * _syscall( syscall_data_t * arg )
{
    cli();
    raise_syscall_interrupt();
    sei();
    return arg;
}

static syscall_data_t scdata;
void syscall( unsigned char num, void * arg )
{
     scdata.num = num;
     scdata.arg = arg;
     _syscall( &scdata );
     SYSCALL_DELLAY();
}
#else
///Если не используется программное прерывание - прямая передача управления
void syscall( unsigned char num, void * arg )
{
    cli();
    syscall_num = num;
    syscall_arg = arg;
    kernel_isr = do_syscall;
    process_kernel_switch();
}
#endif

///=================================================================
///                 ОБРАБОТЧИКИ СИСТЕМНЫХ ВЫЗОВОВ
///=================================================================
///                   Управление процессами
//0
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
                  )
{
    static proc_init_arg_t scarg;

    scarg.proc = proc;
    scarg.pmain = pmain;
    scarg.sv_hook = sv_hook;
    scarg.rs_hook = rs_hook;
    scarg.arg = arg;
    scarg.sstart = sstart;
    scarg.prio = prio;
    scarg.time_quant = time_quant;
    scarg.is_rt = is_rt;

    syscall(0,(void *)&scarg);
}
//---------------------------------------------------------------------------------------------
//1
void scall_proc_run( void * arg )
{
    ((proc_runtime_arg_t *)arg)->scall_ret = proc_run_isr( ((proc_runtime_arg_t *)arg)->proc );
}
bool_t proc_run( proc_t * proc )
{
    proc_runtime_arg_t scarg;
    scarg.proc = proc;
    scarg.scall_ret = (bool_t)0;

    syscall(1,(void *)&scarg);
    return scarg.scall_ret;
}
//---------------------------------------------------------------------------------------------
//2
void scall_proc_restart( void * arg )
{
    ((proc_runtime_arg_t *)arg)->scall_ret = proc_restart_isr( ((proc_runtime_arg_t *)arg)->proc );
}
bool_t proc_restart( proc_t * proc )
{
    proc_runtime_arg_t scarg;
    scarg.proc = proc;

    syscall(2,(void *)&scarg);
    return scarg.scall_ret;
}
//---------------------------------------------------------------------------------------------
//3
void scall_proc_stop( void * arg )
{
    ((proc_runtime_arg_t *)arg)->scall_ret = proc_stop_isr( ((proc_runtime_arg_t *)arg)->proc );
}
bool_t proc_stop( proc_t * proc )
{
    proc_runtime_arg_t scarg;
    scarg.proc = proc;

    syscall(3,(void *)&scarg);
    return scarg.scall_ret;
}

//---------------------------------------------------------------------------------------------
//4
void scall_proc_self_stop( void * arg )
{
    proc_t * proc = kernel.sched.current_proc;
    _proc_stop( proc );
}
void proc_self_stop(void)
{
    syscall(4,(void *)1);
}
//---------------------------------------------------------------------------------------------
//5
/// Останов процесса после выхода из pmain, для обертки proc_run_wrapper
void scall_proc_terminate( void * arg )
{
    proc_t * proc = (proc_t *)arg;
    // Обрабатываем флаги
    // Нельзя выходить из pmain не освободив все захваченные ресурсы, за это процесс будет "убит"!
    if( proc->flags & PROC_FLG_HOLD ) proc->flags |= PROC_FLG_DEAD;
    // В противном случае - просто завершаем процесс
    else proc->flags |= PROC_FLG_END;
    proc->flags &= ~(PROC_FLG_PRE_END|PROC_FLG_RUN);
    // Останов
    _proc_stop_( proc );
    // Выполнить перепланировку
    resched();
}
void proc_run_wrapper( proc_t * proc )
{
    //Атомарно читаем pmain и arg
    cli();
    code_t pmain = proc->pmain;
    void * arg = proc->arg;
    sei();
    //Выполняем pmain
    pmain( arg );
    // Завершаем процесс
    syscall(5,(void *)proc);
}
//---------------------------------------------------------------------------------------------
//6
void scall_proc_flag_stop( void * arg )
{
    _proc_flag_stop_isr( *((flag_t *)arg) );
}
///=================================================================
///                         Сигналы
//7
void scall_sig_init( void * arg )
{
    sig_init_isr( (sig_t *)arg );
}
void sig_init( sig_t * sig )
{
    syscall( 7, (void *)sig );
}
//---------------------------------------------------------------------------------------------
//8
void scall_sig_wait( void * arg )
{
    sig_wait_stage_1_isr( (sig_t *)arg );
}
void sig_wait( sig_t * sig )
{
    const flag_t mask = ~PROC_FLG_WAIT;
    syscall( 8, (void *)sig );
    syscall( 6, (void *)&mask );/// Останов в случае необходимости
}
//---------------------------------------------------------------------------------------------
//9
void scall_sig_signal( void * arg )
{
    sig_signal_isr( (sig_t *)arg );
}
void sig_signal( sig_t * sig )
{
    syscall( 9, (void *)sig );
}
//---------------------------------------------------------------------------------------------
//10
void scall_sig_broadcast( void * arg )
{
    sig_broadcast_isr( (sig_t *)arg );
}
void sig_broadcast( sig_t * sig )
{
    syscall( 10, (void *)sig );
}
///=================================================================
///                         Семафоры
//11
void scall_sem_init( void * arg )
{
    sem_init_isr( ((sem_init_arg_t *)arg)->sem, ((sem_init_arg_t *)arg)->count );
}
void sem_init( sem_t * sem, count_t count )
{
    sem_init_arg_t scarg;
    scarg.sem = sem;
    scarg.count = count;
    syscall( 11, (void *)&scarg );
}
//----------------------------------------------------------------------
//12
void scall_sem_lock( void * arg )
{
    ((sem_lock_arg_t *)arg)->scall_ret = _sem_lock_stage_1( ((sem_lock_arg_t *)arg)->sem );
}
const flag_t all_flags_mask = ~(flag_t)0;
bool_t sem_lock( sem_t * sem, bool_t stop )
{

    sem_lock_arg_t scarg;
    scarg.sem = sem;
    syscall( 12, (void *)&scarg );
    if( stop != (bool_t)0 )syscall( 6, (void *)&all_flags_mask );///Останов по флагам, если надо
    return scarg.scall_ret;
}
//----------------------------------------------------------------------
//13
void scall_sem_unlock( void * arg )
{
    _sem_unlock( (sem_t *)arg );
}
void sem_unlock( sem_t * sem, bool_t stop )
{
    syscall( 13, (void *)sem );
    if( stop != (bool_t)0 )syscall( 6, (void *)&all_flags_mask );///Останов по флагам, если надо
}
///=================================================================
///                         Мьютексы
//14
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
    syscall( 14, (void *)&scarg );
}
//----------------------------------------------------------------------
//15
void scall_mutex_lock(void * arg)
{
    ((mutex_lock_arg_t *)arg)->scall_ret = _mutex_lock( ((mutex_lock_arg_t *)arg)->mutex );
}
bool_t mutex_lock( mutex_t * mutex )
{
    mutex_lock_arg_t scarg;
    scarg.mutex = mutex;
    syscall( 15, (void *)&scarg );
    return scarg.scall_ret;
}
// Захват
//----------------------------------------------------------------------
//16
void scall_mutex_try_lock(void * arg)
{
    ((mutex_lock_arg_t *)arg)->scall_ret = _mutex_try_lock( ((mutex_lock_arg_t *)arg)->mutex );
}
// Попытка захвата
bool_t mutex_try_lock( mutex_t * mutex )
{
    mutex_lock_arg_t scarg;
    scarg.mutex = mutex;
    syscall( 16, (void *)&scarg );
    return scarg.scall_ret;
}
//----------------------------------------------------------------------
//17
void scall_mutex_unlock(void * arg)
{
    _mutex_unlock( (mutex_t *)arg );
}
// Освобождение
void mutex_unlock( mutex_t * mutex )
{
    syscall( 17, (void *)mutex );
}
