#include <test_func.h>
void(*test_kernel_preempt)(void) = test_do_nothing;

void kernel_preemt_hook_add(void(*arg)(void))
{
    cli();
    test_kernel_preempt = arg;
    sei();
}

void init_hardware(void)
{
    cli();
    TCCR2A = 0x02;//
    TCCR2B = 0x05;// prescaler=128
    OCR2A  = 124;
    OCR2B  = 0x00;
    TIMSK2 = 0x00; // scheduler not started
    TIFR2  = 0x00;

    //EICRA = 0x0A; //falling edge
    //EIMSK = 0x03; //resched generates int1, mask 0x02
    //EIFR  |= 0x03;

    DDRB = 0x3F;
    PORTB = 0x00;
    DDRC = 0x3F;
    PORTC = 0x00;
    DDRD = 0xFE;
    PORTD = 0x00;

    G1_on();
    G2_on();
    G3_on();
}

void sched_fix_bgrt_proc_2(void)
{
    cli();
    proc[2].flags &= ~BGRT_PROC_FLG_RT;
    proc[2].flags &= BGRT_PROC_STATE_CLEAR_MASK;
    sei();
}

void blink_1(void)
{
    PORTB ^= 0x10;
}
void blink_2(void)
{
    PORTB ^= 0x08;
}
void blink_3(void)
{
    PORTB ^= 0x04;
}
void blink_4(void)
{
    PORTB ^= 0x02;
}
void blink_5(void)
{
    PORTB ^= 0x01;
}
void blink_6(void)
{
    PORTD ^= 0x80;
}

static void blink_digit(bgrt_cnt_t digit)
{
    PORTB &= ~0x20;
    _delay_ms(200);
    if (!digit)
    {
        PORTB |= 0x20;
        _delay_ms(500);
        PORTB &= ~0x20;
        return;
    }
    while (digit--)
    {
        PORTB |= 0x20;
        _delay_ms(200);
        PORTB &= ~0x20;
        _delay_ms(200);
    }
}
// Can blink numbers from 0 up to 99.
static void blink_num(bgrt_cnt_t num)
{
    PORTB &= ~0x20;
    PORTD &= ~0x40;
    PORTD |= 0x20;
    blink_digit((num/100)%10); // Most significant digit
    _delay_ms(300);
    blink_digit((num/10)%10);
    _delay_ms(300);
    blink_digit(num%10); //Least significant digit

}
void test_output(bgrt_bool_t test_result, bgrt_cnt_t test_num)
{
    // If test has failed, then where will be abnormal program termination!
    if (!test_result)
    {
        cli();
        while (1)
        {
            _delay_ms(1000);
            blink_num(test_num);
        }
    }
}
void test_start(void)
{
    PORTD |= 0x40;
}
void tests_end(void)
{
    cli();
    while (1)
    {
        PORTD |= 0x40;
        _delay_ms(500);
        PORTD &= ~0x40;
        _delay_ms(500);
    }
}

unsigned char test_var_sig;
void test_clear(void)
{
    cli();
    test_var_sig = 0;
    sei();
}
void test_inc(void)
{
    cli();
    test_var_sig++;
    sei();
}

void show_nested_int(void)
{
//#ifdef BGRT_CONFIG_PREEMPTIVE_KERNEL
//    PORTC |= 0x1f;
//    switch (nested_interrupts)
//    {
//        case 0:
//            PORTC &= ~0x10;
//        case 1:
//            PORTC &= ~0x08;
//        case 2:
//            PORTC &= ~0x04;
//        case 3:
//            PORTC &= ~0x02;
//        case 4:
//            PORTC &= ~0x01;
//        default:
//            break;
//    }
//#endif //BGRT_CONFIG_PREEMPTIVE_KERNEL
}
void systick_hook(void)
{
    show_nested_int();
    PORTD ^= 0x04;
}

//BGRT_ISR(INT0_vect)
//{
//    show_nested_int();
//}

void test_do_nothing(void)
{
    NOP();
}

extern bgrt_proc_t proc[6];
const struct bgrt_priv_proc_t * proc_base = proc;
