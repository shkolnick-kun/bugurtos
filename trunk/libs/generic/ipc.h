#ifndef _IPC_H_
#define _IPC_H_

#include <bugurt.h>

typedef struct _ipc_t ipc_t;
struct _ipc_t
{
    sync_t wait; /*!< \~russian Список ожидающих процессов. \~english A list of waiting processes.  */
    void * msg;  /*!< \~russian Указатель на буфер с сообщением. \~english A message buffer pointer. */
};

void ipc_init_isr( ipc_t * endpoint );
void ipc_init( ipc_t * endpoint );

flag_t ipc_send( ipc_t * out, void * msg );
flag_t ipc_wait( ipc_t * in, proc_t ** proc, flag_t block );
flag_t ipc_reply( ipc_t * in, proc_t * proc);

#endif // _IPC_H_
