#include <test_func.h>

void init_hardware(void)
{
    vsmp_init();

    TCCR2A = 0x02;//
    TCCR2B = 0x05;// prescaler=128
    OCR2A  = 124;
    OCR2B  = 0x00;
    TIMSK2 = 0x02;
    TIFR2  = 0x00;

    DDRB = 0x3F;
    PORTB = 0x00;
    DDRC = 0x3F;
    PORTC = 0x00;
    DDRD = 0xFE;
    PORTD = 0x00;

    vsmp_run();
}

void sched_fix_proc_2(void)
{
    cli();
    proc[2].flags &= ~PROC_FLG_RT;
    proc[2].flags &= PROC_STATE_CLEAR_MASK;
    sei();
}

void sched_lb_test_start(void)
{
    cli();
    proc[0].affinity = 0x3;

    proc[2].affinity = 0x3;
    proc[3].affinity = 0x3;
    proc[4].affinity = 0x3;
    proc[5].affinity = 0x3;
    sei();
}

void sched_systick_hook_add(void)
{
    cli();
    kernel.timer_tick = load_bar_graph;
    sei();
}

void blink_1(void)
{
    cli();
    if(current_vm)
    {
        PORTC ^= 0x10;
    }
    else
    {
        PORTB ^= 0x10;
    }
    sei();
}
void blink_2(void)
{
    cli();
    if(current_vm)
    {
        PORTC ^= 0x08;
    }
    else
    {
        PORTB ^= 0x08;
    }
    sei();
}
void blink_3(void)
{
    cli();
    if(current_vm)
    {
        PORTC ^= 0x04;
    }
    else
    {
        PORTB ^= 0x04;
    }
    sei();
}
void blink_4(void)
{
    cli();
    if(current_vm)
    {
        PORTC ^= 0x02;
    }
    else
    {
        PORTB ^= 0x02;
    }
    sei();
}
void blink_5(void)
{
    cli();
    if(current_vm)
    {
        PORTC ^= 0x01;
    }
    else
    {
        PORTB ^= 0x01;
    }
    sei();
}
void blink_6(void)
{
    cli();
    if(current_vm)
    {
        PORTB ^= 0x20;
    }
    else
    {
        PORTD ^= 0x80;
    }
    sei();
}

void load_bar_graph(void)
{
    cli();
    PORTB |= 0x3f;
    PORTC |= 0x1f;
    PORTD |= 0x80;
    switch(kernel.stat[0])
    {

        case 1:
            PORTB &= ~0x10;
        case 2:
            PORTB &= ~0x08;
        case 3:
            PORTB &= ~0x04;
        case 4:
            PORTB &= ~0x02;
        case 5:
            PORTB &= ~0x01;
        case 6:
            PORTD &= ~0x80;
        default:
            break;
    }
    switch(kernel.stat[1])
    {
        case 1:
            PORTC &= ~0x10;
        case 2:
            PORTC &= ~0x08;
        case 3:
            PORTC &= ~0x04;
        case 4:
            PORTC &= ~0x02;
        case 5:
            PORTC &= ~0x01;
        case 6:
            PORTB &= ~0x20;
        default:
            break;
    }
    sei();
}

static void blink_digit( count_t digit )
{
    PORTB &= ~0x20;
    _delay_ms(200);
    while(digit--)
    {
        PORTB |= 0x20;
        _delay_ms(200);
        PORTB &= ~0x20;
        _delay_ms(200);
    }
}
// Can blink numbers from 0 up to 99.
static void blink_num( count_t num )
{
    PORTB &= ~0x20;
    PORTD &= ~0x40;
    PORTD |= 0x20;
    blink_digit( (num/100)%10 ); // Most significant digit
    _delay_ms(300);
    blink_digit( (num/10)%10 );
    _delay_ms(300);
    blink_digit( num%10 ); //Least significant digit

}
void test_output( bool_t test_result, count_t test_num )
{
    // If test has failed, then where will be abnormal program termination!
    if( !test_result )
    {
        cli();
        while(1)
        {
            _delay_ms(500);
            blink_num( test_num );
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
    while(1)
    {
        PORTD |= 0x40;
        _delay_ms(500);
        PORTD &= ~0x40;
        _delay_ms(500);
    }
}

void test_do_nothing(void)
{
    NOP();
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
