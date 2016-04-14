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
#ifndef _BGRT_KERNEL_H_
#define _BGRT_KERNEL_H_
/*!
\file
\brief \~russian Заголовок Ядра. \~english A kernel header.
*/

typedef struct _bgrt_kblock_t bgrt_kblock_t; /*!< \~russian Смотри #_bgrt_kblock_t; \~english See #_bgrt_kblock_t; */
/*!
\~russian
\brief
Блок ядра BuguRTOS.

Отвечает за обработку вритуальных прерываний, обработку системных вызовов, работу планировщика на отдельном процессорном ядре.

\~english
\brief
A BuguRTOS kernel block structure.

A kernel block is responsible for virtual interrupt processing, system call processing and process sheduling jn certain CPU core.
*/
struct _bgrt_kblock_t
{
    bgrt_vic_t   vic;                 /*!< \~russian Виртуальный контроллер прерываний. \~english A virtual interrupt controller. */
    bgrt_sched_t sched;               /*!< \~russian Планировщик. \~english A scheduler. */
    bgrt_vint_t int_scall;            /*!< \~russian Диспетчер системных вызовов. \~english A system call dispatcher. */
    bgrt_vint_t int_sched;            /*!< \~russian Прерывание планировщика. \~english A scheduler interrupt. */
    bgrt_bool_t tmr_flg;              /*!< \~russian Флаг рерывания системмного таймера. \~english System timer interrupt flag. */
};

/*!
\~russian
\brief
Инициализация объекта типа #bgrt_kblock_t.

\param kblock Указатель на объект типа #bgrt_kblock_t.

\~english
\brief
A #bgrt_kblock_t object initialization.

\param kblock A #bgrt_kblock_t object pointer.
*/
void bgrt_kblock_init( bgrt_kblock_t * kblock );

/*!
\~russian
\brief
Главная функция потока Ядра.

\param kblock Указатель на объект типа #bgrt_kblock_t.

\~english
\brief
A kernel thread main function.

\param kblock A #bgrt_kblock_t object pointer.
*/
void bgrt_kblock_main( bgrt_kblock_t * kblock );

//Ядро
///TODO: Remove old kernel!!!
#ifndef BGRT_CONFIG_NEW_KERNEL
typedef struct _bgrt_kernel_t bgrt_kernel_t; /*!< \~russian Смотри #_bgrt_kernel_t; \~english See #_bgrt_kernel_t; */
#else //BGRT_CONFIG_NEW_KERNEL
typedef struct _new_bgrt_kernel_t bgrt_kernel_t; /*!< \~russian Смотри #_bgrt_kernel_t; \~english See #_bgrt_kernel_t; */
#endif//BGRT_CONFIG_NEW_KERNEL
/*!
\~russian
\brief
Ядро BuguRTOS.

В ядре хранится информация о запущенных процессах, процессе(ах) холостого хода.

\~english
\brief
A BuguRTOS kernel structure.

The kernel stores information about launched processes, system time and other important information.

*/
struct _bgrt_kernel_t
{
#ifdef BGRT_CONFIG_MP
    bgrt_sched_t sched[BGRT_MAX_CPU]; /*!< \~russian Планировщики для каждого процессорного ядра. \~english A separate scheduler for every CPU core. */
    bgrt_proc_t idle[BGRT_MAX_CPU];   /*!< \~russian Процессы холостого хода. \~english A separate IDLE process for every CPU core. */
    bgrt_kstat_t stat;                /*!< \~russian Статистика для балансировки нагрузки, на Hotplug работать не собираемся, все будет статично. \~english A statistic for load balancing, CPU hotplug is not supported. */
#else
    bgrt_sched_t sched;               /*!< \~russian Планировщик. \~english The scheduler. */
    bgrt_proc_t idle;                 /*!< \~russian Процесс холостого хода. \~english The IDLE process. */
#endif // BGRT_CONFIG_MP
    bgrt_ktimer_t timer;              /*!< \~russian Системный таймер. \~english The system timer. */
};
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Ядро

/*!
\~russian
\brief
Ядро BuguRTOS.

В ядре хранится информация о запущенных процессах, процессе(ах) холостого хода.

\~english
\brief
A BuguRTOS kernel structure.

The kernel stores information about launched processes, system time and other important information.

*/
struct _new_bgrt_kernel_t
{
#ifdef BGRT_CONFIG_MP
    bgrt_kblock_t kblock[BGRT_MAX_CPU]; /*!< \~russian Планировщики для каждого процессорного ядра. \~english A separate scheduler for every CPU core. */
    bgrt_kstat_t stat;                /*!< \~russian Статистика для балансировки нагрузки, на Hotplug работать не собираемся, все будет статично. \~english A statistic for load balancing, CPU hotplug is not supported. */
#else
    bgrt_kblock_t kblock;               /*!< \~russian Планировщик. \~english The scheduler. */
#endif // BGRT_CONFIG_MP
    bgrt_ktimer_t timer;              /*!< \~russian Системный таймер. \~english The system timer. */
};
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*!
\~russian
\brief
Ядро BuguRTOS.

Оно одно на всю систему!

\~english
\brief
The BuguRTOS bgrt_kernel.

It's the one for the entire system!
*/
extern bgrt_kernel_t bgrt_kernel;
// Методы
/*!
\~russian
\brief
Инициализация ядра.

Готовит ядро к запуску.

\warning Для внутреннего использования.

\~english
\brief
The kernel initiation.

This function prepares the kernel to work.

\warning Internal usage function.
*/
void bgrt_kernel_init(void);

/*!
\~russian
\brief
Главная функция процесса холостого хода.

Можно использовать встроенную функцию, а можно определить ее самому.
Из #bgrt_idle_main можно работать с программными таймерами, подавать сигналы, ОСВОБОЖДАТЬ семафоры.

\warning Ни в коем случае нельзя делать return, останавливать процесс idle, захватывать семафоры и мьютексы из idle!!! Кто будет это все делать, того ждут Страшный суд, АдЪ и ПогибельЪ. Я предупредил!

\param arg Указатель на аргумент.

\~english
\brief
An IDLE process main function.

You can use built-in function, or you can write your own.
IDLE process can work with timers, fire signals and FREE semaphores, SEND IPC data!

\warning An bgrt_idle_main should NOT return, lock mutexes or semaphores, wait for IPC or signals!!!

\param arg An argument pointer.
*/
void bgrt_idle_main(void * arg);

#ifndef BGRT_CONFIG_POSTSTART
#   define BGRT_POST_START(a) bgrt_idle_main(a)
#else
#   define BGRT_POST_START(a) BGRT_CONFIG_POSTSTART(a)
#endif //BGRT_CONFIG_POSTSTART

#endif // _BGRT_KERNEL_H_
