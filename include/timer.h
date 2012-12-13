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
#ifndef _TIMER_H_
#define _TIMER_H_

/*!
\file
\~russian
\brief
Заголовок программных таймеров.

Программные таймеры используются для синхронизации процессов по времени.

\warning Программные таймеры нельзя использовать для точного измерения интервалов времени!

\~english
\brief
A software timer headers.

Software timers used for time-process synchronization.

\warning Software timers can not be used for precision time interval measurement!
*/

/*!
\def SPIN_LOCK_KERNEL_TIMER()
\~russian
\brief
Макрос-обертка.

Обертка захвата спин-блокировки таймера ядра, на однопроцессорной системе - пустой макрос.

\~english
\brief
Wrapper macro.

A wrapper for kernel timer spin-lock, on single core system - empty macro.

\def SPIN_UNLOCK_KERNEL_TIMER()

\~russian
\brief
Макрос-обертка.

Обертка освобождения спин-блокировки таймера ядра, на однопроцессорной системе - пустой макрос.

\~english
\brief
Wrapper macro.

A wrapper for kernel timer spin-unlock, on single core system - empty macro.
*/
#ifdef CONFIG_MP

#define SPIN_LOCK_KERNEL_TIMER() spin_lock( &kernel.timer_lock )
#define SPIN_UNLOCK_KERNEL_TIMER() spin_unlock( &kernel.timer_lock )

#else

#define SPIN_LOCK_KERNEL_TIMER()
#define SPIN_UNLOCK_KERNEL_TIMER()

#endif

// Работа с программными таймерами
/*!
\brief
\~russian
Сброс программного таймера.

\param t Имя переменной таймера.

\~english
Reset software timer.

\param t A timer variable name.
*/
#define CLEAR_TIMER(t) _clear_timer( (timer_t *)&t)
/*!

\~russian
\brief
Получить значение программного таймера, для внутреннего использования.

\param t Значение таймера.

\~english
\brief
Get software timer value.

\param t Software timer value.
*/
#define TIMER(t) (timer_t)_timer( (timer_t)t )
/*!
\~russian
\brief
Подождать заданный интервал времени.

Просто ждет в цикле пока пройдет время time.

\param time Время ожидания.

\~english
\brief
Wait for certain time.

Caller process spins in a loop for a time.

\param time Wait time.
*/
void wait_time( timer_t time );

// Для внутреннего пользования
/*!
\~russian
\brief
Сброс программного таймера, для внутреннего использования.

\param t Указатель на таймер.

\~english
\brief
Clear software timer. For unternal usage.

\param t A pointer to a timer.
*/
void _clear_timer(timer_t * t);
/*!
\~russian
\brief
Получить значение программного таймера, для внутреннего использования.

\param t Значение таймера.

\~english
\brief
Get software timer. For internal usage.

\param t A timer value.
*/
timer_t _timer(timer_t t);

#endif // _TIMER_H_
