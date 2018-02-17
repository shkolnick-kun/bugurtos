/**************************************************************************
    BuguRTOS-4.0.x (Bugurt real time operating system)
    Copyright (C) 2018 anonimous

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
#ifndef BGRT_SYNC_H
#define BGRT_SYNC_H
BGRT_CDECL_BEGIN
/*!
\file
\brief \~russian Заголовок базового примитива синхронизации. \~english A sync header.
*/

typedef struct bgrt_priv_sync_t bgrt_sync_t; /*!< \~russian Смотри #bgrt_priv_sync_t; \~english See #bgrt_priv_sync_t; */
/*Свойства*/
/*!
\~russian
\brief
Базовый примитив синхронизации.

Базовый тип, отвечающий за блокирующую синхронизацию процессов.
Путём "обёртывания" данного типа можно получить привычные примитивы синхронизации
(мьютексы, семафоры, условные переменные, FIFO-буферы, блокирующий IPC, и т.д.).

Поддерживает протокол наследования приоритетов (Basic Priority Inheritance).

\~english
\brief
Basic synchronization primitive

A basic type that handles blocking process synchronization.
By wrapping this type one can get traditional synchronization primitives
(mutexes, semaphores, conditional variables, message-FIFOs, IPC-endpoints, etc.).

Basic priority inheritance protocol is supported.

*/
struct bgrt_priv_sync_t
{
    bgrt_xlist_t sleep;  /*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
    bgrt_proc_t * owner;/*!< \~russian Указатель на процесс-хозяин. \~english A pointer to a process, that holds a sync. */
    bgrt_cnt_t dirty; /*!< \~russian Счётчик незавершённых транзакций наследования приоритетов. \~english Dirty priority inheritance transaction counter. */
    bgrt_cnt_t snum; /*!< \~russian Счётчик спящих процессов. \~english Sleeping process counter. */
    bgrt_cnt_t pwake; /*!< \~russian Счётчик отложенных пробуждений. \~english Pending wakeup counter. */
    bgrt_prio_t prio; /*!< \~russian Приоритет. \~english Priority. */
#ifdef BGRT_CONFIG_MP
    bgrt_lock_t lock;/*!< \~russian Спин-блокировка. \~english A sync spin-lock. */
#endif /*BGRT_CONFIG_MP*/
};
/*Методы*/
/*!
\~russian
\brief
Возвращает текущий приоритет объекта типа #bgrt_sync_t.
\warning Для внутреннего использования.

\~english
\brief
Returns current #bgrt_sync_t object priority.
\warning For internal usage.
*/
bgrt_prio_t bgrt_priv_sync_prio(bgrt_sync_t * sync);
#define BGRT_SYNC_PRIO(s) bgrt_priv_sync_prio(s) /*!< \~russian \brief Считает приоритет щбъекта типа #bgrt_sync_t. \~english \brief Calculates a #bgrt_sync_t object priority */
/*!
\~russian
\brief
Инициализация базового примитива синхронизации.

\~english
\brief
A basic synchronization primitive initiation.
*/
bgrt_st_t bgrt_sync_init(
    bgrt_sync_t * sync, /*!< \~russian Указатель на объект типа #bgrt_sync_t. \~english A sync pointer. */
    bgrt_prio_t prio    /*!< \~russian Приоритет. \~english A priority. */
);
#define BGRT_SYNC_INIT(s,p) bgrt_sync_init((bgrt_sync_t *)s, (bgrt_prio_t)p) /*!< \~russian \brief Смотри #bgrt_sync_init. \~english \brief Watch #bgrt_sync_init. */
/*!
\~russian
\brief
Инициализация из критической секции, или обработчика прерываний.

Да, инициировать из обработчика прерывания можно!
\~english
\brief
A sync initiation for usage in ISRs or in critical sections.
*/
bgrt_st_t bgrt_priv_sync_init(
    bgrt_sync_t * sync, /*!< \~russian Указатель на базовый примитив синхронизации. \~english A sync pointer. */
    bgrt_prio_t prio    /*!< \~russian Приоритет. \~english A priority. */
);
#define BGRT_PRIV_SYNC_INIT(s,p) bgrt_priv_sync_init((bgrt_sync_t *)s, (bgrt_prio_t)p) /*!< \~russian \brief Смотри #bgrt_priv_sync_init. \~english \brief Watch #bgrt_priv_sync_init. */
/*!
\~russian
\brief
Смотри #BGRT_SYNC_SET_OWNER.

\warning Для внутреннего использования.
\~english
\brief
Watch #BGRT_SYNC_SET_OWNER.

\warning For internal usage.
*/
bgrt_st_t bgrt_priv_sync_set_owner(bgrt_sync_t * sync, bgrt_proc_t * proc);
/*!
\~russian
\brief
Смотри #BGRT_SYNC_GET_OWNER.

\warning Для внутреннего использования.
\~english
\brief
See #BGRT_SYNC_GET_OWNER.

\warning For internal usage.
*/
bgrt_proc_t * bgrt_priv_sync_get_owner(bgrt_sync_t * sync);
/*!
\~russian
\brief
Смотри #BGRT_SYNC_OWN.

\warning Для внутреннего использования.

\~english
\brief
Watch #BGRT_SYNC_OWN.

\warning For internal usage.
*/
bgrt_st_t bgrt_priv_sync_own(bgrt_sync_t * sync, bgrt_flag_t touch);
/*!
\~russian
\brief
Смотри #BGRT_SYNC_TOUCH.

\warning Для внутреннего использования.

\~english
\brief
Watch #BGRT_SYNC_TOUCH.

\warning For internal usage.
*/
bgrt_st_t bgrt_priv_sync_touch(bgrt_sync_t * sync);
/*!
\~russian
\brief
Смотри #BGRT_SYNC_WAKE.

\warning Для внутреннего использования.

\~english
\brief
Watch #BGRT_SYNC_WAKE.

\warning For internal usage.
*/
bgrt_st_t bgrt_priv_sync_wake(bgrt_sync_t * sync, bgrt_proc_t * proc, bgrt_flag_t chown);
/*!
\~russian
\brief
Смотри #BGRT_SYNC_SLEEP.

\warning Для внутреннего использования.

\~english
\brief
Watch #BGRT_SYNC_SLEEP.

\warning For internal usage.
*/
bgrt_st_t bgrt_priv_sync_sleep(bgrt_sync_t * sync, bgrt_flag_t * touch);
/*!
\~russian
\brief
Смотри #BGRT_SYNC_WAIT.

\warning Для внутреннего использования.
\~english
\brief
Watch #BGRT_SYNC_WAIT.

\warning For internal usage.
*/
bgrt_st_t bgrt_priv_sync_wait(bgrt_sync_t * sync, bgrt_proc_t ** proc, bgrt_flag_t block);
/*!
\~russian
\brief
Смотри #BGRT_SYNC_PROC_TIMEOUT.

\warning Для внутреннего использования.
\~english
\brief
Watch #BGRT_SYNC_PROC_TIMEOUT.

\warning For internal usage.
*/
bgrt_st_t bgrt_priv_sync_proc_timeout(bgrt_proc_t * proc);

BGRT_CDECL_END
#endif /*BGRT_SYNC_H*/
