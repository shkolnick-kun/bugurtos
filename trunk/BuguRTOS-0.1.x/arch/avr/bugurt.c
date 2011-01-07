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

#include "../../include/bugurt.h"

timer_t system_timer = 0;
/************************************************************
*                platform dependent crap                    *
************************************************************/
void stack_init(proc_t * proc){
    stack_t * top_of_stack = proc->stack_start;

    *top_of_stack-- = (stack_t)0x11;
    *top_of_stack-- = (stack_t)0x22;
    *top_of_stack-- = (stack_t)0x33;

    // return address
    unsigned short code = (unsigned short)proc_run_wrapper;
    //unsigned short code = (unsigned short)proc->code;
    *top_of_stack-- = (stack_t)(code&(unsigned short)0x00ff);
    code>>=8;
    *top_of_stack-- = (stack_t)(code&(unsigned short)0x00ff);

    // registers
    *top_of_stack-- = (stack_t)0x00;
    *top_of_stack-- = (stack_t)0x80;// SREG: enable interrupts
    *top_of_stack-- = (stack_t)0x00;// r1 must B 0
    *top_of_stack-- = (stack_t)0x02;
    *top_of_stack-- = (stack_t)0x03;
    *top_of_stack-- = (stack_t)0x04;
    *top_of_stack-- = (stack_t)0x05;
    *top_of_stack-- = (stack_t)0x06;
    *top_of_stack-- = (stack_t)0x07;
    *top_of_stack-- = (stack_t)0x08;
    *top_of_stack-- = (stack_t)0x09;
    *top_of_stack-- = (stack_t)0x10;
    *top_of_stack-- = (stack_t)0x11;
    *top_of_stack-- = (stack_t)0x12;
    *top_of_stack-- = (stack_t)0x13;
    *top_of_stack-- = (stack_t)0x14;
    *top_of_stack-- = (stack_t)0x15;
    *top_of_stack-- = (stack_t)0x16;
    *top_of_stack-- = (stack_t)0x17;
    *top_of_stack-- = (stack_t)0x18;
    *top_of_stack-- = (stack_t)0x19;
    *top_of_stack-- = (stack_t)0x20;
    *top_of_stack-- = (stack_t)0x21;
    *top_of_stack-- = (stack_t)0x22;
    *top_of_stack-- = (stack_t)0x23;

    // proc must B loaded as an argument 2 proc_run_wrapper

    code = (unsigned short)proc;
    *top_of_stack-- = (stack_t)(code&(unsigned short)0x00ff); // r24 LSByte of proc
    code>>=8;
    *top_of_stack-- = (stack_t)(code&(unsigned short)0x00ff); // r25 MSByte of proc

    //*top_of_stack-- = (stack_t)0x24;
    //*top_of_stack-- = (stack_t)0x25;
    *top_of_stack-- = (stack_t)0x26;
    *top_of_stack-- = (stack_t)0x27;
    *top_of_stack-- = (stack_t)0x28;
    *top_of_stack-- = (stack_t)0x29;
    *top_of_stack-- = (stack_t)0x30;
    *top_of_stack-- = (stack_t)0x31;
#ifdef RAMPZ
    *top_of_stack-- = (stack_t)0xff;
#endif
    proc->stack_pointer = top_of_stack;
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

stack_t * system_timer_handler( stack_t * old_sp ){
    system_sched.current_proc->stack_pointer = old_sp;

    system_timer++;

    // Don't use nested interrupts, they are ABSOLUTE evil.
    if( !(system_sched.nested_interrupts) )schedule( &system_sched );

    return system_sched.current_proc->stack_pointer;
}

// resched tasks on the processor, and switch context if needed
stack_t * resched_local_context_switch( stack_t * old_sp ){
    system_sched.current_proc->stack_pointer = old_sp;

    if( !(system_sched.nested_crit_sec) )resched( &system_sched );

    return system_sched.current_proc->stack_pointer;
}

/************************************************************
*                       4 general use                       *
************************************************************/
void init_bugurt(void){
    cli();
    scheduler_init( &system_sched, &idle );
    system_sched.nested_crit_sec = 1;
}
void start_bugurt(void){
    start_scheduler();
    exit_crit_sec();
}
//-----------------------------------------------------------
// slowpoke critical section wrapper
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
void wait_time(timer_t time){
    timer_t tmr;
    bool_t roll=1;
    enter_crit_sec();
    tmr = (timer_t)system_timer;
    exit_crit_sec();
    while(roll){
        enter_crit_sec();
        roll = ( (timer_t)system_timer - (timer_t)tmr < time );
        exit_crit_sec();
    }
}
timer_t _timer( timer_t t ){
    enter_crit_sec();
    t = (timer_t)system_timer - (timer_t)t;
    exit_crit_sec();
    return t;
}
