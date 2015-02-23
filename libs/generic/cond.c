#include "cond.h"

void cond_init_isr( cond_t * cond )
{
    SYNC_INIT_ISR( cond, PROC_PRIO_LOWEST );
}

void cond_init( cond_t * cond )
{
    disable_interrupts();
    cond_init_isr( cond );
    enable_interrupts();
}

flag_t cond_wait(  cond_t * cond, mutex_t * mutex )
{
    flag_t ret = SYNC_ST_ROLL;

    if( (!mutex) || (!cond) )
    {
        return SYNC_ST_ENULL;
    }

    cond->blocked++; //Guarded by mutex

    ret = mutex_free( mutex );

    if( SYNC_ST_EOWN == ret )
    {
        return ret;
    }

    ret = SYNC_SLEEP( cond );

    mutex_lock( mutex );

    return ret;
}

flag_t cond_signal( cond_t * cond )
{
    flag_t ret = SYNC_ST_EEMPTY;

    if( cond->blocked )
    {
        proc_t * dummy = (proc_t *)0;

        SYNC_WAIT( cond, &dummy, 1, ret );// If wait list is empty (race condition), then caller will block.
        SYNC_WAKE( cond, 0, 0, ret );

        cond->blocked--;
    }

    return ret;
}

flag_t cond_broadcast( cond_t * cond )
{
    flag_t ret = SYNC_ST_ROLL;
    do
    {
        ret = cond_signal( cond );
    }
    while( SYNC_ST_OK == ret );

    return ret;
}
