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
#ifndef BGRT_PCOUNTER_H
#define BGRT_PCOUNTER_H
BGRT_CDECL_BEGIN
/*!
\file
\brief \~russian Заголовок счётчиков захваченных ресурсов. \~english A locked resource counter header.
*/

/*!
\~russian
\brief
Инкремент счётчика.

\warning Для внутреннего использования.

\param val Текущее значение счётчика.
\return Новое значение счётчика.

\~english
\brief
Increment counter.

\warning Internal usage function.

\param val Current counter value.
\return New counter value.
*/
bgrt_cnt_t bgrt_cnt_inc(bgrt_cnt_t val);
/*!
\~russian
\brief
Декремент счётчика.

\warning Для внутреннего использования.

\param val Текущее значение счётчика.
\return Новое значение счётчика.

\~english
\brief
Decrement counter.

\warning Internal usage function.

\param val Current counter value.
\return New counter value.
*/
bgrt_cnt_t bgrt_cnt_dec(bgrt_cnt_t val);
/*!
\~russian
\brief
Добавление к значению счётчика.

\warning Для внутреннего использования.

\param a Текущее значение счётчика.
\param b Изменение.
\return Новое значение счётчика.

\~english
\brief
Addition to counter value.

\warning Internal usage function.

\param a Current counter value.
\param b Change of value.
\return New counter value.
*/
bgrt_cnt_t bgrt_cnt_add(bgrt_cnt_t a, bgrt_cnt_t b);
/*!
\~russian
\brief
Вычитание из значения счётчика.

\warning Для внутреннего использования.

\param a Текущее значение счётчика.
\param b Изменение.
\return Новое значение счётчика.

\~english
\brief
Subtraction from counter value.

\warning Internal usage function.

\param a Current counter value.
\param b Change of value.
\return New counter value.
*/
bgrt_cnt_t bgrt_cnt_sub(bgrt_cnt_t a, bgrt_cnt_t b);

#define BGRT_CNT_INC(cnt)(cnt = bgrt_cnt_inc(cnt)) /*!< \~russian Обёртка над #bgrt_cnt_inc; \~english A wrappet for #bgrt_cnt_inc; */
#define BGRT_CNT_DEC(cnt)(cnt = bgrt_cnt_dec(cnt)) /*!< \~russian Обёртка над #bgrt_cnt_dec; \~english A wrappet for #bgrt_cnt_dec; */
#define BGRT_CNT_ADD(cnt, delta)(cnt = bgrt_cnt_add(cnt, delta)) /*!< \~russian Обёртка над #bgrt_cnt_add; \~english A wrappet for #bgrt_cnt_add; */
#define BGRT_CNT_SUB(cnt, delta)(cnt = bgrt_cnt_sub(cnt, delta)) /*!< \~russian Обёртка над #bgrt_cnt_sub; \~english A wrappet for #bgrt_cnt_sub; */

typedef struct bgrt_priv_pcounter_t bgrt_pcounter_t; /*!< \~russian Смотри #bgrt_priv_pcounter_t; \~english See #bgrt_priv_pcounter_t; */
/*!
\~russian
\brief
Счётчик захваченных ресурсов.

Используется для хранения информации о наследуемых приоритетах.

\~english
\brief
A locked resource counter.

#bgrt_pcounter_t objects are used to store information about inherited priorities.
*/
struct bgrt_priv_pcounter_t
{
    bgrt_cnt_t counter[BGRT_BITS_IN_INDEX_T]; /*!< \~russian Массив счётчиков. \~english A counter array. */
    bgrt_map_t map; /*!< \~russian Индекс для ускорения поиска. \~english An map to speedup search. */
};

/*!
\~russian
\brief
Инициализация счётчика.

\warning Для внутреннего использования.

\param pcounter Указатель на счётчик.

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
Инкремент счётчика.

\warning Для внутреннего использования.

\param pcounter Указатель на счётчик.
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
Декремент счётчика.

\warning Для внутреннего использования.

\param pcounter Указатель на счётчик.
\param prio Приоритет.

\~english
\brief
Decrement counter.

\warning Internal usage function.

\param pcounter A #bgrt_pcounter_t pointer.
\param prio A priority.
*/
bgrt_map_t bgrt_pcounter_dec(bgrt_pcounter_t * pcounter, bgrt_prio_t prio);
/*!
\~russian
\brief
Увеличение счётчика на произвольное количество единиц.

\warning Для внутреннего использования.

\param pcounter Указатель на счётчик.
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
Уменьшение счётчика на произвольное количество единиц.

\warning Для внутреннего использования.

\param pcounter Указатель на счётчик.
\param prio Приоритет.
\param count Количество единиц.
\return 0 - если соответствующая часть счётчика обнулилась, не 0 - в других случаях.

\~english
\brief
Decrease counter by a number of steps;

\warning Internal usage function.

\param pcounter A #bgrt_pcounter_t pointer.
\param prio A priority.
\param count A number of decrement steps.
\return 0 if correspondent counter is nulled, not 0 else.
*/
bgrt_map_t bgrt_pcounter_minus(bgrt_pcounter_t * pcounter, bgrt_prio_t prio, bgrt_cnt_t count);

BGRT_CDECL_END
#endif /*BGRT_PCOUNTER_H*/
