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
#ifndef _GROUP_H_
#define _GROUP_H_
/*!
\file
\brief \~russian Заголовок групп. \~english A group header.
*/

#ifdef CONFIG_MP

#define SPIN_INIT_POOL() spin_init( &kernel.pool_lock )
#define SPIN_LOCK_POOL() spin_lock( &kernel.pool_lock )
#define SPIN_UNLOCK_POOL() spin_unlock( &kernel.pool_lock )

#else

#define SPIN_INIT_POOL()
#define SPIN_LOCK_POOL()
#define SPIN_UNLOCK_POOL()

#endif

typedef struct _group_t group_t;
//свойства
/*!
\brief
\~russian Группа элементов типа #gitem_t. \~english. A group of #gitem_t objects.

\~russian Группа элементов типа #gitem_t, хранит информацию о приоритете входящих в нее элементов, а так же указатель на список #xlist_t, которому принадлежат эти элементы.
Каждый элемент #gitem_t имеет поле типа #group_t, изначально  принадлежит этой самой группе, однако при включении элемента в группированный список, где уже есть элементы с таким же приоритетом, собственная группа будет передана в Пул, и элемент будет включен в группу, которая уже есть в списке.

\~english A #group_t object stores information about priority of included #gitem_t objects and about their #xlist_t container.
Every #gitem_t object has #group_t field, which is the initial group of such object.
When #gitem_t object oject is inserted to #xlist_t container with grouping, its group may be to the kernel.pool.
This hapens when at least one #gitem_t object oject of a same piority is already in destignation container.
*/
struct _group_t
{
    void * link;   /*!< \~russian Поле используется для хранения указателя на список, либо для хранения указателя на следующую группу в Пуле. \~english This pointer may be used to store a pointer to 3xlist_t object, or to store a pointer to next group in kernel.pool.*/
    prio_t prio;    /*!< \~russian Приоритет группы. \~english A group priority.*/
    count_t el_num; /*!< \~russian Количество элементов в группе, подсчет ссылок же! \~english A #gitem_t object cointer.*/
};

/*!
   \~russian Статическая инициализация объекта типа #group_t \~english A static #group_t object initiation.
   \param p \~russian Приоритет. \~english A priotity.
*/
#define INIT_GROUP_T(p) { (void *)0, (prio_t)p, (count_t)1 }

// методы
/*!
\brief
\~russian Инициализация группы. \~english A group initiation.

\param group \~russian Указатель на объект #group_t. \~english A #group_t pointer.
\param prio \~russian Приоритет элемента. \~english A priority.
*/
void group_init(group_t * group, prio_t prio);
/*!
\brief
\~russian Положить группу в Пул. \~english Push a group t a kernel.pool.

\param group \~russian Указатель на объект #group_t. \~english A #group_t pointer.
*/
void group_push(group_t * group);
/*!
\brief
\~russian Взять группу из Пула. \~english Pop a group from the kernel.pool.

Если есть что брать, а есть всегда, избыточность же! \~english This function pops a #group_t object from the kernel.pool. It is supposed that the kernel.pool is not empty at function call time.

\return \~russian Указатель на объект #group_t, который был взят из Пула. \~english A pointer to an #group_t object poped from the kernel.pool.
*/
group_t * group_pop(void);

#endif // _GROUP_H_
