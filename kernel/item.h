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
#ifndef ITEM_H
#define ITEM_H
BGRT_CDECL_BEGIN
/*!
\file
\brief \~russian Заголовок элементов 2-связного списка. \~english A list item header.
*/
/*Элемент 2-связного списка;*/
typedef struct bgrt_priv_item_t bgrt_item_t; /*!< \~russian Смотри #bgrt_priv_item_t; \~english See #bgrt_priv_item_t; */
/*Свойства*/
/*!
\~russian
\brief Элемент 2-связного списка.

Все структуры, где будут применяться 2-связные списки, унаследуют свойства и методы #bgrt_item_t.

\~english
\brief A list item.

All structures, that must be listed, will inherit #bgrt_item_t properties and methods.
*/
struct bgrt_priv_item_t
{
    bgrt_item_t *next;  /*!< \~russian Следующий элемент. \~english Next item in a list. */
    bgrt_item_t *prev;  /*!< \~russian Предыдущий элемент. \~english Previous item in a list. */
};

/*!
   \~russian
   Статическая инициализация объекта типа #bgrt_item_t.
   \warning Для внутреннего использования.
   \param a Имя переменной типа #bgrt_item_t.

   \~english
   Static item initiation.
   \warning For internal usage.
   \param a An #bgrt_item_t variable name.
*/
#define BGRT_ITEM_T_INIT(a) { (bgrt_item_t *)&a, (bgrt_item_t *)&a }

/*Методы*/
/*!
\~russian
\brief
Инициализация объекта типа #bgrt_item_t.

\warning Для внутреннего использования.

\param item Указатель на объект #bgrt_item_t.

\~english
\brief
An #bgrt_item_t object initiation.

\warning Internal usage function.

\param item An #bgrt_item_t pointer.
*/
void bgrt_item_init(bgrt_item_t *item);
/*!
\~russian
\brief
Вставка элемента типа #bgrt_item_t в список.

\warning Для внутреннего использования.

\param item Указатель на объект типа #bgrt_item_t, который будем вставлять.
\param head Указатель на голову списка типа #bgrt_item_t.

\~english
\brief
Insert an item to a list.

\warning Internal usage function.

\param item \~english A pointer to an item.
\param head \~english A pointer to a destination list head.
*/
void bgrt_item_insert(bgrt_item_t *item, bgrt_item_t *head);
/*!
\~russian
\brief
Вырезать элемент типа #bgrt_item_t из списка.

\warning Для внутреннего использования.

\param item Указатель на объект типа #bgrt_item_t, который будем вырезать.

\~english
\brief
Cut an item from a list.

\warning Internal usage function.

\param item A pointer to an item to cut.
*/
void bgrt_item_cut(bgrt_item_t *item);

BGRT_CDECL_END
#endif /*ITEM_H*/
