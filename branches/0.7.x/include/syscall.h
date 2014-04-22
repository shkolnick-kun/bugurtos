/**************************************************************************
    BuguRTOS-0.6.x(Bugurt real time operating system)
    Copyright (C) 2013  anonimous

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
\brief \~russian Заголовок системных вызовов. \~english System call header.
*/

// System call numbers!
#define SYSCALL_PROC_RUN                        ((syscall_t)(1))                                /*!< \~russian Запуск процесса. \~english A process launch. */
#define SYSCALL_PROC_RESTART                    (SYSCALL_PROC_RUN + (syscall_t)(1))             /*!< \~russian Перезапуск процесса. \~english A Process restart. */
#define SYSCALL_PROC_STOP                       (SYSCALL_PROC_RESTART + (syscall_t)(1))         /*!< \~russian Останов процесса. \~english A process stop. */
#define SYSCALL_PROC_SELF_STOP                  (SYSCALL_PROC_STOP + (syscall_t)(1))            /*!< \~russian Самоостанов процесса. \~english A process self stop. */
#define SYSCALL_PROC_YELD                       (SYSCALL_PROC_SELF_STOP + (syscall_t)(1))       /*!< \~russian Передача управления другому процессу. \~english Transfer control to another process. */
#define SYSCALL_PROC_TERMINATE                  (SYSCALL_PROC_YELD + (syscall_t)(1))            /*!< \~russian Завершение работы процесса. \~english A process termination. */
#define SYSCALL_PROC_FLAG_STOP                  (SYSCALL_PROC_TERMINATE + (syscall_t)(1))       /*!< \~russian Останов процесса по флагу #PROC_FLG_PRE_STOP. \~english #PROC_FLG_PRE_STOP flag processing. */
#define SYSCALL_PROC_RESET_WATCHDOG             (SYSCALL_PROC_FLAG_STOP + (syscall_t)(1))       /*!< \~russian Сброс watchdog процесса реального времени. \~english A real time process watchdog reset. */
#define SYSCALL_PROC_SET_PRIO                   (SYSCALL_PROC_RESET_WATCHDOG + (syscall_t)(1))       /*!< \~russian !!!!!!!!!!!!!!! \~english !!!!!!!!!!!!!!!!!! */

#define SYSCALL_SIG_WAIT                        (SYSCALL_PROC_SET_PRIO + (syscall_t)(1))             /*!< \~russian Ожидание сигнала. \~english Wait for signal. */
#define SYSCALL_SIG_WAKEUP                      (SYSCALL_SIG_WAIT + (syscall_t)(1))             /*!< \~russian Обработка запуска по сигналу. \~english Signal wakeup processing. */
#define SYSCALL_SIG_SIGNAL                      (SYSCALL_SIG_WAKEUP + (syscall_t)(1))           /*!< \~russian Подача сигнала одному процессу. \~english Signal to one waiting process. */
#define SYSCALL_SIG_BROADCAST                   (SYSCALL_SIG_SIGNAL + (syscall_t)(1))           /*!< \~russian Подача сигнала всем ожидающим процессам. \~english Signal to all waiting processes. */

#define SYSCALL_SEM_LOCK                        (SYSCALL_SIG_BROADCAST + (syscall_t)(1))             /*!< \~russian Захват семафора. \~english Lock a semaphore. */
#define SYSCALL_SEM_TRY_LOCK                    (SYSCALL_SEM_LOCK + (syscall_t)(1))             /*!< \~russian Попытка захвата семафора. \~english Try yo lock a semaphore. */
#define SYSCALL_SEM_FREE                      (SYSCALL_SEM_TRY_LOCK + (syscall_t)(1))         /*!< \~russian Освобождение семафора. \~english Unlock a semaphore. */

#define SYSCALL_MUTEX_LOCK                      (SYSCALL_SEM_FREE + (syscall_t)(1))           /*!< \~russian Захват мьютекса. \~english Lock a mutex. */
#define SYSCALL_MUTEX_TRY_LOCK                  (SYSCALL_MUTEX_LOCK + (syscall_t)(1))           /*!< \~russian Попытка захвата мьютекса. \~english Try to lock a mutex. */
#define SYSCALL_MUTEX_FREE                    (SYSCALL_MUTEX_TRY_LOCK + (syscall_t)(1))       /*!< \~russian Освобождение мьютекса. \~english Unlock a mutex. */

#define SYSCALL_IPC_WAIT                        (SYSCALL_MUTEX_FREE + (syscall_t)(1))         /*!< \~russian Ожидание передачи данных. \~english Wait for data (IPC). */
#define SYSCALL_IPC_SEND                        (SYSCALL_IPC_WAIT + (syscall_t)(1))             /*!< \~russian Передача данных. \~english Send data via IPC. */
#define SYSCALL_IPC_EXCHANGE                    (SYSCALL_IPC_SEND + (syscall_t)(1))             /*!< \~russian Обмен данными. \~english Exchange data via IPC. */

#define SYSCALL_USER                            (SYSCALL_IPC_EXCHANGE + (syscall_t)(1))         /*!< \~russian Пользовательский системный вызов. \~english A user syscall. */

/*!
\~russian
\brief
Обработка системного вызова.

Зпускает обработчик системного вызова и передает ему аргумент.

\~english
\brief
System call processing routine.

This function calls system call handlers and passes arguments to them.
*/
#ifdef CONFIG_MP
void do_syscall(
                syscall_t syscall_num,  /*!< \~russian Номер системного вызова. \~english System call number.*/
                void * syscall_arg      /*!< \~russian Aргумент системного вызова. \~english System call argument.*/
                );
#else
/*!
\~russian Номер системного вызова. \~english System call number.
*/
extern syscall_t syscall_num;
/*!
\~russian Аргумент системного вызова. \~english System call argument.
*/
extern void * syscall_arg;

void do_syscall( void );
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
Обработчик вызова #SYSCALL_PROC_YELD.

Передает управление следующему процессу.

\param arg не используется.

\~english
\brief
A #SYSCALL_PROC_YELD handler.

Transfers control to another process.

\param arg Not used.
*/
void scall_sched_yeld( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_PROC_TERMINATE.

Завершает выполенение процесса после выхода из pmain. Вызывает #_proc_terminate.

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
Обработчик вызова #SYSCALL_PROC_FLAG_STOP.

Пытается остановить вызывающий процесс по флагу #PROC_FLG_PRE_STOP, обнуляет флаги, заданные маской.
Вызывает #_proc_flag_stop.

\param arg указатель на маску обнуления флагов процесса.

\~english
\brief
A #SYSCALL_PROC_FLAG_STOP handler.

This function process #PROC_FLG_PRE_STOP of the calling process and clears masked flags of a calling process.
It calls #_proc_flag_stop.

\param arg A poointer to a flag mask.
*/
void scall_proc_flag_stop( void * arg );
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
!!!!!!!!!!!!!!!!!!!!!

!!!!!!!!!!!!!!!!!!!!

\param arg !!!!!!!!!!!!!!!!!!!!!!!!!

\~english
\brief
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

!!!!!!!!!!!!!!!!!!!!!!

\param arg !!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
void scall_proc_set_prio( void * arg );
/*****************************************************************************************/
//                                 Signal control!
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SIG_INIT.

Инициализирует сигнал, вызывает #sig_init_isr.

\param arg указатель на сигнал.

\~english
\brief
A #SYSCALL_SIG_INIT handler.

Initiates a signal by #sig_init_isr call.

\param arg A pointer to a signal.
*/
void scall_sig_init( void * arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SIG_WAIT.

Переводит вызваший процесс в состояние ожидания сигнала, вызывает #_sig_wait_prologue.

\param arg указатель на сигнал.

\~english
\brief
A #SYSCALL_SIG_WAIT hadnler.

Transfers a caller process in to signal wait state by #_sig_wait_prologue call.

\param arg A pointer to a signal.
*/
void scall_sig_wait( void * arg );
void scall_sig_wakeup( void *arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SIG_SIGNAL.

"Будит" один из процессов, ожидающих сигнала, вызывает #sig_signal_isr.

\warning На многопроцессорной не действует принцип FIFO при "пробуждении" процессов,
вставленных в списки ожидания для разных процессоров!

\param arg указатель на сигнал.

\~english
\brief
A #SYSCALL_SIG_SIGNAL handler.

Wakes up one waiting process by #sig_signal_isr call.

\warning On a multicore system processes aren't woken up in a FIFO manner!

\param arg A pointer to a signal.
*/
void scall_sig_signal( void * arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SIG_BROADCAST.

"Будит" все процессы , ожидающиe сигнала, вызывает #sig_broadcast_isr.

\param arg указатель на сигнал.

\~english
\brief
A #SYSCALL_SIG_BROADCAST handler.

This function wakes up all waiting processes by #sig_broadcast_isr call.

\param arg A pointer to a signal.
*/
void scall_sig_broadcast( void * arg );
/*****************************************************************************************/
/*                                 Semaphore control !                                   */

/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SEM_INIT.

Инициирует семафор, вызывает #sem_init_isr.

\param arg указатель на аргумент типа #sem_init_arg_t.

\~english
\brief
A #SYSCALL_SEM_INIT handler.

This function initiates semaphore by #sem_init_isr call.

\param arg A pointer to a #sem_init_arg_t structure.
*/
void scall_sem_init( void * arg );
/*****************************************************************************************/

/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SEM_LOCK.

Вызывает #_sem_lock.

\param arg указатель на аргумент типа #sem_lock_arg_t.

\~english
\brief
A #SYSCALL_SEM_LOCK handler.

This function calls #_sem_lock.

\param arg A pointer to an #sem_lock_arg_t object.
*/
void scall_sem_lock( void * arg );
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SEM_TRY_LOCK.

Вызывает #_sem_try_lock.

\param arg указатель на аргумент типа #sem_lock_arg_t.

\~english
\brief
A #SYSCALL_SEM_TRY_LOCK handler.

This function calls #_sem_try_lock.

\param arg A pointer to an #sem_lock_arg_t object.
*/
void scall_sem_try_lock( void * arg );
/*****************************************************************************************/
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_SEM_FREE.

Вызывает #sem_free_isr.

\param arg указатель на семафор.

\~english
\brief
A #SYSCALL_SEM_FREE handler.

This function calls #sem_free_isr.

\param arg A pointer to a semaphore.
*/
void scall_sem_free( void * arg );
/*****************************************************************************************/
/*                                     Мьютексы                                          */

/*!
\~russian
\brief
Обработчик вызова #SYSCALL_MUTEX_INIT.

Инициирует мьютекс, вызывает #mutex_init_isr.

\param arg указатель на аргумент типа #mutex_init_arg_t.

\~english
\brief
A #SYSCALL_MUTEX_INIT handler.

This function initiater mutex by #mutex_init_isr call.

\param arg A poiner to an #mutex_init_arg_t object.
*/
void scall_mutex_init(void * arg);
/*****************************************************************************************/

/*!
\~russian
\brief
Обработчик вызова #SYSCALL_MUTEX_LOCK.

Вызывает #_mutex_lock.

\param arg указатель на аргумент типа #mutex_lock_arg_t.

\~english
\brief
A #SYSCALL_MUTEX_LOCK handler.

This function calls #_mutex_lock.

\param arg A pointer to an #mutex_lock_arg_t object.
*/
void scall_mutex_lock(void * arg);
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_MUTEX_TRY_LOCK.

Вызывает #_mutex_try_lock.

\param arg указатель на аргумент типа #mutex_lock_arg_t.

\~english
\brief
A #SYSCALL_MUTEX_TRY_LOCK handler.

This function calls #_mutex_try_lock.

\param arg A #mutex_lock_arg_t pointer.
*/
void scall_mutex_try_lock(void * arg);
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_MUTEX_FREE.

Вызывает #_mutex_free.

\param arg указатель на мьютекс.

\~english
\brief
A #SYSCALL_MUTEX_FREE handler.

This function calls #_mutex_free.

\param arg A pointer to a mutex.
*/
void scall_mutex_free(void * arg);
/*****************************************************************************************/
/*                                     IPC                                               */

/*!
\~russian
\brief
Обработчик вызова #SYSCALL_IPC_WAIT.

Переводит вызывающий процесс в состояние ожидания получения данных через IPC. Вызывает #_ipc_wait.

\param arg указатель на хранилище для передачи данных.

\~english
\brief
A #SYSCALL_IPC_WAIT handler.

This funtion transfers a caller process to IPC wait state by #_ipc_wait call.

\param arg A pointer to storage for data to receive.
*/
void scall_ipc_wait(void * arg);
/*!
\~russian
\brief
Обработчик вызова #SYSCALL_IPC_SEND.

Вызывает #ipc_send_isr.

\param arg указатель на аргумент типа #ipc_send_arg_t.

\~english
\brief
A #SYSCALL_IPC_SEND handler.

This function tries to transfer data to waiting process by #ipc_send_isr call.

\param arg A #ipc_send_arg_t pointer.
*/
void scall_ipc_send(void * arg);


/*!
\~russian
\brief
Обработчик вызова #SYSCALL_IPC_EXCHANGE.

Вызывает #_ipc_exchange.

\param arg указатель на аргумент типа #ipc_send_arg_t.

\~english
\brief
A #SYSCALL_IPC_EXCHANGE handler.

This function tries to transfer data to waiting process and on success transfers a caller process to IPC wait state.
This function calls #_ipc_exchange.

\param arg A #ipc_exchange_arg_t pointer.
*/
void scall_ipc_exchange( void * arg );

/*!
\~russian
\brief
Обработчик вызова #SYSCALL_USER.

Вызывает пользовательскую функцию.

\param arg указатель на функцию пользователя.
\warning Осторожно! Параметр не проверяется!

\~english
\brief
A #SYSCALL_USER handler.

Calls user function.

\param arg A pointer to a callee.
\warning Be carefull! Callee pointer is not checked before call!
*/
void scall_user(void * arg);
#endif // _SYSCALL_H_
