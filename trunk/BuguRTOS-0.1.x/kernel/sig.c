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
#include "../include/bugurt.h"

void sig_init(sig_t * sig){
    sig->gp_queue.index = (index_t)0;
    sig->rt_queue.index = (index_t)0;
    for(count_t i = 0; i < BITS_IN_INDEX_T; i++ ){
        sig->gp_queue.proc[i] = (proc_t *)0;
        sig->rt_queue.proc[i] = (proc_t *)0;
    }
}
//==============================================================
void sig_wait(sig_t * sig){
    enter_crit_sec();
    register proc_t * proc = system_sched.current_proc;
    register proc_queue_t * sig_queue;
    _proc_stop( proc );
    // define the queue 2 insert proc in
    if( proc->flags & PROC_FLG_RT ){
        sig_queue = &sig->rt_queue;
    }else{
        sig_queue = &sig->gp_queue;
    }
    // insert proc 2 certain signal queue
    proc_insert( proc, sig_queue );
    proc->flags |= (flag_t)PROC_FLG_WAIT;
    exit_crit_sec();
    resched_local();
}
//==============================================================
void sig_signal(sig_t * sig){
    enter_crit_sec();
    register proc_t * proc;
    if( sig->rt_queue.index ){
        proc = proc_queue_head( &sig->rt_queue );
    }else{
        if( sig->gp_queue.index )proc = proc_queue_head( &sig->gp_queue );
        else goto end;
    }
    proc_cut( proc );
    bool_t need_resched = _proc_run( proc );
    exit_crit_sec();
    if(need_resched)resched_local();
    return;
end:
    exit_crit_sec();
}
//==============================================================
void sig_signal_from_isr(sig_t * sig){
    register bool_t nested_isr = ( system_sched.nested_interrupts != 0 );
    if( nested_isr )enter_crit_sec();
    register proc_t * proc;
    if( sig->rt_queue.index ){
        proc = proc_queue_head( &sig->rt_queue );
    }else{
        if( sig->gp_queue.index )proc = proc_queue_head( &sig->gp_queue );
        else goto end;
    }
    proc_cut( proc );
    _proc_run( proc );
end:
    if( nested_isr )exit_crit_sec();
}
//==============================================================
void sig_signal_no_resched(sig_t * sig){
    enter_crit_sec();
    register proc_t * proc;
    if( sig->rt_queue.index ){
        proc = proc_queue_head( &sig->rt_queue );
    }else{
        if( sig->gp_queue.index )proc = proc_queue_head( &sig->gp_queue );
        else goto end;
    }
    proc_cut( proc );
    _proc_run( proc );
end:
    exit_crit_sec();
}
//==============================================================
void sig_broadcast(sig_t * sig){
    enter_crit_sec();
    register proc_t * proc;
    register bool_t need_resched = (bool_t)0;
    while( sig->rt_queue.index ){
        proc = proc_queue_head( &sig->rt_queue );
        proc_cut( proc );
        need_resched |= _proc_run( proc );
    }
    while( sig->gp_queue.index ){
        proc = proc_queue_head( &sig->gp_queue );
        proc_cut( proc );
        need_resched |= _proc_run( proc );
    }
    exit_crit_sec();
    if(need_resched)resched_local();
}
//==============================================================
void sig_broadcast_from_isr(sig_t * sig){
    register bool_t nested_isr = ( system_sched.nested_interrupts != 0 );
    if( nested_isr )enter_crit_sec();
    register proc_t * proc;
    while( sig->rt_queue.index ){
        proc = proc_queue_head( &sig->rt_queue );
        proc_cut( proc );
        _proc_run( proc );
    }
    while( sig->gp_queue.index ){
        proc = proc_queue_head( &sig->gp_queue );
        proc_cut( proc );
        _proc_run( proc );
    }
    if( nested_isr )exit_crit_sec();
}
//==============================================================
void sig_broadcast_no_resched(sig_t * sig){
    enter_crit_sec();
    register proc_t * proc;
    while( sig->rt_queue.index ){
        proc = proc_queue_head( &sig->rt_queue );
        proc_cut( proc );
        _proc_run( proc );
    }
    while( sig->gp_queue.index ){
        proc = proc_queue_head( &sig->gp_queue );
        proc_cut( proc );
        _proc_run( proc );
    }
    exit_crit_sec();
}
