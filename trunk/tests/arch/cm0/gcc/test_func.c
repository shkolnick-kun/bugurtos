#include <test_func.h>


#define BUGURT_SYST_CSR 	*(( volatile unsigned long *) 0xE000E010 )
#define BUGURT_SYST_RVR 	*(( volatile unsigned long *) 0xE000E014 )

#define BUGURT_SYS_SHPR3 	*(( volatile unsigned long *) 0xE000ED20 )

#define BUGURT_SYST_RVR_VALUE ( ( CONFIG_FCPU_HZ / CONFIG_FSYSTICK_HZ ) - 1ul )
#define BUGURT_SYST_CSR_VALUE ( 0x00000007 ) //Enable clock, interrrupt, timer.

#ifndef CONFIG_FCPU_HZ
#error "You must define CONFIG_FCPU_HZ macro!!!"
#endif //CONFIG_FCPU_HZ

#ifndef CONFIG_FSYSTICK_HZ
#error "You must define CONFIG_FSYSTICK_HZ macro!!!"
#endif //CONFIG_FSYSTICK_HZ

#if BUGURT_SYST_RVR_VALUE > 0xFFFFFFUL
#error "Impossible SYST_RVR value!!! "
#endif //BUGURT_SYST_RVR_VALUE

void(*test_kernel_preempt)(void) = test_do_nothing;

void kernel_preemt_hook(void)
{
    test_kernel_preempt();
}

void kernel_preemt_hook_add( void(*arg)(void) )
{
    disable_interrupts();
    test_kernel_preempt = arg;
    enable_interrupts();
}

void test_do_nothing(void)
{
    NOP();
}

void init_hardware(void)
{
    __asm__ __volatile__ ("cpsid i \n\t");
    SystemInit();
    // Настраиваем системный таймер и приоритет его прерывания
    BUGURT_SYS_SHPR3 |= (CONFIG_SCHED_PRIO  << ( 8 - CONFIG_PRIO_BITS )) << 24; // SysTick
    BUGURT_SYST_RVR = BUGURT_SYST_RVR_VALUE;
    BUGURT_SYST_CSR = BUGURT_SYST_CSR_VALUE;
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
