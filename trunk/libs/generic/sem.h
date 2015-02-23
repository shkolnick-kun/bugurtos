#ifndef _SEM_H_
#define _SEM_H_

#include <bugurt.h>

typedef struct _sem_t sem_t;
struct _sem_t
{
    sync_t wait;/*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
    count_t counter;/*!< \~russian Счетчик реусрсов. \~english A resource counter. */
    count_t blocked;/*!< \~russian Счетчик блокированных процессов. \~english A blocked process counter. */
#ifdef CONFIG_MP
    lock_t lock;/*!< \~russian Спин-блокировка. \~english A sync spin-lock. */
#endif // CONFIG_MP
};

void sem_init( sem_t * sem, count_t count );
void sem_init_isr( sem_t * sem, count_t count );
flag_t sem_try_lock( sem_t * sem );
flag_t sem_lock( sem_t * sem );
flag_t sem_free( sem_t * sem );

#endif // _SEM_H_
