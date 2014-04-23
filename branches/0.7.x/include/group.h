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
#ifndef _GROUP_H_
#define _GROUP_H_
/*!
\file
\~russian
\brief Заголовок элементов групп.

\~english
\brief A #group_t and #pool_t header.
*/

typedef struct _group_t group_t;
//свойства
/*!
\~russian
\brief
Группа элементов типа #gitem_t.

Группа элементов типа #gitem_t, хранит информацию о приоритете входящих в нее элементов, а так же указатель на список #xlist_t, которому принадлежат эти элементы.

Каждый элемент #gitem_t имеет поле типа #group_t, изначально  принадлежит этой самой группе, однако при включении элемента в группированный список, где уже есть элементы с таким же приоритетом, собственная группа будет передана в Пул, и элемент будет включен в группу, которая уже есть в списке.

\~english
\brief
A group of #gitem_t objects.

A #gitem_t object, stores priority information of grouped #gitem_t objects, and apointer to an #xlist_t container, which holds these #gitem_t objects.

Every #gitem_t object has #group_t field, this field is initial group for this object. When #gitem_t object is transfered to #gxlist_t container gitem->group may be pushed to local pool of that container.
*/
struct _group_t
{
    void * link;    /*!< \~russian Поле используется для хранения указателя на список, либо для хранения указателя на следующую группу в gуле. \~english Stores an information about container, or about next group in a pool. */
    prio_t prio;    /*!< \~russian Приоритет группы. \~english  A group priority.*/
    count_t el_num; /*!< \~russian Количество элементов в группе, подсчет ссылок же! \~english The number of #gitem_t objects in group, link counter.*/
};

/*!
\~russian
\brief
Пул;

Стек для хранения неиспользуемых групп.

\~english
\brief
Pool of groups;

Pool is a stack container for #gpoup_t objects.
*/
typedef struct _pool_t pool_t;
struct _pool_t
{
    group_t * top; /*!< \~russian Вершина пула. \~english Top of pool. */
    group_t * bot; /*!< \~russian Дно пула.  \~english Bottom of pool. */
};
/*!
   \~russian
   Статическая инициализация объекта типа #pool_t

   \~english
   Static #pool_t object initiation.
*/
#define INIT_POOL_T() { (group_t *)0, (group_t *)0 }
/*!
   \~russian
   Инициализация объекта типа #pool_t

   \param pool - указаткль на пул.

   \~english
   A #pool_t object initiation;

   \param pool A #pool_t pointer.
*/
void pool_init( pool_t * pool );
/*!
   \~russian
   Слияние двух пулов.

   \param src Указатель на пул-источник.
   \param dst Указатель на пул-приемник.

   \~english
   Merges two pools.

   \param src Source #pool_t object pointer.
   \param dst Destignation #pool_t object pointer.
*/
void pool_merge( pool_t * src, pool_t * dst );

/*!
   \~russian
   Статическая инициализация объекта типа group_t
   \param p - Приоритет.
*/
#define INIT_GROUP_T(p) { (void *)0, (prio_t)p, (count_t)1 }

// методы
/*!
\~russian
\brief
Инициализация группы.

\param group Указатель на объект group_t.
\param prio Приоритет элемента.
*/
void group_init(group_t * group, prio_t prio);
/*!
\~russian
\brief
Положить группу в Пул.

\param group Указатель на объект group_t.
*/
void group_push(group_t * group, pool_t * pool);
/*!
\~russian
\brief
Взять группу из Пула.

Если есть что брать, а есть всегда, избыточность же!

\return Указатель на объект group_t, который был взят из Пула.
*/
group_t * group_pop(pool_t * pool);

#endif // _GROUP_H_
