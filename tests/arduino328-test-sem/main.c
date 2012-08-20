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
void blink_4(void * t) {
    PORTB ^= 0x02;
    }
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
stack_t stack[5][128];

sem_t sem;

void main0(void * t)
{
    wait_time(1000);
    while(1)
    {
        sem_lock(&sem);
        wait_time(100);
        sem_unlock(&sem);
        proc_flag_stop(PROC_FLG_SEM);
    }
}
void main1(void * t)
{
    wait_time(1000);
    while(1)
    {
        sem_lock(&sem);
        wait_time(100);
        sem_unlock(&sem);
        proc_flag_stop(PROC_FLG_SEM);
    }
}
void main2(void * t)
{
    while(1)
    {
        sem_lock(&sem);
        proc_reset_watchdog();
        proc_self_stop();
        sem_unlock(&sem);
        proc_flag_stop(PROC_FLG_SEM);
    }
}
void main3(void * t)
{
    wait_time(500);
    if(sem_try_lock(&sem))
    {
        blink_10(0);
        wait_time(250);
        if(sem_try_lock(&sem))
        {
            blink_11(0);
            wait_time(100);
            blink_11(0);
        }
        sem_unlock(&sem);
        proc_flag_stop(PROC_FLG_SEM);
        blink_10(0);
    }
    while(1)
    {
        for(unsigned char i=0;i<10;i++);
    }
}
void idle_main(void * t)
{
    wait_time(1000);
    // Insert code
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
    G3_on();

    proc_init_isr(&proc[0], main0, blink_1, blink_1, 0, &stack[0][127], 1, 2, 0);
    proc_init_isr(&proc[1], main1, blink_2, blink_2, 0, &stack[1][127], 2, 3, 0);
    proc_init_isr(&proc[2], main2, blink_3, blink_3, 0, &stack[2][127], 2, 4, 1);// Типа реального времени
    proc_init_isr(&proc[3], main3, blink_4, blink_4, 0, &stack[3][127], 3, 4, 0);

    kernel.idle.rs_hook = blink_12;
    kernel.idle.sv_hook = blink_12;

    proc_run_isr(&proc[0]);
    proc_run_isr(&proc[1]);
    proc_run_isr(&proc[3]);

    sem_init_isr(&sem,1);

    start_bugurt();
    return 0;
}