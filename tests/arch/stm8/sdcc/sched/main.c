#include <libstm8/stm8l.h>
#include <stdint.h>

#define BGRT_INT_PTR unsigned short
typedef uint8_t bgrt_stack_t;
typedef void (*bgrt_code_t)(void*);

bgrt_stack_t * bgrt_proc_stack_init(
    bgrt_stack_t * bgrt_stack_top,
    bgrt_code_t pmain,
    void * arg,
    void (*return_address)(void)
)
{
    /* main arg */
    *bgrt_stack_top-- = (bgrt_stack_t)((unsigned short)arg & 0xFF);
    *bgrt_stack_top-- = (bgrt_stack_t)(((unsigned short)arg>>8)& 0xFF);
    /* return address (func) */
    *bgrt_stack_top-- = (bgrt_stack_t)(((BGRT_INT_PTR)return_address) & 0xFF);
    *bgrt_stack_top-- = (bgrt_stack_t)(((BGRT_INT_PTR)return_address>>8)& 0xFF);
    /* process main */
    *bgrt_stack_top-- = (bgrt_stack_t)(((BGRT_INT_PTR)pmain) & 0xFF);
    *bgrt_stack_top-- = (bgrt_stack_t)(((BGRT_INT_PTR)pmain>>8)& 0xFF);
    *bgrt_stack_top-- = 0x00;
    /* Y */
    *bgrt_stack_top-- = 0xAD;
    *bgrt_stack_top-- = 0xDE;
    /** WARNING: LARGE RAM MODEL IS NOT SUPPORTED IN THIS CODE!!! */
    /* X - 1st argument is placed in X */
    *bgrt_stack_top-- = 0xBE;
    *bgrt_stack_top-- = 0xAF;
    /* A */
    *bgrt_stack_top-- = 0xAA;
    /* CCR */
    *bgrt_stack_top-- = 0x20; /* Interrupts are enabled */
    //Dummy bytes, as after bgrt_isr_epilogue [addw sp, #2] is done
    *bgrt_stack_top-- = 0xFF;
    *bgrt_stack_top-- = 0xFF;
    return bgrt_stack_top;
}
static bgrt_stack_t * bgrt_isr_prologue(void) __naked
{
    __asm
    ldw X, SP
    ret
    __endasm;
}

static void bgrt_isr_epilogue(bgrt_stack_t * val) __naked
{
    (void)val;
    __asm
    ldw   X, (0x03, SP) /*Get new SP value   */
    popw  Y             /*pop return address */
    ldw   SP, X         /*Set SP             */
    pushw Y             /*push return address*/
    ret                 /*return             */
    __endasm;
}

static bgrt_stack_t * save_sp = (void *)0;

static bgrt_stack_t * main_sp = (void *)0;
static bgrt_stack_t * thread_sp = (void *)0;

static bgrt_stack_t ** restore_sp = &main_sp;

static void my_sched(void)
{
    *restore_sp = save_sp;
    if (&main_sp == restore_sp)
    {
        restore_sp = &thread_sp;
    }
    else
    {
        restore_sp = &main_sp;
    }
    save_sp = *restore_sp;
}

static void my_trap(void) __trap __naked
{
    save_sp = bgrt_isr_prologue();
    my_sched();
    bgrt_isr_epilogue(save_sp);
    __asm__("iret");
}

bgrt_stack_t thread_stack[128];

uint16_t d_thr = 0;

static void thread(void * arg)
{
    d_thr = (int)(arg);
}

static void thread_end(void)
{
    int d;
    while (1)
    {
        GPIOE_ODR &= ~0x80;
        for (d = 0; d < d_thr; d++) { }
        __asm__("trap");
    }
}

int main()
{
    int d;
    // Configure pins
    GPIOE_DDR = 0x80;
    GPIOE_CR1 = 0x80;
    GPIOE_ODR &= ~0x80;

    thread_sp = bgrt_proc_stack_init(&thread_stack[127], thread, (void *)30000, thread_end);
    // Loop
    do
    {
        GPIOE_ODR |= 0x80;
        for (d = 0; d < 15000; d++) { }
        __asm__("trap");
    }
    while (1);
}
