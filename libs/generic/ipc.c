#include "ipc.h"

void ipc_init_isr( ipc_t * endpoint )
{
    SYNC_INIT_ISR( endpoint, PROC_PRIO_LOWEST );
    endpoint->msg = (void *)0;
}

void ipc_init( ipc_t * endpoint )
{
    disable_interrupts();
    ipc_init_isr( endpoint );
    enable_interrupts();
}

flag_t ipc_send( ipc_t * out, void * msg )
{
    flag_t ret;

    ret = SYNC_SLEEP( out );

    if( SYNC_ST_OK != ret )
    {
        return ret;
    }

    out->msg = msg;

    ret = SYNC_SLEEP( out );
    return ret;
}

flag_t ipc_wait( ipc_t * in, proc_t ** proc, flag_t block )
{
    flag_t ret;

    SYNC_WAIT(in, proc, block, ret );

    if( SYNC_ST_OK != ret )
    {
        return ret;
    }

    SYNC_WAKE(in, *proc, 0, ret );

    if( SYNC_ST_OK != ret )
    {
        return ret;
    }

    SYNC_WAIT(in, proc, 1, ret );
    return ret;
}

flag_t ipc_reply( ipc_t * in, proc_t * proc)
{
    flag_t ret;

    SYNC_WAKE(in, proc, 0, ret );

    return ret;
}
