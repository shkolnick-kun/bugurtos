#include <test_func.h>

float a = 1.0, b=3.14;

void(*test_kernel_preempt)(void) = test_do_nothing;

void kernel_preemt_hook(void)
{
    test_kernel_preempt();
}

void kernel_preemt_hook_add(void(*arg)(void))
{
    BGRT_INT_LOCK();
    test_kernel_preempt = arg;
    BGRT_INT_FREE();
}

void test_do_nothing(void)
{
    NOP();
}

void init_hardware(void)
{
    __asm__ __volatile__ ("cpsid i \n\t");
    rcc_clock_setup_hse_3v3(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);
    /* Enable GPIOC clock. */
    rcc_periph_clock_enable(RCC_GPIOD);
    /* Set GPIO12 (in GPIO port C) to 'output push-pull'. */
    gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GREEN | RED);
    gpio_clear(GPIOD, GREEN);
    gpio_clear(GPIOD, RED);
}

void sched_fix_bgrt_proc_2(void)
{
    BGRT_INT_LOCK();
    proc[2].flags &= ~BGRT_PROC_FLG_RT;
    proc[2].flags &= BGRT_PROC_STATE_CLEAR_MASK;
    BGRT_INT_FREE();
}
static void blink_digit(bgrt_cnt_t digit)
{
    LED_OFF(RED);
    bgrt_wait_time(200);

    if (!digit)
    {
        LED_ON(RED);
        bgrt_wait_time(1000);
        LED_OFF(RED);
        return;
    }

    while (digit--)
    {
        LED_ON(RED);
        bgrt_wait_time(200);
        LED_OFF(RED);
        bgrt_wait_time(200);
    }
}
// Can blink numbers from 0 up to 99.
static void blink_num(bgrt_cnt_t num)
{
    LED_OFF(RED);
    blink_digit((num/10)%10); // Most significant digit
    bgrt_wait_time(300);
    blink_digit(num%10); //Least significant digit

}
void test_output(bgrt_bool_t test_result, bgrt_cnt_t test_num)
{
    // If test has failed, then where will be abnormal program termination!
    if (!test_result)
    {
        LED_OFF(GREEN);
        while (1)
        {
            bgrt_wait_time(500);
            blink_num(test_num);
        }
    }
}
void test_start(void)
{
    LED_ON(GREEN);
}
void tests_end(void)
{
    LED_OFF(GREEN);
    bgrt_wait_time(1000);
    while (1)
    {
        LED_ON(GREEN);
        bgrt_wait_time(500);
        LED_OFF(GREEN);
        bgrt_wait_time(500);
    }
}

unsigned char test_var_sig;
void test_clear(void)
{
    BGRT_INT_LOCK();
    test_var_sig = 0;
    BGRT_INT_FREE();
}
void test_inc(void)
{
    BGRT_INT_LOCK();
    test_var_sig++;
    BGRT_INT_FREE();
}
void systick_hook(void)
{
    NOP();
}

void HardFault_Handler(void)
{
    while (1)
    {

    }
}

void float_test_1(void)
{
    a+=1.735;
    if (a >= 178.0) a = 1.11;
}

void float_test_2(void)
{
    b*=1.005;
    if (b >= 178.0) b = 1.17;
}
