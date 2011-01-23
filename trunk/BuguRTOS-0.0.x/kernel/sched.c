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
#include"../include/bugurt.h"

#ifdef CONFIG_MP
// sched_array - 1 schedduler descriptor 4 1 processor
lock_t sched_index_lock;
affinity_t sched_index; // map 4 existing porcessors
sched_t sched_array[MAX_PROCESSORS];
/************************************************************
*       returns a poiter 2 the least loaded scheduler       *
************************************************************/
sched_t * load_balancer( proc_t * proc){
    register affinity_t mask = (affinity_t)1, test;
    load_t current_load,min_load;
    count_t i = (count_t)0,m;

    // find first active sched which can B used 2 run thic proc
    while( (affinity_t)mask ){
        spin_lock( (lock_t *)&sched_index_lock );
        test = (affinity_t)((affinity_t)mask & (affinity_t)sched_index & (affinity_t)proc->affinity);
        spin_unlock( (lock_t *)&sched_index_lock );
        if( (affinity_t)test )break;
        ((count_t)i)++;
        mask <<= (affinity_t)1;
    }

    register sched_t * current_sched = (sched_t *)sched_array + (count_t)i;

    spin_lock( (lock_t *)&current_sched->stat_lock );
    min_load = (load_t)load_calc( (sched_t *)current_sched );
    spin_unlock( (lock_t *)&current_sched->stat_lock );
    // switch 2 next sched
    m=((count_t)i)++;
    mask <<= (affinity_t)1;

    // try 2 find less loaded sched
    while( (affinity_t)mask ){
        spin_lock( (lock_t *)&sched_index_lock );
        test = (affinity_t)((affinity_t)mask & (affinity_t)sched_index & (affinity_t)proc->affinity);
        spin_unlock( (lock_t *)&sched_index_lock );
        if( (affinity_t)test ){

            current_sched = (sched_t *)sched_array + (count_t)i;

            // calculate load 4 current sched
            spin_lock( (lock_t *)&current_sched->stat_lock );
            current_load = (load_t)load_calc( (sched_t *)current_sched );
            spin_unlock( (lock_t *)&current_sched->stat_lock );

            // find a sched with minimal load
            if( (load_t)current_load < (load_t)min_load ){
                    min_load = (load_t)current_load;
                    m = (count_t)i;
            }

        }
        ((count_t)i)++;
        mask <<= (affinity_t)1;
    }
    return ( (sched_t *)sched_array + (count_t)m );
}
#else
sched_t system_sched;
#endif

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
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&current_proc->lock );
#endif
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
#ifdef CONFIG_MP
        spin_lock( (lock_t *)&sched->rt_lock );
#endif
        // switch rt_ready 2 next proc with current prio
        register prio_t prio = (prio_t)current_proc->prio;
        register proc_queue_t * rt_ready = (proc_queue_t *)&sched->rt_ready;
        rt_ready->proc[(prio_t)prio] = (proc_t *)rt_ready->proc[(prio_t)prio]->next;

        //if the process has some time 2 run, rt_ready is guaranteed 2 have head process
        if( (timer_t)current_proc->timer ) goto rt_head_schedule;

        // the process has expired its time, watchdog was not reset.
        proc_cut( (proc_t *)current_proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sched->rt_lock );
#endif
        current_proc->flags &= ~PROC_FLG_RUN;
#ifdef CONFIG_MP
        // update stats
        spin_lock( (lock_t *)&sched->stat_lock );
        ((count_t)sched->proc_count_rt)--;
        sched->total_rt_quant -= (timer_t)current_proc->time_quant;
        spin_unlock( (lock_t *)&sched->stat_lock );
#endif
    }
    // if rt_ready is not empty, then schedule its head
    if( (index_t)sched->rt_ready.index ){
#ifdef CONFIG_MP
        goto rt_head_schedule_with_lock;
#else
        goto rt_head_schedule;
#endif
    }
    // else schedule gp_proc 4 execution. (at least we have idle proc 2 run)
/*********************************************
*    general purpose scheduling sequence     *
*********************************************/
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&current_proc->lock );
#endif
    // let's look at the last scheduled general purpose process
    current_proc = (proc_t *)sched->current_gp_proc;
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&current_proc->lock );
#endif
    if( (proc_queue_t *)current_proc->queue == (proc_queue_t *)sched->gp_ready ){
#ifdef CONFIG_MP
        spin_lock( (lock_t *)&sched->gp_lock );
#endif
        // switch gp_ready 2 next proc with current prio
        register prio_t prio = (prio_t)current_proc->prio;
        register proc_queue_t * gp_ready = (proc_queue_t *)sched->gp_ready;
        gp_ready->proc[(prio_t)prio] = (proc_t *)gp_ready->proc[(prio_t)prio]->next;

        // check 4 timer 2 expire
        if( (timer_t)current_proc->timer ){
#ifdef CONFIG_MP
            spin_unlock( (lock_t *)&sched->gp_lock );
#endif
            goto gp_test;
        }else{

            // reset process timer
            current_proc->timer = (timer_t)current_proc->time_quant;
#if defined(CONFIG_MP) && defined(CONFIG_USE_ALB)
            //cut proc
            proc_fast_cut((proc_t *)current_proc);
            // 2 avoid mutual different scheduler locks
            spin_unlock( (lock_t *)&sched->gp_lock );
            //NOTE: now we can unlock current_proc_lock

            // update stats
            spin_lock( (lock_t *)&sched->stat_lock );
            ((count_t)sched->proc_count_gp)--;
            sched->total_gp_quant -= (timer_t)current_proc->time_quant;
            spin_unlock( (lock_t *)&sched->stat_lock );


            /*
                New sched search, switch 2 it and it's stats update must be done atomicaly,
             2 avoid non optimal load balancing.
            */

            // find most free sched
            register sched_t * new_sched = (sched_t *)load_balancer( (proc_t *)current_proc );

            // switch 2 new sched
            current_proc->sched = (sched_t *)new_sched;
            current_proc->queue_lock = (lock_t *)&new_sched->gp_lock;

            // update stats
            spin_lock( (lock_t *)&new_sched->stat_lock );
            ((count_t)new_sched->proc_count_gp)++;
            new_sched->total_gp_quant += (timer_t)current_proc->time_quant;
            spin_unlock( (lock_t *)&new_sched->stat_lock );

            // now insert proc 2 new_sched->gp_expired
            spin_lock( (lock_t *)&new_sched->gp_lock );
            proc_insert( (proc_t *)current_proc, (proc_queue_t *)new_sched->gp_expired );
            spin_unlock( (lock_t *)&new_sched->gp_lock );
            // now we can unlock current_proc->lock, go to gp_test;
#else
            // move the process 2 gp_expired
            proc_move( (proc_t *)current_proc, (proc_queue_t *)sched->gp_expired );
#ifdef CONFIG_MP
            spin_unlock( (lock_t *)&sched->gp_lock );
#endif
#endif
        }
    }
gp_test:
#ifdef CONFIG_MP
    // we don't need this proc any moar, and we CAN unlock it, so:
    spin_unlock( (lock_t *)&current_proc->lock );
    // now we can lock gp_lock
    spin_lock( (lock_t *)&sched->gp_lock );
#endif
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
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&sched->gp_lock );
#endif
    return;
/**********************************************
* scedule rt_ready head 4 execution and exit  *
**********************************************/

#ifdef CONFIG_MP
rt_head_schedule_with_lock:
    spin_lock( (lock_t *)&sched->rt_lock );
#endif
rt_head_schedule:
    sched->current_proc = (proc_t *)proc_queue_head( &sched->rt_ready );
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&sched->rt_lock );
    spin_unlock( (lock_t *)&current_proc->lock );
#endif
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
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&sched->rt_lock );
#endif
    if( (index_t)sched->rt_ready.index ){
        sched->current_proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sched->rt_ready );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sched->rt_lock );
#endif
    }else{
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sched->rt_lock );
        spin_lock( (lock_t *)&sched->gp_lock );
#endif
        // scedule the head of gp_ready 4 execution
        sched->current_proc = (proc_t *)proc_queue_head( (proc_queue_t *)sched->gp_ready );
        // remember current_gp_proc 4 next time general purpose scheduling sequence
        sched->current_gp_proc = (proc_t *)sched->current_proc;
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sched->gp_lock );
#endif
    }
}

/************************************************************
*             Scheduler initialization routine              *
************************************************************/
void scheduler_init( sched_t * sched, proc_t * idle ){
    count_t i;
#ifdef CONFIG_MP
    spin_init( (lock_t *)&sched->rt_lock );
    spin_init( (lock_t *)&sched->gp_lock );
    spin_init( (lock_t *)&sched->stat_lock );
#endif
    sched->current_proc = (proc_t *)idle;
    sched->current_gp_proc = (proc_t *)idle;
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&sched->rt_lock );
#endif
    sched->rt_ready.index = (index_t)0;
    for( i = (count_t)0; i < (count_t)BITS_IN_INDEX_T; ((count_t)i)++ ){
        sched->rt_ready.proc[i] = (proc_t *)0;
    }
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&sched->rt_lock );
    spin_lock( (lock_t *)&sched->gp_lock );
#endif
    sched->gp_ready = (proc_queue_t *)&sched->gp_queues[0];
    sched->gp_expired = (proc_queue_t *)&sched->gp_queues[1];
    sched->gp_ready->index = (index_t)0;
    sched->gp_expired->index = (index_t)0;

    for( i = (count_t)0; (count_t)i < (count_t)BITS_IN_INDEX_T; ((count_t)i)++ ){
        sched->gp_queues[0].proc[i] = (proc_t *)0;
        sched->gp_queues[1].proc[i] = (proc_t *)0;
    }

#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&sched->gp_lock );

    spin_lock( (lock_t *)&idle->lock );
    spin_lock( (lock_t *)&sched->stat_lock );

    sched->total_gp_quant = (timer_t)idle->time_quant;;
    sched->total_rt_quant = (timer_t)0;
    sched->proc_count_rt = (count_t)0;
    sched->proc_count_gp = (count_t)1;

    spin_unlock( (lock_t *)&sched->stat_lock );

    // schedule idle proc
    spin_lock( (lock_t *)&sched->gp_lock );
#endif
    proc_insert((proc_t *)idle, (proc_queue_t *)sched->gp_ready);
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&sched->gp_lock );
    spin_unlock( (lock_t *)&idle->lock );
#endif
    // critical section nest count
    sched->nested_crit_sec = (count_t)0;
    // ISR nest count
    sched->nested_interrupts = (count_t)0;
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&sched_index_lock );
    sched_index |= ((affinity_t)1)<<(count_t)((sched_t *)sched - (sched_t *)sched_array);
    spin_unlock( (lock_t *)&sched_index_lock );
#endif
}
