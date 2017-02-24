#ifndef _BGRT_PORT_H_
#define _BGRT_PORT_H_

#define BGRT_INT_LOCK()        \
    __asm__ __volatile__ (     \
        "mov r0, %0      \n\t" \
        "msr basepri, r0 \n\t" \
        "dsb             \n\t" \
        "isb             \n\t" \
        :                      \
        :"i" (BGRT_CONFIG_CRITSEC_PRIO << (8 - BGRT_CONFIG_PRIO_BITS)) \
        :"r0"                  \
        )

#define BGRT_INT_FREE()        \
    __asm__ __volatile__ (     \
        "mov r0, #0      \n\t" \
        "msr basepri, r0 \n\t" \
        "dsb             \n\t" \
        "isb             \n\t" \
        :                      \
        :                      \
        :"r0"                  \
        )

#define BGRT_ATM_INIT_ISR(map_ptr) do{*(map_ptr) = (bgrt_map_t)0;}while(0)

static inline void bgrt_atm_init(bgrt_map_t * fic) /* ADLINT:SL:[W0629] linkage*/
{
    BGRT_INT_LOCK();
    BGRT_ATM_INIT_ISR(fic);
    BGRT_INT_FREE();
}

#define BGRT_ATM_BSET_ISR(map_ptr, msk) __atomic_fetch_or((map_ptr), (msk), __ATOMIC_SEQ_CST)

static inline void bgrt_atm_bset(bgrt_map_t * fic, bgrt_map_t msk)
{
    BGRT_ATM_BSET_ISR(fic,msk);
}

#define BGRT_ATM_BGET_ISR(map_ptr, msk) (*(map_ptr) & (msk))

static inline bgrt_map_t bgrt_atm_bget(bgrt_map_t * fic, bgrt_map_t msk)
{
    return BGRT_ATM_BGET_ISR(fic,msk);
}

#define BGRT_ATM_BCLR_ISR(map_ptr, msk) ((msk) & __atomic_fetch_and((map_ptr), ~(msk), __ATOMIC_SEQ_CST))

static inline bgrt_map_t bgrt_atm_bclr(bgrt_map_t * fic, bgrt_map_t msk)
{
    return BGRT_ATM_BCLR_ISR(fic,msk);
}

#define BGRT_VINT_PUSH_ISR    bgrt_vint_push

#define BGRT_KBLOCK bgrt_kernel.kblock
#define BGRT_CURR_PROC bgrt_kernel.kblock.sched.current_proc

// Пролог обработчика прерывания
#define BGRT_ISR_START() do{}while(0)

// Эпилог обработчика прерывания
#define BGRT_ISR_END()                    \
    do{                                   \
        BGRT_SYS_ICSR |= BGRT_PENDSV_SET; \
    }while(0)

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
