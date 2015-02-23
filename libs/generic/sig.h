#ifndef _SIG_H_
#define _SIG_H_

#include <bugurt.h>
#include <cond.h>

typedef struct _sig_t sig_t;
struct _sig_t
{
    cond_t wakeup; /*!< \~russian Список процессов для пробуждения. \~english Wakeup process list. */
    mutex_t wait;  /*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
};

void sig_init( sig_t * sig );
void sig_init_isr( sig_t * sig );
flag_t sig_wait( sig_t * sig );
flag_t sig_signal( sig_t * sig );
count_t sig_broadcast( sig_t * sig );

#endif // _SIG_H_
