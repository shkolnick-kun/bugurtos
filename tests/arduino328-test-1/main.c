/*
 */
#include <bugurt.h>

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

///----------------------------------------------------------------------------------------
void blink_1(void * t) {PORTB ^= 0x10;}
void blink_2(void * t) {PORTB ^= 0x08;}
void blink_3(void * t) {PORTB ^= 0x04;}
void blink_4(void * t) {PORTB ^= 0x02;}
void blink_5(void * t) {PORTB ^= 0x01;}
void blink_6(void * t) {PORTD ^= 0x80;}
void blink_7(void * t) {PORTC ^= 0x10;}
void blink_8(void * t) {PORTC ^= 0x08;}
void blink_9(void * t) {PORTC ^= 0x04;}
void blink_10(void * t) {PORTC ^= 0x02;}
void blink_11(void * t) {PORTC ^= 0x01;}
void blink_12(void * t) {
    PORTB ^= 0x20;
    blink_G3();
    blink_R3();
    }
///----------------------------------------------------------------------------------------

proc_t proc[4];
stack_t stack[4][128];

void main0(void * t)
{
    while(1)
    {
        wait_time(50);
    }
}
void main1(void * t)
{
    while(1)
    {
        wait_time(500);
    }
}
void main2(void * t)
{
    while(1)
    {
        wait_time(1);
        proc_reset_watchdog();
        proc_self_stop();
    }
}
void main3(void * t)
{
    wait_time(500);
}
void idle_main(void * t)
{
    // Insert code
    proc_init(&proc[3], main3, blink_4, blink_4, 0, &stack[3][127], 3, 4, 0);
    proc_run( &proc[3] );
    wait_time(1000);
    proc_run( &proc[3] );
    wait_time(1000);
    proc_restart( &proc[3] );
    wait_time(500);
    proc_run( &proc[3] );
    while(1)
    {
         wait_time(1000);
         proc_run(&proc[2]);
    }
}

int main(void)
{
    init_bugurt();

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
    R3_on();

    proc_init_isr(&proc[0], main0, blink_1, blink_1, 0, &stack[0][127], 1, 2, 0);
    proc_init_isr(&proc[1], main1, blink_2, blink_2, 0, &stack[1][127], 2, 3, 0);
    proc_init_isr(&proc[2], main2, blink_3, blink_3, 0, &stack[2][127], 2, 4, 1);// Типа реального времени
    //proc_init_isr(&proc[3], main3, blink_4, blink_4, 0, &stack[3][127], 3, 4, 0);

    kernel.idle.rs_hook = blink_12;
    kernel.idle.sv_hook = blink_12;

    proc_run_isr(&proc[0]);
    proc_run_isr(&proc[1]);
    proc_run_isr(&proc[2]);
    //proc_run_isr(&proc[3]);

    start_bugurt();
    return 0;
}
