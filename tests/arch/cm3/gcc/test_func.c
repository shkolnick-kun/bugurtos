#include <test_func.h>

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

    rcc_clock_setup_pll(&rcc_clock_config[RCC_CLOCK_VRANGE1_HSI_PLL_32MHZ]);

    rcc_periph_clock_enable(RCC_GPIOB);
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GREEN);
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, RED);


    dwt_enable_cycle_counter();
    /* *(uint32_t *)0xE0001004 */
}

void sched_fix_bgrt_proc_2(void)
{
    BGRT_INT_LOCK();
    proc[2].flags &= ~BGRT_PROC_FLG_RT;
    proc[2].flags &= BGRT_PROC_STATE_CLEAR_MASK;
    BGRT_INT_FREE();
}
// Can blink numbers from 0 up to 99.
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
