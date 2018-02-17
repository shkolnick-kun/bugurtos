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

/* ADLINT:SF:[W1071,W1052,W0165,W0422] Multiple return, OVF, out of range access */

#ifdef BGRT_CONFIG_TEST
static void _cnt_panic(void)
{
    while (1);
}
#   define BGRT_CNT_PANIC() _cnt_panic()
#else  /*BGRT_CONFIG_TEST*/
#   ifdef BGRT_CONFIG_PANIC
#       define BGRT_CNT_PANIC() BGRT_CONFIG_PANIC()
#   else
#       define BGRT_CNT_PANIC() do{}while (0)
#   endif /*BGRT_CONFIG_PANIC*/
#endif /*BGRT_CONFIG_TEST*/

bgrt_cnt_t bgrt_cnt_inc(bgrt_cnt_t val)
{
    if (BGRT_CONFIG_CNT_MAX > val)
    {
        return val + (bgrt_cnt_t)1;
    }
    else
    {
        BGRT_CNT_PANIC();
        return BGRT_CONFIG_CNT_MAX;
    }
}

bgrt_cnt_t bgrt_cnt_dec(bgrt_cnt_t val)
{
    if (val)
    {
        return val - (bgrt_cnt_t)1;
    }
    else
    {
        BGRT_CNT_PANIC();
        return (bgrt_cnt_t)0;
    }
}

bgrt_cnt_t bgrt_cnt_add(bgrt_cnt_t a, bgrt_cnt_t b)
{
    if ((BGRT_CONFIG_CNT_MAX - a) > b)
    {
        return a + b;
    }
    else
    {
        BGRT_CNT_PANIC();
        return BGRT_CONFIG_CNT_MAX;
    }
}

bgrt_cnt_t bgrt_cnt_sub(bgrt_cnt_t a, bgrt_cnt_t b)
{
    if (a >= b)
    {
        return a - b;
    }
    else
    {
        BGRT_CNT_PANIC();
        return (bgrt_cnt_t)0;
    }
}

/* bgrt_pcounter_t methods*/
/* Initiation*/
void bgrt_pcounter_init(bgrt_pcounter_t * pcounter)
{
    bgrt_prio_t p;
    BGRT_ASSERT(pcounter, "The #pcounter must not be NULL!");
    pcounter->map = (bgrt_map_t)0;
    for (p = 0; p < (bgrt_map_t)BGRT_BITS_IN_INDEX_T; p++)
    {
        pcounter->counter[p] = (bgrt_cnt_t)0;    /* ADLINT:SL:[W0705] Out of range access!*/
    }
}
/* Increment*/
void bgrt_pcounter_inc(bgrt_pcounter_t * pcounter, bgrt_prio_t prio)
{
    BGRT_ASSERT(pcounter, "The #pcounter must not be NULL!");
    BGRT_CNT_INC(pcounter->counter[prio]);      /* ADLINT:SL:[W0705] Out of range access!*/
    pcounter->map |= ((bgrt_map_t)1)<<prio; /* ADLINT:SL:[W0572] Drop bits!*/
}
/* Decrement*/
bgrt_map_t bgrt_pcounter_dec(bgrt_pcounter_t * pcounter, bgrt_prio_t prio)
{
    bgrt_map_t mask;

    BGRT_ASSERT(pcounter, "The #pcounter must not be NULL!");

    mask = ((bgrt_map_t)1)<<prio;

    BGRT_CNT_DEC(pcounter->counter[prio]);  /* ADLINT:SL:[W0705] Out of range access!*/

    if (pcounter->counter[prio] == (bgrt_cnt_t)0) /* ADLINT:SL:[W0705] Out of range access!*/
    {
        pcounter->map &= ~mask; /* ADLINT:SL:[W0578] type conversions */
    }
    return pcounter->map & mask; /* ADLINT:SL:[W0272,W0301] */
}
/* Multiple increment*/
void bgrt_pcounter_plus(bgrt_pcounter_t * pcounter, bgrt_prio_t prio, bgrt_cnt_t count)
{
    BGRT_ASSERT(pcounter, "The #pcounter must not be NULL!");

    pcounter->map |= ((bgrt_map_t)1)<<prio;  /* ADLINT:SL:[W0572] */

    BGRT_CNT_ADD(pcounter->counter[prio], count); /* ADLINT:SL:[W0705] Out of range access!*/
}
/* Multiple decrement*/
bgrt_map_t bgrt_pcounter_minus(bgrt_pcounter_t * pcounter, bgrt_prio_t prio, bgrt_cnt_t count)
{
    bgrt_map_t mask;

    BGRT_ASSERT(pcounter, "The #pcounter must not be NULL!");

    mask = ((bgrt_map_t)1)<<prio;

    BGRT_CNT_SUB(pcounter->counter[prio], count); /* ADLINT:SL:[W0705] Out of range access!*/

    if ((bgrt_cnt_t)0 == pcounter->counter[prio])/* ADLINT:SL:[W0705] Out of range access!*/
    {
        pcounter->map &= ~mask; /* ADLINT:SL:[W0578] type conversions */
    }
    return pcounter->map & mask; /* ADLINT:SL:[W0272,W0301] */
}
