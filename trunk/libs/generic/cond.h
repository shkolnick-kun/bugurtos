#ifndef _COND_H_
#define _COND_H_

#include <bugurt.h>
#include "mutex.h"

typedef struct _cond_t cond_t;
struct _cond_t
{
    sync_t wait;/*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
    count_t blocked; /*!< \~russian Счетчик ожидающих процессов. \~english A list of blocked processes. */
};

void cond_init_isr( cond_t * cond );
void cond_init( cond_t * cond );
flag_t cond_wait(  cond_t * cond, mutex_t * mutex );
flag_t cond_signal( cond_t * cond );
flag_t cond_broadcast( cond_t * cond );

#endif // _COND_H_
