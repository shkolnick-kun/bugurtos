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
#ifndef _SIG_H_
#define _SIG_H_
/*!
\file
\brief Заголовок сигналов.
*/
//Сигнал
#ifdef CONFIG_MP
typedef struct _sig_t sig_t;
// Свойства
/*!
\brief Сигнал

Сигналы используются для синхронизации процессов по событиям. Процесс может встать в список ожидания сигнала.
Другой процесс, или обработчик прерывания может подать сигнал и возобновить выполнение 1 или всех процессов, ожидающих этот сигнал.
*/
struct _sig_t
{
    xlist_t sig_list[MAX_CORES]; /*!< Массив списков ожидания, по 1 на каждое процессорное ядро в системе. */
    stat_t sig_stat[MAX_CORES]; /*!< Массив статистических данных для предварительной балансировки нагрузки. */
    lock_t lock; /*!< На многопроцессорной системе сигнал защищен спин-блокитровкой. */
};
#else
typedef xlist_t sig_t; /*!< На 1 процессорной системе сигнал - просто список ожидания. */
#endif

// Методы
// Инициация
/*!
\brief Инициализация сигнала из обработчика прерывания или критической секции.

\param sig Указатель на сигнал.
*/
void sig_init_isr( sig_t * sig );
/*!
\brief Инициализация сигнала.

\param sig Указатель на сигнал.
*/
void sig_init( sig_t * sig );
// Встать на ожидание
/*!
\brief Встать в список ожидания сигнала.

Останавливает вызвавший процесс и ставит его в список ожидания. На многопроцессорной системе при этом происходит предварительная балансировка нагрузки.
После возобноаления работы процесса делается попытка остановить его по флагу #PROC_FLG_PRE_STOP.

\param sig Указатель на сигнал.
*/
void sig_wait( sig_t * sig );

//Для внутреннего использования
/*!
\brief Встать в список ожидания сигнала, для внутреннего использования.

Используется в критических секциях и обработчиках прерываний.
Останавливает вызвавший процесс и ставит его в список ожидания. На многопроцессорной системе при этом происходит предварительная балансировка нагрузки.

\param sig Указатель на сигнал.
*/
void _sig_wait_prologue( sig_t * sig );
/*!
\brief Встать в список ожидания сигнала, для внутреннего использования.

Останавливает вызвавший процесс и ставит его в список ожидания. На многопроцессорной системе при этом происходит предварительная балансировка нагрузки.

\param sig Указатель на сигнал.
*/
void sig_wait_prologue( sig_t * sig );

// Разбудить 1 процесс
/*!
\brief Возобновить работу 1 процесса ожидающего сигнал.

На мнгогопроцессорной системе:
Ищет в массиве статистики сигнала самое "нагруженное" ядро.
Далее возобновляет работу головы списка ожидающих сигнал для этого ядра, при этом происходит балансировка нагрузци - запускаемый процесс будет выполняться на самом ненагруженном процессорном ядре из возможных.

На 1 процессорной системе: просто возобновляет работу голоы списка ожидающих.

\param sig Указатель на сигнал.
*/
void sig_signal( sig_t * sig );
// Разбудить все процессы
/*!
\brief Возобновить работу всех ожидающих процессов.

Возобновляет работу всех ожидающих процессов.
Процессы в списках ожидания сигналов сгруппированы, что дает возможность за ограниченное время перенести весь список ожидающих в соотетствующий список готовых к выполнению.

\param sig Указатель на сигнал.
*/
void sig_broadcast( sig_t * sig );

// Тоже самое что и предыдущие, олько для вызова из обработчиков прерываний
// Во время выполнения прерывания должны быть запрещены!
/*!
\brief Возобновить работу 1 процесса ожидающего сигнал, для использования в критических секциях и обработчиках прерываний.

На мнгогопроцессорной системе:
Ищет в массиве статистики сигнала самое "нагруженное" ядро.
Далее возобновляет работу головы списка ожидающих сигнал для этого ядра, при этом происходит балансировка нагрузци - запускаемый процесс будет выполняться на самом ненагруженном процессорном ядре из возможных.

На 1 процессорной системе: просто возобновляет работу головы списка ожидающих.

\param sig Указатель на сигнал.
*/
void sig_signal_isr( sig_t * sig );
/*!
\brief Возобновить работу всех ожидающих процессов, для использования в критических секциях и обработчиках прерываний.

Возобновляет работу всех ожидающих процессов.
Процессы в списках ожидания сигналов сгруппированы, что дает возможность за ограниченное время перенести весь список ожидающих в соотетствующий список готовых к выполнению.

\param sig Указатель на сигнал.
*/
void sig_broadcast_isr( sig_t * sig );

#endif // _SIG_H_
