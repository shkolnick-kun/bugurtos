#ifndef _MUTEX_H_
#define _MUTEX_H_

#include <bugurt.h>

typedef struct _mutex_t mutex_t;
struct _mutex_t
{
    sync_t wait;/*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
};

void mutex_init( mutex_t * mutex, prio_t prio );
void mutex_init_isr( mutex_t * mutex, prio_t prio );
flag_t mutex_try_lock( mutex_t * mutex );
flag_t mutex_lock( mutex_t * mutex );
flag_t mutex_free( mutex_t * mutex );

#endif // _MUTEX_H_
