/**************************************************************************
    BuguRTOS-0.0.x(nuTyx) a test code 4 BuguRTOS-0.x.x.
    Probably it won't B a real OS.
    Copyright (C) 2010  anonimous

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
// Types like index_t etc are declared in config.h
#include "../include/bugurt.h"

#define ITEM_CUT        proc_cut
#define ITEM_FASTCUT    proc_fast_cut
#define ITEM_INSERT     proc_insert
#define ITEM_MOVE       proc_move
#define LIST_SWITCH     proc_queue_switch
#define LIST_HEAD       proc_queue_head

#define ITEM_T          proc_t
#define PRIO_T          prio_t
#define INDEX_T         index_t
#define LIST_T          proc_queue_t

#define LIST            queue
#define HEAD            proc

#include "../include/worklist_c.h"

#undef ITEM_CUT
#undef ITEM_INSERT
#undef ITEM_MOVE
#undef LIST_SWITCH
#undef LIST_HEAD

#undef ITEM_T
#undef PRIO_T
#undef INDEX_T
#undef LIST_T

#undef LIST
#undef HEAD

//===========================================================
// proc descriptor and stack initialization
void proc_init(
                proc_t * proc,
                stack_t * stack_start,
                code_t code,
                prio_t prio,
                flag_t flags,
#ifdef CONFIG_MP
                affinity_t affinity,
#endif
                timer_t time_quant
            ){
    //register sched_t * sched = _enter_crit_sec();
#ifdef CONFIG_MP
    spin_init( (lock_t *)&proc->lock );
    spin_lock( (lock_t *)&proc->lock );
#endif
    proc->stack_start = (stack_t *)stack_start;

    proc->code = (code_t)code;
    proc->prio = (prio_t)prio;
    proc->flags = (flag_t)flags;
#ifdef CONFIG_MP
    proc->affinity = (affinity_t)affinity;
    proc->queue_lock = (lock_t *)0;
#endif
    proc->timer = (timer_t)time_quant;
    proc->time_quant = (timer_t)time_quant;
    proc->prev = (proc_t *)proc;
    proc->next = (proc_t *)proc;
    proc->queue = (proc_queue_t *)0;
    proc->sched = (sched_t *)0;
    //extern func
    stack_init( (proc_t *)proc );
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&proc->lock );
#endif
    //_exit_crit_sec( sched );
}
//===========================================================
void proc_run_wrapper( proc_t * proc ){
    // run the process code
    proc->code();
    // exit sequence, we must terminate process
    register sched_t * sched = (sched_t *)_enter_crit_sec();
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    proc->flags |= PROC_FLG_END;
    _proc_stop( (proc_t *)proc );
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&proc->lock );
#endif
    resched_local();
    _exit_crit_sec( (sched_t *)sched );
}
/************************************************************
*                                                           *
*                        CAUTION!!!                         *
*                                                           *
*                   4 internal use only                     *
*                                                           *
*                   proc must be locked                     *
*                                                           *
************************************************************/
bool_t _proc_run( proc_t * proc ){
    register sched_t * new_sched;
    register proc_queue_t * new_queue;
    bool_t need_resched = (bool_t)1;
#ifdef CONFIG_MP
    new_sched = load_balancer( (proc_t *)proc );
#else
    new_sched = (sched_t *)&system_sched;
#endif
    proc->flags |= PROC_FLG_RUN;
    proc->flags &= ~ ( PROC_FLG_WAIT | PROC_FLG_END );
    proc->sched = (sched_t *)new_sched;
    if( (flag_t)proc->flags & PROC_FLG_RT ){
        if((timer_t)proc->timer)new_queue = (proc_queue_t *)&new_sched->rt_ready;
        else return ((bool_t)0);
#ifdef CONFIG_MP
        proc->queue_lock = (lock_t *)&new_sched->rt_lock;
        // update stats
        spin_lock( (lock_t *)&new_sched->stat_lock );
        ((count_t)new_sched->proc_count_rt)++;
        new_sched->total_rt_quant += (timer_t)proc->time_quant;
        spin_unlock( (lock_t *)&new_sched->stat_lock );
#endif
    }else{
        if((timer_t)proc->timer)new_queue = (proc_queue_t *)new_sched->gp_ready;
        else{
            proc->timer = (timer_t)proc->time_quant;
            new_queue = (proc_queue_t *)new_sched->gp_expired;
            need_resched = (bool_t)0;
        }
#ifdef CONFIG_MP
        proc->queue_lock = (lock_t *)&new_sched->gp_lock;
        // update stats
        spin_lock( (lock_t *)&new_sched->stat_lock );
        ((count_t)new_sched->proc_count_gp)++;
        new_sched->total_gp_quant += (timer_t)proc->time_quant;
        spin_unlock( (lock_t *)&new_sched->stat_lock );
#endif
    }
#ifdef CONFIG_MP
    spin_lock( (lock_t *)proc->queue_lock );
#endif
    proc_insert( (proc_t *)proc, (proc_queue_t *)new_queue );
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)proc->queue_lock );
#endif
    return ((bool_t)need_resched);
}
//===========================================================
void _proc_run_and_resched( proc_t * proc, bool_t is_resched_needed ){
    // Do we REALY need reched?
#ifdef CONFIG_MP
    register bool_t need_resched = (bool_t)_proc_run( (proc_t *)proc );
    register sched_t * proc_sched = (sched_t *)proc->sched;
    spin_unlock( (lock_t *)&proc->lock );
    if( (bool_t)need_resched ){
        if( (sched_t *)proc_sched != (sched_t *)current_sched() ){
            //now we can resched
            resched_extern( (sched_t *)proc_sched );
            return;
        }
        if( (bool_t)is_resched_needed )resched_local();
    }
#else
    if( ( (bool_t)is_resched_needed )&&( (bool_t)_proc_run( (proc_t *)proc )) )resched_local();
#endif
}
//===========================================================
void proc_run( proc_t * proc ){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    if( ( (proc_queue_t *)proc->queue ) || ( (flag_t)proc->flags & PROC_FLG_END ) ){
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&proc->lock );
#endif
        goto end; // already running, or invalid call, also fools can not into running ended procrsses
    }
    _proc_run_and_resched( (proc_t *)proc, (bool_t)1 );
end:
    _exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void proc_run_from_isr( proc_t * proc ){
    register sched_t * sched = (sched_t *)current_sched();
    register bool_t nested_isr = (bool_t)((count_t)sched->nested_interrupts != (count_t)0);//true if interrupts R enabled on a local processor
    if( (bool_t)nested_isr )_enter_crit_sec_2( (sched_t *)sched );
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    if( ( (proc_queue_t *)proc->queue ) || ( (flag_t)proc->flags & PROC_FLG_END ) ){
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&proc->lock );
#endif
        goto end; // already running, or invalid call, also fools can not into running ended procrsses
    }
    _proc_run_and_resched( (proc_t *)proc, !(bool_t)nested_isr );
end:
    if( (bool_t)nested_isr )_exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void proc_run_no_resched( proc_t * proc ){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    if( ( (proc_queue_t *)proc->queue ) || ( (flag_t)proc->flags & PROC_FLG_END ) ) goto end; // already running, or invalid call, also fools can not into running ended procrsses
    _proc_run( (proc_t *)proc );
end:
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&proc->lock );
#endif
    _exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void proc_restart( proc_t * proc ){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    if( (proc_queue_t *)proc->queue ){
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&proc->lock );
#endif
        goto end; // already running, or invalid call
    }

    stack_init( (proc_t *)proc );
    proc->timer = (timer_t)proc->time_quant;
    proc->prev = (proc_t *)proc;
    proc->next = (proc_t *)proc;
    proc->queue = (proc_queue_t *)0;
    proc->sched = (sched_t *)0;
    // do we need reched?
    _proc_run_and_resched( (proc_t *)proc, (bool_t)1 );
end:
    _exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void proc_restart_from_isr( proc_t * proc ){
    register sched_t * sched = (sched_t *)current_sched();
    register bool_t nested_isr = (bool_t)((count_t)sched->nested_interrupts != (count_t)0);//true if interrupts R enabled on a local processor
    if( (bool_t)nested_isr )_enter_crit_sec_2( (sched_t *)sched );
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    if( (proc_queue_t *)proc->queue ){
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&proc->lock );
#endif
        goto end; // already running, or invalid call
    }

    stack_init( (proc_t *)proc );
    proc->timer = (timer_t)proc->time_quant;
    proc->prev = (proc_t *)proc;
    proc->next = (proc_t *)proc;
    proc->queue = (proc_queue_t *)0;
    proc->sched = (sched_t *)0;
    // do we need reched?
    _proc_run_and_resched( (proc_t *)proc, !(bool_t)nested_isr );
end:
    if( (bool_t)nested_isr )_exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void proc_restart_no_resched( proc_t * proc ){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    if( (proc_queue_t *)proc->queue )goto end; // already running, or invalid call

    stack_init( (proc_t *)proc );
    proc->timer = (timer_t)proc->time_quant;
    proc->prev = (proc_t *)proc;
    proc->next = (proc_t *)proc;
    proc->queue = (proc_queue_t *)0;
    proc->sched = (sched_t *)0;

    _proc_run( (proc_t *)proc );
end:
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&proc->lock );
#endif
    _exit_crit_sec( (sched_t *)sched );
}
/************************************************************
*                                                           *
*                        CAUTION!!!                         *
*                                                           *
*                   4 internal use only,                    *
*                                                           *
*                   proc must be locked,                    *
*                                                           *
*             do not run with PROC_FLG_WAIT set.            *
*                                                           *
************************************************************/
void _proc_stop( proc_t * proc ){
#ifdef CONFIG_MP
    register flag_t proc_flags = (flag_t)proc->flags;
    register lock_t * stat_lock = (lock_t *)&proc->sched->stat_lock;
#endif
    proc->flags &= ~PROC_FLG_RUN;
    // end waiting process 2 avoid common resource corruption
#ifdef CONFIG_MP
    if( (flag_t)proc_flags & PROC_FLG_WAIT )proc->flags |= PROC_FLG_END;
    else{
        // if proc isn't waiting 4 signal broadcast or 4 semaphore lock,
        // then it's supposed 2B running, and we must update stats
        spin_lock( (lock_t *)stat_lock );
        if( (flag_t)proc_flags & PROC_FLG_RT ){
            ((count_t)proc->sched->proc_count_rt)--;
            proc->sched->total_rt_quant -= (timer_t)proc->time_quant;
        }else{
            ((count_t)proc->sched->proc_count_gp)--;
            proc->sched->total_gp_quant -= (timer_t)proc->time_quant;
        }
        spin_unlock( stat_lock );
    }
    register lock_t * queue_lock = (lock_t *)proc->queue_lock;
    spin_lock( (lock_t *)queue_lock );
#else
    if( (flag_t)proc->flags & PROC_FLG_WAIT )proc->flags |= PROC_FLG_END;
#endif
    proc_cut( (proc_t *)proc );
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)queue_lock );
    proc->queue_lock = (lock_t *)0;
#endif
}
//==============================================================
void _proc_stop_and_resched( proc_t * proc, bool_t is_resched_needed ){
    if( (proc_queue_t *)proc->queue ){
        _proc_stop( (proc_t *)proc );
#ifdef CONFIG_MP
        register sched_t * proc_sched = (sched_t *)proc->sched;
        spin_unlock( (lock_t *)&proc->lock );
        if( (sched_t *)proc_sched != (sched_t *)current_sched() ){
        //now we can resched
            resched_extern( (sched_t *)proc_sched );
            return;
        }
#endif
        if( (bool_t)is_resched_needed ){
            resched_local();
            return;
        }
    }
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&proc->lock );
#endif
}
//==============================================================
void proc_stop( proc_t * proc ){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    _proc_stop_and_resched( (proc_t *)proc, (bool_t)1 );
    _exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void proc_stop_from_isr( proc_t * proc ){
    register sched_t * sched = (sched_t *)current_sched();
    register bool_t nested_isr = (bool_t)((count_t)sched->nested_interrupts != (count_t)0);//true if interrupts R enabled on a local processor
    if( (bool_t)nested_isr )_enter_crit_sec_2( (sched_t *)sched );
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    _proc_stop_and_resched( (proc_t *)proc, !(bool_t)nested_isr );
    if( (bool_t)nested_isr )_exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void proc_stop_no_resched( proc_t * proc ){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    if( (proc_queue_t *)proc->queue ){
        _proc_stop( (proc_t *)proc );
    }
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&proc->lock );
#endif
    _exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void proc_self_stop( void ){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
    register proc_t * proc = (proc_t *)sched->current_proc;
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    if( (proc_queue_t *)proc->queue ){
        _proc_stop( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( &proc->lock );
#endif
        resched_local();
        _exit_crit_sec( (sched_t *)sched );
        return;
    }
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&proc->lock );
#endif
    _exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void proc_reset_watchdog( void ){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
    register proc_t * proc = sched->current_proc;
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    if( (proc_queue_t *)proc->queue ){
        if( (flag_t)proc->flags & PROC_FLG_RT )proc->timer = (timer_t)proc->time_quant;
#ifdef CONFIG_MP
        spin_unlock( &proc->lock );
#endif
        _exit_crit_sec( (sched_t *)sched );
        return;
    }
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&proc->lock );
#endif
    _exit_crit_sec( (sched_t *)sched );
}
