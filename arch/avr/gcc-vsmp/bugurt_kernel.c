/**************************************************************************
    BuguRTOS-0.4.x(Bugurt real time operating system)
    Copyright (C) 2011  anonimous

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

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes BuguRTOS, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
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
#include "bugurt_kernel.h"

///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
stack_t * saved_vm_sp[MAX_CORES];
__MACRO_FUNCTION__(_bugurt_isr_prologue)
{
    cli();
    saved_vm_sp[current_vm] = (stack_t *)SP; // I didn't write bugurt_get_stack_pointer();
    bugurt_set_stack_pointer( kernel.idle[current_vm].spointer );
    sei();
}
__MACRO_FUNCTION__(_bugurt_isr_epilogue)
{
    cli();
    bugurt_set_stack_pointer( saved_vm_sp[current_vm] );
    sei();
}
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void disable_interrupts(void)
{
    cli();
    vm_state[current_vm].int_enabled = (bool_t)0;
    sei();
}

void enable_interrupts(void)
{
    cli();
    vm_state[current_vm].int_enabled = (bool_t)1;
    sei();
}

proc_t * current_proc(void)
{
    proc_t * ret;
    cli();
    ret = kernel.sched[current_vm].current_proc;
    sei();
    return ret;
}

core_id_t current_core(void)
{
    core_id_t ret;
    cli();
    ret = current_vm;
    sei();
    return ret;
}

void spin_init( lock_t * lock )
{
    cli();
    *lock = (lock_t)0;
    sei();
}

void spin_lock( lock_t * lock )
{
    while(1)
    {
        cli();
        if(!*lock)
        {
            *lock = (lock_t)1;
            sei();
            return;
        }
        sei();
    }
}
void spin_unlock(lock_t * lock)
{
    unsigned char i;
    for(i = 0; i< 1000; i++);// delay, all other vms must spin for a while
    cli();
    *lock = (lock_t)0;
    sei();
}
// stat_t is simply prcess counter here!
void stat_init( stat_t * stat )
{
    *stat = 0; // no lad on a system
}
void stat_dec( proc_t * proc, stat_t * stat )
{
    *stat--;
}
void stat_inc( proc_t * proc, stat_t * stat )
{
    *stat++;
}
void stat_merge( stat_t *src_stat, stat_t * dst_stat  )
{
    *dst_stat += *src_stat;
    *src_stat = (stat_t)0;
}
load_t stat_calc_load(prio_t prio, stat_t * stat)
{
    return (load_t)*stat;
}
void resched(core_id_t core_id)
{
    vsmp_vinterrupt_isr( core_id, ( vinterrupt_t * )resched_vectors + core_id );
}

/******************************************************************************************************/
// Код ядра
vinterrupt_t resched_vectors[MAX_CORES];
__attribute__ (( naked )) void resched_isr(void)
{
    _bugurt_isr_prologue();

    sched_reschedule();

    _bugurt_isr_epilogue();
}
void resched_vectors_init(void)
{
    core_id_t i;
    for(i = 0; i < MAX_CORES; i++)
    {
        vsmp_vinterrupt_init( ( vinterrupt_t * )resched_vectors + i, resched_isr );
    }
}

vinterrupt_t systimer_vectors[MAX_CORES];
void _systimer_tick_isr(void)
{
    SPIN_LOCK_KERNEL_TIMER();
    kernel.timer++;
    if( kernel.timer_tick != (void (*)(void))0 ) kernel.timer_tick();
    SPIN_UNLOCK_KERNEL_TIMER();

    sched_schedule();
}
__attribute__ (( naked )) void systimer_tick_isr(void)
{
    _bugurt_isr_prologue();

    _systimer_tick_isr();

    _bugurt_isr_epilogue();
}


__attribute__ (( naked )) void systimer_sched_isr(void)
{
    _bugurt_isr_prologue();

    sched_schedule();

    _bugurt_isr_epilogue();
}

void systimer_vectors_init(void)
{
    core_id_t i;
    vsmp_vinterrupt_init( (vinterrupt_t *)systimer_vectors, systimer_tick_isr ); // Zero core is "mater", it handles kernel.timer
    for(i = 1; i < MAX_CORES; i++)
    {
        vsmp_vinterrupt_init( (vinterrupt_t *)systimer_vectors + i, systimer_sched_isr ); // Other cores are slaves they just shedule.
    }
}

void systimer_vectors_fire(void)
{
    core_id_t i;
    for(i = 0; i < MAX_CORES; i++)
    {
        vsmp_vinterrupt_isr( i, (vinterrupt_t *)systimer_vectors + i );
    }
}

#define SYSTIMER_HOOK_THR 10
count_t systimer_hook_counter;
void vsmp_systimer_hook_bugurt(void)
{
    if(!current_vm)
    {
        systimer_hook_counter++;
        if( systimer_hook_counter >= SYSTIMER_HOOK_THR )
        {
            systimer_hook_counter = (count_t)0;
            systimer_vectors_fire();
        }

    }
}

vinterrupt_t syscall_vectors[MAX_CORES];
syscall_t syscall_num[MAX_CORES];
void * syscall_arg[MAX_CORES];

// Local variable is used compiler generated prologue and epilogue needed
void _syscall_isr(void)
{
    core_id_t core;
    core = current_core();
    do_syscall( syscall_num[core], syscall_arg[core] );
}
__attribute__ (( naked )) void syscall_isr(void)
{
    _bugurt_isr_prologue();

    _syscall_isr();

    _bugurt_isr_epilogue();
}


void syscall_vectors_init(void)
{
    core_id_t i;
    for(i = 0; i < MAX_CORES; i++)
    {
        vsmp_vinterrupt_init( ( vinterrupt_t * )syscall_vectors + i, syscall_isr );
        syscall_num[i] = (syscall_t)0;
        syscall_arg[i] = (void *)0;
    }
}

void syscall_bugurt( unsigned char num, void * arg )
{
    core_id_t core;
    item_t * vector;

    disable_interrupts();

    cli();
    core = current_vm;
    sei();

    syscall_num[core] = (syscall_t)num;
    syscall_arg[core] = (void *)arg;
    vector = (item_t *)( &syscall_vectors[core] );

    cli();
    vm_state[current_vm].int_enabled = (bool_t)1; // Virtual interrupts MUST be eanabled !!!
    // System call is not an ordinary interrupt!!!
    // It MUST be serviced FIRST!!!
    if( vm_state[current_vm].int_fifo )
    {
        item_insert( (item_t *)vector, ((item_t *)vm_state[current_vm].int_fifo)->next );
    }
    vm_state[current_vm].int_fifo = (item_t *)vector;
    _vsmp_vinterrupt();
}
/***************************************************************************************************************/
// Функции общего пользования

void init_bugurt(void)
{
    core_id_t i;
    disable_interrupts();
    resched_vectors_init();
    systimer_vectors_init();
    syscall_vectors_init();
    kernel_init();
    kernel.sched[current_core()].nested_crit_sec = (count_t)1;
    for(i = 1; i < MAX_CORES; i++)
    {
        kernel.idle[i].pmain = vsmp_idle_main;
    }
}
void start_bugurt(void)
{
    kernel.sched[current_core()].nested_crit_sec = (count_t)0;
    enable_interrupts();
    cli();
    vsmp_systimer_hook = vsmp_systimer_hook_bugurt;
    sei();
    idle_main( (void *)0 );
}
