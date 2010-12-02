/**************************************************************************
    BuguRTOS-0.1.x(sguschekka) a small OS 4 microcontrollers.
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
/*!
 \file proc.h
 \brief Process definition & control functions.

 Processes R devided in 2 groups:
 \par 1. General purpose processes.
 General purpose processes R supposed 2B running all the time. Sheduling scheme 4 them is preemptive fair fifo:
 all of them get their processor time, but more prioritized R going 2 take their time first and 2 preempt les prioritized;
 if 2 or more processes R running on one priority level, then they are round robin sheduled;
 the process that was inserted 2 ready queue first will take its time first.

 \par 2. Real time processes.
 RT processes R supposed 2B stoped almost all the time,
 they R supposed 2B used as bottom halfs of interrupt service routines,
 and 4 other purposes like that.
 Sheduling scheme 4 them is fully preemptive fifo:
 RT process preempts all of the general purpose processes and least prioritized RT processes;
 if 2 or more processes R running on one priority level, then they are round robin sheduled;
 the process that was inserted 2 ready queue first will take its time first;
 the process is running until it's been preempted or until it runs out its time quant and stops.
*/
#ifndef _PROC_H_
#define _PROC_H_

#ifndef _CONFIG_H_
	#error "#include config.h" must appear in source files before "#include proc.h"
#endif

//===========================================================
/*!
 \struct _proc_struct
 \brief Process descriptor structure.
*/
/*!
 \typedef proc_t
 \brief Process descriptor.
*/
typedef struct _proc_struct {
    stack_t * stack_pointer;            //!< Process stack pointer.
    stack_t * stack_start;              //!< Process stack start (bottom).

    code_t code;                        //!< A pointer 2 the process main.

    prio_t prio;                        //!< Process priority (zero value is the highest, BITS_IN_INDEX_T-1 is the lowest).

    flag_t flags;                       //!< Process flags.

    timer_t timer;                      //!< Process timer, used as watchdoc 4 RT processes.
    timer_t time_quant;                 //!< Process time quant.

    struct _proc_struct * prev;         //!< Previous process in a queue ring pointer.
    struct _proc_struct * next;         //!< Next process in a queue ring pointer.
    struct _proc_queue_struct * queue;  //!< Process queue pointer.
    struct _sched_struct * sched;       //!< Process scheduler structure pointer.
} proc_t;
/*!
 \def PROC_FLG_RT
 \brief Indicates that process is real time.

 When U call proc_run() or proc_run_no_resched(), U must add this flag 2 indicate that process is RT.
*/
#define PROC_FLG_RT ((flag_t)1)
/*!
 \def PROC_FLG_RUN
 \brief Indicates that process is running.
 \warning 4 internal use only!
*/
#define PROC_FLG_RUN ((flag_t)2)
/*!
 \def PROC_FLG_WAIT
 \brief Indicates that process is waiting.
 \warning 4 internal use only!
*/
#define PROC_FLG_WAIT ((flag_t)4)

//===========================================================
/*!
 \struct _proc_queue_struct
 \brief Process queue descriptor structure.

 Processes in queues R organized in rings.
 All processes in one ring have the same priority.
 Pointers in proc[] array point 2 current processes in rings, they may B switched 2 proc[n]->next when schedule() is called.

 \typedef proc_queue_t
 \brief Process queue descriptor.
*/
typedef struct _proc_queue_struct {
    index_t index;                                  //!< Binary priority index 4 quick search.
    struct _proc_struct * proc[BITS_IN_INDEX_T];    //!< Process pointer array, processes a ranged by piority.
} proc_queue_t;

/************************************************************
*                                                           *
*                         CAUTION !!!                       *
*                                                           *
*       THESE FUNCIONS ARE FOR INTERNAL USE ONLY !!!        *
*                                                           *
************************************************************/
/*!
 Cuts a process from its queue.
 \warning 4 internal use only!
*/
void proc_cut( proc_t * item );
/*!
 Cuts a process from its queue wthout making its queue field null.
 \warning 4 internal use only!
*/
void proc_fast_cut( proc_t * item );
/*!
 Inserts a process 2 a queue.
 \warning 4 internal use only!
*/
void proc_insert( proc_t * item, proc_queue_t * list );
/*!
 Moves a process from one queue 2 another.
 \warning 4 internal use only!
*/
void proc_move( proc_t * item, proc_queue_t * new_list );
/*!
 Switches a poiter list->proc[prio] 2 a next process in a ring.
 \warning 4 internal use only!
*/
void proc_queue_switch( proc_queue_t * list, prio_t prio);
/*!
 Finds a most prrioritized process in a queue.
 \warning 4 internal use only!
*/
proc_t * proc_queue_head( proc_queue_t * list );

/*!
 Process run common sequence.
 \warning 4 internal use only!
*/
bool_t _proc_run( proc_t * proc );
/*!
 Process stop common sequence.
 \warning 4 internal use only!
*/
void _proc_stop( proc_t * proc );

/************************************************************
*                                                           *
*               PROCESS CONTROL FUNCTIONS                   *
*                                                           *
*                    FOR GENERAL USE                        *
*                                                           *
************************************************************/
/*!
 \brief Process descriptor initialization.

 Initiates process descriptor.
*/
void proc_init(
                proc_t * proc,          //!< A process descriptor pointer.
                stack_t * stack_start,  //!< Stack start pointer.
                code_t code,            //!< A pointer 2 the process "main" function.
                prio_t prio,            //!< A process priority.
                flag_t flags,           //!< Initial process flags (now U can use only 1 flag: PROC_FLG_RT).
                timer_t time_quant      //!< A time 4 process 2 run.
            );
/*!
 \brief Process code run wrapper.

 A wrapper 4 a process "main" function.
 It runs a process "main" function, and if "main" returns, it terminates a process correctly.
 So, user don't have 2 care about correct process termination.
 \warning 4 internal use only!
*/
void proc_run_wrapper(
                proc_t * proc //!< A process descriptor pointer.
                );
/*!
 \brief Makes a process 2 run.

 This function inserts a process 2 correspondent ready proc_queue and does recheduling.
 It can be used 2 start new process or 2 resume some stoped process.
*/
void proc_run(
                proc_t * proc //!< A process descriptor pointer.
                );
/*!
 \brief Makes a process 2 run.

 As previous, but does not resched, used in interrupt service routines, critical sections, etc.
*/
void proc_run_no_resched(
                proc_t * proc //!< A process descriptor pointer
                );

/*!
 \brief Makes a process 2 restart.

 This function restarts a process.
 It restores the stack of a process,
 as if it was just initialized,
 and calls _proc_run().

 \warning             CAUTION!!!
 \warning The process must B stoped B4 restart
*/
void proc_restart(
                    proc_t * proc //!< A process descriptor pointer

                );
/*!
 \brief Makes a process 2 stop.

 This function cuts a process from its queue and does rescheduling.
*/
void proc_stop(
                proc_t * proc //!< A process descriptor pointer

                );
/*!
 \brief Makes a process 2 stop.

 Same as above but does not rescheduling.
*/
void proc_stop_no_resched(
                            proc_t * proc //!< A process descriptor pointer

                            );

/*!
 \brief Makes a process 2 stop.

 This function is used 4 process self stop.
 \warning Do not use in critical sections and interrupts!
*/
void proc_self_stop( void );

/*!
 \brief Resets RT proc watchdog.

 This function resets watchdog 4 RT process.
*/
void proc_reset_watchdog( void );

#endif // _PROC_H_
