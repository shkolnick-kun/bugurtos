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
#ifndef BGRT_PITEM_H
#define BGRT_PITEM_H
BGRT_CDECL_BEGIN
/*!
\file
\brief \~russian Заголовок элементов списка с приоритетами. \~english A prioritized list item header.
*/
/*Элемент списка с приоритетами*/

typedef struct bgrt_priv_pitem_t bgrt_pitem_t;
/*Свойства*/
/*!
\~russian
\brief
Элемент списка с приоритетами

\~english
\brief
A prioritized list item.
*/
struct bgrt_priv_pitem_t
{
    bgrt_item_t parent; /*!< \~russian Родитель - #bgrt_item_t. \~english A parent - #bgrt_item_t. */
    bgrt_xlist_t * list; /*!< \~russian Указатель на список в который будем вставлять. \~english A pointer to an #bgrt_xlist_t object.*/
    bgrt_prio_t prio; /*!< \~russian Приоритет. \~english A priority. */
};

/*!
   \~russian
   Статическая инициализация объекта типа #bgrt_pitem_t

   \warning Для внутреннего использования.

   \param a Имя переменной.
   \param p Приоритет.

   \~english
   A static #bgrt_pitem_t object initiation.

   \warning For internal usage.

   \param a A variable name.
   \param p A priority.
*/
#define BGRT_PITEM_T_INIT(a,p) { BGRT_ITEM_T_INIT(a), (bgrt_xlist_t *)0, (bgrt_prio_t)p }

/*Методы*/
/*!
\~russian
\brief
Инициализация объект а типа #bgrt_pitem_t.

\warning Для внутреннего использования.

\param pitem Указатель на объект #bgrt_pitem_t.
\param prio Приоритет элемента.

\~english
\brief
A #bgrt_pitem_t object initiation.

\warning For internal usage.

\param pitem A #bgrt_pitem_t pointer.
\param prio A priority.
*/
void bgrt_pitem_init(bgrt_pitem_t * pitem, bgrt_prio_t prio);
/*!
\~russian
\brief
Вставка элемента типа #bgrt_pitem_t в список типа #bgrt_xlist_t.

\warning Для внутреннего использования.

\param pitem Указатель на объект #bgrt_pitem_t.
\param xlist Указатель на список.

\~english
\brief
Insert #bgrt_pitem_t object to #bgrt_xlist_t container.

\warning For internal usage.

\param pitem A #bgrt_pitem_t pointer.
\param xlist A pointer to destination list.
*/
void bgrt_pitem_insert(bgrt_pitem_t * pitem, bgrt_xlist_t * xlist);
/*!
\~russian
\brief
Быстро вырезать из списка.

Вырезает объект типа #bgrt_pitem_t, из списка типа #bgrt_xlist_t, не обнуляет указатель pitem->list.

\warning Для внутреннего использования.

\param pitem Указатель на объект #bgrt_pitem_t.

\~english
\brief
Fast cut #bgrt_pitem_t object from #bgrt_xlist_t container.

This function cuts #bgrt_pitem_t object from #bgrt_xlist_t container without pitem->list field.

\warning For internal usage.

\param pitem A #bgrt_pitem_t pointer.
*/
void bgrt_pitem_fast_cut(bgrt_pitem_t * pitem);
/*!
\~russian
\brief
Вырезать из списка.

Вызывает #bgrt_pitem_fast_cut и обнуляет указатель pitem->list.

\warning Для внутреннего использования.

\param pitem Указатель на объект #bgrt_pitem_t.

\~english
\brief
Cut #bgrt_pitem_t object from #bgrt_xlist_t container.

This function calls #bgrt_pitem_fast_cut and then nulls pitem->list field.

\warning For internal usage.

\param pitem A #bgrt_pitem_t pointer.
*/
void bgrt_pitem_cut(bgrt_pitem_t * pitem);

/*!
\~russian
\brief
"Сцепить" список типа #bgrt_xlist_t.

Вырезать из списка типа bgrt_xlist_t все элементы типа #bgrt_pitem_t и сделать из них простой 2-связный список.

\warning Для внутреннего использования.

\param src Указатель на объект #bgrt_xlist_t.
\return Указатель на голову 2-связного списка.

\~english
\brief
"Chain" #bgrt_pitem_t objects from #bgrt_xlist_t container.

Cut all #bgrt_pitem_t objects from #bgrt_xlist_t container and form an ordinary list from them.

\warning For internal usage.

\param src A #bgrt_xlist_t pointer.
\return An ordinary doublelinked list head pointer.
*/
bgrt_pitem_t * bgrt_pitem_xlist_chain(bgrt_xlist_t * src);

BGRT_CDECL_END
#endif /*BGRT_PITEM_H*/
