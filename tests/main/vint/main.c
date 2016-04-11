#include <stdio.h>
#include <stdlib.h>

// Include BuguRTOS headers.
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

void bgrt_disable_interrupts(void)
{

}

void bgrt_enable_interrupts(void)
{

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
