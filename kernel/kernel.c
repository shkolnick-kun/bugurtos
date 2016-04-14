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

#ifdef BGRT_CONFIG_SAVE_POWER
#   define BGRT_SAFE_POWER() BGRT_CONFIG_SAVE_POWER()
#else // BGRT_CONFIG_SAVE_POWER
#   define BGRT_SAFE_POWER() do{}while(0)
#endif// BGRT_CONFIG_SAVE_POWER

static void do_int_scall( bgrt_kblock_t * kblock )
{
    bgrt_syscall_t * scnum;
    //Get system call number storage
    scnum = bgrt_get_scnum();
    //Do system call
    if( BGRT_ST_ROLL != bgrt_do_syscall( *scnum, bgrt_get_scarg() ) )
    {
        //Clear system call number ()
        *scnum = (bgrt_syscall_t)0;
    }
}

static void do_int_sched( bgrt_kblock_t * kblock )
{
    if( kblock->tmr_flg )
    {
        kblock->tmr_flg = (bgrt_bool_t)0;
        bgrt_sched_schedule_prologue( &kblock->sched );
    }
    else
    {
        bgrt_sched_reschedule_prologue( &kblock->sched );
    }

    if( BGRT_ST_OK != bgrt_sched_epilogue( &kblock->sched ) )
    {
        //Do IDLE work if needed
#if defined(BGRT_CONFIG_MP) && (!defined(BGRT_CONFIG_USE_ALB))
#   ifdef BGRT_CONFIG_USE_LGLB
        bgrt_sched_lazy_global_load_balancer();
#   else//BGRT_CONFIG_USE_LGLB
        bgrt_sched_lazy_local_load_balancer();
#   endif//BGRT_CONFIG_USE_LGLB
#endif//BGRT_CONFIG_MP
        if( BGRT_ST_OK != bgrt_sched_epilogue( &kblock->sched ) )
        {
            //A scheduler is empty, must do reshed
            bgrt_vint_push( &kblock->int_sched, &kblock->vic );
            //May safe power
            BGRT_SAFE_POWER();
        }
    }
    else
    {
        if( *bgrt_get_scnum() )
        {
            bgrt_vint_push( &kblock->int_scall, &kblock->vic );
        }
    }
}

extern void new_bgrt_sched_init( bgrt_sched_t * sched );

void bgrt_kblock_init( bgrt_kblock_t * kblock )
{
    bgrt_vic_init( &kblock->vic );
    ///!!!!!!!!!!!!!!!!!!!!
    new_bgrt_sched_init( &kblock->sched ); ///TODO: replace new_bgrt_sched_init with bgrt_sched_init!!!
    ///!!!!!!!!!!!!!!!!!!!!
    bgrt_vint_init( &kblock->int_scall, BGRT_PRIO_LOWEST, (bgrt_code_t)do_int_scall, (void *)kblock );
    bgrt_vint_init( &kblock->int_sched, BGRT_PRIO_LOWEST, (bgrt_code_t)do_int_sched, (void *)kblock );
    kblock->tmr_flg = (bgrt_bool_t)0;
}

void bgrt_kblock_main( bgrt_kblock_t * kblock )
{
    while(1)
    {
        bgrt_vic_do_work( &kblock->vic );
        bgrt_switch_to_proc();
    }
}

bgrt_kernel_t bgrt_kernel;// The kernel, it is the one!

#ifndef BGRT_CONFIG_USER_IDLE
WEAK void bgrt_idle_main(void * arg)
{
    while(1)
    {
#   ifdef BGRT_CONFIG_SAVE_POWER
        if( bgrt_sched_proc_yeld() )BGRT_CONFIG_SAVE_POWER();
#   else // BGRT_CONFIG_SAVE_POWER
        bgrt_sched_proc_yeld();
#   endif // BGRT_CONFIG_SAVE_POWER
    }
}
#endif // BGRT_CONFIG_USER_IDLE
///TODO:Remove old kernel.
#ifndef BGRT_CONFIG_NEW_KERNEL
void bgrt_kernel_init(void)
{
#   ifdef BGRT_CONFIG_MP
    bgrt_cpuid_t i;

    BGRT_SPIN_INIT( &bgrt_kernel.stat );
    BGRT_SPIN_LOCK( &bgrt_kernel.stat );
    //The Kernel initiation!
    for( i = (bgrt_cpuid_t)0; i<(bgrt_cpuid_t)BGRT_MAX_CPU; i++ )
    {
        _bgrt_proc_init(
            bgrt_kernel.idle + i, //A bgrt_kernel.idle[i] process
            bgrt_idle_main, // main
            (bgrt_code_t)0, // none
            (bgrt_code_t)0, // none
            (void *)0, // null
            0,         // null, will be replaced with kernel stack pointer.
            BGRT_PROC_PRIO_LOWEST,// idle has lowest priority
            (bgrt_tmr_t)1,// Smallest time slice
            (bgrt_bool_t)0,// idle is not RT
            ((bgrt_aff_t)1)<<i // Disable to other cores!
        );
        bgrt_kernel.idle[i].core_id = i;
        bgrt_stat_init( (bgrt_ls_t *)bgrt_kernel.stat.val + i );
        bgrt_sched_init( (bgrt_sched_t *)bgrt_kernel.sched + i, (bgrt_proc_t *)bgrt_kernel.idle + i );
    }
    BGRT_SPIN_FREE( &bgrt_kernel.stat );
#   else
    _bgrt_proc_init(
        &bgrt_kernel.idle, //The bgrt_kernel.idle process.
        bgrt_idle_main, // pmain
        (bgrt_code_t)0, // none
        (bgrt_code_t)0, // none
        (void *)0, // null
        0,         // null, will be replaced with kernel stack pointer.
        BGRT_PROC_PRIO_LOWEST, // idle has lowest priority
        (bgrt_tmr_t)1,//Smallest time slice
        (bgrt_bool_t)0// Idle is not RT
    );
    sched_init( (sched_t *)&kernel.sched, (proc_t *)&kernel.idle );
#   endif // BGRT_CONFIG_MP
    BGRT_SPIN_INIT( &bgrt_kernel.timer );
    BGRT_SPIN_LOCK( &bgrt_kernel.timer );
    bgrt_kernel.timer.val = (bgrt_tmr_t)0;
    bgrt_kernel.timer.tick = (void(*)(void))0;
    BGRT_SPIN_FREE( &bgrt_kernel.timer );
}
#else //BGRT_CONFIG_NEW_KERNEL
void bgrt_kernel_init(void)
{
#   ifdef BGRT_CONFIG_MP
    bgrt_cpuid_t i;

    BGRT_SPIN_INIT( &bgrt_kernel.stat );
    BGRT_SPIN_LOCK( &bgrt_kernel.stat );
    //The Kernel initiation!
    for( i = (bgrt_cpuid_t)0; i<(bgrt_cpuid_t)BGRT_MAX_CPU; i++ )
    {
        bgrt_stat_init( (bgrt_ls_t *)bgrt_kernel.stat.val + i );
    }
    BGRT_SPIN_FREE( &bgrt_kernel.stat );

    for( i = (bgrt_cpuid_t)0; i<(bgrt_cpuid_t)BGRT_MAX_CPU; i++ )
    {
        bgrt_kblock_init( (bgrt_kblock_t *)bgrt_kernel.kblock + i );
    }
#   else
    bgrt_kblock_init( (bgrt_kblock_t *)&bgrt_kernel.kblock );
#   endif // BGRT_CONFIG_MP
    BGRT_SPIN_INIT( &bgrt_kernel.timer );
    BGRT_SPIN_LOCK( &bgrt_kernel.timer );
    bgrt_kernel.timer.val = (bgrt_tmr_t)0;
    bgrt_kernel.timer.tick = (void(*)(void))0;
    BGRT_SPIN_FREE( &bgrt_kernel.timer );
}
#endif//BGRT_CONFIG_NEW_KERNEL
