#ifndef _BGRT_PORT_H_
#define _BGRT_PORT_H_

#define BGRT_KBLOCK bgrt_kernel.kblock
#define BGRT_CURR_PROC bgrt_kernel.kblock.sched.current_proc

// Пролог обработчика прерывания
#define BGRT_ISR_START()     \
    bgrt_disable_interrupts()

// Эпилог обработчика прерывания
#define BGRT_ISR_END()                \
    BGRT_SYS_ICSR |= BGRT_PENDSV_SET; \
    bgrt_enable_interrupts()

// Шаблон обработчика прерывания для внутреннего пользования
#define _BGRT_ISR(v,f) \
void v(void)           \
{                      \
    BGRT_ISR_START();  \
    f();               \
    BGRT_ISR_END();    \
}

/*
Объявление обработчика прерывания.

Обработка прерываний происходит в контексте main,
он же контекст процесса холостого хода.

Не очень быстро,
зато память экономится.
*/
#define BGRT_ISR(v)               \
void BGRT_CONCAT(v,_func)(void);  \
_BGRT_ISR(v,BGRT_CONCAT(v,_func)) \
void BGRT_CONCAT(v,_func)(void)

#endif //_BGRT_PORT_H_
