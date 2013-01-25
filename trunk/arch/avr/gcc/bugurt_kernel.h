/**************************************************************************
    BuguRTOS-0.5.x(Bugurt real time operating system)
    Copyright (C) 2013  anonimous

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
#ifndef _BUGURT_KERNEL_H_
#define _BUGURT_KERNEL_H_

#include"../../../include/bugurt.h"

// Конкатенация строк
#define BUGURT_CONCAT(a,b) a##b

// Пролог обработчика прерывания
///                         АХТУНГ !!!
/// Используется переменная saved_sp для временного хранения
/// указателя стека прерываемого процесса, если так не делать,
/// компилятор будет стирать r16, r17 до сохранения контекста.
#ifndef CONFIG_PREEMPTIVE_KERNEL

// Пролог обработчика прерывания
#define BUGURT_ISR_START() \
    saved_sp = bugurt_save_context();\
    kernel.sched.current_proc->spointer = saved_sp;\
    bugurt_set_stack_pointer( kernel.idle.spointer )
// Выход из обработчика прерывания, восстановление контекста текущего процесса
#define BUGURT_ISR_EXIT() \
    bugurt_restore_context( kernel.sched.current_proc->spointer );\
    __asm__ __volatile__("reti"::)

// Эпилог обработчика прерывания
#define BUGURT_ISR_END() \
    bugurt_check_resched();\
    BUGURT_ISR_EXIT()

#else // CONFIG_PREEMPTIVE_KERNEL

// Пролог обработчика прерывания
#define BUGURT_ISR_START() \
    saved_sp = bugurt_save_context();\
    if( nested_interrupts ) goto  skip_stack_switch;\
    kernel.sched.current_proc->spointer = saved_sp;\
    STOP_SCHEDULER();\
    bugurt_set_stack_pointer( kernel.idle.spointer );\
skip_stack_switch:\
    nested_interrupts++;\
    KERNEL_PREEMPT()


// Выход из обработчика прерывания
#define BUGURT_ISR_EXIT() \
    KERNEL_PREEMPT();\
    nested_interrupts--;\
    if( nested_interrupts )goto exit_nested;\
    START_SCHEDULER();\
    bugurt_restore_context( kernel.sched.current_proc->spointer );\
    __asm__ __volatile__("reti"::); \
exit_nested: \
    bugurt_pop_context();\
    __asm__ __volatile__("reti"::)

// Эпилог обработчика прерывания, отличается от BUGURT_ISR_EXIT вызовом bugurt_check_resched
#define BUGURT_ISR_END() \
    KERNEL_PREEMPT();\
    nested_interrupts--;\
    if( nested_interrupts )goto exit_nested;\
    bugurt_check_resched();\
    START_SCHEDULER();\
    bugurt_restore_context( kernel.sched.current_proc->spointer );\
    __asm__ __volatile__("reti"::); \
exit_nested: \
    bugurt_pop_context();\
    __asm__ __volatile__("reti"::)

#endif // CONFIG_PREEMPTIVE_KERNEL

// Шаблон обработчика прерывания для внутреннего пользования
#define _BUGURT_ISR(v,f) \
__attribute__ (( signal, naked )) void v(void); \
void v(void) \
{ \
    BUGURT_ISR_START();\
    f();\
    BUGURT_ISR_END();\
} \

/*
Объявление обработчика прерывания.

Обработка прерываний происходит в контексте main,
он же контекст процесса холостого хода.

Не очень быстро,
зато память экономится.
*/
#define BUGURT_INTERRUPT(v) \
void BUGURT_CONCAT(v,_func)(void);\
_BUGURT_ISR(v,BUGURT_CONCAT(v,_func)) \
void BUGURT_CONCAT(v,_func)(void)

// Флаги состояния ядра
#define KRN_FLG_RESCHED ((unsigned char)1)

#ifdef SYSCALL_ISR
#define KRN_FLG_DO_SCALL ((unsigned char)2)
#endif // SYSCALL_ISR

unsigned char kernel_state;
//Временное хранилище для указателей стеков процессов.
stack_t * saved_sp;
#ifdef CONFIG_PREEMPTIVE_KERNEL
count_t nested_interrupts;
#endif //CONFIG_PREEMPTIVE_KERNEL

//Внешние функции, специфичные для AVR
#ifdef SYSCALL_ISR
extern void raise_syscall_interrupt(void);
#endif

void bugurt_check_resched( void );

extern stack_t * bugurt_save_context( void );
extern void bugurt_restore_context( stack_t * new_sp );
extern void bugurt_pop_context( void );
extern void bugurt_set_stack_pointer( stack_t * new_sp );
extern stack_t * bugurt_reverse_byte_order ( stack_t * arg );

#endif // _BUGURT_KERNEL_H_
