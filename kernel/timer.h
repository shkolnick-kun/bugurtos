/**************************************************************************
    BuguRTOS-0.9.x (Bugurt real time operating system)
    Copyright (C) 2015 anonimous

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
\def BGRT_SPIN_LOCK_KERNEL_TIMER()
\~russian
\brief
Макрос-обёртка.

Обёртка захвата спин-блокировки таймера ядра, на однопроцессорной системе - пустой макрос.

\~english
\brief
Wrapper macro.

A wrapper for kernel timer spin-lock, on single core system - empty macro.
*/
/*!
\def BGRT_SPIN_FREE_KERNEL_TIMER()

\~russian
\brief
Макрос-обёртка.

Обёртка освобождения спин-блокировки таймера ядра, на однопроцессорной системе - пустой макрос.

\~english
\brief
Wrapper macro.

A wrapper for kernel timer spin-free, on single core system - empty macro.
*/
#ifdef BGRT_CONFIG_MP
#   define BGRT_SPIN_LOCK_KERNEL_TIMER() bgrt_spin_lock( &bgrt_kernel.timer_lock )
#   define BGRT_SPIN_FREE_KERNEL_TIMER() bgrt_spin_free( &bgrt_kernel.timer_lock )
#else // BGRT_CONFIG_MP
#   define BGRT_SPIN_LOCK_KERNEL_TIMER()
#   define BGRT_SPIN_FREE_KERNEL_TIMER()
#endif // BGRT_CONFIG_MP

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
#define BGRT_CLEAR_TIMER(t) _bgrt_clear_timer( (bgrt_tmr_t *)&t)

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
#define BGRT_TIMER(t) (bgrt_tmr_t)_bgrt_timer( (bgrt_tmr_t)t )

/*!
\~russian
\brief
Подождать заданный интервал времени.

Просто ждёт в цикле пока пройдёт время time.

\param time Время ожидания.

\~english
\brief
Wait for certain time.

Caller process spins in a loop for a time.

\param time Wait time.
*/
void bgrt_wait_time( bgrt_tmr_t time );
// Для внутреннего пользования

/*!
\~russian
\brief
Сброс программного таймера.

\warning Для внутреннего использования.

\param t Указатель на таймер.

\~english
\brief
Clear software timer.

\warning For internal usage.

\param t A pointer to a timer.
*/
void _bgrt_clear_timer(bgrt_tmr_t * t);

/*!
\~russian
\brief
Получить значение программного таймера.

\warning Для внутреннего использования.

\param t Значение таймера.

\~english
\brief
Get software timer value.

\warning For internal usage.

\param t A timer value.
*/
bgrt_tmr_t _bgrt_timer(bgrt_tmr_t t);

#endif // _TIMER_H_
