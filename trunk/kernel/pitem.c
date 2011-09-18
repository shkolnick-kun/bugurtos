#include "../include/bugurt.h"
// Инициация
void pitem_init( pitem_t * pitem, prio_t prio )
{
    item_init( (item_t *)pitem );
    pitem->list = (xlist_t *)0;
    pitem->prio = prio;
}
// Вставка в список
void pitem_insert( pitem_t * pitem, xlist_t * xlist )
{
    prio_t prio = pitem->prio;
    index_t mask = ((index_t)1)<<prio;
    item_t ** head = (item_t **)xlist + prio;
    // Пуста ли часть списка с таким приоритетом
    if( ( xlist->index )& mask)
    {
        //Не пуста вставляем туда gitem
        item_insert( (item_t *)pitem, *head );
    }
    else
    {
        // Пуста, gitem будет головой
        *head = (item_t *)pitem;
        xlist->index |= mask;
    }
    pitem->list = xlist;
}
// Быстрая вырезка из списка
void pitem_fast_cut( pitem_t * pitem )
{
    prio_t prio = pitem->prio;
    xlist_t * xlist = (xlist_t *)pitem->list;
    //Является ли элемент единственным в своей части списка?
    if( ((item_t *)pitem)->next == (item_t *)pitem )
    {
        // Да, является!
        xlist->item[prio] = (item_t *)0;
        xlist->index &= ~(((index_t)1)<<prio);
    }
    else
    {
        // Нет, не является!
        // Является ли элемент головой своей части списка?
        if( xlist->item[(prio_t)prio] == (item_t *)pitem )
        {
            // Является, список надо переключить
            xlist_switch( xlist, prio );
        }
        // Собственно - вырезаем элемент
        item_cut( (item_t *)pitem );
    }
}
// Вырезка из списка
void pitem_cut(pitem_t * pitem)
{
    pitem_fast_cut( pitem );
    pitem->list = (xlist_t *)0;
}
