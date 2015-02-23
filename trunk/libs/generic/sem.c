#include "sem.h"

void sem_init_isr( sem_t * sem, count_t count )
{
    SYNC_INIT_ISR( sem, PROC_PRIO_LOWEST );
    SPIN_INIT( sem );
    SPIN_LOCK( sem );
    sem->counter = count;
    sem->blocked = (count_t)0;
    SPIN_FREE( sem );
}

void sem_init( sem_t * sem, count_t count )
{
    disable_interrupts();
    sem_init_isr( sem, count );
    enable_interrupts();
}

flag_t sem_try_lock( sem_t * sem )
{
    flag_t ret = SYNC_ST_ROLL;

    if( !sem )
    {
        return SYNC_ST_ENULL;
    }

    disable_interrupts();
    SPIN_LOCK( sem );

    if( sem->counter )
    {
        sem->counter--;
        ret = SYNC_ST_OK;
    }

    SPIN_FREE( sem );
    enable_interrupts();

    return ret;
}

flag_t sem_lock( sem_t * sem )
{
    flag_t ret;

    if( !sem )
    {
        return SYNC_ST_ENULL;
    }

    disable_interrupts();
    SPIN_LOCK( sem );

    if( sem->counter )
    {
        sem->counter--;
        ret = SYNC_ST_OK;
    }
    else
    {
        sem->blocked++;
        ret = SYNC_ST_ROLL;
    }

    SPIN_FREE( sem );
    enable_interrupts();

    if( ret == SYNC_ST_ROLL )
    {
        ret = SYNC_SLEEP( sem );
    }
    return ret;
}

flag_t sem_free( sem_t * sem )
{
    flag_t ret;

    if( !sem )
    {
        return SYNC_ST_ENULL;
    }

    disable_interrupts();
    SPIN_LOCK( sem );

    if( sem->blocked )
    {
        sem->blocked--;
        ret = SYNC_ST_ROLL;
    }
    else
    {
        sem->counter++;
        ret = SYNC_ST_OK;
    }

    SPIN_FREE( sem );
    enable_interrupts();

    if( ret == SYNC_ST_ROLL )
    {
        proc_t * dummy = (proc_t *)0;
        SYNC_WAIT( sem, &dummy, 1, ret );// If wait list is empty (race condition), then caller will block.
        SYNC_WAKE( sem,  0, 0, ret );// Now we can wake some process.
    }

    return ret;
}
