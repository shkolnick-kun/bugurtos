/**************************************************************************
    BuguRTOS-0.8.x (Bugurt real time operating system)
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

#include <bugurt.h>

//====================================================================================
#define BUGURT_SYS_ICSR 	*(( volatile unsigned long *) 0xE000ED04 )
//#define BUGURT_SYS_SCR 		*(( volatile unsigned long *) 0xE000ED10 )
//#define BUGURT_SYS_CCR 		*(( volatile unsigned long *) 0xE000ED14 )

//#define BUGURT_SYS_SHPR1 	*(( volatile unsigned long *) 0xE000ED18 )
#define BUGURT_SYS_SHPR2 	*(( volatile unsigned long *) 0xE000ED1C )
#define BUGURT_SYS_SHPR3 	*(( volatile unsigned long *) 0xE000ED20 )
//#define BUGURT_SYS_SHCRS 	*(( volatile unsigned long *) 0xE000ED24 )
//#define BUGURT_SYS_CFSR 	*(( volatile unsigned long *) 0xE000ED28 )
#define BUGURT_SYS_CPACR 	*(( volatile unsigned long *) 0xE000ED88 )

#define BUGURT_SYST_CSR 	*(( volatile unsigned long *) 0xE000E010 )
#define BUGURT_SYST_RVR 	*(( volatile unsigned long *) 0xE000E014 )



#define BUGURT_SYST_RVR_VALUE ( ( BGRT_CONFIG_FCPU_HZ / BGRT_CONFIG_FSYSTICK_HZ ) - 1ul )
#define BUGURT_SYST_CSR_VALUE ( 0x00000007 ) //Enable clock, interrupt, timer.

#define BUGURT_PENDSV_SET   (0x10000000)
#define BUGURT_PENDSV_CLR   (0x08000000)
#define BUGURT_FPU_ENABLE   (0x00f00000)

//====================================================================================
#ifndef __VFP_FP__
#error "THis works only on FPU enabled devices (Cotrex(tm)-M4F)!!!"
#endif

#ifndef BGRT_CONFIG_FCPU_HZ
#error "You must define BGRT_CONFIG_FCPU_HZ macro!!!"
#endif //BGRT_CONFIG_FCPU_HZ

#ifndef BGRT_CONFIG_FSYSTICK_HZ
#error "You must define BGRT_CONFIG_FSYSTICK_HZ macro!!!"
#endif //BGRT_CONFIG_FSYSTICK_HZ

#if BUGURT_SYST_RVR_VALUE > 0xFFFFFFUL
#error "Impossible SYST_RVR value!!! "
#endif //BUGURT_SYST_RVR_VALUE

#ifndef BGRT_CONFIG_PRIO_BITS
#error "You must define BGRT_CONFIG_PRIO_BITS macro!!!"
#endif //BGRT_CONFIG_PRIO_BITS

#if (BGRT_CONFIG_CRITSEC_PRIO <= BGRT_CONFIG_SYSCALL_PRIO)
#error "BGRT_CONFIG_SYSCALL_PRIO must be less than BGRT_CONFIG_CRITSEC_PRIO !!!"
#endif //BGRT_CONFIG_CRITSEC_PRIO

#if (BGRT_CONFIG_SCHED_PRIO < BGRT_CONFIG_CRITSEC_PRIO)
#error "BGRT_CONFIG_SCHED_PRIO must be greater or equal to BGRT_CONFIG_CRITSEC_PRIO !!!"
#endif //BGRT_CONFIG_SCHED_PRIO
//====================================================================================
volatile bgrt_stack_t bugurt_idle_stack[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//====================================================================================
#define BUGURT_SCHED_ENTER() \
	__asm__ __volatile__ ( 							 \
				"mrs r0, psp                    \n\t"\
				"tst r14, #0x10                 \n\t"\
				"it eq                          \n\t"\
				"vstmdbeq r0!, {s16-s31}        \n\t"\
				"stmdb r0!, {r4-r11,lr}         \n\t"\
				"msr psp, r0                    \n\t"\
				"dsb        					\n\t"\
				"isb        					\n\t"\
				::: )
//====================================================================================
#define BUGURT_SCHED_EXIT() \
	__asm__ __volatile__ (						 	 \
				"mrs r0, psp                    \n\t"\
				"ldmfd r0!, {r4-r11,lr}			\n\t"\
				"tst r14, #0x10                 \n\t"\
				"it eq                          \n\t"\
				"vldmiaeq r0!, {s16-s31}		\n\t"\
				"msr psp, r0                    \n\t"\
				"dsb        					\n\t"\
				"isb        					\n\t"\
				"bx lr                          \n\t"\
				::: )
//====================================================================================
static bgrt_stack_t * bugurt_read_psp(void)
{
    bgrt_stack_t * ret=0;
    __asm__ __volatile__ ("mrs %0, psp\n\t" : "=r" (ret) );
    return(ret);
}
//====================================================================================
static void bugurt_write_psp( volatile bgrt_stack_t * ptr )
{
    __asm__ __volatile__ (
                          "msr psp, %0\n\t"
                          "dsb \n\t"
                          "isb \n\t"
                          : : "r" (ptr) );
}
//====================================================================================
bgrt_stack_t * bgrt_proc_stack_init( bgrt_stack_t * sstart, bgrt_code_t pmain, void * arg, void(*return_address)(void)  )
{
    // регистры, сохраняемые аппаратно
    *sstart = (bgrt_stack_t)0x01000000;		// psr
    *(--sstart) = (bgrt_stack_t)pmain;		   	// pc !!! pmain !!!
    *(--sstart) = (bgrt_stack_t)return_address; 	// lr !!! return_address !!!
    *(--sstart) = (bgrt_stack_t)0x12;			// r12
    *(--sstart) = (bgrt_stack_t)0x03;			// r3
    *(--sstart) = (bgrt_stack_t)0x02;			// r2
    *(--sstart) = (bgrt_stack_t)0x01;			// r1
    *(--sstart) = (bgrt_stack_t)arg;				// r0 !!! arg !!!
    // регистры, сохраняемые программно
    *(--sstart) = (bgrt_stack_t)0xFFFFFFFD;		// lr Во всех процессах, кроме idle будет использоваться psp
    *(--sstart) = (bgrt_stack_t)0x11;			// r11
    *(--sstart) = (bgrt_stack_t)0x10;			// r10
    *(--sstart) = (bgrt_stack_t)0x09;			// r9
    *(--sstart) = (bgrt_stack_t)0x08;			// r8
    *(--sstart) = (bgrt_stack_t)0x07;			// r7
    *(--sstart) = (bgrt_stack_t)0x06;			// r6
    *(--sstart) = (bgrt_stack_t)0x05;			// r5
    *(--sstart) = (bgrt_stack_t)0x04;			// r4
    return sstart;
}
//====================================================================================
void bgrt_resched(void)
{
    BUGURT_SYS_ICSR |= BUGURT_PENDSV_SET;
}
//====================================================================================
void bgrt_disable_interrupts(void)
{
    __asm__ __volatile__ (
                          "mov r0, %0      \n\t"
                          "msr basepri, r0 \n\t"
                          "dsb             \n\t"
                          "isb             \n\t"
                          :
                          : "i" ( BGRT_CONFIG_CRITSEC_PRIO << ( 8 - BGRT_CONFIG_PRIO_BITS ) )
                          : "r0"
                          );
}
//====================================================================================
void bgrt_enable_interrupts(void)
{
    __asm__ __volatile__ (
                          "mov r0, #0      \n\t"
                          "msr basepri, r0  \n\t"
                          "dsb             \n\t"
                          "isb             \n\t"
                          :
                          :
                          : "r0"
                          );
}
//====================================================================================
bgrt_proc_t * bgrt_curr_proc(void)
{
    return bgrt_kernel.sched.current_proc;
}
//====================================================================================
void bgrt_init(void)
{
    __asm__ __volatile__ (
                          "dsb     \n\t"
                          "cpsid i \n\t"
                          );
    BUGURT_SYS_CPACR |= BUGURT_FPU_ENABLE;

    bgrt_kernel_init();
    bgrt_kernel.sched.nested_crit_sec = (bgrt_cnt_t)1;// Только после инициализации Ядра!!!
    // Устанавливаем начальное значение PSP, для процесса idle;
    bugurt_write_psp( (volatile bgrt_stack_t *)&bugurt_idle_stack[32] ); //  !!! Внимательно смотрим на границы!!!
    // Устанавливаем приоритеты обработчиков прерываний;
    BUGURT_SYS_SHPR2 |= (BGRT_CONFIG_SYSCALL_PRIO<< ( 8 - BGRT_CONFIG_PRIO_BITS )) << 24; // SVC
    BUGURT_SYS_SHPR3 |= (BGRT_CONFIG_SCHED_PRIO  << ( 8 - BGRT_CONFIG_PRIO_BITS )) << 16; // PendSV
    BUGURT_SYS_SHPR3 |= (BGRT_CONFIG_SCHED_PRIO  << ( 8 - BGRT_CONFIG_PRIO_BITS )) << 24; // SysTick
    // Настраиваем системный таймер и приоритет его прерывания
    BUGURT_SYST_RVR = BUGURT_SYST_RVR_VALUE;
	BUGURT_SYST_CSR = BUGURT_SYST_CSR_VALUE;

}
//====================================================================================
void bgrt_start(void)
{
    bgrt_kernel.sched.nested_crit_sec = (bgrt_cnt_t)0;
    __asm__ __volatile__ (
                          "dsb     \n\t"
                          "cpsie i \n\t"
                          "isb     \n\t"
                          );
    bgrt_idle_main((void *)0);
}
//====================================================================================
__attribute__ (( naked )) void BGRT_SYSTEM_TIMER_ISR(void)
{
    BUGURT_SCHED_ENTER();
    bgrt_kernel.sched.current_proc->spointer = bugurt_read_psp();

    bgrt_disable_interrupts();

    bgrt_kernel.timer++;
    if( bgrt_kernel.timer_tick != (void (*)(void))0 ) bgrt_kernel.timer_tick();

    BGRT_KERNEL_PREEMPT(); ///BGRT_KERNEL_PREEMPT

    bgrt_sched_schedule();

    bgrt_enable_interrupts();

    bugurt_write_psp( bgrt_kernel.sched.current_proc->spointer );
    BUGURT_SCHED_EXIT();
}
//====================================================================================
__attribute__ (( naked )) void BGRT_RESCHED_ISR(void)
{
    BUGURT_SCHED_ENTER();
    bgrt_kernel.sched.current_proc->spointer = bugurt_read_psp();

    bgrt_disable_interrupts();

    bgrt_sched_reschedule();
    BUGURT_SYS_ICSR |= BUGURT_PENDSV_CLR; // Fix for a hardware race condition.

    bgrt_enable_interrupts();

    bugurt_write_psp( bgrt_kernel.sched.current_proc->spointer );
    BUGURT_SCHED_EXIT();
}
//====================================================================================
//In single processor system call reentrancy is not necessary.
bgrt_syscall_t syscall_num = (bgrt_syscall_t)0;
void * syscall_arg = (void *)0;
//====================================================================================
void bgrt_syscall( bgrt_syscall_t num, void * arg )
{
    bgrt_disable_interrupts();
    syscall_num = num;
    syscall_arg = arg;
    __asm__ __volatile__ (
                          "dsb   \n\t"
                          "svc 0 \n\t"
                          );
    bgrt_enable_interrupts();
}
//====================================================================================
void BGRT_SYSCALL_ISR(void)
{
    // Обрабатываем системный вызов
    bgrt_do_syscall(syscall_num, syscall_arg);
    syscall_num = 0; // Готово.
}
