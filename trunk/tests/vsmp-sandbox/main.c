/*
 */

#include "../../arch/avr/gcc-vsmp/vsmp.h"

stack_t * vm_main_sp;
stack_t vm_stack[128];

__attribute__ (( naked )) void vm_interrupt(void)
{
    PORTB ^= 0x40;
    bugurt_pop_context();
    __asm__ __volatile__("ret"::);
}

void vm_main(void)
{
    PORTB ^= 0x20;
    while(1)
    {
        PORTB ^= 0x20;
        PORTB ^= 0x40;
    }
}

int main(void)
{

    vm_main_sp = proc_stack_init( &vm_stack[127], (code_t)vm_main, (void *)0 );

    /// Работает !!! Можно делать BuguRTThreads !!!
    bugurt_set_stack_pointer(vm_main_sp);
    bugurt_push_pointer( (void *)vm_interrupt );
    __asm__ __volatile__("ret"::);
    /// Работает !!! Можно делать BuguRTThreads !!!
    while(1)
    ;

    return 0;
}
