#include <test_func.h>
void init_hardware(void)
{
	LPC_PINCON->PINSEL1	&= 0xffffcfff;
	LPC_GPIO0->FIODIR |= LED_MSK;
}

void sched_fix_proc_2(void)
{
    disable_interrupts();
    proc[2].flags &= ~PROC_FLG_RT;
    proc[2].flags &= PROC_STATE_CLEAR_MASK;
    enable_interrupts();
}
static void blink_digit( count_t digit )
{
	LED_OFF();
    wait_time(200);
    while(digit--)
    {
    	LED_ON();
    	wait_time(200);
    	LED_OFF();
        wait_time(200);
    }
}
// Can blink numbers from 0 up to 99.
static void blink_num( count_t num )
{
	LED_OFF();
    blink_digit( (num/10)%10 ); // Most significant digit
    wait_time(300);
    blink_digit( num%10 ); //Least significant digit

}
void test_output( bool_t test_result, count_t test_num )
{
    // If test has failed, then where will be abnormal program termination!
    if( !test_result )
    {
        while(1)
        {
        	wait_time(500);
            blink_num( test_num );
        }
    }
}
void test_start(void)
{
	LED_ON();
}
void tests_end(void)
{
	LED_OFF();
	wait_time(1000);
    while(1)
    {
    	LED_ON();
        wait_time(500);
        LED_OFF();
        wait_time(500);
    }
}

unsigned char test_var_sig;
void test_clear(void)
{
    disable_interrupts();
    test_var_sig = 0;
    enable_interrupts();
}
void test_inc(void)
{
	disable_interrupts();
    test_var_sig++;
    enable_interrupts();
}
void systick_hook(void)
{
	NOP();
}
