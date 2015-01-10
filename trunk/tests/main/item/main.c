#include <stdio.h>

// Incliude BuguRTOS headers.
#include <bugurt.h>

void print_ok(void)
{
    printf( "\t\t[ OK ]\n" );
}
void print_fail(void)
{
    printf( "\t\t[Fail]\n" );
}
int main()
{
    item_t item_1 = INIT_ITEM_T( item_1 );
    item_t item_2, item_3;
    item_t * head;
    int test;

    printf("Test 1: INIT_ITEM_T macro: ");
    if( (item_1.next != &item_1) || (item_1.prev != &item_1) )
    {
        print_fail();
        return 0;
    }
    else
    {
        print_ok();
    }

    printf("Test 2: item_init function: ");
    item_init( &item_2 );
    item_init( &item_3 );
    if( (item_2.next != &item_2) || (item_2.prev != &item_2) )
    {
        print_fail();
        return 0;
    }
    else
    {
        print_ok();
    }

    printf("Test 3: item_insert function: ");
    head = &item_1;

    item_insert( &item_2, head );

    test = (item_1.next != &item_2) || (item_1.prev != &item_2);
    test |= (item_2.next != &item_1) || (item_2.prev != &item_1);

    item_insert( &item_3, head );

    test |= (item_1.next != &item_2) || (item_1.prev != &item_3);
    test |= (item_2.next != &item_3) || (item_2.prev != &item_1);
    test |= (item_3.next != &item_1) || (item_3.prev != &item_2);

    if( test )
    {
        print_fail();
        return 0;
    }
    else
    {
        print_ok();
    }

    printf("Test 4: item_cut function: ");

    item_cut( &item_3 );

    test = (item_1.next != &item_2) || (item_1.prev != &item_2);
    test |= (item_2.next != &item_1) || (item_2.prev != &item_1);

    item_cut( &item_2 );

    test |= (item_1.next != &item_1) || (item_1.prev != &item_1);

    if( test )
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
