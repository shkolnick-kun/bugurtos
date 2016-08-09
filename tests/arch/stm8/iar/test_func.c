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

    CLK_PCKENR1|=0x02;
    SPI_CR1 = 0x04;
    SPI_CR2 = 0x03;
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
void test_output( bgrt_bool_t test_result, bgrt_cnt_t test_num )
{
    // If test has failed, then where will be abnormal program termination!
    if( !test_result )
    {
        bgrt_disable_interrupts();
        test_is_running = 0;
        test_fail = test_num;
        while(1);
    }
}
void test_start(void)
{
    test_is_running = 1;
}
void tests_end(void)
{
    bgrt_disable_interrupts();
    test_is_running = 0;
    while(1);
}

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
    SPI_DR = 0xff;
    SPI_ICR = 0x80;
    SPI_SR = 0x00;
    SPI_CR1 |= 0x40;
}
BGRT_ISR( SPI_TXE_vector )
{
    SPI_CR1 &= ~0x40;
    SPI_ICR &= ~0x80;
}
