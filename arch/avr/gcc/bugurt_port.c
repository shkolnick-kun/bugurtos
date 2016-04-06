/**************************************************************************
    BuguRTOS-0.9.x (Bugurt real time operating system)
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

// Платформозависимый код
// Просто функции, специфичные для AVR

void bgrt_disable_interrupts(void)
{
    cli();
}
void bgrt_enable_interrupts(void)
{
    sei();
}

bgrt_proc_t * bgrt_curr_proc(void)
{
    return bgrt_kernel.sched.current_proc;
}

/******************************************************************************************************/
// Код ядра

// Состояние ядра, выполняем перепланировку
unsigned char bgrt_kernel_state = KRN_FLG_RESCHED;
//Временное хранилище для указателей стеков процессов.
bgrt_stack_t * saved_sp;
#ifdef BGRT_CONFIG_PREEMPTIVE_KERNEL
// Счётчик уровней вложенности прерываний
bgrt_cnt_t nested_interrupts = (bgrt_cnt_t)0;
#endif //BGRT_CONFIG_PREEMPTIVE_KERNEL
// Функция перепланировки
void bgrt_resched( void )
{
    bgrt_kernel_state |= KRN_FLG_RESCHED;
}
/*
  Перепланировка при необходимости,
в случае использования системных вызовов
на основе программного прерывания -
- проверка на гонки с прерыванием системного вызова.
*/
void bugurt_check_resched( void )
{
    if( bgrt_kernel_state & KRN_FLG_RESCHED )
    {
        bgrt_kernel_state &= ~KRN_FLG_RESCHED;
        bgrt_sched_reschedule();
    }
}


__attribute__ (( signal, naked )) void BGRT_SYSTEM_TIMER_ISR(void);
void BGRT_SYSTEM_TIMER_ISR(void)
{
    BUGURT_ISR_START();
    BGRT_KERNEL_PREEMPT(); /// BGRT_KERNEL_PREEMPT()

    bgrt_kernel.timer.val++;
    if( bgrt_kernel.timer.tick != (void (*)(void))0 ) bgrt_kernel.timer.tick();

    BGRT_KERNEL_PREEMPT(); /// BGRT_KERNEL_PREEMPT()
    bgrt_sched_schedule();

    BUGURT_ISR_END();
}

//In single processor system call reentrancy is not necessary.
bgrt_syscall_t syscall_num = (bgrt_syscall_t)0;
void * syscall_arg = (void *)0;

__attribute__ (( naked )) void _syscall(void);
void _syscall(void)
{
    BUGURT_ISR_START();

    // Обрабатываем системный вызов
    bgrt_do_syscall(syscall_num, syscall_arg);
    syscall_num = 0;//Готово

    BUGURT_ISR_END(); //Выходим и разрешаем прерывания!
}
///Если не используется программное прерывание - прямая передача управления
void bgrt_syscall( unsigned char num, void * arg )
{
    cli();
    syscall_num = num;
    syscall_arg = arg;
    _syscall();
}
/***************************************************************************************************************/
// Функции общего пользования

void bgrt_init(void)
{
    cli();
    bgrt_kernel_init();
    bgrt_kernel.sched.nested_crit_sec = (bgrt_cnt_t)1;// Только после инициализации Ядра!!!
}
void bgrt_start(void)
{
    BGRT_START_SCHEDULER();
    bgrt_kernel.sched.nested_crit_sec = (bgrt_cnt_t)0;
    sei();
    BGRT_POST_START( (void *)0 );
}
