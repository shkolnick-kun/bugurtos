#include <stdio.h>
#include <stdlib.h>
#include "../../include/bugurt.h"
pcounter_t cnt;
int main()
{
    pcounter_init(&cnt);
    pcounter_inc(&cnt, 2);
    pcounter_inc(&cnt, 2);
    pcounter_dec(&cnt, 2);
    pcounter_dec(&cnt, 2);
    pcounter_plus(&cnt, 3, 2);
    pcounter_plus(&cnt, 3, 2);
    pcounter_minus(&cnt, 3, 1);
    pcounter_minus(&cnt, 3, 3);
    printf("Hello world!\n");
    return 0;
}
