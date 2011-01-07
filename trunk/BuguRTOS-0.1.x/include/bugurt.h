/**************************************************************************
    BuguRTOS-0.1.x(sguschenka) a small OS 4 microcontrollers.
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
 \mainpage
 \author anonimous <shkolnick.kun@gmail.com>
 \par Origin

 The name BuguRTOS comes from Butthurt Yogurt and BAGET RTOS.
 In the year 2010 there were alot of events, one of those was BolgenOS. I had a real, REAL BUTTHURT when Denis Popov had released it.
 During that time there was a cancer wave on my warm vacuumtubed 0chan, some idiots forced butthurt and other B...T words.
 One of those words was BAGET. SUDDENLY!!! This was the name of russian military real time platform. Some forcers forced BUGURT,
 a hybrid of YOGURT and BUTTHURT.

 As I had my butthurt I decided 2 write MY OWN OPERATING SYSTEM !!1
 I got together a trend word BUGURT and BAGET RTOS, and the codename BuguRTOS was born.

 Next I wrote some monkey code and with a great aplomb named it BuguRTOS.
 \par Branches

 There are 2 brances of BuguRTOS code:

  0.0.x codename nuTyx (SUDDENLY!!! /S/permclowns can not into calling GNU/Linux with names like nuTyx, pituh, pitux, etc.). It's a test code with some hi level MP support, and yes it IS an OS.
  I used OSBME 2 write low level functions. Only AVR is supported now, so it can not into MP, but low level MP support is just a matter of time.

  and

  0.1.x codename sguschenka - small microcontroller OS, this documentation is writen 4 that branch.
 \par Version

 Current version is 0.1.0. It is alpha and it will allways B alpha as all OpenSource. Also because girls love alphas.
 \par Arch

 BuguRTOS-0.1.0 and 0.0.0 support only AVR architecture, but they can easily B ported 2 other architectures.
 \par License

 BuguRTOS license is GPLv3 or later, NO EXCEPTIONS!!!

 If U want 2 use it in your closed source application, then U have 2 implement syscall interface,
 release yor syscall implementation under GPLv3 or later and
 release a lib supporting your syscall under your license
 (actualy supporting lib won't B linked with GPLed code,
 it just will generate a special kind of interrupt(s)).
 \image html logo.png "Enjoy your BuguRTOS, LOL!"
 \image latex logo.eps "Enjoy your BuguRTOS, LOL!" width=7cm
 \par Future work

 At the moment I'm going 2 work on a new branch 0.2.x it'll inherit most of 0.1.x source code,
 but it'll B based on significantly different ideas. 0.2.0 will only suport AVR as 0.1.0.
 Next I'm going 2 create 1 interesting AVR project, and then I'm going 2 port 0.0.x, 0.1.x and 0.2.x branches 2 ARM.

 \par Toolchain

 I Use GNU toolchain with my BuguRTOS.
 \par Usage

 1. Take your favorite IDE (my choice is code::blocks).

 2. Create a new embedded project (AVR only now).

 3. Copy BuguRTOS directory 2 your project directory.

 4. Add files 2 your project.

 5. Write your own config.h

 6. ??????

 7. PROFIT!!!
*/

/*!
 \file bugurt.h
 \brief The root header.

 \par

 All headers are included here. Also necessary platform dependent functions are declared here.

 \par Project scope definitions

 Project scope definitions R supposed 2B in ../../config.h.

 Here is example config.h, it contains necessary project scope definitions, includes & functions 4 the sample project.
 \par config.h

 \includelineno config.h
*/
#ifndef _BUGURT_H_
#define _BUGURT_H_

// Project related stuff is in ../../config.h
#ifndef _CONFIG_H_
#include "../../config.h"
#endif

#include "proc.h"
#include "sched.h"
#include "sem.h"
#include "sig.h"
/************************************************************
*                platform dependent crap                    *
************************************************************/
/*!
 \brief Platform dependent process stack initialization.

 \warning 4 internal use only!
*/
extern void stack_init(proc_t * proc);
/*!
 \brief Platform dependent try 2 lock semaphore function.

 \warning 4 internal use only!
*/
extern bool_t _sem_try_lock(lock_t * lock);
/*!
 \brief Platform dependent unlock semaphore function.

 \warning 4 internal use only!
*/
extern void _sem_unlock(lock_t * lock);

/************************************************************
*                       4 general use                       *
************************************************************/
/*!
 \brief Start scheduler function.

 This function enables system timer interupt.
*/
extern void start_scheduler( void );
/*!
 \brief Stop scheduler function.

 This function disables system timer interrupt.
*/
extern void stop_scheduler( void );

/*!
 \brief Rescheduler function.

 This function rescheds tasks on the processor, and switch context if needed.
*/
extern void resched_local( void );

/*!
 \brief The BuguRTOS initialization function.

 This function disables interrupts and initiates system shceduler structure.
*/
extern void init_bugurt(void);
/*!
 \brief The BuguRTOS start function.

 This function starts sheduler and enables interrupts. U must call init_bugurt and initiate all that you need B4 calling start_bugurt().
*/
extern void start_bugurt(void);

/*!
 \brief Critical section start.

 This function disables interrupt if they R enabled, and increments nested critical section count.
*/
extern void enter_crit_sec(void);
/*!
 \brief Critical section end.

 This function decrements nested critical section count and if it becomes zero, it enables interrupts
*/
extern void exit_crit_sec(void);
/*!
 \brief Nested interrupt service routine start.

 This function stops scheduler increments nested interrupt count and enables interrupts.
*/
extern void nested_isr_start(void);
/*!
 \brief Nested interrupt service routine end.

 This function disables interrupts decrements nested interrupt count and starts scheduler.
*/
extern void nested_isr_end(void);
/*!
 \brief System timer interrupt service routine.

 This is system timer interrupt, scheduler routine is called here.
*/
extern void SYSTEM_TIMER_ISR(void) SYS_TMR_ISR_ATTR;
/*!
 \warning 4 internal use only!
*/
extern timer_t  system_timer;
/*!
 \warning 4 internal use only!
*/
extern timer_t _timer( timer_t t );
/*!
 \def TIMER
 \brief Soft timer value.

 "Returns" a software timer value.
*/
#define TIMER(t) _timer(t)
/*!
 \def CLEAR_TIMER
 \brief Soft timer clear.

 "Clears" a software timer.
*/
#define CLEAR_TIMER(t) {enter_crit_sec(); t = system_timer; exit_crit_sec();}
/*!
 \brief Wait 4 some time.

 This function spinns 4 specified time.
*/
extern void wait_time(
                        timer_t time //!< Time 2 spin

                        );
#endif // _BUGURT_H_
