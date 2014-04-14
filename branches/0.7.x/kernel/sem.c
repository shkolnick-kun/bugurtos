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
/**********************************************************************************************
                                       SYSCALL_SEM_INIT
**********************************************************************************************/
// Инициализация

/*!
\~russian
\brief
Параметр системного вызова #SYSCALL_SEM_INIT.

\~english
\brief
A #SYSCALL_SEM_INIT argument structure.
*/
typedef struct {
    sem_t * sem;    /*!< \~russian указатель на семафор. \~english A pointer to a semaphore.*/
    count_t count;  /*!< \~russian начальное значение счетчика семафора. \~english A semaphore counter initial value.*/
}sem_init_arg_t;

void sem_init( sem_t * sem, count_t count )
{
    volatile sem_init_arg_t scarg;
    scarg.sem = sem;
    scarg.count = count;
    syscall_bugurt( SYSCALL_SEM_INIT, (void *)&scarg );
}
//========================================================================================
void sem_init_isr( sem_t * sem, count_t count )
{
    SPIN_INIT( sem );
    SPIN_LOCK( sem );

    xlist_init( (xlist_t *)sem );
    sem->counter = count;
    SPIN_UNLOCK( sem );
}
//========================================================================================
void scall_sem_init( void * arg )
{
    sem_init_isr( ((sem_init_arg_t *)arg)->sem, ((sem_init_arg_t *)arg)->count );
}
/**********************************************************************************************
                                         SYSCALL_SEM_LOCK
**********************************************************************************************/
/*!
\~russian
\brief
Параметр системных вызовов #SYSCALL_SEM_LOCK и #SYSCALL_SEM_TRY_LOCK.

\~english
\brief
An argument structure for #SYSCALL_SEM_LOCK and #SYSCALL_SEM_TRY_LOCK.
*/
typedef struct {
    sem_t * sem;        /*!< \~russian  указатель на семафор. \~english A pointer to a semaphore.*/
    bool_t ret;         /*!< \~russian  хранилище результата выполнения операции. \~english A storage for a result. */
}sem_lock_arg_t;
//========================================================================================
bool_t sem_lock( sem_t * sem )
{

    volatile sem_lock_arg_t scarg;
    scarg.sem = sem;
    syscall_bugurt( SYSCALL_SEM_LOCK, (void *)&scarg );
    return scarg.ret;
}
//========================================================================================
bool_t _sem_lock( sem_t * sem )
{
    bool_t ret = (bool_t)0;
    proc_t * proc;
    proc = current_proc();
    // Выставляем флаг захватат семафора
    SPIN_LOCK( proc );
    _proc_stop_flags_set( proc, PROC_FLG_SEM );
    SPIN_UNLOCK( proc );

    KERNEL_PREEMPT(); /// KERNEL_PREEMPT

    // Собственно захват семафора
    SPIN_LOCK( sem );
    SPIN_LOCK( proc );
    if( sem->counter != 0 )
    {
        sem->counter--;
        ret = (bool_t)1;
        _proc_run( proc, PROC_STATE_READY );
    }
    else
    {
        proc->flags |= PROC_STATE_W_SEM;
        gitem_insert( (gitem_t *)proc, (xlist_t *)sem );
    }
    SPIN_UNLOCK( proc );
    SPIN_UNLOCK( sem );
    return ret;
}
//========================================================================================
void scall_sem_lock( void * arg )
{
    ((sem_lock_arg_t *)arg)->ret = _sem_lock( ((sem_lock_arg_t *)arg)->sem );
}
/**********************************************************************************************
                                       SYSCALL_SEM_TRY_LOCK
**********************************************************************************************/
void scall_sem_try_lock( void * arg )
{
    ((sem_lock_arg_t *)arg)->ret = _sem_try_lock( ((sem_lock_arg_t *)arg)->sem );
}
//========================================================================================
bool_t _sem_try_lock( sem_t * sem )
{
    bool_t ret = (bool_t)0;
    SPIN_LOCK( sem );
    if( sem->counter != 0 )
    {
        proc_t * proc;
        proc = current_proc();

        sem->counter--;
        ret = (bool_t)1;
        // Выставляем флаг захватат семафора
        SPIN_LOCK( proc );

        if( PROC_RUN_TEST( proc ) )
        {
            proc->flags |= PROC_FLG_SEM;
        }
        else
        {
            proc->flags |= (PROC_FLG_SEM|PROC_FLG_PRE_STOP);
            _proc_run( proc, PROC_STATE_READY );
        }

        SPIN_UNLOCK( proc );
    }
    SPIN_UNLOCK( sem );
    return ret;
}
//========================================================================================
bool_t sem_try_lock( sem_t * sem )
{

    volatile sem_lock_arg_t scarg;
    scarg.sem = sem;
    syscall_bugurt( SYSCALL_SEM_TRY_LOCK, (void *)&scarg );
    return scarg.ret;
}
/**********************************************************************************************
                                       SYSCALL_SEM_UNLOCK
**********************************************************************************************/
void sem_unlock( sem_t * sem )
{
    syscall_bugurt( SYSCALL_SEM_UNLOCK, (void *)sem );
}
//========================================================================================
void sem_unlock_isr( sem_t * sem )
{
    proc_t * proc;
    SPIN_LOCK( sem );

    if( ((xlist_t *)sem)->index == (index_t)0  )
    {
        sem->counter++;
        goto end;
    }
    proc = (proc_t *)xlist_head((xlist_t *)sem);

    SPIN_LOCK( proc );

    gitem_cut( (gitem_t *)proc );
    _proc_run( proc, PROC_STATE_READY );

    SPIN_UNLOCK( proc );
end:
    SPIN_UNLOCK( sem );
}
//========================================================================================
void scall_sem_unlock( void * arg )
{
    sem_unlock_isr( (sem_t *)arg );
}