#include"../../../include/bugurt.h"

#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
#define BGRT_INT_PTR unsigned long
#else
#define BGRT_INT_PTR unsigned short
#endif

stack_t * proc_stack_init( stack_t * stack_top, code_t code, void * arg){
     // return address (func)
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)code) & 0xFF);
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)code>>8)& 0xFF);
#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)code>>16)& 0xFF);
#else
     *stack_top-- = 0x00;
#endif
     // Y
     *stack_top-- = 0xAD;
     *stack_top-- = 0xDE;

#if (__DATA_MODEL__==__LARGE_DATA_MODEL__)
     *stack_top-- = 0xAF;
     *stack_top-- = 0xBE;
#else // __SMALL_DATA_MODEL__ or __MEDIUM_DATA_MODEL__
     // X - 1st argument is placed in X
     *stack_top-- = (stack_t)((unsigned short)arg & 0xFF);
     *stack_top-- = (stack_t)(((unsigned short)arg>>8)& 0xFF);
#endif
     // A
     *stack_top-- = 0xAA;
     // CCR
     *stack_top-- = 0x20; //Interrupts are enabled
     // b0...b7
     // Compiler saves them in order: b3,b2,b1,b0 ,b7,b6,b5,b4, sort of optimization I think.
#if (__DATA_MODEL__==__LARGE_DATA_MODEL__)
     *stack_top-- = (stack_t)((BGRT_INT_PTR)arg & 0xFF);
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)arg>>8)& 0xFF);
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)arg>>16)& 0xFF);
#else // __SMALL_DATA_MODEL__ or __MEDIUM_DATA_MODEL__
     *stack_top-- = 0xB3;
     *stack_top-- = 0xB2;
     *stack_top-- = 0xB1;
#endif
     *stack_top-- = 0xB0;
     // b4...b7
     *stack_top-- = 0xB7;
     *stack_top-- = 0xB6;
     *stack_top-- = 0xB5;
     *stack_top-- = 0xB4;
     // b8...b11
     *stack_top-- = 0xBB;
     *stack_top-- = 0xBA;
     *stack_top-- = 0xB9;
     *stack_top-- = 0xB8;
     //b12...b15
     *stack_top-- = 0xBF;
     *stack_top-- = 0xBE;
     *stack_top-- = 0xBD;
     *stack_top-- = 0xBC;

     return stack_top;
}
