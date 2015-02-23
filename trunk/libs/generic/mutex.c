#include "mutex.h"

void mutex_init_isr( mutex_t * mutex, prio_t prio )
{
    SYNC_INIT_ISR( mutex, prio );
}

void mutex_init( mutex_t * mutex, prio_t prio )
{
    disable_interrupts();
    mutex_init_isr( mutex, prio );
    enable_interrupts();
}

flag_t mutex_try_lock( mutex_t * mutex )
{
    return SYNC_SET_OWNER( mutex, 0 );
}

flag_t mutex_lock( mutex_t * mutex )
{
    flag_t ret;

    ret = mutex_try_lock( mutex );

    if( ret == SYNC_ST_ROLL )
    {
        ret = SYNC_SLEEP( mutex );
    }

    return ret;
}

flag_t mutex_free( mutex_t * mutex )
{
    flag_t ret = SYNC_ST_ROLL;

    SYNC_WAKE( mutex,  0, 1, ret );    // Now we can wake some process.

    return ret;
}
