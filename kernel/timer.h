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
#ifndef TIMER_H
#define TIMER_H
BGRT_CDECL_BEGIN
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

typedef struct bgrt_priv_ktimer_t bgrt_ktimer_t;/*!< \~russian Системный таймер (используется для подсчёта времени Ядром). \~english The system timer (used by the kernel to count ticks). */
struct bgrt_priv_ktimer_t
{
    void (*tick)(void);           /*!< \~russian Хук. \~english A hook pointer. */
    bgrt_tmr_t val;               /*!< \~russian Значение. \~english A value. */
#ifdef BGRT_CONFIG_MP
    bgrt_lock_t lock;             /*!< \~russian Спин-блокировка. \~english A spin-lock. */
#endif /*BGRT_CONFIG_MP*/
};
/*Работа с программными таймерами*/
/*!
\brief
\~russian
Сброс программного таймера.

\param t Имя переменной таймера.

\~english
Reset software timer.

\param t A timer variable name.
*/
#define BGRT_CLEAR_TIMER(t) bgrt_priv_clear_timer((bgrt_tmr_t *)&t)

/*!
\brief
\~russian
Установка программного таймера.

Может быть использована вместо #BGRT_CLEAR_TIMER для периодического вызова кода,
в этом случае поведение таймеров будет детерминированным, не будет наблюдаться
рассинхронизации.

\param t Имя переменной таймера.
\param s Шаг таймера.

\~english
Set software timer.

May be used instead of #BGRT_CLEAR_TIMER for periodic code execution.
Software timers will have deterministic behavior. Software timers with the same
period will work synchronously.

\param t A timer variable name.
\param s A timer step.
*/
#define BGRT_SET_TIMER(t,s) (t += s)

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
#define BGRT_TIMER(t) (bgrt_tmr_t)bgrt_priv_timer((bgrt_tmr_t)t)

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
void bgrt_wait_time(bgrt_tmr_t time);

/*!
\~russian
\brief
Вызывающий процесс ожидает в цикле, когда системное время становится больше или равно, чем tmr + time.

\param tmr Имя переменной таймера.
\param time Интервал времени ожидания.

\~english
\brief
The caller waits until system time becomes greater or equal than tmr + time.

\param tmr A timer variable name.
\param time Wait time interval.
*/
#define BGRT_WAIT_INTERVAL(tmr, time) (bgrt_priv_wait_interval(&tmr, time))
/*Для внутреннего пользования*/

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
void bgrt_priv_clear_timer(bgrt_tmr_t * t);

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
bgrt_tmr_t bgrt_priv_timer(bgrt_tmr_t t);

/*!
\~russian
\brief
Вызывающий процесс ожидает в цикле, когда системное время становится больше или равно, чем *tmr + time.

\warning Для внутреннего использования.

\param tmr Указатель на таймер.
\param time Интервал времени ожидания.

\~english
\brief
The caller waits until system time becomes greater or equal than *tmr + time.

\warning For internal usage.

\param tmr A pointer to a timer.
\param time Wait time interval.
*/
void bgrt_priv_wait_interval(bgrt_tmr_t * tmr, bgrt_tmr_t time);

BGRT_CDECL_END
#endif /*TIMER_H*/
