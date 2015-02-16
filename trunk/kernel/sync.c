/**************************************************************************
    BuguRTOS-0.8.x(Bugurt real time operating system)
    Copyright (C) 2015  anonimous

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
#include "bugurt.h"

prio_t _sync_prio( sync_t * sync )
{
    prio_t sprio; //sync prio

    sprio = sync->prio;
    if( (((xlist_t *)sync)->index) )
    {
        prio_t wprio; //wait list prio

        wprio = index_search(((xlist_t *)sync)->index);
        return (wprio < sprio)?wprio:sprio;
    }
    else
    {
        return sprio;
    }
}

#ifdef CONFIG_MP
#define PROC_PRIO_PROP_HOOK() hook(hook_arg)
void _proc_prio_propagate( proc_t * proc, code_t hook, void * hook_arg )
#else
#define PROC_PRIO_PROP_HOOK()
void _proc_prio_propagate( proc_t * proc )
#endif
{
    switch( PROC_GET_STATE( proc ) )
    {
    case PROC_STATE_READY:
    case PROC_STATE_RUNNING:
    case PROC_STATE_WD_READY:
    case PROC_STATE_WD_RUNNING:
    case PROC_STATE_SYNC_READY:
    case PROC_STATE_SYNC_RUNNING:
    case PROC_STATE_PI_READY:
    case PROC_STATE_PI_RUNNING:
    {
        flag_t state;
        state = PROC_GET_STATE( proc );
        _proc_stop_ensure( proc );
        _proc_prio_control_stoped( proc );
        sched_proc_run( proc, state );
        PROC_PRIO_PROP_HOOK();
        break;
    }
    case PROC_STATE_SYNC_SLEEP:
    {
        sync_t * sync;
        prio_t old_prio, new_prio;
        PROC_SET_STATE( proc, PROC_STATE_PI_PEND );  // Ensure that process will not run, and stay in a sync sleep list!

        sync = proc->sync;

        PROC_PRIO_PROP_HOOK();

        KERNEL_PREEMPT();

        if( sync == (sync_t *)0 )
        {
            // A process was trying to free a dirty sync and blocked
            SPIN_LOCK( proc );

            _proc_prio_control_stoped( proc );
            sched_proc_run( proc, PROC_STATE_READY ); // A process must unlock the sync.

            SPIN_FREE( proc );
            break; //Break the switch!
        }

        SPIN_LOCK( sync );

        old_prio = SYNC_PRIO( sync ); // Get sync prio to keep sync->owner priority data consistent

        SPIN_LOCK( proc );

        pitem_cut( (pitem_t *)proc );
        _proc_prio_control_stoped( proc );
        if( PROC_GET_STATE(proc) == PROC_STATE_PI_PEND )
        {
            if( sync->owner )
            {
                // Start priority inheritanse transaction.
                sync->dirty++;
                sched_proc_run( proc, PROC_STATE_PI_READY );
            }
            else
            {
                // Put back into sync->sleep
                PROC_SET_STATE( proc, PROC_STATE_SYNC_SLEEP );
                pitem_insert( (pitem_t *)proc, (xlist_t *)sync );
            }
        }
        else
        {
            // Finish process wakeup
            sched_proc_run( proc, PROC_STATE_SYNC_READY );
        }

        SPIN_FREE( proc );

        proc = sync->owner;
        if( proc )
        {
            // Keep priority data consistent
            new_prio = SYNC_PRIO( sync );
            if( new_prio != old_prio )
            {
                SPIN_LOCK( proc );
                PROC_LRES_DEC( proc, old_prio );
                PROC_LRES_INC( proc, new_prio );
                SPIN_FREE( proc );
            }
        }
        SPIN_FREE( sync );

        break;
    }
    case PROC_STATE_SYNC_WAIT:
    {
        _proc_prio_control_stoped( proc );
        sched_proc_run( proc, PROC_STATE_READY );
        PROC_PRIO_PROP_HOOK();
        break;
    }
    case PROC_STATE_STOPED:
    case PROC_STATE_END:
    case PROC_STATE_WD_STOPED:
    case PROC_STATE_DEAD:

    {
        _proc_prio_control_stoped( proc );
    }
    case PROC_STATE_PI_PEND:
    case PROC_STATE_PI_DONE:
    default:
    {
        PROC_PRIO_PROP_HOOK();
    }
    }
}

/**********************************************************************************************
                                       SYSCALL_PROC_SET_PRIO
**********************************************************************************************/
/*!
\~russian
\brief
Параметр системного вызова #SYSCALL_PROC_SET_PRIO.

\~english
\brief
An argument for system call #SYSCALL_PROC_SET_PRIO.
*/
typedef struct
{
    proc_t * proc; /*!< \~russian Указатель на процесс. \~english A pointer to a process. */
    prio_t prio;   /*!< \~russian Приоритет. \~english Priority. */
}
proc_set_prio_arg_t;

void proc_set_prio( proc_t * proc, prio_t prio )
{
    volatile proc_set_prio_arg_t arg;
    arg.proc = proc;
    arg.prio = prio;
    syscall_bugurt( SYSCALL_PROC_SET_PRIO, (void *)&arg );
}
//========================================================================================
#ifdef CONFIG_MP
#define PROC_PROC_PRIO_PROPAGATE(p) _proc_prio_propagate( p, (code_t)spin_free, (void *)&p->lock )
#else
#define PROC_PROC_PRIO_PROPAGATE(p) _proc_prio_propagate( p )
#endif
void _proc_set_prio( proc_t * proc, prio_t prio )
{
    if( !proc )
    {
        proc = current_proc();
    }
    SPIN_LOCK( proc );
    proc->base_prio = prio;
    PROC_PROC_PRIO_PROPAGATE( proc );
}
//========================================================================================
void scall_proc_set_prio( void * arg )
{
    _proc_set_prio( ((proc_set_prio_arg_t *)arg)->proc, ((proc_set_prio_arg_t *)arg)->prio );
}
/**********************************************************************************************
                                       Bsync methods
**********************************************************************************************/
#ifdef CONFIG_MP

void _sync_spin_lock( lock_t * lock )
{
    if( lock )
    {
        spin_lock(lock);
    }
}

void _sync_spin_free( lock_t * lock )
{
    if( lock )
    {
        spin_free(lock);
    }
}

static void sync_prio_prop_hook( sync_t * sync )
{
    SPIN_FREE( (sync->owner) );
    SPIN_FREE( sync );
}
#define SYNC_PROC_PRIO_PROPAGATE(p,m) _proc_prio_propagate( p, (code_t)sync_prio_prop_hook, (void *)m )
#else
#define SYNC_PROC_PRIO_PROPAGATE(p,m) _proc_prio_propagate( p )
#endif
//========================================================================================
void sync_init( sync_t * sync, prio_t prio )
{
    disable_interrupts();
    sync_init_isr( sync, prio );
    enable_interrupts();
}
//========================================================================================
void sync_init_isr( sync_t * sync, prio_t prio )
{
    SPIN_INIT( sync );
    SPIN_LOCK( sync );
    xlist_init( (xlist_t *)sync );
    sync->owner = (proc_t *)0;
    sync->dirty = (count_t)0;
    sync->prio = prio;
    SPIN_FREE( sync );
}
//**********************************************************************************************
proc_t * sync_get_owner( sync_t * sync )
{
    proc_t * ret;
    disable_interrupts();
    SPIN_LOCK( sync );
    ret = sync->owner;
    SPIN_FREE( sync );
    enable_interrupts();
    return ret;
}
/**********************************************************************************************
                                       SYSCALL_SYNC_SET_OWNER
**********************************************************************************************/
typedef struct
{
    sync_t * sync;
    proc_t * proc;
}
sync_set_owner_t;
//========================================================================================
void sync_set_owner( sync_t * sync, proc_t * proc )
{
    volatile sync_set_owner_t scarg;
    scarg.sync = sync;
    scarg.proc = proc;
    syscall_bugurt( SYSCALL_SYNC_SET_OWNER, (void *)&scarg );
}
//========================================================================================
void _sync_set_owner( sync_t * sync, proc_t * proc )
{
    proc_t * owner;

    if(!sync)
    {
        return;
    }

    if(!proc)
    {
        proc = current_proc();
    }

    SPIN_LOCK( sync );

    owner = sync->owner;
    if( proc!= owner )
    {
        prio_t sync_prio = SYNC_PRIO( sync );

        sync->owner = proc;
        SPIN_LOCK(proc);
        PROC_LRES_INC( proc, sync_prio );
        SYNC_PROC_PRIO_PROPAGATE( proc, sync );

        KERNEL_PREEMPT();

        if( !owner )
        {
            return;
        }
        SPIN_LOCK(owner);
        PROC_LRES_DEC( owner, sync_prio );
        PROC_PROC_PRIO_PROPAGATE( owner );
    }
    else
    {
        SPIN_FREE( sync );
    }
}
//========================================================================================
void scall_sync_set_owner( void * arg )
{
    _sync_set_owner( ((sync_set_owner_t *)arg)->sync, ((sync_set_owner_t *)arg)->proc );
}
/**********************************************************************************************
                                       SYSCALL_SYNC_CLEAR_OWNER
**********************************************************************************************/
void sync_clear_owner( sync_t * sync )
{
    syscall_bugurt( SYSCALL_SYNC_CLEAR_OWNER, (void *)sync );
}
//========================================================================================
void _sync_clear_owner( sync_t * sync )
{
    proc_t * proc;
    prio_t prio;
    if(!sync)
    {
        return;
    }

    SPIN_LOCK( sync );

    prio = SYNC_PRIO( sync );
    proc = sync->owner;

    sync->owner = (proc_t *)0;

    SPIN_FREE( sync );
    // check proc
    if(!proc)
    {
        return;
    }
    // update proc priority info
    SPIN_LOCK( proc );
    PROC_LRES_DEC( proc, prio );
    PROC_PROC_PRIO_PROPAGATE( proc );
}
//========================================================================================
void scall_sync_clear_owner( void * arg )
{
    _sync_clear_owner( (sync_t *)arg );
}
/**********************************************************************************************
                                       SYSCALL_SYNC_SLEEP
**********************************************************************************************/
flag_t sync_sleep( sync_t * sync )
{
    volatile sync_sleep_t scarg;
    scarg.status = SYNC_ST_ROLL;
    scarg.sync = sync;
    do
    {
        syscall_bugurt( SYSCALL_SYNC_SLEEP, (void *)&scarg );
    }
    while( scarg.status >= SYNC_ST_ROLL );
    return scarg.status;
}
//========================================================================================
flag_t _sync_sleep( sync_t * sync )
{
    proc_t * proc;
    prio_t old_prio, new_prio;
    count_t dirty;

    dirty = 0;

    _proc_reset_watchdog();

    if( !sync )
    {
        return  SYNC_ST_ENULL;
    }

    proc = current_proc();

    SPIN_LOCK( proc );
    if( PROC_GET_STATE( proc ) == PROC_STATE_SYNC_RUNNING )
    {
        PROC_SET_STATE( proc, PROC_STATE_RUNNING );
        SPIN_FREE( proc );

        return SYNC_ST_OK;
    }
    SPIN_FREE( proc );

    KERNEL_PREEMPT();

    SPIN_LOCK( sync );

    if( sync->owner == proc )
    {
        SPIN_FREE( sync );

        return SYNC_ST_EOWN;
    }
    SPIN_FREE( sync );

    KERNEL_PREEMPT();

    SPIN_LOCK( sync );

    old_prio = SYNC_PRIO( sync );

    SPIN_LOCK( proc );

    if( PROC_GET_STATE(proc) == PROC_STATE_PI_RUNNING )
    {
        //This is priority inheritanse transaction end
        dirty = sync->dirty--; //No zero check needed, as a process state is PROC_STATE_PI_RUNNING.
    }

    proc->sync = sync;
    _proc_stop_flags_set( proc, PROC_STATE_SYNC_SLEEP );
    pitem_insert( (pitem_t *)proc, (xlist_t *)sync );

    SPIN_FREE( proc );

    proc = sync->owner;
    if( proc )
    {
        new_prio = SYNC_PRIO( sync );
        if( (old_prio != new_prio) || dirty )
        {
            // When owner in PROC_STATE_SYNC_WAIT state, then old_prio != new_prio as sync->sleep was empty when owner called sync_wait.
            SPIN_LOCK( proc );
            PROC_LRES_DEC( proc, old_prio );
            PROC_LRES_INC( proc, new_prio );
            SYNC_PROC_PRIO_PROPAGATE( proc, sync );
            return SYNC_ST_ROLL;
        }
    }
    SPIN_FREE(sync);
    return SYNC_ST_ROLL;
}
//========================================================================================
void scall_sync_sleep( void * arg )
{
    ((sync_sleep_t *)arg)->status = _sync_sleep( ((sync_sleep_t *)arg)->sync );
}
/**********************************************************************************************
                                    SYSCALL_SYNC_WAIT
**********************************************************************************************/
static void _sync_owner_block( proc_t * owner )
{
    SPIN_LOCK( owner );

    owner->sync = (sync_t *)0;
    _proc_stop_flags_set( owner, PROC_STATE_SYNC_SLEEP );

    SPIN_FREE( owner );
}
//========================================================================================
flag_t sync_wait( sync_t * sync, proc_t ** proc, flag_t block )
{
    volatile sync_wait_t scarg;
    scarg.status = SYNC_ST_ROLL;
    scarg.sync = sync;
    scarg.proc = proc;
    scarg.block = block;
    do
    {
        syscall_bugurt( SYSCALL_SYNC_WAIT, (void *)&scarg );
    }
    while( scarg.status >= SYNC_ST_ROLL );
    return scarg.status;
}
//========================================================================================
flag_t _sync_wait( sync_t * sync, proc_t ** proc, flag_t block )
{
    proc_t * owner;
    flag_t status;

    _proc_reset_watchdog();

    if( !sync )
    {
        return SYNC_ST_ENULL;
    }

    if( !proc )
    {
        return SYNC_ST_ENULL;
    }

    status = (block)?SYNC_ST_ROLL:SYNC_ST_EEMPTY;

    SPIN_LOCK( sync );
    owner = sync->owner;

    if( owner != current_proc() )
    {
        SPIN_FREE( sync );
        return SYNC_ST_EOWN;
    }

    if( sync->dirty )
    {
        _sync_owner_block( owner );
        SPIN_FREE( sync );
        return SYNC_ST_ROLL;
    }

    if( !*proc )
    {
        *proc = (proc_t *)xlist_head( ((xlist_t *)sync) );
    }

    if( *proc )
    {
        SPIN_LOCK( (*proc) );
        if( (*proc)->sync == sync )
        {
            status = SYNC_ST_OK;
        }
        else
        {
            status = SYNC_ST_ESYNC;
        }
        SPIN_FREE( (*proc) );
    }//else ROLL/SYNC_ST_EEMPTY

    if( status == SYNC_ST_ROLL )
    {
        SPIN_LOCK( owner );
        _proc_stop_flags_set( owner, PROC_STATE_SYNC_WAIT );
        SPIN_FREE( owner );
    }

    SPIN_FREE( sync );
    return status;
}
//========================================================================================
void scall_sync_wait( void * arg )
{
    ((sync_wait_t *)arg)->status = _sync_wait( ((sync_wait_t *)arg)->sync, ((sync_wait_t *)arg)->proc, ((sync_wait_t *)arg)->block );
}
/**********************************************************************************************
                                    SYSCALL_SYNC_WAKE
**********************************************************************************************/
flag_t sync_wake( sync_t * sync, proc_t * proc, flag_t chown )
{
    volatile sync_wake_t scarg;
    scarg.status = SYNC_ST_ROLL;
    scarg.sync = sync;
    scarg.proc = proc;
    scarg.chown = chown;
    SYNC_SPIN_INIT(0);
    do
    {
        syscall_bugurt( SYSCALL_SYNC_WAKE, (void *)&scarg );
    }
    while( scarg.status >= SYNC_ST_ROLL );
    return scarg.status;
}
//========================================================================================
flag_t _sync_wake( sync_t * sync, proc_t * proc, flag_t chown )
{
    proc_t * owner;
    flag_t status;

    _proc_reset_watchdog();

    status = SYNC_ST_EEMPTY;

    if( !sync )
    {
        return SYNC_ST_ENULL;
    }

    SPIN_LOCK( sync );
    owner = sync->owner;
    // Check sync ownership
    if( owner )
    {
        if( owner != current_proc() )
        {
            SPIN_FREE( sync );

            return SYNC_ST_EOWN;
        }
        //Check for dirty priority inheritanse transactions
        if( sync->dirty )
        {
            _sync_owner_block( owner );
            SPIN_FREE( sync );

            return SYNC_ST_ROLL;
        }
    }

    // Nonzero proc argument???
    if( proc )
    {
        // Check proc
        SPIN_LOCK(proc);
        if( proc->sync != sync )
        {
            SPIN_FREE( proc );
            SPIN_FREE( sync );

            return SYNC_ST_ESYNC;
        }
        SPIN_FREE( proc );
    }
    else
    {
        proc = (proc_t *)xlist_head( (xlist_t *)sync );
    }
    // Will now handle sync->owner
    if( owner )
    {
        SPIN_LOCK( owner );
        // As PROC_FLG_sync is set, a process can be stoped safely.
        sched_proc_stop( owner );
        PROC_LRES_DEC( owner, SYNC_PRIO( sync ) );// No prio control now!

        SPIN_FREE( owner );
    }

    if( chown )
    {
        //Ownership has been changed.
        sync->owner = proc;
    }

    if( proc )
    {
        // We can wake some proc.
        status = SYNC_ST_OK;

        SPIN_LOCK( proc );

        proc->sync = (void *)0; //It doesn't wait on sync any more.

        if( PROC_GET_STATE( proc ) == PROC_STATE_PI_PEND )
        {
            PROC_SET_STATE ( proc, PROC_STATE_PI_DONE );
            if( chown )
            {
                PROC_LRES_INC( proc, SYNC_PRIO( sync ) );  //sync prio has changed
            }
        }
        else
        {
            pitem_cut( (pitem_t *)proc );
            if( chown )
            {
                PROC_LRES_INC( proc, SYNC_PRIO( sync ) );  //sync prio has changed
                _proc_prio_control_stoped( proc );
            }
            sched_proc_run( proc, PROC_STATE_SYNC_READY );
        }
        SPIN_FREE( proc );
    }

    if( owner )
    {
        SPIN_LOCK( owner );

        if( !chown )
        {
            PROC_LRES_INC( owner, SYNC_PRIO( sync ) );
        }
        _proc_prio_control_stoped( owner );
        // Is PROC_FLG_PRE_STOP processing needed, can process be stoped if "Yes"?
        if(  PROC_PRE_STOP_TEST( owner )  )
        {
            // Yes, Yes. Will not run actualy.
            owner->flags &= ~PROC_FLG_PRE_STOP;
        }
        else
        {
            // Run in other cases!
            sched_proc_run( owner, PROC_STATE_READY );
        }
        SPIN_FREE( owner );
    }

    SPIN_FREE( sync );
    return status;
}
//========================================================================================
void scall_sync_wake( void * arg )
{
    SYNC_SPIN_LOCK(sync_wake_t);
    ((sync_wake_t *)arg)->status = _sync_wake( ((sync_wake_t *)arg)->sync , ((sync_wake_t *)arg)->proc, ((sync_wake_t *)arg)->chown );
    SYNC_SPIN_FREE(sync_wake_t);
}
/**********************************************************************************************
                                SYSCALL_SYNC_WAKE_AND_SLEEP
**********************************************************************************************/
flag_t sync_wake_and_sleep( sync_t * wake, proc_t * proc, flag_t chown, sync_t * sleep )
{
    volatile sync_wake_and_sleep_t scarg;
    scarg.sleep.sync = sleep;
    scarg.sleep.status = SYNC_ST_ROLL;
    scarg.chown = chown;
    scarg.wake = wake;
    scarg.proc = proc;
    scarg.stage = (flag_t)0;
    SYNC_SPIN_INIT(0);
    do
    {
        syscall_bugurt( SYSCALL_SYNC_WAKE_AND_SLEEP, (void *)&scarg );
    }
    while( scarg.sleep.status >= SYNC_ST_ROLL );
    return scarg.sleep.status;
}
//========================================================================================
void scall_sync_wake_and_sleep( void * arg )
{
    SYNC_SPIN_LOCK(sync_wake_and_sleep_t);
    switch( ((sync_wake_and_sleep_t *)arg)->stage )
    {
    case 0:
    default:
    {
        flag_t status;
        status = _sync_wake(  ((sync_wake_and_sleep_t *)arg)->wake, ((sync_wake_and_sleep_t *)arg)->proc, ((sync_wake_and_sleep_t *)arg)->chown );
        if( SYNC_ST_OK == status )
        {
            ((sync_wake_and_sleep_t *)arg)->stage++;
        }
        else
        {
            ((sync_sleep_t *)arg)->status = status;
            break;
        }
    }
    case 1:
    {
        scall_sync_sleep(arg);
        break;
    }
    }
    SYNC_SPIN_FREE(sync_wake_and_sleep_t);
}
/**********************************************************************************************
                                SYSCALL_SYNC_WAKE_AND_WAIT
**********************************************************************************************/
flag_t sync_wake_and_wait( sync_t * wake, proc_t * proc_wake, flag_t chown, sync_t * wait, proc_t ** proc_wait, flag_t block )
{
    volatile sync_wake_and_wait_t scarg;
    scarg.wait.sync = wait;
    scarg.wait.proc = proc_wait;
    scarg.wait.block = block;
    scarg.wait.status = SYNC_ST_ROLL;
    scarg.wake = wake;
    scarg.proc = proc_wake;
    scarg.chown = chown;
    scarg.stage = (flag_t)0;
    SYNC_SPIN_INIT(0);
    do
    {
        syscall_bugurt( SYSCALL_SYNC_WAKE_AND_WAIT, (void *)&scarg );
    }
    while( scarg.wait.status >= SYSCALL_SYNC_WAKE_AND_WAIT );
    return scarg.wait.status;
}
//========================================================================================
void scall_sync_wake_and_wait( void * arg )
{
    SYNC_SPIN_LOCK(sync_wake_and_sleep_t);
    switch( ((sync_wake_and_wait_t *)arg)->stage )
    {
    case 0:
    default:
    {
        flag_t status;
        status = _sync_wake( ((sync_wake_and_wait_t*)arg)->wake , ((sync_wake_and_wait_t*)arg)->proc, ((sync_wake_and_wait_t*)arg)->chown );
        if( SYNC_ST_OK == status )
        {
            ((sync_wake_and_wait_t *)arg)->stage++;
        }
        else
        {
            ((sync_wait_t *)arg)->status = status;
            break;
        }
    }
    case 1:
    {
        scall_sync_wait(arg);
        break;
    }
    }
    SYNC_SPIN_FREE(sync_wake_and_sleep_t);
}
