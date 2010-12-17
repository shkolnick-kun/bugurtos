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

void sig_init(sig_t * sig){
#ifdef CONFIG_MP
    spin_init( &sig->rt_lock );
    spin_init( &sig->gp_lock );
#endif
    sig->gp_queue.index = (index_t)0;
    sig->rt_queue.index = (index_t)0;
    for(count_t i = 0; i < BITS_IN_INDEX_T; i++ ){
        sig->gp_queue.proc[i] = (proc_t *)0;
        sig->rt_queue.proc[i] = (proc_t *)0;
    }
}
//==============================================================
void sig_wait(sig_t * sig){
    register sched_t * sched = _enter_crit_sec();
    register proc_t * proc = sched->current_proc;
    register proc_queue_t * sig_queue;
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
#endif
    _proc_stop( proc );
    // define the queue 2 insert proc in
    if( proc->flags & PROC_FLG_RT ){
        sig_queue = &sig->rt_queue;
#ifdef CONFIG_MP
        proc->queue_lock = &sig->rt_lock;
#endif
    }else{
        sig_queue = &sig->gp_queue;
#ifdef CONFIG_MP
        proc->queue_lock = &sig->gp_lock;
#endif
    }
    // insert proc 2 certain signal queue
#ifdef CONFIG_MP
    spin_lock( proc->queue_lock );
#endif
    proc_insert( proc, sig_queue );
#ifdef CONFIG_MP
    spin_unlock( proc->queue_lock );
#endif
    proc->flags |= (flag_t)PROC_FLG_WAIT;
    resched_local();
    _exit_crit_sec( sched );
#ifdef CONFIG_MP
    spin_unlock( &proc->lock );
#endif
}
//==============================================================
void sig_signal(sig_t * sig){
    register sched_t * sched = _enter_crit_sec();
    register proc_t * proc;
#ifdef CONFIG_MP
    register sched_t * proc_sched;
    spin_lock(&sig->rt_lock);
#endif
    if( sig->rt_queue.index ){
        proc = proc_queue_head( &sig->rt_queue );
#ifdef CONFIG_MP
        spin_unlock(&sig->rt_lock);
#endif
    }else{
#ifdef CONFIG_MP
        spin_unlock(&sig->rt_lock);
        spin_lock(&sig->gp_lock);
#endif
        if( sig->gp_queue.index ){
            proc = proc_queue_head( &sig->gp_queue );
#ifdef CONFIG_MP
            spin_unlock(&sig->gp_lock);
#endif
        }else{
#ifdef CONFIG_MP
            spin_unlock(&sig->gp_lock);
#endif
            goto end;
        }
    }
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
    spin_lock( proc->queue_lock );
#endif
    proc_cut( proc );
#ifdef CONFIG_MP
    spin_unlock( proc->queue_lock );
#endif
    _proc_run( proc );
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
end:
    _exit_crit_sec( sched );
}
//==============================================================
void sig_signal_no_resched(sig_t * sig){
    register sched_t * sched = _enter_crit_sec();
    register proc_t * proc;
#ifdef CONFIG_MP
    register sched_t * proc_sched;
    spin_lock(&sig->rt_lock);
#endif
    if( sig->rt_queue.index ){
        proc = proc_queue_head( &sig->rt_queue );
#ifdef CONFIG_MP
        spin_unlock(&sig->rt_lock);
#endif
    }else{
#ifdef CONFIG_MP
        spin_unlock(&sig->rt_lock);
        spin_lock(&sig->gp_lock);
#endif
        if( sig->gp_queue.index ){
            proc = proc_queue_head( &sig->gp_queue );
#ifdef CONFIG_MP
            spin_unlock(&sig->gp_lock);
#endif
        }else{
#ifdef CONFIG_MP
            spin_unlock(&sig->gp_lock);
#endif
            goto end;
        }
    }
#ifdef CONFIG_MP
    spin_lock( &proc->lock );
    spin_lock( proc->queue_lock );
#endif
    proc_cut( proc );
#ifdef CONFIG_MP
    spin_unlock( proc->queue_lock );
#endif
    _proc_run( proc );
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
end:
    _exit_crit_sec( sched );
}
//==============================================================
void sig_broadcast(sig_t * sig){
    register sched_t * sched = _enter_crit_sec();
    register proc_t * proc;
    register bool_t need_reched = (bool_t)0;
#ifdef CONFIG_MP
        spin_lock(&sig->rt_lock);
#endif
    while( sig->rt_queue.index ){
        proc = proc_queue_head( &sig->rt_queue );
#ifdef CONFIG_MP
        spin_unlock( &sig->rt_lock );
        spin_lock( &proc->lock );
        spin_lock( proc->queue_lock );
#endif
        proc_cut( proc );
#ifdef CONFIG_MP
        spin_unlock( proc->queue_lock );
#endif
        need_reched |= _proc_run( proc );
#ifdef CONFIG_MP
        spin_unlock( &proc->lock );
        spin_lock(&sig->rt_lock);
#endif
    }
#ifdef CONFIG_MP
        spin_unlock(&sig->rt_lock);
        spin_lock(&sig->gp_lock);
#endif
    while( sig->gp_queue.index ){
        proc = proc_queue_head( &sig->gp_queue );
#ifdef CONFIG_MP
        spin_unlock( &sig->gp_lock );
        spin_lock( &proc->lock );
        spin_lock( proc->queue_lock );
#endif
        proc_cut( proc );
#ifdef CONFIG_MP
        spin_unlock( proc->queue_lock );
#endif
        need_reched |= _proc_run( proc );
#ifdef CONFIG_MP
        spin_unlock( &proc->lock );
        spin_lock(&sig->gp_lock);
#endif
    }
#ifdef CONFIG_MP
        spin_unlock(&sig->gp_lock);
#endif
    if(need_reched)resched_system();
    _exit_crit_sec( sched );
}
//==============================================================
void sig_broadcast_no_resched(sig_t * sig){
    register sched_t * sched = _enter_crit_sec();
    register proc_t * proc;
#ifdef CONFIG_MP
        spin_lock(&sig->rt_lock);
#endif
    while( sig->rt_queue.index ){
        proc = proc_queue_head( &sig->rt_queue );
#ifdef CONFIG_MP
        spin_unlock( &sig->rt_lock );
        spin_lock( &proc->lock );
        spin_lock( proc->queue_lock );
#endif
        proc_cut( proc );
#ifdef CONFIG_MP
        spin_unlock( proc->queue_lock );
#endif
        _proc_run( proc );
#ifdef CONFIG_MP
        spin_unlock( &proc->lock );
        spin_lock(&sig->rt_lock);
#endif
    }
#ifdef CONFIG_MP
        spin_unlock(&sig->rt_lock);
        spin_lock(&sig->gp_lock);
#endif
    while( sig->gp_queue.index ){
        proc = proc_queue_head( &sig->gp_queue );
#ifdef CONFIG_MP
        spin_unlock( &sig->gp_lock );
        spin_lock( &proc->lock );
        spin_lock( proc->queue_lock );
#endif
        proc_cut( proc );
#ifdef CONFIG_MP
        spin_unlock( proc->queue_lock );
#endif
        _proc_run( proc );
#ifdef CONFIG_MP
        spin_unlock( &proc->lock );
        spin_lock(&sig->gp_lock);
#endif
    }
#ifdef CONFIG_MP
        spin_unlock(&sig->gp_lock);
#endif
    _exit_crit_sec( sched );
}
