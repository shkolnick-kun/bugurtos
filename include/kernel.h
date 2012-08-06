/**************************************************************************
    BuguRTOS-0.4.x(Bugurt real time operating system)
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
#ifndef _KERNEL_H_
#define _KERNEL_H_
/*!
\file
\brief \~russian Заголовок Ядра. \~english A kernel header.
*/
//Ядро
typedef struct _kernel_t kernel_t;
/*!
\brief
\~russian Ядро BuguRTOS. \~english A BuguRTOS kernel structure.

\~russian В ядре хранится информация о запущенных процессах, процессе(ах) холостого хода.
\~english The kernel stores information about launched processes, system time and other important information.
*/
struct _kernel_t
{
#ifdef CONFIG_MP
    sched_t sched[MAX_CORES];   /*!< \~russian Планировщики для каждого процессорного ядра. \~english A separate scheduler for every CPU core. */
    proc_t idle[MAX_CORES];     /*!< \~russian Процессы холостого хода. \~english A separate IDLE process for every CPU core. */
    stat_t stat[MAX_CORES];     /*!< \~russian Статистика для балансировки нагузки, на Hotplug работать не собираемся, все будет статично. \~english A stsatistic for load balansing, CPU hotplug is not supported. */
    lock_t stat_lock; /*!< \~russian Спин-блокировка статистики. \~english A statistic spin-lock. */
    lock_t timer_lock; /*!< \~russian Спин-блокировка таймера. \~english A system timer spin-lock. */
#else
    sched_t sched; /*!< \~russian Планировшик. \~english The scheduler. */
    proc_t idle; /*!< \~russian Процесс холостого хода. \~english The IDLE process. */
#endif // CONFIG_MP
    timer_t timer; /*!< \~russian Системный таймер. \~english The system timer. */
    void (*timer_tick)(void);/*!< \~russian Хук обработчика системного таймера. \~english The system timer tick hook pointer. */
};
/*!
\brief
\~russian Ядро BuguRTOS. \~english The BuguRTOS kernel.

\~russian Оно одно на всю систему! \~english It's the one for the entire system!
*/
extern kernel_t kernel;
// Методы
/*!
\brief
\~russian Инициализация Ядра. \~english The kernel initiation.

\~russian Готовит ядро к запуску. \~english This function prepares the kernel to work.
*/
void kernel_init(void);

/*!
\brief
\~russian Главная функция процесса холостого хода. \~english An IDLE process main function.

\~russian
Можно использовать встроенную функцию, а можно определить ее самому.
Из #idle_main можно работать с программными таймерами, подавать сигналы, ОСВОБОЖДАТЬ семафоры.
\~english
You can use builtin function, or you can write your own.
IDLE process can work with timers, fire signals and UNLOCK semaphores, SEND IPC data!

\warning \~russian Ни в коем случае нельзя делать return, останавливать процесс idle, захватывать семаформы и мьютексы из idle!!! Кто будет это все делать, того ждут Страшный суд, АдЪ и ПогибельЪ. Я предупредил! \~english An idle_main sholud NOT return, lock mutexes or semaphores, wait for IPC or signals!!!

\param arg \~russian Указатель на аргумент. \~english An argument pointer.
*/
void idle_main(void * arg);

#endif // _KERNEL_H_
