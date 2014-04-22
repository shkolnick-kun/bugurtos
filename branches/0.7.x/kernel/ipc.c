/**************************************************************************
    BuguRTOS-0.6.x(Bugurt real time operating system)
    Copyright (C) 2013  anonimous

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Please contact with me by E-mail: shkolnick.kun@gmail.com

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes BuguRTOS, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
**************************************************************************/

/*****************************************************************************************
```````````````````````````````..:+oyhdmNNMMMMMMNmmdhyo+:..```````````````````````````````
``````````````````````````.:oydNMMMMMMMMMNNNNNNNNMMMMMMMMMNdy+:.``````````````````````````
```````````````````````:sdNMMMMMNdys+/::----------::/osydNMMMMMNds:```````````````````````
```````````````````.+hNMMMMmho/-..........................-/shmMMMMNh/.```````````````````
````````````````./hNMMMNho:...................................-:ohNMMMNh/`````````````````
``````````````.smMMMNy/-.......:////ss++/+-.......................-+yNMMMmo.``````````````
````````````-sNMMMd+-.....:////:-...-/s::..............+o/-..........-odMMMNs.````````````
``````````.sNMMNh/....................................-o:--............./hMMMNo.``````````
`````````+mMMMh:-........................................-...............-/dMMMm/`````````
```````.yMMMm/...................-::--..................:-........--........+mMMMy.```````
``````:mMMMy-.......................-::-...............-:.........-::........-yMMMd:``````
`````/NMMN+-..................::-.....-:-............../--.........-:/-.......-+NMMN:`````
````+NMMm::o/-..--/+o+o+++++o+osys+//::-::.............:/....-:-::-..-++-.......:NMMN/````
```/NMMm:.-++-+yhs/-``       `dMMMMMmho+:-..............:-/+yho/:/+oyo//o-......./mMMN:```
``-NMMm/....-/--::/o+o+oo+oo++oosyss+smyo/.............:yyho-`     smMMddh-......./NMMN.``
`.hMMM/......-++:-.-:oooooooooosyyhhys/...............-+osyyyyysssssooo+ohhs-......+MMMh.`
`+MMMy.......-::/++:-.....-:/++++o+o/--................--/oooo+o++o+++////-y/.......hMMM/`
.mMMN:.........--:---...-::/+//::--.......................--//+//-...-.....+/......./NMMd`
/MMMy............-::----------....----/+-.....................-++/:---....-o-........hMMN:
yMMM/.............--:://///oo+++/+++oo+-.......................-://+/:--::::.........+MMMs
mMMN:................----:/h:::/:/::---.........................--/osss+++:..........:NMMd
MMMd-....................:mNs:-....................................--:odo:-..........:mMMN
MMMd-....................yoshyoso:--................................../mm/...........:mMMM
MMMm:..................../-o/h.y-:+dooo+/:--....................-/osydddmh...........:mMMN
mMMN:........................+mNs `h.  -d/:/+h++ooooy+++s++y+++mo+y` yh.do...........:NMMh
sMMM+........................-hmMo/ds  oMo`.-o     :h   s:`h` `Nysd.-Ny-h:...........+MMMo
/MMMh........................./smMMMMd+NMMNNMh`    sN: .mNNMddNMMMMNmN+..............hMMN:
.dMMN/........................./+hMMMMMMMMMMMMmhyyyNMNNMMMMMMMMMMMNsoo-............./NMMd`
`+MMMh.........................-/+omMMMMMMMMMMMMMMMMMMMMMMMMMMMMms-/+...............hMMM/`
`.hMMM+..........................:/-omMMMMMMMMMMMMMMMdmMdhMMMds/-..-...............oMMMy``
``.NMMN/............................--/hNN/h.`ys:dmsd:-syos+--+.................../NMMN.``
```/NMMm:...........................:+/--:+s++oo+osoo+/:-..-/+::-................/mMMN:```
````/NMMN:............................-/++/:-..........-//+/-..:+.--............/NMMN/````
`````:NMMN+-.............../+-.............-://////////:-.......+s+::.........-oNMMN:`````
``````:mMMMy-..............:/o-.................................:yo//........-hMMMd-``````
```````.yMMMm+.............:o:++-...............................+y+o-......-+mMMMs.```````
`````````/mMMMd/-...........-++:+/-.---........................-ho+/.....-/dMMMm/`````````
``````````.oNMMMh/............-++:++/////:....................-yo:o-...-+hMMMNo.``````````
````````````.sNMMMdo-...........-++::++:-:/+//:..............:o:/o-..-omMMMNo.````````````
``````````````.omMMMNy+-..........-/+-.:/+/:--:+++/++//:/::/+/-+/.-+hMMMMmo```````````````
`````````````````/hNMMMNho:-...............-:/:-....--::::--..-/ohNMMMNy:`````````````````
```````````````````./hNMMMMmhs/-..........................-/shNMMMMNy/.```````````````````
```````````````````````:sdNMMMMMNdhso+/:----------:/+oshdNMMMMMNho:```````````````````````
``````````````````````````.:+ydNMMMMMMMMMMNNNNNNMMMMMMMMMMmds+:```````````````````````````
````````````````````````````````.:/osyhdmNNMMMMNNmdhyso/:.````````````````````````````````
******************************************************************************************
*                                                                                        *
*                   This logo was graciously delivered by 10003-kun ITT:                 *
*                                                                                        *
*                           http://www.0chan.ru/r/res/9996.html                          *
*                                                                                        *
*****************************************************************************************/
#include "../include/bugurt.h"
/**********************************************************************************************
                                           IPC
***********************************************************************************************
                                       SYSCALL_IPC_WAIT
**********************************************************************************************/
ipc_data_t ipc_wait( void )
{
    volatile ipc_data_t ret = (ipc_data_t)0;
    syscall_bugurt( SYSCALL_IPC_WAIT, (void *)&ret );
    return ret;
}
//========================================================================================
void _ipc_wait( void * ipc_pointer )
{
    proc_t * proc;
    proc = current_proc();

    SPIN_LOCK( proc );
    // Останавливаем процесс
    _proc_stop_flags_set( proc, PROC_STATE_W_IPC );
    proc->buf = ipc_pointer;

    SPIN_FREE( proc );
}
//========================================================================================
void scall_ipc_wait(void * arg)
{
    _ipc_wait( arg );
}
/**********************************************************************************************
                                       SYSCALL_IPC_SEND
**********************************************************************************************/
/*!
\~russian
\brief
Параметр системного вызова #SYSCALL_IPC_SEND.

\~english
\brief
An argument structure for #SYSCALL_IPC_SEND.
*/
typedef struct {
    proc_t * proc;  /*!< \~russian указатель на процесс-адресат. \~english A pointer to a destignation process. */
    bool_t ret;     /*!< \~russian хранилище результата выполнения операции. \~english A storage for a result. */
    ipc_data_t ipc_data;/*!< \~russian данные для передачи. \~english A data to send. */
} ipc_send_arg_t;
//========================================================================================
bool_t ipc_send( proc_t * proc, ipc_data_t ipc_data )
{
    volatile ipc_send_arg_t arg;
    arg.proc = proc;
    arg.ipc_data = ipc_data;
    syscall_bugurt( SYSCALL_IPC_SEND, (void *)&arg );
    return arg.ret;
}
//========================================================================================
bool_t ipc_send_isr( proc_t * proc, ipc_data_t ipc_data )
{
    bool_t ret = (bool_t)0;

    SPIN_LOCK( proc );

    if( PROC_IPC_TEST( proc ) )
    {
        proc->flags &= PROC_STATE_CLEAR_MASK;
        ///Обработка флага останова целевого процесса
        if(  PROC_PRE_STOP_TEST(proc)  )
        {
            /*
            Если был запрошен останов целевого процесса,
            и целевой процесс не удерживает общие ресурсы,
            то мы не будем возобновлять его работу
            и передавать ему информацию.
            */
            proc->flags &= ~PROC_FLG_PRE_STOP;
            goto end;
        }
        ret = (bool_t)1; // информация будет передана
        *(ipc_data_t *)proc->buf = ipc_data;
        sched_proc_run( proc, PROC_STATE_READY );
    }
end:
    SPIN_FREE( proc );
    return ret;
}
//========================================================================================
void scall_ipc_send(void * arg)
{
    ((ipc_send_arg_t *)arg)->ret = ipc_send_isr( ((ipc_send_arg_t *)arg)->proc, ((ipc_send_arg_t *)arg)->ipc_data );
}
/**********************************************************************************************
                                    SYSCALL_IPC_EXCHANGE
**********************************************************************************************/
/*!
\~russian
\brief
Параметр системного вызова #SYSCALL_IPC_EXCHANGE.

\~english
\brief
An argument structure for #SYSCALL_IPC_EXCHANGE.
*/
typedef struct {
    ipc_send_arg_t send;  /*!< \~russian Родитель. \~english A parent. */
    ipc_data_t * receive; /*!< \~russian Указатель на хранилище принимаемых данных. \~english Apointer to storage for data to receive. */
} ipc_exchange_arg_t;
//========================================================================================
bool_t ipc_exchange( proc_t * proc, ipc_data_t send, ipc_data_t * receive )
{
    volatile ipc_exchange_arg_t arg;
    arg.send.proc = proc;
    arg.send.ipc_data = send;
    arg.receive = receive;
    syscall_bugurt( SYSCALL_IPC_EXCHANGE, (void *)&arg );
    return arg.send.ret;
}
//========================================================================================
bool_t _ipc_exchange( proc_t * proc, ipc_data_t send, ipc_data_t * receive )
{
    bool_t ret = (bool_t)0;

    SPIN_LOCK( proc );

    if( PROC_IPC_TEST( proc ) )
    {
        proc->flags &= PROC_STATE_CLEAR_MASK;
        ///Обработка флага останова целевого процесса
        if(  PROC_PRE_STOP_TEST(proc)  )
        {
            /*
            Если был запрошен останов целевого процесса,
            и целевой процесс не удерживает общие ресурсы,
            то мы не будем возобновлять его работу
            и передавать ему информацию.
            */
            proc->flags &= ~PROC_FLG_PRE_STOP;
            goto end;
        }
        ret = (bool_t)1; // информация будет передана
        *(ipc_data_t *)proc->buf = send;
        _ipc_wait( receive ); // Готовимся к приему данных!
        sched_proc_run( proc, PROC_STATE_READY );   // И только после этого запускаем процесс-адресат!
    }
end:
    SPIN_FREE( proc );
    return ret;
}
//========================================================================================
void scall_ipc_exchange(void * arg)
{
    ((ipc_send_arg_t *)arg)->ret = _ipc_exchange( ((ipc_send_arg_t *)arg)->proc, ((ipc_send_arg_t *)arg)->ipc_data, ((ipc_exchange_arg_t *)arg)->receive );
}
