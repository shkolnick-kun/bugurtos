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
#ifndef _SCHED_H_
#define _SCHED_H_
/*!
\file
\brief Заголовок планировщика

\warning Все функции в этом файле для внутреннего использования!!!
*/
// Планировшик
typedef struct _sched_t sched_t;
// Свойства
/*!
\brief Планировщик.

Планировщик содержит информацию о процессах, запущенных на процессоре (процессорном ядре).
*/
struct _sched_t
{
    proc_t * current_proc;      /*!< Текущий процесс. */
    xlist_t * ready;            /*!< Указатель на список готовых к выполнению процессов. */
    xlist_t * expired;          /*!< Указатель на список процессов, исчерпавших свой квант времени. */
    xlist_t plst[2];            /*!< Сами списки процесов. */
    count_t nested_crit_sec;    /*!< Счетчик вложенности критических секций. */
#ifdef CONFIG_MP
    lock_t lock;                /*!< Спин-блокировка планировщика. */
#endif // CONFIG_MP
};
// Методы


/*!
\brief Инициализация планировщика.

Готовит планировщик к запуску.
\param sched - Указатель на планировщик.
\param idle - Указатель на процесс холостого хода.
*/
void sched_init(sched_t * sched, proc_t * idle);
/*!
\brief Функция планирования.
Переключает процессы в обработчике прерывания системного таймера.
*/
void sched_schedule(
#ifdef CONFIG_MP
                        sched_t * sched /*!< Работаем с этим экземпляром планировщика*/
#else
                        void
#endif // CONFIG_MP
                       );
/*!
\brief Функция перепланирования.
Переключает процессы в обработчике прерывания перепланирования.
*/
void sched_reschedule(
#ifdef CONFIG_MP
                        sched_t * sched /*!< Работаем с этим экземпляром планировщика*/
#else
                        void
#endif // CONFIG_MP
                       );
#ifdef CONFIG_MP
// Балансировщик нагрузки
/*!
\brief Балансировщик нагрузки.

Используется для балансировки нагрузки в Ядре, а также для предварительной балансировки нагрузки в сигналах.

\param proc Указатель на процесс, который надо перенести на новое процессорное ядро.
\param stat Указатель на массив статистики Ядра, либо сигнала.
\return ID процессороного ядра с наименьшей нагрузкой.
*/
core_id_t sched_load_balancer(proc_t * proc, stat_t * stat);
/*!
\brief Функция поиска процессорного Ядра с максимальной нагрузкой.

Используется в глобальном ленивом балансировщике нагрузки и функции sig_signal.

\param stat Указатель на массив статистики Ядра, либо сигнала.
\return ID процессороного ядра с наибольшей нагрузкой.
*/
core_id_t sched_highest_load_core( stat_t * stat );
#endif // CONFIG_MP
#endif // _SCHED_H_
