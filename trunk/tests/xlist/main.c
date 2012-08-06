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

int main()
{
    item_t item[3], *test;
    xlist_t list1;

    item_init(&item[0]);
    item_init(&item[1]);
    item_init(&item[2]);

    xlist_init(&list1);

    list1.index = 5;
    list1.item[0] = &item[0];
    list1.item[2] = &item[1];

    item_insert(&item[2], list1.item[0]);

    test = xlist_head(&list1);

    printf("%d\n", (int)(test - item));

    xlist_switch(&list1, 0);

    test = xlist_head(&list1);

    printf("%d\n", (int)(test - item));

    printf("Hello world!\n");


    return 0;
}
