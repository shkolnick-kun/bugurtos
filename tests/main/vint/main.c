#include <stdio.h>
#include <stdlib.h>

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


void bgrt_spin_init(bgrt_lock_t * lock)
{
    (void)lock;
}

void bgrt_spin_lock(bgrt_lock_t * lock)
{
    (void)lock;
}

void bgrt_spin_free(bgrt_lock_t * lock)
{
    (void)lock;
}

void BGRT_INT_LOCK(void)
{
    printf("Interrupts disabled.\n");
}

void BGRT_INT_FREE(void)
{
    printf("Interrupts enabled.\n");
}

bgrt_vic_t tst_vic;

bgrt_vint_t tst_vint_1;
static void tst_vfunc_1(bgrt_vic_t * vic)
{
    printf("Do work for tst_vint_1:%d\n", (int)vic->prio);
}

bgrt_vint_t tst_vint_2;
static void tst_vfunc_2(bgrt_vic_t * vic)
{
    printf("Do work for tst_vint_2:%d\n", (int)vic->prio);
}

bgrt_vint_t tst_vint_3;
static void tst_vfunc_3(bgrt_vic_t * vic)
{
    printf("Do work for tst_vint_3:%d\n", (int)vic->prio);
}

bgrt_vint_t tst_vint_4;
static void tst_vfunc_4(bgrt_vic_t * vic)
{
    printf("Do work for tst_vint_4:%d\n", (int)vic->prio);

    printf("Insert VINT2.\n");
    bgrt_vint_push(&tst_vint_2, &tst_vic);
    printf("Do nested work.\n");
    bgrt_vic_do_work(&tst_vic);
    printf("Done nested work.\n");
}

int main()
{
    bgrt_vic_init(&tst_vic);
    bgrt_vint_init(&tst_vint_1,      BGRT_PRIO_LOWEST, (bgrt_code_t)tst_vfunc_1, (void *)&tst_vic);
    bgrt_vint_init(&tst_vint_2,                     2, (bgrt_code_t)tst_vfunc_2, (void *)&tst_vic);
    bgrt_vint_init(&tst_vint_3,                     2, (bgrt_code_t)tst_vfunc_3, (void *)&tst_vic);
    bgrt_vint_init(&tst_vint_4,      BGRT_PRIO_LOWEST, (bgrt_code_t)tst_vfunc_4, (void *)&tst_vic);

    printf("Do work on empty VIC.\n");
    bgrt_vic_do_work(&tst_vic);

    printf("\nInsert VINT1.\n");
    bgrt_vint_push_isr(&tst_vint_1, &tst_vic);
    printf("\nDo work on with 1 VINT.\n");
    bgrt_vic_do_work(&tst_vic);

    printf("\nInsert VINT1.\n");
    bgrt_vint_push(&tst_vint_1, &tst_vic);
    printf("\nInsert VINT2.\n");
    bgrt_vint_push(&tst_vint_2, &tst_vic);
    printf("\nDo work on with 2 VINTs.\n");
    bgrt_vic_do_work(&tst_vic);

    printf("\nInsert VINT1.\n");
    bgrt_vint_push(&tst_vint_1, &tst_vic);
    printf("\nInsert VINT2.\n");
    bgrt_vint_push(&tst_vint_2, &tst_vic);
    printf("\nInsert VINT3.\n");
    bgrt_vint_push(&tst_vint_3, &tst_vic);

    printf("\nDo work on with 3 VINTs.\n");
    bgrt_vic_do_work(&tst_vic);

    printf("\nInsert VINT4.\n");
    bgrt_vint_push(&tst_vint_4, &tst_vic);
    printf("\nDo work on with nested VINTs.\n");
    bgrt_vic_do_work(&tst_vic);

    printf("\nHello world!\n");
    return 0;
}
