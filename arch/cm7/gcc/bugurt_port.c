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

#include <bugurt.h>

/*====================================================================================*/
#ifndef __VFP_FP__
#error "THis works only on FPU enabled devices (Cotrex(tm)-M4F)!!!"
#endif

#ifndef BGRT_CONFIG_FCPU_HZ
#error "You must define BGRT_CONFIG_FCPU_HZ macro!!!"
#endif /*BGRT_CONFIG_FCPU_HZ*/

#ifndef BGRT_CONFIG_FSYSTICK_HZ
#error "You must define BGRT_CONFIG_FSYSTICK_HZ macro!!!"
#endif /*BGRT_CONFIG_FSYSTICK_HZ*/

#if BGRT_SYST_RVR_VALUE > 0xFFFFFFUL
#error "Impossible SYST_RVR value!!! "
#endif /*BGRT_SYST_RVR_VALUE*/

#ifndef BGRT_CONFIG_PRIO_BITS
#error "You must define BGRT_CONFIG_PRIO_BITS macro!!!"
#endif /*BGRT_CONFIG_PRIO_BITS*/

#if (BGRT_CONFIG_CRITSEC_PRIO <= BGRT_CONFIG_SYSCALL_PRIO)
#error "BGRT_CONFIG_SYSCALL_PRIO must be less than BGRT_CONFIG_CRITSEC_PRIO !!!"
#endif /*BGRT_CONFIG_CRITSEC_PRIO*/

#if (BGRT_CONFIG_SCHED_PRIO < BGRT_CONFIG_CRITSEC_PRIO)
#error "BGRT_CONFIG_SCHED_PRIO must be greater or equal to BGRT_CONFIG_CRITSEC_PRIO !!!"
#endif /*BGRT_CONFIG_SCHED_PRIO*/
/*====================================================================================*/
volatile bgrt_stack_t bugurt_kernel_stack[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
/*====================================================================================*/
#define BGRT_CONTEXT_STORE() \
	__asm__ __volatile__ (               \
				"mrs r0, psp             \n\t"\
				"tst r14, #0x10          \n\t"\
				"it eq                   \n\t"\
				"vstmdbeq r0!, {s16-s31} \n\t"\
				"stmdb r0!, {r4-r11,lr}  \n\t"\
				"msr psp, r0             \n\t"\
				"dsb                     \n\t"\
				"isb                     \n\t"\
				:::)
/*====================================================================================*/
#define BGRT_CONTEXT_LOAD() \
	__asm__ __volatile__ (               \
				"mrs r0, psp             \n\t"\
				"ldmfd r0!, {r4-r11,lr}  \n\t"\
				"tst r14, #0x10          \n\t"\
				"it eq                   \n\t"\
				"vldmiaeq r0!, {s16-s31} \n\t"\
				"msr psp, r0             \n\t"\
				"dsb                     \n\t"\
				"isb                     \n\t"\
				"bx lr                   \n\t"\
				:::)
/*====================================================================================*/
static bgrt_stack_t * _read_psp(void)
{
    bgrt_stack_t * ret=0;
    __asm__ __volatile__ ("mrs %0, psp \n\t" :"=r" (ret)::);
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
bgrt_stack_t * bgrt_proc_stack_init(bgrt_stack_t * sstart, bgrt_code_t pmain, void * arg, void(*return_address)(void) )
{
    /* регистры, сохраняемые аппаратно */
    *sstart = (bgrt_stack_t)0x01000000;         /* psr */
    *(--sstart) = (bgrt_stack_t)pmain;          /* pc !!! pmain !!! */
    *(--sstart) = (bgrt_stack_t)return_address; /* lr !!! return_address !!! */
    *(--sstart) = (bgrt_stack_t)0x12;           /* r12 */
    *(--sstart) = (bgrt_stack_t)0x03;           /* r3 */
    *(--sstart) = (bgrt_stack_t)0x02;           /* r2 */
    *(--sstart) = (bgrt_stack_t)0x01;           /* r1 */
    *(--sstart) = (bgrt_stack_t)arg;            /* r0 !!! arg !!! */
    /* регистры, сохраняемые программно */
    *(--sstart) = (bgrt_stack_t)0xFFFFFFFD;     /* lr Во всех процессах будет использоваться psp */
    *(--sstart) = (bgrt_stack_t)0x11;           /* r11 */
    *(--sstart) = (bgrt_stack_t)0x10;           /* r10 */
    *(--sstart) = (bgrt_stack_t)0x09;           /* r9 */
    *(--sstart) = (bgrt_stack_t)0x08;           /* r8 */
    *(--sstart) = (bgrt_stack_t)0x07;           /* r7 */
    *(--sstart) = (bgrt_stack_t)0x06;           /* r6 */
    *(--sstart) = (bgrt_stack_t)0x05;           /* r5 */
    *(--sstart) = (bgrt_stack_t)0x04;           /* r4 */
    return sstart;
}
/*====================================================================================*/
static bgrt_stack_t * saved_sp;
static bgrt_stack_t * kernel_sp;
static bgrt_stack_t ** current_sp = &kernel_sp;
/*====================================================================================*/
static bgrt_bool_t kernel_mode = (bgrt_bool_t)1;
/*====================================================================================*/
static void bgrt_set_curr_sp(void)
{
    if (BGRT_KBLOCK.hpmap      ||
#ifdef BGRT_CONFIG_USE_VIC
        BGRT_KBLOCK.vic.list.map ||
#endif/*BGRT_CONFIG_USE_VIC*/
        BGRT_KBLOCK.lpmap)
    {
        kernel_mode = 1;
    }

    if (kernel_mode)
    {
        current_sp = &kernel_sp;
    }
    else
    {
        current_sp = &BGRT_CURR_PROC->spointer;
    }
}
/*====================================================================================*/
bgrt_proc_t * bgrt_curr_proc(void)
{
    return BGRT_CURR_PROC;
}
/*====================================================================================*/
void bgrt_resched(void)
{
    bgrt_atm_bset(&BGRT_KBLOCK.lpmap, BGRT_KBLOCK_VRESCH);
}
/*====================================================================================*/
void bgrt_init(void)
{
    __asm__ __volatile__ (
        "dsb     \n\t"
        "cpsid i \n\t"
        :::
    );
    bgrt_kernel_init();
    /* Устанавливаем начальное значение PSP, для процесса потока Ядра; */
    _write_psp((volatile bgrt_stack_t *)&bugurt_kernel_stack[32]); /* !!! Внимательно смотрим на границы!!! */
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
    __asm__ __volatile__ (
        "dsb     \n\t"
        "cpsie i \n\t"
        "isb     \n\t"
        :::
    );
    bgrt_kblock_main(&BGRT_KBLOCK);
}
/*====================================================================================*/
void BGRT_SYSTEM_TIMER_ISR(void)
{
    BGRT_ISR_START();

    bgrt_kernel.timer.val++;
    if (bgrt_kernel.timer.tick != (void (*)(void))0)bgrt_kernel.timer.tick();

    bgrt_atm_bset(&BGRT_KBLOCK.lpmap, BGRT_KBLOCK_VTMR);

    BGRT_ISR_END();
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

    kernel_mode = (bgrt_bool_t)0;

    BGRT_SYS_ICSR |= BGRT_PENDSV_SET;
    BGRT_INT_FREE();
}
/*====================================================================================*/
__attribute__ ((naked)) void BGRT_SYSCALL_ISR(void)
{
    BGRT_CONTEXT_STORE();
    saved_sp = _read_psp();
    *current_sp = saved_sp;

    bgrt_set_curr_sp();

    BGRT_SYS_ICSR |= BGRT_PENDSV_CLR; /* Fix for a hardware race condition. */

    _write_psp(*current_sp);
    BGRT_CONTEXT_LOAD();
}
