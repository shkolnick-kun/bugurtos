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
#include <util/delay.h>

bgrt_stack_t * saved_sp;
bgrt_stack_t * kernel_sp[BGRT_MAX_CPU];
bgrt_bool_t kernel_mode[BGRT_MAX_CPU];
bgrt_stack_t kernel_stack[BGRT_MAX_CPU -1][VM_STACK_SIZE];

/*VM variables*/
volatile bgrt_cpuid_t current_vm = 0;
bgrt_bool_t vm_int_enabled[BGRT_MAX_CPU];

bgrt_stack_t ** current_sp = &kernel_sp[0];

bgrt_cpuid_t bgrt_curr_cpu(void)
{
    bgrt_cpuid_t ret;
    cli();
    ret = current_vm;
    sei();
    return ret;
}

bgrt_proc_t * bgrt_curr_proc(void)
{
    bgrt_proc_t * ret;
    cli();
    ret = BGRT_CURR_PROC;
    sei();
    return ret;
}

void bgrt_resched(bgrt_cpuid_t core)
{
    cli();
    BGRT_ATM_BSET_ISR(&bgrt_kernel.kblock[core].lpmap, BGRT_KBLOCK_VRESCH);
    sei();
}

void bgrt_spin_init(bgrt_lock_t * lock)
{
    cli();
    *lock = (bgrt_lock_t)0;
    sei();
}

void bgrt_spin_lock(bgrt_lock_t * lock)
{
    unsigned short i;
    i = 1;
    do
    {
        cli();
        if (!*lock)
        {
            *lock = (bgrt_lock_t)1;
            i = 0;
        }
        sei();
    }
    while (i);
    for(i=0;i<1000;i++);/*_delay_us(1100);// delay, all other vms must spin for a while*/
}
void bgrt_spin_free(bgrt_lock_t * lock)
{
    cli();
    *lock = (bgrt_lock_t)0;
    sei();
}
/* bgrt_ls_t is simply process counter here!*/
void bgrt_stat_init(bgrt_ls_t * stat)
{
    *stat = 0; /* no lad on a system*/
}
void bgrt_stat_dec(bgrt_proc_t * proc, bgrt_ls_t * stat)
{
    (*stat)--;
}
void bgrt_stat_inc(bgrt_proc_t * proc, bgrt_ls_t * stat)
{
    (*stat)++;
}
void bgrt_stat_merge(bgrt_ls_t *src_stat, bgrt_ls_t * dst_stat )
{
    *dst_stat += *src_stat;
    *src_stat = (bgrt_ls_t)0;
}
bgrt_load_t bgrt_stat_calc_load(bgrt_prio_t prio, bgrt_ls_t * stat)
{
    return (bgrt_load_t)*stat;
}
/******************************************************************************************************/
void bgrt_set_curr_sp(void)
{
    if (vm_int_enabled[current_vm])
    {
        if (BGRT_KBLOCK.hpmap      ||
            BGRT_KBLOCK.vic.list.map ||
            BGRT_KBLOCK.lpmap)
        {
            kernel_mode[current_vm] = 1;
        }

    }

    if (kernel_mode[current_vm])
    {
        current_sp = &kernel_sp[current_vm];
    }
    else
    {
        current_sp = &BGRT_CURR_PROC->spointer;
    }
}

/* Код ядра*/
static void bgrt_priv_switch_to_kernel(void)
{
    BGRT_ATM_BSET_ISR(&BGRT_KBLOCK.lpmap, BGRT_KBLOCK_VSCALL);
}
__attribute__ ((naked)) void bgrt_switch_to_kernel(void);
void bgrt_switch_to_kernel(void)
{
    BGRT_ISR_START();
    bgrt_priv_switch_to_kernel();
    BGRT_ISR_END();
}

bgrt_st_t bgrt_syscall(bgrt_syscall_t num, void * arg)
{
    BGRT_USPD_T udata;
    udata = BGRT_GET_USPD();
    cli();
    udata->scnum = num;
    udata->scarg = arg;
    vm_int_enabled[current_vm]=1;
    bgrt_switch_to_kernel();
    return udata->scret;
}

void bgrt_int_lock(void)
{
    cli();
    vm_int_enabled[current_vm]=0;
    sei();
}

bgrt_vint_t int_systick;

static void do_int_systick(void * arg)
{
    bgrt_cpuid_t i;
    (void)arg;

    BGRT_SPIN_LOCK(&bgrt_kernel.timer);

    bgrt_kernel.timer.val++;
    if (bgrt_kernel.timer.tick != (void (*)(void))0)bgrt_kernel.timer.tick();

    BGRT_SPIN_FREE(&bgrt_kernel.timer);

    cli();
    for (i = 0; i < BGRT_MAX_CPU; i++)
    {
        BGRT_ATM_BSET_ISR(&bgrt_kernel.kblock[i].lpmap, BGRT_KBLOCK_VTMR);
    }
    sei();
}

static void _int_free(void)
{
    vm_int_enabled[current_vm]=1;
    kernel_mode[current_vm] = 1;
}

__attribute__ ((naked)) void bgrt_int_free(void);
void bgrt_int_free(void)
{
    cli();
    BGRT_ISR_START();
    _int_free();
    BGRT_ISR_END();
}

static void _switch_to_proc(void)
{
    if (vm_int_enabled[current_vm])
    {
        kernel_mode[current_vm] = (bgrt_bool_t)0;
    }
}

__attribute__ ((naked)) void bgrt_switch_to_proc(void)
{
    cli();
    BGRT_ISR_START();
    _switch_to_proc();
    BGRT_ISR_END();
}

bgrt_cnt_t systimer_hook_counter = 0;
static void _BGRT_SYSTEM_TIMER_ISR(void)
{
    current_vm++;
    if (current_vm >= BGRT_MAX_CPU)current_vm = (bgrt_cpuid_t)0;

    systimer_hook_counter++;
    if (systimer_hook_counter >= BGRT_CONFIG_SYSTIMER_HOOK_THR)
    {
        systimer_hook_counter = (bgrt_cnt_t)0;
        bgrt_vint_push_isr(&int_systick, &BGRT_KBLOCK.vic);
    }
}
__attribute__ ((signal, naked)) void BGRT_SYSTEM_TIMER_ISR(void);
void BGRT_SYSTEM_TIMER_ISR(void)
{
    BGRT_ISR_START();
    _BGRT_SYSTEM_TIMER_ISR();
    BGRT_ISR_END();
}
/***************************************************************************************************************/
/* Функции общего пользования*/

static void _kernel_panic(void)
{
    while (1)
    {
        NOP();
    };
}

static void _idle_main(void *arg)
{
    (void)arg;

    while (1)
    {
        NOP();
    };
}

void bgrt_init(void)
{
    bgrt_cpuid_t i;
    cli();
    vm_int_enabled[0]=0;
    kernel_mode[0] = 1;
    for (i = 1; i < BGRT_MAX_CPU; i++)
    {
        vm_int_enabled[i]=0;
        kernel_mode[i] = 1;
        kernel_sp[i] = bgrt_proc_stack_init(
                           &kernel_stack[i-1][VM_STACK_SIZE - 1],
                           (bgrt_code_t)_idle_main,
                           (void *)0,
                           (void(*)(void))_kernel_panic
                       );
    }
    sei();
    bgrt_vint_init(&int_systick, BGRT_PRIO_LOWEST, (bgrt_code_t)do_int_systick, (void *)0);
    bgrt_kernel_init();
}
void bgrt_start(void)
{
    bgrt_cpuid_t i;
    cli();
    vm_int_enabled[0]=1;
    kernel_mode[0] = 1;
    for (i = 1; i < BGRT_MAX_CPU; i++)
    {
        vm_int_enabled[i]=1;
        kernel_mode[i] = 1;
        kernel_sp[i] = bgrt_proc_stack_init(
                           &kernel_stack[i-1][VM_STACK_SIZE - 1],
                           (bgrt_code_t)bgrt_kblock_main,
                           (void *)&bgrt_kernel.kblock[i],
                           (void(*)(void))_kernel_panic
                       );
    }
    sei();
    bgrt_kblock_main(&bgrt_kernel.kblock[0]);
}
