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
#include "../include/bugurt.h"
//============================================================================
//pool_t methods
void pool_init( pool_t * pool )
{
    pool->top = (group_t *)0;
    pool->bot = (group_t *)0;
}

void pool_merge( pool_t * src, pool_t * dst )
{
    if( src->bot == (group_t *)0 )
    {
        return; // src is empty, nothing to do
    }
    src->bot->link = (void *)dst->top;
    dst->top = src->top;
    if( dst->bot == (group_t *)0 )
    {
        dst->bot = src->bot; // dst was empty
    }
    src->top = (group_t *)0;
    src->bot = (group_t *)0;
}
//============================================================================
//group_t methods
void group_init(group_t * group, prio_t prio)
{
    group->link = (void *)0;
    group->prio = prio;
    group->el_num = (count_t)1;
}
// Push a group to to a pool
void group_push(group_t * group, pool_t * pool)
{
    if( pool->bot == (group_t *)0 )
    {
        pool->bot = group; // pool was empty, update pool->bot
    }
    group->link = pool->top;
    pool->top = group;
}
// Pop a group from a pool, called only after group_push, so no need to check zero in pool->top
group_t * group_pop(pool_t * pool)
{
    group_t * group;
    group = pool->top;
    pool->top = (group_t *)group->link;
    if( pool->top == (group_t *)0 )
    {
        pool->bot = (group_t *)0; // pool is empty, update pool->bot
    }
    return group;
}
//============================================================================
//gitem_t methods
// Initiation
void gitem_init(gitem_t * gitem, prio_t prio)
{
    group_t * group;

    group = &gitem->grp;
    item_init( (item_t *)gitem );
    group_init( group, prio );
    gitem->group = group;
}
// Insert to gitem_t object to xlist_t container
void gitem_insert(gitem_t * gitem, xlist_t *xlist)
{
    prio_t prio;
    index_t mask;
    item_t ** head;

    prio = gitem->group->prio;
    mask = ((index_t)1)<<prio;
    head = (item_t **)xlist + prio;
    // Is container sublist empty?
    if( ( xlist->index )& mask)
    {
        //Not empty
        item_insert( (item_t *)gitem, *head );
    }
    else
    {
        // Empty, gitem will be the head
        *head = (item_t *)gitem;
        xlist->index |= mask;
    }
    gitem->group->link = (void *)xlist;
}
// Insert gitem_t object to gxlist_t container
/*
  A gitem is inserted to container list with prio = gitem->group->prio,
  and grouped to xlist->item[prio]->group,
  gitem->group is pushed to a gxlist->pool

  A limitation for gitem: It must not be grouped before insert.
*/
void gitem_insert_group(gitem_t * gitem, gxlist_t *gxlist)
{
    prio_t prio;
    index_t mask;
    item_t ** head;
    group_t * group;

    prio = gitem->group->prio;
    mask = ((index_t)1)<<prio;
    head = (item_t **)gxlist + prio;
    group = gitem->group;
    // Is container sublist empty?
    if( ( ((xlist_t *)gxlist)->index )& mask)
    {
        //Not empty
        item_insert((item_t *)gitem, *head );
        //Push gitem->group to a pool
        group_push(group, &gxlist->pool);
        //Assign new group
        group = ((gitem_t *)*head)->group;
        gitem->group = group;
        //Increment group element number
        group->el_num++;
    }
    else
    {
        // Empty! gitem will be the head.
        *head = (item_t *)gitem;
        ((xlist_t *)gxlist)->index |= mask;
        group->link = (void *)gxlist;
    }
}
// Cut gitem_t ibject from its container (gitem->group->link is not touched)
void gitem_fast_cut(gitem_t * gitem)
{
    prio_t prio;
    xlist_t * xlist;

    prio = gitem->group->prio;
    xlist = (xlist_t *)gitem->group->link;
    // Is container list grouped?
    if( gitem->group->el_num > (count_t)1 )
    {
        // A container list is grouped, cut gitem from a container and pop some group for it.
        // Decrement element number
        gitem->group->el_num--;
        // Pop a new group
        gitem->group = group_pop(&((gxlist_t *)xlist)->pool);
        // Assign a priority to a group
        gitem->group->prio = (prio_t)prio;
    }
    //Is gitem the only element in its sublist?
    if( ((item_t *)gitem)->next == (item_t *)gitem )
    {
        // Yes, it is!
        xlist->item[prio] = (item_t *)0;
        xlist->index &= ~(((index_t)1)<<prio);
    }
    else
    {
        // No its, not!
        // Is gitem the head of its sublist?
        if( xlist->item[(prio_t)prio] == (item_t *)gitem )
        {
            // It is. Switch the head.
            xlist_switch( xlist, prio );
        }
        // Cut from sublist.
        item_cut( (item_t *)gitem );
    }
}
// Cut gitem from its container
void gitem_cut(gitem_t * gitem)
{
    gitem_fast_cut( gitem );
    gitem->group->link = (void *)0;
}
//============================================================================
// gxlist_t methods
// Initiation
void gxlist_init( gxlist_t * gxlist )
{
    xlist_init( (xlist_t *)gxlist );
    pool_init( &gxlist->pool );
}
// Transfer all gitem_t objects from #source container to #destignation container
/*
 Limitations:
 1) Both #source and #destignation contain only gitem_t objects.
 2) In #source container all sublists a grouped and each sublist contain only one group of gitem_t objects.
 3) In #source container all sublists have different groups (one group - one sublist).
*/
void gxlist_merge(gxlist_t * source, gxlist_t * destignation)
{
    index_t mask = (index_t)1;
    prio_t current_prio = (prio_t)0;
    while( mask )
    {
        // Is there anything to move?
        if( mask & ((xlist_t *)source)->index )
        {
            // Yes!
            // Is #destignation sublist not empty?
            if( mask & ((xlist_t *)destignation)->index )
            {
                // Yes!
                // Form one double-linked list from two!!!
                item_t * src;
                item_t * dst;
                item_t * buf;

                src = ((xlist_t *)source)->item[current_prio];
                dst = ((xlist_t *)destignation)->item[current_prio];
                src->prev->next = dst;
                dst->prev->next = src;
                buf = dst->prev;
                dst->prev = src->prev;
                src->prev = buf;
            }
            else
            {
                //No! Then just move sublist from #source to #destignation!
                ((xlist_t *)destignation)->item[current_prio] = ((xlist_t *)source)->item[current_prio];
                ((xlist_t *)destignation)->index |= mask;
            }
            // Link resulting sublist with #destignation!
            ((gitem_t *)((xlist_t *)source)->item[current_prio])->group->link = (void *)destignation;
            // Emty #source sublist.
            ((xlist_t *)source)->item[(prio_t)current_prio] = (item_t *)0;
        }
        mask<<=1;
        current_prio++;
    }
    pool_merge( &source->pool, &destignation->pool );
    // Empty #source index bitmap.
    ((xlist_t *)source)->index = (index_t)0;
}
