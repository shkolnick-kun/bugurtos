#include <test_func.h>
#include <libopencm3/stm32/flash.h>

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

const struct rcc_clock_scale rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_END] = {
	{ /* 216MHz */
		.pllm = 8,
		.plln = 432,
		.pllp = 2,
		.pllq = 9,
		.flash_config = FLASH_ACR_ICEN | FLASH_ACR_DCEN |
				FLASH_ACR_LATENCY_7WS,
		.hpre = RCC_CFGR_HPRE_DIV_NONE,
		.ppre1 = RCC_CFGR_PPRE_DIV_4,
		.ppre2 = RCC_CFGR_PPRE_DIV_2,
		.vos_scale = PWR_SCALE1,
		.overdrive = 1,
		.apb1_frequency = 108000000,
		.apb2_frequency = 216000000,
	},
};

void init_hardware(void)
{
    __asm__ __volatile__ ("cpsid i \n\t");
    rcc_clock_setup_hse_3v3(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_216MHZ]);
    /* Enable GPIOI clock. */
    rcc_periph_clock_enable(RCC_GPIOB);
    /* Set GPIO12 (in GPIO port C) to 'output push-pull'. */
    gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GREEN | RED);
    gpio_clear(GPIOB, GREEN);
    gpio_clear(GPIOB, RED);
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
