/**************************************************************************
    BuguRTOS-0.1.x(sguschenka) a small OS 4 microcontrollers.
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
                timer_t time_quant
            ){
    //register sched_t * sched = _enter_crit_sec();
    proc->stack_start = stack_start;
    proc->code = code;
    proc->prio = prio;
    proc->flags = flags;
    proc->timer = time_quant;
    proc->time_quant = time_quant;
    proc->prev = proc;
    proc->next = proc;
    proc->queue = (proc_queue_t *)0;
    proc->sched = (sched_t *)0;
    //extern func
    stack_init( proc );

    //_exit_crit_sec( sched );
}
//===========================================================
void proc_run_wrapper( proc_t * proc ){
    // run the process code
    proc->code();
    // exit sequence, we must terminate process
    enter_crit_sec();
    proc->flags |= PROC_FLG_END;
    _proc_stop( proc );
    resched_local();
    exit_crit_sec();
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

    register sched_t * new_sched = (sched_t *)&system_sched;

    register proc_queue_t * new_queue;

    bool_t need_resched = 1;

    proc->flags |= PROC_FLG_RUN;
    proc->flags &= ~ ( PROC_FLG_WAIT | PROC_FLG_END );
    proc->sched = (sched_t *)new_sched;

    if( (flag_t)proc->flags & PROC_FLG_RT ){
        if((timer_t)proc->timer)new_queue = (proc_queue_t *)&new_sched->rt_ready;
        else return ((bool_t)0);
    }else{
        if((timer_t)proc->timer)new_queue = (proc_queue_t *)new_sched->gp_ready;
        else{
            proc->timer = (timer_t)proc->time_quant;
            new_queue = (proc_queue_t *)new_sched->gp_expired;
            need_resched = (bool_t)0;
        }
    }

    proc_insert( (proc_t *)proc, (proc_queue_t *)new_queue );
    return ((bool_t)need_resched);
}
//===========================================================
void proc_run( proc_t * proc ){
    enter_crit_sec();
    if( ( (proc_queue_t *)proc->queue ) || ( (flag_t)proc->flags & PROC_FLG_END ) ){
        // already running, or invalid call, also fools can not into running ended procrsses
        exit_crit_sec();
        return;
    }
    if((bool_t)_proc_run( proc ))resched_local();
    exit_crit_sec();
}
//===========================================================
void proc_run_from_isr( proc_t * proc ){
    register bool_t nested_isr = (bool_t)( (count_t)system_sched.nested_interrupts != 0 );
    if( (bool_t)nested_isr )enter_crit_sec();
    if( ( (proc_queue_t *)proc->queue ) || ( (flag_t)proc->flags & PROC_FLG_END ) ) goto end; // already running, or invalid call

    if((!((bool_t)nested_isr))&&((bool_t)_proc_run( (proc_t *)proc )))resched_local();
end:
    if( (bool_t)nested_isr )exit_crit_sec();
}
//===========================================================
void proc_run_no_resched( proc_t * proc ){
    enter_crit_sec();
    if( ( (proc_queue_t *)proc->queue ) || ( (flag_t)proc->flags & PROC_FLG_END ) ) goto end; // already running, or invalid call
    _proc_run( (proc_t *)proc );
end:
    exit_crit_sec();
}
//==============================================================
void proc_restart( proc_t * proc ){
    enter_crit_sec();
    if( (proc_queue_t *)proc->queue ){
        // already running, or invalid call
        exit_crit_sec();
        return;
    }
    stack_init( (proc_t *)proc );
    proc->timer = (timer_t)proc->time_quant;
    proc->prev = (proc_t *)proc;
    proc->next = (proc_t *)proc;
    proc->queue = (proc_queue_t *)0;
    proc->sched = (sched_t *)0;

    if((bool_t)_proc_run( (proc_t *)proc ))resched_local();
    exit_crit_sec();
}
//==============================================================
void proc_restart_from_isr( proc_t * proc ){
    register bool_t nested_isr = (bool_t)( (count_t)system_sched.nested_interrupts != 0 );
    if( (bool_t)nested_isr )enter_crit_sec();
    if( (proc_queue_t *)proc->queue ){
        // already running, or invalid call
        if( (bool_t)nested_isr )exit_crit_sec();
        return;
    }
    stack_init( (proc_t *)proc );
    proc->timer = (timer_t)proc->time_quant;
    proc->prev = (proc_t *)proc;
    proc->next = (proc_t *)proc;
    proc->queue = (proc_queue_t *)0;
    proc->sched = (sched_t *)0;

    if( ( !(bool_t)nested_isr )&&( (bool_t)_proc_run( (proc_t *)proc ) ) )resched_local();
    if( (bool_t)nested_isr )exit_crit_sec();
}
//==============================================================
void proc_restart_no_resched( proc_t * proc ){
    enter_crit_sec();
    if( (proc_queue_t *)proc->queue ){
        // already running, or invalid call
        exit_crit_sec();
        return;
    }
    stack_init( (proc_t *)proc );
    proc->timer = (timer_t)proc->time_quant;
    proc->prev = (proc_t *)proc;
    proc->next = (proc_t *)proc;
    proc->queue = (proc_queue_t *)0;
    proc->sched = (sched_t *)0;

    _proc_run( (proc_t *)proc );
    exit_crit_sec();
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
    proc->flags &= ~PROC_FLG_RUN;
    // end waiting process 2 avoid common resource corruption
    if( (flag_t)proc->flags & PROC_FLG_WAIT )proc->flags |= PROC_FLG_END;
    proc_cut( (proc_t *)proc );
}
//==============================================================
void proc_stop( proc_t * proc ){
    enter_crit_sec();
    if( (proc_queue_t *)proc->queue ){
        _proc_stop( (proc_t *)proc );
        resched_local();
        exit_crit_sec();
        return;
    }
    exit_crit_sec();
}
//==============================================================
void proc_stop_from_isr( proc_t * proc ){
    register bool_t nested_isr = (bool_t)( (count_t)system_sched.nested_interrupts != 0 );
    if( (bool_t)nested_isr )enter_crit_sec();
    if( (proc_queue_t *)proc->queue ){
        _proc_stop( (proc_t *)proc );
        if( (bool_t)nested_isr )exit_crit_sec();
        else resched_local();
        return;
    }
    if( (bool_t)nested_isr )exit_crit_sec();
}
//==============================================================
void proc_stop_no_resched( proc_t * proc ){
    enter_crit_sec();
    if( (proc_queue_t *)proc->queue ){
        _proc_stop( (proc_t *)proc );
    }
    exit_crit_sec();
}
//==============================================================
void proc_self_stop( void ){
    enter_crit_sec();
    register proc_t * proc = system_sched.current_proc;
    if( (proc_queue_t *)proc->queue ){
        _proc_stop( (proc_t *)proc );
        resched_local();
        exit_crit_sec();
        return;
    }
    exit_crit_sec();
}
//==============================================================
void proc_reset_watchdog( void ){
    enter_crit_sec();
    register proc_t * proc = (proc_t *)system_sched.current_proc;
    if( (proc_queue_t *)proc->queue ){
        if( (flag_t)proc->flags & PROC_FLG_RT )proc->timer = (timer_t)proc->time_quant;
    }
    exit_crit_sec();
}
