#include <test_func.h>

void(*test_kernel_preempt)(void) = test_do_nothing;

void kernel_preemt_hook(void)
{
    test_kernel_preempt();
}

void kernel_preemt_hook_add( void(*arg)(void) )
{
    bgrt_disable_interrupts();
    test_kernel_preempt = arg;
    bgrt_enable_interrupts();
}

void test_do_nothing(void)
{
    NOP();
}

#define RLED_ON()  GPIOC_ODR |= GPIO7;
#define RLED_OFF() GPIOC_ODR &= ~GPIO7;

#define GLED_ON()  GPIOE_ODR |= GPIO7;
#define GLED_OFF() GPIOE_ODR &= ~GPIO7;

void init_hardware(void)
{
    bgrt_disable_interrupts();
    
    CLK_CKDIVR = 0x00;
    
    TIM4_CR1   = 0x01;
    TIM4_IER   = 0x01;
    TIM4_SR    = 0x00;
    TIM4_EGR   = 0x00;
    TIM4_CNTR  = 0x00;
    TIM4_PSCR  = 0x07; // 0x07 - 1 мс, 0x05 - 250 мкс
    TIM4_ARR   = 0x7C;

    CLK_PCKENR1 |= CLK_PCKEN1_SPI1;
    SPI1_CR1 = 0x04;
    SPI1_CR2 = 0x03;
    
    gpio_mode_setup (GPIOE, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO7);//Green
    gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO7);
    /*Process leds*/
    gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO0);
    gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO1);
    gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO2);
    gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO3);
    gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO4);
    gpio_mode_setup (GPIOC, GPIO_MODE_OUTPUT, GPIO_CR1_PP, GPIO_CR2_2, GPIO5);
    GPIOC_ODR &= ~(GPIO0|GPIO1|GPIO2|GPIO3|GPIO4|GPIO5); //Off everything
}

void sched_fix_bgrt_proc_2(void)
{
    bgrt_disable_interrupts();
    proc[2].flags &= ~BGRT_PROC_FLG_RT;
    proc[2].flags &= BGRT_PROC_STATE_CLEAR_MASK;
    bgrt_enable_interrupts();
}

unsigned char test_fail = 0;
unsigned char test_is_running = 0;

static void blink_digit( bgrt_cnt_t digit )
{
    RLED_ON();
    bgrt_wait_time(200);

    if(!digit)
    {
    	RLED_ON();
    	bgrt_wait_time(1000);
    	RLED_OFF();
    	return;
    }

    while(digit--)
    {
    	RLED_ON();
    	bgrt_wait_time(200);
    	RLED_OFF();
        bgrt_wait_time(200);
    }
}
// Can blink numbers from 0 up to 99.
static void blink_num( bgrt_cnt_t num )
{
    RLED_OFF();
    blink_digit( (num/10)%10 ); // Most significant digit
    bgrt_wait_time(300);
    blink_digit( num%10 ); //Least significant digit

}
void test_output( bgrt_bool_t test_result, bgrt_cnt_t test_num )
{
    // If test has failed, then where will be abnormal program termination!
    if( !test_result )
    {
        GLED_OFF();
        while(1)
        {
            bgrt_wait_time(500);
            blink_num( test_num );
        }
    }
}

void test_start(void)
{
    GLED_ON();
    RLED_OFF();
}

void tests_end(void)
{
    GLED_OFF();
    bgrt_wait_time(1000);
    while(1)
    {
    	GLED_ON();
        bgrt_wait_time(500);
        GLED_OFF();
        bgrt_wait_time(500);
    }
}

void blink_1(void) {GPIOC_ODR ^= GPIO0;}
void blink_2(void) {GPIOC_ODR ^= GPIO1;}
void blink_3(void) {GPIOC_ODR ^= GPIO2;}
void blink_4(void) {GPIOC_ODR ^= GPIO3;}
void blink_5(void) {GPIOC_ODR ^= GPIO4;}
void blink_6(void) {GPIOC_ODR ^= GPIO5;}

unsigned char test_var_sig;
void test_clear(void)
{
    bgrt_disable_interrupts();
    test_var_sig = 0;
    bgrt_enable_interrupts();
}

void test_inc(void)
{
    bgrt_disable_interrupts();
    test_var_sig++;
    bgrt_enable_interrupts();
}

void systick_hook(void)
{
    SPI1_DR = 0xff;
    SPI1_ICR = 0x80;
    SPI1_SR = 0x00;
    SPI1_CR1 |= 0x40;
}

BUGURT_INTERRUPT( SPI_TXE_VECTOR )
{
    SPI1_CR1 &= ~0x40;
    SPI1_ICR &= ~0x80;
}
