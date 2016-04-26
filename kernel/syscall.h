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
#ifndef _SYSCALL_H_
#define _SYSCALL_H_

/*!
\file
\brief \~russian Заголовок системных вызовов.

\warning Все содержимое файла для внутреннего использования!

\~english System call header.

\warning This file content is internal usage!
*/

// System call numbers!
#define BGRT_SYSCALL_PROC_RUN                       ((bgrt_syscall_t)(1))                                           /*!< \~russian \brief Запуск процесса. \~english \brief A process launch. */
#define BGRT_SYSCALL_PROC_RESTART                   (BGRT_SYSCALL_PROC_RUN + (bgrt_syscall_t)(1))                   /*!< \~russian \brief Перезапуск процесса. \~english \brief A Process restart. */
#define BGRT_SYSCALL_PROC_STOP                      (BGRT_SYSCALL_PROC_RESTART + (bgrt_syscall_t)(1))               /*!< \~russian \brief Останов процесса. \~english \brief A process stop. */
#define BGRT_SYSCALL_PROC_SELF_STOP                 (BGRT_SYSCALL_PROC_STOP + (bgrt_syscall_t)(1))                  /*!< \~russian \brief Самоостанов процесса. \~english \brief A process self stop. */
#define BGRT_SYSCALL_PROC_TERMINATE                 (BGRT_SYSCALL_PROC_SELF_STOP + (bgrt_syscall_t)(1))             /*!< \~russian \brief Завершение работы процесса. \~english \brief A process termination. */
#define BGRT_SYSCALL_PROC_LOCK                      (BGRT_SYSCALL_PROC_TERMINATE + (bgrt_syscall_t)(1))             /*!< \~russian \brief Установить флаг #BGRT_PROC_FLG_LOCK для вызывающего процесса. \~english \brief #BGRT_PROC_FLG_LOCK for caller process. */
#define BGRT_SYSCALL_PROC_FREE                      (BGRT_SYSCALL_PROC_LOCK + (bgrt_syscall_t)(1))                  /*!< \~russian \brief Останов процесса по флагу #BGRT_PROC_FLG_PRE_STOP. \~english \brief #BGRT_PROC_FLG_PRE_STOP flag processing. */
#define BGRT_SYSCALL_PROC_RESET_WATCHDOG            (BGRT_SYSCALL_PROC_FREE + (bgrt_syscall_t)(1))                  /*!< \~russian \brief Сброс watchdog процесса реального времени. \~english \brief A real time process watchdog reset. */
#define BGRT_SYSCALL_PROC_SET_PRIO                  (BGRT_SYSCALL_PROC_RESET_WATCHDOG + (bgrt_syscall_t)(1))        /*!< \~russian \brief Установить приоритет процесса \~english \brief Set a process priority. */
#define BGRT_SYSCALL_PROC_GET_PRIO                  (BGRT_SYSCALL_PROC_SET_PRIO + (bgrt_syscall_t)(1))              /*!< \~russian \brief Получить приоритет процесса \~english \brief Get a process priority. */
#define BGRT_SYSCALL_PROC_GET_ID                    (BGRT_SYSCALL_PROC_GET_PRIO + (bgrt_syscall_t)(1))              /*!< \~russian \brief Установить приоритет процесса \~english \brief Set a process priority. */

#define BGRT_SYSCALL_SCHED_PROC_YELD                (BGRT_SYSCALL_PROC_GET_ID + (bgrt_syscall_t)(1))                /*!< \~russian \brief Передача управления другому процессу. \~english \brief Transfer control to another process. */

#define BGRT_SYSCALL_SYNC_SET_OWNER                 (BGRT_SYSCALL_SCHED_PROC_YELD + (bgrt_syscall_t)(1))            /*!< \~russian \brief Установить нового хозяина объекта типа #bgrt_sync_t. \~english \brief Set new #bgrt_sync_t object owner. */
#define BGRT_SYSCALL_SYNC_GET_OWNER                 (BGRT_SYSCALL_SYNC_SET_OWNER + (bgrt_syscall_t)(1))             /*!< \~russian \brief Узнать принадлежность объекта типа #bgrt_sync_t. \~english \brief Get #bgrt_sync_t object owner. */
#define BGRT_SYSCALL_SYNC_OWN                       (BGRT_SYSCALL_SYNC_GET_OWNER + (bgrt_syscall_t)(1))             /*!< \~russian \brief Завладеть объектом типа #bgrt_sync_t. \~english \brief Own #bgrt_sync_t object. */
#define BGRT_SYSCALL_SYNC_TOUCH                     (BGRT_SYSCALL_SYNC_OWN + (bgrt_syscall_t)(1))                   /*!< \~russian \brief Заблокировать пробуждение процессов. \~english \brief Block process wake*/
#define BGRT_SYSCALL_SYNC_SLEEP                     (BGRT_SYSCALL_SYNC_TOUCH + (bgrt_syscall_t)(1))                 /*!< \~russian \brief Заблокировать процесс в ожидании синхронизации. \~english \brief Block process for synchronization. */
#define BGRT_SYSCALL_SYNC_WAKE                      (BGRT_SYSCALL_SYNC_SLEEP + (bgrt_syscall_t)(1))                 /*!< \~russian \brief Запустить процесс, ожидающий синхронизации. \~english \brief Run a process waiting for synchronization. */
#define BGRT_SYSCALL_SYNC_WAIT                      (BGRT_SYSCALL_SYNC_WAKE + (bgrt_syscall_t)(1))                  /*!< \~russian \brief Подождать блокировки процесса на объекте типа #bgrt_sync_t. \~english \brief Wait for process to block on #bgrt_sync_t object*/
#define BGRT_SYSCALL_SYNC_PROC_TIMEOUT              (BGRT_SYSCALL_SYNC_WAIT + (bgrt_syscall_t)(1))                  /*!< \~russian \brief Разбудить процесс по таймауту. \~english \brief Wake a process on timeout. */

#define BGRT_SYSCALL_USER                           (BGRT_SYSCALL_SYNC_PROC_TIMEOUT + (bgrt_syscall_t)(1))     /*!< \~russian \brief Пользовательский системный вызов. \~english \brief User system call. */

typedef bgrt_st_t (* bgrt_scsr_t)(void *); /*!< \~russian \brief Обработчик системного вызова. \~english \brief System call srvice routine pointer. */

#define BGRT_SC_TBL_ENTRY(f) ((bgrt_scsr_t)f)
/*!
\~russian
\brief
Обработка системного вызова.

Запускает обработчик системного вызова и передаёт ему аргумент.

\~english
\brief
System call processing routine.

This function calls system call handlers and passes arguments to them.
*/
bgrt_st_t bgrt_do_syscall(
                bgrt_syscall_t syscall_num,  /*!< \~russian Номер системного вызова. \~english System call number.*/
                void * syscall_arg      /*!< \~russian Аргумент системного вызова. \~english System call argument.*/
                );

/*****************************************************************************************/
/*                               System call handlers !!!                                */
/*****************************************************************************************/
/*                                   Process control                                     */
/*****************************************************************************************/
/*!
\~russian
\brief
Параметр системных вызовов #BGRT_SYSCALL_PROC_RUN, #BGRT_SYSCALL_PROC_RESTART, #BGRT_SYSCALL_PROC_STOP.

\~english
\brief
An argument for system calls #BGRT_SYSCALL_PROC_RUN, #BGRT_SYSCALL_PROC_RESTART, #BGRT_SYSCALL_PROC_STOP.
*/
typedef struct{
    BGRT_PID_T pid;      /*!< \~russian Идентификатор процесса. \~english A process ID. */
    bgrt_st_t ret;         /*!< \~russian Результат выполнения системного вызова. \~english A result storage. */
}bgrt_proc_runtime_arg_t;

/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_PROC_RUN.

Пытается запустить процесс, вызывая #_bgrt_proc_run.

\param arg указатель на структуру #bgrt_proc_runtime_arg_t.

\~english
\brief
A #BGRT_SYSCALL_PROC_RUN handler.

This function tries to launch a process by #_bgrt_proc_run call.

\param arg A #bgrt_proc_runtime_arg_t pointer.
*/
bgrt_st_t bgrt_scall_proc_run( bgrt_proc_runtime_arg_t * arg );
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_PROC_RESTART.

Пытается перезапустить процесс, вызывая #_bgrt_proc_restart.

\param arg указатель на структуру #bgrt_proc_runtime_arg_t.

\~english
\brief
A #BGRT_SYSCALL_PROC_RESTART handler.

This function tries to restart a process by #_bgrt_proc_restart call.

\param arg A #bgrt_proc_runtime_arg_t pointer.
*/
bgrt_st_t bgrt_scall_proc_restart( bgrt_proc_runtime_arg_t * arg );
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_PROC_STOP.

Пытается остановить процесс, вызывая #_bgrt_proc_stop.

\param arg указатель на структуру #bgrt_proc_runtime_arg_t.

\~english
\brief
A #BGRT_SYSCALL_PROC_STOP handler.

This function tries to stop a process by #_bgrt_proc_stop call.

\param arg A #bgrt_proc_runtime_arg_t pointer.
*/
bgrt_st_t bgrt_scall_proc_stop( bgrt_proc_runtime_arg_t * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_PROC_SELF_STOP.

Останавливает вызывающий процесс.

\param arg не используется.

\~english
\brief
A #BGRT_SYSCALL_PROC_SELF_STOP handler.

This function stops calling process.

\param arg Not used.
*/
bgrt_st_t bgrt_scall_proc_self_stop( void * arg );

/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_PROC_TERMINATE.

Завершает выполнение процесса после выхода из pmain. Вызывает #_bgrt_proc_terminate.

\param arg указатель на процесс.

\~english
\brief
A #BGRT_SYSCALL_PROC_TERMINATE handler.

This function terminates calling process after pmain return by #_bgrt_proc_terminate call.

\param arg A pointer to a process.
*/
bgrt_st_t bgrt_scall_proc_terminate( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_PROC_LOCK.

Устанавливает флаг #BGRT_PROC_FLG_LOCK для вызывающего процесса, увеличивает счётчик proc->lres.

\~english
\brief
A #BGRT_SYSCALL_PROC_LOCK handler.

Sets #BGRT_PROC_FLG_LOCK for caller process, increases proc->lres counter.
*/
bgrt_st_t bgrt_scall_proc_lock( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_PROC_FREE.

Уменьшает счётчик proc->lres, при необходимости обнуляет флаг #BGRT_PROC_FLG_LOCK, пытается остановить вызывающий процесс по флагу #BGRT_PROC_FLG_PRE_STOP.
Вызывает #_bgrt_proc_free.

\param arg указатель на маску обнуления флагов процесса.

\~english
\brief
A #BGRT_SYSCALL_PROC_FREE handler.

This function decreases proc->lres counter, clears #BGRT_PROC_FLG_LOCK if needed and, process #BGRT_PROC_FLG_PRE_STOP of the calling process and clears masked flags of a calling process.
It calls #_bgrt_proc_free.

\param arg A pointer to a flag mask.
*/
bgrt_st_t bgrt_scall_proc_free( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_PROC_RESET_WATCHDOG.

Вызывает #_bgrt_proc_reset_watchdog.

\param arg не используется.

\~english
\brief
A #BGRT_SYSCALL_PROC_RESET_WATCHDOG handler.

This function calls #_bgrt_proc_reset_watchdog.

\param arg Not used.
*/
bgrt_st_t bgrt_scall_proc_reset_watchdog( void * arg );
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
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_PROC_GET_PRIO.

Вызывает #_bgrt_proc_get_prio.

\~english
\brief
A #BGRT_SYSCALL_PROC_GET_PRIO handler.

This function calls #_bgrt_proc_get_prio.
*/
bgrt_st_t bgrt_scall_proc_get_prio( bgrt_proc_get_prio_arg_t * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_PROC_GET_ID.

Вызывает #bgrt_curr_proc.

\~english
\brief
A #BGRT_SYSCALL_PROC_GET_ID handler.

This function calls #bgrt_curr_proc.
*/
bgrt_st_t bgrt_scall_proc_get_id( BGRT_PID_T * arg );
/*****************************************************************************************/
/*                                     Scheduler                                         */
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_SCHED_PROC_YELD.

Передаёт управление следующему процессу.

\param arg не используется.

\~english
\brief
A #BGRT_SYSCALL_SCHED_PROC_YELD handler.

Transfers control to another process.

\param arg Not used.
*/
bgrt_st_t bgrt_scall_sched_proc_yeld( bgrt_bool_t * arg );
/*****************************************************************************************/
/*                                        Sync                                           */
/*****************************************************************************************/
#define BGRT_SYNC_INIT(s,p) bgrt_sync_init((bgrt_sync_t *)s, (bgrt_prio_t)p) /*!< \~russian \brief Смотри #bgrt_sync_init. \~english \brief Watch #bgrt_sync_init. */
/*****************************************************************************************/
#define _BGRT_SYNC_INIT(s,p) _bgrt_sync_init((bgrt_sync_t *)s, (bgrt_prio_t)p) /*!< \~russian \brief Смотри #_bgrt_sync_init. \~english \brief Watch #_bgrt_sync_init. */
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
Обработчик вызова #BGRT_SYSCALL_PROC_SET_PRIO.

Вызывает #_bgrt_proc_set_prio.

\param arg Указатель на переменную типа #bgrt_proc_set_prio_arg_t.

\~english
\brief
A #BGRT_SYSCALL_PROC_SET_PRIO handler.

This function calls #_bgrt_proc_set_prio.

\param arg A pointer to #bgrt_proc_set_prio_arg_t object.
*/
bgrt_st_t bgrt_scall_proc_set_prio( bgrt_proc_set_prio_arg_t * arg );
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
    bgrt_st_t status;
}
bgrt_sync_owner_t;
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_SYNC_SET_OWNER.

Вызывает #_bgrt_sync_set_owner.
\~english
\brief
A #BGRT_SYSCALL_SYNC_SET_OWNER handler.

This function calls #_bgrt_sync_set_owner.
*/
bgrt_st_t bgrt_scall_sync_set_owner( bgrt_sync_owner_t * arg );
#define BGRT_SYNC_SET_OWNER(s,p) bgrt_sync_set_owner((bgrt_sync_t *)s, (BGRT_PID_T)p) /*!< \~russian \brief Смотри #bgrt_sync_set_owner. \~english \brief Watch #bgrt_sync_set_owner. */
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_SYNC_GET_OWNER.

Вызывает #_bgrt_sync_set_owner.
\~english
\brief
A #BGRT_SYSCALL_SYNC_GET_OWNER handler.

This function calls #_bgrt_sync_set_owner.
*/
bgrt_st_t bgrt_scall_sync_get_owner( bgrt_sync_owner_t * arg );
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
    bgrt_st_t status;
}bgrt_sync_own_sleep_t;
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_SYNC_OWN.

Вызывает #_bgrt_sync_own.
\~english
\brief
A #BGRT_SYSCALL_SYNC_OWN handler.

This function calls #_bgrt_sync_own.
*/
bgrt_st_t bgrt_scall_sync_own( bgrt_sync_own_sleep_t * arg );
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
    bgrt_st_t status;
}bgrt_sync_touch_t;
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_SYNC_TOUCH.

Вызывает #_bgrt_sync_touch.
\~english
\brief
A #BGRT_SYSCALL_SYNC_TOUCH handler.

This function calls #_bgrt_sync_touch.
*/
bgrt_st_t bgrt_scall_sync_touch( bgrt_sync_touch_t * arg );
#define BGRT_SYNC_TOUCH(s) bgrt_sync_touch( (bgrt_sync_t *)(s) ) /*!< \~russian \brief Смотри #bgrt_sync_touch. \~english \brief Watch #bgrt_sync_touch. */
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_SYNC_SLEEP.

Вызывает #_bgrt_sync_sleep.
\~english
\brief
A #BGRT_SYSCALL_SYNC_SLEEP handler.

This function calls #_bgrt_sync_sleep.
*/
bgrt_st_t bgrt_scall_sync_sleep( bgrt_sync_own_sleep_t * arg );
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
    bgrt_st_t status; /*!< \~russian Результат выполнения. \~english Execution status. */
}
bgrt_sync_wake_t;
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_SYNC_WAKE.

Вызывает #_bgrt_sync_wake.
\~english
\brief
A #BGRT_SYSCALL_SYNC_WAKE handler.

This function calls #_bgrt_sync_wake.
*/
bgrt_st_t bgrt_scall_sync_wake( bgrt_sync_wake_t * arg );
#define BGRT_SYNC_WAKE(s,p,c,st)                                \
do                                                              \
{                                                               \
    volatile bgrt_sync_wake_t scarg;                            \
    scarg.status = BGRT_ST_ROLL;                                \
    scarg.sync = (bgrt_sync_t *)(s);                            \
    scarg.pid = (BGRT_PID_T)(p);                                \
    scarg.chown = (bgrt_flag_t)(c);                             \
    bgrt_syscall( BGRT_SYSCALL_SYNC_WAKE, (void *)&scarg );     \
    (st) = scarg.status;                                        \
}                                                               \
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
    bgrt_st_t status; /*!< \~russian Результат выполнения. \~english Execution status. */
}
bgrt_sync_wait_t;
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_SYNC_WAIT.

Вызывает #_bgrt_sync_wait.
\~english
\brief
A #BGRT_SYSCALL_SYNC_WAIT handler.

This function calls #_bgrt_sync_wait.
*/
bgrt_st_t bgrt_scall_sync_wait( bgrt_sync_wait_t * arg );
#define BGRT_SYNC_WAIT(s,p,b,st)                                \
do                                                              \
{                                                               \
    volatile bgrt_sync_wait_t scarg;                            \
    scarg.status = BGRT_ST_ROLL;                                \
    scarg.sync = (bgrt_sync_t *)(s);                            \
    scarg.pid = (BGRT_PID_T *)(p);                              \
    scarg.block = (bgrt_flag_t)(b);                             \
    bgrt_syscall( BGRT_SYSCALL_SYNC_WAIT, (void *)&scarg );     \
    (st) = scarg.status;                                        \
}                                                               \
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
    bgrt_st_t status;
}
bgrt_sync_proc_timeout_t;
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_SYNC_PROC_TIMEOUT.
\~english
\brief
A #BGRT_SYSCALL_SYNC_PROC_TIMEOUT handler.
*/
bgrt_st_t bgrt_scall_sync_proc_timeout( bgrt_sync_proc_timeout_t * arg );
/*****************************************************************************************/



/*!
\~russian
\brief
Обработчик вызова #BGRT_SYSCALL_USER.
\~english
\brief
A #BGRT_SYSCALL_USER handler.
*/
bgrt_st_t bgrt_scall_user(void * arg);
#endif // _SYSCALL_H_
