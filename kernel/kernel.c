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
#include "bugurt.h"

/* ADLINT:SF:[W1076,W0422,W0553,W1073,W0085,W0165] Static with no decls, Unsafe code.*/

#ifdef BGRT_CONFIG_SAVE_POWER
#   define BGRT_SAFE_POWER() BGRT_CONFIG_SAVE_POWER()
#else // BGRT_CONFIG_SAVE_POWER
#   define BGRT_SAFE_POWER() do{}while (0)
#endif// BGRT_CONFIG_SAVE_POWER

static void do_int_scall(bgrt_kblock_t * kblock)
{
    BGRT_USPD_T uspd;
    bgrt_st_t scret;
    (void)kblock;
    //Get system call number storage
    uspd = BGRT_GET_USPD(); /* ADLINT:SL:[W0422] Yes this code is unsafe!*/
    //Do system call
    scret = bgrt_do_syscall(uspd->scnum, uspd->scarg);
    uspd->scret = scret;
    //Clear scnum
    if (BGRT_ST_ROLL != scret)
    {
        uspd->scnum = BGRT_SC_ENUM_END;
    }
}
//Check for pending system call and push it
static void push_pend_scall(bgrt_kblock_t * kblock)
{
    (void)kblock;
    if (BGRT_SC_ENUM_END != BGRT_GET_USPD()->scnum) /* ADLINT:SL:[W0422] Yes this code is unsafe!*/
    {
        do_int_scall(kblock);
    }
}

static void do_int_sched(bgrt_kblock_t * kblock)
{
    (void)kblock;
    if (kblock->tmr_flg)
    {
        kblock->tmr_flg = (bgrt_bool_t)0;
        bgrt_sched_schedule_prologue(&kblock->sched);
    }
    else
    {
        bgrt_sched_reschedule_prologue(&kblock->sched);
    }

    if (BGRT_ST_OK != bgrt_sched_epilogue(&kblock->sched))
    {
        //Do IDLE work if needed
#if defined(BGRT_CONFIG_MP) && (!defined(BGRT_CONFIG_USE_ALB))
#   ifdef BGRT_CONFIG_USE_LLB
        bgrt_sched_lazy_global_load_balancer();
#   endif//BGRT_CONFIG_USE_LLB
#endif//BGRT_CONFIG_MP
        if (BGRT_ST_OK != bgrt_sched_epilogue(&kblock->sched))
        {
            //A scheduler is empty, must do resched
            bgrt_vint_push(&kblock->int_sched, &kblock->vic);
            //May safe power
            BGRT_SAFE_POWER();
        }
        else
        {
            push_pend_scall(kblock);
        }
    }
    else
    {
        push_pend_scall(kblock);
    }
}

void bgrt_kblock_init(bgrt_kblock_t * kblock)
{
    bgrt_vic_init(&kblock->vic);
    bgrt_sched_init(&kblock->sched);
    bgrt_vint_init(&kblock->int_scall, BGRT_PRIO_LOWEST, (bgrt_code_t)do_int_scall, (void *)kblock);
    bgrt_vint_init(&kblock->int_sched, BGRT_PRIO_LOWEST, (bgrt_code_t)do_int_sched, (void *)kblock);
    kblock->tmr_flg = (bgrt_bool_t)0;

    bgrt_vint_push_isr(&kblock->int_sched, &kblock->vic);
}

void bgrt_kblock_main(bgrt_kblock_t * kblock)
{
    while (1)
    {
        bgrt_vic_do_work(&kblock->vic);
        bgrt_switch_to_proc();
    }
}

bgrt_kernel_t bgrt_kernel;// The kernel, it is the one!

void bgrt_kernel_init(void)
{
#ifdef BGRT_CONFIG_MP
    bgrt_cpuid_t i;

    BGRT_SPIN_INIT(&bgrt_kernel.stat);
    BGRT_SPIN_LOCK(&bgrt_kernel.stat);
    //The Kernel initiation!
    for (i = (bgrt_cpuid_t)0; i<(bgrt_cpuid_t)BGRT_MAX_CPU; i++)
    {
        bgrt_stat_init((bgrt_ls_t *)bgrt_kernel.stat.val + i);
    }
    BGRT_SPIN_FREE(&bgrt_kernel.stat);

    for (i = (bgrt_cpuid_t)0; i<(bgrt_cpuid_t)BGRT_MAX_CPU; i++)
    {
        bgrt_kblock_init((bgrt_kblock_t *)bgrt_kernel.kblock + i);
    }
#else
    bgrt_kblock_init((bgrt_kblock_t *)&bgrt_kernel.kblock);
#endif // BGRT_CONFIG_MP
    BGRT_SPIN_INIT(&bgrt_kernel.timer);
    BGRT_SPIN_LOCK(&bgrt_kernel.timer);
    bgrt_kernel.timer.val = (bgrt_tmr_t)0;
    bgrt_kernel.timer.tick = (void(*)(void))0; /* ADLINT:SL:[W0566,W0567] I know. */
    BGRT_SPIN_FREE(&bgrt_kernel.timer);
}
