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
\brief Заголовок элементов группированного списка.
*/
//Элемент группированного списка
typedef struct _gitem_t gitem_t;
//свойства
/*!
\brief
Элемент группированного списка.

Такой элемент постоянно состоит в одной из групп (смотри group_t). В каждом таком элементе gitem_t есть поле типа group_t, это группа, в которую изначально включен элемент.
*/
struct _gitem_t
{
    item_t parent; /*!< Родитель - элемент 2-связного списка. */
    group_t * group; /*!< Указатель на группу, в которую сейчас включен элемент. */
    group_t grp; /*!< Выделение памяти под группу, в нее изначально будет включен элемент. */
};

typedef struct _gxlist_t gxlist_t;
struct _gxlist_t
{
    xlist_t parent;
    pool_t pool;
};

void gxlist_init( gxlist_t * gxlist );


/*!
   Статическая инициализация объекта типа gitem_t.
   \param a - Имя переменной типа gitem_t.
   \param p - Приоритет.
*/
#define INIT_G_ITEM_T(a,p) { INIT_ITEM_T(a), &a.grp, INIT_GROUP_T(p) }

//Методы
/*!
\brief
Инициализация объекта типа gitem_t.

\param gitem Указатель на объект gitem_t.
\param prio Приоритет элемента.
*/
void gitem_init(gitem_t * gitem, prio_t prio);
/*!
\brief
Вставка элемента типа gitem_t в список типа xlist_t без группировки.

\param gitem Указатель на объект gitem_t.
\param xlist Указатель на список.
*/
void gitem_insert(gitem_t * gitem, xlist_t *xlist);
/*!
\brief
Вставка элемента типа gitem_t в список типа gxlist_t с группировкой.

Вставляет в часть списка с приоритетом prio = gitem->group->prio, и переносит элемент в группу gxlist->parent.item[prio]->group, при этом gitem->group переходит в пул.

\param gitem Указатель на объект gitem_t.
\param gxlist Указатель на список.
*/
void gitem_insert_group(gitem_t * gitem, gxlist_t *gxlist);
/*!
\brief
Быстро вырезать из списка.

Вырезает объект типа gitem_t, из списка типа xlist_t, если объект был сгруппирован, то он вырезается из группы, и для него выделяется группа из Пула. При этом не обнуляется указатель gitem->group->link.

\param gitem Указатель на объект gitem_t.
*/
void gitem_fast_cut(gitem_t * gitem);
/*!
\brief
Вырезать из списка.

Вызывает gitem_fast_cut, а потом таки обнуляет gitem->group->link

\param gitem Указатель на объект gitem_t.
*/
void gitem_cut(gitem_t * gitem);
/*!
\brief
Переносит все элементы из одного группированного списка в другой

Перенести все элементы из группированного списка типа gxlist_t в другой список типа gxlist_t. Выполняется за O(1) шагов.

\param source Указатель на список из которого переносим элементы.
\param destignation Указатель на список в который преносим элементы.
*/
void gxlist_merge(gxlist_t * source, gxlist_t * destignation);

#endif // _GITEM_H_