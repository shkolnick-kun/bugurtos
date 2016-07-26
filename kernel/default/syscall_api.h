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
#ifndef _SYSCALL_API_H_
#define _SYSCALL_API_H_
/*!
\file
\brief \~russian Заголовок системных вызовов.

\warning Все содержимое файла для внутреннего использования!

\~english System call header.

\warning This file content is internal usage!
*/
/*****************************************************************************************/
/*                                   Process control                                     */
/*****************************************************************************************/
/*!
\~russian
\brief Запуск процесса.

Ставит процесс в список готовых к выполнению, если можно (процесс не запущен, ещё не завершил работу, не был "убит"), и производит перепланировку.
\param pid - Идентификатор процесса.
\return BGRT_ST_OK - если процесс был вставлен в список готовых к выполнению, либо код ошибки.

\~english
\brief A process launch routine.

This function schedules a process if possible.

\param pid - A process ID.
\return BGRT_ST_OK - if a process has been scheduled, error code in other cases.
*/
#define BGRT_PROC_RUN(pid) BGRT_SYSCALL_N(PROC_RUN, (void *)pid )

/*!
\~russian
\brief Перезапуск процесса.

Если можно (процесс не запущен, завершил работу, не был "убит"), приводит структуру proc в состояние, которое было после вызова #bgrt_proc_init, и ставит процесс в список готовых к выполнению, и производит перепланировку.
\param pid - Идентификатор процесса.
\return BGRT_ST_OK - если процесс был вставлен в список готовых к выполнению, либо код ошибки.

\~english
\brief A process restart routine.

This function reinitializes a process and schedules it if possible.

\param pid - A process ID.
\return BGRT_ST_OK - if a process has been scheduled, error code in other cases.
*/
#define BGRT_PROC_RESTART(pid) BGRT_SYSCALL_N(PROC_RESTART, (void *)pid )
/*!
\~russian
\brief Останов процесса.

Вырезает процесс из списка готовых к выполнению и производит перепланировку.
\param pid - Идентификатор процесса.
\return BGRT_ST_OK - если процесс был вырезан из списка готовых к выполнению, либо код ошибки.

\~english
\brief A process stop routine.

This function stops a process if possible.
\param pid - A process ID.
\return BGRT_ST_OK - if a process has been stopped, error code in other cases.
*/
#define BGRT_PROC_STOP(pid) BGRT_SYSCALL_N(PROC_STOP, (void *)pid )
/*!
\~russian
\brief Самоостанов процесса.

Вырезает вызывающий процесс из списка готовых к выполнению и производит перепланировку.

\~english
\brief A process self stop routine.

This function stops caller process.
*/
void bgrt_proc_self_stop(void);
/*!
\~russian
\brief Установка флага #BGRT_PROC_FLG_LOCK для вызывающего процесса.

\~english
\brief Set #BGRT_PROC_FLG_LOCK for caller process.
*/
void bgrt_proc_lock(void);
/*!
\~russian
\brief Останов процесса по флагу #BGRT_PROC_FLG_PRE_STOP.

\~english
\brief A #BGRT_PROC_FLG_PRE_STOP flag processing routine.
*/
void bgrt_proc_free(void);
/*!
\~russian
\brief Сброс watchdog для процесса реального времени.

Если функцию вызывает процесс реального времени, то функция сбрасывает его таймер.
Если процесс завис, и таймер не был вовремя сброшен, то планировщик остановит такой процесс и передаст управление другому.

\~english
\brief A watchdog reset routine for real time processes.

If a caller process is real time, then this function resets its timer.
If a real time process failed to reset its watchdog, then the scheduler stops such process and wakes up next ready process.
*/
void bgrt_proc_reset_watchdog(void);
/*****************************************************************************************/
/*!
\~russian
\brief
Аргумент вызова #BGRT_SYSCALL_PROC_GET_PRIO.

\~english
\brief
A #BGRT_SYSCALL_PROC_GET_PRIO argument.
*/
typedef struct{
    BGRT_PID_T pid;          /*!< \~russian Идентификатор процесса. \~english A process ID. */
    bgrt_prio_t ret;         /*!< \~russian Результат выполнения системного вызова. \~english A result storage. */
}bgrt_proc_get_prio_arg_t;   /*!< \~russian Аргумент #bgrt_scall_proc_get_prio. \~english An arg for #bgrt_scall_proc_get_prio.*/
/*****************************************************************************************/
/*                                        Sync                                           */
/*****************************************************************************************/
/*!
\~russian
\brief
Параметр системного вызова #BGRT_SYSCALL_PROC_SET_PRIO.

\~english
\brief
An argument for system call #BGRT_SYSCALL_PROC_SET_PRIO.
*/
typedef struct
{
    BGRT_PID_T pid;     /*!< \~russian Идентификатор процесса. \~english A process ID. */
    bgrt_prio_t prio;   /*!< \~russian Приоритет. \~english Priority. */
}
bgrt_proc_set_prio_arg_t;
/*****************************************************************************************/
/*!
\~russian
\brief
Аргумент вызовов #BGRT_SYSCALL_SYNC_SET_OWNER/#BGRT_SYSCALL_SYNC_GET_OWNER.

\~english
\brief
A #BGRT_SYSCALL_SYNC_SET_OWNER/#BGRT_SYSCALL_SYNC_GET_OWNER. arg.
*/
typedef struct
{
    bgrt_sync_t * sync;
    BGRT_PID_T    pid;
}
bgrt_sync_owner_t;
/*****************************************************************************************/
#define BGRT_SYNC_SET_OWNER(s,p) bgrt_sync_set_owner((bgrt_sync_t *)s, (BGRT_PID_T)p) /*!< \~russian \brief Смотри #bgrt_sync_set_owner. \~english \brief Watch #bgrt_sync_set_owner. */
/*****************************************************************************************/
#define BGRT_SYNC_GET_OWNER(s) bgrt_sync_get_owner((bgrt_sync_t *)s) /*!< \~russian \brief Смотри #bgrt_sync_get_owner. \~english \brief Watch #bgrt_sync_get_owner. */
/*****************************************************************************************/
/*!
\~russian
\brief
Аргумент вызова #BGRT_SYSCALL_SYNC_OWN.

\~english
\brief
A #BGRT_SYSCALL_SYNC_OWN arg.
*/
typedef struct
{
    bgrt_sync_t * sync;
    bgrt_flag_t touch;
}bgrt_sync_own_sleep_t;
/*****************************************************************************************/
#define BGRT_SYNC_OWN(s,t) bgrt_sync_own( (bgrt_sync_t *)(s), (bgrt_flag_t)(t) ) /*!< \~russian \brief Смотри #bgrt_sync_own. \~english \brief Watch #bgrt_sync_own. */
/*****************************************************************************************/
/*!
\~russian
\brief
Аргумент вызова #BGRT_SYSCALL_SYNC_TOUCH.

\~english
\brief
A #BGRT_SYSCALL_SYNC_TOUCH arg.
*/
typedef struct
{
    bgrt_sync_t * sync;
}bgrt_sync_touch_t;
#define BGRT_SYNC_TOUCH(s) bgrt_sync_touch( (bgrt_sync_t *)(s) ) /*!< \~russian \brief Смотри #bgrt_sync_touch. \~english \brief Watch #bgrt_sync_touch. */
/*****************************************************************************************/
#define BGRT_SYNC_SLEEP(s,t) bgrt_sync_sleep((bgrt_sync_t *)(s), (bgrt_flag_t)(t)) /*!< \~russian \brief Смотри #bgrt_sync_sleep. \~english \brief Watch #bgrt_sync_sleep. */
/*****************************************************************************************/
/*!
\~russian
\brief
Для внутреннего пользования.

\~english
\brief
For internal usage.
*/
typedef struct
{
    bgrt_sync_t * sync; /*!< \~russian Указатель на объект типа #bgrt_sync_t. \~english A #bgrt_sync_t object pointer. */
    BGRT_PID_T pid; /*!< \~russian Указатель на процесс. \~english A process pointer. */
    bgrt_flag_t chown;  /*!< \~russian Флаг смены хозяина. \~english A change owner flag. */
}
bgrt_sync_wake_t;
/*****************************************************************************************/
#define BGRT_SYNC_WAKE(s,p,c,st)                                   \
do                                                                 \
{                                                                  \
    volatile bgrt_sync_wake_t scarg;                               \
    scarg.sync = (bgrt_sync_t *)(s);                               \
    scarg.pid = (BGRT_PID_T)(p);                                   \
    scarg.chown = (bgrt_flag_t)(c);                                \
    (st) = BGRT_SYSCALL_N(SYNC_WAKE, (void *)&scarg );  \
}                                                                  \
while(0) /*!< \~russian \brief Смотри #bgrt_sync_wake. \~english \brief Watch #bgrt_sync_wake. */
/*****************************************************************************************/
/*!
\~russian
\brief
Для внутреннего пользования.

\~english
\brief
For internal usage.
*/
typedef struct
{
    bgrt_sync_t * sync;  /*!< \~russian Указатель на объект типа #bgrt_sync_t. \~english A #bgrt_sync_t object pointer. */
    BGRT_PID_T * pid; /*!< \~russian Указатель на буфер процесса. \~english A process buffer pointer. */
    bgrt_flag_t block;   /*!< \~russian Флаг блокирования. \~english A block flag. */
}
bgrt_sync_wait_t;
/*****************************************************************************************/
#define BGRT_SYNC_WAIT(s,p,b,st)                                   \
do                                                                 \
{                                                                  \
    volatile bgrt_sync_wait_t scarg;                               \
    scarg.sync = (bgrt_sync_t *)(s);                               \
    scarg.pid = (BGRT_PID_T *)(p);                                 \
    scarg.block = (bgrt_flag_t)(b);                                \
    (st) = BGRT_SYSCALL_N(SYNC_WAIT, (void *)&scarg ); \
}                                                                  \
while(0) /*!< \~russian \brief Смотри #bgrt_sync_wait. \~english \brief Watch #bgrt_sync_wait. */
/*****************************************************************************************/
/*!
\~russian
\brief
Аргумент вызова #BGRT_SYSCALL_SYNC_PROC_TIMEOUT.

\~english
\brief
A #BGRT_SYSCALL_SYNC_PROC_TIMEOUT arg.
*/
typedef struct
{
    BGRT_PID_T pid;
}
bgrt_sync_proc_timeout_t;
#endif // _SYSCALL_API_H_
