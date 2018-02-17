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
#ifndef MUTEX_H
#define MUTEX_H
/*!
\file
\brief \~russian Заголовок мьютексов. \~english A mutex header.
*/
#include <bugurt.h>
BGRT_CDECL_BEGIN
/*Мьютекс*/
typedef struct bgrt_priv_mtx_t bgrt_mtx_t; /*!< \~russian Смотри #bgrt_priv_mtx_t; \~english See #bgrt_priv_mtx_t; */
/*!
\~russian
\brief
Мьютекс.

Используется для управления доступом к общим ресурсам, в тех случаях, когда общий ресурс нужен в течение долгого времени.
Поддерживается произвольная вложенность мьютексов.

\warning  Мьютексы захватываются и освобождаются только процессами. Нельзя делать это из обработчиков прерываний.
\warning  Мьютекс должен освободить ИМЕННО ТОТ процесс, который его захватил.

\~english
\brief
A mutex.

Mutexes are used to control an access to common data. If your code needs yo use some common data for a long time,
then you should use mutex instead of critical section. Mutex nesting is supported.

\warning  Only a process can lock or free a mutex!
\warning  Locked mutex can be freed only by a locker process!
*/
struct bgrt_priv_mtx_t
{
    bgrt_sync_t wait;/*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
};
/*Методы*/
/*!
\~russian
\brief
Инициализация мьютекса из критической секции, или обработчика прерываний.

Да, инициировать из обработчика прерывания можно!
\param mutex Указатель на мьютекс.
\param prio Приоритет мьютекса.
\~english
\brief
A mutex initiation for usage in ISRs or in critical sections.

\param mutex A mutex pointer.
\param prio A mutex priority.
*/
bgrt_st_t bgrt_mtx_init_cs(bgrt_mtx_t * mutex, bgrt_prio_t prio);
/*!
\~russian
\brief
Инициализация мьютекса.

\param mutex Указатель на мьютекс.
\param prio Приоритет мьютекса.
\~english
\brief
A mutex initiation

\param mutex A mutex pointer.
\param prio A mutex priority.
*/
bgrt_st_t bgrt_mtx_init(bgrt_mtx_t * mutex, bgrt_prio_t prio);

/*!
\~russian
\brief
Попытка захвата мьютекса.

Если мьютекс свободен - процесс захватывает его и продолжает выполняться, если уже занят - процесс продолжает выполнение.

\param mutex Указатель на мьютекс.
\return #BGRT_ST_OK - если удалось захватить, #BGRT_ST_ROLL - если не удалось.

\~english
\brief
Try to lock a mutex.

If mutex is free then caller process locks it and continues, if not caller process continues without wait.

\param mutex A mutex pointer.
\return #BGRT_ST_OK - if mutex was successfully locked else - #BGRT_ST_ROLL.
*/
bgrt_st_t bgrt_mtx_try_lock(bgrt_mtx_t * mutex);
/*!
\~russian
\brief
Захват мьютекса.

Если мьютекс свободен - процесс захватывает его и продолжает выполняться, если уже занят - процесс останавливается и записывается в список ожидающих.

\param mutex Указатель на мьютекс.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Lock a mutex.

If a mutex is free then caller process locks it and continues, else caller process stops and waits until mutex gets freed.

\param mutex A mutex pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_mtx_lock(bgrt_mtx_t * mutex);
/*!
\~russian
\brief
Освобождение мьютекса.

Если список ожидающих процессов пуст - вызывающий процесс освобождает мьютекс, если список не пуст - ставит на выполнение голову списка.
Также происходит обработка флагов, при необходимости вызывающий процесс останавливается.

\param mutex Указатель на мьютекс.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Mutex free.

If a mutex wait list is empty, then caller process frees a mutex, else mutex wait list head gets launched.

\param mutex A mutex pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_mtx_free(bgrt_mtx_t * mutex);

BGRT_CDECL_BEGIN
#endif /*MUTEX_H*/
