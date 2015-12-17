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

#define BUGURT_SYS_SHPR3 	*(( volatile unsigned long *) 0xE000ED20 )

#define BUGURT_PENDSV_SET   (0x10000000)
#define BUGURT_PENDSV_CLR   (0x08000000)

//====================================================================================
#ifndef BGRT_CONFIG_PRIO_BITS
#error "You must define BGRT_CONFIG_PRIO_BITS macro!!!"
#endif //BGRT_CONFIG_PRIO_BITS

#if (BGRT_CONFIG_SYSCALL_PRIO < BGRT_CONFIG_SCHED_PRIO)
#error "BGRT_CONFIG_SYSCALL_PRIO must be greater or equal to BGRT_CONFIG_SCHED_PRIO !!!"
#endif //BGRT_CONFIG_SYSCALL_PRIO
//====================================================================================
volatile bgrt_stack_t bugurt_idle_stack[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//====================================================================================
#define BUGURT_SCHED_ENTER() \
	__asm__ __volatile__ ( 							 \
				"mrs r0, psp					\n\t"\
				"sub r0, r0, #36                \n\t"\
				"msr psp, r0					\n\t"\
				"stmia r0!, {r4-r7}			    \n\t"\
				"mov r3, r8						\n\t"\
				"mov r4, r9						\n\t"\
				"mov r5, r10				    \n\t"\
				"mov r6, r11					\n\t"\
				"mov r7, lr	  				    \n\t"\
				"stmia r0!, {r3-r7}			    \n\t"\
				"dsb			                \n\t"\
				::: )
//====================================================================================
#define BUGURT_SCHED_EXIT() \
	__asm__ __volatile__ (						 	 \
				"mrs r1, psp					\n\t"\
				"mov r0, r1                     \n\t"\
				"add r0, r0, #16                \n\t"\
				"ldmia r0!, {r3-r7}  			\n\t"\
				"mov r8,  r3				    \n\t"\
				"mov r9,  r4				    \n\t"\
				"mov r10, r5				    \n\t"\
				"mov r11, r6					\n\t"\
				"mov lr,  r7	  				\n\t"\
				"ldmia r1!, {r4-r7}  			\n\t"\
				"msr psp, r0					\n\t"\
				"dsb			                \n\t"\
				"isb			                \n\t"\
				"bx lr							\n\t"\
				::: )
//====================================================================================
static bgrt_stack_t * bugurt_read_psp(void)
{
    bgrt_stack_t * ret=0;
    __asm__ __volatile__ ( "mrs %0, psp\n\t" : "=r" (ret) );
    return(ret);
}
//====================================================================================
static void bugurt_write_psp( volatile bgrt_stack_t * ptr )
{
    __asm__ __volatile__ (
                          "msr psp, %0\n\t"
                          "dsb \n\t"
                          "isb \n\t"
                          : : "r" (ptr)
                          );
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
volatile unsigned char resched_flag = 0;
void bgrt_resched(void)
{
    resched_flag = 1;
    BUGURT_SYS_ICSR |= BUGURT_PENDSV_SET;
}
//====================================================================================
void bgrt_disable_interrupts(void)
{
    __asm__ __volatile__ (
                          "dsb \n\t"
                          "cpsid i \n\t"
                          );
}
//====================================================================================
void bgrt_enable_interrupts(void)
{
    __asm__ __volatile__ (
                          "dsb \n\t"
                          "cpsie i \n\t"
                          "isb \n\t"
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
                          "dsb \n\t"
                          "cpsid i \n\t"
                          );
    bgrt_kernel_init();
    bgrt_kernel.sched.nested_crit_sec = (bgrt_cnt_t)1;// Только после инициализации Ядра!!!
    // Устанавливаем начальное значение PSP, для процесса idle;
    bugurt_write_psp( (volatile bgrt_stack_t *)&bugurt_idle_stack[16] ); //  !!! Внимательно смотрим на границы!!!
    // Устанавливаем приоритеты обработчиков прерываний;
    BUGURT_SYS_SHPR3 |= (BGRT_CONFIG_SCHED_PRIO  << ( 8 - BGRT_CONFIG_PRIO_BITS )) << 16; // PendSV
}
//====================================================================================
void bgrt_start(void)
{
    bgrt_kernel.sched.nested_crit_sec = (bgrt_cnt_t)0;
    __asm__ __volatile__ (
                          "dsb \n\t"
                          "cpsie i \n\t"
                          "isb \n\t"
                          );
    BGRT_POST_START((void *)0);
}
//====================================================================================
volatile unsigned char systimer_flag = 0;
void BGRT_SYSTEM_TIMER_ISR(void)
{
    bgrt_disable_interrupts();

    bgrt_kernel.timer++;
    if( bgrt_kernel.timer_tick != (void (*)(void))0 ) bgrt_kernel.timer_tick();

    systimer_flag = 1;
    BUGURT_SYS_ICSR |= BUGURT_PENDSV_SET;

    bgrt_enable_interrupts();
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
    BUGURT_SYS_ICSR |= BUGURT_PENDSV_SET;
    bgrt_enable_interrupts();
}
//====================================================================================
__attribute__ (( naked )) void BGRT_SYSCALL_ISR(void)
{
    BUGURT_SCHED_ENTER();
    bgrt_kernel.sched.current_proc->spointer = bugurt_read_psp();
    bgrt_disable_interrupts();

    // Обрабатываем системный вызов
    bgrt_do_syscall(syscall_num, syscall_arg);
    syscall_num = 0; // Готово.

    BGRT_KERNEL_PREEMPT();

    if( resched_flag )
    {
        resched_flag = 0;
        bgrt_sched_reschedule();
    }

    BGRT_KERNEL_PREEMPT();

    if( systimer_flag )
    {
        systimer_flag = 0;
        bgrt_sched_schedule();
    }

    BGRT_KERNEL_PREEMPT();

    BUGURT_SYS_ICSR |= BUGURT_PENDSV_CLR; // Fix for a hardware race condition.

    bgrt_enable_interrupts();
    bugurt_write_psp( bgrt_kernel.sched.current_proc->spointer );
    BUGURT_SCHED_EXIT();
}
//====================================================================================
