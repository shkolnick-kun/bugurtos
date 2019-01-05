/**************************************************************************
    BuguRTOS-4.0.x (Bugurt real time operating system)
    Copyright (C) 2018 anonimous

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

vsmp_vm_t vm_state[BGRT_MAX_CPU];
bgrt_stack_t vm_stack[BGRT_MAX_CPU -1][VM_STACK_SIZE];
bgrt_stack_t vm_int_stack[BGRT_MAX_CPU][VM_INT_STACK_SIZE];

volatile bgrt_cpuid_t current_vm;
volatile void * vm_buf;
hook_t vsmp_systimer_hook;



void vsmp_vm_init(vsmp_vm_t * vm, bgrt_stack_t * sp, bgrt_stack_t * int_sp)
{
    vm->int_fifo = (bgrt_item_t *)0; /*Нет прерываний;*/
    vm->int_enabled = 1;/*прерывания разрешены*/
    vm->sp = (bgrt_stack_t *)sp;
    vm->int_sp = (bgrt_stack_t *)int_sp;
    vm->int_nest_count = (bgrt_cnt_t)0;
}
void vsmp_init(void)
{
    unsigned short i;
    cli();
    for (i = 0; i < VM_STACK_SIZE; i++)vm_int_stack[0][i] = 0x55;
    vsmp_vm_init(&vm_state[0], (bgrt_stack_t *)0 , &vm_int_stack[0][VM_INT_STACK_SIZE-1]);
    for (current_vm = 1; current_vm < BGRT_MAX_CPU; current_vm++)
    {
        bgrt_stack_t * vm_sp;
        for (i = 0; i < VM_STACK_SIZE; i++)
        {
            vm_stack[current_vm - 1][i] = 0x55;
            vm_int_stack[current_vm][i] = 0x55;
        }
        vm_sp = bgrt_proc_stack_init(&vm_stack[current_vm - 1][VM_STACK_SIZE - 1], (bgrt_code_t)vsmp_idle_main, (void *)0, (void(*)(void))vsmp_idle_main);
        vsmp_vm_init(&vm_state[current_vm], (bgrt_stack_t *)vm_sp, &vm_int_stack[current_vm][VM_INT_STACK_SIZE-1]);
    }
    current_vm = 0;
}

void vsmp_run(void)
{
    sei();
}
void vsmp_idle_main(void * arg)
{
    while (1);
}

bgrt_bool_t vsmp_do_interrupt(void)
{
    /* if current vm is interruptible and there are some interrupts in fifo,*/
    if ((vm_state[current_vm].int_enabled) && (vm_state[current_vm].int_fifo))
    {
        /* cut head interrupt,*/
        vm_buf = (void *)vm_state[current_vm].int_fifo;
        if (vm_buf == (void *)((bgrt_item_t *)vm_buf)->next)
        {
            /* only one interrupt in fifo */
            vm_state[current_vm].int_fifo = (bgrt_item_t *)0;
        }
        else
        {
            /* many interrupts in fifo */
            vm_state[current_vm].int_fifo = (void *)((bgrt_item_t *)vm_buf)->next;
            bgrt_item_cut((bgrt_item_t *)vm_buf);
        }
        /* write its isr pointer to vm_buf,*/
        ((vinterrupt_t *)vm_buf)->num_pending = (bgrt_cnt_t)0;
        vm_buf = (void *)(((vinterrupt_t *)vm_buf)->isr);
        /* and return 1;*/
        return (bgrt_bool_t)1;
    }
    /* else return 0.*/
    return (bgrt_bool_t)0;
}

/* Virtual interrupt prologue and epilogue inline functions (I can,t debug macros !) */
#define _vsmp_interrupt_prologue() \
    vm_buf = (void *)bugurt_save_context(); \
    if (vm_state[current_vm].int_nest_count)\
    { \
        vm_state[current_vm].int_sp = (bgrt_stack_t *)vm_buf; \
    } \
    else \
    { \
        vm_state[current_vm].sp = (bgrt_stack_t *)vm_buf; \
    } \
    bugurt_set_stack_pointer(vm_state[current_vm].int_sp)

#define _vsmp_interrupt_epilogue() \
 \
    if (vsmp_do_interrupt())goto chained_vinterrupt_return; \
 \
    if (--vm_state[current_vm].int_nest_count)goto nesting_vinterrupt_return; \
 \
    vm_state[current_vm].int_sp = &vm_int_stack[current_vm][VM_INT_STACK_SIZE-1]; \
    bugurt_restore_context(vm_state[current_vm].sp); \
    __asm__ __volatile__("reti"::); \
 \
nesting_vinterrupt_return: \
 \
    bugurt_pop_context(); \
    __asm__ __volatile__("reti"::); \
 \
chained_vinterrupt_return: \
    bugurt_push_pointer((void *)vinterrupt_wrapper); \
    __asm__ __volatile__("ret"::)

/*
                       Virtual interrupts wrapper functions.
    Local variable is used to call virtual ISR, so wrapper must have two parts.
*/
/* Nested part, uses local variables, so compiler generated prologue and epilogue are needed.*/
void _vinterrupt_wrapper(void)
{
    void (*isr)(void);
    vm_state[current_vm].int_enabled = (bgrt_bool_t)0; /* Virtual interrupt nesting is not allowed by default.*/
    isr = (void (*)(void))vm_buf;
    /* After vm-buf read we can re-enable real interrupts!*/
    sei();
    isr();
}
/* Nesting part, no prologue and hand made epilogue.*/
__attribute__ ((naked)) void vinterrupt_wrapper(void)
{
    _vinterrupt_wrapper();
    cli();
    /* Virtual interrupts are enabled after interrupt processing.*/
    vm_state[current_vm].int_enabled = (bgrt_bool_t)1;
    /* Tail recursion, will return to it self entry point until all virtual interrupts are processed, lol!*/
    _vsmp_interrupt_epilogue();
}
/* System timer interrupt, round robin scheduler.*/
__attribute__ ((signal, naked)) void BGRT_SYSTEM_TIMER_ISR(void);
void BGRT_SYSTEM_TIMER_ISR(void)
{
    _vsmp_interrupt_prologue();

    current_vm++;
    if (current_vm >= BGRT_MAX_CPU)current_vm = (bgrt_cpuid_t)0;

    if (vsmp_systimer_hook)
    {
        vsmp_systimer_hook();
    }

    vm_state[current_vm].int_nest_count++;
    bugurt_set_stack_pointer(vm_state[current_vm].int_sp);

    _vsmp_interrupt_epilogue();
}
/* Software virtual interrupt tail function*/
__attribute__ ((naked)) void _vsmp_vinterrupt(void)
{
    _vsmp_interrupt_prologue();

    vm_state[current_vm].int_nest_count++;

    _vsmp_interrupt_epilogue();
}

/* Software virtual interrupt (For ISR usage only ! Do NOT call from "main"!)*/
bgrt_bool_t vsmp_vinterrupt_isr(bgrt_cpuid_t vm, vinterrupt_t * vector)
{
    if (vector->num_pending++)return (bgrt_bool_t)0;
    if (vm_state[vm].int_fifo)
    {
        bgrt_item_insert((bgrt_item_t *)vector, (bgrt_item_t *)vm_state[vm].int_fifo);
    }
    else
    {
        vm_state[vm].int_fifo = (bgrt_item_t *)vector;
    }
    return (bgrt_bool_t)1;
}
/* Software virtual interrupt (Use in "main" only ! Do NOT call from ISR!)*/
void vsmp_vinterrupt(bgrt_cpuid_t vm, vinterrupt_t * vector)
{
    cli();
    if (vsmp_vinterrupt_isr(vm, vector)) _vsmp_vinterrupt();
    else sei();
}

void vsmp_vinterrupt_init(vinterrupt_t * vector, void (*isr)(void))
{
    bgrt_item_init((bgrt_item_t *)vector);
    vector->num_pending = (bgrt_cnt_t)0;
    vector->isr = isr;
}

void BGRT_INT_LOCK(void)
{
    cli();
    vm_state[current_vm].int_enabled = (bgrt_bool_t)0;
    sei();
}

void BGRT_INT_FREE(void)
{
    cli();
    vm_state[current_vm].int_enabled = (bgrt_bool_t)1;
    if (vm_state[current_vm].int_fifo)_vsmp_vinterrupt();
    else sei();
}

bgrt_cpuid_t bgrt_curr_cpu(void)
{
    bgrt_cpuid_t ret;
    cli();
    ret = current_vm;
    sei();
    return ret;
}
