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

/* ADLINT:SF:[W0025,W0026,W0422] syscall_table.h, NULL */

/*System call SR declarations*/
#define BGRT_SC_TBL_ENTRY(syscall,arg) BGRT_SC_SR(syscall, arg);
#include <syscall_table.h>
#undef  BGRT_SC_TBL_ENTRY

/*User may write his own system calls*/
#ifdef BGRT_CONFIG_CUSTOM_SYSCALL
#   include <syscall_routines.h>
#else
#   include <default/syscall_routines.h> /*Default system call handlers*/
#endif/*BGRT_CONFIG_USER_SYSCALL*/

/**********************************************************************************************
                                      MANDATORY THINGS!!!
**********************************************************************************************/
static bgrt_st_t _do_nothing_sr(void * arg)
{
    (void)arg; /* ADLINT:SL:[W0085] no effect*/
    return BGRT_ST_SCALL;
}
/**********************************************************************************************
                                       PROC_TERMINATE
**********************************************************************************************/
/*Terminate a process after pmain return.*/
void bgrt_proc_terminate(void)
{
    BGRT_SYSCALL_N(PROC_TERMINATE, (void *)0); /* ADLINT:SL:[W0567,W1059,W1073] conversion*/
}
/*====================================================================================*/
BGRT_SC_SR(PROC_TERMINATE, void * arg)
{
    (void)arg; /* ADLINT:SL:[W0085] no effect*/
    bgrt_priv_proc_terminate();
    return BGRT_ST_OK;
}
/**********************************************************************************************
                                         PROC_YIELD
**********************************************************************************************/
bgrt_bool_t bgrt_sched_proc_yield(void)
{
    volatile bgrt_bool_t ret;
    BGRT_SYSCALL_N(SCHED_PROC_YIELD, (void *)&ret); /* ADLINT:SL:[W0459,W0021,W1059,W1073] conversion of ret, enum, result discarded*/
    return ret;
}
/*====================================================================================*/
BGRT_SC_SR(SCHED_PROC_YIELD, void * arg)
{
    bgrt_bool_t ret;
    ret = bgrt_priv_sched_proc_yield();
#ifdef BGRT_CONFIG_SAVE_POWER
    if (ret)
    {
        BGRT_CONFIG_SAVE_POWER();
    }
#endif /* BGRT_CONFIG_SAVE_POWER */
    *(bgrt_bool_t *)arg = ret;
    return BGRT_ST_OK;
}

BGRT_SC_TBL(syscall_handler[])= /* ADLINT:SL:[W0117] extern linkage*/
{
#   define BGRT_SC_TBL_ENTRY(syscall,arg) (bgrt_scsr_t)(BGRT_SC_SR_NAME(syscall)),
#   include <syscall_table.h>
#   undef  BGRT_SC_TBL_ENTRY
    _do_nothing_sr
};

#ifdef BGRT_CONFIG_SYSCALL_CHECK
#   define BGRT_SYSCALL_CHECK BGRT_CONFIG_SYSCALL_CHECK
#else  /*BGRT_CONFIG_SYSCALL_CHECK*/
/*Default syscall sanity check macro*/
#   define BGRT_SYSCALL_CHECK(n,a) ((bgrt_syscall_t)BGRT_SC_ENUM_END <= n)
#endif /*BGRT_CONFIG_SYSCALL_CHECK*/

bgrt_st_t bgrt_priv_do_syscall(bgrt_syscall_t syscall_num, void * syscall_arg)
{
    /*Sanity check*/
    if (BGRT_SYSCALL_CHECK(syscall_num, syscall_arg))
    {
        /*Fail*/
        return BGRT_ST_SCALL;
    }
    else
    {
        /*Syscall processing*/
        return (BGRT_SC_TBL_READ(syscall_handler[syscall_num]))(syscall_arg); /* ADLINT:SL:[W0147,W0644] type conversion,void val */
    }
}
/*Variadic version of bgrt_syscall*/
bgrt_st_t bgrt_syscall_var(bgrt_syscall_t num, ...)
{
    bgrt_va_wr_t varg;
    bgrt_st_t ret;

    va_start(varg.list, num);               /* ADLINT:SL:[W0459,W0085] */
    ret = bgrt_syscall(num, (void *)&varg); /* ADLINT:SL:[W0459,W0085] */
    va_end(varg.list);                      /* ADLINT:SL:[W0085] no side effect*/

    return ret;
}
