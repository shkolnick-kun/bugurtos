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
#ifndef _SCHED_H_
#define _SCHED_H_

/*!
 \file sched.h
 \brief Sheduler definition & control functions.
*/

#ifndef _CONFIG_H_
	#error "#include config.h" must appear in source files before "#include sched.h"
#endif

//===========================================================

/*!
 \struct _sched_struct
 \brief Shceduler descriptor structure.
 \typedef sched_t
 \brief Scheduler descriptor.
*/
typedef struct _sched_struct{
    /*
     current_proc & current_gp_proc are supposed 2B accessed by
     only lockal processor during the critical section (interrupts disabled)
    */
    struct _proc_struct * current_proc;     //!< The procees that is executed now.
    struct _proc_struct * current_gp_proc;  //!< Last executed general purpose process (needed 2B remembered if it was preempted by RT proc).

    struct _proc_queue_struct rt_ready;     //!< Real time ready queue.

    struct _proc_queue_struct gp_queues[2]; //!< General purpose queues.
    struct _proc_queue_struct * gp_ready;   //!< A pointer 2 an active (executing) general purpose queue.
    struct _proc_queue_struct * gp_expired; //!< A pointer 2 an expired general purpose queue (processes which expired their time quant R there).

    count_t nested_crit_sec;                //!< Critical section nest count.

    count_t nested_interrupts;              //!< ISR nest count.

} sched_t;

/************************************************************
*                                                           *
*                   4 INTERNAL USE ONLY !!!                 *
*                                                           *
************************************************************/
/*!
 \brief The system shceduler.
 \warning 4 internal use only!
*/
sched_t system_sched;
/*!
 \brief The system idle process (actualy it's projects main) it must B spinning all the time.

 The idle process code is main function. Idle runs at lowest priority level.
 \warning 4 internal use only!

 \warning CAUTION!!!

 \warning MAIN FUNCTION MUST B SPINNING ALL THE TIME!
 \warning DO NOT RETURN FROM MAIN!
 \warning DO NOT LOCK SEMAPHORES WITHIN MAIN!
 \warning DO NOT WAIT 4 SIGNALS WITHIN MAIN!
*/
proc_t idle;
/*!
 \brief Scheduler function, called in system timer ISR.

 Implements fully preemptive fifo scheduler 4 RT processes and preemptive fair fifo shceduler 4 general purpose processes.
 If U use CONFIG_USE_O1_SEARCH option the sheduler will B fully o(1),
 the execution time of schedule(...) will not depend on the number of running processes either on the number of used priority levels.
 On the other hand if U do not use this option, the execution time may depend on number of used priority levels, but it probably will B faster than o(1).
*/
void schedule(
    sched_t * sched //!< A pointer 2 a shceduler descriptor 2B sheduled.
    );
/*!
 \brief Rescheduler function, called by resched_local().
*/
void resched(
                sched_t * sched //!< A pointer 2 a shceduler descriptor 2B rescheduled.
            );
/***********************************************************/
/*!
 \brief Scheduler initialization.

 This function initiates a sheduler descriptor and an idle process descriptor.
*/
void scheduler_init(
                    sched_t * sched,    //!< A pointer 2 the shceduler descriptor.
                    proc_t * idle       //!< A pointer 2 the idle process descriptor.
                    );
#endif // _SCHED_H_
