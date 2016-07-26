/**************************************************************************
    BuguRTOS-1.0.x (Bugurt real time operating system)
    Copyright (C) 2016 anonimous

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
#ifndef _BGRT_SCR_H_
#define _BGRT_SCR_H_

#include <bugurt.h>
/**********************************************************************************************
                                  System call handlers !!!
***********************************************************************************************
                                       PROC_RUN
**********************************************************************************************/
BGRT_SC_SR(PROC_RUN)(void * arg)
{
    return _bgrt_proc_run( BGRT_PID_TO_PROC( (BGRT_PID_T)arg ) );
}
/**********************************************************************************************
                                       PROC_RESTART
**********************************************************************************************/
BGRT_SC_SR(PROC_RESTART)(void * arg)
{
    return _bgrt_proc_restart( BGRT_PID_TO_PROC( (BGRT_PID_T)arg ) );
}
/**********************************************************************************************
                                         PROC_STOP
**********************************************************************************************/
BGRT_SC_SR(PROC_STOP)(void * arg)
{
    return _bgrt_proc_stop( BGRT_PID_TO_PROC( (BGRT_PID_T)arg ) );
}
/**********************************************************************************************
                                       PROC_SELF_STOP
**********************************************************************************************/
void bgrt_proc_self_stop(void)
{
    BGRT_SYSCALL_N(PROC_SELF_STOP, (void *)1 );
}
//========================================================================================
BGRT_SC_SR(PROC_SELF_STOP)(void * arg)
{
    (void)arg;
    _bgrt_proc_self_stop();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                         PROC_LOCK
**********************************************************************************************/
void bgrt_proc_lock(void)
{
    BGRT_SYSCALL_N(PROC_LOCK, (void *)0 );
}
//========================================================================================
BGRT_SC_SR(PROC_LOCK)(void * arg)
{
    (void)arg;
    _bgrt_proc_lock();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                         PROC_FREE
**********************************************************************************************/
void bgrt_proc_free( void )
{
    BGRT_SYSCALL_N(PROC_FREE, (void *)0 );
}
//========================================================================================
BGRT_SC_SR(PROC_FREE)( void * arg )
{
    (void)arg;
    _bgrt_proc_free();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                    PROC_RESET_WATCHDOG
**********************************************************************************************/
void bgrt_proc_reset_watchdog(void)
{
    BGRT_SYSCALL_N(PROC_RESET_WATCHDOG, (void *)0 );
}
//========================================================================================
BGRT_SC_SR(PROC_RESET_WATCHDOG)( void * arg )
{
    (void)arg;
    _bgrt_proc_reset_watchdog();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                       PROC_SET_PRIO
**********************************************************************************************/
void bgrt_proc_set_prio( BGRT_PID_T pid, bgrt_prio_t prio )
{
    volatile bgrt_proc_prio_arg_t arg;

    arg.pid = pid;
    arg.prio = prio;

    BGRT_SYSCALL_NVAR(PROC_SET_PRIO, (void *)&arg );
}
//========================================================================================
BGRT_SC_SR(PROC_SET_PRIO)( bgrt_proc_prio_arg_t * arg )
{
    _bgrt_proc_set_prio( BGRT_PID_TO_PROC( arg->pid ), arg->prio );
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                       PROC_GET_PRIO
**********************************************************************************************/
bgrt_prio_t bgrt_proc_get_prio( BGRT_PID_T pid )
{
    volatile bgrt_proc_prio_arg_t arg;

    arg.prio = BGRT_PRIO_LOWEST + 1; //Not possible!
    arg.pid = pid;

    BGRT_SYSCALL_N(PROC_GET_PRIO, (void *)&arg );
    return arg.prio;
}
//========================================================================================
BGRT_SC_SR(PROC_GET_PRIO)( bgrt_proc_prio_arg_t * arg )
{
    arg->prio = _bgrt_proc_get_prio( BGRT_PID_TO_PROC( arg->pid ) );
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                        PROC_GET_ID
**********************************************************************************************/
BGRT_PID_T bgrt_proc_get_id(void)
{
    BGRT_PID_T ret = (BGRT_PID_T)0;
    BGRT_SYSCALL_N(PROC_GET_ID, (void *)&ret );
    return ret;
}
//========================================================================================
BGRT_SC_SR(PROC_GET_ID)( BGRT_PID_T * arg )
{
    *arg = BGRT_PROC_TO_PID( bgrt_curr_proc() );
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                      SYNC_SET_OWNER
**********************************************************************************************/
bgrt_st_t bgrt_sync_set_owner( bgrt_sync_t * sync, BGRT_PID_T pid )
{
    volatile bgrt_sync_owner_t scarg;
    scarg.sync = sync;
    scarg.pid = pid;
    return BGRT_SYSCALL_N(SYNC_SET_OWNER, (void *)&scarg );
}
//========================================================================================
BGRT_SC_SR(SYNC_SET_OWNER)( bgrt_sync_owner_t * arg )
{
    return _bgrt_sync_set_owner( arg->sync, BGRT_PID_TO_PROC( arg->pid ) );
}
/**********************************************************************************************
                                       SYNC_GET_OWNER
**********************************************************************************************/
BGRT_PID_T bgrt_sync_get_owner( bgrt_sync_t * sync )
{
    volatile bgrt_sync_owner_t scarg;
    scarg.sync = sync;
    scarg.pid = 0;
    BGRT_SYSCALL_N(SYNC_GET_OWNER, (void *)&scarg );
    return scarg.pid;
}
//========================================================================================
BGRT_SC_SR(SYNC_GET_OWNER)( bgrt_sync_owner_t * arg )
{
    arg->pid = BGRT_PROC_TO_PID( _bgrt_sync_get_owner( arg->sync ) );
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                          SYNC_OWN
**********************************************************************************************/
bgrt_st_t bgrt_sync_own( bgrt_sync_t * sync, bgrt_flag_t touch )
{
    bgrt_sync_own_sleep_t scarg;
    scarg.sync = sync;
    scarg.touch = touch;
    return BGRT_SYSCALL_N(SYNC_OWN, (void *)&scarg );
}
//========================================================================================
BGRT_SC_SR(SYNC_OWN)( bgrt_sync_own_sleep_t * arg )
{
    return _bgrt_sync_own( arg->sync, arg->touch );
}
/**********************************************************************************************
                                        SYNC_TOUCH
**********************************************************************************************/
bgrt_st_t bgrt_sync_touch( bgrt_sync_t * sync )
{
    bgrt_sync_touch_t scarg;
    scarg.sync = sync;
    return BGRT_SYSCALL_N(SYNC_TOUCH, (void *)&scarg );
}
//========================================================================================
BGRT_SC_SR(SYNC_TOUCH)( bgrt_sync_touch_t * arg )
{
    return _bgrt_sync_touch( arg->sync );
}
/**********************************************************************************************
                                         SYNC_SLEEP
**********************************************************************************************/
bgrt_st_t bgrt_sync_sleep( bgrt_sync_t * sync, bgrt_flag_t touch )
{
    volatile bgrt_sync_own_sleep_t scarg;
    scarg.sync = sync;
    scarg.touch = touch;
    return BGRT_SYSCALL_N(SYNC_SLEEP, (void *)&scarg );
}
//========================================================================================
BGRT_SC_SR(SYNC_SLEEP)( bgrt_sync_own_sleep_t * arg )
{
    return _bgrt_sync_sleep( arg->sync, &arg->touch );
}
/**********************************************************************************************
                                        SYNC_WAKE
**********************************************************************************************/
bgrt_st_t bgrt_sync_wake( bgrt_sync_t * sync, BGRT_PID_T pid, bgrt_flag_t chown )
{
    volatile bgrt_sync_wake_t scarg;
    scarg.sync = sync;
    scarg.pid = pid;
    scarg.chown = chown;
    return BGRT_SYSCALL_N(SYNC_WAKE, (void *)&scarg );
}
//========================================================================================
BGRT_SC_SR(SYNC_WAKE)( bgrt_sync_wake_t * arg )
{
    return _bgrt_sync_wake( arg->sync , BGRT_PID_TO_PROC( arg->pid ), arg->chown );
}
/**********************************************************************************************
                                        SYNC_WAIT
**********************************************************************************************/
bgrt_st_t bgrt_sync_wait( bgrt_sync_t * sync, BGRT_PID_T * pid, bgrt_flag_t block )
{
    volatile bgrt_sync_wait_t scarg;
    scarg.sync = sync;
    scarg.pid = pid;
    scarg.block = block;
    return BGRT_SYSCALL_N(SYNC_WAIT, (void *)&scarg );
}
//========================================================================================
BGRT_SC_SR(SYNC_WAIT)( bgrt_sync_wait_t * arg )
{
    if( !arg->pid )
    {
        return BGRT_ST_ENULL;
    }
    else
    {
        bgrt_proc_t * proc;
        bgrt_st_t ret;

        proc = BGRT_PID_TO_PROC( *arg->pid );
        ret  = _bgrt_sync_wait( arg->sync, &proc, arg->block );
        *arg->pid = BGRT_PROC_TO_PID( proc );

        return ret;
    }
}
/**********************************************************************************************
                                      SYNC_PROC_TIMEOUT
**********************************************************************************************/
bgrt_st_t bgrt_sync_proc_timeout( BGRT_PID_T pid )
{
    volatile bgrt_sync_proc_timeout_t scarg;
    scarg.pid = pid;
    return BGRT_SYSCALL_N(SYNC_PROC_TIMEOUT, (void *)&scarg );
}
//========================================================================================
BGRT_SC_SR(SYNC_PROC_TIMEOUT)( bgrt_sync_proc_timeout_t * arg )
{
    return _bgrt_sync_proc_timeout( BGRT_PID_TO_PROC( arg->pid ) );
}
/**********************************************************************************************
                                            USER
**********************************************************************************************/
BGRT_SC_SR(USER)(void (*arg)(void))
{
    arg();
    return BGRT_ST_OK;
}
#endif //_BGRT_SCR_H_
