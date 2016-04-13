/**************************************************************************
    BuguRTOS-0.9.x (Bugurt real time operating system)
    Copyright (C) 2015 anonimous

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
#include "bugurt.h"

BGRT_SCL_TBL( syscall_handler[] ) =
{
    // Process control
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_run               ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_restart           ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_stop              ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_self_stop         ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_terminate         ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_lock              ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_free              ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_reset_watchdog    ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_set_prio          ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_get_prio          ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_proc_get_id            ),
    // Scheduler
    BGRT_SC_TBL_ENTRY( bgrt_scall_sched_proc_yeld        ),
    // Bsync
    BGRT_SC_TBL_ENTRY( bgrt_scall_sync_set_owner         ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_sync_get_owner         ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_sync_own               ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_sync_touch             ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_sync_sleep             ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_sync_wake              ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_sync_wait              ),
    BGRT_SC_TBL_ENTRY( bgrt_scall_sync_proc_timeout      ),
    //Arbitrary code execution
    BGRT_SC_TBL_ENTRY( bgrt_scall_user                   )
};

#ifndef BGRT_CONFIG_SYSCALL_CHECK
//Default syscall sanity check macro
#define BGRT_SYSCALL_CHECK(n,a) \
( ( (bgrt_syscall_t)0 == n )||( BGRT_SYSCALL_USER < n  ) )

#else  //BGRT_CONFIG_SYSCALL_CHECK

#define BGRT_SYSCALL_CHECK BGRT_CONFIG_SYSCALL_CHECK

#endif //BGRT_CONFIG_SYSCALL_CHECK

bgrt_st_t bgrt_do_syscall( bgrt_syscall_t syscall_num, void * syscall_arg )
{
    //Sanity check
    if( BGRT_SYSCALL_CHECK(syscall_num, syscall_arg) )
    {
        //Fail
        return BGRT_ST_SCALL;
    }
    else
    {
        //Syscall processing
        return (BGRT_SCL_TBL_READ(syscall_handler[syscall_num - 1]))(syscall_arg);
    }
}



/**********************************************************************************************
                                  System call handlers !!!
***********************************************************************************************
                                   BGRT_SYSCALL_PROC_RUN
**********************************************************************************************/
bgrt_st_t bgrt_proc_run( BGRT_PID_T pid )
{
    volatile bgrt_proc_runtime_arg_t scarg;
    scarg.pid = pid;
    bgrt_syscall( BGRT_SYSCALL_PROC_RUN, (void *)&scarg );
    return scarg.ret;
}
//=============================================================================================
bgrt_st_t bgrt_scall_proc_run( bgrt_proc_runtime_arg_t * arg )
{
    arg->ret = _bgrt_proc_run( BGRT_PID_TO_PROC( arg->pid ) );
    return arg->ret;
}
/**********************************************************************************************
                                  BGRT_SYSCALL_PROC_RESTART
**********************************************************************************************/
bgrt_st_t bgrt_proc_restart( BGRT_PID_T pid )
{
    volatile bgrt_proc_runtime_arg_t scarg;
    scarg.pid = pid;
    bgrt_syscall( BGRT_SYSCALL_PROC_RESTART, (void *)&scarg );
    return scarg.ret;
}
//========================================================================================
bgrt_st_t bgrt_scall_proc_restart( bgrt_proc_runtime_arg_t * arg )
{
    arg->ret = _bgrt_proc_restart( BGRT_PID_TO_PROC( arg->pid ) );
    return arg->ret;
}
/**********************************************************************************************
                                   BGRT_SYSCALL_PROC_STOP
**********************************************************************************************/
bgrt_st_t bgrt_proc_stop( BGRT_PID_T pid )
{
    volatile bgrt_proc_runtime_arg_t scarg;
    scarg.pid = pid;
    bgrt_syscall( BGRT_SYSCALL_PROC_STOP, (void *)&scarg);
    return scarg.ret;
}
//========================================================================================
bgrt_st_t bgrt_scall_proc_stop( bgrt_proc_runtime_arg_t * arg )
{
    arg->ret = _bgrt_proc_stop( BGRT_PID_TO_PROC( arg->pid ) );
    return arg->ret;
}
/**********************************************************************************************
                                 BGRT_SYSCALL_PROC_SELF_STOP
**********************************************************************************************/
void bgrt_proc_self_stop(void)
{
    bgrt_syscall( BGRT_SYSCALL_PROC_SELF_STOP, (void *)1 );
}
//========================================================================================
bgrt_st_t bgrt_scall_proc_self_stop( void * arg )
{
    _bgrt_proc_self_stop();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                 BGRT_SYSCALL_PROC_TERMINATE
**********************************************************************************************/
// Terminate a process after pmain return.
void bgrt_proc_terminate( void )
{
    bgrt_syscall( BGRT_SYSCALL_PROC_TERMINATE, (void *)0 );
}
//========================================================================================
bgrt_st_t bgrt_scall_proc_terminate( void * arg )
{
    _bgrt_proc_terminate();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                   BGRT_SYSCALL_PROC_LOCK
**********************************************************************************************/
void bgrt_proc_lock( void )
{
    bgrt_syscall( BGRT_SYSCALL_PROC_LOCK, (void *)0 );
}
//========================================================================================
bgrt_st_t bgrt_scall_proc_lock( void * arg )
{
    _bgrt_proc_lock();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                   BGRT_SYSCALL_PROC_FREE
**********************************************************************************************/
void bgrt_proc_free( void )
{
    bgrt_syscall( BGRT_SYSCALL_PROC_FREE, (void *)0 );
}
//========================================================================================
bgrt_st_t bgrt_scall_proc_free( void * arg )
{
    _bgrt_proc_free();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                             BGRT_SYSCALL_PROC_RESET_WATCHDOG
**********************************************************************************************/
void bgrt_proc_reset_watchdog(void)
{
    bgrt_syscall( BGRT_SYSCALL_PROC_RESET_WATCHDOG, (void *)0 );
}
//========================================================================================
bgrt_st_t bgrt_scall_proc_reset_watchdog( void * arg )
{
    _bgrt_proc_reset_watchdog();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                 BGRT_SYSCALL_PROC_SET_PRIO
**********************************************************************************************/
void bgrt_proc_set_prio( BGRT_PID_T pid, bgrt_prio_t prio )
{
    volatile bgrt_proc_set_prio_arg_t arg;
    arg.pid = pid;
    arg.prio = prio;
    bgrt_syscall( BGRT_SYSCALL_PROC_SET_PRIO, (void *)&arg );
}
//========================================================================================
bgrt_st_t bgrt_scall_proc_set_prio( bgrt_proc_set_prio_arg_t * arg )
{
    _bgrt_proc_set_prio( BGRT_PID_TO_PROC( arg->pid ), arg->prio );
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                BGRT_SYSCALL_PROC_GET_PRIO
**********************************************************************************************/
bgrt_prio_t bgrt_proc_get_prio( BGRT_PID_T pid )
{
    bgrt_proc_get_prio_arg_t scarg;
    scarg.ret = BGRT_PROC_PRIO_LOWEST + 1; //Not possible!
    scarg.pid = pid;
    bgrt_syscall( BGRT_SYSCALL_PROC_GET_PRIO, (void *)&scarg );
    return scarg.ret;
}
//========================================================================================
bgrt_st_t bgrt_scall_proc_get_prio( bgrt_proc_get_prio_arg_t * arg )
{
    arg->ret = _bgrt_proc_get_prio( BGRT_PID_TO_PROC( arg->pid ) );
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                BGRT_SYSCALL_PROC_GET_ID
**********************************************************************************************/
BGRT_PID_T bgrt_proc_get_id(void)
{
    BGRT_PID_T ret = (BGRT_PID_T)0;
    bgrt_syscall( BGRT_SYSCALL_PROC_GET_ID, (void *)&ret );
    return ret;
}
//========================================================================================
bgrt_st_t bgrt_scall_proc_get_id( BGRT_PID_T * arg )
{
    *arg = BGRT_PROC_TO_PID( bgrt_curr_proc() );
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                 BGRT_SYSCALL_PROC_YELD
**********************************************************************************************/
bgrt_bool_t bgrt_sched_proc_yeld(void)
{
    volatile bgrt_bool_t ret;
    bgrt_syscall( BGRT_SYSCALL_SCHED_PROC_YELD, (void *)&ret );
    return ret;
}
//========================================================================================
bgrt_st_t bgrt_scall_sched_proc_yeld( bgrt_bool_t * arg )
{
    *arg = _bgrt_sched_proc_yeld();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                BGRT_SYSCALL_SYNC_SET_OWNER
**********************************************************************************************/
bgrt_st_t bgrt_sync_set_owner( bgrt_sync_t * sync, BGRT_PID_T pid )
{
    volatile bgrt_sync_owner_t scarg;
    scarg.sync = sync;
    scarg.pid = pid;
    scarg.status = BGRT_ST_ROLL;
    bgrt_syscall( BGRT_SYSCALL_SYNC_SET_OWNER, (void *)&scarg );
    return scarg.status;
}
//========================================================================================
bgrt_st_t bgrt_scall_sync_set_owner( bgrt_sync_owner_t * arg )
{
    arg->status = _bgrt_sync_set_owner( arg->sync, BGRT_PID_TO_PROC( arg->pid ) );
    return arg->status;
}
/**********************************************************************************************
                               BGRT_SYSCALL_SYNC_GET_OWNER
**********************************************************************************************/
BGRT_PID_T bgrt_sync_get_owner( bgrt_sync_t * sync )
{
    volatile bgrt_sync_owner_t scarg;
    scarg.sync = sync;
    scarg.pid = 0;
    scarg.status = BGRT_ST_ROLL;
    bgrt_syscall( BGRT_SYSCALL_SYNC_GET_OWNER, (void *)&scarg );
    return scarg.pid;
}
//========================================================================================
bgrt_st_t bgrt_scall_sync_get_owner( bgrt_sync_owner_t * arg )
{
    arg->pid = BGRT_PROC_TO_PID( _bgrt_sync_get_owner( arg->sync ) );
    arg->status = BGRT_ST_OK;
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                  BGRT_SYSCALL_SYNC_OWN
**********************************************************************************************/
bgrt_st_t bgrt_sync_own( bgrt_sync_t * sync, bgrt_flag_t touch )
{
    bgrt_sync_own_sleep_t scarg;
    scarg.status = BGRT_ST_EOWN;
    scarg.sync = sync;
    scarg.touch = touch;
    bgrt_syscall( BGRT_SYSCALL_SYNC_OWN, (void *)&scarg );
    return scarg.status;
}
//========================================================================================
bgrt_st_t bgrt_scall_sync_own( bgrt_sync_own_sleep_t * arg )
{
    arg->status = _bgrt_sync_own( arg->sync, arg->touch );
    return arg->status;
}
/**********************************************************************************************
                                 BGRT_SYSCALL_SYNC_TOUCH
**********************************************************************************************/
bgrt_st_t bgrt_sync_touch( bgrt_sync_t * sync )
{
    bgrt_sync_touch_t scarg;
    scarg.status = BGRT_ST_ENULL;
    scarg.sync = sync;
    bgrt_syscall( BGRT_SYSCALL_SYNC_TOUCH, (void *)&scarg );
    return scarg.status;
}
//========================================================================================
bgrt_st_t bgrt_scall_sync_touch( bgrt_sync_touch_t * arg )
{
    arg->status = _bgrt_sync_touch( arg->sync );
    return arg->status;
}
/**********************************************************************************************
                                 BGRT_SYSCALL_SYNC_SLEEP
**********************************************************************************************/
bgrt_st_t bgrt_sync_sleep( bgrt_sync_t * sync, bgrt_flag_t touch )
{
    volatile bgrt_sync_own_sleep_t scarg;
    scarg.status = BGRT_ST_ROLL;
    scarg.sync = sync;
    scarg.touch = touch;
    do
    {
        bgrt_syscall( BGRT_SYSCALL_SYNC_SLEEP, (void *)&scarg );
    }
    while( scarg.status >= BGRT_ST_ROLL );
    return scarg.status;
}
//========================================================================================
bgrt_st_t bgrt_scall_sync_sleep( bgrt_sync_own_sleep_t * arg )
{
    arg->status = _bgrt_sync_sleep( arg->sync, &arg->touch );
    return arg->status;
}
/**********************************************************************************************
                                    BGRT_SYSCALL_SYNC_WAKE
**********************************************************************************************/
bgrt_st_t bgrt_sync_wake( bgrt_sync_t * sync, BGRT_PID_T pid, bgrt_flag_t chown )
{
    volatile bgrt_sync_wake_t scarg;
    scarg.status = BGRT_ST_ROLL;
    scarg.sync = sync;
    scarg.pid = pid;
    scarg.chown = chown;
    do
    {
        bgrt_syscall( BGRT_SYSCALL_SYNC_WAKE, (void *)&scarg );
    }
    while( scarg.status >= BGRT_ST_ROLL );
    return scarg.status;
}
//========================================================================================
bgrt_st_t bgrt_scall_sync_wake( bgrt_sync_wake_t * arg )
{
    arg->status = _bgrt_sync_wake( arg->sync , BGRT_PID_TO_PROC( arg->pid ), arg->chown );
    return arg->status;
}
/**********************************************************************************************
                                    BGRT_SYSCALL_SYNC_WAIT
**********************************************************************************************/
bgrt_st_t bgrt_sync_wait( bgrt_sync_t * sync, BGRT_PID_T * pid, bgrt_flag_t block )
{
    volatile bgrt_sync_wait_t scarg;
    scarg.status = BGRT_ST_ROLL;
    scarg.sync = sync;
    scarg.pid = pid;
    scarg.block = block;
    do
    {
        bgrt_syscall( BGRT_SYSCALL_SYNC_WAIT, (void *)&scarg );
    }
    while( scarg.status >= BGRT_ST_ROLL );
    return scarg.status;
}
//========================================================================================
bgrt_st_t bgrt_scall_sync_wait( bgrt_sync_wait_t * arg )
{
    if( !arg->pid )
    {
        arg->status = BGRT_ST_ENULL;
    }
    else
    {
        bgrt_proc_t * proc;

        proc = BGRT_PID_TO_PROC( *arg->pid );
        arg->status = _bgrt_sync_wait( arg->sync, &proc, arg->block );
        *arg->pid = BGRT_PROC_TO_PID( proc );
    }
    return arg->status;
}
/**********************************************************************************************
                               BGRT_SYSCALL_SYNC_PROC_TIMEOUT
**********************************************************************************************/
bgrt_st_t bgrt_sync_proc_timeout( BGRT_PID_T pid )
{
    volatile bgrt_sync_proc_timeout_t scarg;
    scarg.pid = pid;
    scarg.status = BGRT_ST_ROLL;
    bgrt_syscall( BGRT_SYSCALL_SYNC_PROC_TIMEOUT, (void *)&scarg );
    return scarg.status;
}
//========================================================================================
bgrt_st_t bgrt_scall_sync_proc_timeout( bgrt_sync_proc_timeout_t * arg )
{
    arg->status = _bgrt_sync_proc_timeout( BGRT_PID_TO_PROC( arg->pid ) );
    return arg->status;
}
/**********************************************************************************************
                                       BGRT_SYSCALL_USER
**********************************************************************************************/
typedef union
{
    bgrt_code_t func;
    void * arg;
}
bgrt_scall_user_t;

bgrt_st_t bgrt_scall_user(void * arg)
{
    bgrt_scall_user_t user;
    user.func = (bgrt_code_t)0;
    user.arg = arg;
    user.func(arg);
    return BGRT_ST_OK;
}
