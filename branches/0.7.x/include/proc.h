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
#ifndef _PROC_H_
#define _PROC_H_
/*!
\file
\~russian
\brief Заголовок процессов.
\~english
\brief A process header.
*/

/*!
\~russian

\def PROC_LRES_INIT(a)
\brief Макрос-обертка.

Инициирует поле proc->lres процесса.

\param a указатель на процесс.

\def PROC_LRES_INC(a,b)
\brief Макрос-обертка.

Инкремент счетчика захваченных мьютексов.

\param a указатель на процесс.
\param b приоритет захваченного мьютекса, если используется протокол highest locker.

\def PROC_LRES_DEC(a,b)
\brief Макрос-обертка.

Декремент счетчика захваченных мьютексов.

\param a указатель на процесс.
\param b приоритет захваченного мьютекса, если используется протокол highest locker.

\def PROC_PRIO_CONTROL_STOPED(a)
\brief Макрос-обертка.

Управление приоритетом остановленного процесса.
В случае использования протокола highest locker приводит
поле proc->group->prio в соответствие с полем proc->lres,
иначе - пустой макрос.

\param a указатель на процесс.

\~english

\def PROC_LRES_INIT(a)
\brief Wrapper macro.

Initiates proc->lres field of a process.

\param a a pointer to a process.

\def PROC_LRES_INC(a,b)
\brief Wrapper macro.

An increment of locked mutex counter field of a process.

\param a a pointer to a process.
\param b a priority of a locked mutex for highest locker protocol.

\def PROC_LRES_DEC(a,b)
\brief Wrapper macro.

A decrement of locked mutex counter field of a process.

\param a a pointer to a process.
\param b a priority of a locked mutex for highest locker protocol.

\def PROC_PRIO_CONTROL_STOPED(a)
\brief Wrapper macro.

Stoped process priority control.
If highest locker protocol is used,
then this macro computes a proc->group->prio using proc->lres field,
else this macro does nothing.

\param a a pointer to a process.

*/
#ifdef CONFIG_USE_HIGHEST_LOCKER

#define PROC_LRES_INIT(a) pcounter_init(&a->lres)
#define PROC_LRES_INC(a,b) _proc_lres_inc(a,b)
#define PROC_LRES_DEC(a,b) _proc_lres_dec(a,b)

#define PROC_PRIO_CONTROL_STOPED(a) _proc_prio_control_stoped(a)

#else

#define PROC_LRES_INIT(a) a->lres = (count_t)0
#define PROC_LRES_INC(a,b) _proc_lres_inc(a)
#define PROC_LRES_DEC(a,b) _proc_lres_dec(a)

#define PROC_PRIO_CONTROL_STOPED(a)

#endif

//Процесс
typedef struct _proc_t proc_t;
// Свойства
/*!
\~russian
\brief Процесс.

В разных ОС это называется по разному: процесс, поток, задача и пр., суть такова: это независимый поток исполнения инструкций процессора.

То есть это исполняющийся кусок твоей программы, у которого есть своя собственная «main» (смотри поле pmain), и эта «main» может быть написана так, как будто других процессов нет!

Можно использовать 1 функцию pmain для нескольких процессов, каждый запущенный экземпляр pmain не зависит от других, но есть одно но.
\warning Осторожно со статическими переменными, они будут общими для всех запущенных экземпляров,  доступ к ним необходимо организовывать только с помощью средств синхронизации процессов.

\~english
\brief A process.

There are many OSes, so It may be called a process, a thread, a task etc.
The point of all these names is: independent sequence of CPU instructions.

So a process is a part of your program, that has its own "main" routine (stored in pmain field of #proc_t object).
A process "main" routine can be written in a way as if there were no other processes!

It's possible to use one "main" routine for many processes, as differents processes are independent, but you have to remember one thing about static variables in such "main" routine.

\warning
Be carefull with static variables, these variables are common for all processes sharing one routine!
You must access such static variables using process synchronization facilities.
*/
struct _proc_t
{
    pitem_t parent;     /*!<\~russian Родитель - #pitem_t. \~english A parent is #pitem_t.*/
    flag_t flags;       /*!<\~russian  Флаги (для ускорения анализа состояния процесса). \~english Process state flags (to treat process state quickly).*/
#ifdef CONFIG_USE_HIGHEST_LOCKER
    prio_t base_prio;     /*!<\~russian  Базовый приоритет. \~english A base process priority.*/
    pcounter_t lres;     /*!<\~russian  Счетчик захваченных ресурсов. \~english A locked resource counter.*/
#else
    count_t lres;       /*!<\~russian  Счетчик захваченных ресурсов. \~english A locked resource counter.*/
#endif
    timer_t time_quant; /*!<\~russian  Квант времени процесса. \~english A process time slice.*/
    timer_t timer;      /*!<\~russian  Таймер процесса, для процессов жесткого реального времени используется как watchdog. \~english A process timer, it is used as watchdog for real time processes*/
    void * buf;         /*!<\~russian  Указатель на хранилище для передачи данных через IPC. \~english A pointer to process IPC data storage.*/
#ifdef CONFIG_MP
    // Поля, специфичные для многопроцессорных систем;
    core_id_t core_id;      /*!<\~russian  Идентификатор процессора, на котором исполняется процесс. \~english An ID of a CPU that runs a process.*/
    affinity_t affinity;    /*!<\~russian  Аффинность (индекс процессоров, на котором может исполняться процесс). \~english An Affinity of a process.*/
    lock_t lock;            /*!<\~russian  Спин блокировка процесса. \~english  A process spin-lock.*/
#endif
    code_t pmain;       /*!<\~russian  Главная функция процесса. \~english A pointer to a process "main" routine.*/
    code_t sv_hook;     /*!<\~russian  Хук, исполняется планировщиком после сохранения контекста процесса. \~english A context save hook, it is run after saving a process context.*/
    code_t rs_hook;     /*!<\~russian  Хук, исполняется планировщиком перед восстановлением контекста процесса. \~english  A context restore hook, it is run before restoring a process context.*/
    void * arg;         /*!<\~russian  Аргумент для pmain, sv_hook, rs_hook, может хранить ссылку на локальные данные конкретного экземпляра процесса. \~english An argument for pmain, sv_hook, rs_hook, may be used to store process local data.*/

    stack_t * sstart;   /*!<\~russian  Указатель на дно стека экземпляра процесса. \~english A process stack bottom pointer.*/
    stack_t * spointer; /*!<\~russian Указатель на вершину стека экземпляра процесса. \~english A process stack top pointer.*/
};
/*
Порядок захвата блокировок:
1) при постановке процесса в список: 1-блокировка процесса, 2-блокировка списка
2) при удалении процесса из списка, без изменения полей кроме parent: блокировка списка
3) при удалении процесса из списка, с изменениями полей кроме parent: 1-блокировка процесса, 2-блокировка списка
*/
// Флаги
/*!
\~russian
\brief Флаг реального времени.

Для этого процесса используется политика планирования жесткого реального времени.
\~english
\brief A real time flag.

This flag enables real time process scheduling policy.
*/
#define PROC_FLG_RT         ((flag_t)0x80)
/*!
\~russian
\brief Флаг захвата мьютексов.

Процесс удерживает мьютекс.
\~english
\brief A mutex lock flag.

A process has locked some mutex controled resources.
*/
#define PROC_FLG_MUTEX       ((flag_t)0x40)
/*!
\~russian
\brief Флаг захвата семафора.

Выставляется при вызове #sem_lock и при удачном вызове #sem_try_lock.
Обнулять необходимо вручную, при освобождении общего ресурса, охраняемого семафором.
Обнуляется вызовом #proc_flag_stop.
\~english
\brief A semaphore lock flag.

It is set on #sem_lock call or on succesfull #sem_try_lock call.
It is necessary to clear this flag manually, when semaphore controled resource is released.
Use #proc_flag_stop call to clear this flag.
*/
#define PROC_FLG_SEM      ((flag_t)0x20)
/*!
\~russian
\brief Флаг запроса останова.

Произошел запрос на останов процесса. Процесс будет остановлен при первой же возможности.
\~english
\brief A proces stop preparation flag.

A process must be stoped, but it can't be stoped now. It'll be stoped when possible.
*/
#define PROC_FLG_PRE_STOP    ((flag_t)0x10)

/*!
\~russian
\brief Маска #PROC_FLG_MUTEX или #PROC_FLG_SEM.

Нужна, чтобы определить, удерживает ли процесс общие ресурсы.
\~english
\brief A #PROC_FLG_MUTEX or #PROC_FLG_SEM mask.

Used to test if a process has locked some resources.
*/
#define PROC_FLG_LOCK_MASK ((flag_t)(PROC_FLG_MUTEX|PROC_FLG_SEM))

/*!
\~russian
\brief Маска очистки состояния исполнения процесса.

Нужна, чтобы очистить биты стотояния выполнения процесса в поле proc->flags.
\~english
\brief An execution state clear mask.

Used clear execution state bitts in proc->flags.
*/
#define PROC_STATE_CLEAR_MASK ((flag_t)0xF0)

/*!
\~russian
\brief Маска очистки состояния исполнения процесса.

Нужна, чтобы очистить младшие биты стотояния выполнения процесса в поле proc->flags.
\~english
\brief An execution state clear mask.

Used clear execution three LSBs state bitts in proc->flags.
*/
#define PROC_STATE_CLEAR_RUN_MASK ((flag_t)0xF8)

/*!
\~russian
\brief Маска состояния исполнения процесса.

\~english
\brief An execution state mask.
*/
#define PROC_STATE_MASK ((flag_t)0x0F)
/*!
\~russian
\brief Маска проверки состояния процесса.

Используется функциями #proc_restart и #proc_restart_isr, для проверки возможности перезапуска.

\~english
\brief A process execution state check mask.

Used by #proc_restart and #proc_restart_isr to check for restart posibility.
*/
#define PROC_STATE_RESTART_MASK ((flag_t)0xC)

/*!
\~russian
\brief Маска проверки состояния процесса.

Используется для того, чтобы проверить, запущен ли процесс.

\~english
\brief A process execution state check mask.

Used to check if the process has been run.
*/
#define PROC_STATE_RUN_MASK ((flag_t)0x7)

/*!
\~russian
\brief Маска проверки состояния процесса.

Используется для того, чтобы проверить, ожидате ли процесс получения семафора, мьютекса, сообщения через IPC или сигнала.

\~english
\brief A process execution state check mask.

Used to check if the process is waiting for semaphore, mutex, ipc or signal.
*/
#define PROC_STATE_WAIT_MASK ((flag_t)0x8)

// process states not checked on restart
#define PROC_STATE_STOPED           ((flag_t)0x0)   /*!< \~russian Начальное состояние, остановлен. \~english Initial state, stoped. */
#define PROC_STATE_END              ((flag_t)0x1)   /*!< \~russian Завершен. \~english Normal process termination. */
#define PROC_STATE_W_WD_STOPED      ((flag_t)0x2)   /*!< \~russian Остановлен по вачдог в состоянии W_RUNNING. \~english Watchdog termination from W_RUNNING state. */
#define PROC_STATE_WD_STOPED        ((flag_t)0x3)   /*!< \~russian Остановлен по вачдог. \~english Watchdog termination. */

#define PROC_STATE_DEAD             ((flag_t)0x4)   /*!< \~russian Завершен до освобождения общих ресурсов. \~english Abnormal termination, terminated with resources locked. */
// run states
#define PROC_STATE_READY            ((flag_t)0x5)   /*!< \~russian Готов к выполнению. \~english Is ready to run. */
#define PROC_STATE_RESERVED_0x6     ((flag_t)0x6)   /*!< \~russian Зарезервировано. \~english Reserved. */
#define PROC_STATE_RUNNING          ((flag_t)0x7)   /*!< \~russian Выполняется. \~english Is running. */

// wait states
#define PROC_STATE_W_MUT            ((flag_t)0x8)   /*!< \~russian Ожидает мьютекса. \~english Is waiting for mutex. */
#define PROC_STATE_W_SEM            ((flag_t)0x9)   /*!< \~russian Ожидает семафора. \~english Is waiting for semaphore. */
#define PROC_STATE_W_SIG            ((flag_t)0xA)   /*!< \~russian Ожидает сигнала. \~english Is waiting for signal. */
#define PROC_STATE_W_IPC            ((flag_t)0xB)   /*!< \~russian Ожидает IPC. \~english Is waiting for IPC. */

//special states
#define PROC_STATE_W_DEAD           ((flag_t)0xC)   /*!< \~russian Остановлен по вачдог в состоянии W_RUNNING до освобождения общих ресурсов. \~english Watchdog termination from W_RUNNING state with resources locked. */

#define PROC_STATE_W_READY          ((flag_t)0xD)   /*!< \~russian Готов к выполнению (специальное). \~english Is ready to run (special). */
#define PROC_STATE_RESERVED_0xE     ((flag_t)0xE)   /*!< \~russian Зарезервировано. \~english Reserved. */
#define PROC_STATE_W_RUNNING        ((flag_t)0xF)   /*!< \~russian Выполняется (специальное). \~english Is running (special). */

/*!
\~russian
\brief Макрос проверки условий останова по флагу #PROC_FLG_PRE_STOP.

Используется для проверки процессов на возможность останова по флагу #PROC_FLG_PRE_STOP.
Процесс не должен удерживать общие ресурсы в момент останова по флагу.

\~english
\brief A #PROC_FLG_PRE_STOP condition test macro.

Used to test if a process can be stoped on #PROC_FLG_PRE_STOP flag.
A process should not have locked resources at a moment of a flag stop.
*/
#define PROC_PRE_STOP_TEST(a) ( ( a->flags & PROC_FLG_PRE_STOP ) && ( !( a->flags & PROC_FLG_LOCK_MASK ) ) )
/*!
\~russian
\brief Проверяет, запущен ли процесс.

\~english
\brief Check if process is ready or running
*/
#define PROC_RUN_TEST(a) ( ( a->flags & PROC_STATE_RUN_MASK ) >= PROC_STATE_READY )
/*!
\~russian
\brief Проверяет ждет ли процесс IPC

\~english
\brief Checks if process is waiting for IPC.
*/
#define PROC_IPC_TEST(a) ( ( a->flags & PROC_STATE_MASK ) == PROC_STATE_W_IPC )

// Методы
/*!
\brief \~russian Инициализация процесса из обработчика прерывания, либо из критической секции. \~english A process initialization. Must be used in critical sections and interrupt service routines.
*/
void proc_init_isr(
    proc_t * proc,      /*!< \~russian Указатель на инициируемый процесс. \~english A ponter to a initialized process.*/
    code_t pmain,       /*!< \~russian Указатель на главную функцию процесса. \~english A pointer to a process "main" routine.*/
    code_t sv_hook,     /*!< \~russian Указатель на хук proc->sv_hook. \~english A context save hook pointer.*/
    code_t rs_hook,     /*!< \~russian Указатель на хук proc->rs_hook. \~english A context save hook pointer.*/
    void * arg,         /*!< \~russian Указатель на аргумент. \~english An argument pointer.*/
    stack_t *sstart,    /*!< \~russian Указатель на дно стека процесса. \~english A process stack bottom pointer.*/
    prio_t prio,        /*!< \~russian Приоритет. \~english A process priority.*/
    timer_t time_quant, /*!< \~russian Квант времени. \~english A process time slice.*/
    bool_t is_rt        /*! \~russian Флаг реального времени, если true, значит процесс будет иметь поведение RT. \~english A real time flag. If frue, then a process is scheduled in a real time manner.*/
#ifdef CONFIG_MP
    ,affinity_t affinity/*!< \~russian Афинность. \~english A process affinity.*/
#endif // CONFIG_MP
);
/*!
\brief \~russian Инициализация процесса. \~english A process initialization.
*/
void proc_init(
    proc_t * proc,      /*!< \~russian Указатель на инициируемый процесс. \~english A ponter to a initialized process.*/
    code_t pmain,       /*!< \~russian Указатель на главную функцию процесса. \~english A pointer to a process "main" routine.*/
    code_t sv_hook,     /*!< \~russian Указатель на хук proc->sv_hook. \~english A context save hook pointer.*/
    code_t rs_hook,     /*!< \~russian Указатель на хук proc->rs_hook. \~english A context save hook pointer.*/
    void * arg,         /*!< \~russian Указатель на аргумент. \~english An argument pointer.*/
    stack_t *sstart,    /*!< \~russian Указатель на дно стека процесса. \~english A process stack bottom pointer.*/
    prio_t prio,        /*!< \~russian Приоритет. \~english A process priority.*/
    timer_t time_quant, /*!< \~russian Квант времени. \~english A process time slice.*/
    bool_t is_rt        /*! \~russian Флаг реального времени, если true, значит процесс будет иметь поведение RT. \~english A real time flag. If frue, then a process is scheduled in a real time manner.*/
#ifdef CONFIG_MP
    ,affinity_t affinity/*!< \~russian Афинность. \~english A process affinity.*/
#endif // CONFIG_MP
);
/*!
\~russian
\brief Обертка для запуска процессов.

Эта функция  вызывает proc->pmain(proc->arg), и если происходит возврат из pmain, то #proc_run_wrapper корректно завершает процесс.
\param proc - Указатель на запускаемый процесс.
\~english
\brief A wrapper for process "main" routines.

This function calls proc->pmain(proc->arg), and if pmain returns, then #proc_run_wrapper terminates process correctly.
\param proc - A pointer to a process to launch.
*/
void proc_run_wrapper(proc_t * proc);
/*!
\~russian
\brief Завершение работы процесса после возврата из proc->pmain. Для внутреннего использования.

\~english
\brief A process termination routine called after proc->pmain return. Internal usage function.
*/
void proc_terminate( void );
/*!
\~russian
\brief Завершение работы процесса после возврата из proc->pmain. Для внутреннего использования.

\~english
\brief A process termination routine called after proc->pmain return. Internal usage function.
*/
void _proc_terminate( void );
/*!
\~russian
\brief Запуск процесса.

Ставит процесс в список готовых к выполнению, если можно (процесс не запущен, еще не завершил работу, не был "убит"), и производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return 1 - если процесс был вставлен в список готовых к выполнению, 0 во всех остальных случаях.

\~english
\brief A process launch routine.

This function schedules a process if possible.

\param proc - A pointer to a process to launch.
\return 1 - if a process has been scheduled, 0 in other cases.
*/
bool_t proc_run(proc_t * proc);
/*!
\~russian
\brief Запуск процесса из критической секции, либо обработчика прерывания.

Ставит процесс в список готовых к выполнению, если можно (процесс не запущен, еще не завершил работу, не был "убит"), и производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return 1 - если процесс был вставлен в список готовых к выполнению, 0 во всех остальных случаях.

\~english
\brief A process launch routine for usage in interrupt service routines and critical sections.

This function schedules a process if possible.

\param proc - A pointer to a process to launch.
\return 1 - if a process has been scheduled, 0 in other cases.
*/
bool_t proc_run_isr(proc_t * proc);

/*!
\~russian
\brief Перезапуск процесса.

Если можно (процесс не запущен, завершил работу, не был "убит"), приводит структуру proc в состояние, которое было после вызова #proc_init, и ставит процесс в список готовых к выполнению, и производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return 1 - если процесс был вставлен в список готовых к выполнению, 0 во всех остальных случаях.

\~english
\brief A process restart routine.

This function reinitializes a process and schedules it if possible.

\param proc - A pointer to a process to launch.
\return 1 - if a process has been scheduled, 0 in other cases.
*/
bool_t proc_restart(proc_t * proc);
/*!
\~russian
\brief Перезапуск процесса из критической секции или обработчика прерывания.

Если можно (процесс не запущен, завершил работу, не был "убит"), приводит структуру proc в состояние, которое было после вызова #proc_init, и ставит процесс в список готовых к выполнению, производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return 1 - если процесс был вставлен в список готовых к выполнению, 0 во всех остальных случаях.

\~english
\brief A process restart routine for usage in interrupt service routines and critical sections.

This function reinitializes a process and schedules it if possible.

\param proc - A pointer to a process to launch.
\return 1 - if a process has been scheduled, 0 in other cases.
*/
bool_t proc_restart_isr(proc_t * proc);
/*!
\~russian
\brief Останов процесса.

Вырезает процесс из списка готовых к выполнению и производит перепланировку.
\param proc - Указатель на останавливаемый процесс.
\return 1 - если процесс был вырезан из списка готовых к выполнению, 0 во всех остальных случаях.

\~english
\brief A process stop routine.

This function stops a process if possible.
\param proc - A pointer to a process to stop.
\return 1 - if a process has been stoped, 0 in other cases.
*/
bool_t proc_stop(proc_t * proc);
/*!
\~russian
\brief Останов процесса из критической секции или обработчика прерывания.

Вырезает процесс из списка готовых к выполнению и производит перепланировку.
\param proc - Указатель на останавливаемый процесс.
\return 1 - если процесс был вырезан из списка готовых к выполнению, 0 во всех остальных случаях.

\~english
\brief A process stop routine for usage in interrupts service routines and critical sections.

This function stops a process if possible.
\param proc - A pointer to a process to stop.
\return 1 - if a process has been stoped, 0 in other cases.
*/
bool_t proc_stop_isr(proc_t * proc);
/*!
\~russian
\brief Самоостанов процесса.

Вырезает вызывающий процесс из списка готовых к выполнению и производит перепланировку.

\~english
\brief A process self stop routine.

This function stops caller process.
*/
void proc_self_stop(void);
/*!
\~russian
\brief Самоостанов процесса (для внутреннего использования).

Вырезает вызывающий процесс из списка готовых к выполнению и производит перепланировку.

\~english
\brief A process self stop routine (for internal usage only!).

This function stops caller process.
*/
void _proc_self_stop(void);

/*!
\~russian
\brief Передача управления следующему процессу (для внутреннего использования).

Передает управление следующему процессу, если такой процесс есть.

\return 0 если нет других выполняющихся процессов, не 0 - если есть.

\~english
\brief Pass control to next ready process (for internal usage only!).

If there is another running process, this function passes control to it.

\return Zero if there are no other running processes, none zero if there is at least one.
*/

index_t _proc_yeld( void );
/*!
\~russian
\brief Передача управления следующему процессу.

Передает управление следующему процессу, если такой процесс есть.

\return 0 если нет других выполняющихся процессов, не 0 - если есть.

\~english
\brief Pass control to next ready process.

If there is another running process, this function passes control to it.

\return Zero if there are no other running processes, none zero if there is at least one.
*/
index_t proc_yeld( void );


/*!
\~russian
\brief Сброс watchdog для процесса реального времени.

Если функцию вызывает процесс реального времени, то функция сбрасывает его таймер.
Если процесс завис, и таймер не был вовремя сброшен, то планировщик остановит такой процесс и передаст управление другому.

\~english
\brief A watchdog reset routine for real time processes.

If a caller process is real time, then this function resets its timer.
If a real time process failes to reset its watchdog, then the scheduler stops such process and wakes up next ready process.
*/
void proc_reset_watchdog(void);
/*!
\~russian
\brief Сброс watchdog для процесса реального времени из обработчика прерывания (для внутреннего использования).

Если функцию вызывает процесс реального времени, то функция сбрасывает его таймер.
Если процесс завис, и таймер не был вовремя сброшен, то планировщик остановит такой процесс и передаст управление другому.

\~english
\brief A watchdog reset routine for real time processes for internal usage.

If a caller process is real time, then this function resets its timer.
If a real time process failes to reset its watchdog, then the scheduler stops such process and wakes up next ready process.
*/
void _proc_reset_watchdog(void);

//  Функция для внутреннего использования - собственно запуск процесса
#ifdef CONFIG_MP
/*!
\brief \~russian Вставка процесса в список готовых к выполнению, для внутреннего использования. \~english A routine that inserts a process to ready process list. For internal usage.
*/
void __proc_run( proc_t * proc );
#else
/*!
\brief \~russian Вставка процесса в список готовых к выполнению, для внутреннего использования. \~english A routine that inserts a process to ready process list. For internal usage.
*/
#define __proc_run(proc) pitem_insert( (pitem_t *)proc, kernel.sched.ready )
#endif
/*!
\brief \~russian "Низкоуровневый" запуск процесса, для внутреннего использования. \~english A low level process run routine. For internal usage.
*/
void _proc_run( proc_t * proc );
/*!
\brief \~russian "Низкоуровневый" останов процесса, для внутреннего использования. \~english A low level process stop routine. For internal usage.
*/
void _proc_stop(proc_t * proc);
/*!
\brief \~russian "Низкоуровневый" останов процесса с установкой флагов, для внутреннего использования. \~english A low level process stop with flags set routine. For internal usage.
*/
void _proc_stop_flags_set( proc_t * proc, flag_t mask );
/*!
\brief \~russian Останов процесса по флагу #PROC_FLG_PRE_STOP из критической секции или обработчика прерывания, для внутреннего использования. \~english A #PROC_FLG_PRE_STOP flag processing routine. For internal usage.
*/
void _proc_flag_stop( flag_t mask );
/*!
\brief \~russian Останов процесса по флагу #PROC_FLG_PRE_STOP. \~english A #PROC_FLG_PRE_STOP flag processing routine.
*/
void proc_flag_stop( flag_t mask );
// Упраление счетчиком захваченных ресурсов, для внутреннего использования
/*!
\brief \~russian Инкремент счетчика захваченных ресурсов, для внутреннего использования. \~english A locked resource counter increment routine. For internal usage.
*/
void _proc_lres_inc(
    proc_t * proc /*!< \~russian Указатель на процесс, захвативший ресурс. \~english A pointer to a process.*/
#ifdef CONFIG_USE_HIGHEST_LOCKER
    ,prio_t prio /*!< \~russian Приоритет захваченного ресурса, используется совместно с опцией CONFIG_USE_HIGHEST_LOCKER. \~english A locked resource priority. Used with CONFIG_USE_HIGHEST_LOCKER option.*/
#endif
);
/*!
\brief \~russian Декремент счетчика захваченных ресурсов, для внутреннего использования. \~english A locked resource counter decrement routine. For internal usage.
*/
void _proc_lres_dec(
    proc_t * proc /*!< \~russian Указатель на процесс, захвативший ресурс. \~english A pointer to a process.*/
#ifdef CONFIG_USE_HIGHEST_LOCKER
    ,prio_t prio /*!< \~russian Приоритет захваченного ресурса, используется совместно с опцией CONFIG_USE_HIGHEST_LOCKER. \~english A locked resource priority. Used with CONFIG_USE_HIGHEST_LOCKER option.*/
#endif
);
#ifdef CONFIG_USE_HIGHEST_LOCKER
/*!
\~russian
\brief Управление приоритетом процесса, для внутреннего использования.

Используется совместно с опцией CONFIG_USE_HIGHEST_LOCKER. Процесс должен быть остановлен на момент вызова.
\param proc - Указатель на процесс.

\~english
\brief A stoped process priority control routine.

Used with CONFIG_USE_HIGHEST_LOCKER option. A process must be stoped before call of the routine.
\param proc - A pointer to a process.
*/
void _proc_prio_control_stoped( proc_t * proc );
#endif

#if defined(CONFIG_MP) && (!defined(CONFIG_USE_ALB))
/************************************
  "Ленивые" балансировщики нагрузки

,предназначены для запуска из тел
процессов, если не используется
активная схема балансировки нагрузки.

Можно использовать только один,
или оба в различных комбинациях

************************************/
/*!
\~russian
\brief Ленивая балансировка нагрузки, для внутренненго использования.

Переносит 1 процесс на самое не нагруженное процессорное ядро в системе.
\param object_core - процессорное ядро, с которого будем снимать нагрузку.

\~english
\brief A lazy load balancer routine. For internal usage.

This function transfers one process on the least loaded CPU core from the object core.
\param object_core - A CPU core to decrease a load on.
*/
void _proc_lazy_load_balancer(core_id_t object_core);

/*!
\~russian
\brief Ленивая балансировка нагрузки, локальный балансировщик.

Переносит 1 процесс с ядра, на котором выполняется на самое не нагруженное процессорное ядро в системе.

\~english
\brief A lazy local load balancer routine.

Transfers one process from a current CPU core to the least loaded CPU core on the system.
*/
void proc_lazy_local_load_balancer(void);
/*!
\~russian
\brief Ленивая балансировка нагрузки, глобальный балансировщик.

Ищет самое нагруженное процессорное ядро в системе и переносит с него один процесс на самое ненагруженное ядро в системе.

\~english
\brief A lazy global load balancer routine.

Finds the most loaded CPU core on the system and transfers one process from it to the least loaded CPU core.
*/
void proc_lazy_global_load_balancer(void);

#endif // CONFIG_MP CONFIG_USE_ALB

#endif // _PROC_H_
