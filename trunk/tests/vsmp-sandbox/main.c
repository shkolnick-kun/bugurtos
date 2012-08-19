/*
 */

#include "../../arch/avr/gcc-vsmp/vsmp.h"

proc_t proc[6];
stack_t proc_stack[6][128];

void main0(void * t)
{
    while(1)
    {
        wait_time(10);
    }
}

void main1(void * t)
{
    while(1)
    {
        wait_time(10);
    }
}

void main2(void * t)
{
    while(1)
    {
        wait_time(3);
        proc_reset_watchdog();
        proc_self_stop();
    }
}
void main3(void * t)
{
    while(1)
    {
        wait_time(50);
        proc_run(&proc[2]);
    }
}
void main4(void * t)
{
    while(1)
    {
        wait_time(10);
    }
}
void main5(void * t)
{
    wait_time(50);
}
void idle_main(void * arg)
{
    proc_run(&proc[0]);
    proc_run(&proc[1]);
    proc_run(&proc[2]);
    proc_run(&proc[3]);
    proc_run(&proc[4]);
    proc_run(&proc[5]);

    wait_time(15);

    cli();
    proc[0].affinity = 0x3;
    proc[1].affinity = 0x3;
    proc[2].affinity = 0x3;
    proc[3].affinity = 0x3;
    proc[4].affinity = 0x3;
    proc[5].affinity = 0x3;
    sei();

    while(1){
        wait_time(10);
        proc_lazy_global_load_balancer();
    }
}

/*
void test_visr(void)
{
    PORTB^=0x10;
}
void test_visr3(void)
{
    PORTB^=0x10;
}
vinterrupt_t test_vector3 = VINTERRUPT_INIT(test_vector3,test_visr3);
void test_visr2(void)
{
    core_id_t core;
    core = current_core();
    PORTB^=0x10;
    vsmp_vinterrupt_isr( core, &test_vector3 ); // nested interrupt
    enable_interrupts();
}
vinterrupt_t test_vector = VINTERRUPT_INIT(test_vector,test_visr);
vinterrupt_t test_vector2 = VINTERRUPT_INIT(test_vector2,test_visr2);

core_id_t i;
unsigned short j;
//*/
int main(void)
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
/*
    for(i=0; i<MAX_CORES; i++)
    {
        cli();
        vsmp_vinterrupt_isr( i, &test_vector );
        vsmp_vinterrupt( i, &test_vector2 );
        for(j=0;j<1000;j++);
    }
    for(i=0; i<MAX_CORES; i++)
    {
        cli();
        vsmp_vinterrupt_isr( i, &test_vector );
        vsmp_vinterrupt( i, &test_vector2 );
        for(j=0;j<1000;j++);
    }
    //*/
    init_bugurt();

    proc_init_isr(&proc[0], main0, 0, 0, 0, &proc_stack[0][127], 1, 2, 0, 0x1);
    proc_init_isr(&proc[1], main1, 0, 0, 0, &proc_stack[1][127], 2, 3, 0, 0x1);
    proc_init_isr(&proc[2], main2, 0, 0, 0, &proc_stack[2][127], 2, 4, 0, 0x1);
    proc_init_isr(&proc[3], main3, 0, 0, 0, &proc_stack[3][127], 1, 2, 0, 0x1);
    proc_init_isr(&proc[4], main4, 0, 0, 0, &proc_stack[4][127], 2, 2, 0, 0x1);
    proc_init_isr(&proc[5], main5, 0, 0, 0, &proc_stack[5][127], 2, 2, 0, 0x1);

    start_bugurt();

    return 0;
}
