#ifndef BGRT_PORT_H
#define BGRT_PORT_H

extern void BGRT_INT_LOCK(void);
extern void BGRT_INT_FREE(void);

extern void BGRT_ATM_INIT_ISR(bgrt_map_t * fic);
extern void bgrt_atm_init(bgrt_map_t * fic);
extern void BGRT_ATM_BSET_ISR(bgrt_map_t * fic, bgrt_map_t msk);
extern void bgrt_atm_bset(bgrt_map_t * fic, bgrt_map_t msk);
extern bgrt_map_t BGRT_ATM_BGET_ISR(bgrt_map_t * fic, bgrt_map_t msk);
extern bgrt_map_t bgrt_atm_bget(bgrt_map_t * fic, bgrt_map_t msk);
extern bgrt_map_t BGRT_ATM_BCLR_ISR(bgrt_map_t * fic, bgrt_map_t msk);
extern bgrt_map_t bgrt_atm_bclr(bgrt_map_t * fic, bgrt_map_t msk);

#endif /*BGRT_PORT_H*/
