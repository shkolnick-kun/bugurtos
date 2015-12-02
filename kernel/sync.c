/**************************************************************************
    BuguRTOS-0.8.x (Bugurt real time operating system)
    Copyright (C) 2015 anonimous

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

bgrt_prio_t _bgrt_sync_prio( bgrt_sync_t * sync )
{
    bgrt_prio_t sprio; //sync prio

    sprio = sync->prio;
    if( (((bgrt_xlist_t *)sync)->index) )
    {
        bgrt_prio_t wprio; //wait list prio

        wprio = bgrt_index_search(((bgrt_xlist_t *)sync)->index);
        return (wprio < sprio)?wprio:sprio;
    }
    else
    {
        return sprio;
    }
}
//========================================================================================
static bgrt_st_t _bgrt_sync_do_wake( bgrt_proc_t * proc, bgrt_sync_t * sync, bgrt_flag_t chown )
{
    if( proc )
    {
        BGRT_SPIN_LOCK( proc );

        proc->sync = (void *)0; //It doesn't wait on sync any more.

        if( BGRT_PROC_STATE_PI_PEND == BGRT_PROC_GET_STATE( proc ) )
        {
            BGRT_PROC_SET_STATE ( proc, BGRT_PROC_STATE_PI_DONE );
            if( chown )
            {
                BGRT_PROC_LRES_INC( proc, BGRT_SYNC_PRIO( sync ) );  //sync prio has changed
            }
        }
        else
        {
            bgrt_pitem_cut( (bgrt_pitem_t *)proc );
            if( chown )
            {
                BGRT_PROC_LRES_INC( proc, BGRT_SYNC_PRIO( sync ) );  //sync prio has changed
                _bgrt_proc_prio_control_stoped( proc );
            }
            bgrt_sched_proc_run( proc, BGRT_PROC_STATE_SYNC_READY );
        }
        BGRT_SPIN_FREE( proc );

        return BGRT_ST_OK;
    }
    else
    {
        return BGRT_ST_EEMPTY;
    }
}
//========================================================================================
static void _bgrt_sync_do_pending_wake( bgrt_sync_t * sync )
{
    bgrt_proc_t * proc;
    sync->pwake--;
    proc = (bgrt_proc_t *)bgrt_xlist_head( (bgrt_xlist_t *)sync );
    _bgrt_sync_do_wake( proc, sync, (bgrt_flag_t)0 );
}
//========================================================================================
#ifdef BGRT_CONFIG_MP
#define BGRT_PI_PRIO_PROP_ARGS bgrt_proc_t * proc, bgrt_code_t hook, void * hook_arg
#define BGRT_PI_PRIO_PROP_HOOK() hook(hook_arg)
#else // BGRT_CONFIG_MP
#define BGRT_PI_PRIO_PROP_ARGS bgrt_proc_t * proc
#define BGRT_PI_PRIO_PROP_HOOK()
#endif // BGRT_CONFIG_MP
static void _bgrt_pi_prio_propagate( BGRT_PI_PRIO_PROP_ARGS )
{
    switch( BGRT_PROC_GET_STATE( proc ) )
    {
    case BGRT_PROC_STATE_READY:
    case BGRT_PROC_STATE_RUNNING:
    case BGRT_PROC_STATE_TO_READY:
    case BGRT_PROC_STATE_TO_RUNNING:
    case BGRT_PROC_STATE_SYNC_READY:
    case BGRT_PROC_STATE_SYNC_RUNNING:
    case BGRT_PROC_STATE_PI_READY:
    case BGRT_PROC_STATE_PI_RUNNING:
    {
        bgrt_flag_t state;
        state = BGRT_PROC_GET_STATE( proc );
        _bgrt_proc_stop_ensure( proc );
        _bgrt_proc_prio_control_stoped( proc );
        bgrt_sched_proc_run( proc, state );
        BGRT_PI_PRIO_PROP_HOOK();
        break;
    }
    case BGRT_PROC_STATE_SYNC_SLEEP:
    {
        bgrt_sync_t * sync;
        bgrt_prio_t old_prio, new_prio;
        BGRT_PROC_SET_STATE( proc, BGRT_PROC_STATE_PI_PEND );  // Ensure that process will not run, and stay in a sync sleep list!

        sync = proc->sync;

        BGRT_PI_PRIO_PROP_HOOK();

        BGRT_KERNEL_PREEMPT();

        if( (bgrt_sync_t *)0 == sync )
        {
            // A process was trying to free a dirty sync and blocked
            BGRT_SPIN_LOCK( proc );

            _bgrt_proc_prio_control_stoped( proc );
            bgrt_sched_proc_run( proc, BGRT_PROC_STATE_READY ); // A process must unlock the sync.

            BGRT_SPIN_FREE( proc );
            break; //Break the switch!
        }

        BGRT_SPIN_LOCK( sync );

        old_prio = BGRT_SYNC_PRIO( sync ); // Get sync prio to keep sync->owner priority data consistent

        BGRT_SPIN_LOCK( proc );

        bgrt_pitem_cut( (bgrt_pitem_t *)proc );
        _bgrt_proc_prio_control_stoped( proc );
        if( BGRT_PROC_STATE_PI_PEND == BGRT_PROC_GET_STATE( proc ) )
        {
            if( sync->owner )
            {
                // Start priority inheritance transaction.
                sync->dirty++;
                bgrt_sched_proc_run( proc, BGRT_PROC_STATE_PI_READY );
            }
            else
            {
                // Put back into sync->sleep
                BGRT_PROC_SET_STATE( proc, BGRT_PROC_STATE_SYNC_SLEEP );
                bgrt_pitem_insert( (bgrt_pitem_t *)proc, (bgrt_xlist_t *)sync );
            }
        }
        else
        {
            // Finish process wakeup
            bgrt_sched_proc_run( proc, BGRT_PROC_STATE_SYNC_READY );
        }

        BGRT_SPIN_FREE( proc );

        proc = sync->owner;
        if( proc )
        {
            // Keep priority data consistent
            new_prio = BGRT_SYNC_PRIO( sync );
            if( new_prio != old_prio )
            {
                BGRT_SPIN_LOCK( proc );
                BGRT_PROC_LRES_DEC( proc, old_prio );
                BGRT_PROC_LRES_INC( proc, new_prio );
                BGRT_SPIN_FREE( proc );
            }
        }
        BGRT_SPIN_FREE( sync );

        break;
    }
    case BGRT_PROC_STATE_SYNC_WAIT:
    {
        _bgrt_proc_prio_control_stoped( proc );
        bgrt_sched_proc_run( proc, BGRT_PROC_STATE_READY );
        BGRT_PI_PRIO_PROP_HOOK();
        break;
    }
    case BGRT_PROC_STATE_STOPED:
    case BGRT_PROC_STATE_END:
    case BGRT_PROC_STATE_WD_STOPED:
    case BGRT_PROC_STATE_DEAD:

    {
        _bgrt_proc_prio_control_stoped( proc );
    }
    case BGRT_PROC_STATE_PI_PEND:
    case BGRT_PROC_STATE_PI_DONE:
    default:
    {
        BGRT_PI_PRIO_PROP_HOOK();
    }
    }
}

/**********************************************************************************************
                                       BGRT_SYSCALL_PROC_SET_PRIO
**********************************************************************************************/
void bgrt_proc_set_prio( BGRT_PID_T pid, bgrt_prio_t prio )
{
    volatile bgrt_proc_set_prio_arg_t arg;
    arg.pid = pid;
    arg.prio = prio;
    bgrt_syscall( BGRT_SYSCALL_PROC_SET_PRIO, (void *)&arg );
}
//========================================================================================
#ifdef BGRT_CONFIG_MP
#define BGRT_PROC_PS_PI_PRIO_PROPAGATE(p) _bgrt_pi_prio_propagate( p, (bgrt_code_t)bgrt_spin_free, (void *)&p->lock )
#else // BGRT_CONFIG_MP
#define BGRT_PROC_PS_PI_PRIO_PROPAGATE(p) _bgrt_pi_prio_propagate( p )
#endif // BGRT_CONFIG_MP
void _bgrt_proc_set_prio( bgrt_proc_t * proc, bgrt_prio_t prio )
{
    if( !proc )
    {
        proc = bgrt_curr_proc();
    }
    BGRT_SPIN_LOCK( proc );
    proc->base_prio = prio;
    BGRT_PROC_PS_PI_PRIO_PROPAGATE( proc );
}
//========================================================================================
void bgrt_scall_proc_set_prio( bgrt_proc_set_prio_arg_t * arg )
{
    _bgrt_proc_set_prio( BGRT_PID_TO_PROC( arg->pid ), arg->prio );
}
/**********************************************************************************************
                                       Bsync methods
**********************************************************************************************/
#ifdef BGRT_CONFIG_MP
static void bgrt_sync_prio_prop_hook( bgrt_sync_t * sync )
{
    BGRT_SPIN_FREE( (sync->owner) );
    BGRT_SPIN_FREE( sync );
}
#define BGRT_SYNC_PI_PRIO_PROPAGATE(p,m) _bgrt_pi_prio_propagate( p, (bgrt_code_t)bgrt_sync_prio_prop_hook, (void *)m )
#else // BGRT_CONFIG_MP
#define BGRT_SYNC_PI_PRIO_PROPAGATE(p,m) _bgrt_pi_prio_propagate( p )
#endif // BGRT_CONFIG_MP
//========================================================================================
bgrt_st_t bgrt_sync_init( bgrt_sync_t * sync, bgrt_prio_t prio )
{
    bgrt_st_t ret;
    bgrt_disable_interrupts();
    ret = bgrt_sync_init_isr( sync, prio );
    bgrt_enable_interrupts();
    return ret;
}
//========================================================================================
bgrt_st_t bgrt_sync_init_isr( bgrt_sync_t * sync, bgrt_prio_t prio )
{
    if( !sync )
    {
        return BGRT_ST_ENULL;
    }

    BGRT_SPIN_INIT( sync );
    BGRT_SPIN_LOCK( sync );
    bgrt_xlist_init( (bgrt_xlist_t *)sync );
    sync->owner = (bgrt_proc_t *)0;
    sync->dirty = (bgrt_cnt_t)0;
    sync->pwake = (bgrt_cnt_t)0;
    sync->prio = prio;
    BGRT_SPIN_FREE( sync );
    return BGRT_ST_OK;
}
//**********************************************************************************************
bgrt_proc_t * bgrt_sync_get_owner( bgrt_sync_t * sync )
{
    bgrt_proc_t * ret;
    bgrt_disable_interrupts();
    BGRT_SPIN_LOCK( sync );
    ret = sync->owner;
    BGRT_SPIN_FREE( sync );
    bgrt_enable_interrupts();
    return ret;
}
/**********************************************************************************************
                                       BGRT_SYSCALL_SYNC_SET_OWNER
**********************************************************************************************/
static void _bgrt_sync_assign_owner( bgrt_sync_t * sync, bgrt_proc_t * proc )
{
    sync->owner = proc;
    BGRT_SPIN_LOCK(proc);
    BGRT_PROC_LRES_INC( proc, BGRT_SYNC_PRIO( sync ) );
    BGRT_SYNC_PI_PRIO_PROPAGATE( proc, sync );
}
//========================================================================================
bgrt_st_t bgrt_sync_set_owner( bgrt_sync_t * sync, bgrt_proc_t * proc )
{
    volatile bgrt_sync_set_owner_t scarg;
    scarg.sync = sync;
    scarg.proc = proc;
    scarg.status = BGRT_ST_ROLL;
    bgrt_syscall( BGRT_SYSCALL_SYNC_SET_OWNER, (void *)&scarg );
    return scarg.status;
}
//========================================================================================
bgrt_st_t _bgrt_sync_set_owner( bgrt_sync_t * sync, bgrt_proc_t * proc )
{
    bgrt_proc_t * owner;
    bgrt_prio_t old_prio;

    if(!sync)
    {
        return BGRT_ST_ENULL;
    }

    //Clear last owner
    BGRT_SPIN_LOCK( sync );

    old_prio = BGRT_SYNC_PRIO( sync );
    owner = sync->owner;

    if( owner == proc )
    {
        BGRT_SPIN_FREE( sync );

        return BGRT_ST_OK;
    }

    sync->owner = (bgrt_proc_t *)0;
    BGRT_SPIN_FREE( sync );

    // check proc
    if( owner )
    {
        // update proc priority info
        BGRT_SPIN_LOCK( owner );
        BGRT_PROC_LRES_DEC( owner, old_prio );
        BGRT_PROC_PS_PI_PRIO_PROPAGATE( owner );
    }

    //Check new owner
    if( !proc )
    {
        return BGRT_ST_OK;
    }

    //We have some new owner
    BGRT_SPIN_LOCK( sync );
    _bgrt_sync_assign_owner( sync, proc );


    return BGRT_ST_OK;
}
//========================================================================================
void bgrt_scall_sync_set_owner( bgrt_sync_set_owner_t * arg )
{
    arg->status = _bgrt_sync_set_owner( arg->sync, arg->proc );
}
/**********************************************************************************************
                                       BGRT_SYSCALL_SYNC_CLEAR_OWNER
**********************************************************************************************/
bgrt_st_t bgrt_sync_own( bgrt_sync_t * sync, bgrt_flag_t touch )
{
    bgrt_sync_own_t scarg;
    scarg.status = BGRT_ST_EOWN;
    scarg.sync = sync;
    scarg.touch = touch;
    bgrt_syscall( BGRT_SYSCALL_SYNC_OWN, (void *)&scarg );
    return scarg.status;
}
//========================================================================================
bgrt_st_t _bgrt_sync_own( bgrt_sync_t * sync, bgrt_flag_t touch )
{
    bgrt_proc_t * owner;


    if(!sync)
    {
        return BGRT_ST_ENULL;
    }

    BGRT_SPIN_LOCK( sync );

    owner = sync->owner;
    if( !owner )
    {
        _bgrt_sync_assign_owner( sync, bgrt_curr_proc() );

        return BGRT_ST_OK;
    }
    else
    {
        bgrt_proc_t * current;
        current = bgrt_curr_proc();

        if( touch && (owner != current) )
        {
            sync->dirty++;
            BGRT_SPIN_FREE( sync );

            BGRT_SPIN_LOCK( current );
            BGRT_PROC_SET_STATE( current, BGRT_PROC_STATE_PI_RUNNING );
            current->sync = sync;
            BGRT_SPIN_FREE( current );
        }
        else
        {
            BGRT_SPIN_FREE( sync );
        }
        return BGRT_ST_ROLL;
    }
}
//========================================================================================
void bgrt_scall_sync_own( bgrt_sync_own_t * arg )
{
    arg->status = _bgrt_sync_own( arg->sync, arg->touch );
}
/**********************************************************************************************
                                       BGRT_SYSCALL_SYNC_TOUCH
**********************************************************************************************/
bgrt_st_t bgrt_sync_touch( bgrt_sync_t * sync )
{
    bgrt_sync_touch_t scarg;
    scarg.status = BGRT_ST_ENULL;
    scarg.sync = sync;
    bgrt_syscall( BGRT_SYSCALL_SYNC_TOUCH, (void *)&scarg );
    return scarg.status;
}
//========================================================================================
bgrt_st_t _bgrt_sync_touch( bgrt_sync_t * sync )
{
    bgrt_proc_t * current;

    if( !sync )
    {
        return BGRT_ST_ENULL;
    }

    BGRT_SPIN_LOCK( sync );
    sync->dirty++;
    BGRT_SPIN_FREE( sync );

    current = bgrt_curr_proc();
    BGRT_SPIN_LOCK( current );
    BGRT_PROC_SET_STATE( current, BGRT_PROC_STATE_PI_RUNNING );
    current->sync = sync;
    BGRT_SPIN_FREE( current );
    return BGRT_ST_OK;
}
//========================================================================================
void bgrt_scall_sync_touch( bgrt_sync_touch_t * arg )
{
    arg->status = _bgrt_sync_touch( arg->sync );
}
/**********************************************************************************************
                                       BGRT_SYSCALL_SYNC_SLEEP
**********************************************************************************************/
bgrt_st_t bgrt_sync_sleep( bgrt_sync_t * sync )
{
    volatile bgrt_sync_sleep_t scarg;
    scarg.status = BGRT_ST_ROLL;
    scarg.sync = sync;
    do
    {
        bgrt_syscall( BGRT_SYSCALL_SYNC_SLEEP, (void *)&scarg );
    }
    while( scarg.status >= BGRT_ST_ROLL );
    return scarg.status;
}
//========================================================================================
static void _bgrt_sync_sleep_swap_locks( bgrt_sync_t * sync, bgrt_proc_t * proc )
{
    BGRT_SPIN_FREE( proc );
    BGRT_KERNEL_PREEMPT();
    BGRT_SPIN_LOCK( sync );
    BGRT_SPIN_LOCK( proc );
}
//========================================================================================
bgrt_st_t _bgrt_sync_sleep( bgrt_sync_t * sync )
{
    bgrt_proc_t * proc;
    bgrt_prio_t old_prio, new_prio;
    bgrt_flag_t sync_clear;

    _bgrt_proc_reset_watchdog();

    if( !sync )
    {
        return  BGRT_ST_ENULL;
    }

    proc = bgrt_curr_proc();

    BGRT_SPIN_LOCK( proc );
    switch( sync_clear = BGRT_PROC_GET_STATE( proc ), BGRT_PROC_SET_STATE( proc, BGRT_PROC_STATE_RUNNING ), sync_clear ) //Use sync_clear as temp var.
    {
    case BGRT_PROC_STATE_SYNC_RUNNING:
    {
        BGRT_SPIN_FREE( proc );

        BGRT_KERNEL_PREEMPT();

        BGRT_SPIN_LOCK( sync );
        if( sync->pwake )
        {
            _bgrt_sync_do_pending_wake( sync );
        }
        BGRT_SPIN_FREE( sync );

        return BGRT_ST_OK;
    }
    case BGRT_PROC_STATE_TO_RUNNING:
    {
        BGRT_SPIN_FREE( proc );

        return BGRT_ST_ETIMEOUT;
    }
    case BGRT_PROC_STATE_PI_RUNNING:
    {
        _bgrt_sync_sleep_swap_locks( sync, proc );
        //The end of priority inheritance transaction or bgrt_sync_own transaction
        //No zero check needed, as a process state is BGRT_PROC_STATE_PI_RUNNING.
        sync_clear = (bgrt_flag_t)( (bgrt_cnt_t)1 == sync->dirty-- );
        break;
    }
    default:
    {
        _bgrt_sync_sleep_swap_locks( sync, proc );
        sync_clear = (bgrt_flag_t)0;
        break;
    }
    }
    // Must be handled after proc state
    if( sync->owner == proc )
    {
        BGRT_SPIN_FREE( proc );
        BGRT_SPIN_FREE( sync );

        return BGRT_ST_EOWN;
    }

    old_prio = BGRT_SYNC_PRIO( sync );

    proc->sync = sync;
    _bgrt_proc_stop_flags_set( proc, BGRT_PROC_STATE_SYNC_SLEEP );
    bgrt_pitem_insert( (bgrt_pitem_t *)proc, (bgrt_xlist_t *)sync );

    BGRT_SPIN_FREE( proc );

    if( (sync_clear) && (sync->pwake) )
    {
        _bgrt_sync_do_pending_wake( sync );
    }

    proc = sync->owner;
    if( proc )
    {
        new_prio = BGRT_SYNC_PRIO( sync );
        if( (old_prio != new_prio) || sync_clear )
        {
            // When owner in BGRT_PROC_STATE_SYNC_WAIT state, then old_prio != new_prio as sync->sleep was empty when owner called bgrt_sync_wait.
            BGRT_SPIN_LOCK( proc );
            BGRT_PROC_LRES_DEC( proc, old_prio );
            BGRT_PROC_LRES_INC( proc, new_prio );
            BGRT_SYNC_PI_PRIO_PROPAGATE( proc, sync );
        }
        else
        {
            BGRT_SPIN_LOCK( proc );
            if( BGRT_PROC_STATE_SYNC_WAIT == BGRT_PROC_GET_STATE( proc ) )
            {
                bgrt_sched_proc_run( proc, BGRT_PROC_STATE_READY );
            }
            BGRT_SPIN_FREE( proc );
            BGRT_SPIN_FREE( sync );
        }
    }
    else
    {
        BGRT_SPIN_FREE(sync);
    }
    return BGRT_ST_ROLL;
}
//========================================================================================
void bgrt_scall_sync_sleep( bgrt_sync_sleep_t * arg )
{
    arg->status = _bgrt_sync_sleep( arg->sync );
}
/**********************************************************************************************
                                    BGRT_SYSCALL_SYNC_WAIT
**********************************************************************************************/
static void _bgrt_sync_owner_block( bgrt_proc_t * owner )
{
    BGRT_SPIN_LOCK( owner );

    owner->sync = (bgrt_sync_t *)0;
    _bgrt_proc_stop_flags_set( owner, BGRT_PROC_STATE_SYNC_SLEEP );

    BGRT_SPIN_FREE( owner );
}
//========================================================================================
bgrt_st_t bgrt_sync_wait( bgrt_sync_t * sync, bgrt_proc_t ** proc, bgrt_flag_t block )
{
    volatile bgrt_sync_wait_t scarg;
    scarg.status = BGRT_ST_ROLL;
    scarg.sync = sync;
    scarg.proc = proc;
    scarg.block = block;
    do
    {
        bgrt_syscall( BGRT_SYSCALL_SYNC_WAIT, (void *)&scarg );
    }
    while( scarg.status >= BGRT_ST_ROLL );
    return scarg.status;
}
//========================================================================================
bgrt_st_t _bgrt_sync_wait( bgrt_sync_t * sync, bgrt_proc_t ** proc, bgrt_flag_t block )
{
    bgrt_proc_t * current;
    bgrt_proc_t * owner;
    bgrt_st_t status;

    _bgrt_proc_reset_watchdog();

    if( !sync )
    {
        return BGRT_ST_ENULL;
    }

    if( !proc )
    {
        return BGRT_ST_ENULL;
    }

    current = bgrt_curr_proc();

    BGRT_SPIN_LOCK( current );
    status = BGRT_PROC_GET_STATE( current );
    BGRT_SPIN_FREE( current );

    if( BGRT_PROC_STATE_TO_RUNNING == status )
    {
        return BGRT_ST_ETIMEOUT;
    }

    BGRT_SPIN_LOCK( sync );
    owner = sync->owner;

    if( owner != current )
    {
        BGRT_SPIN_FREE( sync );
        return BGRT_ST_EOWN;
    }

    if( sync->dirty )
    {
        _bgrt_sync_owner_block( owner );
        BGRT_SPIN_FREE( sync );
        return BGRT_ST_ROLL;
    }

    if( !*proc )
    {
        *proc = (bgrt_proc_t *)bgrt_xlist_head( ((bgrt_xlist_t *)sync) );
    }

    status = (block)?BGRT_ST_ROLL:BGRT_ST_EEMPTY;
    if( *proc )
    {
        BGRT_SPIN_LOCK( (*proc) );
        if( (*proc)->sync == sync )
        {
            status = BGRT_ST_OK;
        }
        BGRT_SPIN_FREE( (*proc) );
    }//else BGRT_ST_ROLL/BGRT_ST_EEMPTY

    if( status == BGRT_ST_ROLL )
    {
        BGRT_SPIN_LOCK( owner );
        _bgrt_proc_stop_flags_set( owner, BGRT_PROC_STATE_SYNC_WAIT );
        BGRT_SPIN_FREE( owner );
    }

    BGRT_SPIN_FREE( sync );
    return status;
}
//========================================================================================
void bgrt_scall_sync_wait( bgrt_sync_wait_t * arg )
{
    arg->status = _bgrt_sync_wait( arg->sync, arg->proc, arg->block );
}
/**********************************************************************************************
                                    BGRT_SYSCALL_SYNC_WAKE
**********************************************************************************************/
bgrt_st_t bgrt_sync_wake( bgrt_sync_t * sync, bgrt_proc_t * proc, bgrt_flag_t chown )
{
    volatile bgrt_sync_wake_t scarg;
    scarg.status = BGRT_ST_ROLL;
    scarg.sync = sync;
    scarg.proc = proc;
    scarg.chown = chown;
    do
    {
        bgrt_syscall( BGRT_SYSCALL_SYNC_WAKE, (void *)&scarg );
    }
    while( scarg.status >= BGRT_ST_ROLL );
    return scarg.status;
}
//========================================================================================
bgrt_st_t _bgrt_sync_wake( bgrt_sync_t * sync, bgrt_proc_t * proc, bgrt_flag_t chown )
{
    bgrt_proc_t * owner;
    bgrt_st_t status;

    _bgrt_proc_reset_watchdog();

    if( !sync )
    {
        return BGRT_ST_ENULL;
    }

    BGRT_SPIN_LOCK( sync );
    owner = sync->owner;
    // Check sync ownership
    if( owner )
    {
        if( bgrt_curr_proc() != owner )
        {
            BGRT_SPIN_FREE( sync );

            return BGRT_ST_EOWN;
        }
        //Check for dirty priority inheritance transactions
        if( sync->dirty )
        {
            _bgrt_sync_owner_block( owner );
            BGRT_SPIN_FREE( sync );

            return BGRT_ST_ROLL;
        }
    }
    else
    {
        if( sync->dirty )
        {
            sync->pwake++;
            BGRT_SPIN_FREE( sync );

            return BGRT_ST_OK;
        }
    }
    // Nonzero proc argument???
    if( proc )
    {
        // Check proc
        BGRT_SPIN_LOCK(proc);
        if( proc->sync != sync )
        {
            BGRT_SPIN_FREE( proc );
            BGRT_SPIN_FREE( sync );

            return BGRT_ST_ESYNC;
        }
        BGRT_SPIN_FREE( proc );
    }
    else
    {
        proc = (bgrt_proc_t *)bgrt_xlist_head( (bgrt_xlist_t *)sync );
    }
    // Will now handle sync->owner
    if( owner )
    {
        BGRT_SPIN_LOCK( owner );

        bgrt_sched_proc_stop( owner );
        BGRT_PROC_LRES_DEC( owner, BGRT_SYNC_PRIO( sync ) );// No prio control now!

        BGRT_SPIN_FREE( owner );
    }
    //Ownership has been changed.
    if( chown )
    {
        sync->owner = proc;
    }
    // We can wake some proc.
    status = _bgrt_sync_do_wake( proc, sync, chown );

    if( owner )
    {
        BGRT_SPIN_LOCK( owner );

        if( !chown )
        {
            BGRT_PROC_LRES_INC( owner, BGRT_SYNC_PRIO( sync ) );
        }
        _bgrt_proc_prio_control_stoped( owner );
        bgrt_sched_proc_run( owner, BGRT_PROC_STATE_READY );

        BGRT_SPIN_FREE( owner );
    }

    BGRT_SPIN_FREE( sync );
    return status;
}
//========================================================================================
void bgrt_scall_sync_wake( bgrt_sync_wake_t * arg )
{
    arg->status = _bgrt_sync_wake( arg->sync , arg->proc, arg->chown );
}
/**********************************************************************************************
                                BGRT_SYSCALL_SYNC_PROC_TIMEOUT
**********************************************************************************************/
bgrt_st_t bgrt_sync_proc_timeout( bgrt_proc_t * proc )
{
    volatile bgrt_sync_proc_timeout_t scarg;
    scarg.proc = proc;
    scarg.status = BGRT_ST_ROLL;
    bgrt_syscall( BGRT_SYSCALL_SYNC_PROC_TIMEOUT, (void *)&scarg );
    return scarg.status;
}
//========================================================================================
void bgrt_scall_sync_proc_timeout( bgrt_sync_proc_timeout_t * arg )
{
    arg->status = _bgrt_sync_proc_timeout( arg->proc );
}
//========================================================================================
bgrt_st_t _bgrt_sync_proc_timeout( bgrt_proc_t * proc )
{
    bgrt_st_t status;
    bgrt_sync_t * sync;

    _bgrt_proc_reset_watchdog();

    status = BGRT_ST_OK;

    if( !proc )
    {
        return BGRT_ST_ENULL;
    }

    BGRT_SPIN_LOCK( proc );
    sync = proc->sync;
    BGRT_SPIN_FREE( proc );

    if( (bgrt_sync_t *)0 == sync )
    {
        BGRT_KERNEL_PREEMPT();

        BGRT_SPIN_LOCK( proc );

        switch( BGRT_PROC_GET_STATE( proc ) )
        {
        case BGRT_PROC_STATE_SYNC_WAIT:
        {
            //Is waiting on empty sync, wake up
            status = BGRT_ST_OK;
            bgrt_sched_proc_run( proc, BGRT_PROC_STATE_TO_READY );
        }
        break;

        case BGRT_PROC_STATE_SYNC_SLEEP:
        {
            //Blocked on dirty sync, will wakeup soon
            status = BGRT_ST_OK;
        }
        break;

        default:
        {
            //Something went wrong...
            status = BGRT_ST_ESYNC;
        }
        break;
        }

        BGRT_SPIN_FREE( proc );
        return status;
    }

    BGRT_KERNEL_PREEMPT();

    BGRT_SPIN_LOCK( sync );
    BGRT_SPIN_LOCK( proc );

    if( proc->sync != sync )
    {
        BGRT_SPIN_FREE( proc );
        BGRT_SPIN_FREE( sync );

        return BGRT_ST_ESYNC;  /// Not covered !!!
    }

    switch( BGRT_PROC_GET_STATE( proc ) )
    {
    case BGRT_PROC_STATE_SYNC_SLEEP:
    {
        //Undo bgrt_sync_sleep
        bgrt_prio_t old_prio;

        old_prio = BGRT_SYNC_PRIO( sync );

        bgrt_pitem_cut( (bgrt_pitem_t *)proc );
        proc->sync = (bgrt_sync_t *)0;
        bgrt_sched_proc_run( proc, BGRT_PROC_STATE_TO_READY );
        BGRT_SPIN_FREE(proc);

        proc = sync->owner;
        if( proc )
        {
            bgrt_prio_t new_prio;

            new_prio = BGRT_SYNC_PRIO( sync );
            if( new_prio != old_prio )
            {
                BGRT_SPIN_LOCK( proc );
                BGRT_PROC_LRES_DEC( proc, old_prio );
                BGRT_PROC_LRES_INC( proc, new_prio );
                BGRT_SYNC_PI_PRIO_PROPAGATE( proc, sync );
            }
            else
            {
                BGRT_SPIN_FREE( sync );
            }
        }
        else
        {
            BGRT_SPIN_FREE( sync );
        }

        return BGRT_ST_OK;
    }

    case BGRT_PROC_STATE_PI_PEND:
    case BGRT_PROC_STATE_PI_READY:
    case BGRT_PROC_STATE_PI_RUNNING:
    {
        BGRT_SPIN_FREE( proc );
        BGRT_SPIN_FREE( sync );

        return BGRT_ST_ROLL;
    }
    default:
    {
        BGRT_SPIN_FREE( proc );
        BGRT_SPIN_FREE( sync );

        return BGRT_ST_OK;
    }
    }

}
