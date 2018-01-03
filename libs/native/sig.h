/**************************************************************************
    BuguRTOS-2.0.x (Bugurt real time operating system)
    Copyright (C) 2016 anonimous

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
#ifndef SIG_H
#define SIG_H
/*!
\file
\brief \~russian Заголовок сигналов. \~english A signal header.
*/
#include <bugurt.h>
#include "cond.h"
/*Сигнал*/
typedef struct _sig_t sig_t; /*!< \~russian Смотри #_sig_t; \~english See #_sig_t; */
/*Свойства*/
/*!
\~russian
\brief
Сигнал.

Сигналы используются для синхронизации процессов по событиям. Процесс может встать в список ожидания сигнала.
Другой процесс, или обработчик прерывания может подать сигнал и возобновить выполнение 1 или всех процессов, ожидающих этот сигнал.

\~english
\brief
A signal.

Signals are used for process-event synchronization. A process can wait for a signal.
Other process or interrupt handler can fire a signal and launch one or all processes waiting for that signal.
*/
struct _sig_t
{
    bgrt_cond_t wakeup; /*!< \~russian Список процессов для пробуждения. \~english Wakeup process list. */
    bgrt_mtx_t wait;  /*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
};
/*!
\~russian
\brief

Инициализация сигнала из обработчика прерывания или критической секции.

\param sig Указатель на сигнал.

\~english
\brief
A signal initiation from ISR or critical section.

\param sig A #sig_t pointer.
*/
bgrt_st_t sig_init_cs(sig_t * sig);
/*!
\~russian
\brief
Инициализация сигнала.

\param sig Указатель на сигнал.

\~english
\brief
Signal initiation.

\param sig A #sig_t pointer.
*/
bgrt_st_t sig_init(sig_t * sig);
/*!

\~russian
\brief
Встать в список ожидания сигнала.

Останавливает вызвавший процесс и ставит его в список ожидания.

\param sig Указатель на сигнал.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Wait for a signal.

This function stops caller process and inserts it to signal wait list.

\param sig A #sig_t pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t sig_wait(sig_t * sig);
/*!
\~russian
\brief
Возобновить работу 1 процесса ожидающего сигнал.

На многопроцессорной системе:

\param sig Указатель на сигнал.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Fire a signal, launch one waiting process.

\param sig A #sig_t pointer.
\return #BGRT_ST_OK on success, or error number.
*/

bgrt_st_t sig_signal(sig_t * sig);
/*!
\~russian
\brief
Возобновить работу всех ожидающих процессов.

Возобновляет работу всех ожидающих процессов.

\param sig Указатель на сигнал.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Fire a signal, launch all waiting processes.

This function launches all processes waiting for certain signal.

\param sig A #sig_t pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t sig_broadcast(sig_t * sig);

#endif /*SIG_H*/
