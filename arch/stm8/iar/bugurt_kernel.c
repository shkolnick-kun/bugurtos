/**************************************************************************
    BuguRTOS-0.3.x(Bugurt real time operating system)
    Copyright (C) 2011  anonimous

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
#include"bugurt_kernel.h"

#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
#define BGRT_INT_PTR unsigned long
#else
#define BGRT_INT_PTR unsigned short
#endif

stack_t * proc_stack_init( stack_t * stack_top, code_t code, void * arg){
     // return address (func)
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)code) & 0xFF);
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)code>>8)& 0xFF);
#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)code>>16)& 0xFF);
#else
     *stack_top-- = 0x00;
#endif
     // Y
     *stack_top-- = 0xAD;
     *stack_top-- = 0xDE;

#if (__DATA_MODEL__==__LARGE_DATA_MODEL__)
     *stack_top-- = 0xAF;
     *stack_top-- = 0xBE;
#else // __SMALL_DATA_MODEL__ or __MEDIUM_DATA_MODEL__
     // X - 1st argument is placed in X
     *stack_top-- = (stack_t)((unsigned short)arg & 0xFF);
     *stack_top-- = (stack_t)(((unsigned short)arg>>8)& 0xFF);
#endif
     // A
     *stack_top-- = 0xAA;
     // CCR
     *stack_top-- = 0x20; //Interrupts are enabled
     // b0...b7
     // Compiler saves them in order: b3,b2,b1,b0 ,b7,b6,b5,b4, sort of optimization I think.
#if (__DATA_MODEL__==__LARGE_DATA_MODEL__)
     *stack_top-- = (stack_t)((BGRT_INT_PTR)arg & 0xFF);
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)arg>>8)& 0xFF);
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)arg>>16)& 0xFF);
#else // __SMALL_DATA_MODEL__ or __MEDIUM_DATA_MODEL__
     *stack_top-- = 0xB3;
     *stack_top-- = 0xB2;
     *stack_top-- = 0xB1;
#endif
     *stack_top-- = 0xB0;
     // b4...b7
     *stack_top-- = 0xB7;
     *stack_top-- = 0xB6;
     *stack_top-- = 0xB5;
     *stack_top-- = 0xB4;
     // b8...b11
     *stack_top-- = 0xBB;
     *stack_top-- = 0xBA;
     *stack_top-- = 0xB9;
     *stack_top-- = 0xB8;
     //b12...b15
     *stack_top-- = 0xBF;
     *stack_top-- = 0xBE;
     *stack_top-- = 0xBD;
     *stack_top-- = 0xBC;

     return stack_top;
}

// Платформеннозависимый код
// Просто функции, специфичные для AVR
proc_t * current_proc(void)
{
    return kernel.sched.current_proc;
}

/******************************************************************************************************/
// Код ядра

// Состояние ядра, выполняем перепланиировку
unsigned char kernel_state = KRN_FLG_RESCHED;
// Функция перепланировки
void resched( void )
{
    kernel_state |= KRN_FLG_RESCHED;
}
/*
  Перепланировка при необхродимости,
в случае использования системных вызовов
на основе программного прерывания -
- проверка на гонки с прерыванием системного вызова.
*/
void bugurt_check_resched( void )
{
    if( kernel_state & KRN_FLG_RESCHED )
    {
        kernel_state &= ~KRN_FLG_RESCHED;
        sched_reschedule();
    }
}
#pragma vector = SYSTEM_TIMER_VECTOR
__interrupt void system_timer_isr(void)
{
    kernel.sched.current_proc->spointer = bugurt_save_context();
    bugurt_set_stack_pointer( kernel.idle.spointer );

    SYSTEM_TIMER_INTERRUPT_CLEAR();

    kernel.timer++;
    if( kernel.timer_tick != (void (*)(void))0 ) kernel.timer_tick();
    sched_schedule();

    bugurt_restore_context( kernel.sched.current_proc->spointer );
}

static stack_t * proc_stack;
#pragma vector = 1 // trap insrtuction vector!
__interrupt  void system_call_handler(void)
{

    proc_stack = bugurt_save_context();
    kernel.sched.current_proc->spointer = proc_stack;
    bugurt_set_stack_pointer( kernel.idle.spointer );


    // Set interrupt flags in saved CCR
    proc_stack[17] |= MASK_CPU_CCR_I1;
    proc_stack[17] &= ~MASK_CPU_CCR_I0;

    // Set system call params
    syscall_num = proc_stack[18];

#if (__DATA_MODEL__==__LARGE_DATA_MODEL__)
    syscall_arg = (void *)(((unsigned long)proc_stack[16]) | (((unsigned long)proc_stack[15])<<8) | (((unsigned long)proc_stack[14])<<16));
#else // __SMALL_DATA_MODEL__ or __MEDIUM_DATA_MODEL__
    syscall_arg = (void *)(((unsigned short)proc_stack[19]<<8) | (((unsigned short)proc_stack[20])));
#endif

    // Обрабатываем системный вызов
    do_syscall();

    // Перепланировка при необходимости
    if( kernel_state & KRN_FLG_RESCHED )
    {
        kernel_state &= ~KRN_FLG_RESCHED;
        sched_reschedule();
    }
    bugurt_restore_context( kernel.sched.current_proc->spointer );
}

/***************************************************************************************************************/
// Функции общего пользования

void init_bugurt(void)
{
    disable_interrupts();
    kernel.sched.nested_crit_sec = (count_t)1;
    kernel_init();
}
void start_bugurt(void)
{
    kernel.sched.nested_crit_sec = (count_t)0;
    enable_interrupts();
    idle_main( (void *)0 );
}
