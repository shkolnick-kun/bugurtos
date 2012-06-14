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
#ifndef _IPC_H_
#define _IPC_H_

/*!
\file
\brief \~russian Заголовок IPC. \~english An IPC header.
*/

/*!
\brief
\~russian Переход процесса к ожиданию получения данных через IPC. \~english Wait for IPC kernel part.

\warning \~russian Для внутреннего использования. \~english For internal usage only!!!
\param ipc_pointer \~russian Указатель на хранилище для передаваемых данных. \~english A pointer to IPC data storage.
*/
void _ipc_wait( void * ipc_pointer );

/*!
\brief
\~russian Переход процесса к ожиданию получения данных через IPC. \~english Wait for IPC.

\return \~russian Данные. \~english IPC data.
*/
ipc_data_t ipc_wait( void );

/*!
\brief
\~russian Посылка данных процессу через IPC. \~english IPC data transmition.

\~russian Проверяет, действительно ли процесс-адресат ждет получения данных через IPC.
Если процесс-адресат действительно ждет, Ядро передает данные и запускает процесс-адресат.

\~english This function checks a destignation process state.
If destignation process is waiting for IPC, then data gets transmited and destignation process gets launched.

\param proc \~russian Указатель на процесс-адресат. \~english A ddestignation process pointer.
\param data \~russian Данные для передачи. \~english A data to transmit.
\return \~russian 1 - Если удалось передать данные, 0 - если нет. \~english 1 - if data has been transmited, else 0.
*/
bool_t ipc_send( proc_t * proc, ipc_data_t data );

/*!
\brief
\~russian Посылка данных процессу через IPC. Для вызова из обработчиков прерываний. \~english IPC data transmition for ISR usage.

\warning \~russian Для вызова из обработчиков прерываний! \~english Use in interrupt service routines.

\~russian
Проверяет, действительно ли процесс-адресат ждет получения данных через IPC.
Если процесс-адресат действительно ждет, Ядро передает данные и запускает процесс-адресат.

\~english This function checks a destignation process state.
If destignation process is waiting for IPC, then data gets transmited and destignation process gets launched.

\param proc \~russian Указатель на процесс-адресат. \~english A ddestignation process pointer.
\param data \~russian Данные для передачи. \~english A data to transmit.
\return \~russian 1 - Если удалось передать данные, 0 - если нет. \~english 1 - if data has been transmited, else 0.
*/
bool_t ipc_send_isr( proc_t * proc, ipc_data_t data );

/*!
\brief
\~russian Посылка данных процессу через IPC, прием ответа через IPC. \~english An IPC data transmition with wait for answer via IPC kernel part.

\warning \~russian Для внутреннего использования! \~english For internal usage only!

\~russian
Проверяет, действительно ли процесс-адресат ждет получения данных через IPC.
Если процесс-адресат действительно ждет, Ядро передает данные и запускает процесс-адресат,
при этом процесс отправитель переходит к ожиданию данных через IPC.

\~english
This function checks a destignation process state.
If destignation process is waiting for IPC, then data gets transmited and destignation process gets launched.
If transmition has been sucessful then caller process wats for answer via IPC.

\param proc \~russian Указатель на процесс-адресат. \~english A ddestignation process pointer.
\param send \~russian Данные для передачи. \~english A data to transmit.
\param receive \~russian указатель на хранилище данных для приема. \~english A pointer to receive data storage.
\return \~russian 1 - если удалось передать данные, 0 - если нет. \~english 1 - if data has been transmited, else 0.
*/
bool_t _ipc_exchange( proc_t * proc, ipc_data_t send, ipc_data_t * receive );

/*!
\brief
\~russian Посылка данных процессу через IPC, прием ответа через IPC. \~english An IPC data transmition with wait for answer via IPC kernel part.

\~russian
Проверяет, действительно ли процесс-адресат ждет получения данных через IPC.
Если процесс-адресат действительно ждет, Ядро передает данные и запускает процесс-адресат,
при этом процесс отправитель переходит к ожиданию данных через IPC.

\~english
This function checks a destignation process state.
If destignation process is waiting for IPC, then data gets transmited and destignation process gets launched.
If transmition has been sucessful then caller process wats for answer via IPC.

\param proc \~russian Указатель на процесс-адресат. \~english A ddestignation process pointer.
\param send \~russian Данные для передачи. \~english A data to transmit.
\param receive \~russian указатель на хранилище данных для приема. \~english A pointer to receive data storage.
\return \~russian 1 - если удалось передать данные, 0 - если нет. \~english 1 - if data has been transmited, else 0.
*/
bool_t ipc_exchange( proc_t * proc, ipc_data_t send, ipc_data_t * receive );

#endif // _IPC_H_
