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
#ifndef BGRT_XLIST_H
#define BGRT_XLIST_H
BGRT_CDECL_BEGIN
/*!
\file

\~russian
\brief
Заголовок списков с приоритетами.

\~english
\brief
A prioritized list header.
*/
typedef struct bgrt_priv_xlist_t bgrt_xlist_t; /*!< \~russian Смотри #bgrt_priv_xlist_t; \~english See #bgrt_priv_xlist_t; */
/*Свойства*/
/*!
\~russian
\brief
Список с приоритетами.

Такой список хранит ссылки на структуры типа #bgrt_item_t. Фактически в нем будут храниться ссылки на элементы типа #bgrt_pitem_t.

\~english
\brief
A prioritized list.

A container type, #bgrt_xlist_t objects store lists of #bgrt_item_t objects.
In fact these containers store lists of #bgrt_pitem_t or other compatible objects.
*/
struct bgrt_priv_xlist_t
{
    bgrt_item_t * item[BGRT_BITS_IN_INDEX_T]; /*!< \~russian Массив указателей на элементы. \~english An array of list head pointers. */
    bgrt_map_t map; /*!< \~russian Индекс, показывает, где в массиве ненулевые указатели. \~english Index for fast search. */
};
/*Методы*/
/*!
\~russian
\brief
Инициализация списка.

\warning Для внутреннего использования.

\param xlist Указатель на список.

\~english
\brief
An #bgrt_xlist_t object initiation.

\warning For internal usage.

\param xlist An #bgrt_xlist_t pointer.
*/
void bgrt_xlist_init(
    bgrt_xlist_t * xlist
);

/*!
\~russian
\brief
Поиск головы списка.

\warning Для внутреннего использования.

\param xlist Указатель на список.
\return Указатель на голову - самый приоритетный элемент в массиве указателей.

\~english
\brief
List head search.

\warning For internal usage.

\param xlist An #bgrt_xlist_t pointer.
\return The head pointer, which is the most prioritized pointer in the list head pointer array.
*/
bgrt_item_t * bgrt_xlist_head(bgrt_xlist_t * xlist);

/*!
\brief

\~russian
Переключение списка.

Изменяет указатель xlist->item[prio] на xlist->item[prio]->next.

\warning Для внутреннего использования.

\param xlist Указатель на список.
\param prio Приоритет переключаемой части списка.

\~english
Switch a head pointer.

Does xlist->item[prio] = xlist->item[prio]->next.

\warning For internal usage.

\param xlist An #bgrt_xlist_t pointer.
\param prio A priority to switch.
*/
void bgrt_xlist_switch (bgrt_xlist_t * xlist, bgrt_prio_t prio);

/*---------------------------------------------------
Для типов элементов, ссылки на которые будут хранится в bgrt_xlist_t
должны быть определены методы

"вырезать"
"вставить"
"переместить в другой список"
----------------------------------------------------*/
BGRT_CDECL_END
#endif /*BGRT_XLIST_H*/
