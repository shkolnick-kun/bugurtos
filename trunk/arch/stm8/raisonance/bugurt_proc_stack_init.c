#include"../../../include/bugurt.h"

#if (__ROM_MODEL__ > 0)
#define BGRT_INT_PTR unsigned long
#else
#define BGRT_INT_PTR unsigned short
#endif

stack_t * proc_stack_init(
                            stack_t * stack_top,
                            code_t pmain,
                            void * arg
                         )
{
     // return address (func)
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)pmain) & 0xFF);
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)pmain>>8)& 0xFF);
#if (__ROM_MODEL__ > 0)
     *stack_top-- = (stack_t)(((BGRT_INT_PTR)pmain>>16)& 0xFF);
#else
     *stack_top-- = 0x00;
#endif
     // Y
     *stack_top-- = 0xAD;
     *stack_top-- = 0xDE;
     /** WARNING: LARGE RAM MODEL IS NOT SUPPORTED IN THIS CODE!!! */
     // X - 1st argument is placed in X
     *stack_top-- = (stack_t)((unsigned short)arg & 0xFF);
     *stack_top-- = (stack_t)(((unsigned short)arg>>8)& 0xFF);
     // A
     *stack_top-- = 0xAA;
     // CCR
     *stack_top-- = 0x20; //Interrupts are enabled
     // ?BH ?BL ?CH ?CL
     *stack_top-- = 0xC1;
     *stack_top-- = 0xC0;
     *stack_top-- = 0xB1;
     *stack_top-- = 0xB0;

     return stack_top;
}
