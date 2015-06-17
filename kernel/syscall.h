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
#define SYSCALL_PROC_RUN                        ((syscall_t)(1))                                /*!< \~russian \brief Запуск процесса. \~english \brief A process launch. */
#define SYSCALL_PROC_RESTART                    (SYSCALL_PROC_RUN + (syscall_t)(1))             /*!< \~russian \brief Перезапуск процесса. \~english \brief A Process restart. */
#define SYSCALL_PROC_STOP                       (SYSCALL_PROC_RESTART + (syscall_t)(1))         /*!< \~russian \brief Останов процесса. \~english \brief A process stop. */
#define SYSCALL_PROC_SELF_STOP                  (SYSCALL_PROC_STOP + (syscall_t)(1))            /*!< \~russian \brief Самоостанов процесса. \~english \brief A process self stop. */
#define SYSCALL_PROC_TERMINATE                  (SYSCALL_PROC_SELF_STOP + (syscall_t)(1))       /*!< \~russian \brief Завершение работы процесса. \~english \brief A process termination. */
#define SYSCALL_PROC_LOCK                       (SYSCALL_PROC_TERMINATE + (syscall_t)(1))       /*!< \~russian \brief Установить флаг #PROC_FLG_LOCK для вызывающего процесса. \~english \brief #PROC_FLG_LOCK for caller process. */
#define SYSCALL_PROC_FREE                       (SYSCALL_PROC_LOCK + (syscall_t)(1))            /*!< \~russian \brief Останов процесса по флагу #PROC_FLG_PRE_STOP. \~english \brief #PROC_FLG_PRE_STOP flag processing. */
#define SYSCALL_PROC_RESET_WATCHDOG             (SYSCALL_PROC_FREE + (syscall_t)(1))            /*!< \~russian \brief Сброс watchdog процесса реального времени. \~english \brief A real time process watchdog reset. */
#define SYSCALL_PROC_SET_PRIO                   (SYSCALL_PROC_RESET_WATCHDOG + (syscall_t)(1))  /*!< \~russian \brief Установить приоритет процесса \~english \brief Set a process priority. */

#define SYSCALL_SCHED_PROC_YELD                 (SYSCALL_PROC_SET_PRIO + (syscall_t)(1))        /*!< \~russian \brief Передача управления другому процессу. \~english \brief Transfer control to another process. */

#define SYSCALL_SYNC_SET_OWNER                 (SYSCALL_SCHED_PROC_YELD + (syscall_t)(1))       /*!< \~russian \brief Установить нового хозяина объекта типа #sync_t. \~english \brief Set new #sync_t object owner. */
#define SYSCALL_SYNC_OWN                       (SYSCALL_SYNC_SET_OWNER + (syscall_t)(1))        /*!< \~russian \brief Завладеть объектом типа #sync_t. \~english \brief Own #sync_t object. */
#define SYSCALL_SYNC_SLEEP                     (SYSCALL_SYNC_OWN + (syscall_t)(1))              /*!< \~russian \brief Заблокировать процесс в ожидании синхронизации. \~english \brief Block process for synchronization. */
#define SYSCALL_SYNC_WAKE                      (SYSCALL_SYNC_SLEEP + (syscall_t)(1))            /*!< \~russian \brief Запустить процесс, ожидающий синхронизации. \~english \brief Run a process waiting for synchronization. */

#define SYSCALL_SYNC_WAIT                      (SYSCALL_SYNC_WAKE + (syscall_t)(1))             /*!< \~russian \brief Подождать блокировки процесса на объекте типа #sync_t. \~english \brief Wait for process to block on #sync_t object*/
#define SYSCALL_SYNC_WAKE_AND_SLEEP            (SYSCALL_SYNC_WAIT + (syscall_t)(1))             /*!< \~russian \brief Смотри #SYSCALL_SYNC_WAKE и #SYSCALL_SYNC_SLEEP. \~english \brief Watch #SYSCALL_SYNC_WAKE and #SYSCALL_SYNC_SLEEP. */
#define SYSCALL_SYNC_WAKE_AND_WAIT             (SYSCALL_SYNC_WAKE_AND_SLEEP + (syscall_t)(1))   /*!< \~russian \brief Смотри #SYSCALL_SYNC_WAKE и #SYSCALL_SYNC_WAIT. \~english \brief Watch #SYSCALL_SYNC_WAKE and #SYSCALL_SYNC_WAIT. */
#define SYSCALL_SYNC_PROC_TIMEOUT              (SYSCALL_SYNC_WAKE_AND_WAIT + (syscall_t)(1))   /*!< \~russian \brief Разбудить процесс по таймауту. \~english \brief Wake a process on timeout. */
#define SYSCALL_USER                           (SYSCALL_SYNC_PROC_TIMEOUT + (syscall_t)(1))    /*!< \~russian \brief Пользовательский системный вызов. \~english \brief User system call. */
/*!
\~russian
\brief
Обработка системного вызова.

Запускает обработчик системного вызова и передает ему аргумент.

\~english
\brief
System call processing routine.

This function calls system call handlers and passes arguments to them.
*/

#ifdef CONFIG_MP
void do_syscall(
                syscall_t syscall_num,  /*!< \~russian \brief Номер системного вызова. \~english \brief System call number.*/
                void * syscall_arg      /*!< \~russian \brief Aргумент системного вызова. \~english \brief System call argument.*/
                );
#else
void do_syscall( void );

extern syscall_t syscall_num; /*!< \~russian \brief Номер системного вызова. \~english \brief System call number.*/
extern void * syscall_arg; /*!< \~russian \brief Аргумент системного вызова. \~english \brief System call argument.*/
#endif

/*****************************************************************************************/
/*                               System call handlers !!!                                */
/*****************************************************************************************/
//                                   Process control !
/*****************************************************************************************/


/*!
\~russian
\brief
Обработчик вызова #SYSCALL_PROC_RUN.

Пытается запустить процесс, вызывая #proc_run_isr.

\param arg указатель на структуру #proc_runtime_arg_t.

\~english
\brief
A #SYSCALL_PROC_RUN handler.

This function tries to launch a process by #proc_run_isr call.

\param arg A #proc_runtime_arg_t pointer.
*/
void scall_proc_run( void * arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_PROC_RESTART.

Пытается перезапустить процесс, вызывая #proc_restart_isr.

\param arg указатель на структуру #proc_runtime_arg_t.

\~english
\brief
A #SYSCALL_PROC_RESTART handler.

This function tries to restart a process by #proc_restart_isr call.

\param arg A #proc_runtime_arg_t pointer.
*/
void scall_proc_restart( void * arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_PROC_STOP.

Пытается остановить процесс, вызывая #proc_stop_isr.

\param arg указатель на структуру #proc_runtime_arg_t.

\~english
\brief
A #SYSCALL_PROC_STOP handler.

This function tries to stop a process by #proc_stop_isr call.

\param arg A #proc_runtime_arg_t pointer.
*/
void scall_proc_stop( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_PROC_SELF_STOP.

Останавливает вызывающий процесс.

\param arg не используется.

\~english
\brief
A #SYSCALL_PROC_SELF_STOP handler.

This function stops calling process.

\param arg Not used.
*/
void scall_proc_self_stop( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SCHED_PROC_YELD.

Передает управление следующему процессу.

\param arg не используется.

\~english
\brief
A #SYSCALL_SCHED_PROC_YELD handler.

Transfers control to another process.

\param arg Not used.
*/
void scall_sched_proc_yeld( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_PROC_TERMINATE.

Завершает выполнение процесса после выхода из pmain. Вызывает #_proc_terminate.

\param arg указатель на процесс.

\~english
\brief
A #SYSCALL_PROC_TERMINATE handler.

This function terminates calling process after pmain return by #_proc_terminate call.

\param arg A pointer to a process.
*/
void scall_proc_terminate( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_PROC_LOCK.

Устанавливает флаг #PROC_FLG_LOCK для вызывающего процесса, увеличивает счетчик proc->lres.

\~english
\brief
A #SYSCALL_PROC_LOCK handler.

Sets #PROC_FLG_NONSTOP for caller process, increases proc->lres counter.
*/
void scall_proc_lock( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_PROC_FREE.

Уменьшает счетчик proc->lres, при необходимости обнуляет флаг #PROC_FLG_LOCK, пытается остановить вызывающий процесс по флагу #PROC_FLG_PRE_STOP.
Вызывает #_proc_free.

\param arg указатель на маску обнуления флагов процесса.

\~english
\brief
A #SYSCALL_PROC_FREE handler.

This function decreases proc->lres counter, clears #PROC_FLG_LOCK if needed and, process #PROC_FLG_PRE_STOP of the calling process and clears masked flags of a calling process.
It calls #_proc_free.

\param arg A pointer to a flag mask.
*/
void scall_proc_free( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_PROC_RESET_WATCHDOG.

Вызывает #_proc_reset_watchdog.

\param arg не используется.

\~english
\brief
A #SYSCALL_PROC_RESET_WATCHDOG handler.

This function calls #_proc_reset_watchdog.

\param arg Not used.
*/
void scall_proc_reset_watchdog( void * arg );

/*!
\~russian
\brief
Обработчик вызова #SYSCALL_PROC_SET_PRIO.

Вызывает #_proc_set_prio.

\param arg Указатель на переменную типа #proc_set_prio_arg_t.

\~english
\brief
A #SYSCALL_PROC_SET_PRIO handler.

This function calls #_proc_set_prio.

\param arg A pointer to #proc_set_prio_arg_t object.
*/
void scall_proc_set_prio( void * arg );
/*****************************************************************************************/
//                            Basic synchronization primitive
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SYNC_SET_OWNER.

Вызывает #_sync_set_owner.
\~english
\brief
A #SYSCALL_SYNC_SET_OWNER handler.

This function calls #_sync_set_owner.
*/
void scall_sync_set_owner( void * arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SYNC_OWN.

Вызывает #_sync_own.
\~english
\brief
A #SYSCALL_SYNC_OWN handler.

This function calls #_sync_own.
*/
void scall_sync_own( void * arg );

/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SYNC_SLEEP.

Вызывает #_sync_sleep.
\~english
\brief
A #SYSCALL_SYNC_SLEEP handler.

This function calls #_sync_sleep.
*/
void scall_sync_sleep( void * arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SYNC_WAKE.

Вызывает #_sync_wake.
\~english
\brief
A #SYSCALL_SYNC_WAKE handler.

This function calls #_sync_wake.
*/
void scall_sync_wake( void * arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SYNC_WAIT.

Вызывает #_sync_wait.
\~english
\brief
A #SYSCALL_SYNC_WAIT handler.

This function calls #_sync_wait.
*/
void scall_sync_wait( void * arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SYNC_WAKE_AND_SLEEP.
\~english
\brief
A #SYSCALL_SYNC_WAKE_AND_SLEEP handler.
*/
void scall_sync_wake_and_sleep( void * arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SYNC_WAKE_AND_WAIT.
\~english
\brief
A #SYSCALL_SYNC_WAKE_AND_WAIT handler.
*/
void scall_sync_wake_and_wait( void * arg );

/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SYNC_PROC_TIMEOUT.
\~english
\brief
A #SYSCALL_SYNC_PROC_TIMEOUT handler.
*/
void scall_sync_proc_timeout( void * arg );

/*!
\~russian
\brief
Обработчик вызова #SYSCALL_USER.
\~english
\brief
A #SYSCALL_USER handler.
*/
void scall_user(void * arg);
#endif // _SYSCALL_H_
