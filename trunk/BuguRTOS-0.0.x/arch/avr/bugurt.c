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
#include "../../../osbme/osbme.h"
#include "../../include/bugurt.h"

#ifdef CONFIG_MP
#error "CONFIG_MP: BuguRTOS does not support multiprocessing 4 avr"
#endif

#ifdef MAX_PROCESSORS
#error "MAX_PROCESSORS: BuguRTOS does not support multiprocessing 4 avr"
#endif

#ifdef CONFIG_USE_ALB
#error "CONFIG_USE_ALB: BuguRTOS does not support multiprocessing 4 avr"
#endif

timer_t system_timer = 0, _system_timer = 0;
proc_t idle;
/************************************************************
*                platform dependent crap                    *
************************************************************/
void stack_init(proc_t * proc){
    proc->stack_pointer = osbme_init_stack( (void *)proc->stack_start, (osbme_code_t)proc_run_wrapper, (void *)proc );
}

bool_t _sem_try_lock(lock_t * lock){
    bool_t ret = 0;
    if(*lock){
        ret = 1;
        (*lock)--;
    }
    return (ret);
}

void _sem_unlock(lock_t * lock){
    (*lock)++;
}
static void * sp;
SYS_TMR_ISR_ATTR void SYSTEM_TIMER_ISR(void){
    sp = (stack_t *)osbme_store_context();
    system_sched.current_proc->stack_pointer = (stack_t *)sp;
    _system_timer++;
    // Don't use nested interrupts, they are ABSOLUTE evil.
    if( !(system_sched.nested_interrupts) )schedule( &system_sched );
    sp = (void *)system_sched.current_proc->stack_pointer;
    osbme_load_context( sp );
    reti();
}
RLOC_ISR_ATTR void RESCHED_LOCAL_ISR(void){
    sp = (stack_t *)osbme_store_context();
    system_sched.current_proc->stack_pointer = (stack_t *)sp;
    // Don't use nested interrupts, they are ABSOLUTE evil.
    if( !(system_sched.nested_interrupts) )resched( &system_sched );
    sp = (void *)system_sched.current_proc->stack_pointer;
    osbme_load_context( sp );
    reti();
}

/************************************************************
*                       4 general use                       *
************************************************************/
void init_bugurt(void){
    cli();

    idle.code = 0;
    idle.prio = (prio_t)(BITS_IN_INDEX_T - 1);
    idle.flags = 0;
    idle.timer = 1;
    idle.time_quant = 1;
    idle.prev = &idle;
    idle.next = &idle;
    idle.queue = (proc_queue_t *)0;
    idle.sched = &system_sched;

    scheduler_init( &system_sched, &idle );
    system_sched.nested_crit_sec = 1;
}
void start_bugurt(void){
    start_scheduler();
    exit_crit_sec();
}
//-----------------------------------------------------------
// slowpoke critical section wrapper
sched_t * _enter_crit_sec(void){
    cli();
    system_sched.nested_crit_sec++;
    return &system_sched;
}
void _enter_crit_sec_2(sched_t * sched){
    cli();
    sched->nested_crit_sec++;
}
void _exit_crit_sec(sched_t * sched){
    if( sched->nested_crit_sec )sched->nested_crit_sec--;
    if( !sched->nested_crit_sec )sei();
}
void enter_crit_sec(void){
    cli();
    system_sched.nested_crit_sec++;
    }
void exit_crit_sec(void){
    if( system_sched.nested_crit_sec )system_sched.nested_crit_sec--;
    if( !system_sched.nested_crit_sec )sei();
}
//-----------------------------------------------------------
void nested_isr_start(void){
    stop_scheduler();
    system_sched.nested_interrupts++;
    if( !system_sched.nested_crit_sec )sei();
}
void nested_isr_end(void){
    cli();
    system_sched.nested_interrupts--;
    start_scheduler();
}
//-----------------------------------------------------------
// needed in  soft timers
void update_system_timer(void){
    enter_crit_sec();
    system_timer = _system_timer;
    exit_crit_sec();
}
void wait_time(timer_t time){
    timer_t tmr;
    update_system_timer();
    CLEAR_TIMER(tmr);
    while( TIMER(tmr) < time )update_system_timer();
}
