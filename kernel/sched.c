/**************************************************************************
    BuguRTOS-4.0.x (Bugurt real time operating system)
    Copyright (C) 2018 anonimous

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

/* ADLINT:SF:[W1052,W0422] pointer OVF, NULL */

#ifdef BGRT_CONFIG_MP
/*====================================================================================*/
/* Load balancing function*/
WEAK bgrt_cpuid_t bgrt_sched_load_balancer(bgrt_proc_t * proc, bgrt_ls_t * stat)
{
    bgrt_cpuid_t core = (bgrt_cpuid_t)0;
    bgrt_cpuid_t ret;
    bgrt_aff_t mask = (bgrt_aff_t)1;

    BGRT_ASSERT(proc, "The #proc must not be NULL!");
    BGRT_ASSERT(stat, "The #stat must not be NULL!");

    while (core < (bgrt_cpuid_t)BGRT_MAX_CPU)
    {
        if (proc->affinity & mask)
        {
            break;
        }
        mask<<=1;
        core++;
    }
    /* Initial*/
    stat += (bgrt_cpuid_t)core;
    ret = core++; /* ADLINT:SL:[W0512] inc in expr*/
    mask<<=1;
    {
        bgrt_prio_t proc_prio;
        bgrt_load_t current_load;
        bgrt_load_t min_load;

        proc_prio = ((bgrt_pitem_t *)proc)->prio;
        min_load = bgrt_stat_calc_load(proc_prio, stat++); /* ADLINT:SL:[W0512] inc in expr*/
        /* Just find min load*/
        while (core < (bgrt_cpuid_t)BGRT_MAX_CPU)
        {
            current_load = bgrt_stat_calc_load(proc_prio, stat++); /* ADLINT:SL:[W0512] inc in expr*/
            if ((proc->affinity & mask) && (current_load < min_load)) /* ADLINT:SL:[W0734] inc in expr*/
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
/*====================================================================================*/
/*Find most loaded bgrt_ls_t object in an array*/
WEAK bgrt_cpuid_t bgrt_sched_highest_load_core(bgrt_ls_t * stat) /* ADLINT:SL:[W0432] Indentation*/
{/* ADLINT:SL:[W0431] Indentation*/
    bgrt_load_t max_load;
    bgrt_cpuid_t object_core = (bgrt_cpuid_t)0; /*max loaded core*/
    bgrt_cpuid_t core = (bgrt_cpuid_t)1;

    BGRT_ASSERT(stat, "The #stat must not be NULL!");

    max_load  = bgrt_stat_calc_load((bgrt_prio_t)BGRT_BITS_IN_INDEX_T, stat);

    while (core < (bgrt_cpuid_t)BGRT_MAX_CPU)
    {
        bgrt_load_t current_load;
        current_load = bgrt_stat_calc_load((bgrt_prio_t)BGRT_BITS_IN_INDEX_T, stat + core);
        if (current_load > max_load)
        {
            max_load = current_load;
            object_core = core;
        }
        core++;
    }

    return object_core;
}
#endif /*BGRT_CONFIG_MP*/
/*====================================================================================*/
/*Initiate a scheduler object.*/
void bgrt_sched_init(bgrt_sched_t * sched)
{
#ifdef BGRT_CONFIG_MP
    bgrt_lock_t * sched_lock;
    sched_lock = &sched->lock;
    bgrt_spin_init(sched_lock);
    bgrt_spin_lock(sched_lock);
#endif /*BGRT_CONFIG_MP*/

    BGRT_ASSERT(sched, "The #sched must not be NULL!");

    sched->ready = (bgrt_xlist_t *)sched->plst;
    bgrt_xlist_init(sched->ready);
    sched->expired = (bgrt_xlist_t *)sched->plst + 1; /* ADLINT:SL:[W0567] Int to pointer*/
    bgrt_xlist_init(sched->expired);
    sched->current_proc = (bgrt_proc_t *)0; /* ADLINT:SL:[W0567] Int to pointer*/
    sched->nested_crit_sec = (bgrt_cnt_t)0;
#ifdef BGRT_CONFIG_MP
    bgrt_spin_free(sched_lock);
#endif /*BGRT_CONFIG_MP*/
}

/*====================================================================================*/
/*Insert a process to ready list and update load information.*/
#ifdef BGRT_CONFIG_MP
void bgrt_priv_sched_proc_set_core(bgrt_proc_t * proc)
{
    BGRT_ASSERT(proc, "The #proc must not be NULL!");

    BGRT_SPIN_LOCK(&bgrt_kernel.stat);
    proc->core_id = bgrt_sched_load_balancer(proc, (bgrt_ls_t *)bgrt_kernel.stat.val);
    BGRT_SPIN_FREE(&bgrt_kernel.stat);
}

static bgrt_sched_t * _sched_stat_update_run(bgrt_proc_t * proc)
{
    BGRT_ASSERT(proc, "The #proc must not be NULL!");

    BGRT_SPIN_LOCK(&bgrt_kernel.stat);
    bgrt_stat_inc(proc, (bgrt_ls_t *)bgrt_kernel.stat.val + proc->core_id);
    BGRT_SPIN_FREE(&bgrt_kernel.stat);

    return ((bgrt_sched_t *)&bgrt_kernel.sched[proc->core_id]); /* ADLINT:SL:[W0705] out of range*/
}
static void _sched_stat_update_stop(bgrt_proc_t * proc)
{
    BGRT_ASSERT(proc, "The #proc must not be NULL!");

    BGRT_SPIN_LOCK(&bgrt_kernel.stat);
    bgrt_stat_dec(proc, (bgrt_ls_t *)bgrt_kernel.stat.val + proc->core_id);
    BGRT_SPIN_FREE(&bgrt_kernel.stat);
}
static bgrt_sched_t * _sched_stat_update_migrate(bgrt_proc_t * proc)
{
    BGRT_ASSERT(proc, "The #proc must not be NULL!");

    BGRT_SPIN_LOCK(&bgrt_kernel.stat);
    bgrt_stat_dec(proc, (bgrt_ls_t *)bgrt_kernel.stat.val + proc->core_id);
    proc->core_id = bgrt_sched_load_balancer(proc, (bgrt_ls_t *)bgrt_kernel.stat.val);
    bgrt_stat_inc(proc, (bgrt_ls_t *)bgrt_kernel.stat.val + proc->core_id);
    BGRT_SPIN_FREE(&bgrt_kernel.stat);

    return ((bgrt_sched_t *)&bgrt_kernel.sched[proc->core_id]); /* ADLINT:SL:[W0705] out of range*/
}
#   define BGRT_SCHED_STAT_UPDATE_RUN(a)  _sched_stat_update_run(a)
#   define BGRT_SCHED_STAT_UPDATE_STOP(a) _sched_stat_update_stop(a)
#else  /*BGRT_CONFIG_MP*/
#   define BGRT_SCHED_STAT_UPDATE_RUN(a) (&bgrt_kernel.sched)
#   define BGRT_SCHED_STAT_UPDATE_STOP(a) do{}while (0)
#endif /*BGRT_CONFIG_MP*/
void bgrt_sched_proc_run(bgrt_proc_t * proc, bgrt_flag_t state)
{
    bgrt_sched_t * sched;

    BGRT_ASSERT(proc, "The #proc must not be NULL!");

    /*Set new state*/
    BGRT_PROC_SET_STATE(proc, state); /* ADLINT:SL:[W0447] coma operator*/
    sched = BGRT_SCHED_STAT_UPDATE_RUN(proc);

    BGRT_SPIN_LOCK(sched);
    bgrt_pitem_insert((bgrt_pitem_t *)proc, sched->ready);
    BGRT_SPIN_FREE(sched);

    BGRT_RESCHED_PROC(proc);
}
/*====================================================================================*/
/* Cut a process from ready or expired list, update load information.*/
void bgrt_sched_proc_stop(bgrt_proc_t * proc , bgrt_flag_t state)
{
#ifdef BGRT_CONFIG_MP
    bgrt_lock_t * xlist_lock;

    _sched_stat_update_stop(proc);

    xlist_lock = &bgrt_kernel.sched[proc->core_id].lock; /* ADLINT:SL:[W0705] out of range*/
    bgrt_spin_lock(xlist_lock);
#endif /*BGRT_CONFIG_MP*/

    BGRT_ASSERT(proc, "The #proc must not be NULL!");

    BGRT_PROC_SET_STATE(proc, state); /* ADLINT:SL:[W0447] coma operator*/
    bgrt_pitem_cut((bgrt_pitem_t *)proc);

#ifdef BGRT_CONFIG_MP
    bgrt_spin_free(xlist_lock);
#endif /*BGRT_CONFIG_MP*/
    BGRT_RESCHED_PROC(proc);
}
/*====================================================================================*/
static bgrt_st_t _bgrt_sched_epilogue(bgrt_sched_t * sched)
{
    bgrt_proc_t * current_proc;
    bgrt_st_t status = BGRT_ST_OK;

    BGRT_ASSERT(sched, "The #sched must not be NULL!");

    current_proc = sched->current_proc;
    /* Context save hook*/
    if (current_proc)
    {
        BGRT_SPIN_LOCK(current_proc);
        if (current_proc->sv_hook)
        {
            current_proc->sv_hook(current_proc->arg);
        }
        BGRT_SPIN_FREE(current_proc);
    }

    BGRT_SPIN_LOCK(sched);

    if ((bgrt_map_t)0 == sched->ready->map)
    {
        /* If ready list is empty, then swap ready and expired lists*/
        bgrt_xlist_t * buf;
        buf = sched->ready;
        sched->ready = sched->expired;
        sched->expired = buf;

        /* The system is IDLE, clear current proc*/
        sched->current_proc = (bgrt_proc_t *)0; /* ADLINT:SL:[W0567] Int to pointer*/
        status = BGRT_ST_IDLE;
    }

    if ((bgrt_map_t)0 == sched->ready->map)
    {
        BGRT_SPIN_FREE(sched);
        status = BGRT_ST_EEMPTY; /*Give an error code*/
    }
    else
    {
        /* Find new current process, scheduler object must be locked.*/
        current_proc = (bgrt_proc_t *)bgrt_xlist_head(sched->ready); /* Preemptive multitasking!*/
        sched->current_proc = current_proc;
        BGRT_SPIN_FREE(sched);

        /*Schedule new process*/
        BGRT_SPIN_LOCK(current_proc);
        /***************************************************************************
            Switch a process state from *_READY to *_RUNNING
        ***************************************************************************/
        current_proc->flags &= BGRT_PROC_STATE_CLEAR_RUN_MASK;
        current_proc->flags |= BGRT_PROC_STATE_RUNNING;
        /*Context restore hook*/
        if (current_proc->rs_hook)
        {
            current_proc->rs_hook(current_proc->arg);
        }
        BGRT_SPIN_FREE(current_proc);
    }

    return status;
}

#ifdef BGRT_CONFIG_MP
static void _bgrt_sched_proc_insert_expired(bgrt_proc_t * proc, bgrt_sched_t * sched)
{
    BGRT_ASSERT(sched, "The #sched must not be NULL!");

    BGRT_SPIN_LOCK(sched);
    bgrt_pitem_insert((bgrt_pitem_t *)proc, sched->expired);
    BGRT_SPIN_FREE(sched);
}
#   define BGRT_SCHED_PROC_INSERT_EXPIRED _bgrt_sched_proc_insert_expired
#else /*BGRT_CONFIG_MP*/
#   define BGRT_SCHED_PROC_INSERT_EXPIRED(proc,sched) bgrt_pitem_insert((bgrt_pitem_t *)proc, sched->expired)
#endif/*BGRT_CONFIG_MP*/

#if defined(BGRT_CONFIG_MP) && defined(BGRT_CONFIG_USE_ALB)
#   define BGRT_PROC_NEW_SCHED _sched_stat_update_migrate /*A process will migrate*/
#else /* BGRT_CONFIG_MP BGRT_CONFIG_USE_ALB */
#   define BGRT_PROC_NEW_SCHED(proc) sched       /*A process will stay on the same scheduler*/
#endif/* BGRT_CONFIG_MP BGRT_CONFIG_USE_ALB */

#ifdef BGRT_CONFIG_HARD_RT  /*Hard real time, the process may be "killed" or "wd stopped"*/
#   define BGRT_PROC_NEW_STATE(flags) ((flags & BGRT_PROC_FLG_LOCK_MASK)?(BGRT_PROC_STATE_DEAD):(BGRT_PROC_STATE_WD_STOPED))
#else /*BGRT_CONFIG_HARD_RT Soft real time, just stop the process!*/
#   define BGRT_PROC_NEW_STATE(flags) (BGRT_PROC_STATE_WD_STOPED)
#endif/*BGRT_CONFIG_HARD_RT*/

/******************************************************************************************
If we have some CPU core and corresponding bgrt_sched_t object,
then "sched->current_proc", "sched->ready", "sched->expired fields"
must be changed only during "bgrt_sched_schedule" and "bgrt_sched_reschedule" execution.

So there are some limitations on "bgrt_sched_schedule" and "bgrt_sched_reschedule" usage:

1) These functions must be executed in atomic manner.
******************************************************************************************/
/* Scheduling function, must be called when the system timer fires.*/
static void _bgrt_sched_schedule_prologue(bgrt_sched_t * sched)
{
    bgrt_proc_t * current_proc;

    BGRT_ASSERT(sched, "The #sched must not be NULL!");

    /* As sched->current_proc is changed on local core, we don't need to spin-lock sched->lock! */
    current_proc = sched->current_proc;
    /*This is IDLE situation, do nothing.*/
    if (!current_proc)
    {
        return;
    }
    /*We must spin-lock a process!*/
    BGRT_SPIN_LOCK(current_proc);
    /*Is current process in ready list?*/
    if ((bgrt_xlist_t *)((bgrt_pitem_t *)current_proc)->list == sched->ready)
    {
        /***************************************************************************
        Switch a process state from *_RUNNING to *_READY
        ***************************************************************************/
        current_proc->flags &= BGRT_PROC_STATE_CLEAR_RUN_MASK;
        current_proc->flags |= BGRT_PROC_STATE_READY;

        if (current_proc->flags & BGRT_PROC_FLG_RR)
        {
            /*Switch ready sublist to a next process.*/
            BGRT_SPIN_LOCK(sched);
            bgrt_xlist_switch(sched->ready, ((bgrt_pitem_t *)current_proc)->prio);
            BGRT_SPIN_FREE(sched);
        }
        /*Is a process time slice over?*/
        if (current_proc->timer > (bgrt_tmr_t)1)
        {
            current_proc->timer--;/*No! Decrement a process timer!*/
        }
        else
        {
            bgrt_flag_t flags;
            /*A process time slice os over!!! A process must be transfered to an expired list! */
            BGRT_SPIN_LOCK(sched);
            bgrt_pitem_fast_cut((bgrt_pitem_t *)current_proc);
            BGRT_SPIN_FREE(sched);

            /*What process is it?*/
            flags = current_proc->flags;
            if (
                (!(flags & BGRT_PROC_FLG_RT)) /* ADLINT:SL:[W0559] neg operator*/
#ifndef BGRT_CONFIG_HARD_RT
                ||(flags & BGRT_PROC_FLG_LOCK_MASK)
#endif /*BGRT_CONFIG_HARD_RT*/

            )
            {
                /*Clear the process timer*/
                current_proc->timer = current_proc->time_quant;
                /*A process is not RT, or it was locked in soft real time configuration,
                transfer it to expired list and reset its timer.*/
                BGRT_SCHED_PROC_INSERT_EXPIRED(current_proc, BGRT_PROC_NEW_SCHED(current_proc));
            }
            else
            {
                /* A process is RT and it does not nave locked resources, stop it on watchdog! */
                BGRT_SCHED_STAT_UPDATE_STOP(current_proc);
                /*Finish process cut*/
                ((bgrt_pitem_t *)current_proc)->list = (void *)0; /* ADLINT:SL:[W0567] Int to pointer*/
                /*Update process state*/
                BGRT_PROC_SET_STATE(current_proc, BGRT_PROC_NEW_STATE(flags)); /* ADLINT:SL:[W0447] coma operator*/
            }
        }
    }
    /*Free current_proc spin-lock!*/
    BGRT_SPIN_FREE(current_proc);
}
/*====================================================================================*/
/* Resched function, called from resched ISR.*/
static void _bgrt_sched_reschedule_prologue(bgrt_sched_t * sched)
{
    bgrt_proc_t * current_proc;

    BGRT_ASSERT(sched, "The #sched must not be NULL!");

    /* We don't need to lock sched->lock as sched->current_proc changed on local core!*/
    current_proc = sched->current_proc;
    if (current_proc)
    {
        /* Need to spin-lock a current proc!*/
        BGRT_SPIN_LOCK(current_proc);

        if (BGRT_PROC_STATE_RUNNING == (current_proc->flags & BGRT_PROC_STATE_RUN_MASK))
        {
            /***************************************************************************
            Switch a process state from *_RUNNING to *_READY
            ***************************************************************************/
            current_proc->flags &= BGRT_PROC_STATE_CLEAR_RUN_MASK;
            current_proc->flags |= BGRT_PROC_STATE_READY;
        }

        BGRT_SPIN_FREE(current_proc);
    }
}

/*====================================================================================*/
#define _BGRT_SCHED_LLB(sched) do{}while(0)

#if defined(BGRT_CONFIG_MP) && (!defined(BGRT_CONFIG_USE_ALB))
static void _bgrt_sched_lazy_load_balancer(bgrt_cpuid_t object_core)
{
    bgrt_sched_t * sched;
    bgrt_proc_t * proc;
    sched = (bgrt_sched_t *)&bgrt_kernel.sched[object_core];

    /*Is there any process in expired list?*/
    /*If "Yes" then will transfer it.*/

    BGRT_SPIN_LOCK(sched);

    if ((bgrt_map_t)0 == sched->expired->map)
    {
        BGRT_SPIN_FREE(sched);
        return;
    }
    proc = (bgrt_proc_t *)bgrt_xlist_head(sched->expired); /* Target process.*/

    BGRT_SPIN_FREE(sched);

    BGRT_SPIN_LOCK(proc);

    if (BGRT_PROC_RUN_TEST(proc))
    {
        /* If the process is still running...*/
        /* Stop it;*/
        sched = (bgrt_sched_t *)&bgrt_kernel.sched[proc->core_id];

        BGRT_SPIN_LOCK(sched);
        bgrt_pitem_fast_cut((bgrt_pitem_t *)proc);
        BGRT_SPIN_FREE(sched);

        bgrt_resched(proc->core_id); /* Resched object core...*/

        /* Migrate it*/
        sched = _sched_stat_update_migrate(proc);

        BGRT_SCHED_PROC_INSERT_EXPIRED(proc, sched);
    }
    BGRT_SPIN_FREE(proc);
}
/*====================================================================================*/
/* Global*/
static void _bgrt_sched_lazy_global_load_balancer(void)
{
    bgrt_cpuid_t object_core;
    /* Find highest load core*/
    BGRT_SPIN_LOCK(&bgrt_kernel.stat);
    object_core = bgrt_sched_highest_load_core((bgrt_ls_t *)bgrt_kernel.stat.val);
    BGRT_SPIN_FREE(&bgrt_kernel.stat);
    /* Transfer load...*/
    _bgrt_sched_lazy_load_balancer(object_core);
}
static void _bgrt_sched_llb(bgrt_sched_t * sched)
{
    bgrt_map_t map;

    BGRT_SPIN_LOCK(sched);
    map = sched->ready->map;
    BGRT_SPIN_FREE(sched);

    if (0 == map)
    {
        _bgrt_sched_lazy_global_load_balancer();
    }
}
/*====================================================================================*/
#   ifdef BGRT_CONFIG_USE_LLB
#       undef  _BGRT_SCHED_LLB
#       define _BGRT_SCHED_LLB(sched) _bgrt_sched_llb(sched)
#   endif/*BGRT_CONFIG_USE_LLB*/
#endif/*BGRT_CONFIG_MP*/

#ifdef BGRT_CONFIG_MP
#   define BGRT_SCHED_INIT() ((bgrt_sched_t *)&bgrt_kernel.sched[bgrt_curr_cpu()])
#else /*BGRT_CONFIG_MP*/
#   define BGRT_SCHED_INIT() ((bgrt_sched_t *)&bgrt_kernel.sched)
#endif /*BGRT_CONFIG_MP*/

bgrt_st_t bgrt_sched_run(bgrt_bool_t is_periodic)
{
    bgrt_sched_t * sched;
    sched = BGRT_SCHED_INIT();/* ADLINT:SL:[W0567,W0705] Int to pointer, OOR*/
    if (is_periodic)
    {
        _bgrt_sched_schedule_prologue(sched);
    }
    else
    {
        _bgrt_sched_reschedule_prologue(sched);
    }
    /*
    WARNING: NO KERNEL PREEMPTION HERE!!!

    Kernel preemption may lead to stack overflow
    due to recursive core rescheduling!!!
    */
    _BGRT_SCHED_LLB(sched);
    return _bgrt_sched_epilogue(sched);
}
/*====================================================================================*/


bgrt_bool_t bgrt_priv_sched_proc_yield(void)
{
    bgrt_bool_t save_power = (bgrt_bool_t)0;
    bgrt_map_t proc_map;
    bgrt_proc_t * proc;
    bgrt_sched_t * sched;

    sched = BGRT_SCHED_INIT(); /* ADLINT:SL:[W0567,W0705] Int to pointer, OOR*/

    BGRT_ASSERT(sched, "The #sched must not be NULL!");

    proc = sched->current_proc;

    BGRT_SPIN_LOCK(proc);

    if (BGRT_PROC_RUN_TEST(proc))
    {
        if (proc->flags & BGRT_PROC_FLG_RT)
        {
            bgrt_prio_t prio;

            bgrt_map_t mask = ~(bgrt_map_t)0;
            mask <<= ((bgrt_pitem_t *)proc)->prio; /* ADLINT:SL:[W0165] type conversion*/
            mask = ~mask; /* Mask all lower prio processes*/

            prio = ((bgrt_pitem_t *)proc)->prio;

            BGRT_SPIN_LOCK(sched);

            bgrt_xlist_switch(sched->ready, prio); /* ADLINT:SL:[W1026] 1st arg type*/
            /* Is there any other process in proc sublist? If none, then we probably can save power...*/
            save_power = (bgrt_bool_t)(sched->ready->item[prio] == (bgrt_item_t *)proc);/* ADLINT:SL:[W0567,W0608,W0705] type conversions*/

            proc_map = sched->ready->map;

            BGRT_SPIN_FREE(sched);
            /*Are there higher prio processes in sched->ready?*/
            proc_map &= mask; /* ADLINT:SL:[W0165] type conversions*/
            /* If there are some processes with proc->parent->group->prio >= prio, then we can't save power.*/
            save_power = save_power || ((bgrt_bool_t)!proc_map); /* ADLINT:SL:[W0608,W0168] type conversions*/
        }
        else
        {
            BGRT_SPIN_LOCK(sched);
            proc_map = sched->expired->map;

            bgrt_pitem_fast_cut((bgrt_pitem_t *)proc);

            proc_map |= sched->ready->map; /* ADLINT:SL:[W0165] type conversions*/

            bgrt_pitem_insert((bgrt_pitem_t *)proc, sched->expired); /* ADLINT:SL:[W1026] 2nd arg type*/
            BGRT_SPIN_FREE(sched);

            save_power = (bgrt_bool_t)!proc_map; /* ADLINT:SL:[W0608,W0168] type conversions*/
        }

    }
    proc->timer = proc->time_quant; /* reset timer*/
    BGRT_RESCHED_PROC(proc);
    BGRT_SPIN_FREE(proc);

    BGRT_KERNEL_PREEMPT(); /* ADLINT:SL:[W0705,W0067] type conversions*/

    return save_power;
}
