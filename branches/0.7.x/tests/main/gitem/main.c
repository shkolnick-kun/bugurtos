#include <stdio.h>

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
        print_ok()

int main()
{
    gitem_t item = INIT_G_ITEM_T(item,3);
    gitem_t my_item[6];
    prio_t my_prio[] = { 0,1,1,2,2,2 };
    gxlist_t list, list2;
    int i, test;

    //================================================================
    printf("Test 1: INIT_G_ITEM_T macro: ");

    test  = ( item.group->prio != (prio_t)3 );
    test |= ( item.group->link != (xlist_t *)0 );
    test |= ( item.group != &item.grp );
    test |= ( item.parent.next != (item_t *)&item );
    test |= ( item.parent.prev != (item_t *)&item );
    print_test_res( test );
    //================================================================
    printf("Test 2: gitem_init function: ");
    test = 0;
    for( i=0; i<6; i++ )
    {
        gitem_init( &my_item[i], my_prio[i] );
        test |= ( my_item[i].group != &my_item[i].grp );
        test |= ( my_item[i].group->prio != my_prio[i] );
        test |= ( my_item[i].group->link != (xlist_t *)0 );
        test |= ( my_item[i].group->el_num != 1 );

        test |= ( my_item[i].parent.next != (item_t *)&my_item[i] );
        test |= ( my_item[i].parent.prev != (item_t *)&my_item[i] );
    }
    print_test_res( test );
    //================================================================
    printf("Test 3: gitem_insert function: ");
    gxlist_init( &list );
    for( i=0; i<6; i++ )
    {
        gitem_insert( &my_item[i], (xlist_t *)&list );
        test |= ( my_item[i].group != &my_item[i].grp );
        test |= ( my_item[i].group->link != &list );
        test |= ( my_item[i].group->el_num != 1 );
    }
    test |= ( list.parent.index != (index_t)7 );
    test |= ( list.parent.item[0] != (item_t *)&my_item[0] );
    test |= ( list.parent.item[1] != (item_t *)&my_item[1] );
    test |= ( list.parent.item[2] != (item_t *)&my_item[3] );

    test |= ( my_item[0].parent.next != (item_t *)&my_item[0] )||( my_item[0].parent.prev != (item_t *)&my_item[0] );

    test |= ( my_item[1].parent.next != (item_t *)&my_item[2] )||( my_item[1].parent.prev != (item_t *)&my_item[2] );
    test |= ( my_item[2].parent.next != (item_t *)&my_item[1] )||( my_item[2].parent.prev != (item_t *)&my_item[1] );

    test |= ( my_item[3].parent.next != (item_t *)&my_item[4] )||( my_item[3].parent.prev != (item_t *)&my_item[5] );
    test |= ( my_item[4].parent.next != (item_t *)&my_item[5] )||( my_item[4].parent.prev != (item_t *)&my_item[3] );
    test |= ( my_item[5].parent.next != (item_t *)&my_item[3] )||( my_item[5].parent.prev != (item_t *)&my_item[4] );

    print_test_res( test );
    //================================================================
    printf("Test 4: gitem_cut function: ");

    gitem_cut( &my_item[3] );

    test |= ( list.parent.item[2] != (item_t *)&my_item[4] );

    test |= ( my_item[3].parent.next != (item_t *)&my_item[3] )||( my_item[3].parent.prev != (item_t *)&my_item[3] );
    test |= ( my_item[3].group->el_num != 1 );
    test |= ( my_item[3].group->link != 0 );

    test |= ( my_item[4].parent.next != (item_t *)&my_item[5] )||( my_item[4].parent.prev != (item_t *)&my_item[5] );
    test |= ( my_item[5].parent.next != (item_t *)&my_item[4] )||( my_item[5].parent.prev != (item_t *)&my_item[4] );
    test |= ( my_item[4].group->el_num != 1 );
    test |= ( my_item[5].group->el_num != 1 );
    test |= ( my_item[4].group->link != &list );
    test |= ( my_item[5].group->link != &list );

    gitem_cut( &my_item[5] );

    test |= ( list.parent.item[2] != (item_t *)&my_item[4] );

    test |= ( my_item[4].parent.next != (item_t *)&my_item[4] )||( my_item[4].parent.prev != (item_t *)&my_item[4] );
    test |= ( my_item[4].group->el_num != 1 );
    test |= ( my_item[4].group->link != &list );

    test |= ( my_item[5].parent.next != (item_t *)&my_item[5] )||( my_item[5].parent.prev != (item_t *)&my_item[5] );
    test |= ( my_item[5].group->el_num != 1 );
    test |= ( my_item[5].group->link != 0 );

    gitem_cut( &my_item[4] );

    test |= ( list.parent.item[2] != 0 )||( list.parent.index != (index_t)3 );

    test |= ( my_item[4].parent.next != (item_t *)&my_item[4] )||( my_item[4].parent.prev != (item_t *)&my_item[4] );
    test |= ( my_item[4].group->el_num != 1 );
    test |= ( my_item[4].group->link != 0 );

    test |= ( list.parent.item[2] != 0 )||( list.parent.index != (index_t)3 );

    gitem_cut( &my_item[1] );
    gitem_cut( &my_item[2] );

    test |= ( list.parent.item[1] != 0 )||( list.parent.index != (index_t)1 );

    gitem_cut( &my_item[0] );

    test |= ( list.parent.item[0] != 0 )||( list.parent.index != (index_t)0 );

    for( i=0; i<6; i++ )
    {
        test |= ( my_item[i].group->prio != my_prio[i] );
        test |= ( my_item[i].group->link != (void *)0 );
        test |= ( my_item[i].parent.next != (item_t *)&my_item[i] );
        test |= ( my_item[i].parent.prev != (item_t *)&my_item[i] );
    }

    print_test_res( test );
    //================================================================
    printf("Test 5: gitem_insert_group function: ");
    gxlist_init( &list );
    for( i=0; i<6; i++ )
    {
        gitem_insert_group( &my_item[i], &list );
        test |= ( my_item[i].group->link != &list );
    }
    test |= ( list.parent.index != (index_t)7 );
    test |= ( list.parent.item[0] != (item_t *)&my_item[0] );
    test |= ( list.parent.item[1] != (item_t *)&my_item[1] );
    test |= ( list.parent.item[2] != (item_t *)&my_item[3] );

    test |= ( my_item[0].parent.next != (item_t *)&my_item[0] )||( my_item[0].parent.prev != (item_t *)&my_item[0] );
    test |= ( my_item[0].group != &my_item[0].grp );
    test |= ( my_item[0].group->el_num != 1 );

    test |= ( my_item[1].parent.next != (item_t *)&my_item[2] )||( my_item[1].parent.prev != (item_t *)&my_item[2] );
    test |= ( my_item[2].parent.next != (item_t *)&my_item[1] )||( my_item[2].parent.prev != (item_t *)&my_item[1] );
    test |= ( my_item[1].group != &my_item[1].grp );
    test |= ( my_item[2].group != &my_item[1].grp );
    test |= ( my_item[1].group->el_num != 2 );

    test |= ( my_item[3].parent.next != (item_t *)&my_item[4] )||( my_item[3].parent.prev != (item_t *)&my_item[5] );
    test |= ( my_item[4].parent.next != (item_t *)&my_item[5] )||( my_item[4].parent.prev != (item_t *)&my_item[3] );
    test |= ( my_item[5].parent.next != (item_t *)&my_item[3] )||( my_item[5].parent.prev != (item_t *)&my_item[4] );
    test |= ( my_item[3].group != &my_item[3].grp );
    test |= ( my_item[4].group != &my_item[3].grp );
    test |= ( my_item[5].group != &my_item[3].grp );
    test |= ( my_item[3].group->el_num != 3 );

    print_test_res( test );
    //================================================================
    printf("Test 6: gitem_cut function: ");

    gitem_cut( &my_item[3] );

    test |= ( list.parent.item[2] != (item_t *)&my_item[4] );

    test |= ( my_item[3].parent.next != (item_t *)&my_item[3] )||( my_item[3].parent.prev != (item_t *)&my_item[3] );

    test |= ( my_item[4].parent.next != (item_t *)&my_item[5] )||( my_item[4].parent.prev != (item_t *)&my_item[5] );
    test |= ( my_item[5].parent.next != (item_t *)&my_item[4] )||( my_item[5].parent.prev != (item_t *)&my_item[4] );
    test |= ( my_item[4].group->el_num != 2 );
    test |= ( my_item[5].group != my_item[4].group );
    test |= ( my_item[4].group->link != &list );

    gitem_cut( &my_item[5] );

    test |= ( list.parent.item[2] != (item_t *)&my_item[4] );

    test |= ( my_item[4].parent.next != (item_t *)&my_item[4] )||( my_item[4].parent.prev != (item_t *)&my_item[4] );
    test |= ( my_item[4].group->el_num != 1 );
    test |= ( my_item[4].group->link != &list );

    test |= ( my_item[5].parent.next != (item_t *)&my_item[5] )||( my_item[5].parent.prev != (item_t *)&my_item[5] );
    test |= ( my_item[5].group->el_num != 1 );
    test |= ( my_item[5].group->link != 0 );

    gitem_cut( &my_item[4] );

    test |= ( list.parent.item[2] != 0 )||( list.parent.index != (index_t)3 );

    test |= ( my_item[4].parent.next != (item_t *)&my_item[4] )||( my_item[4].parent.prev != (item_t *)&my_item[4] );
    test |= ( my_item[4].group->el_num != 1 );
    test |= ( my_item[4].group->link != 0 );

    gitem_cut( &my_item[1] );
    gitem_cut( &my_item[2] );

    test |= ( list.parent.item[1] != 0 )||( list.parent.index != (index_t)1 );

    gitem_cut( &my_item[0] );

    test |= ( list.parent.item[0] != 0 )||( list.parent.index != (index_t)0 );

    for( i=0; i<6; i++ )
    {
        test |= ( my_item[i].group->el_num != 1 );
        test |= ( my_item[i].group->prio != my_prio[i] );
        test |= ( my_item[i].group->link != (void *)0 );
        test |= ( my_item[i].parent.next != (item_t *)&my_item[i] );
        test |= ( my_item[i].parent.prev != (item_t *)&my_item[i] );
    }

    print_test_res( test );
    //================================================================
    printf("Test 7: gxlist_merge function: ");

    gxlist_init( &list2 );

    gitem_insert_group( &my_item[0], &list );
    gitem_insert_group( &my_item[1], &list2 );
    gitem_insert_group( &my_item[2], &list );
    gitem_insert_group( &my_item[3], &list2 );
    gitem_insert_group( &my_item[4], &list );
    gitem_insert_group( &my_item[5], &list2 );

    test |= ( list.parent.index != (index_t)7 );
    test |= ( list2.parent.index != (index_t)6 );

    test |= ( my_item[0].group->el_num != 1 );
    test |= ( my_item[1].group->el_num != 1 );
    test |= ( my_item[2].group->el_num != 1 );
    test |= ( my_item[3].group->el_num != 2 );
    test |= ( my_item[4].group->el_num != 1 );
    test |= ( my_item[5].group->el_num != 2 );

    test |= ( my_item[0].parent.next != (item_t *)&my_item[0] )||( my_item[0].parent.prev != (item_t *)&my_item[0] );
    test |= ( my_item[1].parent.next != (item_t *)&my_item[1] )||( my_item[1].parent.prev != (item_t *)&my_item[1] );
    test |= ( my_item[2].parent.next != (item_t *)&my_item[2] )||( my_item[2].parent.prev != (item_t *)&my_item[2] );
    test |= ( my_item[3].parent.next != (item_t *)&my_item[5] )||( my_item[3].parent.prev != (item_t *)&my_item[5] );
    test |= ( my_item[4].parent.next != (item_t *)&my_item[4] )||( my_item[4].parent.prev != (item_t *)&my_item[4] );
    test |= ( my_item[5].parent.next != (item_t *)&my_item[3] )||( my_item[5].parent.prev != (item_t *)&my_item[3] );

    test |= ( my_item[0].group->link != (void *)&list );
    test |= ( my_item[1].group->link != (void *)&list2 );
    test |= ( my_item[2].group->link != (void *)&list );
    test |= ( my_item[3].group->link != (void *)&list2 );
    test |= ( my_item[4].group->link != (void *)&list );
    test |= ( my_item[5].group->link != (void *)&list2 );

    gxlist_merge( &list2, &list );

    test |= ( my_item[0].group->el_num != 1 );
    test |= ( my_item[1].group->el_num != 1 );
    test |= ( my_item[2].group->el_num != 1 );
    test |= ( my_item[3].group->el_num != 2 );
    test |= ( my_item[4].group->el_num != 1 );
    test |= ( my_item[5].group->el_num != 2 );

    test |= ( my_item[0].parent.next != (item_t *)&my_item[0] )||( my_item[0].parent.prev != (item_t *)&my_item[0] );

    test |= ( my_item[1].parent.next != (item_t *)&my_item[2] )||( my_item[1].parent.prev != (item_t *)&my_item[2] );
    test |= ( my_item[2].parent.next != (item_t *)&my_item[1] )||( my_item[2].parent.prev != (item_t *)&my_item[1] );

    test |= ( my_item[3].parent.next != (item_t *)&my_item[5] )||( my_item[3].parent.prev != (item_t *)&my_item[4] );
    test |= ( my_item[4].parent.next != (item_t *)&my_item[3] )||( my_item[4].parent.prev != (item_t *)&my_item[5] );
    test |= ( my_item[5].parent.next != (item_t *)&my_item[4] )||( my_item[5].parent.prev != (item_t *)&my_item[3] );

    test |= ( my_item[0].group->link != (void *)&list );
    test |= ( my_item[1].group->link != (void *)&list );
    test |= ( my_item[2].group->link != (void *)&list );
    test |= ( my_item[3].group->link != (void *)&list );
    test |= ( my_item[4].group->link != (void *)&list );
    test |= ( my_item[5].group->link != (void *)&list );

    print_test_res( test );
    return 0;
}
