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
static void _proc_mutex_lock(proc_t * proc, mutex_t * mutex )
{
        mutex->free = (bool_t)0;
        mutex->owner = proc;

        SPIN_LOCK( proc );

        PROC_LRES_INC( proc, PROC_PRIO_LOWEST );
        _proc_dont_stop( proc, PROC_FLG_MUTEX );

        SPIN_FREE( proc );
}
/**********************************************************************************************
                                          Мьютексы
***********************************************************************************************
                                     SYSCALL_MUTEX_INIT
**********************************************************************************************/
void mutex_init( mutex_t * mutex )
{
    disable_interrupts();
    mutex_init_isr( mutex );
    enable_interrupts();
}
//========================================================================================
void mutex_init_isr( mutex_t * mutex )
{
    SPIN_INIT( mutex );
    SPIN_LOCK( mutex );
    xlist_init( (xlist_t *)mutex );
    mutex->free = (bool_t)1;
    mutex->owner = (proc_t *)0;
    SPIN_FREE( mutex );
}
/**********************************************************************************************
                                    SYSCALL_MUTEX_LOCK
**********************************************************************************************/
// Захват
/*!
\~russian
\brief
Параметр системных вызовов #SYSCALL_MUTEX_LOCK и #SYSCALL_MUTEX_TRY_LOCK.

\~english
\brief
An argument structure for #SYSCALL_MUTEX_LOCK and #SYSCALL_MUTEX_TRY_LOCK.
*/
typedef struct {
    mutex_t * mutex;    /*!< \~russian указатель на мьютекс. \~english A pointer to a mutex. */
    bool_t ret;         /*!< \~russian хранилище результата выполнения операции. \~english A storage for a result. */
} mutex_lock_arg_t;
//========================================================================================
bool_t mutex_lock( mutex_t * mutex )
{
    volatile mutex_lock_arg_t scarg;
    scarg.mutex = mutex;

    do
    {
        syscall_bugurt( SYSCALL_MUTEX_LOCK, (void *)&scarg );
    }
    while( scarg.ret );

    return 1;
}
//========================================================================================

#ifdef CONFIG_MP

static void mutex_prio_prop_hook( mutex_t * mutex )
{
    SPIN_FREE( (mutex->owner) );
    SPIN_FREE( mutex );
}
#define MUTEX_PROC_PRIO_PROPAGATE(p,m) _proc_prio_propagate( p, (code_t)mutex_prio_prop_hook, (void *)m )

#else

#define MUTEX_PROC_PRIO_PROPAGATE(p,m) _proc_prio_propagate( p )

#endif


bool_t _mutex_lock( mutex_t * mutex )
{
    proc_t * proc;
    proc = current_proc();

    SPIN_LOCK( mutex );

    if( mutex->free )_proc_mutex_lock( proc, mutex ); //A proc gets the mutex immediatly!
    else
    {
        if( mutex->owner == proc ) goto end; //Finaly a proc has got the mutex, no more itterations!
        else
        {
            prio_t old_prio;
            old_prio = MUTEX_PRIO( mutex );

            SPIN_LOCK( proc );

            proc->buf = (void *)mutex;
            _proc_stop_flags_set( proc, (PROC_FLG_MUTEX|PROC_STATE_W_MUT) );
            gitem_insert( (gitem_t *)proc, (xlist_t *)mutex );

            SPIN_FREE( proc );

            proc = mutex->owner;
            SPIN_LOCK( proc );

            PROC_LRES_DEC( proc, old_prio );
            PROC_LRES_INC( proc, MUTEX_PRIO( mutex ) );

            MUTEX_PROC_PRIO_PROPAGATE( proc, mutex );

            return 1; // Next iteration...
        }
    }
end:
    SPIN_FREE( mutex );
    return 0;
}
//========================================================================================
void scall_mutex_lock(void * arg)
{
    ((mutex_lock_arg_t *)arg)->ret = _mutex_lock( ((mutex_lock_arg_t *)arg)->mutex );
}
/**********************************************************************************************
                                    SYSCALL_MUTEX_TRY_LOCK
**********************************************************************************************/
// Попытка захвата
bool_t mutex_try_lock( mutex_t * mutex )
{
    volatile mutex_lock_arg_t scarg;
    scarg.mutex = mutex;
    syscall_bugurt( SYSCALL_MUTEX_TRY_LOCK, (void *)&scarg );
    return scarg.ret;
}
//========================================================================================
bool_t _mutex_try_lock( mutex_t * mutex )
{
    bool_t ret;
    proc_t * proc;
    proc = current_proc();

    SPIN_LOCK( mutex );

    ret = mutex->free;

    if( ret )_proc_mutex_lock( proc, mutex );

    SPIN_FREE( mutex );
    return ret;
}
//========================================================================================
void scall_mutex_try_lock(void * arg)
{
    ((mutex_lock_arg_t *)arg)->ret = _mutex_try_lock( ((mutex_lock_arg_t *)arg)->mutex );
}
/**********************************************************************************************
                                   SYSCALL_MUTEX_FREE
**********************************************************************************************/
// Освобождение
void mutex_free( mutex_t * mutex )
{
    syscall_bugurt( SYSCALL_MUTEX_FREE, (void *)mutex );
}
//========================================================================================
void _mutex_free( mutex_t *  mutex )
{
    proc_t * proc;
    prio_t prio;

    SPIN_LOCK( mutex );
    proc = current_proc();
    prio = MUTEX_PRIO( mutex );

    SPIN_LOCK(proc);
    // т.к. установлен флаг PROC_FLG_MUTEX, процесс можно безопасно остановить.
    sched_proc_stop( proc );
    PROC_LRES_DEC( proc, prio );
    _proc_prio_control_stoped( proc );

    if( proc->lres.index == (index_t)0 ) proc->flags &= PROC_FLG_MUTEX;
    // Если проготовлен и готов к остановке - останавливаем
    if(  PROC_PRE_STOP_TEST(proc)  )
    {
        proc->flags &= ~PROC_FLG_PRE_STOP;
    }
    else
    {
        // Не было запроса останова, или процесс еще не освободил ресурсы, запускаем обратно.
        sched_proc_run( proc, PROC_STATE_READY );
    }

    SPIN_FREE( proc );
    SPIN_FREE( mutex );

    KERNEL_PREEMPT(); /// KERNEL_PREEMPT

    SPIN_LOCK( mutex );
    // Обрабока самого мьютекса
    if( ((xlist_t *)mutex)->index == (index_t)0  )
    {
        // Список ожидающих пуст, выходим
        mutex->free = (bool_t)1;
        mutex->owner = (proc_t *)0;
        goto end;
    }
    // Список ожидающих не пуст, запускаем голову
    proc = (proc_t *)xlist_head( (xlist_t *)mutex );

    mutex->owner = proc;

    SPIN_LOCK( proc );

    proc->buf = (void *)0; //It doesn't wait on mutex any more.

    if( PROC_GET_STATE( proc ) == PROC_STATE_W_PCHANGE )
    {
        PROC_SET_STATE ( proc, PROC_STATE_PCHANGE );
        PROC_LRES_INC( proc, MUTEX_PRIO( mutex ) );  //mutex prio has changed
    }
    else
    {
        gitem_cut( (gitem_t *)proc );
        PROC_LRES_INC( proc, MUTEX_PRIO( mutex ) );  //mutex prio has changed
        _proc_prio_control_stoped( proc );
        sched_proc_run( proc, PROC_STATE_READY );
    }

    SPIN_FREE( proc );
end:
    SPIN_FREE( mutex );
}
//========================================================================================
void scall_mutex_free(void * arg)
{
    _mutex_free( (mutex_t *)arg );
}
