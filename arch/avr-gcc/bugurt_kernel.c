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

// Стек процесса холостого хода
stack_t idle_stack[CONFIG_IDLE_STACK_SIZE];

//Внешние функции, специфичные для AVR
extern void start_scheduler( void );
extern void stop_scheduler( void );
// Просто функции, специфичные для AVR
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

void * proc_stack_init(stack_t * sstart, code_t code, void * arg)
{
    return osbme_init_stack( (void *)sstart, (osbme_code_t)proc_run_wrapper, (void *)arg );
}

/******************************************************************************************************/
// Код ядра

// Флаг перепланировки
bool_t resched_flag = (bool_t)1;

//Указатели стека
void    * proc_sp,  // процессов
        * kernel_sp;// ядра
//Через этот указатель будет вызываться обработчик прерывания
void (*kernel_isr)(void);

// Функция перепланировки
void resched(void)
{
    resched_flag = (bool_t)1;
}

__attribute__((naked)) void kernel_process_switch(void)
{
    //Сразу же после обработки отложенных прерываний передаем управление процессу
    kernel_sp = osbme_store_context();
    osbme_load_context( proc_sp );
    __asm__ __volatile__("reti"::);/// Дада, именно reti, мы же типа прерывания счас обрабатывали
}

__attribute__((naked)) void process_kernel_switch(void)
{
    proc_sp = osbme_store_context();
    osbme_load_context( kernel_sp );
    __asm__ __volatile__("ret"::);
}
///================================================================
void kernel_thread(void)
{
    while(1)
    {
        // Если надо перепланировать - перепланируем
        if( resched_flag != (bool_t)0 )
        {
            resched_flag = (bool_t)0;
            proc_sp = sched_reschedule( proc_sp );
        }
        /// Прямая передача управления от ядра к процессу, прерывания запрещены
        kernel_process_switch();//В результате выполнения этого прерывания будут разрешены
        /// Сюда можно попасть только из прерывания, либо из процесса, при этом прерывания опять таки запрещены

        #ifdef SYSCALL_ISR
        if( syscall_flags & SYSCALL_FLG_GET_DATA )
        {
            syscall_data_get();
            syscall_flags &= ~SYSCALL_FLG_GET_DATA;
        }
        #endif

        // Обработка прерывания
        kernel_isr();
    }
}

// А вот и первое определение обработчика прерывания
BUGURT_INTERRUPT(SYSTEM_TIMER_ISR)
{
    kernel.timer++;
    proc_sp = sched_schedule( proc_sp );
}

/***************************************************************************************************************/
// Функции общего пользования

void init_bugurt(void)
{
    cli();
    kernel_init();
    proc_sp = osbme_init_stack( &idle_stack[CONFIG_IDLE_STACK_SIZE-1], idle_main, 0);
    kernel.idle.spointer = proc_sp;
    kernel.sched.nested_crit_sec = (count_t)1;
}
void start_bugurt(void)
{
    start_scheduler();
    kernel.sched.nested_crit_sec = (count_t)0;
    kernel_thread();
}
