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
        print_ok(); \

int main()
{
    bgrt_item_t
    bgrt_item_1 = BGRT_ITEM_T_INIT(bgrt_item_1),
                  bgrt_item_2 = BGRT_ITEM_T_INIT(bgrt_item_2),
                                bgrt_item_3 = BGRT_ITEM_T_INIT(bgrt_item_3);

    bgrt_item_t * head;
    bgrt_xlist_t list;
    int test, i;

    printf("Test 1: bgrt_xlist_init function: ");

    bgrt_xlist_init(&list);

    test = (list.map != (bgrt_map_t)0);
    for (i=0; i<BGRT_BITS_IN_INDEX_T; i++)
    {
        test |= (list.item[i]!=(bgrt_item_t*)0);
    }

    print_test_res(test);

    printf("Test 2: bgrt_xlist_head function: ");

    list.map = 5;
    list.item[0] = &bgrt_item_1;
    list.item[2] = &bgrt_item_2;
    bgrt_item_insert(&bgrt_item_3, list.item[0]);

    head = bgrt_xlist_head(&list);

    print_test_res((head != &bgrt_item_1));

    printf("Test 3: bgrt_xlist_switch function: ");

    bgrt_xlist_switch(&list, 0);
    head = bgrt_xlist_head(&list);
    print_test_res((head != &bgrt_item_3));

    return 0;
}
