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
#ifndef _GITEM_H_
#define _GITEM_H_
/*!
\file
\brief \~russian Заголовок элементов группированного списка. \~english A grouped list item header.
*/
//Элемент группированного списка
typedef struct _gitem_t gitem_t;
//свойства
/*!
\brief
\~russian Элемент группированного списка. \~english A grouped list item.

\~russian Такой элемент постоянно состоит в одной из групп (смотри #group_t).
В каждом таком элементе gitem_t есть поле типа group_t,
это группа, в которую изначально включен элемент.

\~english A grouped list item is included to some group (look at #group_t).
Every grouped list item has a #group_t field,
that is used as initial group for a grouped list item.
*/
struct _gitem_t
{
    item_t parent; /*!< \~russian Родитель - элемент 2-связного списка. \~english A parent (list item). */
    group_t * group; /*!< \~russian Указатель на группу, в которую сейчас включен элемент. \~english A pointer to a current group. */
    group_t grp; /*!< \~russian Выделение памяти под группу, в нее изначально будет включен элемент. \~english A group storage and initial group. */
};

/*!
   \~russian Статическая инициализация объекта типа gitem_t. \~english A stasic gitem_t object initiation.
   \param a \~russian Имя переменной типа gitem_t. \~english A #gitem_t variable name.
   \param p \~russian Приоритет. \~english A priority.
*/
#define INIT_G_ITEM_T(a,p) { INIT_ITEM_T(a), &((gitem_t)a).grp, INIT_GROUP_T(p) }

//Методы
/*!
\brief
\~russian Инициализация объекта типа #gitem_t. \~english A #gitem_t object initiation.

\param gitem \~russian Указатель на объект #gitem_t. \~english A #gitem_t pointer.
\param prio \~russian Приоритет элемента. \~english A priority.
*/
void gitem_init(gitem_t * gitem, prio_t prio);
/*!
\brief
\~russian Вставка элемента типа #gitem_t в список типа #xlist_t без группировки. \~english Insert to list without grouping.

\param gitem \~russian Указатель на объект #gitem_t. \~english A #gitem_t pointer.
\param xlist \~russian Указатель на список. \~english A pointer to a list.
*/
void gitem_insert(gitem_t * gitem, xlist_t *xlist);
/*!
\brief
\~russian Вставка элемента типа #gitem_t в список типа #xlist_t с группировкой. \~english Insert to list with grouping.

\~russian Вставляет в часть списка с приоритетом prio = gitem->group->prio, и переносит элемент в группу xlist->item[prio]->group, при этом gitem->group переходит в Пул.
\~english This function inserts a #gitem_t object to #xlist_t container with grouping, current process group is transfered to the kernel.pool.

\param gitem \~russian Указатель на объект #gitem_t. \~english A #gitem_t pointer.
\param xlist \~russian Указатель на список. \~english A pointer to a list.
*/
void gitem_insert_group(gitem_t * gitem, xlist_t *xlist);
/*!
\brief
\~russian Быстро вырезать из списка. \~english Fast cut grouped item from a list.

\~russian Вырезает объект типа #gitem_t, из списка типа #xlist_t, если объект был сгруппирован, то он вырезается из группы, и для него выделяется группа из Пула. При этом не обнуляется указатель gitem->group->link.
\~english This function cuts a #gitem_t object from #xlist_t container.
If a #gitem_t object was insert to list with grouping, then ungrouping is done, new group is taken from the kernel.pool.

\param gitem \~russian Указатель на объект #gitem_t. \~english A #gitem_t pointer.
*/
void gitem_fast_cut(gitem_t * gitem);
/*!
\brief
\~russian Вырезать из списка. \~english Cut #gitem_t oblect from #xlist_t container.

\~russian Вызывает #gitem_fast_cut, а потом таки обнуляет gitem->group->link \~english This function calls #gitem_fast_cut and then nulls gitem->group->link.

\param gitem \~russian Указатель на объект #gitem_t. \~english A #gitem_t pointer.
*/
void gitem_cut(gitem_t * gitem);
/*!
\brief
\~russian Переносит все элементы из одного группированного списка в другой. \~english Transfer all #gitem_t objects from a grouped #xlist_t container to another.

\~russian Перенести все элементы из группированного списка типа #xlist_t в другой список типа #xlist_t. Выполняется за O(1) шагов.
\~english This function takes all #gitem_t objects from one #xlist_t container to another. This function is O(1).
A source container must store only #gitem_t objects,
provided that #gitem_t objects on a same priority level must be included to one group.

\param source \~russian Указатель на список из которого переносим элементы. \~english A source #xlist_t pointer.
\param destignation \~russian Указатель на список в который преносим элементы. \~english A destignation #xlist_t object.
*/
void gitem_xlist_merge(xlist_t * source, xlist_t * destignation);

#endif // _GITEM_H_
