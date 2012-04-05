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

// Платформеннозависимый код
// Просто функции, специфичные для AVR
stack_t * proc_stack_init(stack_t * sstart, code_t code, void * arg)
{
    stack_t * tos = (stack_t *)sstart;
    // return address
    unsigned short tmp = (unsigned short)code;
    *tos-- = (stack_t)(tmp&(unsigned short)0x00ff);
    tmp>>=8;
    *tos-- = (stack_t)(tmp&(unsigned short)0x00ff);

    // s
    *tos-- = 0x00;
    *tos-- = 0x00;// r1 must B 0
    *tos-- = 0x02;// r2
    *tos-- = 0x80;// SREG: enable interrupts
    *tos-- = 0x03;
    *tos-- = 0x04;
    *tos-- = 0x05;
    *tos-- = 0x06;
    *tos-- = 0x07;
    *tos-- = 0x08;
    *tos-- = 0x09;
    *tos-- = 0x10;
    *tos-- = 0x11;
    *tos-- = 0x12;
    *tos-- = 0x13;
    *tos-- = 0x14;
    *tos-- = 0x15;
    *tos-- = 0x16;
    *tos-- = 0x17;
    *tos-- = 0x18;
    *tos-- = 0x19;
    *tos-- = 0x20;
    *tos-- = 0x21;
    *tos-- = 0x22;
    *tos-- = 0x23;

    tmp = (unsigned short)arg;
    *tos-- = (stack_t)(tmp&(unsigned short)0x00ff); // r24 LSByte of arg
    tmp>>=8;
    *tos-- = (stack_t)(tmp&(unsigned short)0x00ff); // r25 MSByte of arg

    *tos-- = 0x26;
    *tos-- = 0x27;
    *tos-- = 0x28;
    *tos-- = 0x29;
    *tos-- = 0x30;
    *tos-- = 0x31;
#ifdef RAMPZ
    *tos-- = 0xff;
#endif
    return tos;
}

void disable_interrupts(void)
{
    cli();
}
void enable_interrupts(void)
{
    sei();
}

proc_t * current_proc(void)
{
    return kernel.sched.current_proc;
}

/******************************************************************************************************/
// Код ядра

// Состояние ядра, выполняем перепланиировку
unsigned char kernel_state = KRN_FLG_RESCHED;
//Временное хранилище для указателей стеков процессов.
stack_t * saved_proc_sp;
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
    if(
    ( kernel_state & KRN_FLG_RESCHED )
#ifdef SYSCALL_ISR
    && ( (~kernel_state) & KRN_FLG_DO_SCALL )
#endif // SYSCALL_ISR
    )
    {
        kernel_state &= ~KRN_FLG_RESCHED;
        sched_reschedule();
    }
}


__attribute__ (( signal, naked )) void SYSTEM_TIMER_ISR(void)
{
    BUGURT_ISR_START();

    kernel.timer++;
    if( kernel.timer_tick != (void (*)(void))0 ) kernel.timer_tick();
    sched_schedule();

    BUGURT_ISR_EXIT();
}

#ifdef SYSCALL_ISR

#ifdef RAMPZ
#define PROC_STACK_OFFSET 8
#else
#define PROC_STACK_OFFSET 7
#endif

typedef struct
{
    unsigned char num;
    void * arg;
} syscall_data_t;

static syscall_data_t scdata;
/// Если используется программное прерывание - вот его обработчик
__attribute__ (( signal, naked )) void SYSCALL_ISR(void)
{
    BUGURT_ISR_START();

    // Получаем информацию о системном вызове из стека процесса
    unsigned char * tos;
    unsigned short temp;
    tos = (unsigned char *)kernel.sched.current_proc->spointer + PROC_STACK_OFFSET;
    temp = (unsigned short)*tos++;
    temp <<= 8;
    temp |= (unsigned short)*tos;

    syscall_num = ((syscall_data_t *)temp)->num;
    syscall_arg = ((syscall_data_t *)temp)->arg;

    // Обрабатываем системный вызов
    do_syscall();
    kernel_state &= ~KRN_FLG_DO_SCALL;

    // Перепланировка при необходимости
    if( kernel_state & KRN_FLG_RESCHED )
    {
        kernel_state &= ~KRN_FLG_RESCHED;
        sched_reschedule();
    }

    // Разрешаем обработку прерывания системного таймера.
    start_scheduler();

    BUGURT_ISR_EXIT();
}

syscall_data_t * _syscall( syscall_data_t * arg )
{
    kernel_state |= KRN_FLG_DO_SCALL;
    stop_scheduler(); // Чтобы не было гонок с обработчиком прерывания системного таймера.
    raise_syscall_interrupt();
    sei();
    return arg;
}
void syscall_bugurt( unsigned char num, void * arg )
{
     cli();
     scdata.num = num;
     scdata.arg = arg;
     _syscall( &scdata );
     SYSCALL_DELLAY();
     while( kernel_state & KRN_FLG_DO_SCALL );
}
#else
__attribute__ (( naked )) void _syscall(void)
{
    BUGURT_ISR_START();

    // Обрабатываем системный вызов
    do_syscall();

    BUGURT_ISR_END(); //Выходим и разрешаем прерывания!
}
///Если не используется программное прерывание - прямая передача управления
void syscall_bugurt( unsigned char num, void * arg )
{
    cli();
    syscall_num = num;
    syscall_arg = arg;
    _syscall();
}

#endif
/***************************************************************************************************************/
// Функции общего пользования

void init_bugurt(void)
{
    cli();
    kernel_init();
    kernel.sched.nested_crit_sec = (count_t)1;// Только после инициализации Ядра!!!
}
void start_bugurt(void)
{
    start_scheduler();
    kernel.sched.nested_crit_sec = (count_t)0;
    sei();
    idle_main( (void *)0 );
}
