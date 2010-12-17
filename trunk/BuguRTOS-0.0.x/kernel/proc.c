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
    spin_init( &proc->lock );
    spin_lock( &proc->lock );
#endif
    proc->stack_start = stack_start;
    //extern func
    stack_init( proc );

    proc->code = code;
    proc->prio = prio;
    proc->flags = flags;
#ifdef CONFIG_MP
    proc->affinity = affinity;
    proc->queue_lock = (lock_t *)0;
#endif
    proc->timer = time_quant;
    proc->time_quant = time_quant;
    proc->prev = proc;
    proc->next = proc;
    proc->queue = (proc_queue_t *)0;
    proc->sched = (sched_t *)0;
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
    //_exit_crit_sec( sched );
}
//===========================================================
void proc_run_wrapper( proc_t * proc ){
    // run the process code
    proc->code();
    // exit sequence, we must terminate process
    register sched_t * sched = _enter_crit_sec();
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif
    _proc_stop( proc );
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
    resched_local();
    _exit_crit_sec( sched );
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
    bool_t need_resched = 1;
#ifdef CONFIG_MP
    new_sched = load_balancer( proc );
#else
    new_sched = &system_sched;
#endif
    proc->flags |= PROC_FLG_RUN;
    proc->flags &= ~PROC_FLG_WAIT;
    proc->sched = new_sched;
    if( proc->flags & PROC_FLG_RT ){
        if(proc->timer)new_queue = &new_sched->rt_ready;
        else return (0);
#ifdef CONFIG_MP
        proc->queue_lock = &new_sched->rt_lock;
        // update stats
        spin_lock( &new_sched->stat_lock );
        new_sched->proc_count_rt++;
        new_sched->total_rt_quant += proc->time_quant;
        spin_unlock( &new_sched->stat_lock );
#endif
    }else{
        if(proc->timer)new_queue = new_sched->gp_ready;
        else{
            proc->timer = proc->time_quant;
            new_queue = new_sched->gp_expired;
            need_resched = 0;
        }
#ifdef CONFIG_MP
        proc->queue_lock = &new_sched->gp_lock;
        // update stats
        spin_lock( &new_sched->stat_lock );
        new_sched->proc_count_gp++;
        new_sched->total_gp_quant += proc->time_quant;
        spin_unlock( &new_sched->stat_lock );
#endif
    }
#ifdef CONFIG_MP
    spin_lock( proc->queue_lock );
#endif
    proc_insert( proc, new_queue );
#ifdef CONFIG_MP
    spin_unlock( proc->queue_lock );
#endif
    return (need_resched);
}
//===========================================================
void proc_run( proc_t * proc ){
    register sched_t * sched = _enter_crit_sec();
#ifdef CONFIG_MP
    register sched_t * proc_sched;
    spin_lock( &proc->lock );
#endif
    if( proc->queue ) goto end; // already running, or invalid call
    // do we need reched?
    bool_t need_resched = _proc_run( proc );
#ifdef CONFIG_MP
    proc_sched = proc->sched;
    spin_unlock( &proc->lock );
#endif
    if( need_resched ){
#ifdef CONFIG_MP
        if( proc_sched != sched ){
            //now we can resched
            resched_extern( proc_sched );
            _exit_crit_sec( sched );
            return;
        }
#endif
        resched_local();
    }
    _exit_crit_sec( sched );
    return;
end:
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
    _exit_crit_sec( sched );
}
//===========================================================
void proc_run_no_resched( proc_t * proc ){
    register sched_t * sched = _enter_crit_sec();
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif
    if( proc->queue ) goto end; // already running, or invalid call
    _proc_run( proc );
end:
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
    _exit_crit_sec( sched );
}
//==============================================================
void proc_restart( proc_t * proc ){
    register sched_t * sched = _enter_crit_sec();
#ifdef CONFIG_MP
    register sched_t * proc_sched;
    spin_lock( &proc->lock );
#endif
    if( proc->queue )goto end; // already running, or invalid call

    stack_init( proc );
    proc->timer = proc->time_quant;
    proc->prev = proc;
    proc->next = proc;
    proc->queue = (proc_queue_t *)0;
    proc->sched = (sched_t *)0;

    // do we need reched?
    bool_t need_resched = _proc_run( proc );
#ifdef CONFIG_MP
    proc_sched = proc->sched;
    spin_unlock( &proc->lock );
#endif
    if( need_resched ){
#ifdef CONFIG_MP
        if( proc_sched != sched ){
            //now we can resched
            resched_extern( proc_sched );
            _exit_crit_sec( sched );
            return;
        }
#endif
        resched_local();
    }
    _exit_crit_sec( sched );
    return;
end:
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
    _exit_crit_sec( sched );
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
void _proc_stop( proc_t * proc ){
#ifdef CONFIG_MP
    register lock_t * stat_lock = &proc->sched->stat_lock;
    // if proc isn't waiting 4 signal broadcast or 4 semaphore lock,
    // then it's supposed 2B running, and we must update stats
    register flag_t proc_flags = proc->flags;
    if( !(proc_flags & PROC_FLG_WAIT) ){
        spin_lock( stat_lock );
        if( proc_flags & PROC_FLG_RT ){
            proc->sched->proc_count_rt--;
            proc->sched->total_rt_quant -= proc->time_quant;
        }else{
            proc->sched->proc_count_gp--;
            proc->sched->total_gp_quant -= proc->time_quant;
        }
        spin_unlock( stat_lock );
    }

    register lock_t * queue_lock = proc->queue_lock;
    spin_lock( queue_lock );
#endif
    proc_cut( proc );
    proc->flags &= ~PROC_FLG_RUN;
#ifdef CONFIG_MP
    spin_unlock( queue_lock );
    proc->queue_lock = (lock_t *)0;
#endif
}
//==============================================================
void proc_stop( proc_t * proc ){
    register sched_t * sched = _enter_crit_sec();
#ifdef CONFIG_MP
    register sched_t * proc_sched;
    spin_lock( &proc->lock );
#endif
    if( proc->queue ){
        _proc_stop( proc );
#ifdef CONFIG_MP
        proc_sched = proc->sched;
        spin_unlock( &proc->lock );
        if( proc_sched != sched ){
            //now we can resched
            resched_extern( proc_sched );
            _exit_crit_sec( sched );
            return;
        }
#endif
        resched_local();
        _exit_crit_sec( sched );
        return;
    }
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
    _exit_crit_sec( sched );
}
//==============================================================
void proc_stop_no_resched( proc_t * proc ){
    register sched_t * sched = _enter_crit_sec();
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif
    if( proc->queue ){
        _proc_stop( proc );
    }
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
    _exit_crit_sec( sched );
}
//==============================================================
void proc_self_stop( void ){
    register sched_t * sched = _enter_crit_sec();
    register proc_t * proc = sched->current_proc;
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif
    if( proc->queue ){
        _proc_stop( proc );
#ifdef CONFIG_MP
        spin_unlock( &proc->lock );
#endif
        resched_local();
        _exit_crit_sec( sched );
        return;
    }
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
    _exit_crit_sec( sched );
}
//==============================================================
void proc_reset_watchdog( void ){
    register sched_t * sched = _enter_crit_sec();
    register proc_t * proc = sched->current_proc;
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif
    if( proc->queue ){
        if( proc->flags & PROC_FLG_RT )proc->timer = proc->time_quant;
#ifdef CONFIG_MP
        spin_unlock( &proc->lock );
#endif
        _exit_crit_sec( sched );
        return;
    }
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
    _exit_crit_sec( sched );
}
