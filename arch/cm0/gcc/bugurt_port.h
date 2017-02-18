#ifndef _BGRT_PORT_H_
#define _BGRT_PORT_H_

#define BGRT_INT_LOCK()    \
    __asm__ __volatile__ ( \
        "dsb     \n\t"     \
        "cpsid i \n\t"     \
        :::                \
        )

#define BGRT_INT_FREE()    \
    __asm__ __volatile__ ( \
        "dsb     \n\t"     \
        "cpsie i \n\t"     \
        "isb     \n\t"     \
        :::                \
        )

#define BGRT_ATM_INIT_ISR(map_ptr) do{*(map_ptr) = (bgrt_map_t)0;}while(0)

static inline void bgrt_atm_init(bgrt_map_t * fic) /* ADLINT:SL:[W0629] linkage*/
{
    BGRT_INT_LOCK();
    BGRT_ATM_INIT_ISR(fic);
    BGRT_INT_FREE();
}

#define BGRT_ATM_BSET_ISR(map_ptr, msk) do{ *(map_ptr) |= (msk); }while(0)

static inline void bgrt_atm_bset(bgrt_map_t * fic, bgrt_map_t msk) /* ADLINT:SL:[W0629] linkage*/
{
    BGRT_INT_LOCK();
    BGRT_ATM_BSET_ISR(fic,msk);
    BGRT_INT_FREE();
}

#define BGRT_ATM_BGET_ISR(map_ptr, msk) (*(map_ptr) & (msk))

static inline bgrt_map_t bgrt_atm_bget(bgrt_map_t * fic, bgrt_map_t msk) /* ADLINT:SL:[W0629] linkage*/
{
    bgrt_map_t ret;
    BGRT_INT_LOCK();
    ret = BGRT_ATM_BGET_ISR(fic,msk);
    BGRT_INT_FREE();
    return ret; /* ADLINT:SL:[W0256,W0268] ret type check fail*/
}

#define BGRT_ATM_BCLR_ISR(map_ptr, msk) (__bgrt_atm_bclr_isr((map_ptr), (msk)))
static inline bgrt_map_t __bgrt_atm_bclr_isr(bgrt_map_t * fic, bgrt_map_t msk)
{
    bgrt_map_t ret;
    //Get states
    ret = *fic & msk; /* ADLINT:SL:[W0422,W0165] NULL ptr deref*/
    //Clear states
    *fic &= ~msk;     /* ADLINT:SL:[W0422,W0165,W0578] NULL ptr deref*/
    return ret;           /* ADLINT:SL:[W0256,W0268] ret type check fail*/
}

static inline bgrt_map_t bgrt_atm_bclr(bgrt_map_t * fic, bgrt_map_t msk) /* ADLINT:SL:[W0629] linkage*/
{
    bgrt_map_t ret;
    BGRT_INT_LOCK();
    ret = BGRT_ATM_BCLR_ISR(fic,msk);
    BGRT_INT_FREE();
    return ret;         /* ADLINT:SL:[W0256,W0268] ret type check fail*/
}

#define BGRT_VINT_PUSH_ISR    bgrt_vint_push
#define BGRT_FIC_PUSH_INT_ISR bgrt_atm_bset

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
