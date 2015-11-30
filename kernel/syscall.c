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
#include "bugurt.h"

#define BGRT_SC_TBL_ENTRY(f) ((bgrt_code_t)f)

BGRT_SCL_TBL( syscall_handler[] ) =
{
    // Process control
    BGRT_SC_TBL_ENTRY( scall_bgrt_proc_run               ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_proc_restart           ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_proc_stop              ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_proc_self_stop         ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_proc_terminate         ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_proc_lock              ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_proc_free              ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_proc_reset_watchdog    ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_proc_set_prio          ),
    // Scheduler
    BGRT_SC_TBL_ENTRY( scall_bgrt_sched_proc_yeld        ),
    // Bsync
    BGRT_SC_TBL_ENTRY( scall_bgrt_sync_set_owner         ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_sync_own               ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_sync_touch             ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_sync_sleep             ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_sync_wake              ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_sync_wait              ),
    BGRT_SC_TBL_ENTRY( scall_bgrt_sync_proc_timeout      ),
    //Arbitrary code execution
    BGRT_SC_TBL_ENTRY( scall_user                   )
};

#ifndef BGRT_CONFIG_SYSCALL_CHECK
//Default syscall sanity check macro
#define BGRT_CONFIG_SYSCALL_CHECK(n,a) \
( ( (bgrt_syscall_t)0 == n )&&( SYSCALL_USER < n  ) )

#endif //BGRT_CONFIG_SYSCALL_CHECK

void do_syscall( bgrt_syscall_t syscall_num, void * syscall_arg )
{
    //Sanity check
    if( BGRT_CONFIG_SYSCALL_CHECK(syscall_num, syscall_arg) )
    {
        //Fail
        return;
    }
    else
    {
        //Syscall processing
        (BGRT_SCL_TBL_READ(syscall_handler[syscall_num - 1]))(syscall_arg);
    }
}

/**********************************************************************************************
                                  System call handlers !!!
***********************************************************************************************
                                       SYSCALL_USER
**********************************************************************************************/
typedef union
{
    bgrt_code_t func;
    void * arg;
}
scall_user_t;

void scall_user(void * arg)
{
    scall_user_t user;
    user.func = (bgrt_code_t)0;
    user.arg = arg;
    user.func(arg);
}
