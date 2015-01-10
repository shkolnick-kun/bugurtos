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

// Подстановка_строки
#define BUGURT_ARG_TO_STR(a) #a
// Конкатенация строк
#define BUGURT_CONCAT(a,b) a##b

#ifndef CONFIG_PREEMPTIVE_KERNEL

// Пролог обработчика прерывания
#define BUGURT_ISR_START() \
    _bugurt_do_it(); \
    kernel.sched.current_proc->spointer = (stack_t *)_getSP_();\
   _setSP_( (unsigned int)kernel.idle.spointer )

// Выход из обработчика прерывания, восстановление контекста текущего процесса
#define BUGURT_ISR_EXIT() \
    _setSP_( (unsigned int)kernel.sched.current_proc->spointer )

// Эпилог обработчика прерывания
#define BUGURT_ISR_END() \
    bugurt_check_resched();\
    BUGURT_ISR_EXIT()

#else // CONFIG_PREEMPTIVE_KERNEL

// Пролог обработчика прерывания
/// NOTE: No KERNEL_PREEMPT() call on the end of prologue to avoid ISR reentrance!
#define BUGURT_ISR_START() \
    _bugurt_do_it(); \
    saved_sp = (stack_t *)_getSP_();\
    if( nested_interrupts ) goto  skip_stack_switch;\
    kernel.sched.current_proc->spointer = saved_sp;\
    STOP_SCHEDULER();\
    _setSP_( (unsigned int)kernel.idle.spointer );\
skip_stack_switch:\
    nested_interrupts++

// Выход из обработчика прерывания, восстановление контекста текущего процесса
#define BUGURT_ISR_EXIT() \
    KERNEL_PREEMPT();\
    nested_interrupts--;\
    if( nested_interrupts )goto exit_nested;\
    START_SCHEDULER();\
    _setSP_( (unsigned int)kernel.sched.current_proc->spointer );\
exit_nested: \

// Эпилог обработчика прерывания
#define BUGURT_ISR_END() \
    KERNEL_PREEMPT();\
    nested_interrupts--;\
    if( nested_interrupts )goto exit_nested;\
    bugurt_check_resched();\
    START_SCHEDULER();\
    _setSP_( (unsigned int)kernel.sched.current_proc->spointer );\
exit_nested: \

#endif // CONFIG_PREEMPTIVE_KERNEL

/*
Объявление обработчика прерывания.

Обработка прерываний происходит в контексте main,
он же контекст процесса холостого хода.

Не очень быстро,
зато память экономится.
*/
#define BUGURT_INTERRUPT(v) \
void BUGURT_CONCAT(vector_func_,v)(void);\
void BUGURT_CONCAT(vector_wrapper_,v)(void) interrupt v \
{ \
    BUGURT_ISR_START();\
    BUGURT_CONCAT(vector_func_,v)();\
    BUGURT_ISR_END();\
} \
void BUGURT_CONCAT(vector_func_,v)(void)

// Флаги состояния ядра
#define KRN_FLG_RESCHED ((unsigned char)1)

extern unsigned char kernel_state;
extern stack_t * saved_sp;
extern void (*_bugurt_do_it)(void); /// NEEDED TO MAKE PROPER ISR PROLOGUES/EPILOGUES !
#ifdef CONFIG_PREEMPTIVE_KERNEL
extern count_t nested_interrupts;
#endif // CONFIG_PREEMPTIVE_KERNEL

void _bugurt_do_nothing( void ); /// NEEDED TO MAKE PROPER ISR PROLOGUES/EPILOGUES !

void bugurt_check_resched( void );

extern stack_t * bugurt_save_context( void );
extern void bugurt_restore_context( stack_t * new_sp );
extern void bugurt_pop_context( void );
extern void bugurt_set_stack_pointer( stack_t * new_sp );

#endif // _BUGURT_KERNEL_H_
