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
int main()
{
    bgrt_item_t bgrt_item_1 = BGRT_ITEM_T_INIT(bgrt_item_1);
    bgrt_item_t bgrt_item_2, bgrt_item_3;
    bgrt_item_t * head;
    int test;

    printf("Test 1: BGRT_ITEM_T_INIT macro: ");
    if ((bgrt_item_1.next != &bgrt_item_1) || (bgrt_item_1.prev != &bgrt_item_1))
    {
        print_fail();
        return 0;
    }
    else
    {
        print_ok();
    }

    printf("Test 2: bgrt_item_init function: ");
    bgrt_item_init(&bgrt_item_2);
    bgrt_item_init(&bgrt_item_3);
    if ((bgrt_item_2.next != &bgrt_item_2) || (bgrt_item_2.prev != &bgrt_item_2))
    {
        print_fail();
        return 0;
    }
    else
    {
        print_ok();
    }

    printf("Test 3: bgrt_item_insert function: ");
    head = &bgrt_item_1;

    bgrt_item_insert(&bgrt_item_2, head);

    test = (bgrt_item_1.next != &bgrt_item_2) || (bgrt_item_1.prev != &bgrt_item_2);
    test |= (bgrt_item_2.next != &bgrt_item_1) || (bgrt_item_2.prev != &bgrt_item_1);

    bgrt_item_insert(&bgrt_item_3, head);

    test |= (bgrt_item_1.next != &bgrt_item_2) || (bgrt_item_1.prev != &bgrt_item_3);
    test |= (bgrt_item_2.next != &bgrt_item_3) || (bgrt_item_2.prev != &bgrt_item_1);
    test |= (bgrt_item_3.next != &bgrt_item_1) || (bgrt_item_3.prev != &bgrt_item_2);

    if (test)
    {
        print_fail();
        return 0;
    }
    else
    {
        print_ok();
    }

    printf("Test 4: bgrt_item_cut function: ");

    bgrt_item_cut(&bgrt_item_3);

    test = (bgrt_item_1.next != &bgrt_item_2) || (bgrt_item_1.prev != &bgrt_item_2);
    test |= (bgrt_item_2.next != &bgrt_item_1) || (bgrt_item_2.prev != &bgrt_item_1);

    bgrt_item_cut(&bgrt_item_2);

    test |= (bgrt_item_1.next != &bgrt_item_1) || (bgrt_item_1.prev != &bgrt_item_1);

    if (test)
    {
        print_fail();
        return 0;
    }
    else
    {
        print_ok();
    }

    return 0;
}
