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
    spin_init( (lock_t *)&sig->rt_lock );
    spin_init( (lock_t *)&sig->gp_lock );
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
    register sched_t * sched = (sched_t *)_enter_crit_sec();
    register proc_t * proc = (proc_t *)sched->current_proc;
    register proc_queue_t * sig_queue;
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
#endif
    _proc_stop( (proc_t *)proc );
    // define the queue 2 insert proc in
    if( (flag_t)proc->flags & PROC_FLG_RT ){
        sig_queue = (proc_queue_t *)&sig->rt_queue;
#ifdef CONFIG_MP
        proc->queue_lock = (lock_t *)&sig->rt_lock;
#endif
    }else{
        sig_queue = (proc_queue_t *)&sig->gp_queue;
#ifdef CONFIG_MP
        proc->queue_lock = (lock_t *)&sig->gp_lock;
#endif
    }
    // insert proc 2 certain signal queue
#ifdef CONFIG_MP
    spin_lock( (lock_t *)proc->queue_lock );
#endif
    proc_insert( (proc_t *)proc, (proc_queue_t *)sig_queue );
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)proc->queue_lock );
#endif
    proc->flags |= PROC_FLG_WAIT;
    resched_local();
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&proc->lock );
#endif
    _exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void sig_signal(sig_t * sig){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
    register proc_t * proc;
#ifdef CONFIG_MP
    register sched_t * proc_sched;
    spin_lock( (lock_t *)&sig->rt_lock );
#endif
    if( (index_t)sig->rt_queue.index ){
        proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->rt_queue );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
#endif
    }else{
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
        spin_lock( (lock_t *)&sig->gp_lock );
#endif
        if( (index_t)sig->gp_queue.index ){
            proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->gp_queue );
#ifdef CONFIG_MP
            spin_unlock( (lock_t *)&sig->gp_lock );
#endif
        }else{
#ifdef CONFIG_MP
            spin_unlock( (lock_t *)&sig->gp_lock );
#endif
            goto end;
        }
    }
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
    spin_lock( (lock_t *)proc->queue_lock );
#endif
    proc_cut( (proc_t *)proc );
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)proc->queue_lock );
    bool_t need_resched = (bool_t)_proc_run( (proc_t *)proc );
    proc_sched = (sched_t *)proc->sched;
    spin_unlock( (lock_t *)&proc->lock );
    if( (bool_t)need_resched ){
        if( (sched_t *)proc_sched != (sched_t *)sched ){
            //now we can resched
            resched_extern( (sched_t *)proc_sched );
            _exit_crit_sec( (sched_t *)sched );
            return;
        }
        resched_local();
    }
#else
    if( (bool_t)_proc_run( (proc_t *)proc ) )resched_local();
#endif
end:
    _exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void sig_signal_from_isr(sig_t * sig){
    register sched_t * sched = (sched_t *)current_sched();
    register bool_t nested_isr = (bool_t)((count_t)sched->nested_interrupts != (count_t)0);//true if interrupts R enabled on a local processor
    register proc_t * proc;
    if( (bool_t)nested_isr )_enter_crit_sec_2( (sched_t *)sched );
#ifdef CONFIG_MP
    register sched_t * proc_sched;
    spin_lock( (lock_t *)&sig->rt_lock );
#endif
    if( (index_t)sig->rt_queue.index ){
        proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->rt_queue );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
#endif
    }else{
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
        spin_lock( (lock_t *)&sig->gp_lock );
#endif
        if( (index_t)sig->gp_queue.index ){
            proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->gp_queue );
#ifdef CONFIG_MP
            spin_unlock( (lock_t *)&sig->gp_lock );
#endif
        }else{
#ifdef CONFIG_MP
            spin_unlock( (lock_t *)&sig->gp_lock );
#endif
            goto end;
        }
    }
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
    spin_lock( (lock_t *)proc->queue_lock );
#endif
    proc_cut( (proc_t *)proc );
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)proc->queue_lock );
    bool_t need_resched = (bool_t)_proc_run( (proc_t *)proc );
    proc_sched = (sched_t *)proc->sched;
    spin_unlock( (lock_t *)&proc->lock );
    if( (bool_t)need_resched ){
        if( (sched_t *)proc_sched != (sched_t *)sched ){
            //now we can resched
            resched_extern( (sched_t *)proc_sched );
            _exit_crit_sec( (sched_t *)sched );
            return;
        }
        if(!((bool_t)nested_isr))resched_local();
    }
#else
    if( ( !((bool_t)nested_isr) )&&( (bool_t)_proc_run( (proc_t *)proc ) ) )resched_local();
#endif
end:
    if( (bool_t)nested_isr )_exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void sig_signal_no_resched(sig_t * sig){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
    register proc_t * proc;
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&sig->rt_lock );
#endif
    if( (index_t)sig->rt_queue.index ){
        proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->rt_queue );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
#endif
    }else{
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
        spin_lock( (lock_t *)&sig->gp_lock );
#endif
        if( (index_t)sig->gp_queue.index ){
            proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->gp_queue );
#ifdef CONFIG_MP
            spin_unlock( (lock_t *)&sig->gp_lock );
#endif
        }else{
#ifdef CONFIG_MP
            spin_unlock( (lock_t *)&sig->gp_lock );
#endif
            goto end;
        }
    }
#ifdef CONFIG_MP
    spin_lock( (lock_t *)&proc->lock );
    spin_lock( (lock_t *)proc->queue_lock );
#endif
    proc_cut( (proc_t *)proc );
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)proc->queue_lock );
#endif
    _proc_run( (proc_t *)proc );
#ifdef CONFIG_MP
    spin_unlock( (lock_t *)&proc->lock );
#endif
end:
    _exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void sig_broadcast(sig_t * sig){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
    register proc_t * proc;
    register bool_t need_resched = (bool_t)0;
#ifdef CONFIG_MP
        spin_lock( (lock_t *)&sig->rt_lock );
#endif
    while( (index_t)sig->rt_queue.index ){
        proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->rt_queue );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
        spin_lock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)proc->queue_lock );
#endif
        proc_cut( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)proc->queue_lock );
#endif
        need_resched |= (bool_t)_proc_run( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)&sig->rt_lock );
#endif
    }
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
        spin_lock( (lock_t *)&sig->gp_lock );
#endif
    while( (index_t)sig->gp_queue.index ){
        proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->gp_queue );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->gp_lock );
        spin_lock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)proc->queue_lock );
#endif
        proc_cut( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)proc->queue_lock );
#endif
        need_resched |= (bool_t)_proc_run( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)&sig->gp_lock );
#endif
    }
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->gp_lock );
#endif
    if((bool_t)need_resched)resched_system();
    _exit_crit_sec( (sched_t *)sched );
}
//==============================================================
void sig_broadcast_from_isr(sig_t * sig){
    register sched_t * sched = (sched_t *)current_sched();
    register bool_t nested_isr = (bool_t)((count_t)sched->nested_interrupts != (count_t)0);//true if interrupts R enabled on a local processor
    register bool_t need_resched = (bool_t)0;
    register proc_t * proc;
    if( (bool_t)nested_isr )_enter_crit_sec_2( (sched_t *)sched );
#ifdef CONFIG_MP
        spin_lock( (lock_t *)&sig->rt_lock);
#endif
    while( (index_t)sig->rt_queue.index ){
        proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->rt_queue );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
        spin_lock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)proc->queue_lock );
#endif
        proc_cut( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)proc->queue_lock );
#endif
        need_resched |= (bool_t)_proc_run( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)&sig->rt_lock );
#endif
    }
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
        spin_lock( (lock_t *)&sig->gp_lock );
#endif
    while( (index_t)sig->gp_queue.index ){
        proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->gp_queue );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->gp_lock );
        spin_lock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)proc->queue_lock );
#endif
        proc_cut( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)proc->queue_lock );
#endif
        need_resched |= (bool_t)_proc_run( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)&sig->gp_lock );
#endif
    }
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->gp_lock );
#endif

    if( (bool_t)nested_isr )_exit_crit_sec( (sched_t *)sched );
    else if( (bool_t)need_resched )resched_system();
}
//==============================================================
void sig_broadcast_no_resched(sig_t * sig){
    register sched_t * sched = (sched_t *)_enter_crit_sec();
    register proc_t * proc;
#ifdef CONFIG_MP
        spin_lock( (lock_t *)&sig->rt_lock );
#endif
    while( (index_t)sig->rt_queue.index ){
        proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->rt_queue );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
        spin_lock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)proc->queue_lock );
#endif
        proc_cut( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)proc->queue_lock );
#endif
        _proc_run( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)&sig->rt_lock );
#endif
    }
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->rt_lock );
        spin_lock( (lock_t *)&sig->gp_lock );
#endif
    while( (index_t)sig->gp_queue.index ){
        proc = (proc_t *)proc_queue_head( (proc_queue_t *)&sig->gp_queue );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->gp_lock );
        spin_lock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)proc->queue_lock );
#endif
        proc_cut( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)proc->queue_lock );
#endif
        _proc_run( (proc_t *)proc );
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&proc->lock );
        spin_lock( (lock_t *)&sig->gp_lock);
#endif
    }
#ifdef CONFIG_MP
        spin_unlock( (lock_t *)&sig->gp_lock);
#endif
    _exit_crit_sec( (sched_t *)sched );
}
