/**************************************************************************
    BuguRTOS-0.3.x(Bugurt real time operating system)
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
#include "../include/bugurt.h"
// Инициация
void gitem_init(gitem_t * gitem, prio_t prio)
{
    group_t * group;

    group = &gitem->grp;
    item_init( (item_t *)gitem );
    group_init( group, prio );
    gitem->group = group;
}
// Вставить в список
void gitem_insert(gitem_t * gitem, xlist_t *xlist)
{
    prio_t prio;
    index_t mask;
    item_t ** head;

    prio = gitem->group->prio;
    mask = ((index_t)1)<<prio;
    head = (item_t **)xlist + prio;
    // Пуста ли часть списка с таким приоритетом
    if( ( xlist->index )& mask)
    {
        //Не пуста вставляем туда gitem
        item_insert( (item_t *)gitem, *head );
    }
    else
    {
        // Пуста, gitem будет головой
        *head = (item_t *)gitem;
        xlist->index |= mask;
    }
    gitem->group->link = (void *)xlist;
}
// Вставить в список с добавлением в группу
/*
 Вставляет в часть списка с проиритетом prio = gitem->group->prio,
 и переносит элемент в группу xlist->item[prio]->group,
 при этом gitem->group переходит в Пул

 Ограничения на gitem - он не должен быть сгруппирован в момент встаки в группу.
*/
void gitem_insert_group(gitem_t * gitem, xlist_t *xlist)
{
    prio_t prio;
    index_t mask;
    item_t ** head;
    group_t * group;

    prio = gitem->group->prio;
    mask = ((index_t)1)<<prio;
    head = (item_t **)xlist + prio;
    group = gitem->group;
    // Пуста ли часть списка с таким приоритетом
    if( ( xlist->index )& mask)
    {
        //Не пуста вставляем туда gitem
        item_insert((item_t *)gitem, *head );
        //Передаем старую группу в пул
        group_push(group);
        //назначаем новую группу - ту, в которой голова
        group = ((gitem_t *)*head)->group;
        gitem->group = group;
        //количество элементов в группе увеличилось на 1
        group->el_num++;
    }
    else
    {
        // Пуста, gitem будет головой
        *head = (item_t *)gitem;
        xlist->index |= mask;
        group->link = (void *)xlist;
    }
}
// Быстро вырезать из списка (не обнуляется указатель gitem->group->link)
void gitem_fast_cut(gitem_t * gitem)
{
    prio_t prio;
    xlist_t * xlist;

    prio = gitem->group->prio;
    xlist = (xlist_t *)gitem->group->link;
    // Является ли эта часть списка группированной?
    if( gitem->group->el_num > (count_t)1 )
    {
        //Группированная часть списка, будем вырезать из группы с выделением новой группы из Пула
        // В текущей группе стало на 1 элемент меньше
        gitem->group->el_num--;
        //выделяем новую группу
        gitem->group = group_pop();
        // Правильный приоритет, количество элементов в группе, выделенной из пула должно быть равно 1
        gitem->group->prio = (prio_t)prio;
    }
    //Является ли элемент единственным в своей части списка?
    if( ((item_t *)gitem)->next == (item_t *)gitem )
    {
        // Да, является!
        xlist->item[prio] = (item_t *)0;
        xlist->index &= ~(((index_t)1)<<prio);
    }
    else
    {
        // Нет, не является!
        // Является ли элемент головой своей части списка?
        if( xlist->item[(prio_t)prio] == (item_t *)gitem )
        {
            // Является, список надо переключить
            xlist_switch( xlist, prio );
        }
        // Собственно - вырезаем элемент
        item_cut( (item_t *)gitem );
    }
}
// Вырезать из списка
void gitem_cut(gitem_t * gitem)
{
    gitem_fast_cut( gitem );
    gitem->group->link = (void *)0;
}
// Переносит все елементы из одного группированного списка в другой
/*
 Ограничения на объекты:
 1) Оба списка содержат только объекты типа gitem_t
 2) В списке source на каждом уровне приоритета все объекты типа gitem_t приенадлежат к одной группе.
 3) Элементы списка source, находящиеся на разных уровнях приоритета, пренадлежат разным группам.
*/
void gitem_xlist_merge(xlist_t * source, xlist_t * destignation)
{
    index_t mask = (index_t)1;
    prio_t current_prio = (prio_t)0;
    while( mask )
    {
        // Есть че перенести?
        if( mask & source->index )
        {
            // Есть!
            // Есть куда переносить?
            if( mask & destignation->index )
            {
                //Есть!
                // Сшиваем 2 2-связных списка!!!
                item_t * src;
                item_t * dst;

                src = source->item[current_prio];
                dst = destignation->item[current_prio];
                src->prev->next = dst;
                dst->prev->next = src;
                item_t * buf = dst->prev;
                dst->prev = src->prev;
                src->prev = buf;
            }
            else
            {
                //Нет, тупо переносим всю группу.
                destignation->item[current_prio] = source->item[current_prio];
                destignation->index |= mask;
            }
            // Вот почему эта функция отнесена к методам gitem_t
            ((gitem_t *)source->item[current_prio])->group->link = (void *)destignation;
            // Перенос закончен, обнуляем указатель
            source->item[(prio_t)current_prio] = (item_t *)0;
        }
        mask<<=1;
        current_prio++;
    }
    // Список полностью перенесен, обнуляем индекс
    source->index = (index_t)0;
}
