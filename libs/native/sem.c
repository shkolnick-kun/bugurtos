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
#include "sem.h"

bgrt_st_t bgrt_sem_init_cs(bgrt_sem_t * sem, bgrt_cnt_t count)
{
    if (!sem)
    {
        return BGRT_ST_ENULL;
    }
    BGRT_PRIV_SYNC_INIT(sem, BGRT_PRIO_LOWEST);
    BGRT_SPIN_INIT(sem);
    BGRT_SPIN_LOCK(sem);
    sem->counter = count;
    BGRT_SPIN_FREE(sem);
    return BGRT_ST_OK;
}

bgrt_st_t bgrt_sem_init(bgrt_sem_t * sem, bgrt_cnt_t count)
{
    bgrt_st_t ret;
    BGRT_INT_LOCK();
    ret = bgrt_sem_init_cs(sem, count);
    BGRT_INT_FREE();
    return ret;
}

bgrt_st_t bgrt_sem_try_lock(bgrt_sem_t * sem)
{
    bgrt_st_t ret = BGRT_ST_ROLL;

    if (!sem)
    {
        return BGRT_ST_ENULL;
    }

    BGRT_INT_LOCK();
    BGRT_SPIN_LOCK(sem);

    if (sem->counter)
    {
        sem->counter--;
        ret = BGRT_ST_OK;
    }

    BGRT_SPIN_FREE(sem);
    BGRT_INT_FREE();

    return ret;
}

static bgrt_st_t _sem_lock_fsm(bgrt_va_wr_t* va)
{
    bgrt_st_t ret = BGRT_ST_SCALL;
    bgrt_sem_t       * sem;
    bgrt_flag_t * touch;
    bgrt_flag_t * state;

    BGRT_ASSERT(va, "The #va must not be NULL!");

    sem   = (bgrt_sem_t *)va_arg(va->list, void *);
    touch = (bgrt_flag_t*)va_arg(va->list, void *);
    state = (bgrt_flag_t*)va_arg(va->list, void *);

    BGRT_ASSERT(sem,   "The #sem must not be NULL!");
    BGRT_ASSERT(touch, "The #touch must not be NULL!");
    BGRT_ASSERT(state, "The #state must not be NULL!");

    switch (*state)
    {
    case 0:
    {
        bgrt_priv_proc_lock();

        BGRT_KERNEL_PREEMPT();

        BGRT_SPIN_LOCK(sem);

        if (sem->counter)
        {
            sem->counter--;
            BGRT_SPIN_FREE(sem);

            return BGRT_ST_OK;

        }
        else
        {
            bgrt_priv_sync_touch((bgrt_sync_t *)sem);
            BGRT_SPIN_FREE(sem);
            /*Now goto state 1*/
            *touch = (bgrt_flag_t)1;
            *state = (bgrt_flag_t)1;
        }
    }
    case 1:
    {
        ret = bgrt_priv_sync_sleep((bgrt_sync_t *)sem, touch);
        if (BGRT_ST_ROLL != ret)
        {
            bgrt_priv_proc_free();
        }
        break;
    }
    default:
        break;
    }
    return ret;
}


bgrt_st_t bgrt_sem_lock(bgrt_sem_t * sem)
{
    volatile bgrt_flag_t touch = 0;
    volatile bgrt_flag_t state = 0;

    if (!sem)
    {
        return BGRT_ST_ENULL;
    }
    else
    {
        return BGRT_SYSCALL_NVAR(USER, (void *)(_sem_lock_fsm), (void *)sem, (void *)&touch, (void *)&state);
    }
}

static bgrt_st_t _sem_free_body(bgrt_sem_t *sem)
{
    bgrt_st_t ret;
    /*Now we can wake some process.*/
    ret = bgrt_priv_sync_wake((bgrt_sync_t *)sem, (bgrt_proc_t *)0, (bgrt_flag_t)0);
    if (BGRT_ST_EEMPTY == ret)
    {
        sem->counter++;
        ret = BGRT_ST_OK;
    }
    return ret;
}

bgrt_st_t _sem_free_payload(bgrt_va_wr_t* va)
{
    bgrt_sem_t *sem;
    bgrt_st_t ret;

    BGRT_ASSERT(va, "The #va must not be NULL!");

    sem   = (bgrt_sem_t *)va_arg(va->list, void *);

    BGRT_ASSERT(sem, "The #sem must not be NULL!");

    BGRT_SPIN_LOCK(sem);
    ret = _sem_free_body(sem);
    BGRT_SPIN_FREE(sem);

    return ret;
}

bgrt_st_t bgrt_sem_free(bgrt_sem_t * sem)
{
    if (!sem)
    {
        return BGRT_ST_ENULL;
    }
    else
    {
        return BGRT_SYSCALL_NVAR(USER, (void *)(_sem_free_payload), (void *)sem);
    }
}

bgrt_st_t bgrt_sem_free_cs(bgrt_sem_t * sem)
{
    bgrt_st_t ret;

    if (!sem)
    {
        return BGRT_ST_ENULL;
    }

    BGRT_SPIN_LOCK(sem);
    /*Check owner*/
    if (((bgrt_sync_t *)sem)->owner)
    {
        ret = BGRT_ST_EOWN;
    }
    else
    {
        _sem_free_body(sem);
    }
    BGRT_SPIN_FREE(sem);

    return ret;
}
