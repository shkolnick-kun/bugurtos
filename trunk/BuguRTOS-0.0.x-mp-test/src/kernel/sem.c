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
#include "../include/bugurt.h"
//==============================================================
void sem_init(sem_t * sem, lock_t value){
    sem->value = (lock_t)value;
#ifdef CONFIG_MP
    spin_init( &sem->rt_lock );
    spin_init( &sem->gp_lock );
#endif
    sem->gp_queue.index = (index_t)0;
    sem->rt_queue.index = (index_t)0;
    for(count_t i = 0; i < BITS_IN_INDEX_T; i++ ){
        sem->gp_queue.proc[i] = (proc_t *)0;
        sem->rt_queue.proc[i] = (proc_t *)0;
    }
}
//==============================================================
bool_t sem_try_lock(sem_t * sem){
    register sched_t * sched = _enter_crit_sec();
    register bool_t ret_val = _sem_try_lock( &sem->value );
    _exit_crit_sec( sched );
    return ret_val;
}
//==============================================================
bool_t sem_lock(sem_t * sem){
    register sched_t * sched = _enter_crit_sec();
    register proc_t * proc = sched->current_proc;
    register proc_queue_t * sem_queue;
    bool_t ret = (bool_t)1;
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif
    if( !_sem_try_lock( &sem->value ) ){
        _proc_stop( proc );
        // define the queue 2 insert proc in
        if( proc->flags & PROC_FLG_RT ){
            sem_queue = &sem->rt_queue;
#ifdef CONFIG_MP
            proc->queue_lock = &sem->rt_lock;
#endif
        }else{
            sem_queue = &sem->gp_queue;
#ifdef CONFIG_MP
            proc->queue_lock = &sem->gp_lock;
#endif
        }
        // insert proc 2 certain semaphore queue
#ifdef CONFIG_MP
        spin_lock( proc->queue_lock );
#endif
        proc_insert( proc, sem_queue );
#ifdef CONFIG_MP
        spin_unlock( proc->queue_lock );
#endif
        resched_local();
        proc->flags |= (flag_t)PROC_FLG_WAIT;
        ret = (bool_t)0;
    }
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
    _exit_crit_sec( sched );
    return (ret);
}
//==============================================================
void sem_unlock(sem_t * sem){
    register sched_t * sched = _enter_crit_sec();
    register proc_queue_t * sem_queue;
    register lock_t * sem_queue_lock;

    // find the queue 2 run process from
    if( sem->rt_queue.index ){
        sem_queue = &sem->rt_queue;
#ifdef CONFIG_MP
        sem_queue_lock = &sem->rt_lock;
#endif
    }else{
        if( sem->gp_queue.index ){
            sem_queue = &sem->gp_queue;
#ifdef CONFIG_MP
            sem_queue_lock = &sem->gp_lock;
#endif
        }else{
            goto end;
        }
    }
    // find the head of the queue
#ifdef CONFIG_MP
    spin_lock( sem_queue_lock );
#endif
    register proc_t * proc_2_run = proc_queue_head( sem_queue );
    // run the proc
#ifdef CONFIG_MP
    spin_unlock( sem_queue_lock );
    spin_lock( &proc_2_run->lock );
    spin_lock( sem_queue_lock );
#endif
    proc_fast_cut( proc_2_run );
#ifdef CONFIG_MP
    spin_unlock( sem_queue_lock );
#endif
    _proc_run( proc_2_run );
#ifdef CONFIG_MP
    register sched_t * proc_sched = proc_2_run->sched;
    spin_unlock( &proc_2_run->lock );
    if( proc_sched != sched ){
        resched_extern( proc_sched );
        goto end;
    }
#endif
    resched_local();
end:
    _sem_unlock( &sem->value );
    _exit_crit_sec( sched );
}
