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
#ifndef COND_H
#define COND_H
/*!
\file
\brief \~russian Заголовок условных переменных. \~english A conditional variable header.
*/
#include <bugurt.h>
BGRT_CDECL_BEGIN
#include "mutex.h"

typedef struct bgrt_priv_cond_t bgrt_cond_t; /*!< \~russian Смотри #bgrt_priv_cond_t; \~english See #bgrt_priv_cond_t; */
/*Свойства*/
/*!
\~russian
\brief
Условная переменная.

Условные переменные используются в сочетании с мьютексами для синхронизации процессов по событиям. Процесс может заблокировать себя на условной переменной.
Другой процесс может возобновить выполнение 1 или всех процессов, заблокированных на условной переменной.

\~english
\brief
A conditional variable.

Conditional variables with mutexes are used for process-event synchronization. A process can block on conditional variable.
Other process can launch one or all processes blocked on conditional variable.
*/
struct bgrt_priv_cond_t
{
    bgrt_sync_t wait;/*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
};
/*!
\~russian
\brief

Инициализация условной переменной из обработчика прерывания или критической секции.

\param cond Указатель на условную переменную.

\~english
\brief
A conditional variable initiation from ISR or critical section.

\param cond A #bgrt_cond_t pointer.
*/
bgrt_st_t bgrt_cond_init_cs(bgrt_cond_t * cond);
/*!
\~russian
\brief

Инициализация условной переменной.

\param cond Указатель на условную переменную.

\~english
\brief
A conditional variable initiation.

\param cond A #bgrt_cond_t pointer.
*/
bgrt_st_t bgrt_cond_init(bgrt_cond_t * cond);
/*!

\~russian
\brief
Встать в список ожидания условной переменной.

Останавливает вызвавший процесс и ставит его в список ожидания.

\param cond Указатель на условную переменную.
\param mutex Указатель на мьютекс, защищающий условную переменную.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Wait for a condition.

This function stops caller process and inserts it to conditional variable wait list.

\param cond A #bgrt_cond_t pointer.
\param mutex A pointer to a mutex which protects a conditional variable.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_cond_wait( bgrt_cond_t * cond, bgrt_mtx_t * mutex);
/*!
\~russian
\brief
Возобновить работу 1 процесса ожидающего условной переменной.

Возобновляет работу головы списка ожидающих процессов.

\warning Вызывать только при захваченном мьютексе!

\param cond Указатель на условную переменную.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Launch one waiting process.

Launches the head of waiting process list.
\warning Caller must lock mutex first!

\param cond A #bgrt_cond_t pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_cond_signal(bgrt_cond_t * cond);
/*!
\~russian
\brief
Возобновить работу вех процессов ожидающих условной переменной.

Возобновляет работу всех процессов из списка ожидающих.

\warning Вызывать только при захваченном мьютексе!

\param cond Указатель на условную переменную.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Launch all waiting processes.

Launches all processes from waiting process list.
\warning Caller must lock mutex first!

\param cond A #bgrt_cond_t pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_cond_broadcast(bgrt_cond_t * cond);

BGRT_CDECL_END
#endif /*COND_H*/
