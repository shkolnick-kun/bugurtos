/**************************************************************************
    BuguRTOS-0.9.x (Bugurt real time operating system)
    Copyright (C) 2015 anonimous

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
#include <bugurt.h>
#include <util/delay.h>
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#define _bugurt_isr_prologue() \
    bgrt_proc_t * cp; \
    cp = bgrt_curr_proc(); \
    cli(); \
    cp->spointer = vm_state[current_vm].sp; \
    sei()

#define _bugurt_isr_epilogue() \
    cp = bgrt_curr_proc(); \
    cli(); \
    vm_state[current_vm].sp = cp->spointer; \
    sei()
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bgrt_proc_t * bgrt_curr_proc(void)
{
    bgrt_proc_t * ret;
    cli();
    ret = bgrt_kernel.sched[current_vm].current_proc;
    sei();
    return ret;
}

void bgrt_spin_init( bgrt_lock_t * lock )
{
    cli();
    *lock = (bgrt_lock_t)0;
    sei();
}

void bgrt_spin_lock( bgrt_lock_t * lock )
{
    unsigned short i;
    i = 1;
    do
    {
        cli();
        if(!*lock)
        {
            *lock = (bgrt_lock_t)1;
            i = 0;
        }
        sei();
    }while(i);
    _delay_us(1100);// delay, all other vms must spin for a while
}
void bgrt_spin_free(bgrt_lock_t * lock)
{
    cli();
    *lock = (bgrt_lock_t)0;
    sei();
}
// bgrt_ls_t is simply process counter here!
void bgrt_stat_init( bgrt_ls_t * stat )
{
    *stat = 0; // no lad on a system
}
void bgrt_stat_dec( bgrt_proc_t * proc, bgrt_ls_t * stat )
{
    (*stat)--;
}
void bgrt_stat_inc( bgrt_proc_t * proc, bgrt_ls_t * stat )
{
    (*stat)++;
}
void bgrt_stat_merge( bgrt_ls_t *src_stat, bgrt_ls_t * dst_stat  )
{
    *dst_stat += *src_stat;
    *src_stat = (bgrt_ls_t)0;
}
load_t bgrt_stat_calc_load(bgrt_prio_t prio, bgrt_ls_t * stat)
{
    return (load_t)*stat;
}
void bgrt_resched(bgrt_cpuid_t core_id)
{
    cli();
    vsmp_vinterrupt_isr( core_id, ( vinterrupt_t * )resched_vectors + core_id );
    sei();
}

/******************************************************************************************************/
// Код ядра
vinterrupt_t resched_vectors[BGRT_MAX_CPU];

void resched_isr(void)
{
    _bugurt_isr_prologue();

    bgrt_sched_reschedule();

    _bugurt_isr_epilogue();
}
void resched_vectors_init(void)
{
    bgrt_cpuid_t i;
    for(i = 0; i < BGRT_MAX_CPU; i++)
    {
        vsmp_vinterrupt_init( ( vinterrupt_t * )resched_vectors + i, resched_isr );
    }
}
vinterrupt_t systimer_tick_vector;
vinterrupt_t systimer_vectors[BGRT_MAX_CPU];
void _systimer_tick_isr(void)
{
    BGRT_SPIN_LOCK_KERNEL_TIMER();
    bgrt_kernel.timer++;
    if( bgrt_kernel.timer_tick != (void (*)(void))0 ) bgrt_kernel.timer_tick();
    BGRT_SPIN_FREE_KERNEL_TIMER();

    systimer_vectors_fire();
}

void systimer_tick_isr(void)
{
    _bugurt_isr_prologue();

    _systimer_tick_isr();

    _bugurt_isr_epilogue();
}

void systimer_sched_isr(void)
{
    _bugurt_isr_prologue();

    bgrt_sched_schedule();

    _bugurt_isr_epilogue();
}

void systimer_vectors_init(void)
{
    bgrt_cpuid_t i;
    vsmp_vinterrupt_init( &systimer_tick_vector, systimer_tick_isr ); // Zero core is "mater", it handles bgrt_kernel.timer
    for(i = 0; i < BGRT_MAX_CPU; i++)
    {
        vsmp_vinterrupt_init( (vinterrupt_t *)systimer_vectors + i, systimer_sched_isr ); // Other cores are slaves they just schedule.
    }
}

void systimer_vectors_fire(void)
{
    bgrt_cpuid_t i;
    for(i = 0; i < BGRT_MAX_CPU; i++)
    {
        cli();
        vsmp_vinterrupt_isr( i, (vinterrupt_t *)systimer_vectors + i );
        sei();
    }
}


bgrt_cnt_t systimer_hook_counter = 0;
void vsmp_systimer_hook_bugurt(void)
{
    if(!current_vm)
    {
        systimer_hook_counter++;
        if( systimer_hook_counter >= BGRT_CONFIG_SYSTIMER_HOOK_THR )
        {
            systimer_hook_counter = (bgrt_cnt_t)0;
            cli();
            vsmp_vinterrupt_isr(0,&systimer_tick_vector);
            sei();
        }

    }
}

vinterrupt_t syscall_vectors[BGRT_MAX_CPU];
bgrt_syscall_t syscall_num[BGRT_MAX_CPU];
void * syscall_arg[BGRT_MAX_CPU];

// Local variable is used compiler generated prologue and epilogue needed
void _syscall_isr(void)
{
    bgrt_cpuid_t core;
    core = bgrt_current_cpu();
    bgrt_do_syscall( syscall_num[core], syscall_arg[core] );
    syscall_num[core] = 0;//Готово
}
//__attribute__ (( naked )) void syscall_isr(void)
void syscall_isr(void)
{
    _bugurt_isr_prologue();

    _syscall_isr();

    _bugurt_isr_epilogue();
}


void syscall_vectors_init(void)
{
    bgrt_cpuid_t i;
    for(i = 0; i < BGRT_MAX_CPU; i++)
    {
        vsmp_vinterrupt_init( ( vinterrupt_t * )syscall_vectors + i, syscall_isr );
        syscall_num[i] = (bgrt_syscall_t)0;
        syscall_arg[i] = (void *)0;
    }
}

void bgrt_syscall( unsigned char num, void * arg )
{
    bgrt_cpuid_t core;
    bgrt_item_t * vector;

    bgrt_disable_interrupts();

    cli();
    core = current_vm;
    sei();

    syscall_num[core] = (bgrt_syscall_t)num;
    syscall_arg[core] = (void *)arg;
    vector = (bgrt_item_t *)( &syscall_vectors[core] );

    cli();
    vm_state[current_vm].int_enabled = (bgrt_bool_t)1; // Virtual interrupts MUST be enabled !!!
    // System call is not an ordinary interrupt!!!
    // It MUST be serviced FIRST!!!
    if( vm_state[current_vm].int_fifo )
    {
        bgrt_item_insert( (bgrt_item_t *)vector, ((bgrt_item_t *)vm_state[current_vm].int_fifo)->next );
    }
    vm_state[current_vm].int_fifo = (bgrt_item_t *)vector;
    _vsmp_vinterrupt();
}
/***************************************************************************************************************/
// Функции общего пользования

void bgrt_init(void)
{
    bgrt_cpuid_t i;
    bgrt_disable_interrupts();
    resched_vectors_init();
    systimer_vectors_init();
    syscall_vectors_init();
    bgrt_kernel_init();
    bgrt_kernel.sched[bgrt_current_cpu()].nested_crit_sec = (bgrt_cnt_t)1;
    for(i = 1; i < BGRT_MAX_CPU; i++)
    {
        bgrt_kernel.idle[i].pmain = vsmp_idle_main;
    }
}
void bgrt_start(void)
{
    bgrt_kernel.sched[bgrt_current_cpu()].nested_crit_sec = (bgrt_cnt_t)0;
    cli();
    vsmp_systimer_hook = vsmp_systimer_hook_bugurt;
    sei();
    bgrt_enable_interrupts();
    BGRT_POST_START( (void *)0 );
}
