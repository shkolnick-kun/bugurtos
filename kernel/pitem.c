/**************************************************************************
    BuguRTOS-0.8.x (Bugurt real time operating system)
    Copyright (C) 2015 anonimous

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
#include "bugurt.h"
// Инициация
void bgrt_pitem_init( bgrt_pitem_t * pitem, bgrt_prio_t prio )
{
    bgrt_item_init( (bgrt_item_t *)pitem );
    pitem->list = (bgrt_xlist_t *)0;
    pitem->prio = prio;
}
// Вставка в список
void bgrt_pitem_insert( bgrt_pitem_t * pitem, bgrt_xlist_t * xlist )
{
    bgrt_prio_t prio;
    bgrt_index_t mask;
    bgrt_item_t ** head;

    prio = pitem->prio;
    mask = ((bgrt_index_t)1)<<prio;
    head = (bgrt_item_t **)xlist + prio;
    // Пуста ли часть списка с таким приоритетом
    if( ( xlist->index )& mask)
    {
        //Не пуста вставляем туда gitem
        bgrt_item_insert( (bgrt_item_t *)pitem, *head );
    }
    else
    {
        // Пуста, gitem будет головой
        *head = (bgrt_item_t *)pitem;
        xlist->index |= mask;
    }
    pitem->list = xlist;
}
// Быстрая вырезка из списка
void bgrt_pitem_fast_cut( bgrt_pitem_t * pitem )
{
    bgrt_prio_t prio;
    bgrt_xlist_t * xlist;

    prio = pitem->prio;
    xlist = (bgrt_xlist_t *)pitem->list;
    //Является ли элемент единственным в своей части списка?
    if( ((bgrt_item_t *)pitem)->next == (bgrt_item_t *)pitem )
    {
        // Да, является!
        xlist->item[prio] = (bgrt_item_t *)0;
        xlist->index &= ~(((bgrt_index_t)1)<<prio);
    }
    else
    {
        // Нет, не является!
        // Является ли элемент головой своей части списка?
        if( xlist->item[(bgrt_prio_t)prio] == (bgrt_item_t *)pitem )
        {
            // Является, список надо переключить
            bgrt_xlist_switch( xlist, prio );
        }
        // Собственно - вырезаем элемент
        bgrt_item_cut( (bgrt_item_t *)pitem );
    }
}
// Вырезка из списка
void bgrt_pitem_cut(bgrt_pitem_t * pitem)
{
    bgrt_pitem_fast_cut( pitem );
    pitem->list = (bgrt_xlist_t *)0;
}

bgrt_pitem_t * bgrt_pitem_xlist_chain( bgrt_xlist_t * src )
{
    bgrt_pitem_t * ret;  // return value
    ret = (bgrt_pitem_t *)bgrt_xlist_head( src );     // will return former xlist head
    if(ret)
    {
        bgrt_index_t mask,   // index mask to check for items in xlist
                index;  // buffer for xlist index
        bgrt_prio_t  prio;   // current working priority
        bgrt_item_t * tail;  // current list tail;


        tail = ((bgrt_item_t *)ret)->prev;           // current list tail initial value
        prio = ret->prio;                       // initial working prio
        src->item[prio++] = (bgrt_item_t *)0;        // cut all items from current xlist part
        index = src->index;                     // remember xlist index to improve performance
        mask = ((bgrt_index_t)1) << prio;            // initial mask value
        // cut all items from xlist and form an ordinary list of them
        while(mask)
        {
            if( index & mask )
            {
                // current part of xlist has some items to cut
                bgrt_item_t * xhead;
                bgrt_item_t * buf;
                xhead = src->item[prio];                    // current xlist head;
                src->item[prio] = (bgrt_item_t *)0;              // cut all items from current xlist part
                // chain former xlist head to a list tail
                tail->next = xhead;
                buf = xhead->prev;
                xhead->prev = tail;
                tail = buf;
            }
            mask <<= (bgrt_prio_t)1;
            prio++;
        }
        // complete the list by chaining tail and head
        ((bgrt_item_t *)ret)->prev = tail;
        tail->next = (bgrt_item_t *)ret;
        src->index = (bgrt_index_t)0;        // xlist is empty.
    }
    return ret;                     // return list head;
}
