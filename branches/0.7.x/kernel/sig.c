/**************************************************************************
    BuguRTOS-0.7.x(Bugurt real time operating system)
    Copyright (C) 2014  anonimous

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

static void _sig_wakeup_list( sig_t * sig )
{
    proc_t * proc;

    proc = (proc_t *)xlist_head( (xlist_t *)&sig->wakeup );

    SPIN_LOCK( proc );
    _proc_cut_and_run( proc, PROC_STATE_W_READY );
    SPIN_FREE( proc );
}

/**********************************************************************************************
                                            Сигналы
***********************************************************************************************
                                      SYSCALL_PROC_RESTART
**********************************************************************************************/
// Инициация
void sig_init( sig_t * sig )
{
    disable_interrupts();
    sig_init_isr( sig );
    enable_interrupts();
}
//========================================================================================
void sig_init_isr( sig_t * sig )
{
    SPIN_INIT( sig );
    SPIN_LOCK( sig );
    gxlist_init( &sig->wait );
    gxlist_init( &sig->wakeup );
    SPIN_FREE( sig );
}
/**********************************************************************************************
                                       SYSCALL_SIG_WAIT
                                       SYSCALL_SIG_WAKEUP
**********************************************************************************************/
// Это выполнится при постановке процесса в список ожидания сигнала
void sig_wait( sig_t * sig )
{
    syscall_bugurt( SYSCALL_SIG_WAIT, (void *)sig );
    syscall_bugurt( SYSCALL_SIG_WAKEUP, (void *)0 );// Останов в случае необходимости
}
//========================================================================================
void _sig_wait_prologue( sig_t * sig )
{
    proc_t * proc;

    SPIN_LOCK( sig );

    proc = current_proc();

    SPIN_LOCK( proc );

    // Останавливаем процесс
    _proc_stop_flags_set( proc, PROC_STATE_W_SIG );
    proc->buf = (void *)sig; //Initialize a pointer before use.
    gitem_insert_group( (gitem_t *)proc, &sig->wait );// A process is inserted to a wait list

    SPIN_FREE( proc );

    SPIN_FREE( sig );
}
//========================================================================================
void scall_sig_wait( void * arg )
{
    _sig_wait_prologue( (sig_t *)arg );
}
//========================================================================================
void _sig_wait_epilogue( void )
{
    sig_t * sig;
    proc_t * proc;
    proc = current_proc();

    SPIN_LOCK( proc );

    sig = (sig_t *)proc->buf;
    proc->buf = (void *)0;
    PROC_SET_STATE( proc, PROC_STATE_RUNNING );

    SPIN_FREE( proc );

    KERNEL_PREEMPT(); /// KERNEL_PREEMPT

    if( sig == (sig_t *)0 ) return;

    SPIN_LOCK( sig );

    if( sig->wakeup.parent.index )
    {
        _sig_wakeup_list( sig );
    }

    SPIN_FREE( sig );
}
//========================================================================================
void scall_sig_wakeup( void *arg )
{
    _sig_wait_epilogue();
    _proc_flag_stop( (flag_t)0 );
}
/**********************************************************************************************
                                       SYSCALL_SIG_SIGNAL
**********************************************************************************************/
// Будит 1 процесс, для вызова из обработчиков прерываний
void sig_signal( sig_t * sig )
{
    syscall_bugurt( SYSCALL_SIG_SIGNAL, (void *)sig );
}
//========================================================================================
void sig_signal_isr( sig_t * sig )
{
    proc_t * proc;
    SPIN_LOCK( sig );

    if( sig->wait.parent.index == 0 ) goto end;

    proc = (proc_t *)xlist_head( (xlist_t*)&sig->wait );

    SPIN_LOCK( proc );

    proc->buf = (void *)0; // Will NOT continue wakeup.
    _proc_cut_and_run( proc, PROC_STATE_W_READY );

    SPIN_FREE( proc );
end:
    SPIN_FREE( sig );
}
//========================================================================================
void scall_sig_signal( void * arg )
{
    sig_signal_isr( (sig_t *)arg );
}
/**********************************************************************************************
                                       SYSCALL_SIG_BROADCAST
**********************************************************************************************/
// Будит все ожидающие процессы
void sig_broadcast( sig_t * sig )
{
    syscall_bugurt( SYSCALL_SIG_BROADCAST, (void *)sig );
}
//========================================================================================
void sig_broadcast_isr( sig_t * sig )
{
    SPIN_LOCK( sig );

    if( sig->wait.parent.index == 0 ) goto end;

    gxlist_merge( &sig->wait, &sig->wakeup );
    _sig_wakeup_list( sig );
end:
    SPIN_FREE( sig );
}
//========================================================================================
void scall_sig_broadcast( void * arg )
{
    sig_broadcast_isr( (sig_t *)arg );
}
