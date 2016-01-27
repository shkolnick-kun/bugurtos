/**************************************************************************
    BuguRTOS-0.9.x (Bugurt real time operating system)
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
//Run a process with higher prio to avoid prio inversion!
static void _bgrt_pctrl_proc_run_high( bgrt_proc_t * proc, bgrt_flag_t state )
{
    BGRT_PROC_LRES_INC(proc, 0 );
    ((bgrt_pitem_t *)proc)->prio = (bgrt_prio_t)0;
    bgrt_sched_proc_run( proc, state );
}
//========================================================================================
// Change a process priority according to its #lres data field.
static void _bgrt_pctrl_proc_stoped( bgrt_proc_t * proc )
{
    if( (bgrt_index_t)0 != proc->lres.index )
    {

        bgrt_prio_t locker_prio;
        locker_prio = bgrt_index_search( proc->lres.index );
        ((bgrt_pitem_t *)proc)->prio = ( locker_prio < proc->base_prio )?locker_prio:proc->base_prio;
    }
    else
    {
        ((bgrt_pitem_t *)proc)->prio = proc->base_prio;
    }
}
//========================================================================================
static void _bgrt_pctrl_proc_run( bgrt_proc_t * proc, bgrt_flag_t state )
{
    _bgrt_pctrl_proc_stoped( proc );
    bgrt_sched_proc_run( proc, state );
}
//========================================================================================
static void _bgrt_pctrl_proc_running( bgrt_proc_t * proc, bgrt_flag_t state )
{
    _bgrt_proc_stop_ensure( proc );
    _bgrt_pctrl_proc_run( proc, state );
}
//========================================================================================
static void _bgrt_sync_proc_stop( bgrt_proc_t * proc, bgrt_flag_t mask )
{
    // Was a process stopped some where else?
    if( BGRT_PROC_RUN_TEST( proc ) )
    {
        // No, stop it now.
        bgrt_sched_proc_stop( proc );
        proc->flags |= mask;
    }
}
//========================================================================================
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
static void _bgrt_sync_do_wake( bgrt_proc_t * proc, bgrt_sync_t * sync, bgrt_flag_t chown )
{
    BGRT_SPIN_LOCK( proc );

    proc->sync = (void *)0; //It doesn't wait on sync any more.

    if( BGRT_PROC_STATE_PI_PEND == BGRT_PROC_GET_STATE( proc ) )
    {
        BGRT_PROC_SET_STATE ( proc, BGRT_PROC_STATE_PI_DONE );
        if( chown )
        {
            BGRT_PROC_LRES_INC( proc, BGRT_SYNC_PRIO( sync ) );
        }
    }
    else
    {
        bgrt_pitem_cut( (bgrt_pitem_t *)proc );
        if( chown )
        {
            BGRT_PROC_LRES_INC( proc, BGRT_SYNC_PRIO( sync ) );
            _bgrt_pctrl_proc_stoped( proc );
        }
        _bgrt_pctrl_proc_run_high( proc, BGRT_PROC_STATE_SYNC_READY );
    }
    BGRT_SPIN_FREE( proc );
}
//========================================================================================
static void _bgrt_sync_do_pending_wake( bgrt_sync_t * sync )
{
    bgrt_proc_t * proc;
    proc = (bgrt_proc_t *)bgrt_xlist_head( (bgrt_xlist_t *)sync );
    if( proc )
    {
        sync->pwake--;
        _bgrt_sync_do_wake( proc, sync, (bgrt_flag_t)0 );
    }
    else
    {
        return;/// Not covered!!! How about panic here???
    }
}
//========================================================================================
#ifdef BGRT_CONFIG_MP
#define BGRT_PCTRL_PROP_ARGS bgrt_proc_t * proc, bgrt_code_t hook, void * hook_arg
#define BGRT_PCTRL_PROP_HOOK() hook(hook_arg)
#else // BGRT_CONFIG_MP
#define BGRT_PCTRL_PROP_ARGS bgrt_proc_t * proc
#define BGRT_PCTRL_PROP_HOOK()
#endif // BGRT_CONFIG_MP
static void _bgrt_pctrl_propagate( BGRT_PCTRL_PROP_ARGS )
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
        _bgrt_pctrl_proc_running( proc, state );
        BGRT_PCTRL_PROP_HOOK();
        break;
    }
    case BGRT_PROC_STATE_SYNC_SLEEP:
    {
        bgrt_sync_t * sync;
        bgrt_prio_t old_prio, new_prio;
        BGRT_PROC_SET_STATE( proc, BGRT_PROC_STATE_PI_PEND );  // Ensure that process will not run, and stay in a sync sleep list!

        sync = proc->sync;

        BGRT_PCTRL_PROP_HOOK();

        BGRT_KERNEL_PREEMPT();

        if( (bgrt_sync_t *)0 == sync )
        {
            // A process was trying to free a dirty sync and blocked
            BGRT_SPIN_LOCK( proc );

            _bgrt_pctrl_proc_run( proc, BGRT_PROC_STATE_READY ); // A process must unlock the sync.

            BGRT_SPIN_FREE( proc );
            break; //Break the switch!
        }

        BGRT_SPIN_LOCK( sync );

        old_prio = BGRT_SYNC_PRIO( sync ); // Get sync prio to keep sync->owner priority data consistent

        BGRT_SPIN_LOCK( proc );

        bgrt_pitem_cut( (bgrt_pitem_t *)proc );
        if( BGRT_PROC_STATE_PI_PEND == BGRT_PROC_GET_STATE( proc ) )
        {
            if( sync->owner )
            {
                // Start priority inheritance transaction.
                BGRT_CNT_INC( sync->dirty ) ;
                //To avoid prio inversion!!!
                _bgrt_pctrl_proc_run_high( proc, BGRT_PROC_STATE_PI_READY );
            }
            else
            {
                // Put back into sync->sleep
                _bgrt_pctrl_proc_stoped( proc );
                BGRT_PROC_SET_STATE( proc, BGRT_PROC_STATE_SYNC_SLEEP );
                bgrt_pitem_insert( (bgrt_pitem_t *)proc, (bgrt_xlist_t *)sync );
            }
        }
        else
        {
            // Finish process wakeup
            _bgrt_pctrl_proc_run_high( proc, BGRT_PROC_STATE_SYNC_READY );
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
        _bgrt_pctrl_proc_run( proc, BGRT_PROC_STATE_READY );
        BGRT_PCTRL_PROP_HOOK();
        break;
    }
    case BGRT_PROC_STATE_STOPED:
    case BGRT_PROC_STATE_END:
    case BGRT_PROC_STATE_WD_STOPED:
    case BGRT_PROC_STATE_DEAD:
    {
        _bgrt_pctrl_proc_stoped( proc );
    }
    case BGRT_PROC_STATE_PI_PEND:
    case BGRT_PROC_STATE_PI_DONE:
    default:
    {
        BGRT_PCTRL_PROP_HOOK();
    }
    }
}
//========================================================================================
#ifdef BGRT_CONFIG_MP
#define BGRT_PROC_PS_PI_PRIO_PROPAGATE(p) _bgrt_pctrl_propagate( p, (bgrt_code_t)bgrt_spin_free, (void *)&p->lock )
#else // BGRT_CONFIG_MP
#define BGRT_PROC_PS_PI_PRIO_PROPAGATE(p) _bgrt_pctrl_propagate( p )
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
/**********************************************************************************************
                                       Bsync methods
**********************************************************************************************/
#ifdef BGRT_CONFIG_MP
static void bgrt_sync_prio_prop_hook( bgrt_sync_t * sync )
{
    BGRT_SPIN_FREE( (sync->owner) );
    BGRT_SPIN_FREE( sync );
}
#define BGRT_SYNC_PI_PRIO_PROPAGATE(p,m) _bgrt_pctrl_propagate( p, (bgrt_code_t)bgrt_sync_prio_prop_hook, (void *)m )
#else // BGRT_CONFIG_MP
#define BGRT_SYNC_PI_PRIO_PROPAGATE(p,m) _bgrt_pctrl_propagate( p )
#endif // BGRT_CONFIG_MP
//========================================================================================
bgrt_st_t bgrt_sync_init( bgrt_sync_t * sync, bgrt_prio_t prio )
{
    bgrt_st_t ret;
    bgrt_disable_interrupts();
    ret = _bgrt_sync_init( sync, prio );
    bgrt_enable_interrupts();
    return ret;
}
//========================================================================================
bgrt_st_t _bgrt_sync_init( bgrt_sync_t * sync, bgrt_prio_t prio )
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
    sync->snum  = (bgrt_cnt_t)0;
    sync->pwake = (bgrt_cnt_t)0;
    sync->prio = prio;
    BGRT_SPIN_FREE( sync );
    return BGRT_ST_OK;
}
//========================================================================================
bgrt_proc_t * _bgrt_sync_get_owner( bgrt_sync_t * sync )
{
    bgrt_proc_t * ret;
    BGRT_SPIN_LOCK( sync );
    ret = sync->owner;
    BGRT_SPIN_FREE( sync );
    return ret;
}
//========================================================================================
static void _bgrt_sync_assign_owner( bgrt_sync_t * sync, bgrt_proc_t * proc )
{
    sync->owner = proc;
    BGRT_SPIN_LOCK(proc);
    BGRT_PROC_LRES_INC( proc, BGRT_SYNC_PRIO( sync ) );
    BGRT_SYNC_PI_PRIO_PROPAGATE( proc, sync );
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
static void _bgrt_sync_touch_prio_up( bgrt_sync_t * sync, bgrt_proc_t * proc )
{
    BGRT_SPIN_LOCK( proc );

    _bgrt_proc_stop_ensure( proc );
    proc->sync = sync;
    _bgrt_pctrl_proc_run_high( proc, BGRT_PROC_STATE_RUNNING );

    BGRT_SPIN_FREE( proc );
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
            BGRT_CNT_INC( sync->dirty ) ;
            BGRT_CNT_INC( sync->snum ); //Increment sleeping process counter. Caller is going to sleep.
            BGRT_SPIN_FREE( sync );

            _bgrt_sync_touch_prio_up( sync, current );
        }
        else
        {
            BGRT_SPIN_FREE( sync );
        }
        return BGRT_ST_ROLL;
    }
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
    BGRT_CNT_INC( sync->dirty ) ;
    BGRT_CNT_INC( sync->snum ); //Increment sleeping process counter. Caller is going to sleep.
    BGRT_SPIN_FREE( sync );

    current = bgrt_curr_proc();
    _bgrt_sync_touch_prio_up( sync, current );

    return BGRT_ST_OK;
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
static void _bgrt_sync_snum_dec( bgrt_sync_t * sync )
{
    if( sync->snum )
    {
        sync->snum--;// Decrement sleeping proc count.
    }
}
//========================================================================================
bgrt_st_t _bgrt_sync_sleep( bgrt_sync_t * sync, bgrt_flag_t * touch )
{
    bgrt_proc_t * proc;
    bgrt_prio_t old_prio, new_prio;
    bgrt_flag_t sync_clear; //Used as event flag and as temp var;

    _bgrt_proc_reset_watchdog();

    if( !sync )
    {
        return  BGRT_ST_ENULL;
    }

    proc = bgrt_curr_proc();

    BGRT_SPIN_LOCK( proc );
    //Use sync_clear as temp var.
    if( *touch )
    {
        *touch = 0;//Clear flag
        sync_clear = BGRT_PROC_STATE_PI_RUNNING;
    }
    else
    {
        sync_clear = BGRT_PROC_GET_STATE( proc );
    }
    BGRT_PROC_SET_STATE( proc, BGRT_PROC_STATE_RUNNING );

    switch( sync_clear )
    {
    case BGRT_PROC_STATE_SYNC_RUNNING:
    {
        BGRT_PROC_LRES_DEC( proc, 0 );
        _bgrt_pctrl_proc_running( proc, BGRT_PROC_STATE_RUNNING );

        BGRT_SPIN_FREE( proc );
        BGRT_KERNEL_PREEMPT();
        BGRT_SPIN_LOCK( sync );

        _bgrt_sync_snum_dec(sync); //One sleeping proc less!

        if( sync->pwake )
        {
            _bgrt_sync_do_pending_wake( sync );
        }
        BGRT_SPIN_FREE( sync );

        return BGRT_ST_OK;
    }
    case BGRT_PROC_STATE_TO_RUNNING:
    {
        //sync->snum decremented in _bgrt_sync_proc_timeout !!!
        //no need to BGRT_SPIN_LOCK( sync ) !!!
        BGRT_SPIN_FREE( proc );

        return BGRT_ST_ETIMEOUT;
    }
    case BGRT_PROC_STATE_PI_RUNNING:
    {
        //The end of priority inheritance transaction or bgrt_sync_own transaction
        _bgrt_sync_sleep_swap_locks( sync, proc );
        //No zero check needed, as a process state is BGRT_PROC_STATE_PI_RUNNING.
        sync_clear = (bgrt_flag_t)( (bgrt_cnt_t)1 == sync->dirty-- ); //Event!
        _bgrt_sync_proc_stop( proc, BGRT_PROC_STATE_SYNC_SLEEP );
        BGRT_PROC_LRES_DEC( proc, 0 );
        _bgrt_pctrl_proc_stoped( proc );
        if( sync->owner == proc )
        {
            bgrt_sched_proc_run( proc, BGRT_PROC_STATE_READY );

            BGRT_SPIN_FREE( proc );

            _bgrt_sync_snum_dec( sync ); //One sleeping process less!
            BGRT_SPIN_FREE( sync );

            return BGRT_ST_EOWN;
        }
        else
        {
            break;
        }
    }
    case BGRT_PROC_STATE_RUNNING:
    default:
    {
        _bgrt_sync_sleep_swap_locks( sync, proc );
        if( sync->owner == proc )
        {
            BGRT_SPIN_FREE( proc );

            _bgrt_sync_snum_dec( sync ); //One sleeping process less!
            BGRT_SPIN_FREE( sync );

            return BGRT_ST_EOWN;
        }
        else
        {
            _bgrt_sync_proc_stop( proc, BGRT_PROC_STATE_SYNC_SLEEP );
            BGRT_CNT_INC( sync->snum );  //Increment sleeping process counter. Caller is going to sleep.
            sync_clear = (bgrt_flag_t)0; //No event!
            break;
        }
    }
    }

    old_prio = BGRT_SYNC_PRIO( sync );
    proc->sync = sync;
    //Insert to wait list
    bgrt_pitem_insert( (bgrt_pitem_t *)proc, (bgrt_xlist_t *)sync );

    BGRT_SPIN_FREE( proc );
    //Here we process a state, not sync_clear event!
    if( ((bgrt_cnt_t)0 == sync->dirty) && (sync->pwake) )
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
static void _bgrt_sync_owner_block( bgrt_proc_t * owner )
{
    BGRT_SPIN_LOCK( owner );

    owner->sync = (bgrt_sync_t *)0;
    _bgrt_sync_proc_stop( owner, BGRT_PROC_STATE_SYNC_SLEEP );

    BGRT_SPIN_FREE( owner );
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

    current = bgrt_curr_proc();

    BGRT_SPIN_LOCK( current );
    if( BGRT_PROC_STATE_TO_RUNNING == BGRT_PROC_GET_STATE( current ) )
    {
        BGRT_PROC_SET_STATE( current, BGRT_PROC_STATE_RUNNING );
        BGRT_SPIN_FREE( current );

        return BGRT_ST_ETIMEOUT;
    }
    else
    {
        BGRT_SPIN_FREE( current );
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
        _bgrt_sync_proc_stop( owner, BGRT_PROC_STATE_SYNC_WAIT );
        BGRT_SPIN_FREE( owner );
    }

    BGRT_SPIN_FREE( sync );
    return status;
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
            if( sync->pwake < sync->snum )
            {
                sync->pwake++;
                status = BGRT_ST_OK;
            }
            else
            {
                status = BGRT_ST_EEMPTY; //We can,t wake more processes.
            }
            BGRT_SPIN_FREE( sync );

            return status;
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
    if( proc )
    {
        _bgrt_sync_do_wake( proc, sync, chown );
        status = BGRT_ST_OK;
    }
    else
    {
        status = BGRT_ST_EEMPTY;
    }

    if( owner )
    {
        BGRT_SPIN_LOCK( owner );

        if( !chown )
        {
            BGRT_PROC_LRES_INC( owner, BGRT_SYNC_PRIO( sync ) );
        }
        _bgrt_pctrl_proc_run( owner, BGRT_PROC_STATE_READY );

        BGRT_SPIN_FREE( owner );
    }

    BGRT_SPIN_FREE( sync );
    return status;
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
            break;
        }
        case BGRT_PROC_STATE_SYNC_SLEEP:
        {
            //Blocked on dirty sync, will wakeup soon
            status = BGRT_ST_OK;
            break;
        }
        default:
        {
            //Something went wrong...
            status = BGRT_ST_ESYNC;
            break;
        }
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

        return BGRT_ST_ESYNC;
    }
    else
    {
        bgrt_cnt_t pwake;

        pwake = sync->pwake;

        if((pwake)&&( pwake >= sync->snum ))
        {
            //The process is going to be woken up.
            BGRT_SPIN_FREE( proc );
            BGRT_SPIN_FREE( sync );

            return BGRT_ST_OK;
        }
    }

    switch( BGRT_PROC_GET_STATE( proc ) )
    {
    case BGRT_PROC_STATE_SYNC_SLEEP:
    {
        //Undo bgrt_sync_sleep
        bgrt_prio_t old_prio;

        _bgrt_sync_snum_dec( sync ); //One sleeping proc less

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
