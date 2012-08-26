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
    sei();
}
