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
bgrt_proc_t * bgrt_curr_proc(void)
{
    return BGRT_CURR_PROC;
}

bgrt_syscall_t * bgrt_get_scnum(void)
{
    return &BGRT_CURR_PROC->scnum;//Pointer!!!
}

void * bgrt_get_scarg(void)
{
    return BGRT_CURR_PROC->scarg; //Value!!!
}

void bgrt_resched( void )
{
    bgrt_vint_push( &BGRT_KBLOCK.int_sched, &BGRT_KBLOCK.vic );
}
/******************************************************************************************************/
// Код ядра
// Состояние ядра, выполняем перепланировку


// Код ядра
//Временное хранилище для указателей стеков процессов.
bgrt_stack_t * saved_sp;
bgrt_stack_t * kernel_sp;
bgrt_stack_t ** current_sp = &kernel_sp;

bgrt_bool_t kernel_mode = (bgrt_bool_t)1;

void bgrt_set_curr_sp(void)
{
    if( BGRT_KBLOCK.vic.list.index )
    {
        kernel_mode = 1;
    }
    if( kernel_mode )
    {
        current_sp = &kernel_sp;
    }
    else
    {
        current_sp = &BGRT_CURR_PROC->spointer;
    }
}

void bgrt_switch_to_proc(void)
{
    bgrt_disable_interrupts();
    kernel_mode = (bgrt_bool_t)0;
    __trap();
    bgrt_enable_interrupts();
}

void bgrt_syscall( bgrt_syscall_t num, void * arg )
{
    bgrt_disable_interrupts();
    BGRT_CURR_PROC->scnum = num;
    BGRT_CURR_PROC->scarg = arg;
    bgrt_vint_push_isr( &BGRT_KBLOCK.int_scall, &BGRT_KBLOCK.vic );
    __trap();
    bgrt_enable_interrupts();
}

#pragma vector = 1 // trap instruction vector!
__interrupt  void bgrt_switch_context(void)
{
    BUGURT_ISR_START();
    BUGURT_ISR_END();
}

#pragma vector = BGRT_SYSTEM_TIMER_VECTOR
__interrupt void system_timer_isr(void)
{
    BUGURT_ISR_START();
    BGRT_SYSTEM_TIMER_INTERRUPT_CLEAR();

    bgrt_kernel.timer.val++;
    if( bgrt_kernel.timer.tick != (void (*)(void))0 ) bgrt_kernel.timer.tick();

    BGRT_KBLOCK.tmr_flg = (bgrt_bool_t)1;
    bgrt_vint_push_isr( &BGRT_KBLOCK.int_sched, &BGRT_KBLOCK.vic );

    BUGURT_ISR_END();
}
/***************************************************************************************************************/
// Функции общего пользования
void bgrt_init(void)
{
    bgrt_disable_interrupts();
    bgrt_kernel_init();
}
void bgrt_start(void)
{
    bgrt_enable_interrupts();
    bgrt_kblock_main( &BGRT_KBLOCK );
}
