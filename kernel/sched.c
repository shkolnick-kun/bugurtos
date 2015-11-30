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

#ifdef BGRT_CONFIG_MP
//========================================================================================
// Load balancing function
WEAK bgrt_cpuid_t bgrt_sched_load_balancer(proc_t * proc, bgrt_ls_t * stat)
{
    bgrt_cpuid_t core = (bgrt_cpuid_t)0, ret;
    bgrt_aff_t mask = (bgrt_aff_t)1;
    while( core < (bgrt_cpuid_t)BGRT_MAX_CPU )
    {
        if( proc->affinity & mask )
        {
            break;
        }
        mask<<=1;
        core++;
    }
    // Initial
    stat += (bgrt_cpuid_t)core;
    ret = core++;
    mask<<=1;
    {
        bgrt_prio_t proc_prio;
        load_t current_load, min_load;

        proc_prio = ((bgrt_prit_t *)proc)->prio;
        min_load = bgrt_stat_calc_load( proc_prio, stat++ );
        // Just find min load
        while( core < (bgrt_cpuid_t)BGRT_MAX_CPU )
        {
            current_load = bgrt_stat_calc_load( proc_prio, stat++ );
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
//Fing most loaded bgrt_ls_t object in an array
WEAK bgrt_cpuid_t bgrt_sched_highest_load_core( bgrt_ls_t * stat )
{
    load_t max_load;
    bgrt_cpuid_t object_core = (bgrt_cpuid_t)0; //max loaded core
    bgrt_cpuid_t core = (bgrt_cpuid_t)1;
    max_load  = bgrt_stat_calc_load( (bgrt_prio_t)BGRT_BITS_IN_INDEX_T, stat );

    while( core < (bgrt_cpuid_t)BGRT_MAX_CPU )
    {
        load_t current_load;
        current_load = bgrt_stat_calc_load( (bgrt_prio_t)BGRT_BITS_IN_INDEX_T, stat + core );
        if( current_load > max_load )
        {
            max_load = current_load;
            object_core = core;
        }
        core++;
    }

    return object_core;
}
#endif // BGRT_CONFIG_MP
//========================================================================================
// Initiate a scheduler object.
void bgrt_sched_init(bgrt_sched_t * sched, proc_t * idle)
{
#ifdef BGRT_CONFIG_MP
    bgrt_lock_t * sched_lock;
    sched_lock = &sched->lock;
    bgrt_spin_init( sched_lock );
    bgrt_spin_lock( sched_lock );
#endif // BGRT_CONFIG_MP
    sched->ready = (bgrt_xlist_t *)sched->plst;
    bgrt_xlist_init( sched->ready );
    sched->expired = (bgrt_xlist_t *)sched->plst + 1;
    bgrt_xlist_init( sched->expired );
    bgrt_prit_insert( (bgrt_prit_t *)idle, sched->ready );
    idle->flags |= BGRT_PROC_STATE_RUNNING;
    sched->current_proc = idle;
    sched->nested_crit_sec = (bgrt_cnt_t)0;
#ifdef BGRT_CONFIG_MP
    bgrt_spin_free( sched_lock );
    bgrt_stat_inc( idle, (bgrt_ls_t *)bgrt_kernel.stat + idle->core_id );
#endif // BGRT_CONFIG_MP
}
//========================================================================================
// Insert a process to ready list and update load information.
#ifdef BGRT_CONFIG_MP

static bgrt_sched_t * sched_stat_update_run( proc_t * proc )
{
    bgrt_spin_lock( &bgrt_kernel.stat_lock );
    proc->core_id = bgrt_sched_load_balancer( proc, (bgrt_ls_t *)bgrt_kernel.stat );
    bgrt_stat_inc( proc, (bgrt_ls_t *)bgrt_kernel.stat+proc->core_id );
    bgrt_spin_free( &bgrt_kernel.stat_lock );

    return ((bgrt_sched_t *)bgrt_kernel.sched + proc->core_id);
}

#define BGRT_SCHED_STAT_UPDATE_RUN(a) sched_stat_update_run(a)

#else  //BGRT_CONFIG_MP

#define BGRT_SCHED_STAT_UPDATE_RUN(a) (&bgrt_kernel.sched)

#endif //BGRT_CONFIG_MP
void bgrt_sched_proc_run( proc_t * proc, bgrt_flag_t state )
{
    bgrt_sched_t * sched;
    //Set new state
    BGRT_PROC_SET_STATE( proc, state );
    sched = BGRT_SCHED_STAT_UPDATE_RUN( proc );

    BGRT_SPIN_LOCK( sched );
    bgrt_prit_insert( (bgrt_prit_t *)proc, sched->ready );
    BGRT_SPIN_FREE( sched );

    BGRT_RESCHED_PROC( proc );
}
//========================================================================================
// Cut a process from ready or expired list, update load information.
void bgrt_sched_proc_stop(proc_t * proc)
{
#ifdef BGRT_CONFIG_MP
    bgrt_lock_t * bgrt_xlist_lock;
    bgrt_xlist_lock = &((bgrt_sched_t *)bgrt_kernel.sched + proc->core_id)->lock;

    bgrt_spin_lock( &bgrt_kernel.stat_lock );
    bgrt_stat_dec( proc, (bgrt_ls_t *)bgrt_kernel.stat + proc->core_id );
    bgrt_spin_free( &bgrt_kernel.stat_lock );

    bgrt_spin_lock( bgrt_xlist_lock );
#endif // BGRT_CONFIG_MP

    proc->flags &= BGRT_PROC_STATE_CLEAR_MASK;
    bgrt_prit_cut( (bgrt_prit_t *)proc );

#ifdef BGRT_CONFIG_MP
    bgrt_spin_free( bgrt_xlist_lock );
#endif // BGRT_CONFIG_MP
    BGRT_RESCHED_PROC( proc );
}
//========================================================================================
static void _sched_switch_current( bgrt_sched_t * sched, proc_t * current_proc )
{
    BGRT_SPIN_LOCK( current_proc );
    // Context save hook
    if( current_proc->sv_hook )
    {
        current_proc->sv_hook( current_proc->arg );
    }
    BGRT_SPIN_FREE( current_proc );

    BGRT_SPIN_LOCK( sched );
    // If ready list is empty, then swap ready and expired lists
    while( sched->ready->index == (bgrt_index_t)0 )
    {
        // The Kernel may panic here !!!
        bgrt_xlist_t * buf;
        buf = sched->ready;
        sched->ready = sched->expired;
        sched->expired = buf;
    }
    // Find new current process, scheduler object must be locked.
    current_proc = (proc_t *)bgrt_xlist_head( sched->ready ); // Preemptive multitasking!
    sched->current_proc = current_proc;
    BGRT_SPIN_FREE( sched );

    BGRT_SPIN_LOCK( current_proc );
    /***************************************************************************
    If a process was in READY state then it will go to RUNNING state,
    and if it was in W_READY state? then it will go to W_RUNNING state!!!
    ***************************************************************************/
    current_proc->flags &= BGRT_PROC_STATE_CLEAR_RUN_MASK;
    current_proc->flags |= BGRT_PROC_STATE_RUNNING;
    //Context restore hook
    if( current_proc->rs_hook )
    {
        current_proc->rs_hook( current_proc->arg );
    }
    BGRT_SPIN_FREE( current_proc );
}
/******************************************************************************************
If we have some CPU core and corresponding bgrt_sched_t object,
then "sched->current_proc", "sched->ready", "sched->expired fields"
must be changed only during "bgrt_sched_schedule" and "bgrt_sched_reschedule" execution.

So there are some limitations on "bgrt_sched_schedule" and "bgrt_sched_reschedule" usage:

1) These functions must be executed in atomic manner.
******************************************************************************************/
// Scheduling function, must be called when the system timer fires.
void bgrt_sched_schedule(void)
{
    proc_t * current_proc;
    bgrt_sched_t * sched;
    sched = BGRT_SCHED_INIT();
    // As sched->current_proc is changed on local core, we don't need to spin-lock sched->lock!
    current_proc = sched->current_proc;
    // We must spin-lock a process!
    BGRT_SPIN_LOCK( current_proc );
    // Is current process in ready list?
    if( (bgrt_xlist_t *)((bgrt_prit_t *)current_proc)->list == sched->ready )
    {
        /***************************************************************************
        Switch a process state from RUNNING/W_RUNNING to STOPED/W_MUT!
        ***************************************************************************/
        current_proc->flags &= BGRT_PROC_STATE_CLEAR_RUN_MASK;

        if( current_proc->flags & BGRT_PROC_FLG_RR )
        {
            // Switch ready sublist to a next process.
            BGRT_SPIN_LOCK( sched );
            bgrt_xlist_switch( sched->ready, ((bgrt_prit_t *)current_proc)->prio );
            BGRT_SPIN_FREE( sched );
        }
        //Is a process time slice over?
        if( current_proc->timer > (bgrt_tmr_t)1 )
        {
            current_proc->timer--;// No! Decrement a process timer!
            /**********************************************************************
            Switch a process state to READY/PI_READY/SYNC_READY.
            **********************************************************************/
            current_proc->flags |= BGRT_PROC_STATE_READY;
        }
        else
        {
            bgrt_flag_t flags;
            // A process time slice os over!!! A process must be transfered to an expired list!
            BGRT_SPIN_LOCK( sched );
            bgrt_prit_fast_cut( (bgrt_prit_t *)current_proc );
            BGRT_SPIN_FREE( sched );
#if defined(BGRT_CONFIG_MP) && defined(BGRT_CONFIG_USE_ALB)
            /***********************************************************************
            The bgrt_kernel.stat_lock is locked here if BGRT_CONFIG_USE_ALB config option defined.
            We must free bgrt_kernel.stat_lock in both "if" statement branches!!!
            ***********************************************************************/
            bgrt_spin_lock( &bgrt_kernel.stat_lock );
            // Update load stats after a process was cut!
            bgrt_stat_dec( current_proc, (bgrt_ls_t *)bgrt_kernel.stat + current_proc->core_id );
#endif // BGRT_CONFIG_USE_ALB
            // What process is it?
            flags = current_proc->flags;
            if(
                (!(flags & BGRT_PROC_FLG_RT))
#ifndef BGRT_CONFIG_HARD_RT
                ||(flags & BGRT_PROC_FLG_LOCK_MASK)
#endif // BGRT_CONFIG_HARD_RT

            )
            {
                //A process is not RT, or it didn't release some resources, transfer it to expired list and reset its timer.
#if defined(BGRT_CONFIG_MP) && defined(BGRT_CONFIG_USE_ALB)
                bgrt_sched_t * new_sched;
                // Load balancing
                current_proc->core_id = bgrt_sched_load_balancer( current_proc, (bgrt_ls_t *)bgrt_kernel.stat );
                // A new sched pointer
                new_sched = (bgrt_sched_t *)bgrt_kernel.sched + current_proc->core_id;
                // Update load stats before insert a process to expired list!
                bgrt_stat_inc( current_proc, (bgrt_ls_t *)bgrt_kernel.stat + current_proc->core_id );
                /******************************************************
                We need to free bgrt_kernel.stat_lock in that branch
                only when BGRT_CONFIG_USE_ALB option defined.
                ******************************************************/
                bgrt_spin_free( &bgrt_kernel.stat_lock );

                // Insert a process to expired list.
                BGRT_SPIN_LOCK( new_sched );
                bgrt_prit_insert( (bgrt_prit_t *)current_proc, new_sched->expired );
                BGRT_SPIN_FREE( new_sched );
#else // BGRT_CONFIG_MP BGRT_CONFIG_USE_ALB
                // Just insert a process to expired list.
                BGRT_SPIN_LOCK( sched );
                bgrt_prit_insert( (bgrt_prit_t *)current_proc, sched->expired );
                BGRT_SPIN_FREE( sched );

#endif // BGRT_CONFIG_MP BGRT_CONFIG_USE_ALB
                current_proc->timer = current_proc->time_quant; // Сбросили таймер!
                /**********************************************************************
                Switch a process state to READY/PI_READY/SYNC_READY.
                **********************************************************************/
                current_proc->flags |= BGRT_PROC_STATE_READY;
            }
            else
            {
                // A process is RT and it does not nave locked resources, stop it on watchdog!
#ifdef BGRT_CONFIG_MP
#ifndef BGRT_CONFIG_USE_ALB
                // Update load stats after a process was cut from ready list
                /*********************************************************
                If BGRT_CONFIG_USE_ALB option is not defined,
                then bgrt_kernel.stat_lock is locked only in that
                "if" statement branch.
                *********************************************************/
                bgrt_spin_lock( &bgrt_kernel.stat_lock );
                bgrt_stat_dec( current_proc, (bgrt_ls_t *)bgrt_kernel.stat + current_proc->core_id );
#endif // nBGRT_CONFIG_USE_ALB
                /*********************************************************
                We must free bgrt_kernel.stat_lock now. No exceptions!!!
                *********************************************************/
                bgrt_spin_free( &bgrt_kernel.stat_lock );
#endif // BGRT_CONFIG_MP
                ((bgrt_prit_t *)current_proc)->list = (void *)0;// Просто вырезали из списка, как в bgrt_prit_cut
                flags &= BGRT_PROC_STATE_CLEAR_MASK;
#ifdef BGRT_CONFIG_HARD_RT
                /**********************************************************************
                If process have some locked resources, then it goes to DEAD state,
                or it goes to WD_STOPED state.
                **********************************************************************/
                if( (bgrt_flag_t)0 == (flags & BGRT_PROC_FLG_LOCK_MASK) )
                {
                    flags |= BGRT_PROC_STATE_WD_STOPED;
                }
                else
                {
                    // Go to DEAD state.
                    flags |= BGRT_PROC_STATE_DEAD;
                }
#else // BGRT_CONFIG_HARD_RT
                /**********************************************************************
                In that branch of #ifdef BGRT_CONFIG_HARD_RT, we have a RT process, which
                does not have locked resources.
                **********************************************************************/
                flags |= BGRT_PROC_STATE_WD_STOPED;
#endif // BGRT_CONFIG_HARD_RT
                current_proc->flags = flags;
            }
        }
    }
    //Free current_proc spin-lock!
    BGRT_SPIN_FREE( current_proc );

    BGRT_KERNEL_PREEMPT(); // BGRT_KERNEL_PREEMPT

    _sched_switch_current( sched, current_proc );
}
//========================================================================================
// Resched function, called from resched ISR.
void bgrt_sched_reschedule(void)
{
    proc_t * current_proc;
    bgrt_sched_t * sched;
    sched = BGRT_SCHED_INIT();
    // We don't need to lock sched->lock as sched->current_proc changed on local core!
    current_proc = sched->current_proc;
    // Need to spin-lock a current proc!
    BGRT_SPIN_LOCK( current_proc );

    if( BGRT_PROC_STATE_RUNNING == ( current_proc->flags & BGRT_PROC_STATE_RUN_MASK ) )
    {
        current_proc->flags &= BGRT_PROC_STATE_CLEAR_RUN_MASK;
        current_proc->flags |= BGRT_PROC_STATE_READY;
    }

    BGRT_SPIN_FREE( current_proc );
    _sched_switch_current( sched, current_proc );
}
/**********************************************************************************************
                                      SYSCALL_BGRT_PROC_YELD
**********************************************************************************************/
bgrt_bool_t bgrt_sched_proc_yeld(void)
{
    volatile bgrt_bool_t ret;
    bgrt_syscall( SYSCALL_SCHED_BGRT_PROC_YELD, (void *)&ret );
    return ret;
}
//========================================================================================
bgrt_bool_t _bgrt_bgrt_sched_proc_yeld( void )
{
    bgrt_bool_t save_power = (bgrt_bool_t)0;
    bgrt_index_t proc_map;
    bgrt_sched_t * sched;
    proc_t * proc;

    sched = BGRT_SCHED_INIT();
    proc = sched->current_proc;

    BGRT_SPIN_LOCK( proc );

    if( BGRT_PROC_RUN_TEST( proc ) )
    {
        if( proc->flags & BGRT_PROC_FLG_RT )
        {
            bgrt_prio_t prio;

            bgrt_index_t mask = ~(bgrt_index_t)0;
            mask <<= ((bgrt_prit_t *)proc)->prio;
            mask = ~mask; // Mask all lower prio processes

            prio = ((bgrt_prit_t *)proc)->prio;

            BGRT_SPIN_LOCK( sched );

            bgrt_xlist_switch( sched->ready, prio );

            save_power = (bgrt_bool_t)(sched->ready->item[prio] == (bgrt_item_t *)proc);// Is there any other process in proc sublist? If none, then we probably can save power...

            proc_map = sched->ready->index;

            BGRT_SPIN_FREE( sched );

            proc_map &= mask; //Are there higher prio processes in sched->ready?
            save_power = save_power || ((bgrt_bool_t)!proc_map); // If there are some processes with proc->parent->group->prio >= prio, then we can't save power.
        }
        else
        {
#if defined(BGRT_CONFIG_MP) && defined(BGRT_CONFIG_USE_ALB)
            BGRT_SPIN_LOCK( sched );
            proc_map = sched->expired->index;
            BGRT_SPIN_FREE( sched );

            bgrt_sched_proc_stop(proc);

            BGRT_SPIN_LOCK( sched );
            proc_map |= sched->ready->index;
            BGRT_SPIN_FREE( sched );

            BGRT_PROC_SET_STATE( proc, BGRT_PROC_STATE_READY );

            sched = sched_stat_update_run( proc );

            BGRT_SPIN_LOCK( sched );
            bgrt_prit_insert( (bgrt_prit_t *)proc, sched->expired );
            BGRT_SPIN_FREE( sched );
#else // BGRT_CONFIG_MP BGRT_CONFIG_USE_ALB
            BGRT_SPIN_LOCK( sched );

            bgrt_prit_cut( (bgrt_prit_t *)proc );
            proc_map = sched->expired->index;

            BGRT_SPIN_FREE( sched );

            BGRT_SPIN_LOCK( sched );

            bgrt_prit_insert( (bgrt_prit_t *)proc, sched->expired );
            proc_map |= sched->ready->index;

            BGRT_SPIN_FREE( sched );
#endif // BGRT_CONFIG_MP BGRT_CONFIG_USE_ALB
            save_power = (bgrt_bool_t)!proc_map;

        }

    }
    proc->timer = proc->time_quant; // reset timer
    BGRT_RESCHED_PROC( proc );
    BGRT_SPIN_FREE( proc );

    BGRT_KERNEL_PREEMPT(); // BGRT_KERNEL_PREEMPT

    return save_power;
}
//========================================================================================
void scall_bgrt_bgrt_sched_proc_yeld( bgrt_bool_t * arg )
{
    *arg = _bgrt_bgrt_sched_proc_yeld();
}

#if defined(BGRT_CONFIG_MP) && (!defined(BGRT_CONFIG_USE_ALB))
/************************************
  "Lazy" load balancers.

Must be called when BGRT_CONFIG_USE_ALB option
was not defined.

May be used in combinations...
************************************/
void _bgrt_sched_lazy_load_balancer(bgrt_cpuid_t object_core)
{
    bgrt_sched_t * sched;
    proc_t * proc;
    sched = (bgrt_sched_t *)bgrt_kernel.sched + object_core;

    //Is there any process in expired list?
    //If "Yes" then will transfer it.
    bgrt_disable_interrupts();

    BGRT_SPIN_LOCK( sched );

    if( (bgrt_index_t)0 == sched->expired->index )
    {
        BGRT_SPIN_FREE( sched );
        bgrt_enable_interrupts();
        return;
    }
    proc = (proc_t *)bgrt_xlist_head( sched->expired ); // Target process.

    BGRT_SPIN_FREE( sched );
    bgrt_enable_interrupts();

    bgrt_disable_interrupts();
    BGRT_SPIN_LOCK( proc );
    // Check if a process is still running.
    if( BGRT_PROC_RUN_TEST( proc ) )
    {
        // Stop it;
        BGRT_SPIN_LOCK( sched );
        bgrt_prit_fast_cut( (bgrt_prit_t *)proc );
        BGRT_SPIN_FREE( sched );

        bgrt_resched(object_core); // Resched object core...

        // Process load stats...
        bgrt_spin_lock( &bgrt_kernel.stat_lock );

        bgrt_stat_dec( proc, (bgrt_ls_t *)bgrt_kernel.stat + object_core );

        object_core = bgrt_sched_load_balancer( proc, (bgrt_ls_t *)bgrt_kernel.stat );// New core for target process...
        sched = (bgrt_sched_t *)bgrt_kernel.sched + object_core;//New scheduler object...
        bgrt_stat_inc( proc, (bgrt_ls_t *)bgrt_kernel.stat + object_core );

        bgrt_spin_free( &bgrt_kernel.stat_lock );

        // Transfer a process to new core...
        proc->core_id = object_core;

        BGRT_SPIN_LOCK( sched );
        bgrt_prit_insert( (bgrt_prit_t *)proc, sched->expired );
        BGRT_SPIN_FREE( sched );
    }
    BGRT_SPIN_FREE( proc );
    bgrt_enable_interrupts();
}
//========================================================================================
// Global
void bgrt_sched_lazy_global_load_balancer(void)
{
    bgrt_cpuid_t object_core;
    // Find highest load core
    bgrt_disable_interrupts();
    bgrt_spin_lock( &bgrt_kernel.stat_lock );

    object_core = bgrt_sched_highest_load_core( (bgrt_ls_t *)bgrt_kernel.stat );

    bgrt_spin_free( &bgrt_kernel.stat_lock );
    bgrt_enable_interrupts();
    // Transfer load...
    _bgrt_sched_lazy_load_balancer( object_core );
}
//========================================================================================
// Local
void bgrt_sched_lazy_local_load_balancer(void)
{
    _bgrt_sched_lazy_load_balancer( bgrt_current_cpu() );
}
#endif // BGRT_CONFIG_MP BGRT_CONFIG_USE_ALB
