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
#include "bugurt.h"

/* ADLINT:SF:[W0422] NULL */

void bgrt_vint_init(bgrt_vint_t * vint, bgrt_prio_t prio, bgrt_code_t func, void * arg)
{
    BGRT_ASSERT(vint, "The #vint must not be NULL!");
    BGRT_ASSERT(func, "The #func must not be NULL!");
    BGRT_ASSERT(arg,  "The #arg must not be NULL!");

    bgrt_pitem_init((bgrt_pitem_t *)vint, prio);
    vint->func = func;
    vint->arg = arg;
}

void bgrt_vic_init(bgrt_vic_t * vic)
{
    BGRT_ASSERT(vic, "The #vic must not be NULL!");

    bgrt_xlist_init((bgrt_xlist_t *)vic);
    /*Must be LOWER, than lowest valid priority*/
    vic->prio = BGRT_PRIO_LOWEST + 1 ; /* ADLINT:SL:[W0165] signed/unsigned*/
}

bgrt_st_t bgrt_vint_push_isr(bgrt_vint_t * vint, bgrt_vic_t * vic)
{
    BGRT_ASSERT(vint, "The #vint must not be NULL!");
    BGRT_ASSERT(vic,  "The #vic must not be NULL!");

    if (((bgrt_pitem_t *)vint)->list)
    {
        return BGRT_ST_EAGAIN;
    }
    else
    {
        bgrt_pitem_insert((bgrt_pitem_t *)vint, (bgrt_xlist_t *)vic);
        return BGRT_ST_OK;
    }
}

bgrt_st_t bgrt_vint_push(bgrt_vint_t * vint, bgrt_vic_t * vic)
{
    bgrt_st_t ret;
    BGRT_ASSERT(vint, "The #vint must not be NULL!");
    BGRT_ASSERT(vic,  "The #vic must not be NULL!");
    /*Everything is done on local CPU core, just disable interrupts.*/
    BGRT_VINT_CS_START();
    /*Insert*/
    ret = bgrt_vint_push_isr(vint, vic);
    /*May enable interrupts*/
    BGRT_VINT_CS_END();
    return ret;
}

static bgrt_vint_t * _vint_pop(bgrt_vic_t * vic, bgrt_prio_t lprio)
{
    bgrt_pitem_t * work;
    BGRT_ASSERT(vic,  "The #vic must not be NULL!");
    /*Everything is done on local CPU core, just disable interrupts.*/
    BGRT_VINT_CS_START();
    /*Get list head*/
    work = (bgrt_pitem_t *)bgrt_xlist_head((bgrt_xlist_t *)vic);
    /*Is there any work?*/
    if (work)
    {
        /*Do only higher priority work...*/
        if (work->prio < lprio)
        {
            bgrt_pitem_cut(work);
        }
        else
        {
            work = (bgrt_pitem_t *)0;/* ADLINT:SL:[W0567] type conversion*/
        }
    }
    /*May enable interrupts*/
    BGRT_VINT_CS_END();
    /*We must return virtual interrupt*/
    return (bgrt_vint_t *)work;
}

bgrt_st_t bgrt_vic_iterator(bgrt_vic_t * vic)
{
    bgrt_prio_t lprio;
    bgrt_vint_t * work;

    BGRT_ASSERT(vic,  "The #vic must not be NULL!");

    lprio = vic->prio;
    work = _vint_pop(vic,lprio);
    /*Is there any work?*/
    if (work)
    {
        /*func is used twice, so...*/
        bgrt_code_t func;
        func = work->func;
        /*Is it valid?*/
        if (func)
        {
            /*Remember current priority*/
            vic->prio = ((bgrt_pitem_t *)work)->prio;
            /*Do work.*/
            func(work->arg);
            /*A work is done, remind last priority.*/
            vic->prio = lprio;
        }
        return BGRT_ST_ROLL;
    }
    return BGRT_ST_OK; /* ADLINT:SL:[W0605] signed/unsigned*/
}

void bgrt_vic_do_work(bgrt_vic_t * vic)
{
    BGRT_ASSERT(vic,  "The #vic must not be NULL!");
    //Do some pending work...
    while (BGRT_ST_ROLL == bgrt_vic_iterator(vic)); /* ADLINT:SL:[W0414,W0627,W0085]*/
}
