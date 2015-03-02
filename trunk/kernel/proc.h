/**************************************************************************
    BuguRTOS-0.8.x(Bugurt real time operating system)
    Copyright (C) 2015  anonimous

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

*/

#define PROC_LRES_INIT(a) pcounter_init(&a->lres)
#define PROC_LRES_INC(a,b) _proc_lres_inc(a,b)
#define PROC_LRES_DEC(a,b) _proc_lres_dec(a,b)

/*
#define PROC_LRES_INC(a,b) pcounter_inc( &a->lres, b )
#define PROC_LRES_DEC(a,b) pcounter_dec( &a->lres, b )
*/

//#define PROC_PRIO_CONTROL_STOPED(a) _proc_prio_control_stoped(a)

//Процесс
typedef struct _proc_t proc_t; /*!< \~russian Смотри #_proc_t; \~english See #_proc_t; */
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
    prio_t base_prio;     /*!<\~russian  Базовый приоритет. \~english A base process priority.*/
    pcounter_t lres;     /*!<\~russian  Счетчик захваченных ресурсов. \~english A locked resource counter.*/
    timer_t time_quant; /*!<\~russian  Квант времени процесса. \~english A process time slice.*/
    timer_t timer;      /*!<\~russian  Таймер процесса, для процессов жесткого реального времени используется как watchdog. \~english A process timer, it is used as watchdog for real time processes*/
    struct _sync_t * sync;
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
#define PROC_FLG_BLOCK      ((flag_t)0x40)

#define PROC_FLG_RESERVED   ((flag_t)0x20)
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
\brief Маска #PROC_FLG_BLOCK.

Нужна, чтобы определить, удерживает ли процесс общие ресурсы.
\~english
\brief A #PROC_FLG_BLOCK.

Used to test if a process has locked some resources.
*/
#define PROC_FLG_LOCK_MASK ((flag_t)(PROC_FLG_BLOCK))

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
#define PROC_STATE_CLEAR_RUN_MASK ((flag_t)0xFC)

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
#define PROC_STATE_RESTART_MASK ((flag_t)0x8)

/*!
\~russian
\brief Маска проверки состояния процесса.

Используется для того, чтобы проверить, запущен ли процесс.

\~english
\brief A process execution state check mask.

Used to check if the process has been run.
*/
#define PROC_STATE_RUN_MASK ((flag_t)0x3)

/*!
\~russian
\brief Маска проверки состояния процесса.

Используется для того, чтобы проверить, ожидате ли процесс получения семафора, мьютекса, сообщения через IPC или сигнала.

\~english
\brief A process execution state check mask.

Used to check if the process is waiting for semaphore, mutex, ipc or signal.
*/
#define PROC_STATE_WAIT_MASK ((flag_t)0x8)

//process states
#define PROC_STATE_STOPED           ((flag_t)0x0)   /*!< \~russian Начальное состояние, остановлен. \~english Initial state, stoped. */
#define PROC_STATE_END              ((flag_t)0x1)   /*!< \~russian Завершен. \~english Normal process termination. */
#define PROC_STATE_READY            ((flag_t)0x2)   /*!< \~russian Готов к выполнению. \~english Is ready to run. */
#define PROC_STATE_RUNNING          ((flag_t)0x3)   /*!< \~russian Выполняется. \~english Is running. */

#define PROC_STATE_WD_STOPED        ((flag_t)0x4)   /*!< \~russian Остановлен по вачдог. \~english Watchdog termination. */
#define PROC_STATE_DEAD             ((flag_t)0x5)   /*!< \~russian Завершен до завершения ipc-транзакций. \~english Abnormal termination, terminated with waiting ipc transactions. */
#define PROC_STATE_WD_READY         ((flag_t)0x6)   /*!< \~russian Готов к выполнению. \~english Is ready to run. */
#define PROC_STATE_WD_RUNNING       ((flag_t)0x7)   /*!< \~russian Выполняется. \~english Is running. */

#define PROC_STATE_SYNC_WAIT        ((flag_t)0x8)   /*!< \~russian Ожидает приема спящих процессов. \~english Is waiting for sleaping processes.*/
#define PROC_STATE_SYNC_SLEEP       ((flag_t)0x9)   /*!< \~russian Ожидает пробуждения. \~english Is waiting for wakeup. */
#define PROC_STATE_SYNC_READY       ((flag_t)0xA)   /*!< \~russian Готов к выполнению. \~english Is ready to run. */
#define PROC_STATE_SYNC_RUNNING     ((flag_t)0xB)   /*!< \~russian Выполняется. \~english Is running. */

#define PROC_STATE_PI_PEND          ((flag_t)0xC)   /*!< \~russian Ожидает смены приоритета \~english A process is waiting for priority change */
#define PROC_STATE_PI_DONE          ((flag_t)0xD)   /*!< \~russian Запущен при смене приоритета \~english A process has been run during priority change */
#define PROC_STATE_PI_READY         ((flag_t)0xE)   /*!< \~russian Готов к выполнению. \~english Is ready to run. */
#define PROC_STATE_PI_RUNNING       ((flag_t)0xF)   /*!< \~russian Выполняется. \~english Is running. */

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
\brief Читает состояние процесса.

\~english
\brief Reads a process state.
*/
#define PROC_GET_STATE(a) ( a->flags & PROC_STATE_MASK )
/*!
\~russian
\brief Устанавливает состояние процесса.

\~english
\brief Sets process state.
*/
#define PROC_SET_STATE(a,b) ( a->flags &= PROC_STATE_CLEAR_MASK, proc->flags |= b )

/*!
\~russian
\brief Низший приоритет.

\~english
\brief Lowest priority level.
*/
#define PROC_PRIO_LOWEST ((prio_t)BITS_IN_INDEX_T - (prio_t)1)

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

/*!
\brief \~russian Запуск остановленного процесса с флагом #PROC_FLG_PRE_STOP. Для внутреннего использования. \~english Run stoped process and set #PROC_FLG_PRE_STOP. For internal usage.
*/
void _proc_dont_stop( proc_t * proc, flag_t flags );
/*!
\brief \~russian Вырезать проесс из списка ожидающих и его запуск. Для внутреннего использования. \~english Cut the a process from wait list and run it. For internel usage.
*/
void _proc_cut_and_run( proc_t * proc, flag_t state );
//===========================================================
/*!
\brief \~russian Передача приоритетов по цепи заблокированных процессов. Для внутреннего использования. \~english Propagation of priority through a blovked process chain. For internal usage.
*/
void _proc_prio_propagate( proc_t * proc
#ifdef CONFIG_MP
                          , code_t hook, void * hook_arg
#endif //CONFIG_MP
                         );
//===========================================================
/*!
\brief \~russian "Низкоуровневый" останов процесса с установкой флагов, для внутреннего использования. \~english A low level process stop with flags set routine. For internal usage.
*/
void _proc_stop_flags_set( proc_t * proc, flag_t mask );
/*!
\brief \~russian Установка флага #PROC_FLG_BLOCK для вызывающего процесса. \~english Set #PROC_FLG_BLOCK for caller process.
*/
void _proc_flag_set(void);
/*!
\brief \~russian Установка флага #PROC_FLG_BLOCK для вызывающего процесса. \~english Set #PROC_FLG_BLOCK for caller process.
*/
void proc_flag_set(void);
/*!
\brief \~russian Останов процесса по флагу #PROC_FLG_PRE_STOP из критической секции или обработчика прерывания, для внутреннего использования. \~english A #PROC_FLG_PRE_STOP flag processing routine. For internal usage.
*/
void _proc_flag_stop(void);
/*!
\brief \~russian Останов процесса по флагу #PROC_FLG_PRE_STOP. \~english A #PROC_FLG_PRE_STOP flag processing routine.
*/
void proc_flag_stop(void);
// Упраление счетчиком захваченных ресурсов, для внутреннего использования
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

/*!
\~russian
\brief Управление приоритетом процесса.

Устанавливает приоритет процесса, находящегося в любом состоянии.

\param proc - Указатель на процесс.
\param prio - Новое значение приоритета.

\~english
\brief Set a priotity of a process.

It sets a procees priority. A process current state doesn't matter.

\param proc - A pointer to a process.
\param prio - New process priority value.
*/
void proc_set_prio( proc_t * proc, prio_t prio );

/*!
\~russian
\brief Управление приоритетом процесса. Для внктреннего использования.

Устанавливает приоритет процесса, находящегося в любом состоянии.

\param proc - Указатель на процесс.
\param prio - Новое значение приоритета.

\~english
\brief Set a priotity of a process. For internel usage.

It sets a procees priority. A process current state doesn't matter.

\param proc - A pointer to a process.
\param prio - New process priority value.
*/
void _proc_set_prio( proc_t * proc, prio_t prio );

void _proc_lres_inc( proc_t * proc ,prio_t prio );
void _proc_lres_dec( proc_t * proc ,prio_t prio );

void _proc_stop_ensure( proc_t * proc );

#endif // _PROC_H_
