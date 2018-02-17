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
#ifndef CRIT_SEC_H
#define CRIT_SEC_H
BGRT_CDECL_BEGIN
/*!
\file
\~russian
\brief
Заголовок критических секций.

Критическая секция - область кода, в которой запрещены все прерывания. Критические секции используются, когда надо использовать общий ресурс в течение короткого времени.

Критические секции могут быть вложенные, в этом случае прерывания разрешаются,
когда произошёл выход из всех критических секций.

\~english
\brief
A critical section header.

A critical section is a part of a code where interrupts are disabled.
Critical sections are used when a common data are used for a short time.
Critical sections may be nested, in this case interrupts get enabled on exit from all critical sections.
*/

/*!
\def BGRT_CRIT_SEC_ENTER()
\~russian
\brief Макрос-обёртка.

Вход в критическую секцию.
\warning Использовать в начале блока!
\warning Все локальные переменные должны быть объявлены до #BGRT_CRIT_SEC_ENTER

\~english
\brief A wrapper macro.

A critical section start.
\warning Must be used on a start of a code block!
\warning All local variables must be declared before #BGRT_CRIT_SEC_ENTER, and all executable code must be below it.
*/
/*!
\def BGRT_CRIT_SEC_EXIT()
\~russian
\brief Макрос-обёртка.

Выход из критической секции.
\warning Использовать в конце блока!

\~english
\brief A wrapper macro.

A critical section end.
\warning Must be used at the end of a code block.
*/
#ifdef BGRT_CONFIG_MP
#   define BGRT_CRIT_SEC_ENTER() bgrt_cpuid_t current_core; \
                         current_core = bgrt_priv_crit_sec_enter()
#   define BGRT_CRIT_SEC_EXIT() bgrt_priv_crit_sec_exit(current_core)

/*!
\~russian
\brief Вход в критическую секцию на многопроцессорной системе.

\return
 ID процессорного ядра, на котором выполняется.
\~english
\brief A critical section start on a multicore system.

\return
 An ID of the local CPU core.
*/
bgrt_cpuid_t bgrt_priv_crit_sec_enter(void);
/*!
\~russian
\brief Выход из критической секции на многопроцессорной системе

\param core ID процессорного ядра, на котором выполняется.

\warning Передача ID процессорного ядра, отличного от того, где запускается функция приведёт к непредсказуемым последствиям.
\~english
\brief A critical section end on a multicore system.

\param core An id of a local CPU core.

\warning If core param don't match the local CPU core the behavior is undefined.
*/
void bgrt_priv_crit_sec_exit(bgrt_cpuid_t core);
#else
#   define BGRT_CRIT_SEC_ENTER() bgrt_crit_sec_enter()
#   define BGRT_CRIT_SEC_EXIT() bgrt_crit_sec_exit()
/*!
\~russian
\brief Вход в критическую секцию.
\~english
\brief A critical section start.
*/
void bgrt_crit_sec_enter(void);
/*!
\~russian
\brief Выход из критической секции.
\~english
\brief A critical section end.
*/
void bgrt_crit_sec_exit(void);
#endif /*BGRT_CONFIG_MP*/

BGRT_CDECL_END
#endif /* CRIT_SEC_H */
