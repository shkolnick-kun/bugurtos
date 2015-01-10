/**************************************************************************
    BuguRTOS-0.6.x(Bugurt real time operating system)
    Copyright (C) 2013  anonimous

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
#ifndef _PITEM_H_
#define _PITEM_H_

/*!
\file
\brief \~russian Заголовок элементов списка с приоритетами. \~english A prioritixed lis item header.
*/
//Элемент списка с приоритетами

typedef struct _pitem_t pitem_t;
//Свойства
/*!
\~russian
\brief
Элемент списка с приоритетами

\~english
\brief
A prioritized list item.
*/
struct _pitem_t
{
    item_t parent; /*!< \~russian Родитель - #item_t. \~english A perrent - #item_t. */
    xlist_t * list; /*!< \~russian Указательна спиок в который будем вставлять. \~english A pointer to an #xlist_t object.*/
    prio_t prio; /*!< \~russian Приоритет. \~english A rpiority. */
};

/*!
   \~russian
   Статическая инициализация объекта типа #pitem_t

   \param a Имя переменной.
   \param p Приоритет.

   \~english
   A static #pitem_t object initiation.

   \param a A variable name.
   \param p A rpiority.
*/
#define INIT_P_ITEM_T(a,p) { INIT_ITEM_T(a), (xlist_t *)0, (prio_t)p }

//Методы
/*!
\~russian
\brief
Инициализация объект а типа #pitem_t.

\param pitem Указатель на объект #pitem_t.
\param prio Приоритет элемента.

\~english
\brief
A #pitem_t object initiation.

\param pitem A #pitem_t pointer.
\param prio A priority.
*/
void pitem_init( pitem_t * pitem, prio_t prio );
/*!
\~russian
\brief
Вставка элемента типа #pitem_t в список типа #xlist_t.

\param pitem Указатель на объект #pitem_t.
\param xlist Указатель на список.

\~english
\brief
Insert #pitem_t object to #xlist_t container.

\param pitem A #pitem_t pointer.
\param xlist A pointer to destignation list.
*/
void pitem_insert( pitem_t * pitem, xlist_t * xlist );
/*!
\~russian
\brief
Быстро вырезать из списка.

Вырезает объект типа #pitem_t, из спика типа #xlist_t, не обнуляет указатель pitem->list.

\param pitem Указатель на объект #pitem_t.

\~english
\brief
Fast cut #pitem_t object from #xlist_t container.

This function cuts #pitem_t object from #xlist_t container without pitem->list field.

\param pitem A #pitem_t pointer.
*/
void pitem_fast_cut( pitem_t * pitem );
/*!
\~russian
\brief
Вырезать из списка.

Вызывает #pitem_fast_cut и обнуляет указатель pitem->list.

\param pitem Указатель на объект #pitem_t.

\~english
\brief
Cut #pitem_t object from #xlist_t container.

This function calls #pitem_fast_cut and then nulls pitem->list field.

\param pitem A #pitem_t pointer.
*/
void pitem_cut( pitem_t * pitem );

/*!
\~russian
\brief
"Сцепить" список типа #xlist_t.

Вырезать из списка типа xlist_t все элементы типа #pitem_t и сделать из них простой 2-связный список.

\param src Указатель на объект #xlist_t.
\return Указаьель на голову 2-связного списка.

\~english
\brief
"Chain" #pitem_t objects from #xlist_t container.

Cut all #pitem_t objects from #xlist_t container and form an ordinary list from them.

\param src A #xlist_t pointer.
\return An ordinary doublelinked list head pointer.
*/
pitem_t * pitem_xlist_chain( xlist_t * src );
#endif // _PITEM_H_
