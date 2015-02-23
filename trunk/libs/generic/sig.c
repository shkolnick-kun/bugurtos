#include "sig.h"

void sig_init( sig_t * sig )
{
    disable_interrupts();
    sig_init_isr( sig );
    enable_interrupts();
}

void sig_init_isr( sig_t * sig )
{
    cond_init_isr( (cond_t *)sig );
    KERNEL_PREEMPT();
    mutex_init_isr( &sig->wait, PROC_PRIO_LOWEST );
}

flag_t sig_wait( sig_t * sig )
{
    flag_t ret;
    if( !sig )
    {
        return SYNC_ST_ENULL;
    }
    ret = mutex_lock( &sig->wait );
    if( SYNC_ST_OK != ret )
    {
        return ret;
    }
    ret = cond_wait( (cond_t *)sig, &sig->wait );
    mutex_free( &sig->wait );
    return ret;
}

flag_t sig_signal( sig_t * sig )
{
    flag_t ret;
    if( !sig )
    {
        return SYNC_ST_ENULL;
    }
    ret = mutex_lock( &sig->wait );
    if( SYNC_ST_OK != ret )
    {
        return ret;
    }
    ret = cond_signal( (cond_t *)sig );
    mutex_free( &sig->wait );
    return ret;
}

count_t sig_broadcast( sig_t * sig )
{
    flag_t ret;
    if( !sig )
    {
        return SYNC_ST_ENULL;
    }
    ret = mutex_lock( &sig->wait );
    if( SYNC_ST_OK != ret )
    {
        return ret;
    }
    ret = cond_broadcast( (cond_t *)sig );
    mutex_free( &sig->wait );
    return ret;
}
