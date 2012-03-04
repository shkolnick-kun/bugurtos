#define _TIME_H
#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include "../../include/bugurt.h"
int main()
{
    item_t item1,item2,item3;

    item_t *head = &item1;

    item_init(&item1);
    item_init(&item2);
    item_init(&item3);

    item_insert(&item2,head);
    item_insert(&item3,head);

    item_cut(&item2);
    item_cut(&item3);

    printf("Hello world!\n");
    return 0;
}
