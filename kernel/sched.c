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
#include "bugurt.h"

#ifdef CONFIG_MP
//========================================================================================
// Load balancing function
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
    // Initial
    stat += (core_id_t)core;
    ret = core++;
    mask<<=1;
    {
        prio_t proc_prio;
        load_t current_load, min_load;

        proc_prio = ((pitem_t *)proc)->prio;
        min_load = stat_calc_load( proc_prio, stat++ );
        // Just find min load
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
//Fing most loaded stat_t object in an array
WEAK core_id_t sched_highest_load_core( stat_t * stat )
{
    load_t max_load;
    core_id_t object_core = (core_id_t)0; //max loaded core
    core_id_t core = (core_id_t)1;
    max_load  = stat_calc_load( (prio_t)BITS_IN_INDEX_T, stat );

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
// Initiate a scheduler object.
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
    pitem_insert( (pitem_t *)idle, sched->ready );
    idle->flags = PROC_STATE_RUNNING;
    sched->current_proc = idle;
    sched->nested_crit_sec = (count_t)0;
#ifdef CONFIG_MP
    spin_free( sched_lock );
    stat_inc( idle, (stat_t *)kernel.stat + idle->core_id );
#endif // CONFIG_MP
}
//========================================================================================
// Insert a process to ready list and update load information.
#ifdef CONFIG_MP

static sched_t * sched_stat_update_run( proc_t * proc )
{
    spin_lock( &kernel.stat_lock );
    proc->core_id = sched_load_balancer( proc, (stat_t *)kernel.stat );
    stat_inc( proc, (stat_t *)kernel.stat+proc->core_id );
    spin_free( &kernel.stat_lock );

    return ((sched_t *)kernel.sched + proc->core_id);
}

#define SCHED_STAT_UPDATE_RUN(a) sched_stat_update_run(a)

#else  //CONFIG_MP

#define SCHED_STAT_UPDATE_RUN(a) (&kernel.sched)

#endif //CONFIG_MP
void sched_proc_run( proc_t * proc, flag_t state )
{
    sched_t * sched;
    //Set new state
    PROC_SET_STATE( proc, state );
    sched = SCHED_STAT_UPDATE_RUN( proc );

    SPIN_LOCK( sched );
    pitem_insert( (pitem_t *)proc, sched->ready );
    SPIN_FREE( sched );

    RESCHED_PROC( proc );
}
//========================================================================================
// Cut a process from ready or expired list, update load information.
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
    pitem_cut( (pitem_t *)proc );

#ifdef CONFIG_MP
    spin_free( xlist_lock );
#endif // CONFIG_MP
    RESCHED_PROC( proc );
}
//========================================================================================
static void _sched_switch_current( sched_t * sched, proc_t * current_proc )
{
    SPIN_LOCK( current_proc );
    // Context save hook
    if( current_proc->sv_hook )current_proc->sv_hook( current_proc->arg );
    SPIN_FREE( current_proc );

    SPIN_LOCK( sched );
    // If ready list is empty, then swap ready and expired lists
    while( sched->ready->index == (index_t)0 )
    {
        // The Kernel may panic here !!!
        xlist_t * buf;
        buf = sched->ready;
        sched->ready = sched->expired;
        sched->expired = buf;
    }
    // Find new current process, scheduler object must be locked.
    current_proc = (proc_t *)xlist_head( sched->ready ); // Preemptive multitasking!
    sched->current_proc = current_proc;
    SPIN_FREE( sched );

    SPIN_LOCK( current_proc );
    /***************************************************************************
    If a process was in READY state then it will go to RUNNING state,
    and if it was in W_READY state? then it will go to W_RUNNING state!!!
    ***************************************************************************/
    current_proc->flags &= PROC_STATE_CLEAR_RUN_MASK;
    current_proc->flags |= PROC_STATE_RUNNING;
    //Context restore hook
    if( current_proc->rs_hook )current_proc->rs_hook( current_proc->arg );
    SPIN_FREE( current_proc );
}
/******************************************************************************************
If we have some CPU core and corresponding sched_t object,
then "sched->current_proc", "sched->ready", "sched->expired fields"
must be changed only during "sched_schedule" and "sched_reschedule" execution.

So there are some limitations on "sched_schedule" and "sched_reschedule" usage:

1) These functions must be executed in atomic manner.
******************************************************************************************/
// Scheduling function, must be called when the system timer fires.
void sched_schedule(void)
{
    proc_t * current_proc;
    sched_t * sched;
    sched = _SCHED_INIT();
    // As sched->current_proc is changed on local core, we don't need to spin-lock sched->lock!
    current_proc = sched->current_proc;
    // We must spin-lock a process!
    SPIN_LOCK( current_proc );
    // Is current process in ready list?
    if( (xlist_t *)((pitem_t *)current_proc)->list == sched->ready )
    {
        /***************************************************************************
        Switch a process state from RUNNING/W_RUNNING to STOPED/W_MUT!
        ***************************************************************************/
        current_proc->flags &= PROC_STATE_CLEAR_RUN_MASK;
        // Switch ready sublist to a next process.
        SPIN_LOCK( sched );
        xlist_switch( sched->ready, ((pitem_t *)current_proc)->prio );
        SPIN_FREE( sched );
        //Is a process time slice over?
        if( current_proc->timer > (timer_t)1 )
        {
            current_proc->timer--;// No! Decrement a process timer!
            /**********************************************************************
            Switch a process state to READY/W_READY from STOPED/W_MUT!
            **********************************************************************/
            current_proc->flags |= PROC_STATE_READY;
        }
        else
        {
            flag_t flags;
            // A process time slice os over!!! A process must be transfered to an expired list!
            SPIN_LOCK( sched );
            pitem_fast_cut( (pitem_t *)current_proc );
            SPIN_FREE( sched );
#if defined(CONFIG_MP) && defined(CONFIG_USE_ALB)
            /***********************************************************************
            The kernel.stat_lock is locked here if CONFIG_USE_ALB config option defined.
            We must free kernel.stat_lock in both "if" ctatement branches!!!
            ***********************************************************************/
            spin_lock( &kernel.stat_lock );
            // Update load stats after a process was cut!
            stat_dec( current_proc, (stat_t *)kernel.stat + current_proc->core_id );
#endif // CONFIG_USE_ALB
            // What process is it?
            flags = current_proc->flags;
            if(
                (!(flags & PROC_FLG_RT))
#ifndef CONFIG_HARD_RT
                ||(flags & PROC_FLG_LOCK_MASK)
#endif // CONFIG_HARD_RT

            )
            {
                //A process is not RT, or it didn't release some resources, transfer it to expired list and reset its timer.
#if defined(CONFIG_MP) && defined(CONFIG_USE_ALB)
                sched_t * new_sched;
                // Load balancing
                current_proc->core_id = sched_load_balancer( current_proc, (stat_t *)kernel.stat );
                // A new sched pointer
                new_sched = (sched_t *)kernel.sched + current_proc->core_id;
                // Update load stats before insert a process to expired list!
                stat_inc( current_proc, (stat_t *)kernel.stat + current_proc->core_id );
                /******************************************************
                We need to free kernel.stat_lock in that branch
                only when CONFIG_USE_ALB option defined.
                ******************************************************/
                spin_free( &kernel.stat_lock );

                // Insert a process to expired list.
                SPIN_LOCK( new_sched );
                pitem_insert( (pitem_t *)current_proc, new_sched->expired );
                SPIN_FREE( new_sched );
#else // CONFIG_MP CONFIG_USE_ALB
                // Just insert a process to expired list.
                SPIN_LOCK( sched );
                pitem_insert( (pitem_t *)current_proc, sched->expired );
                SPIN_FREE( sched );

#endif // CONFIG_MP CONFIG_USE_ALB
                current_proc->timer = current_proc->time_quant; // Сбросили таймер!
                /**********************************************************************
                Switch a process state to READY/W_READY from STOPED/W_MUT!
                **********************************************************************/
                current_proc->flags |= PROC_STATE_READY;
            }
            else
            {
                // A process is RT and it does not nave locked resources, stop it on watchdog!
#ifdef CONFIG_MP
#ifndef CONFIG_USE_ALB
                // Update load stats after a process was cut from ready list
                /*********************************************************
                If CONFIG_USE_ALB option is not defined,
                then kernel.stat_lock is locked only in that
                "if" statement branch.
                *********************************************************/
                spin_lock( &kernel.stat_lock );
                stat_dec( current_proc, (stat_t *)kernel.stat + current_proc->core_id );
#endif // nCONFIG_USE_ALB
                /*********************************************************
                We must free kernel.stat_lock now. No exceptions!!!
                *********************************************************/
                spin_free( &kernel.stat_lock );
#endif // CONFIG_MP
                ((pitem_t *)current_proc)->list = (void *)0;// Просто вырезали из списка, как в pitem_cut
#ifdef CONFIG_HARD_RT
                /**********************************************************************
                If process have some locked resources, then it goes to DEAD/W_DEAD state,
                or it goes to WD_STOPED/W_WD_STOPED state.
                **********************************************************************/
                if( (flags & PROC_FLG_LOCK_MASK) == (flag_t)0 )
                {
                    current_proc->flags = (PROC_FLG_RT|PROC_STATE_WD_STOPED);
                }
                else
                {
                    // Go to DEAD/W_DEAD state.
                    current_proc->flags |= PROC_STATE_DEAD;
                }
#else // CONFIG_HARD_RT
                /**********************************************************************
                In that branch of #ifdef CONFIG_HARD_RT, we have a RT process, which
                does not have locked resources.

                If a process was in W_MUT state, then it goes to W_WD_STOPED,
                in other cases it goes to WD_STOPED state.
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
    //Free current_proc spin-lock!
    SPIN_FREE( current_proc );

    KERNEL_PREEMPT(); // KERNEL_PREEMPT

    _sched_switch_current( sched, current_proc );
}
//========================================================================================
// Reched function, called from resched ISR.
void sched_reschedule(void)
{
    proc_t * current_proc;
    sched_t * sched;
    sched = _SCHED_INIT();
    // We don't need to lock sched->lock as sched->current_proc changed on local core!
    current_proc = sched->current_proc;
    // Need to spin-lock a current proc!
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
bool_t sched_proc_yeld(void)
{
    volatile bool_t ret;
    syscall_bugurt( SYSCALL_SCHED_PROC_YELD, (void *)&ret );
    return ret;
}
//========================================================================================
bool_t _sched_proc_yeld( void )
{
    bool_t save_power = (bool_t)0;
    index_t proc_map;
    sched_t * sched;
    proc_t * proc;

    sched = _SCHED_INIT();
    proc = sched->current_proc;

    SPIN_LOCK( proc );

    if( PROC_RUN_TEST( proc ) )
    {
        if( proc->flags & PROC_FLG_RT )
        {
            prio_t prio;

            index_t mask = ~(index_t)0;
            mask <<= ((pitem_t *)proc)->prio;
            mask = ~mask; // Mask all lower prio processes

            prio = ((pitem_t *)proc)->prio;

            SPIN_LOCK( sched );

            xlist_switch( sched->ready, prio );

            save_power = (bool_t)(sched->ready->item[prio] == (item_t *)proc);// Is there any other process in proc sublist? If none, then we probably can save poswer...

            proc_map = sched->ready->index;

            SPIN_FREE( sched );

            proc_map &= mask; //Are there higher prio processes in sched->ready?
            save_power = save_power || ((bool_t)!proc_map); // If there are some processes with proc->parent->group->prio >= prio, then we can't save power.
        }
        else
        {
#if defined(CONFIG_MP) && defined(CONFIG_USE_ALB)
            SPIN_LOCK( sched );
            proc_map = sched->expired->index;
            SPIN_FREE( sched );

            sched_proc_stop(proc);

            SPIN_LOCK( sched );
            proc_map |= sched->ready->index;
            SPIN_FREE( sched );

            PROC_SET_STATE( proc, PROC_STATE_READY );

            sched = sched_stat_update_run( proc );

            SPIN_LOCK( sched );
            pitem_insert( (pitem_t *)proc, sched->expired );
            SPIN_FREE( sched );
#else // CONFIG_MP CONFIG_USE_ALB
            SPIN_LOCK( sched );

            pitem_cut( (pitem_t *)proc );
            proc_map = sched->expired->index;

            SPIN_FREE( sched );

            SPIN_LOCK( sched );

            pitem_insert( (pitem_t *)proc, sched->expired );
            proc_map |= sched->ready->index;

            SPIN_FREE( sched );
#endif // CONFIG_MP CONFIG_USE_ALB
            save_power = (bool_t)!proc_map;

        }

    }
    proc->timer = proc->time_quant; // reset timer
    RESCHED_PROC( proc );
    SPIN_FREE( proc );

    KERNEL_PREEMPT(); // KERNEL_PREEMPT

    return save_power;
}
//========================================================================================
void scall_sched_proc_yeld( void * arg )
{
    *((bool_t *)arg) = _sched_proc_yeld();
}

#if defined(CONFIG_MP) && (!defined(CONFIG_USE_ALB))
/************************************
  "Lazy" load balancers.

Must be called when CONFIG_USE_ALB option
was not defined.

May be used in combinations...
************************************/
void _sched_lazy_load_balancer(core_id_t object_core)
{
    sched_t * sched;
    proc_t * proc;
    sched = (sched_t *)kernel.sched + object_core;

    //Is there any process in expired list?
    //If "Yes" then will transfer it.
    disable_interrupts();

    SPIN_LOCK( sched );

    if(sched->expired->index == (index_t)0)
    {
        SPIN_FREE( sched );
        enable_interrupts();
        return;
    }
    proc = (proc_t *)xlist_head( sched->expired ); // Target process.

    SPIN_FREE( sched );
    enable_interrupts();

    disable_interrupts();
    SPIN_LOCK( proc );
    // Check if a process is still running.
    if( PROC_RUN_TEST( proc ) )
    {
        // Stop it;
        SPIN_LOCK( sched );
        pitem_fast_cut( (pitem_t *)proc );
        SPIN_FREE( sched );

        resched(object_core); // Resched object core...

        // Process load stats...
        spin_lock( &kernel.stat_lock );

        stat_dec( proc, (stat_t *)kernel.stat + object_core );

        object_core = sched_load_balancer( proc, (stat_t *)kernel.stat );// New core for target process...
        sched = (sched_t *)kernel.sched + object_core;//New scheduler object...
        stat_inc( proc, (stat_t *)kernel.stat + object_core );

        spin_free( &kernel.stat_lock );

        // Transfer a process to new core...
        proc->core_id = object_core;

        SPIN_LOCK( sched );
        pitem_insert( (pitem_t *)proc, sched->expired );
        SPIN_FREE( sched );
    }
    SPIN_FREE( proc );
    enable_interrupts();
}
//========================================================================================
// Global
void sched_lazy_global_load_balancer(void)
{
    core_id_t object_core;
    // Find highest losd core
    disable_interrupts();
    spin_lock( &kernel.stat_lock );

    object_core = sched_highest_load_core( (stat_t *)kernel.stat );

    spin_free( &kernel.stat_lock );
    enable_interrupts();
    // Transfer load...
    _sched_lazy_load_balancer( object_core );
}
//========================================================================================
// Local
void sched_lazy_local_load_balancer(void)
{
    _sched_lazy_load_balancer( current_core() );
}
#endif // CONFIG_MP CONFIG_USE_ALB
