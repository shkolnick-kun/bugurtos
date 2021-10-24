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

/*====================================================================================*/
/*Cortex-Mx registers*/
/*SCB*/
#define BGRT_SYS_ICSR 	*((volatile unsigned long *) 0xE000ED04)
#define BGRT_SYS_VTOR 	*((volatile unsigned long *) 0xE000ED08)
/*
#define BGRT_SYS_SCR 		*((volatile unsigned long *) 0xE000ED10)
#define BGRT_SYS_CCR 		*((volatile unsigned long *) 0xE000ED14)

#define BGRT_SYS_SHPR1 	*((volatile unsigned long *) 0xE000ED18)
*/
#define BGRT_SYS_SHPR2 	*((volatile unsigned long *) 0xE000ED1C)
#define BGRT_SYS_SHPR3 	*((volatile unsigned long *) 0xE000ED20)
/*
#define BGRT_SYS_SHCRS 	*((volatile unsigned long *) 0xE000ED24)
#define BGRT_SYS_CFSR 	*((volatile unsigned long *) 0xE000ED28)
*/

/*SysTick*/
#define BGRT_SYST_CSR 	*((volatile unsigned long *) 0xE000E010)
#define BGRT_SYST_RVR 	*((volatile unsigned long *) 0xE000E014)

/*NVIC*/
#define BGRT_NVIC_ISER  *((volatile unsigned long *) 0xE000E100)
#define BGRT_NVIC_ICER  *((volatile unsigned long *) 0xE000E180)
#define BGRT_NVIC_ICPR  *((volatile unsigned long *) 0xE000E280)

/*Masks and values*/
#define BGRT_SYST_RVR_VALUE ((BGRT_CONFIG_FCPU_HZ / BGRT_CONFIG_FSYSTICK_HZ)- 1ul)
#define BGRT_SYST_CSR_VALUE (0x00000007)/* Enable clock, interrupt, timer. */

#define BGRT_PENDSV_SET   (0x10000000)
#define BGRT_PENDSV_CLR   (0x08000000)

#define BGRT_SIO_IRQ_CORE0 (0x00008000)
#define BGRT_SIO_IRQ_CORE1 (0x00010000)
/*------------------------------------------------------------------------------------*/
/*rp2040 registers*/
#define BGRT_SIO_CPUID   *((volatile unsigned long *)0xD0000000)

#define BGRT_SIO_FIFO_ST *((volatile unsigned long *)0xD0000050) /*Status*/
#define BGRT_SIO_FIFO_WR *((volatile unsigned long *)0xD0000054) /*Read*/
#define BGRT_SIO_FIFO_RD *((volatile unsigned long *)0xD0000058) /*Write*/

/*Masks*/
#define BGRT_SIO_FIFO_ST_VLD (0x01)
#define BGRT_SIO_FIFO_ST_RDY (0x02)
#define BGRT_SIO_FIFO_ST_WOF (0x04)
#define BGRT_SIO_FIFO_ST_ROE (0x08)

/*====================================================================================*/
#define BGRT_KBLOCK bgrt_kernel.kblock[BGRT_SIO_CPUID]
#define BGRT_CURR_PROC bgrt_kernel.sched[BGRT_SIO_CPUID].current_proc

/*====================================================================================*/
#ifndef BGRT_CONFIG_PRIO_BITS
#error "You must define BGRT_CONFIG_PRIO_BITS macro!!!"
#endif /*BGRT_CONFIG_PRIO_BITS*/

#ifndef BGRT_CONFIG_MP
#error "You must define BGRT_CONFIG_MP macro!!!"
#endif/*BGRT_CONFIG_MP*/

#if BGRT_MAX_CPU != 2
#error "You must set BGRT_MAX_CPU to 2!!!"
#endif/*BGRT_MAX_CPU*/

#ifndef BGRT_CONFIG_FCPU_HZ
#error "You must define BGRT_CONFIG_FCPU_HZ macro!!!"
#endif /*BGRT_CONFIG_FCPU_HZ*/

#ifndef BGRT_CONFIG_FSYSTICK_HZ
#error "You must define BGRT_CONFIG_FSYSTICK_HZ macro!!!"
#endif /*BGRT_CONFIG_FSYSTICK_HZ*/

#if BGRT_SYST_RVR_VALUE > 0xFFFFFFUL
#error "Impossible SYST_RVR value!!! "
#endif /*BGRT_SYST_RVR_VALUE*/

#ifdef LIB_PICO_STANDARD_LINK
/*Используемые прерывания*/
#   define BGRT_CORE0_SIO_ISR    isr_irq15
#   define BGRT_CORE1_SIO_ISR    isr_irq16
#   define BGRT_SYSTEM_TIMER_ISR isr_systick
#   define BGRT_SYSCALL_ISR      isr_pendsv

extern unsigned long __StackOneTop;
#ifndef BGRT_STACK1_TOP
#define BGRT_STACK1_TOP (&__StackOneTop - 1) /*Do we need -1 ???*/
#endif/*BGRT_STACK1_TOP*/
#endif/*LIB_PICO_STANDARD_LINK*/

#ifndef BGRT_CORE1_CFG_HOOK
#define BGRT_CORE1_CFG_HOOK() do{}while(0) 
#endif

/*====================================================================================*/
#define BGRT_CONTEXT_STORE() \
	__asm__ __volatile__ (           \
				"mrs r0, psp         \n\t"\
				"sub r0, r0, #36     \n\t"\
				"msr psp, r0         \n\t"\
				"stmia r0!, {r4-r7}  \n\t"\
				"mov r3, r8          \n\t"\
				"mov r4, r9          \n\t"\
				"mov r5, r10         \n\t"\
				"mov r6, r11         \n\t"\
				"mov r7, lr          \n\t"\
				"stmia r0!, {r3-r7}  \n\t"\
				"dsb                 \n\t"\
				:::)
/*====================================================================================*/
#define BGRT_CONTEXT_LOAD() \
	__asm__ __volatile__ (           \
				"mrs r1, psp         \n\t"\
				"mov r0, r1          \n\t"\
				"add r0, r0, #16     \n\t"\
				"ldmia r0!, {r3-r7}  \n\t"\
				"mov r8,  r3         \n\t"\
				"mov r9,  r4         \n\t"\
				"mov r10, r5         \n\t"\
				"mov r11, r6         \n\t"\
				"mov lr,  r7         \n\t"\
				"ldmia r1!, {r4-r7}  \n\t"\
				"msr psp, r0         \n\t"\
				"dsb                 \n\t"\
				"isb                 \n\t"\
				"bx lr               \n\t"\
				:::)

#define BGRT_SEV() __asm__ __volatile__ ("sev":::)
#define BGRT_WFE() __asm__ __volatile__ ("wfe":::)
#define BGRT_NOP() __asm__ __volatile__ ("nop":::)
#define BGRT_DMB() __asm__ __volatile__ ("dmb":::"memory")
#define BGRT_DSB() __asm__ __volatile__ ("dsb":::"memory")
#define BGRT_ISB() __asm__ __volatile__ ("isb":::)

/*====================================================================================*/
volatile bgrt_stack_t bugurt_kernel_core0_stack[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
volatile bgrt_stack_t bugurt_kernel_core1_stack[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static volatile bgrt_stack_t * saved_sp[2];
static volatile bgrt_stack_t * kernel_sp[2];
static volatile bgrt_stack_t ** current_sp[2] = {&kernel_sp[0], &kernel_sp[1]};

static volatile bgrt_bool_t kernel_mode[2] = {1, 1};
/*====================================================================================*/
static bgrt_stack_t * _read_psp(void)
{
    bgrt_stack_t * ret=0;
    __asm__ __volatile__ ("mrs %0, psp\n\t" :"=r" (ret)::);
    return ret;
}
/*====================================================================================*/
static void _write_psp(volatile bgrt_stack_t * ptr)
{
    __asm__ __volatile__ (
        "msr psp, %0 \n\t"
        "dsb         \n\t"
        "isb         \n\t"
        ::"r" (ptr):
   );
}

/*====================================================================================*/
void bgrt_spin_init(bgrt_lock_t * lock)
{
    bgrt_cpuid_t i;
    for (i=0; i<BGRT_MAX_CPU; i++)
    {
        lock->number[i]   = 0;
        lock->entering[i] = 0;
    }
}
/*====================================================================================*/
void bgrt_spin_lock(bgrt_lock_t * lock)
{
    bgrt_cpuid_t i = BGRT_SIO_CPUID;
    bgrt_cpuid_t j;

    lock->entering[i] = 1;
    BGRT_DMB();
    for (j = 0; j < BGRT_MAX_CPU; j++)
    {
        if (lock->number[j] > lock->number[i])
        {
            lock->number[i] = lock->number[j];
        }
    }
    lock->number[i] += 1;
    BGRT_DMB();
    lock->entering[i] = 0;
    //BGRT_SEV();

    for (j = 0; j < BGRT_MAX_CPU; j++)
    {
        if (i != j)
        {
            while (1 == lock->entering[j])
            {
                BGRT_NOP();//BGRT_WFE();
            }

            while ((0 != lock->number[j]) && (
                (lock->number[j] < lock->number[i]) || (
                    (lock->number[j] == lock->number[i]) && (j < i))))
            {
                BGRT_NOP();//BGRT_WFE();
            }
        }
    }
}
/*====================================================================================*/
void bgrt_spin_free(bgrt_lock_t * lock)
{
    lock->number[BGRT_SIO_CPUID] = 0;
    //BGRT_SEV();
}

/*====================================================================================*/
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

/*====================================================================================*/
bgrt_cpuid_t bgrt_curr_cpu(void)
{
    return BGRT_SIO_CPUID;
}

/*====================================================================================*/
static inline void _sio_send(bgrt_map_t msg)
{
    while (!(BGRT_SIO_FIFO_ST & BGRT_SIO_FIFO_ST_RDY))
    {
        BGRT_WFE();
    }
    BGRT_SIO_FIFO_WR = msg;
    BGRT_SEV();
}
/*====================================================================================*/
void BGRT_CORE0_SIO_ISR(void)
{
    BGRT_ISR_START();
    if (0 != BGRT_SIO_CPUID)
    {
        BGRT_NVIC_ICER = BGRT_SIO_IRQ_CORE0;
        BGRT_NVIC_ICPR = BGRT_SIO_IRQ_CORE0;
        return;
    }
    while (BGRT_SIO_FIFO_ST & BGRT_SIO_FIFO_ST_VLD)
    {
        BGRT_ATM_BSET_ISR(&BGRT_KBLOCK.lpmap, BGRT_SIO_FIFO_RD);
        BGRT_SEV();
    }
    BGRT_SIO_FIFO_ST = 0xFF;
    BGRT_ISR_END();
}
/*====================================================================================*/
void BGRT_CORE1_SIO_ISR(void)
{
    BGRT_ISR_START();
    if (1 != BGRT_SIO_CPUID)
    {
        BGRT_NVIC_ICER = BGRT_SIO_IRQ_CORE1;
        BGRT_NVIC_ICPR = BGRT_SIO_IRQ_CORE1;
        return;
    }
    while (BGRT_SIO_FIFO_ST & BGRT_SIO_FIFO_ST_VLD)
    {
        BGRT_ATM_BSET_ISR(&BGRT_KBLOCK.lpmap, BGRT_SIO_FIFO_RD);
        BGRT_SEV();
    }
    BGRT_SIO_FIFO_ST = 0xFF;
    BGRT_ISR_END();
}

/*====================================================================================*/
void bgrt_resched(bgrt_cpuid_t core)
{
    if (core != BGRT_SIO_CPUID)
    {
        _sio_send(BGRT_KBLOCK_VRESCH);
    }
    else
    {
        bgrt_atm_bset(&BGRT_KBLOCK.lpmap, BGRT_KBLOCK_VRESCH);
    }
}
/*====================================================================================*/
bgrt_proc_t * bgrt_curr_proc(void)
{
    return BGRT_CURR_PROC;
}

/*====================================================================================*/
bgrt_stack_t * bgrt_proc_stack_init(bgrt_stack_t * sstart, bgrt_code_t pmain, void * arg, void(*return_address)(void) )
{
    /* регистры, сохраняемые аппаратно */
    *sstart = (bgrt_stack_t)0x01000000;		    /* psr */
    *(--sstart) = (bgrt_stack_t)pmain;		   	/* pc !!! pmain !!! */
    *(--sstart) = (bgrt_stack_t)return_address; /* lr !!! return_address !!! */
    *(--sstart) = (bgrt_stack_t)0x12;			/* r12 */
    *(--sstart) = (bgrt_stack_t)0x03;			/* r3 */
    *(--sstart) = (bgrt_stack_t)0x02;			/* r2 */
    *(--sstart) = (bgrt_stack_t)0x01;			/* r1 */
    *(--sstart) = (bgrt_stack_t)arg;			/* r0 !!! arg !!! */
    /* регистры, сохраняемые программно */
    *(--sstart) = (bgrt_stack_t)0xFFFFFFFD;		/* lr Во всех процессах будет использоваться psp */
    *(--sstart) = (bgrt_stack_t)0x11;			/* r11 */
    *(--sstart) = (bgrt_stack_t)0x10;			/* r10 */
    *(--sstart) = (bgrt_stack_t)0x09;			/* r9 */
    *(--sstart) = (bgrt_stack_t)0x08;			/* r8 */
    *(--sstart) = (bgrt_stack_t)0x07;			/* r7 */
    *(--sstart) = (bgrt_stack_t)0x06;			/* r6 */
    *(--sstart) = (bgrt_stack_t)0x05;			/* r5 */
    *(--sstart) = (bgrt_stack_t)0x04;			/* r4 */
    return sstart;
}

/*====================================================================================*/
void bgrt_core1_main(void)
{
    BGRT_INT_LOCK();
    _write_psp((volatile bgrt_stack_t *)&bugurt_kernel_core1_stack[16]); /* !!! Внимательно смотрим на границы!!! */
    /* Настраиваем прерывание SIO*/
    BGRT_NVIC_ICPR = BGRT_SIO_IRQ_CORE1;
    BGRT_NVIC_ISER = BGRT_SIO_IRQ_CORE1;

    BGRT_CORE1_CFG_HOOK();

    BGRT_INT_FREE();

    bgrt_kblock_main(&BGRT_KBLOCK);
}
/*====================================================================================*/
static inline void _bgrt_start_core1(void)
{
    const unsigned long _core1_init_data[] = {
        0,0,1, 
        (unsigned long)BGRT_SYS_VTOR, 
        (unsigned long)BGRT_STACK1_TOP,
        (unsigned long)bgrt_core1_main
    };
    int i;
    BGRT_NVIC_ICER = BGRT_SIO_IRQ_CORE0;
    for (i=0; i < sizeof(_core1_init_data)/sizeof(_core1_init_data[0]); i++)
    {
        unsigned long cmd = _core1_init_data[i];
        if (0 == cmd)
        {
            while (BGRT_SIO_FIFO_ST & BGRT_SIO_FIFO_ST_VLD)
            {
                (void)BGRT_SIO_FIFO_RD;
            }
        }
        _sio_send(cmd);
        while (!(BGRT_SIO_FIFO_ST & BGRT_SIO_FIFO_ST_VLD))
        {
            BGRT_WFE();
        }
        if (BGRT_SIO_FIFO_RD != cmd)
        {
            i = 0;
        }
    }
    /* Настраиваем прерывание SIO*/
    BGRT_NVIC_ICPR = BGRT_SIO_IRQ_CORE0;
    BGRT_NVIC_ISER = BGRT_SIO_IRQ_CORE0;
}
/*====================================================================================*/
void BGRT_SYSTEM_TIMER_ISR(void)
{
    BGRT_ISR_START();

    BGRT_SPIN_LOCK(&bgrt_kernel.timer);
    bgrt_kernel.timer.val++;
    if (bgrt_kernel.timer.tick)
    {
        bgrt_kernel.timer.tick();
    }
    BGRT_SPIN_FREE(&bgrt_kernel.timer);

    bgrt_atm_bset(&BGRT_KBLOCK.lpmap, BGRT_KBLOCK_VTMR); /* Interrupts are enabled on Cortex-Mx */
    _sio_send(BGRT_KBLOCK_VTMR); /*Send event to the core1*/

    BGRT_ISR_END();
}

/*====================================================================================*/
void bgrt_init(void)
{
    BGRT_INT_LOCK();
    bgrt_kernel_init();
    /* Устанавливаем начальное значение PSP, для потока Ядра; */
    _write_psp((volatile bgrt_stack_t *)&bugurt_kernel_core0_stack[16]); /* !!! Внимательно смотрим на границы!!! */
    /* Устанавливаем приоритеты обработчиков прерываний; */
    BGRT_SYS_SHPR3 |= (BGRT_CONFIG_SCHED_PRIO  << (8 - BGRT_CONFIG_PRIO_BITS)) << 16; /* PendSV */
    BGRT_SYS_SHPR3 |= (BGRT_CONFIG_SCHED_PRIO  << (8 - BGRT_CONFIG_PRIO_BITS)) << 24; /* SysTick */
    /* Настраиваем системный таймер и приоритет его прерывания */
    BGRT_SYST_RVR = BGRT_SYST_RVR_VALUE;
    BGRT_SYST_CSR = BGRT_SYST_CSR_VALUE;
}
/*====================================================================================*/
void bgrt_start(void)
{
    _bgrt_start_core1();
    BGRT_INT_FREE();
    bgrt_kblock_main(&BGRT_KBLOCK);
}

/*====================================================================================*/
bgrt_st_t bgrt_syscall(bgrt_syscall_t num, void * arg)
{
    BGRT_USPD_T udata;

    BGRT_INT_LOCK();

    udata = BGRT_GET_USPD();
    udata->scnum = num;
    udata->scarg = arg;

    BGRT_ATM_BSET_ISR(&BGRT_KBLOCK.lpmap, BGRT_KBLOCK_VSCALL);

    BGRT_SYS_ICSR |= BGRT_PENDSV_SET;
    BGRT_INT_FREE();

    return udata->scret;
}
/*====================================================================================*/
void bgrt_switch_to_proc(void)
{
    BGRT_INT_LOCK();

    kernel_mode[BGRT_SIO_CPUID] = (bgrt_bool_t)0;

    BGRT_SYS_ICSR |= BGRT_PENDSV_SET;
    BGRT_INT_FREE();
}
/*====================================================================================*/
static void bgrt_set_curr_sp(void)
{
    if (BGRT_KBLOCK.hpmap      ||
#ifdef BGRT_CONFIG_USE_VIC
        BGRT_KBLOCK.vic.list.map ||
#endif/*BGRT_CONFIG_USE_VIC*/
        BGRT_KBLOCK.lpmap)
    {
        kernel_mode[BGRT_SIO_CPUID] = 1;
    }

    if (kernel_mode[BGRT_SIO_CPUID])
    {
        current_sp[BGRT_SIO_CPUID] = &kernel_sp[BGRT_SIO_CPUID];
    }
    else
    {
        current_sp[BGRT_SIO_CPUID] = &BGRT_CURR_PROC->spointer;
    }
}

/*====================================================================================*/
__attribute__ ((naked)) void BGRT_SYSCALL_ISR(void)
{
    BGRT_CONTEXT_STORE();
    saved_sp[BGRT_SIO_CPUID] = _read_psp();
    *(current_sp[BGRT_SIO_CPUID]) = saved_sp[BGRT_SIO_CPUID];

    bgrt_set_curr_sp();

    BGRT_SYS_ICSR |= BGRT_PENDSV_CLR; /* Fix for a hardware race condition. */

    _write_psp(*(current_sp[BGRT_SIO_CPUID]));
    BGRT_CONTEXT_LOAD();
}
