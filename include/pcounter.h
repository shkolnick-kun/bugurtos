/**************************************************************************
    BuguRTOS-0.7.x(Bugurt real time operating system)
    Copyright (C) 2014  anonimous

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
#ifndef _PCOUNTER_H_
#define _PCOUNTER_H_
/*!
\file
\brief \~russian Заголовок счетчиков захваченных ресурсов. \~english A locked resource counter header.
*/
typedef struct _pcounter_t pcounter_t; /*!< \~russian Смотри #_pcounter_t; \~english See #_pcounter_t; */
/*!
\~russian
\brief
Счетчик захваченных ресурсов.

При использовании опции CONFIG_USE_HIGHEST_LOCKER используется для пересчета захваченных процессом ресурсов.

\~english
\brief
A locked resource counter.

#pcounter_t objects are used to count mutex controled resources locked by processes when CONFIG_USE_HIGHEST_LOCKER is defined.
*/
struct _pcounter_t
{
    count_t counter[BITS_IN_INDEX_T]; /*!< \~russian Массив счетчиков. \~english A counter array. */
    index_t index; /*!< \~russian Индекс для ускорения поиска. \~english An index to speedup search. */
};

/*!
\~russian
\brief
Инициализация счетчика.

\param pcounter Указатель на счетчик.

\~english
\brief
A #pcounter_t object initiation.

\param pcounter A #pcounter_t pointer.
*/
void pcounter_init(pcounter_t * pcounter);

/*!
\~russian
\brief
Инкремент счетчика.

\param pcounter Указатель на счетчик.
\param prio Приоритет.

\~english
\brief
Increment counter.

\param pcounter A #pcounter_t pointer.
\param prio A priority.
*/
void pcounter_inc(pcounter_t * pcounter, prio_t prio);
/*!
\~russian
\brief
Декремент счетчика.

\param pcounter Указатель на счетчик.
\param prio Приоритет.

\~english
\brief
Decrement counter.

\param pcounter A #pcounter_t pointer.
\param prio A priority.
*/
index_t pcounter_dec(pcounter_t * pcounter, prio_t prio);
/*!
\~russian
\brief
Увеличение счетчика на произвольное количество единиц.

\param pcounter Указатель на счетчик.
\param prio Приоритет.
\param count Количество единиц.

\~english
\brief
Increase counter by a number of steps.

\param pcounter A #pcounter_t pointer.
\param prio A priority.
\param count A number of increment steps.
*/
void pcounter_plus(pcounter_t * pcounter, prio_t prio, count_t count);
/*!
\~russian
\brief
Уменьшение счетчика на произвольное количество единиц.

\param pcounter Указатель на счетчик.
\param prio Приоритет.
\param count Количество единиц.
\return 0 - если соответствующая часть счетчика обнулилась, не 0 - в других случаях.

\~english
\brief
Decrease counter by a number of steps;

\param pcounter A #pcounter_t pointer.
\param prio A priority.
\param count A number of decrement steps.
\return 0 if correspondent counter is nulled, not 0 else.
*/
index_t pcounter_minus(pcounter_t * pcounter, prio_t prio, count_t count);
#endif // _PCOUNTER_H_
