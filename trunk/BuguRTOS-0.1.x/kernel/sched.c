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
#include"../include/bugurt.h"

sched_t system_sched;
proc_t idle;

/************************************************************
*                                                           *
*                   SCHEDULER ROUTINE                       *
*                                                           *
*                    4 internal use                         *
*                                                           *
*************************************************************
*                                                           *
*                       CAUTION !!!                         *
*             call this in critical section !!!             *
*                                                           *
************************************************************/
void schedule( sched_t * sched ){
    register proc_t * current_proc = (proc_t *)sched->current_proc;
    // when we use semaphores and signals there may be a situation when current_proc->timer==0 in this case we must analyse
    // PROC_FGL_RT or we can do current_proc->timer-- only when it's nonzero
    if((timer_t)current_proc->timer)((timer_t)current_proc->timer)--;
/*********************************************
*      real time scheduling sequence         *
*********************************************/
/*
I don't think, that flags use would always result in beter performance:
 If we use PROC_FLG_RT, then we must:
  1) load current_proc->flags;
  3) do & PROC_FLG_RT;
  4) compare the result with 0;
  5) branch if not equal;

  6) also, in this case we must check
    (rt_ready->proc[(prio_t)current_proc->prio]==0)
    or
    (rt_ready->index & ((index_t)1<<(prio_t)current_proc->prio))
    2 avoid null pointer derefference,
    so this will B slower anyway.

 If we use current_proc->queue then we only have 2:
  1) load current_proc->queue
  2) load &sched->rt_ready
  3) compare two values
  4) branch if equal.
*/
    if( (proc_queue_t *)current_proc->queue == (proc_queue_t *)&sched->rt_ready ){
        // switch rt_ready 2 next proc with current prio
        register prio_t prio = (prio_t)current_proc->prio;
        register proc_queue_t * rt_ready = (proc_queue_t *)&sched->rt_ready;
        rt_ready->proc[(prio_t)prio] = (proc_t *)rt_ready->proc[(prio_t)prio]->next;

        //if the process has some time 2 run, rt_ready is guaranteed 2 have head process
        if( (timer_t)current_proc->timer ) goto rt_head_schedule;

        // the process has expired its time, watchdog was not reset.
        proc_cut( (proc_t *)current_proc );
        current_proc->flags &= ~PROC_FLG_RUN;
    }
    // if rt_ready is not empty, then schedule its head
    if( (index_t)sched->rt_ready.index ) goto rt_head_schedule;
    // else schedule gp_proc 4 execution. (at least we have idle proc 2 run)
/*********************************************
*    general purpose scheduling sequence     *
*********************************************/
    // let's look at the last scheduled general purpose process
    current_proc = (proc_t *)sched->current_gp_proc;
    if( (proc_queue_t *)current_proc->queue == (proc_queue_t *)sched->gp_ready ){
        // switch gp_ready 2 next proc with current prio
        register prio_t prio = (prio_t)current_proc->prio;
        register proc_queue_t * gp_ready = (proc_queue_t *)sched->gp_ready;
        gp_ready->proc[(prio_t)prio] = (proc_t *)gp_ready->proc[(prio_t)prio]->next;

        // check 4 timer 2 expire
        if( (timer_t)current_proc->timer ){
            goto gp_test;
        }else{
            // reset process timer
            current_proc->timer = (timer_t)current_proc->time_quant;
            // move the process 2 gp_expired
            proc_move( (proc_t *)current_proc, (proc_queue_t *)sched->gp_expired );
        }
    }
gp_test:
    //gp_test:
    // gp_ready is empty, swap ready and expired queues
    if( !((index_t)sched->gp_ready->index) ){
        register proc_queue_t * expired = (proc_queue_t *)sched->gp_expired;
        sched->gp_expired = (proc_queue_t *)sched->gp_ready;
        sched->gp_ready = (proc_queue_t *)expired;
    }
    // scedule the head of the gp_ready 4 execution
    sched->current_proc = (proc_t *)proc_queue_head( (proc_queue_t *)sched->gp_ready );
    // remember current_gp_proc 4 next time general purpose scheduling sequence
    sched->current_gp_proc = (proc_t *)sched->current_proc;
    return;
/**********************************************
* scedule rt_ready head 4 execution and exit  *
**********************************************/
rt_head_schedule:
    sched->current_proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sched->rt_ready );
}

/************************************************************
*                                                           *
*                  RESCHEDULER ROUTINE                      *
*                                                           *
*                    4 internal use                         *
*                                                           *
*************************************************************
*                                                           *
*                       CAUTION !!!                         *
*             call this in critical section !!!             *
*                                                           *
************************************************************/
void resched( sched_t * sched ){
    if( (index_t)sched->rt_ready.index ){
        sched->current_proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sched->rt_ready );
    }else{
        // scedule the head of gp_ready 4 execution
        sched->current_proc = (proc_t *)proc_queue_head( (proc_queue_t *)sched->gp_ready );
        // remember current_gp_proc 4 next time general purpose scheduling sequence
        sched->current_gp_proc = (proc_t *)sched->current_proc;
    }
}

/************************************************************
*             Scheduler initialization routine              *
************************************************************/
void scheduler_init( sched_t * sched, proc_t * idle ){
    count_t i;

    sched->rt_ready.index = (index_t)0;
    for(i = 0; i < BITS_IN_INDEX_T; i++ ){
        sched->rt_ready.proc[i] = (proc_t *)0;
    }

    sched->gp_ready = &sched->gp_queues[0];
    sched->gp_expired = &sched->gp_queues[1];
    sched->gp_ready->index = (index_t)0;
    sched->gp_expired->index = (index_t)0;

    for(i = 0; i < BITS_IN_INDEX_T; i++ ){
        sched->gp_queues[0].proc[i] = (proc_t *)0;
        sched->gp_queues[1].proc[i] = (proc_t *)0;
    }

    idle->code = (code_t)0;
    idle->prio = (prio_t)(BITS_IN_INDEX_T - 1);
    idle->flags = (flag_t)0;
    idle->timer = (timer_t)1;
    idle->time_quant = (timer_t)1;
    idle->prev = (proc_t *)idle;
    idle->next = (proc_t *)idle;
    idle->queue = (proc_queue_t *)0;
    idle->sched = (sched_t *)sched;

    sched->current_proc = (proc_t *)idle;
    sched->current_gp_proc = (proc_t *)idle;

    proc_insert((proc_t *)idle, (proc_queue_t *)sched->gp_ready);

    // critical section nest count
    sched->nested_crit_sec = (count_t)0;
    // ISR nest count
    sched->nested_interrupts = (count_t)0;

}
