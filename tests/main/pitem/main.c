#include <stdio.h>

// Include BuguRTOS headers.
#include <bugurt.h>

void print_ok(void)
{
    printf("\t\t[ OK ]\n");
}
void print_fail(void)
{
    printf("\t\t[Fail]\n");
}

#define print_test_res(t)\
    if (t)\
    { \
        print_fail(); \
        return 0; \
    } \
    else \
        print_ok()

int main()
{
    bgrt_pitem_t item = BGRT_PITEM_T_INIT(item,3);
    bgrt_pitem_t my_item[6];
    bgrt_prio_t my_prio[] = { 0,1,1,2,2,2 };
    bgrt_xlist_t list;
    int i, test;


    printf("Test 1: BGRT_PITEM_T_INIT macro: ");
    print_test_res(
        (item.prio != (bgrt_prio_t)3)
        ||(item.list != (bgrt_xlist_t *)0)
        ||(item.parent.next != (bgrt_item_t *)&item)
        ||(item.parent.prev != (bgrt_item_t *)&item)
   );

    printf("Test 2: bgrt_pitem_init function: ");
    test = 0;
    for (i=0; i<6; i++)
    {
        bgrt_pitem_init(&my_item[i], my_prio[i]);

        test |= (my_item[i].prio != my_prio[i])
                ||(my_item[i].list != (bgrt_xlist_t *)0)
                ||(my_item[i].parent.next != (bgrt_item_t *)&my_item[i])
                ||(my_item[i].parent.prev != (bgrt_item_t *)&my_item[i]);
    }
    print_test_res(test);

    printf("Test 3: bgrt_pitem_insert function: ");
    bgrt_xlist_init(&list);
    for (i=0; i<6; i++)
    {
        bgrt_pitem_insert(&my_item[i], &list);
        test |= (my_item[i].list != &list);
    }
    test |= (list.map != (bgrt_map_t)7);
    test |= (list.item[0] != &my_item[0]);
    test |= (list.item[1] != &my_item[1]);
    test |= (list.item[2] != &my_item[3]);

    test |= (my_item[0].parent.next != &my_item[0])||(my_item[0].parent.prev != &my_item[0]);

    test |= (my_item[1].parent.next != &my_item[2])||(my_item[1].parent.prev != &my_item[2]);
    test |= (my_item[2].parent.next != &my_item[1])||(my_item[2].parent.prev != &my_item[1]);

    test |= (my_item[3].parent.next != &my_item[4])||(my_item[3].parent.prev != &my_item[5]);
    test |= (my_item[4].parent.next != &my_item[5])||(my_item[4].parent.prev != &my_item[3]);
    test |= (my_item[5].parent.next != &my_item[3])||(my_item[5].parent.prev != &my_item[4]);

    print_test_res(test);

    printf("Test 3: bgrt_pitem_cut function: ");

    bgrt_pitem_cut(&my_item[3]);

    test |= (list.item[2] != (bgrt_item_t *)&my_item[4]);

    bgrt_pitem_cut(&my_item[4]);
    bgrt_pitem_cut(&my_item[5]);

    test |= (list.item[2] != 0)||(list.map != (bgrt_map_t)3);

    bgrt_pitem_cut(&my_item[1]);
    bgrt_pitem_cut(&my_item[2]);

    test |= (list.item[1] != 0)||(list.map != (bgrt_map_t)1);

    bgrt_pitem_cut(&my_item[0]);

    test |= (list.item[0] != 0)||(list.map != (bgrt_map_t)0);

    for (i=0; i<6; i++)
    {
        test |= (my_item[i].prio != my_prio[i])
                ||(my_item[i].list != (bgrt_xlist_t *)0)
                ||(my_item[i].parent.next != (bgrt_item_t *)&my_item[i])
                ||(my_item[i].parent.prev != (bgrt_item_t *)&my_item[i]);
    }

    print_test_res(test);

    printf("Test 4: bgrt_pitem_xlist_chain function: ");

    for (i=0; i<6; i++)
    {
        bgrt_pitem_insert(&my_item[i], &list);
    }

    test |= (&my_item[0] != bgrt_pitem_xlist_chain(&list));

    test |= (my_item[0].parent.next != &my_item[1])||(my_item[0].parent.prev != &my_item[5]);
    test |= (my_item[1].parent.next != &my_item[2])||(my_item[1].parent.prev != &my_item[0]);
    test |= (my_item[2].parent.next != &my_item[3])||(my_item[2].parent.prev != &my_item[1]);
    test |= (my_item[3].parent.next != &my_item[4])||(my_item[3].parent.prev != &my_item[2]);
    test |= (my_item[4].parent.next != &my_item[5])||(my_item[4].parent.prev != &my_item[3]);
    test |= (my_item[5].parent.next != &my_item[0])||(my_item[5].parent.prev != &my_item[4]);

    print_test_res(test);

    return 0;
}
