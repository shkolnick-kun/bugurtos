#define _TIME_H
#include <stdio.h>
#include <stdlib.h>

#include "../../include/bugurt.h"
kernel_t kernel;


void spin_init(lock_t * lock)
{
    *lock=1;
}
void spin_lock(lock_t * lock)
{
    *lock=0;
}
void spin_unlock(lock_t * lock)
{
    *lock=1;
}

gitem_t my_gitem = INIT_G_ITEM_T(my_gitem,3);

static xlist_t src, dst;
static gitem_t gitem[17];
static prio_t p[17]={0,2,3,3,3,4,4,5,5,5,6,6,6,7,7,7,7};
static xlist_t * ins[17] = {&dst,&src,&src,&src,&src,&src,&dst,&src,&dst,&dst,&src,&src,&dst,&src,&src,&dst,&dst};
static group_t * grp[17];

static lock_t l1,l2;

void print_gitem_num( gitem_t * arg )
{
    printf("%d\t", (int)(arg - gitem));
}
void print_gitem_list(gitem_t * arg)
{
    if(arg->group->link == &src){
        printf("src \n");
        return;
    }
    if(arg->group->link == &dst)
    {
        printf("dst \n");
        return;
    }
    printf("xxx \n");
}

void print_gitem_grp(gitem_t * arg){
    for(int i = 0; i<17; i++ )
    {
        if( (void *)arg->group == (void *)grp[i] )
        {
            printf("%d\t", i);
            return;
        }
    }
    printf("x\t");
}

void print_item(int i)
{
        printf("%d\t",(int)i);
        print_gitem_num((gitem_t *)gitem[i].parent.prev);
        print_gitem_num((gitem_t *)gitem[i].parent.next);
        print_gitem_grp(&gitem[i]);
        printf("%d\t",gitem[i].group->prio);
        printf("%d\t",(int)gitem[i].group->el_num);
        print_gitem_list(&gitem[i]);
}

void print_xlist( xlist_t * xlist )
{
    prio_t mask;
    int i;
    item_t *current;
    printf("\nСостояние списка:");
    if(xlist == &src){
        printf("src \n");
        goto next;
    }
    if(xlist == &dst)
    {
        printf("dst \n");
        goto next;
    }
    printf("XYNTA \n");
    return;
next:
    printf("Index: %x Items:", (unsigned int)xlist->index);
    i=0;
    for(mask = (prio_t)1; mask; mask <<= 1)
    {
        if(xlist->item[i])print_gitem_num((gitem_t *)xlist->item[i]);
        else printf("x\t");
        //printf("\n");
        i++;
    }
    i=0;
    for(mask = (prio_t)1; mask; mask <<= 1)
    {
        if(xlist->item[i])
        {
            printf("\nУроветь приоритета: %d \ni \t p\t n\t g\t pr\t en\t l\n", i);
            current = xlist->item[i];
            do
            {
                print_item((int)((gitem_t *)current - gitem));
                current = current->next;
            }while(current != xlist->item[i]);
        }
        else
        {
            printf("\nУроветь приоритета: %d \t ПУСТО!!!\n",i);
        }
        i++;
    }
    printf("\n");
}
int main()
{
    spin_init( &kernel.pool_lock );
    kernel.pool = (group_t *)0;

    int i;
    xlist_init(&src);
    xlist_init(&dst);
    printf("\nИнициализация\n");
    printf("i \t p\t n\t g\t pr\t en\t l\n");
    // инициализируем
    for(i=0; i<17 ; i++)
    {
        gitem_init(&gitem[i], p[i]);
        grp[i] = &gitem[i].grp;
        print_item(i);
    }
    // Тест вставки в список без группировки
    printf("\n==================================================================================");
    printf("\nВставка без группировки\n");
    for(i=0; i<5 ; i++)
    {
        printf("Элемент: \ni \t p\t n\t g\t pr\t en\t l\n");
        print_item(i);
        print_xlist(ins[i]);
        gitem_insert(&gitem[i], ins[i]);
        print_xlist(ins[i]);
    }
    // Тест вырезки без группировок
    printf("\n==================================================================================");
    printf("\nВырезка без группировки\n");
    for(i=0; i<5 ; i++)
    {
        print_xlist(ins[i]);
        gitem_cut(&gitem[i]);
        print_xlist(ins[i]);
        printf("Элемент: \ni \t p\t n\t g\t pr\t en\t l\n");
        print_item(i);
    }
    // Тест вставки с группировкой
    printf("\n==================================================================================");
    printf("\nВставка с группировкой\n");
    for(i=0; i<17 ; i++)
    {
        printf("Элемент: \ni \t p\t n\t g\t pr\t en\t l\n");
        print_item(i);
        print_xlist(ins[i]);
        gitem_insert_group(&gitem[i], ins[i]);
        print_xlist(ins[i]);

    }

    // Тест слияния списков
    printf("\n==================================================================================");
    printf("\nСлияние списков\n");

    print_xlist(&src);
    print_xlist(&dst);

    gitem_xlist_merge(&src,&dst);

    print_xlist(&src);
    print_xlist(&dst);

    // Тест вырезки из группированных списков
    printf("\n==================================================================================");
    printf("\nВырезка с группировкой\n");
    for(i=0; i<17 ; i++)
    {
        print_xlist(&dst);
        gitem_cut(&gitem[i]);
        print_xlist(&dst);
        printf("Элемент: \ni \t p\t n\t g\t pr\t en\t l\n");
        print_item(i);
    }
    return 0;
}
