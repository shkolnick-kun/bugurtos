/**************************************************************************
    BuguRTOS-4.0.x (Bugurt real time operating system)
    Copyright (C) 2018 anonimous

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
#ifndef BGRT_SCR_H
#define BGRT_SCR_H
#include <bugurt.h>
//BGRT_CDECL_BEGIN
/* ADLINT:SF:[W0456,W0567,W0644,W0459,W0085,W0073,W0422] extern func, valist */

/**********************************************************************************************
                                  System call handlers !!!
***********************************************************************************************
                                       PROC_RUN
**********************************************************************************************/
BGRT_SC_SR(PROC_RUN, void * arg)
{
    return bgrt_priv_proc_run(BGRT_PID_TO_PROC((BGRT_PID_T)arg));
}
/**********************************************************************************************
                                       PROC_RESTART
**********************************************************************************************/
BGRT_SC_SR(PROC_RESTART, void * arg)
{
    return bgrt_priv_proc_restart(BGRT_PID_TO_PROC((BGRT_PID_T)arg));
}
/**********************************************************************************************
                                         PROC_STOP
**********************************************************************************************/
BGRT_SC_SR(PROC_STOP, void * arg)
{
    return bgrt_priv_proc_stop(BGRT_PID_TO_PROC((BGRT_PID_T)arg));
}
/**********************************************************************************************
                                       PROC_SELF_STOP
**********************************************************************************************/
BGRT_SC_SR(PROC_SELF_STOP, void * arg)
{
    (void)arg;
    bgrt_priv_proc_self_stop();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                         PROC_LOCK
**********************************************************************************************/
BGRT_SC_SR(PROC_LOCK, void * arg)
{
    (void)arg;
    bgrt_priv_proc_lock();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                         PROC_FREE
**********************************************************************************************/
BGRT_SC_SR(PROC_FREE,  void * arg)
{
    (void)arg;
    bgrt_priv_proc_free();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                    PROC_RESET_WATCHDOG
**********************************************************************************************/
BGRT_SC_SR(PROC_RESET_WATCHDOG,  void * arg)
{
    (void)arg;
    bgrt_priv_proc_reset_watchdog();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                       PROC_GET_PRIO
**********************************************************************************************/
BGRT_SC_SR(PROC_GET_PRIO,  bgrt_va_wr_t * va)
{
    bgrt_prio_t * prio_ptr;
    BGRT_PID_T pid;

    prio_ptr = (bgrt_prio_t *)va_arg(va->list, void *); /* ADLINT:SL:[W0644] valist */
    pid = (BGRT_PID_T)va_arg(va->list, void *);

    *prio_ptr = bgrt_priv_proc_get_prio(BGRT_PID_TO_PROC(pid));
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                       PROC_SET_PRIO
**********************************************************************************************/
BGRT_SC_SR(PROC_SET_PRIO,  bgrt_va_wr_t * va)
{
    BGRT_PID_T pid;

    pid = (BGRT_PID_T)va_arg(va->list, void *);

    bgrt_priv_proc_set_prio(BGRT_PID_TO_PROC(pid), (bgrt_prio_t)va_arg(va->list, int));
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                        PROC_GET_ID
**********************************************************************************************/
BGRT_SC_SR(PROC_GET_ID,  void * arg)
{
    bgrt_proc_t * curr_proc;
    /*Do NOT optimize this as BGRT_PROC_TO_PID may call bgrt_curr_proc more than one time!!!*/
    curr_proc = bgrt_curr_proc();
    *(BGRT_PID_T *)arg = BGRT_PROC_TO_PID(curr_proc);
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                      SYNC_SET_OWNER
**********************************************************************************************/
BGRT_SC_SR(SYNC_SET_OWNER,  bgrt_va_wr_t * va)
{
    bgrt_sync_t * sync;
    BGRT_PID_T pid; /* BGRT_PID_TO_PROC macro must get only the value!!! */

    sync = (bgrt_sync_t *)va_arg(va->list, void *);
    pid = (BGRT_PID_T)va_arg(va->list, void *);

    return bgrt_priv_sync_set_owner(sync, BGRT_PID_TO_PROC(pid));
}
/**********************************************************************************************
                                       SYNC_GET_OWNER
**********************************************************************************************/
BGRT_SC_SR(SYNC_GET_OWNER,  bgrt_va_wr_t * va)
{
    BGRT_PID_T * pid;
    bgrt_proc_t * proc;

    pid = (BGRT_PID_T *)va_arg(va->list, void *);
    /*Do NOT optimize this as BGRT_PROC_TO_PID may call va_arg more than one time!!!*/
    proc = bgrt_priv_sync_get_owner((bgrt_sync_t *)va_arg(va->list, void *));
    *pid = BGRT_PROC_TO_PID(proc);
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                          SYNC_OWN
**********************************************************************************************/
BGRT_SC_SR(SYNC_OWN,  bgrt_va_wr_t * va)
{
    bgrt_sync_t * sync;
    sync = (bgrt_sync_t *)va_arg(va->list, void *);
    return bgrt_priv_sync_own(sync, (bgrt_flag_t)va_arg(va->list, int));
}
/**********************************************************************************************
                                        SYNC_TOUCH
**********************************************************************************************/
BGRT_SC_SR(SYNC_TOUCH,  void * arg)
{
    return bgrt_priv_sync_touch((bgrt_sync_t *)arg);
}
/**********************************************************************************************
                                         SYNC_SLEEP
**********************************************************************************************/
BGRT_SC_SR(SYNC_SLEEP,  bgrt_va_wr_t * va) /* ADLINT:SL:[W0031] not used*/
{
    va_list param;
    bgrt_sync_t * sync;
    bgrt_flag_t * touch;

    va_copy(param, va->list);
    sync  = (bgrt_sync_t *)va_arg(param, void *);
    touch = (bgrt_flag_t *)va_arg(param, void *);
    va_end(param);

    return bgrt_priv_sync_sleep(sync, touch);
}
/**********************************************************************************************
                                        SYNC_WAKE
**********************************************************************************************/
BGRT_SC_SR(SYNC_WAKE,  bgrt_va_wr_t * va) /* ADLINT:SL:[W0031] not used*/
{
    va_list param;
    bgrt_sync_t * sync;
    BGRT_PID_T pid;
    bgrt_flag_t chown;

    va_copy(param, va->list);
    sync  = (bgrt_sync_t *)va_arg(param, void *);
    pid   = (BGRT_PID_T  )va_arg(param, void *);
    chown = (bgrt_flag_t )va_arg(param, int  );
    va_end(param);

    return bgrt_priv_sync_wake(sync, BGRT_PID_TO_PROC(pid), chown);
}
/**********************************************************************************************
                                        SYNC_WAIT
**********************************************************************************************/
BGRT_SC_SR(SYNC_WAIT, bgrt_va_wr_t * va) /* ADLINT:SL:[W0031] not used*/
{
    va_list       param;
    bgrt_sync_t  *sync;
    BGRT_PID_T   *pid;
    bgrt_flag_t   block;

    va_copy(param, va->list);
    sync  = (bgrt_sync_t *)va_arg(param, void *);
    pid   = (BGRT_PID_T  *)va_arg(param, void *);
    block = (bgrt_flag_t )va_arg(param, int  );
    va_end(param);

    if (!pid)
    {
        return BGRT_ST_ENULL;
    }
    else
    {
        bgrt_proc_t * proc;
        bgrt_st_t ret;
        /*Do NOT optimize this as BGRT_PROC_TO_PID may call va_arg more than one time!!!*/
        proc = BGRT_PID_TO_PROC(*pid);
        ret  = bgrt_priv_sync_wait(sync, &proc, block);
        *pid = BGRT_PROC_TO_PID(proc);

        return ret;
    }
}
/**********************************************************************************************
                                      SYNC_PROC_TIMEOUT
**********************************************************************************************/
BGRT_SC_SR(SYNC_PROC_TIMEOUT, void * arg)
{
    return bgrt_priv_sync_proc_timeout(BGRT_PID_TO_PROC((BGRT_PID_T)arg));
}
/**********************************************************************************************
                                            USER
**********************************************************************************************/
typedef bgrt_st_t (*bgrt_user_func_t)(bgrt_va_wr_t*);

BGRT_SC_SR(USER, bgrt_va_wr_t* va)/* ADLINT:SL:[W0031] va is used!!!*/
{
    bgrt_user_func_t func;
    bgrt_va_wr_t param;
    bgrt_st_t ret;

    va_copy(param.list, va->list);
    func = (bgrt_user_func_t)va_arg(param.list, void *);
    ret = (*func)(&param);
    va_end(param.list);

    return ret;
}
//BGRT_CDECL_BEGIN
#endif /*BGRT_SCR_H*/
