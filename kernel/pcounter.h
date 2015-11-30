/**************************************************************************
    BuguRTOS-0.8.x (Bugurt real time operating system)
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
#ifndef _BGRT_PCOUNTER_H_
#define _BGRT_PCOUNTER_H_
/*!
\file
\brief \~russian Заголовок счетчиков захваченных ресурсов. \~english A locked resource counter header.
*/
typedef struct _bgrt_pcounter_t bgrt_pcounter_t; /*!< \~russian Смотри #_bgrt_pcounter_t; \~english See #_bgrt_pcounter_t; */
/*!
\~russian
\brief
Счетчик захваченных ресурсов.

Используется для хранения информации о наследуемых приоритетах.

\~english
\brief
A locked resource counter.

#bgrt_pcounter_t objects are used to store information about iherited priorities.
*/
struct _bgrt_pcounter_t
{
    bgrt_cnt_t counter[BGRT_BITS_IN_INDEX_T]; /*!< \~russian Массив счетчиков. \~english A counter array. */
    bgrt_index_t index; /*!< \~russian Индекс для ускорения поиска. \~english An index to speedup search. */
};

/*!
\~russian
\brief
Инициализация счетчика.

\warning Для внутреннего использования.

\param pcounter Указатель на счетчик.

\~english
\brief
A #bgrt_pcounter_t object initiation.

\warning Internal usage function.

\param pcounter A #bgrt_pcounter_t pointer.
*/
void bgrt_pcounter_init(bgrt_pcounter_t * pcounter);

/*!
\~russian
\brief
Инкремент счетчика.

\warning Для внутреннего использования.

\param pcounter Указатель на счетчик.
\param prio Приоритет.

\~english
\brief
Increment counter.

\warning Internal usage function.

\param pcounter A #bgrt_pcounter_t pointer.
\param prio A priority.
*/
void bgrt_pcounter_inc(bgrt_pcounter_t * pcounter, bgrt_prio_t prio);
/*!
\~russian
\brief
Декремент счетчика.

\warning Для внутреннего использования.

\param pcounter Указатель на счетчик.
\param prio Приоритет.

\~english
\brief
Decrement counter.

\warning Internal usage function.

\param pcounter A #bgrt_pcounter_t pointer.
\param prio A priority.
*/
bgrt_index_t bgrt_pcounter_dec(bgrt_pcounter_t * pcounter, bgrt_prio_t prio);
/*!
\~russian
\brief
Увеличение счетчика на произвольное количество единиц.

\warning Для внутреннего использования.

\param pcounter Указатель на счетчик.
\param prio Приоритет.
\param count Количество единиц.

\~english
\brief
Increase counter by a number of steps.

\warning Internal usage function.

\param pcounter A #bgrt_pcounter_t pointer.
\param prio A priority.
\param count A number of increment steps.
*/
void bgrt_pcounter_plus(bgrt_pcounter_t * pcounter, bgrt_prio_t prio, bgrt_cnt_t count);
/*!
\~russian
\brief
Уменьшение счетчика на произвольное количество единиц.

\warning Для внутреннего использования.

\param pcounter Указатель на счетчик.
\param prio Приоритет.
\param count Количество единиц.
\return 0 - если соответствующая часть счетчика обнулилась, не 0 - в других случаях.

\~english
\brief
Decrease counter by a number of steps;

\warning Internal usage function.

\param pcounter A #bgrt_pcounter_t pointer.
\param prio A priority.
\param count A number of decrement steps.
\return 0 if correspondent counter is nulled, not 0 else.
*/
bgrt_index_t bgrt_pcounter_minus(bgrt_pcounter_t * pcounter, bgrt_prio_t prio, bgrt_cnt_t count);
#endif // _BGRT_PCOUNTER_H_
