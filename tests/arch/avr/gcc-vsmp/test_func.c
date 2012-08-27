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
    proc[2].flags &= ~(PROC_FLG_RT|PROC_FLG_WD_STOP);
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
        PORTB ^= 0x10;
    }
    else
    {
        PORTC ^= 0x10;
    }
    sei();
}
void blink_2(void)
{
    cli();
    if(current_vm)
    {
        PORTB ^= 0x08;
    }
    else
    {
        PORTC ^= 0x08;
    }
    sei();
}
void blink_3(void)
{
    cli();
    if(current_vm)
    {
        PORTB ^= 0x04;
    }
    else
    {
        PORTC ^= 0x04;
    }
    sei();
}
void blink_4(void)
{
    cli();
    if(current_vm)
    {
        PORTB ^= 0x02;
    }
    else
    {
        PORTC ^= 0x02;
    }
    sei();
}
void blink_5(void)
{
    cli();
    if(current_vm)
    {
        PORTB ^= 0x01;
    }
    else
    {
        PORTC ^= 0x01;
    }
    sei();
}
void blink_6(void)
{
    cli();
    if(current_vm)
    {
        PORTD ^= 0x80;
    }
    else
    {
        PORTB ^= 0x20;
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
