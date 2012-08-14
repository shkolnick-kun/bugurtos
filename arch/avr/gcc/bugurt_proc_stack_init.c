#include"../../../include/bugurt.h"
stack_t * proc_stack_init(stack_t * sstart, code_t code, void * arg)
{
    stack_t * tos = (stack_t *)sstart;
    // return address
    unsigned short tmp = (unsigned short)code;
    *tos-- = (stack_t)(tmp&(unsigned short)0x00ff);
    tmp>>=8;
    *tos-- = (stack_t)(tmp&(unsigned short)0x00ff);

    // s
    *tos-- = 0x00;
    *tos-- = 0x00;// r1 must B 0
    *tos-- = 0x02;// r2
    *tos-- = 0x80;// SREG: enable interrupts
    *tos-- = 0x03;
    *tos-- = 0x04;
    *tos-- = 0x05;
    *tos-- = 0x06;
    *tos-- = 0x07;
    *tos-- = 0x08;
    *tos-- = 0x09;
    *tos-- = 0x10;
    *tos-- = 0x11;
    *tos-- = 0x12;
    *tos-- = 0x13;
    *tos-- = 0x14;
    *tos-- = 0x15;
    *tos-- = 0x16;
    *tos-- = 0x17;
    *tos-- = 0x18;
    *tos-- = 0x19;
    *tos-- = 0x20;
    *tos-- = 0x21;
    *tos-- = 0x22;
    *tos-- = 0x23;

    tmp = (unsigned short)arg;
    *tos-- = (stack_t)(tmp&(unsigned short)0x00ff); // r24 LSByte of arg
    tmp>>=8;
    *tos-- = (stack_t)(tmp&(unsigned short)0x00ff); // r25 MSByte of arg

    *tos-- = 0x26;
    *tos-- = 0x27;
    *tos-- = 0x28;
    *tos-- = 0x29;
    *tos-- = 0x30;
    *tos-- = 0x31;
#ifdef RAMPZ
    *tos-- = 0xff;
#endif
    return tos;
}
