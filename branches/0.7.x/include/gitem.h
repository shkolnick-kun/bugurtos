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
#ifndef _GITEM_H_
#define _GITEM_H_
/*!
\file

\~russian
\brief Заголовок элементов группированного списка.

\~english
\brief A grouped list and item header.
*/
//Элемент группированного списка
typedef struct _gitem_t gitem_t; /*!< \~russian Элемент группированного списка с приоритетами. \~english Grouped priority list item */
//свойства
/*!
\~russian
\brief
Элемент группированного списка.

Такой элемент постоянно состоит в одной из групп (смотри #group_t). В каждом таком элементе #gitem_t есть поле типа #group_t, это группа, в которую изначально включен элемент.

\~english
\brief
A grouped list item.

Such an item is allways in some group (see #group_t). Every #gitem_t object has a #group_t field, that field is a group that holds this #gitem_t object at the begining.
*/
struct _gitem_t
{
    item_t parent;      /*!< \~russian Родитель - элемент 2-связного списка.                                \~english A tarent type is #item_t. */
    group_t * group;    /*!< \~russian Указатель на группу, в которую сейчас включен элемент.               \~english A pointer to current group.*/
    group_t grp;        /*!< \~russian Выделение памяти под группу, в нее изначально будет включен элемент. \~english A group field, used as initial group.*/
};

typedef struct _gxlist_t gxlist_t; /*!< \~russian Группированный список с приоритетами (Расширение типа #xlixt_t) \~english A grouped xlist (#xlist_t extension).*/
struct _gxlist_t
{
    xlist_t parent;     /*!< \~russian Родительский тип - #xlist_t.             \~english Parent type is #xlist_t. */
    pool_t pool;        /*!< \~russian Пул для хранения неиспользуемых групп.   \~english Unused #group_t objects container.*/
};
/*!
   \~russian

   Статическая инициализация объекта типа #gitem_t.
   \param a - Имя переменной типа #gitem_t.
   \param p - Приоритет.

   \~english

   Static #gitem_t object initiation.
   \param a - A #gitem_t object name.
   \param p - A priority.
*/
#define INIT_G_ITEM_T(a,p) { INIT_ITEM_T(a), &a.grp, INIT_GROUP_T(p) }

//Методы
/*!
\~russian
\brief
Инициализация объекта типа #gitem_t.

\param gitem Указатель на объект #gitem_t.
\param prio Приоритет элемента.

\~english
\brief
A #gitem_t object initiation.

\param gitem A #gitem_t pointer.
\param prio A priority.
*/
void gitem_init(gitem_t * gitem, prio_t prio);
/*!
\~russian
\brief
Вставка элемента типа #gitem_t в список типа #xlist_t без группировки.

\param gitem Указатель на объект #gitem_t.
\param xlist Указатель на список.

\~english
\brief
Inserts #gitem_t object to an #xlist_t container.

\param gitem A #gitem_t pointer.
\param xlist An #xlist_t container pointer.
*/
void gitem_insert(gitem_t * gitem, xlist_t *xlist);
/*!
\~russian
\brief
Вставка элемента типа #gitem_t в список типа #gxlist_t.

Вставляет в часть списка с приоритетом prio = gitem->group->prio, и переносит элемент в группу gxlist->parent.item[prio]->group, при этом gitem->group переходит в пул.

\param gitem Указатель на объект #gitem_t.
\param gxlist Указатель на список.


\~english
\brief
Inserts #gitem_t object to a #gxlist_t container.

A #gitem_t object is inserted to a list with prio = gitem->group->prio, object is also transfered to gxlist->parent.item[prio]->group, its original gitem->group is pushed to local pool (see #pool_t).

\param gitem A #gitem_t pointer.
\param gxlist A #gxlist_t container pointer.
*/
void gitem_insert_group(gitem_t * gitem, gxlist_t *gxlist);
/*!
\~russian
\brief
Быстро вырезать из списка.

Вырезает объект типа #gitem_t, из соответствующего списка, если объект был сгруппирован, то он вырезается из группы, и для него выделяется группа из Пула. При этом не обнуляется указатель gitem->group->link.

\param gitem Указатель на объект gitem_t.

\~english
\brief
Cuts a #gitem_t object from its container.

Cuts  a #gitem_t object, from its cintainer. If #gitem_t object was in #gxlist_t container, then it is cut from its group, new group for this object is poped from local pool. A gitem->group->link pointer is not cleared.
\param gitem A #gitem_t object pointer.
*/
void gitem_fast_cut(gitem_t * gitem);
/*!
\~russian
\brief
Вырезать из списка.

Вызывает gitem_fast_cut, а потом таки обнуляет gitem->group->link

\param gitem Указатель на объект gitem_t.

\~english
\brief
Cuts a #gitem_t object from its container.

Calls #gitem_fast_cut and then clears gitem->group->link pointer.

\param gitem A #gitem_t pointer.
*/
void gitem_cut(gitem_t * gitem);

/*!
\~russian
\brief
Инициация списка типа #gxlist_t.

\param gxlist Указатель типа #gxlist_t *.

\~english
\brief
A #gxlist_t object initiation.

\param gxlist A #gxlist_t pointer.
*/
void gxlist_init( gxlist_t * gxlist );
/*!
\~russian
\brief
Переносит все элементы из одного группированного списка в другой

Перенести все элементы из группированного списка типа gxlist_t в другой список типа gxlist_t. Выполняется за O(1) шагов.

\param source Указатель на список из которого переносим элементы.
\param destignation Указатель на список в который преносим элементы.

\~english
\brief
Transfers all #gitem_t obcets from one #gxlist_t container to another.

Has O(1) complexity.

\param source Source container pointer.
\param destignation Destignation container pointer.
*/
void gxlist_merge(gxlist_t * source, gxlist_t * destignation);

#endif // _GITEM_H_
