/**************************************************************************
    BuguRTOS-0.7.x(Bugurt real time operating system)
    Copyright (C) 2014  anonimous

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
#ifndef CONFIG_PRIO_BITS
#error "You must define CONFIG_PRIO_BITS macro!!!"
#endif //CONFIG_PRIO_BITS

#if (CONFIG_SYSCALL_PRIO < CONFIG_SCHED_PRIO)
#error "CONFIG_SYSCALL_PRIO must be greater or equal to CONFIG_SCHED_PRIO !!!"
#endif //CONFIG_SYSCALL_PRIO
//====================================================================================
volatile stack_t bugurt_idle_stack[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//====================================================================================
#define BUGURT_SCHED_ENTER() \
	__asm__ __volatile__ ( 							 \
				"MRS r0, psp					\n\t"\
				"SUB r0, r0, #36                \n\t"\
				"MSR psp, r0					\n\t"\
				"STMIA r0!, {r4-r7}			    \n\t"\
				"MOV r3, r8						\n\t"\
				"MOV r4, r9						\n\t"\
				"MOV r5, r10				    \n\t"\
				"MOV r6, r11					\n\t"\
				"MOV r7, lr	  				    \n\t"\
				"STMIA r0!, {r3-r7}			    \n\t"\
				::: )
//====================================================================================
#define BUGURT_SCHED_EXIT() \
	__asm__ __volatile__ (						 	 \
				"MRS r1, psp					\n\t"\
				"MOV r0, r1                     \n\t"\
				"ADD r0, r0, #16                \n\t"\
				"LDMIA r0!, {r3-r7}  			\n\t"\
				"MOV r8,  r3				    \n\t"\
				"MOV r9,  r4				    \n\t"\
				"MOV r10, r5				    \n\t"\
				"MOV r11, r6					\n\t"\
				"MOV lr,  r7	  				\n\t"\
				"LDMIA r1!, {r4-r7}  			\n\t"\
				"MSR psp, r0					\n\t"\
				"bx lr							\n\t"\
				::: )
//====================================================================================
static stack_t * bugurt_read_psp(void)
{
    stack_t * ret=0;
    __asm__ __volatile__ ("MRS %0, psp\n\t" : "=r" (ret) );
    return(ret);
}
//====================================================================================
static void bugurt_write_psp( volatile stack_t * ptr )
{
    __asm__ __volatile__ ("MSR psp, %0\n\t" : : "r" (ptr) );
}
//====================================================================================
stack_t * proc_stack_init( stack_t * sstart, code_t pmain, void * arg, void(*return_address)(void)  )
{
    // регистры, сохраняемые аппаратно
    *sstart = (stack_t)0x01000000;		// psr
    *(--sstart) = (stack_t)pmain;		   	// pc !!! pmain !!!
    *(--sstart) = (stack_t)return_address; 	// lr !!! return_address !!!
    *(--sstart) = (stack_t)0x12;			// r12
    *(--sstart) = (stack_t)0x03;			// r3
    *(--sstart) = (stack_t)0x02;			// r2
    *(--sstart) = (stack_t)0x01;			// r1
    *(--sstart) = (stack_t)arg;				// r0 !!! arg !!!
    // регистры, сохраняемые программно
    *(--sstart) = (stack_t)0xFFFFFFFD;		// lr Во всех процессах, кроме idle будет использоваться psp
    *(--sstart) = (stack_t)0x11;			// r11
    *(--sstart) = (stack_t)0x10;			// r10
    *(--sstart) = (stack_t)0x09;			// r9
    *(--sstart) = (stack_t)0x08;			// r8
    *(--sstart) = (stack_t)0x07;			// r7
    *(--sstart) = (stack_t)0x06;			// r6
    *(--sstart) = (stack_t)0x05;			// r5
    *(--sstart) = (stack_t)0x04;			// r4
    return sstart;
}
//====================================================================================
volatile unsigned char resched_flag = 0;
void resched(void)
{
    resched_flag = 1;
    BUGURT_SYS_ICSR |= BUGURT_PENDSV_SET;
}
//====================================================================================
void disable_interrupts(void)
{
    __asm__ __volatile__ ("cpsid i \n\t");
}
//====================================================================================
void enable_interrupts(void)
{
    __asm__ __volatile__ ("cpsie i \n\t");
}
//====================================================================================
proc_t * current_proc(void)
{
    return kernel.sched.current_proc;
}
//====================================================================================
void init_bugurt(void)
{
    __asm__ __volatile__ ("cpsid i \n\t");
    kernel_init();
    kernel.sched.nested_crit_sec = (count_t)1;// Только после инициализации Ядра!!!
    // Устанавливаем начальное значение PSP, для процесса idle;
    bugurt_write_psp( (volatile stack_t *)&bugurt_idle_stack[16] ); //  !!! Внимательно смотрим на границы!!!
    // Устанавливаем приоритеты обработчиков прерываний;
    BUGURT_SYS_SHPR3 |= (CONFIG_SCHED_PRIO  << ( 8 - CONFIG_PRIO_BITS )) << 16; // PendSV
}
//====================================================================================
void start_bugurt(void)
{
    kernel.sched.nested_crit_sec = (count_t)0;
    __asm__ __volatile__ ("cpsie i \n\t");
    idle_main((void *)0);
}
//====================================================================================
void syscall_bugurt( syscall_t num, void * arg )
{
    disable_interrupts();
    syscall_num = num;
    syscall_arg = arg;
    BUGURT_SYS_ICSR |= BUGURT_PENDSV_SET;
    enable_interrupts();
}
//====================================================================================
volatile unsigned char systimer_flag = 0;
void SYSTEM_TIMER_ISR(void)
{
    disable_interrupts();

    kernel.timer++;
    if( kernel.timer_tick != (void (*)(void))0 ) kernel.timer_tick();

    systimer_flag = 1;
    BUGURT_SYS_ICSR |= BUGURT_PENDSV_SET;

    enable_interrupts();
}
//====================================================================================
__attribute__ (( naked )) void SYSCALL_ISR(void)
{
    BUGURT_SCHED_ENTER();
    kernel.sched.current_proc->spointer = bugurt_read_psp();
    disable_interrupts();

    // Обрабатываем системный вызов
    do_syscall();

    KERNEL_PREEMPT();

    if( resched_flag )
    {
        resched_flag = 0;
        sched_reschedule();
    }

    KERNEL_PREEMPT();

    if( systimer_flag )
    {
        systimer_flag = 0;
        sched_schedule();
    }

    KERNEL_PREEMPT();

    BUGURT_SYS_ICSR |= BUGURT_PENDSV_CLR; // Fix for a hardware race condition.

    enable_interrupts();
    bugurt_write_psp( kernel.sched.current_proc->spointer );
    BUGURT_SCHED_EXIT();
}
//====================================================================================
