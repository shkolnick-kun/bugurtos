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
\brief \~russian Заголовок сигналов. \~english A signal header.
*/
//Сигнал
#ifdef CONFIG_MP
typedef struct _sig_t sig_t;
// Свойства
/*!
\brief \~russian Сигнал. \~english A signal.

\~russian
Сигналы используются для синхронизации процессов по событиям. Процесс может встать в список ожидания сигнала.
Другой процесс, или обработчик прерывания может подать сигнал и возобновить выполнение 1 или всех процессов, ожидающих этот сигнал.
\~english
Signals are used for process-event synchronization. A process can wait for a signal.
Other process or interrupt handler can fire a signal and launch one or all processes waiting for that signal.
*/
struct _sig_t
{
    xlist_t sig_list[MAX_CORES]; /*!< \~russian Массив списков ожидания, по 1 на каждое процессорное ядро в системе. \~english An array of signal wait lists, one for each CPU core. */
    stat_t sig_stat[MAX_CORES]; /*!< \~russian Массив статистических данных для предварительной балансировки нагрузки. \~english An array of statistic information. */
    lock_t lock; /*!< \~russian На многопроцессорной системе сигнал защищен спин-блокитровкой. \~english A spin-lock. */
};
#else
typedef xlist_t sig_t; /*!< \~russian На 1 процессорной системе сигнал - просто список ожидания. \~english On one core system a signal is just a wait list. */
#endif

// Методы
// Инициация
/*!
\brief \~russian Инициализация сигнала из обработчика прерывания или критической секции. \~english A signal initiation from ISR or critical section.

\param sig \~russian Указатель на сигнал. \~english A #sig_t pointer.
*/
void sig_init_isr( sig_t * sig );
/*!
\brief Инициализация сигнала.

\param sig \~russian Указатель на сигнал. \~english A #sig_t pointer.
*/
void sig_init( sig_t * sig );
// Встать на ожидание
/*!
\brief Встать в список ожидания сигнала. \~english Wait for a singnal.

\~russian
Останавливает вызвавший процесс и ставит его в список ожидания. На многопроцессорной системе при этом происходит предварительная балансировка нагрузки.
После возобновления работы процесса делается попытка остановить его по флагу #PROC_FLG_PRE_STOP.
\~english
This function stops caller process and inserts it to signal wait list.
On multicore system signal has one wait list per CPU core, so load prebalancing is done.
After firing a signal process will be lounched #PROC_FLG_PRE_STOP processing will be done.


\param sig \~russian Указатель на сигнал. \~english A #sig_t pointer.
*/
void sig_wait( sig_t * sig );

//Для внутреннего использования
/*!
\brief \~russian Встать в список ожидания сигнала, для внутреннего использования. \~english A signal wait prologue kernel part.

\~russian
Останавливает вызвавший процесс и ставит его в список ожидания. На многопроцессорной системе при этом происходит предварительная балансировка нагрузки.
\~english
This function stops cureent running process and insert it to signal wait list.
On multicore system it allso does load prebalancing.

\param sig \~russian Указатель на сигнал. \~english A #sig_t pointer.
*/
void _sig_wait_prologue( sig_t * sig );
void _sig_wait_epilogue( void );

// Разбудить 1 процесс
/*!
\brief \~russian Возобновить работу 1 процесса ожидающего сигнал. \~english Fire a signal, launch one waiting process.

\~russian
На мнгогопроцессорной системе:
Ищет в массиве статистики сигнала самое "нагруженное" ядро.
Далее возобновляет работу головы списка ожидающих сигнал для этого ядра, при этом происходит балансировка нагрузци - запускаемый процесс будет выполняться на самом ненагруженном процессорном ядре из возможных.

На 1 процессорной системе: просто возобновляет работу голоы списка ожидающих.

\~english
On multicore system:
This functin finds most loaded signal wait list (using signal statistic array) and launches its head on the least loaded CPU core.
On one coresystem:
This function launches signal wait list head.

\param sig \~russian Указатель на сигнал. \~english A #sig_t pointer.
*/
void sig_signal( sig_t * sig );
// Разбудить все процессы
/*!
\brief \~russian Возобновить работу всех ожидающих процессов. \~english Fire a signal, launch all waiting processes.

\~russian
Возобновляет работу всех ожидающих процессов.
Процессы в списках ожидания сигналов сгруппированы, что дает возможность за ограниченное время перенести весь список ожидающих в соотетствующий список готовых к выполнению.
\~english
This function launches all processes waiting for certain signal.
This function is O(1), as processes in signal wait lists a grouped, #gitem_xlist_merge is used.

\param sig \~russian Указатель на сигнал. \~english A #sig_t pointer.
*/
void sig_broadcast( sig_t * sig );

// Тоже самое что и предыдущие, олько для вызова из обработчиков прерываний
// Во время выполнения прерывания должны быть запрещены!
/*!
\brief \~russian Возобновить работу 1 процесса ожидающего сигнал из обработчика прерывания. \~english Fire a signal from ISR, launch one waiting process.

\~russian
На мнгогопроцессорной системе:
Ищет в массиве статистики сигнала самое "нагруженное" ядро.
Далее возобновляет работу головы списка ожидающих сигнал для этого ядра, при этом происходит балансировка нагрузци - запускаемый процесс будет выполняться на самом ненагруженном процессорном ядре из возможных.

На 1 процессорной системе: просто возобновляет работу голоы списка ожидающих.

\~english
On multicore system:
This functin finds most loaded signal wait list (using signal statistic array) and launches its head on the least loaded CPU core.
On one coresystem:
This function launches signal wait list head.

\param sig \~russian Указатель на сигнал. \~english A #sig_t pointer.
*/
void sig_signal_isr( sig_t * sig );
/*!
\brief \~russian Возобновить работу всех ожидающих процессов из обработчика прерывания. \~english Fire a signal from ISR, launch all waiting processes.

\~russian
Возобновляет работу всех ожидающих процессов.
Процессы в списках ожидания сигналов сгруппированы, что дает возможность за ограниченное время перенести весь список ожидающих в соотетствующий список готовых к выполнению.
\~english
This function launches all processes waiting for certain signal.
This function is O(1), as processes in signal wait lists a grouped, #gitem_xlist_merge is used.

\param sig \~russian Указатель на сигнал. \~english A #sig_t pointer.
*/
void sig_broadcast_isr( sig_t * sig );

#endif // _SIG_H_
