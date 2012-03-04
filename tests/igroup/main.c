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

group_t my_group = INIT_GROUP_T(2);

group_t group1, group2, group3;
group_t * pop;

int main()
{
    spin_init( &kernel.pool_lock );
    kernel.pool = (group_t *)0;

    group_init( &group1, 1 );
    group_init( &group2, 1 );
    group_init( &group3, 1 );

    group_push( &group1 );
    group_push( &group2 );
    group_push( &group3 );

    pop = group_pop();
    pop = group_pop();
    pop = group_pop();

    printf("Hello world!\n");
    return 0;
}
