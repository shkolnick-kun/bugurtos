/**************************************************************************
    BuguRTOS-0.4.x(Bugurt real time operating system)
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

/*!
\file
\brief Заголовок системных вызовов.
*/

// System call numbers!
#define SYSCALL_PROC_INIT                       ((syscall_t)(1))                                /*!< Инициация процесса. */
#define SYSCALL_PROC_RUN                        (SYSCALL_PROC_INIT + (syscall_t)(1))            /*!< Запуск процесса. */
#define SYSCALL_PROC_RESTART                    (SYSCALL_PROC_RUN + (syscall_t)(1))             /*!< Перезапуск процесса. */
#define SYSCALL_PROC_STOP                       (SYSCALL_PROC_RESTART + (syscall_t)(1))         /*!< Останов процесса. */
#define SYSCALL_PROC_SELF_STOP                  (SYSCALL_PROC_STOP + (syscall_t)(1))            /*!< Самоостанов процесса. */
#define SYSCALL_PROC_TERMINATE                  (SYSCALL_PROC_SELF_STOP + (syscall_t)(1))       /*!< Завершение работы процесса. */
#define SYSCALL_PROC_FLAG_STOP                  (SYSCALL_PROC_TERMINATE + (syscall_t)(1))       /*!< Останов процесса по флагу PROC_FLG_PRE_END. */
#define SYSCALL_PROC_RESET_WATCHDOG             (SYSCALL_PROC_FLAG_STOP + (syscall_t)(1))       /*!< Сброс watchdog процесса реального времени. */

#define SYSCALL_SIG_INIT                        (SYSCALL_PROC_RESET_WATCHDOG + (syscall_t)(1))  /*!< Инициация сигнала. */
#define SYSCALL_SIG_WAIT                        (SYSCALL_SIG_INIT + (syscall_t)(1))             /*!< Ожидание сигнала. */
#define SYSCALL_SIG_SIGNAL                      (SYSCALL_SIG_WAIT + (syscall_t)(1))             /*!< Подача сигнала одному процессу. */
#define SYSCALL_SIG_BROADCAST                   (SYSCALL_SIG_SIGNAL + (syscall_t)(1))           /*!< Подача сигнала всем ожидающим процессам. */

#define SYSCALL_SEM_INIT                        (SYSCALL_SIG_BROADCAST + (syscall_t)(1))        /*!< Инициация семафора. */
#define SYSCALL_SEM_LOCK                        (SYSCALL_SEM_INIT + (syscall_t)(1))             /*!< Захват семафора. */
#define SYSCALL_SEM_TRY_LOCK                    (SYSCALL_SEM_LOCK + (syscall_t)(1))             /*!< Попытка захвата семафора. */
#define SYSCALL_SEM_UNLOCK                      (SYSCALL_SEM_TRY_LOCK + (syscall_t)(1))         /*!< Освобождение семафора. */

#define SYSCALL_MUTEX_INIT                      (SYSCALL_SEM_UNLOCK + (syscall_t)(1))           /*!< Инициация мьютекса. */
#define SYSCALL_MUTEX_LOCK                      (SYSCALL_MUTEX_INIT + (syscall_t)(1))           /*!< Захват мьютекса. */
#define SYSCALL_MUTEX_TRY_LOCK                  (SYSCALL_MUTEX_LOCK + (syscall_t)(1))           /*!< Попытка захвата мьютекса. */
#define SYSCALL_MUTEX_UNLOCK                    (SYSCALL_MUTEX_TRY_LOCK + (syscall_t)(1))       /*!< Освобождение мьютекса. */

#define SYSCALL_IPC_WAIT_P                      (SYSCALL_MUTEX_UNLOCK + (syscall_t)(1))         /*!< Ожидание передачи указателя. */
#define SYSCALL_IPC_WAIT_D                      (SYSCALL_IPC_WAIT_P + (syscall_t)(1))           /*!< Ожидание передачи данных. */
#define SYSCALL_IPC_SEND_P                      (SYSCALL_IPC_WAIT_D + (syscall_t)(1))           /*!< Передача указателя. */
#define SYSCALL_IPC_SEND_D                      (SYSCALL_IPC_SEND_P + (syscall_t)(1))           /*!< Передача данных. */

/*!
\brief
Обработка системного вызова.

Зпускает обработчик системного вызова и передает ему аргумент.
*/
#ifdef CONFIG_MP
/*!
\param syscall_num номер системного вызова.
\param syscall_arg аргумент системного вызова.
*/
void do_syscall( syscall_t syscall_num, void * syscall_arg );
#else
/*!
Номер системного вызова.
*/
extern syscall_t syscall_num;
/*!
Аргумент системного вызова.
*/
extern void * syscall_arg;

void do_syscall( void );
#endif

/*****************************************************************************************/
/*                               System call handlers !!!                                */
/*****************************************************************************************/
//                                   Process control !


/*!
\brief
Параметр системного вызова #SYSCALL_PROC_INIT.

Содержит информацию о процессе, и его свойствах.
*/
typedef struct {
    proc_t * proc;      /*!<Указатель на инициируемый процесс.*/
    code_t pmain;       /*!<Указатель на главную функцию процесса.*/
    code_t sv_hook;     /*!< Хук, исполняется планировщиком после сохранения контекста процесса. */
    code_t rs_hook;     /*!< Хук, исполняется планировщиком перед восстановлением контекста процесса. */
    void * arg;         /*!< Аргумент для pmain, sv_hook, rs_hook. */
    stack_t *sstart;    /*!< Указатель на дно стека экземпляра процесса. */
    prio_t prio;        /*!<Приоритет.*/
    timer_t time_quant; /*!<Квант времени.*/
    bool_t is_rt;       /*!Флаг реального времени, если true, значит процесс будет иметь поведение RT.*/
#ifdef CONFIG_MP
    affinity_t affinity;/*!<Афинность.*/
#endif // CONFIG_MP
} proc_init_arg_t;

/*!
\brief
Обработчик вызова #SYSCALL_PROC_INIT.

Инициализирует процесс, вызывая #proc_init_isr.

\param arg указатель на структуру #proc_init_arg_t.
*/
void scall_proc_init( void * arg );
/*****************************************************************************************/
/*!
\brief
Параметр системных вызовов #SYSCALL_PROC_RUN, #SYSCALL_PROC_RESTART, #SYSCALL_PROC_STOP.
*/
typedef struct{
    proc_t * proc;      /*!<Указатель на процесс.*/
    bool_t ret;         /*!<Результат выполнения системного вызова.*/
}proc_runtime_arg_t;

/*!
\brief
Обработчик вызова #SYSCALL_PROC_RUN.

Пытается запустить процесс, вызывая #proc_run_isr.

\param arg указатель на структуру #proc_runtime_arg_t.
*/
void scall_proc_run( void * arg );
/*!
\brief
Обработчик вызова #SYSCALL_PROC_RESTART.

Пытается перезапустить процесс, вызывая #proc_restart_isr.

\param arg указатель на структуру #proc_runtime_arg_t.
*/
void scall_proc_restart( void * arg );
/*!
\brief
Обработчик вызова #SYSCALL_PROC_STOP.

Пытается остановить процесс, вызывая #proc_stop_isr.

\param arg указатель на структуру #proc_runtime_arg_t.
*/
void scall_proc_stop( void * arg );
/*****************************************************************************************/
/*!
\brief
Обработчик вызова #SYSCALL_PROC_SELF_STOP.

Останавливает вызывающий процесс.

\param arg не используется.
*/
void scall_proc_self_stop( void * arg );
/*****************************************************************************************/
/*!
\brief
Обработчик вызова #SYSCALL_PROC_TERMINATE.

Завершает выполенение процесса после выхода из pmain. Вызывает #_proc_terminate.

\param arg указатель на процесс.
*/
void scall_proc_terminate( void * arg );
/*****************************************************************************************/
/*!
\brief
Обработчик вызова #SYSCALL_PROC_FLAG_STOP.

Пытается остановить вызывающий процесс по флагу #PROC_FLG_PRE_END, обнуляет флаги, заданные маской.
Вызывает #_proc_flag_stop.

\param arg указатель на маску обнуления флагов процесса.
*/
void scall_proc_flag_stop( void * arg );
/*****************************************************************************************/
/*!
\brief
Обработчик вызова #SYSCALL_PROC_RESET_WATCHDOG.

Вызывает #_proc_reset_watchdog.

\param arg не используется.
*/
void scall_proc_reset_watchdog( void * arg );
/*****************************************************************************************/
//                                 Signal control!
/*!
\brief
Обработчик вызова #SYSCALL_SIG_INIT.

Инициализирует сигнал, вызывает #sig_init_isr.

\param arg указатель на сигнал.
*/
void scall_sig_init( void * arg );
/*!
\brief
Обработчик вызова #SYSCALL_SIG_WAIT.

Переводит вызваший процесс в состояние ожидания сигнала, вызывает #_sig_wait_prologue.

\param arg указатель на сигнал.
*/
void scall_sig_wait( void * arg );
/*!
\brief
Обработчик вызова #SYSCALL_SIG_SIGNAL.

"Будит" один из процессов, ожидающих сигнала, вызывает #sig_signal_isr.

\warning На многопроцессорной не действует принцип FIFO при "пробуждении" процессов,
вставленных в списки ожидания для разных процессоров!

\param arg указатель на сигнал.
*/
void scall_sig_signal( void * arg );
/*!
\brief
Обработчик вызова #SYSCALL_SIG_WAIT.

"Будит" все процессы , ожидающиe сигнала, вызывает #sig_broadcast_isr.

\param arg указатель на сигнал.
*/
void scall_sig_broadcast( void * arg );
/*****************************************************************************************/
/*                                 Semaphore control !                                   */
/*!
\brief
Параметр системного вызова #SYSCALL_SEM_INIT.
*/
typedef struct {
    sem_t * sem;    /*!< указатель на семафор. */
    count_t count;  /*!< начальное значение счетчика семафора. */
}sem_init_arg_t;
/*!
\brief
Обработчик вызова #SYSCALL_SEM_INIT.

Инициирует семафор, вызывает #sem_init_isr.

\param arg указатель на аргумент типа #sem_init_arg_t.
*/
void scall_sem_init( void * arg );
/*****************************************************************************************/
/*!
\brief
Параметр системных вызовов #SYSCALL_SEM_LOCK и #SYSCALL_SEM_TRY_LOCK.
*/
typedef struct {
    sem_t * sem;        /*!< указатель на семафор. */
    bool_t ret;         /*!< хранилище результата выполнения операции. */
}sem_lock_arg_t;
/*!
\brief
Обработчик вызова #SYSCALL_SEM_LOCK.

Вызывает #_sem_lock.

\param arg указатель на аргумент типа #sem_lock_arg_t.
*/
void scall_sem_lock( void * arg );
/*!
\brief
Обработчик вызова #SYSCALL_SEM_TRY_LOCK.

Вызывает #_sem_try_lock.

\param arg указатель на аргумент типа #sem_lock_arg_t.
*/
void scall_sem_try_lock( void * arg );
/*****************************************************************************************/
/*!
\brief
Обработчик вызова #SYSCALL_SEM_UNLOCK.

Вызывает #sem_unlock_isr.

\param arg указатель на семафор
*/
void scall_sem_unlock( void * arg );
/*****************************************************************************************/
/*                                     Мьютексы                                          */
/*!
\brief
Параметр системного вызова #SYSCALL_MUTEX_INIT.
*/
typedef struct {
    mutex_t * mutex;    /*!< указатель на мьютекс. */
#ifdef CONFIG_USE_HIGHEST_LOCKER
    prio_t prio;        /*!< приоритет мьютекса */
#endif // CONFIG_USE_HIGHEST_LOCKER
}mutex_init_arg_t;
/*!
\brief
Обработчик вызова #SYSCALL_MUTEX_INIT.

Инициирует мьютекс, вызывает #mutex_init_isr.

\param arg указатель на аргумент типа #mutex_init_arg_t.
*/
void scall_mutex_init(void * arg);
/*****************************************************************************************/
/*!
\brief
Параметр системных вызовов #SYSCALL_MUTEX_LOCK и #SYSCALL_MUTEX_TRY_LOCK.
*/
typedef struct {
    mutex_t * mutex;    /*!< указатель на мьютекс. */
    bool_t ret;         /*!< хранилище результата выполнения операции. */
} mutex_lock_arg_t;
/*!
\brief
Обработчик вызова #SYSCALL_MUTEX_LOCK.

Вызывает #_mutex_lock.

\param arg указатель на аргумент типа #mutex_lock_arg_t.
*/
void scall_mutex_lock(void * arg);
/*!
\brief
Обработчик вызова #SYSCALL_MUTEX_TRY_LOCK.

Вызывает #_mutex_try_lock.

\param arg указатель на аргумент типа #mutex_lock_arg_t.
*/
void scall_mutex_try_lock(void * arg);
/*!
\brief
Обработчик вызова #SYSCALL_MUTEX_UNLOCK.

Вызывает #_mutex_unlock.

\param arg указатель на мьютекс.
*/
void scall_mutex_unlock(void * arg);
/*****************************************************************************************/
/*                                     IPC                                               */
/*!
\brief
Параметр системного вызова #SYSCALL_IPC_SEND_D.
*/
typedef struct {
    proc_t * proc;  /*!< указатель на процесс-адресат. */
    bool_t ret;     /*!< хранилище результата выполнения операции. */
    ipc_data_t data;/*!< данные для передачи. */
} ipc_send_data_arg_t;
/*!
\brief
Параметр системного вызова #SYSCALL_IPC_SEND_P.
*/
typedef struct {
    proc_t * proc;  /*!< указатель на процесс-адресат. */
    bool_t ret;     /*!< хранилище результата выполнения операции. */
    void * pointer; /*!< указатель для передачи. */
} ipc_send_pointer_arg_t;
/*!
\brief
Обработчик вызова #SYSCALL_IPC_WAIT_P.

Переводит вызывающий процесс в состояние ожидания получения указателя через IPC. Вызывает #_ipc_wait.

\param arg указатель на хранилище для передачи указателя.
*/
void scall_ipc_wait_pointer(void * arg);
/*!
\brief
Обработчик вызова #SYSCALL_IPC_WAIT_D.

Переводит вызывающий процесс в состояние ожидания получения данных через IPC. Вызывает #_ipc_wait.

\param arg указатель на хранилище для передачи данных.
*/
void scall_ipc_wait_data(void * arg);
/*!
\brief
Обработчик вызова #SYSCALL_IPC_SEND_P.

Вызывает #ipc_send_pointer_isr.

\param arg указатель на аргумент типа #ipc_send_pointer_arg_t.
*/
void scall_ipc_send_pointer(void * arg);
/*!
\brief
Обработчик вызова #SYSCALL_IPC_SEND_D.

Вызывает #ipc_send_data_isr.

\param arg указатель на аргумент типа #ipc_send_data_arg_t.
*/
void scall_ipc_send_data(void * arg);
#endif // _SYSCALL_H_
