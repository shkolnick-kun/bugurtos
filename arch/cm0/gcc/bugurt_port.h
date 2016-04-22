#ifndef _BUGURT_PORT_H_
#define _BUGURT_PORT_H_

#define BUGURT_CONCAT(a,b) a##b

#define BGRT_KBLOCK bgrt_kernel.kblock
#define BGRT_CURR_PROC bgrt_kernel.kblock.sched.current_proc

// Пролог обработчика прерывания
#define BUGURT_ISR_START() \
    bgrt_disable_interrupts()

// Эпилог обработчика прерывания
#define BUGURT_ISR_END() \
    BUGURT_SYS_ICSR |= BUGURT_PENDSV_SET; \
    bgrt_enable_interrupts()

// Шаблон обработчика прерывания для внутреннего пользования
#define _BUGURT_ISR(v,f) \
__attribute__ (( naked )) void v(void); \
void v(void) \
{ \
    BUGURT_ISR_START();\
    f();\
    BUGURT_ISR_END();\
}


/*
Объявление обработчика прерывания.

Обработка прерываний происходит в контексте main,
он же контекст процесса холостого хода.

Не очень быстро,
зато память экономится.
*/
#define BUGURT_INTERRUPT(v) \
void BUGURT_CONCAT(v,_func)(void);\
_BUGURT_ISR(v,BUGURT_CONCAT(v,_func)) \
void BUGURT_CONCAT(v,_func)(void)

#endif //_BUGURT_PORT_H_
