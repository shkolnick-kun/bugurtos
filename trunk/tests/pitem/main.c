#include <stdio.h>
#include <stdlib.h>
#include "../../include/bugurt.h"
pitem_t item = INIT_P_ITEM_T(item,3);
pitem_t my_item[6];
prio_t my_prio[] = { 0,1,1,2,2,2 };
xlist_t my_list;
int main()
{
    xlist_init(&my_list);
    for(int i = 0; i < 6; i++)
    {
        pitem_init( (pitem_t *)my_item + i, my_prio[i] );
        pitem_insert( (pitem_t *)my_item + i, &my_list );
    }
    for(int i = 0; i < 6; i++)
    {
        pitem_cut( (pitem_t *)my_item + i );
    }
    printf("Hello world!\n");
    return 0;
}
