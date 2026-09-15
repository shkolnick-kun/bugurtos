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
#include "cond.h"

bgrt_st_t bgrt_cond_init_cs(bgrt_cond_t * cond)
{
    return BGRT_PRIV_SYNC_INIT(cond, BGRT_PRIO_LOWEST);
}

bgrt_st_t bgrt_cond_init(bgrt_cond_t * cond)
{
    bgrt_st_t ret;
    BGRT_INT_LOCK();
    ret = bgrt_cond_init_cs(cond);
    BGRT_INT_FREE();
    return ret;
}

/*TODO: Try to reduce number of system calls ???*/
#define _CW_FSM_STATE_BEGIN    (0)
#define _CW_FSM_STATE_MXT_FREE (1)
#define _CW_FSM_STATE_CND_WAIT (2)
#define _CW_FSM_STATE_PR_LOCK  (3)
#define _CW_FSM_STATE_MTX_LOCK (4)
#define _CW_FSM_STATE_MTX_WAIT (5)
#define _CW_FSM_STATE_END      (6)

static bgrt_st_t _cond_wait_fsm(bgrt_va_wr_t* va)
{
    bgrt_st_t ret = BGRT_ST_SCALL;
    bgrt_sync_t  * cond;
    bgrt_sync_t  * mutex;
    bgrt_flag_t  * state;
    bgrt_flag_t  * touch;

    BGRT_ASSERT(va, "The #va must not be NULL!");

    cond   = (bgrt_sync_t *)va_arg(va->list, void *);
    mutex  = (bgrt_sync_t *)va_arg(va->list, void *);
    state  = (bgrt_flag_t *)va_arg(va->list, void *);
    touch  = (bgrt_flag_t *)va_arg(va->list, void *);

    BGRT_ASSERT(cond,  "The #cond must not be NULL!");
    BGRT_ASSERT(mutex, "The #mutex must not be NULL!");
    BGRT_ASSERT(state, "The #state must not be NULL!");
    BGRT_ASSERT(touch, "The #state must not be NULL!");

    switch (*state)
    {
    case _CW_FSM_STATE_BEGIN:
    {
        bgrt_priv_proc_lock();

        ret = bgrt_priv_sync_touch(cond);
        if (BGRT_ST_OK != ret)
        {
            return ret;
        }
        *state = _CW_FSM_STATE_MXT_FREE;
        return BGRT_ST_ROLL;
    }
    case _CW_FSM_STATE_MXT_FREE:
    {
        /*Free mutex, goto next state on success*/
        ret = bgrt_priv_sync_wake(mutex, (bgrt_proc_t *)0, 1);
        switch(ret)
        {
        case BGRT_ST_EEMPTY:
        case BGRT_ST_OK:
        {
            /*May stop calling process.*/
            bgrt_priv_proc_free();
            *state = _CW_FSM_STATE_CND_WAIT;
            *touch = 1;
            return BGRT_ST_ROLL;
        }
        case BGRT_ST_EOWN:
        {
            bgrt_priv_proc_free(); /*Will continue to default*/
        }
        default:
        {
            bgrt_priv_sync_untouch(cond); /*Will continue to BGRT_ST_ROLL*/
        }
        case BGRT_ST_ROLL:
        {
            return ret;
        }
        }
    }
    case _CW_FSM_STATE_CND_WAIT:
    {
        ret = bgrt_priv_sync_sleep(cond, touch);
        if (BGRT_ST_ROLL != ret)
        {
            bgrt_priv_proc_free();
        }
        if (BGRT_ST_OK == ret)
        {
            *state  = _CW_FSM_STATE_PR_LOCK;
            return BGRT_ST_ROLL;
        }
        return ret;
    }
    case _CW_FSM_STATE_PR_LOCK:
    {
        bgrt_priv_proc_lock();
        *state = _CW_FSM_STATE_MTX_LOCK;
        *touch = 1;
        return BGRT_ST_ROLL;
    }
    case _CW_FSM_STATE_MTX_LOCK:
    {

        ret = bgrt_priv_sync_own(mutex, touch);
        if (BGRT_ST_EOWN == ret)
        {
            *state = _CW_FSM_STATE_MTX_WAIT;
            return BGRT_ST_ROLL;
        }
        *state = _CW_FSM_STATE_END;
        return ret;
    }
    case _CW_FSM_STATE_MTX_WAIT:
    {

        ret = bgrt_priv_sync_sleep(mutex, touch);
        if (BGRT_ST_ROLL != ret)
        {
            if (BGRT_ST_OK != ret)
            {
                bgrt_priv_proc_free();
            }
            *state = _CW_FSM_STATE_END;
        }
        return ret;
    }
    default:
    {
        return BGRT_ST_SCALL;
    }
    }
}

bgrt_st_t bgrt_cond_wait(bgrt_cond_t * cond, bgrt_mtx_t * mutex)
{
    bgrt_st_t ret = BGRT_ST_ROLL;

    if ((!mutex) || (!cond))
    {
        return BGRT_ST_ENULL;
    }

    BGRT_PROC_LOCK(); /*Don't stop caller until wakeup!*/

    BGRT_SYNC_TOUCH(cond);

    ret = bgrt_mtx_free(mutex);

    if (BGRT_ST_OK != ret)
    {
        BGRT_SYNC_UNTOUCH(cond);
        BGRT_PROC_FREE(); /*May stop as error occurred!*/
    }
    else
    {
        bgrt_flag_t touch = 1;

        ret = BGRT_SYNC_SLEEP(cond, &touch);
        BGRT_PROC_FREE(); /*Now may stop!*/

        if (BGRT_ST_OK != ret)
        {
            return ret;
        }

        ret = bgrt_mtx_lock(mutex);
    }

    return ret;
}

static inline bgrt_st_t bgrt_priv_cond_signal(bgrt_cond_t * cond)
{
    return BGRT_SYNC_WAKE(cond, BGRT_PID_NOTHING, 0);
}

bgrt_st_t bgrt_cond_signal(bgrt_cond_t * cond)
{
    bgrt_st_t ret;

    ret = bgrt_priv_cond_signal(cond);

    return ret;
}

bgrt_st_t bgrt_cond_broadcast(bgrt_cond_t * cond)
{
    bgrt_cnt_t cwake = (bgrt_cnt_t)0;
    bgrt_st_t ret = BGRT_ST_ROLL;

    for (ret = BGRT_ST_OK; BGRT_ST_OK == ret; ret = bgrt_priv_cond_signal(cond))
    {
        cwake++;
    }
    if (cwake && (BGRT_ST_EEMPTY == ret))
    {
        ret = BGRT_ST_OK;
    }
    return ret;
}
