#include <test_func.h>

void raise_syscall_interrupt(void)
{
    R2_on();
    G2_off();
    R2_off();
    G2_on();
}

void start_scheduler( void )
{
    TIMSK2 |= 0x02;
}

void stop_scheduler( void )
{
    TIMSK2 &= ~0x02;
}

void init_hardware(void)
{
    cli();
    TCCR2A = 0x02;//
    TCCR2B = 0x05;// prescaler=128
    OCR2A  = 124;
    OCR2B  = 0x00;
    TIMSK2 = 0x00; // shceduler not started
    TIFR2  = 0x00;

    EICRA = 0x08; //falling edge
    EIMSK = 0x02; //resched generates int1, mask 0x02
    EIFR  |= 0x02;

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

void sched_fix_proc_2(void)
{
    cli();
    proc[2].flags &= ~(PROC_FLG_RT|PROC_FLG_WD_STOP);
    sei();
}
