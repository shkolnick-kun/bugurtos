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
#ifndef IPC_H
#define IPC_H
/*!
\file
\brief \~russian Заголовок IPC. \~english An IPC header.
*/
#include <bugurt.h>
BGRT_CDECL_BEGIN

typedef struct bgrt_priv_ipc_t bgrt_ipc_t;/*!< \~russian Смотри #bgrt_priv_ipc_t; \~english See #bgrt_priv_ipc_t; */
/*Свойства*/
/*!
\~russian
\brief
Конечная точка IPC.

Используется для реализации блокирующего синхронного или асинхронного протокола IPC.

\~english
\brief
An IPC endpoint.

Used for blocking synchronous or asynchronous IPC protocol implementation.
*/
struct bgrt_priv_ipc_t
{
    bgrt_sync_t wait; /*!< \~russian Список ожидающих процессов. \~english A list of waiting processes.  */
    void * msg;  /*!< \~russian Указатель на буфер с сообщением. \~english A message buffer pointer. */
};
/*Методы*/
/*Инициализация*/
/*!
\~russian
\brief
Инициализация конечной точки IPC из критической секции или обработчика прерывания.

\param endpoint Указатель на конечную точку.
\~english
\brief
IPC endpoint initiation from ISR or critical section.

\param endpoint A pointer to the endpoint.
*/
bgrt_st_t bgrt_ipc_init_cs(bgrt_ipc_t * endpoint);
/*!
\~russian
\brief
Инициализация конечной точки IPC.

\param endpoint Указатель на конечную точку.
\~english
\brief
IPC endpoint initiation.

\param endpoint A pointer to the endpoint.
*/
bgrt_st_t bgrt_ipc_init(bgrt_ipc_t * endpoint);
/*!
\~russian
\brief
Посылка данных процессу через IPC.

Пересылает указатель на буфер с сообщением через IPC, отправители блокируются и ждут своей очереди,
получатель наследует приоритеты отправителей.

\param out Указатель на конечную точку IPC.
\param msg Указатель на буфер с сообщением.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
IPC data transmission.

This function transfers a pinter to the message buffer through IPC.
Senders are blocked on IPC endpoint and wait for their turn,
receiver inherits senders priorities.

\param out An IPC endpoint pointer.
\param msg A message buffer pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_ipc_send(bgrt_ipc_t * out, void * msg);
/*!
\~russian
\brief
Переход процесса к ожиданию получения данных через IPC.

Для для указания отправителя или получения указателя на отправитель используется буфер,
адрес которого передаётся вторым аргументом.

\param in Указатель на конечную точку IPC.
\param pid Указатель на буфер идентификатора отправителя.
\param block Флаг блокировки вызывающего процесса, если не 0, то вызывающий процесс блокируется до готовности сообщения.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Wait for IPC.

A buffer must be used to set or get sender process.
A buffer pointer must be passed as a second parameter.

\param in An IPC endpoint pointer.
\param pid A sender pid buffer pointer.
\param block A caller block flag. If non zero, then caller is blocked until message is sent.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_ipc_wait(bgrt_ipc_t * in, BGRT_PID_T * pid, bgrt_flag_t block);

/*!
\~russian
\brief
Разблокировать процесс, от которого получено сообщение.


\param in Указатель на конечную точку IPC.
\param pid Идентификатор отправителя.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Unblock a sender process, which message has been received.

\param in An IPC endpoint pointer.
\param pid A sender process ID.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_ipc_reply(bgrt_ipc_t * in, BGRT_PID_T pid);

BGRT_CDECL_END
#endif /*IPC_H*/
