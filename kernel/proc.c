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

/* ADLINT:SF:[W0256,W0268,W1072,W0422] retval types, goto*/
/*****************************************************************************************
                              Internal Usage functions!!!
*****************************************************************************************/
void bgrt_priv_proc_stop_ensure(bgrt_proc_t * proc, bgrt_flag_t state)
{
    BGRT_ASSERT(proc, "The #proc must not be NULL!");

    if (BGRT_PROC_RUN_TEST(proc))
    {
        bgrt_sched_proc_stop(proc, state);
    }
}
/**********************************************************************************************
                                    Process control !!!
**********************************************************************************************/
/*Initiation.*/
bgrt_st_t bgrt_proc_init(
    bgrt_proc_t * proc, /*A process pointer*/
    bgrt_code_t pmain,
    bgrt_code_t sv_hook,
    bgrt_code_t rs_hook,
    void * arg,
    bgrt_stack_t *sstart,
    bgrt_prio_t prio,
    bgrt_tmr_t time_quant,
    bgrt_bool_t is_rt /* Is it RT process*/
#ifdef BGRT_CONFIG_MP
    ,bgrt_aff_t affinity
#endif /*BGRT_CONFIG_MP*/
)
{
    bgrt_st_t ret;
    BGRT_INT_LOCK();
    ret = bgrt_priv_proc_init(
              proc, /*A process pointer*/
              pmain,
              sv_hook,
              rs_hook,
              arg,
              sstart,
              prio,
              time_quant,
              is_rt /* Is it RT process?*/
#ifdef BGRT_CONFIG_MP
              ,affinity
#endif /*BGRT_CONFIG_MP*/
          );                  /* ADLINT:SL:[W0432] Indentation */
    BGRT_INT_FREE(); /* ADLINT:SL:[W0431] Indentation */
    return ret;
}
/*====================================================================================*/
bgrt_st_t bgrt_priv_proc_init(
    bgrt_proc_t * proc, /*A process pointer!*/
    bgrt_code_t pmain,
    bgrt_code_t sv_hook,
    bgrt_code_t rs_hook,
    void * arg,
    bgrt_stack_t *sstart,
    bgrt_prio_t prio,
    bgrt_tmr_t time_quant,
    bgrt_bool_t is_rt /*Is it RT process?*/
#ifdef BGRT_CONFIG_MP
    ,bgrt_aff_t affinity
#endif /*BGRT_CONFIG_MP*/
)
{
    BGRT_ASSERT(pmain,   "The #pmain must not be NULL!");
    BGRT_ASSERT(sv_hook, "The #sv_hook must not be NULL!");
    BGRT_ASSERT(rs_hook, "The #rs_hook must not be NULL!");
    BGRT_ASSERT(arg,     "The #arg must not be NULL!");
    BGRT_ASSERT(sstart,  "The #sstart must not be NULL!");

    if (!proc)
    {
        return BGRT_ST_ENULL;
    }

    BGRT_SPIN_INIT(proc);
    BGRT_SPIN_LOCK(proc);

    bgrt_pitem_init((bgrt_pitem_t *)proc, prio);
    proc->flags = (is_rt)?(BGRT_PROC_FLG_RT|BGRT_PROC_FLG_RR):(BGRT_PROC_FLG_RR); /* Default behavior is round robin scheduling*/

    BGRT_PROC_LRES_INIT(proc);

    proc->base_prio = prio;
    proc->time_quant = time_quant;
    proc->timer = time_quant;
    proc->sync = (bgrt_sync_t *)0; /* ADLINT:SL:[W0567] Int to pointer*/
    proc->cnt_lock = (bgrt_cnt_t)0;
#ifdef BGRT_CONFIG_MP
    proc->core_id = (bgrt_cpuid_t)0;
    proc->affinity = affinity;
#endif /*BGRT_CONFIG_MP*/
    proc->pmain = pmain;
    proc->sv_hook = sv_hook;
    proc->rs_hook = rs_hook;
    proc->arg = arg;
    proc->sstart = sstart;

    if (sstart)
    {
        proc->spointer = bgrt_proc_stack_init(sstart, (bgrt_code_t)pmain, (void *)arg, (void (*)(void))bgrt_proc_terminate);
    }

    BGRT_USPD_INIT(proc); /* ADLINT:SL:[W0567,W0425] Int to pointer, multiline macro*/

    BGRT_SPIN_FREE(proc);

    return BGRT_ST_OK;
}
/*====================================================================================*/
/* Run a process? used in ISRs and in #BGRT_SYSCALL_PROC_RUN*/
bgrt_st_t bgrt_priv_proc_run(bgrt_proc_t * proc)
{
    bgrt_st_t ret = BGRT_ST_OK;

    if (!proc)
    {
        return BGRT_ST_ENULL;
    }

    BGRT_SPIN_LOCK(proc);

    if (BGRT_PROC_STATE_STOPED != BGRT_PROC_GET_STATE(proc))
    {
        ret = BGRT_ST_EAGAIN;
        goto end;
    }
    BGRT_SCHED_PROC_SET_CORE(proc);
    bgrt_sched_proc_run(proc, BGRT_PROC_STATE_READY);
end:
    BGRT_SPIN_FREE(proc);
    return ret;
}
/*====================================================================================*/
/* Restart a process from some ISR.*/
bgrt_st_t bgrt_priv_proc_restart(bgrt_proc_t * proc)
{
    bgrt_st_t ret = BGRT_ST_OK;

    if (!proc)
    {
        return BGRT_ST_ENULL;
    }

    BGRT_SPIN_LOCK(proc);

    if (proc->flags & (BGRT_PROC_FLG_LOCK_MASK|BGRT_PROC_STATE_RESTART_MASK))
    {
        ret = BGRT_ST_ESTAT;
        goto end;
    }
    proc->flags = (proc->flags & BGRT_PROC_FLG_RT)?BGRT_PROC_FLG_RT:(bgrt_flag_t)0;

    BGRT_PROC_LRES_INIT(proc);

    proc->timer = proc->time_quant;

    if (proc->sstart)
    {
        proc->spointer = bgrt_proc_stack_init(proc->sstart, (bgrt_code_t)proc->pmain, (void *)proc->arg, (void (*)(void))bgrt_proc_terminate);
    }
    BGRT_SCHED_PROC_SET_CORE(proc);
    bgrt_sched_proc_run(proc, BGRT_PROC_STATE_READY);
end:
    BGRT_SPIN_FREE(proc);
    return ret;
}
/*====================================================================================*/
/* Stop a process from ISR*/
bgrt_st_t bgrt_priv_proc_stop(bgrt_proc_t * proc)
{
    bgrt_st_t ret = BGRT_ST_EAGAIN;

    if (!proc)
    {
        proc = bgrt_curr_proc();
    }

    BGRT_SPIN_LOCK(proc);
    /*Check flags*/
    /*When the process in wait state or locked, we must stop it later, so set BGRT_PROC_FLG_PRE_STOP flag.*/
    if (proc->flags & (BGRT_PROC_FLG_LOCK_MASK|BGRT_PROC_FLG_PRE_STOP|BGRT_PROC_STATE_WAIT_MASK))
    {
        proc->flags |= BGRT_PROC_FLG_PRE_STOP;
    }
    else
    {
        bgrt_priv_proc_stop_ensure(proc, BGRT_PROC_STATE_STOPED);
        ret = BGRT_ST_OK; /* ADLINT:SL:[W0085] Side effects*/
    }

    BGRT_SPIN_FREE(proc);
    return ret;
}
/*====================================================================================*/
void bgrt_priv_proc_lock(void)
{
    bgrt_proc_t * proc;
    proc = bgrt_curr_proc();

    BGRT_SPIN_LOCK(proc);

    proc->flags |= BGRT_PROC_FLG_LOCK;
    BGRT_CNT_INC(proc->cnt_lock);

    BGRT_SPIN_FREE(proc);
}
/*====================================================================================*/
/* #BGRT_PROC_FLG_PRE_STOP processing with mask clearing.*/
void bgrt_priv_proc_free(void)
{
    bgrt_proc_t * proc;
    proc = bgrt_curr_proc();

    BGRT_SPIN_LOCK(proc);

    BGRT_CNT_DEC(proc->cnt_lock);

    if (((bgrt_cnt_t)0) == proc->cnt_lock)
    {
        proc->flags &= ~BGRT_PROC_FLG_LOCK;
    }
    /*
    If a process stop was called
    and a process does not have locked resources,
    then stop a process.
    */
    if (BGRT_PROC_PRE_STOP_TEST(proc)) /* ADLINT:SL:[W0734,W0559,W0432] Operators in macro*/
    {
        bgrt_priv_proc_stop_ensure(proc, BGRT_PROC_STATE_STOPED);
        proc->flags &= ~BGRT_PROC_FLG_PRE_STOP;
    }

    BGRT_SPIN_FREE(proc);
}
/*====================================================================================*/
void bgrt_priv_proc_self_stop(void)
{
    bgrt_proc_t * proc;
    proc = bgrt_curr_proc();

    BGRT_SPIN_LOCK(proc);

    bgrt_priv_proc_stop_ensure(proc, BGRT_PROC_STATE_STOPED);

    BGRT_SPIN_FREE(proc);
}
/*====================================================================================*/
void bgrt_priv_proc_terminate(void)
{
    bgrt_proc_t * proc;
    proc = bgrt_curr_proc();

    BGRT_SPIN_LOCK(proc);

    bgrt_priv_proc_stop_ensure(proc, BGRT_PROC_STATE_STOPED);
    /* Flags processing!*/
    /* A process is not allowed to return from pmain while being locked! */
    if (proc->flags & BGRT_PROC_FLG_LOCK_MASK)
    {
        proc->flags |= BGRT_PROC_STATE_DEAD;
    }
    else
    {
        /* A normal process termination. */
        proc->flags |= BGRT_PROC_STATE_END;
    }
    proc->flags &= ~BGRT_PROC_FLG_PRE_STOP;

    BGRT_SPIN_FREE(proc);
}
/*====================================================================================*/
void bgrt_priv_proc_reset_watchdog(void)
{
    bgrt_proc_t * proc;
    proc = bgrt_curr_proc();

    BGRT_SPIN_LOCK(proc);

    if (proc->flags & BGRT_PROC_FLG_RT)
    {
        proc->timer = proc->time_quant;
    }

    BGRT_SPIN_FREE(proc);
}
/*====================================================================================*/
bgrt_prio_t bgrt_priv_proc_get_prio(bgrt_proc_t * proc)
{
    bgrt_prio_t ret;

    if (!proc)
    {
        proc = bgrt_curr_proc();
    }

    BGRT_SPIN_LOCK(proc);
    ret = proc->base_prio;
    BGRT_SPIN_FREE(proc);

    return ret;
}
