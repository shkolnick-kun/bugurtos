/*
 */

#include "../../arch/avr/gcc-vsmp/vsmp.h"

void test_visr(void)
{
    PORTB^=0x10;
}
void test_visr2(void)
{
    PORTB^=0x10;
}
vinterrupt_t test_vector = VINTERRUPT_INIT(test_vector,test_visr);
vinterrupt_t test_vector2 = VINTERRUPT_INIT(test_vector2,test_visr2);
core_id_t i;
unsigned short j;

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

    for(i=0; i<MAX_CORES; i++)
    {
        cli();
        vsmp_vinterrupt_isr( i, &test_vector );
        vsmp_vinterrupt( i, &test_vector2 );
        for(j=0;j<1000;j++);
    }

    while(1)
    {
        PORTB ^= 0x20;
    }

    return 0;
}
