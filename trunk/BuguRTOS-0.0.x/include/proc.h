/**************************************************************************
    BuguRTOS-0.0.x(nuTyx) a test code 4 BuguRTOS-0.x.x.
    Probably it won't B a real OS.
    Copyright (C) 2010  anonimous

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
#ifndef _PROC_H_
#define _PROC_H_

#ifndef _CONFIG_H_
	#error "#include config.h" must appear in source files before "#include proc.h"
#endif

//===========================================================
//process descriptor
typedef struct _proc_struct {
    stack_t * stack_pointer;
    stack_t * stack_start;
    // code 2 execute
    code_t code;

    prio_t prio;

    flag_t flags;

#ifdef CONFIG_MP
    affinity_t affinity;
    lock_t lock;
    // queue_lock 4 use in semaphores, signals and 4 _proc_stop(proc)
    lock_t * queue_lock;
#endif
    // process timer (used as wachdog for rt proc)
    timer_t timer;
    timer_t time_quant;

    struct _proc_struct * prev;
    struct _proc_struct * next;
    struct _proc_queue_struct * queue;
    struct _sched_struct * sched;
} proc_t;

#define PROC_FLG_RT ((flag_t)1)
#define PROC_FLG_RUN ((flag_t)2)
#define PROC_FLG_WAIT ((flag_t)4)
#define PROC_FLG_END ((flag_t)8)

//===========================================================
// process queue descriptor
typedef struct _proc_queue_struct {
    index_t index;
    struct _proc_struct * proc[BITS_IN_INDEX_T];
} proc_queue_t;

/************************************************************
*                                                           *
*                         CAUTION !!!                       *
*                                                           *
*       THESE FUNCIONS ARE FOR INTERNAL USE ONLY !!!        *
*                                                           *
************************************************************/
void proc_cut( proc_t * item );

void proc_fast_cut( proc_t * item );

void proc_insert( proc_t * item, proc_queue_t * list );

void proc_move( proc_t * item, proc_queue_t * new_list );

void proc_queue_switch( proc_queue_t * list, prio_t prio);

proc_t * proc_queue_head( proc_queue_t * list );

// proc_run sequence
bool_t _proc_run( proc_t * proc );
// proc_stop seqeuence
void _proc_stop( proc_t * proc );

/************************************************************
*                                                           *
*               PROCESS CONTROL FUNCTIONS                   *
*                                                           *
*                    FOR GENERAL USE                        *
*                                                           *
************************************************************/
// proc descriptor and stack initialization
void proc_init(
                proc_t * proc,  // the process descriptor pointer
                stack_t * stack_start, // stack start pointer
                code_t code,    // a pointer 2 the process "main" function
                prio_t prio,    // the process priority
                flag_t flags,    // initial process flags (now there is only 1 flag: PROC_FLG_RT)
#ifdef CONFIG_MP
                affinity_t affinity,
#endif
                timer_t time_quant
            );
/*
 A wrapper 4 the process "main" function.
 It runs the process "main" function, and if "main" returns, it terminates the process correctly.
 So, user don't have 2 care about correct process termination.
*/
void proc_run_wrapper( proc_t * proc );
/*
 This function inserts the process 2 the correspondent ready proc_queue and does recheduling.
 It can be used 2 start new process | 2 resume some stoped process.
*/
void proc_run( proc_t * proc );

// As previous, but used in interrupt service routines.
void proc_run_no_resched( proc_t * proc );

/*
 This function restarts the process.
 It restores the stack of the process,
 as if it was just initialized,
 and calls _proc_run(proc).
*/
/***************************************
*              CAUTION!!!              *
* The process must B stoped B4 restart *
***************************************/
void proc_restart( proc_t * proc );

// This function cuts the process from its proc_queue and does rescheduling.
void proc_stop( proc_t * proc );
void proc_stop_no_resched( proc_t * proc );

// This function is used for process self stop.
void proc_self_stop( void );

// This function resets watchdog 4 rt process
void proc_reset_watchdog( void );

#endif // _PROC_H_
