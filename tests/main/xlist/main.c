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

#define print_test_res( t ) \
    if( t ) \
    { \
        print_fail(); \
        return 0; \
    } \
    else \
        print_ok(); \

int main()
{
    item_t
        item_1 = INIT_ITEM_T( item_1 ),
        item_2 = INIT_ITEM_T( item_2 ),
        item_3 = INIT_ITEM_T( item_3 );

    item_t * head;
    xlist_t list;
    int test, i;

    printf("Test 1: xlist_init function: ");

    xlist_init( &list );

    test = (list.index != (index_t)0);
    for( i=0; i<BITS_IN_INDEX_T; i++ )
    {
        test |= ( list.item[i]!=(item_t*)0 );
    }

    print_test_res( test );

    printf("Test 2: xlist_head function: ");

    list.index = 5;
    list.item[0] = &item_1;
    list.item[2] = &item_2;
    item_insert(&item_3, list.item[0]);

    head = xlist_head( &list );

    print_test_res( (head != &item_1) );

    printf("Test 3: xlist_switch function: ");

    xlist_switch( &list, 0 );
    head = xlist_head( &list );
    print_test_res( (head != &item_3) );

    return 0;
}
