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
    pool_t pool = INIT_POOL_T(), pool2 = INIT_POOL_T();
    group_t grp[2], group = INIT_GROUP_T(1);
    group_t * gpointer;
    int test;

    printf("Test 1: INIT_POOL_T macro: ");
    test = (pool.top != 0)||(pool.bot != 0);
    print_test_res(test);

    printf("Test 2: INIT_GROUP_T macro: ");
    test = (group.link != 0);
    test |= (group.prio != 1);
    test |= (group.el_num != 1);
    print_test_res(test);

    printf("Test 3: pool_init method: ");
    pool.top = (group_t *)1;
    pool.bot = (group_t *)2;
    pool_init(&pool);
    test = (pool.top != 0)||(pool.bot != 0);
    print_test_res(test);

    printf("Test 4: group_init method: ");
    group_init(&grp[0], 1);
    test = (grp[0].link != 0);
    test |= (grp[0].prio != 1);
    test |= (grp[0].el_num != 1);
    group_init(&grp[1], 2);
    test |= (grp[1].link != 0);
    test |= (grp[1].prio != 2);
    test |= (grp[1].el_num != 1);
    print_test_res(test);

    printf("Test 5: group_push method: ");
    group_push( &grp[0], &pool );
    test = (grp[0].link != 0);
    test |= (pool.top != &grp[0]);
    test |= (pool.bot != &grp[0]);
    print_test_res(test);

    printf("Test 6: group_push method: ");
    group_push( &grp[1], &pool );
    test = (grp[1].link != &grp[0]);
    test |= (pool.top != &grp[1]);
    test |= (pool.bot != &grp[0]);
    print_test_res(test);

    printf("Test 7: group_pop method: ");
    gpointer = group_pop( &pool );
    test = (gpointer != &grp[1]);
    test |= (pool.top != &grp[0]);
    test |= (pool.bot != &grp[0]);
    print_test_res(test);

    printf("Test 8: group_pop method: ");
    gpointer = group_pop( &pool );
    test = (gpointer != &grp[0]);
    test |= (pool.top != 0);
    test |= (pool.bot != 0);
    print_test_res(test);

    printf("Test 9: pool_merge method: ");
    group_push( &grp[0], &pool2 );
    group_push( &grp[1], &pool2 );
    group_push( &group, &pool );
    pool_merge( &pool2, &pool );
    test = (group.link != 0);
    test |= (grp[0].link != &group);
    test |= (grp[1].link != &grp[0]);
    test |= (pool.top != &grp[1]);
    test |= (pool.bot != &group);
    test |= (pool2.top != 0);
    test |= (pool2.bot != 0);

    pool_merge( &pool2, &pool );

    test = (group.link != 0);
    test |= (grp[0].link != &group);
    test |= (grp[1].link != &grp[0]);
    test |= (pool.top != &grp[1]);
    test |= (pool.bot != &group);
    test |= (pool2.top != 0);
    test |= (pool2.bot != 0);

    pool_merge( &pool, &pool2 );

    test = (group.link != 0);
    test |= (grp[0].link != &group);
    test |= (grp[1].link != &grp[0]);
    test |= (pool2.top != &grp[1]);
    test |= (pool2.bot != &group);
    test |= (pool.top != 0);
    test |= (pool.bot != 0);

    print_test_res(test);

    return 0;
}

