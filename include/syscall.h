/**************************************************************************
    BuguRTOS-0.3.x(Bugurt real time operating system)
    Copyright (C) 2011  anonimous

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
#ifndef _SYSCALL_H_
#define _SYSCALL_H_

/// System call numbers!
#define SYSCALL_PROC_INIT                       ((syscall_t)(1))
#define SYSCALL_PROC_RUN                        (SYSCALL_PROC_INIT + (syscall_t)(1))
#define SYSCALL_PROC_RESTART                    (SYSCALL_PROC_RUN + (syscall_t)(1))
#define SYSCALL_PROC_STOP                       (SYSCALL_PROC_RESTART + (syscall_t)(1))
#define SYSCALL_PROC_SELF_STOP                  (SYSCALL_PROC_STOP + (syscall_t)(1))
#define SYSCALL_PROC_TERMINATE                  (SYSCALL_PROC_SELF_STOP + (syscall_t)(1))
#define SYSCALL_PROC_FLAG_STOP                  (SYSCALL_PROC_TERMINATE + (syscall_t)(1))
#define SYSCALL_PROC_RESET_WATCHDOG             (SYSCALL_PROC_FLAG_STOP + (syscall_t)(1))

#define SYSCALL_SIG_INIT                        (SYSCALL_PROC_RESET_WATCHDOG + (syscall_t)(1))
#define SYSCALL_SIG_WAIT                        (SYSCALL_SIG_INIT + (syscall_t)(1))
#define SYSCALL_SIG_SIGNAL                      (SYSCALL_SIG_WAIT + (syscall_t)(1))
#define SYSCALL_SIG_BROADCAST                   (SYSCALL_SIG_SIGNAL + (syscall_t)(1))

#define SYSCALL_SEM_INIT                        (SYSCALL_SIG_BROADCAST + (syscall_t)(1))
#define SYSCALL_SEM_LOCK                        (SYSCALL_SEM_INIT + (syscall_t)(1))
#define SYSCALL_SEM_TRY_LOCK                    (SYSCALL_SEM_LOCK + (syscall_t)(1))
#define SYSCALL_SEM_UNLOCK                      (SYSCALL_SEM_TRY_LOCK + (syscall_t)(1))

#define SYSCALL_MUTEX_INIT                      (SYSCALL_SEM_UNLOCK + (syscall_t)(1))
#define SYSCALL_MUTEX_LOCK                      (SYSCALL_MUTEX_INIT + (syscall_t)(1))
#define SYSCALL_MUTEX_TRY_LOCK                  (SYSCALL_MUTEX_LOCK + (syscall_t)(1))
#define SYSCALL_MUTEX_UNLOCK                    (SYSCALL_MUTEX_TRY_LOCK + (syscall_t)(1))

#ifdef CONFIG_MP
void do_syscall( syscall_t syscall_num, void * syscall_arg );
#else
extern syscall_t syscall_num;
extern void * syscall_arg;

void do_syscall( void );
#endif

///=================================================================
///                   System call handlers !!!
///=================================================================
///                      Process control !
typedef struct {
    proc_t * proc;
    code_t pmain;
    code_t sv_hook;
    code_t rs_hook;
    void * arg;
    stack_t *sstart;
    prio_t prio;
    timer_t time_quant;
    bool_t is_rt;
#ifdef CONFIG_MP
    affinity_t affinity;
#endif // CONFIG_MP
} proc_init_arg_t;

void scall_proc_init( void * arg );
//----------------------------------------------------------------------
typedef struct{
    proc_t * proc;
    bool_t scall_ret;
}proc_runtime_arg_t;

void scall_proc_run( void * arg );
void scall_proc_restart( void * arg );
void scall_proc_stop( void * arg );
//----------------------------------------------------------------------
void scall_proc_self_stop( void * arg );
//----------------------------------------------------------------------
void scall_proc_terminate( void * arg );
//----------------------------------------------------------------------
void scall_proc_flag_stop( void * arg );
//----------------------------------------------------------------------
void scall_proc_reset_watchdog( void * arg );
///=================================================================
///                       Signal control!
void scall_sig_init( void * arg );
void scall_sig_wait( void * arg );
void scall_sig_signal( void * arg );
void scall_sig_broadcast( void * arg );
///=================================================================
///                     Semaphore control !
typedef struct {
    sem_t * sem;
    count_t count;
}sem_init_arg_t;
void scall_sem_init( void * arg );
//----------------------------------------------------------------------
typedef struct {
    sem_t * sem;
    bool_t scall_ret;
}sem_lock_arg_t;
void scall_sem_lock( void * arg );
void scall_sem_try_lock( void * arg );
//----------------------------------------------------------------------
void scall_sem_unlock( void * arg );
///=================================================================
///                         Мьютексы
typedef struct {
    mutex_t * mutex;
#ifdef CONFIG_USE_HIGHEST_LOCKER
    prio_t prio;
#endif // CONFIG_USE_HIGHEST_LOCKER
}mutex_init_arg_t;
void scall_mutex_init(void * arg);
//----------------------------------------------------------------------
typedef struct {
    mutex_t * mutex;
    bool_t scall_ret;
} mutex_lock_arg_t;
void scall_mutex_lock(void * arg);
void scall_mutex_try_lock(void * arg);
void scall_mutex_unlock(void * arg);

#endif // _SYSCALL_H_
