/**************************************************************************
    BuguRTOS-0.8.x (Bugurt real time operating system)
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
#include "sem.h"

status_t sem_init_isr( sem_t * sem, count_t count )
{
    if(!sem)
    {
        return BGRT_ST_ENULL;
    }
    SYNC_INIT_ISR( sem, PROC_PRIO_LOWEST );
    SPIN_INIT( sem );
    SPIN_LOCK( sem );
    sem->counter = count;
    sem->blocked = (count_t)0;
    SPIN_FREE( sem );
    return BGRT_ST_OK;
}

status_t sem_init( sem_t * sem, count_t count )
{
    status_t ret;
    disable_interrupts();
    ret = sem_init_isr( sem, count );
    enable_interrupts();
    return ret;
}

status_t sem_try_lock( sem_t * sem )
{
    status_t ret = BGRT_ST_ROLL;

    if( !sem )
    {
        return BGRT_ST_ENULL;
    }

    disable_interrupts();
    SPIN_LOCK( sem );

    if( sem->counter )
    {
        sem->counter--;
        ret = BGRT_ST_OK;
    }

    SPIN_FREE( sem );
    enable_interrupts();

    return ret;
}

status_t sem_lock( sem_t * sem )
{
    status_t ret;

    if( !sem )
    {
        return BGRT_ST_ENULL;
    }

    proc_lock();

    disable_interrupts();
    SPIN_LOCK( sem );

    if( sem->counter )
    {
        sem->counter--;
        ret = BGRT_ST_OK;
    }
    else
    {
        sem->blocked++;
        ret = BGRT_ST_ROLL;
    }

    SPIN_FREE( sem );
    enable_interrupts();

    if( ret == BGRT_ST_ROLL )
    {
        ret = SYNC_SLEEP( sem );
    }

    proc_free();
    return ret;
}

status_t sem_free( sem_t * sem )
{
    status_t ret;

    if( !sem )
    {
        return BGRT_ST_ENULL;
    }

    proc_lock();

    disable_interrupts();
    SPIN_LOCK( sem );

    if( sem->blocked )
    {
        sem->blocked--;
        ret = BGRT_ST_ROLL;
    }
    else
    {
        sem->counter++;
        ret = BGRT_ST_OK;
    }

    SPIN_FREE( sem );
    enable_interrupts();

    if( ret == BGRT_ST_ROLL )
    {
        status_t clr_own;
        proc_t * dummy = (proc_t *)0;

        clr_own = SYNC_OWN( sem, 0 );

        SYNC_WAIT( sem, &dummy, 1, ret );// If wait list is empty (race condition), then caller will block.

        if( BGRT_ST_OK != ret )
        {
            goto end;
        }
        SYNC_WAKE( sem,  0, 0, ret );// Now we can wake some process.

        if( BGRT_ST_OK == clr_own )
        {
            SYNC_SET_OWNER( sem, 0 );
        }
    }
end:
    proc_free();
    return ret;
}

status_t sem_free_isr( sem_t * sem )
{
    status_t ret;

    if( !sem )
    {
        return BGRT_ST_ENULL;
    }

    SPIN_LOCK( sem );

    if( ((sync_t *)sem)->owner )
    {
        SPIN_FREE( sem );
        return BGRT_ST_EOWN;
    }

    if( sem->blocked )
    {
        sem->blocked--;
        ret = BGRT_ST_ROLL;
    }
    else
    {
        sem->counter++;
        ret = BGRT_ST_OK;
    }

    SPIN_FREE( sem );

    KERNEL_PREEMPT();

    if( ret == BGRT_ST_ROLL )
    {
        ret = _sync_wake( (sync_t *)sem, (proc_t *)0, (flag_t)0 );// Now we can wake some process.
    }
    return ret;
}
