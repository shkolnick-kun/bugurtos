/**************************************************************************
   BuguRTOS-4.0.x (Bugurt real time operating system)
   Copyright (C) 2018 anonimous

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
#ifndef BGRT_PROC_H
#define BGRT_PROC_H
BGRT_CDECL_BEGIN
/*!
\file
\~russian
\brief Заголовок процессов.
\~english
\brief A process header.
*/

/*!
\~russian

\def BGRT_PROC_LRES_INIT(a)
\brief Макрос-обёртка.

Инициирует поле proc->lres процесса.

\param a указатель на процесс.

\def BGRT_PROC_LRES_INC(a,b)
\brief Макрос-обёртка.

Инкремент счётчика proc->lres.

\param a указатель на процесс.
\param b приоритет объекта типа #bgrt_sync_t.

\def BGRT_PROC_LRES_DEC(a,b)
\brief Макрос-обёртка.

Декремент счётчика proc->lres.

\param a указатель на процесс.
\param b приоритет объекта типа #bgrt_sync_t.

\~english

\def BGRT_PROC_LRES_INIT(a)
\brief Wrapper macro.

Initiates proc->lres field of a process.

\param a a pointer to a process.

\def BGRT_PROC_LRES_INC(a,b)
\brief Wrapper macro.

An increment of proc->lres.

\param a a pointer to a process.
\param b a priority of a #bgrt_sync_t object.

\def BGRT_PROC_LRES_DEC(a,b)
\brief Wrapper macro.

A decrement of proc->lres.

\param a a pointer to a process.
\param b a priority of a #bgrt_sync_t object.

*/

#define BGRT_PROC_LRES_INIT(a)  bgrt_pcounter_init(&((a)->lres))
#define BGRT_PROC_LRES_INC(a,b) bgrt_pcounter_inc(&((a)->lres), (bgrt_prio_t)b)
#define BGRT_PROC_LRES_DEC(a,b) bgrt_pcounter_dec(&((a)->lres), (bgrt_prio_t)b)

/*Процесс*/
typedef struct bgrt_priv_proc_t bgrt_proc_t; /*!< \~russian Смотри #bgrt_priv_proc_t; \~english See #bgrt_priv_proc_t; */


/*!
\file
\~russian

\def BGRT_PID_T
\brief Уникальный идентификатор процесса.

\def BGRT_PID_TO_PROC
\brief Преобразование идентификатора процесса в указатель на процесс.

\note Может проверять идентификатор процесса на допустимость.

\param p Уникальный идентификатор процесса.
\return Указатель на объект типа #bgrt_proc_t, или нулевой указатель.

\def BGRT_PROC_TO_PID
\brief Преобразование указателя на процесс в идентификатор процесса.

\note Может проверять допустимость значения указателя.

\param p Указатель на объект типа #bgrt_proc_t.
\return Уникальный идентификатор процесса.

\def BGRT_PID_NOTHING
\brief Пустой идентификатор процесса.

\~english

\def BGRT_PID_T
\brief A unique process ID.

\def BGRT_PID_TO_PROC
\brief Lookup the #bgrt_proc_t object for a given process ID.

\note This macro may check the process ID for validity.

\param p A process ID.
\return The #bgrt_proc_t pointer or a zero pointer.

\def BGRT_PROC_TO_PID
\brief Lookup the ID for a specified #bgrt_proc_t object.

\note This macro may check the #bgrt_proc_t pointer for validity.

\param p A #bgrt_proc_t pointer.
\return The process ID.

\def BGRT_PID_NOTHING
\brief An empty process ID.
*/
#ifndef BGRT_PID_T
#   define BGRT_PID_T bgrt_proc_t *
#   define BGRT_PID_TO_PROC(p) (p)
#   define BGRT_PROC_TO_PID(p) (p)
#   define BGRT_PID_NOTHING ((BGRT_PID_T)0)
#endif/*BGRT_PID_T*/

struct bgrt_priv_uspd_t
{
    void *         scarg;    /*!<\~russian Указатель на аргумент системного вызова. \~english A system call pointer.*/
    bgrt_syscall_t scnum;    /*!<\~russian Номер системного вызова. \~english A system call number.*/
    bgrt_st_t      scret;    /*!<\~russian Результат системного вызова. \~english A system call result.*/
};                           /*!<\~russian Данные процесса из пространства пользователя (заголовок). \~english User space process data header.*/
/*Default implementation*/
#ifndef BGRT_USPD_T
#   define BGRT_USPD_PROC_T struct bgrt_priv_uspd_t     /*!<\~russian Данные процесса из пространства пользователя. \~english User space process data.*/
#   define BGRT_USPD_T BGRT_USPD_PROC_T *               /*!<\~russian Данные процесса из пространства пользователя. \~english User space process data.*/
#   define BGRT_GET_USPD() (&(bgrt_curr_proc()->udata)) /*!<\~russian Получить указатель на данные пространства пользователя текущего процесса. \~english Get current process userspace data pointer.*/
#   define BGRT_USPD_INIT(proc) \
        do{\
            proc->udata.scarg = (void *)0;\
            proc->udata.scnum = (bgrt_syscall_t)BGRT_SC_ENUM_END;\
        }while (0)                                        /*!<\~russian Инициализация. \~english Initialization.*/
#endif
/* Свойства*/
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

So a process is a part of your program, that has its own "main" routine (stored in pmain field of #bgrt_proc_t object).
A process "main" routine can be written in a way as if there were no other processes!

It's possible to use one "main" routine for many processes, as different processes are independent, but you have to remember one thing about static variables in such "main" routine.

\warning
Be careful with static variables, these variables are common for all processes sharing one routine!
You must access such static variables using process synchronization facilities.
*/
struct bgrt_priv_proc_t
{
    bgrt_pitem_t parent;     /*!<\~russian Родитель - #bgrt_pitem_t. \~english A parent is #bgrt_pitem_t.*/
    bgrt_flag_t flags;       /*!<\~russian  Флаги (для ускорения анализа состояния процесса). \~english Process state flags (to treat process state quickly).*/
    bgrt_prio_t base_prio;     /*!<\~russian  Базовый приоритет. \~english A base process priority.*/
    bgrt_pcounter_t lres;     /*!<\~russian  Счётчик захваченных ресурсов. \~english A locked resource counter.*/
    bgrt_tmr_t time_quant; /*!<\~russian  Квант времени процесса. \~english A process time slice.*/
    bgrt_tmr_t timer;      /*!<\~russian  Таймер процесса, для процессов жесткого реального времени используется как watchdog. \~english A process timer, it is used as watchdog for real time processes*/
    struct bgrt_priv_sync_t * sync;
    bgrt_cnt_t cnt_lock;    /*!<\~russian  Счётчик уровней вложенности #BGRT_PROC_LOCK. \~english A counter of #BGRT_PROC_LOCK nesting.*/
#ifdef BGRT_CONFIG_MP
    /* Поля, специфичные для многопроцессорных систем;*/
    bgrt_cpuid_t core_id;    /*!<\~russian  Идентификатор процессора, на котором исполняется процесс. \~english An ID of a CPU that runs a process.*/
    bgrt_aff_t affinity;     /*!<\~russian  Аффинность (индекс процессоров, на котором может исполняться процесс). \~english An Affinity of a process.*/
    bgrt_lock_t lock;        /*!<\~russian  Спин блокировка процесса. \~english  A process spin-lock.*/
#endif
    bgrt_code_t pmain;       /*!<\~russian  Главная функция процесса. \~english A pointer to a process "main" routine.*/
    bgrt_code_t sv_hook;     /*!<\~russian  Хук, исполняется планировщиком после сохранения контекста процесса. \~english A context save hook, it is run after saving a process context.*/
    bgrt_code_t rs_hook;     /*!<\~russian  Хук, исполняется планировщиком перед восстановлением контекста процесса. \~english  A context restore hook, it is run before restoring a process context.*/
    void * arg;              /*!<\~russian  Аргумент для pmain, sv_hook, rs_hook, может хранить ссылку на локальные данные конкретного экземпляра процесса. \~english An argument for pmain, sv_hook, rs_hook, may be used to store process local data.*/

    bgrt_stack_t * sstart;   /*!<\~russian  Указатель на дно стека экземпляра процесса. \~english A process stack bottom pointer.*/
    bgrt_stack_t * spointer; /*!<\~russian Указатель на вершину стека экземпляра процесса. \~english A process stack top pointer.*/

    BGRT_USPD_PROC_T udata;  /*!<\~russian Данные процесса из пространства пользователя. \~english User space process data.*/
};
/*
Порядок захвата блокировок:
1) при постановке процесса в список: 1-блокировка процесса, 2-блокировка списка
2) при удалении процесса из списка, без изменения полей кроме parent: блокировка списка
3) при удалении процесса из списка, с изменениями полей кроме parent: 1-блокировка процесса, 2-блокировка списка
*/
/* Флаги*/
/*!
\~russian
\brief Флаг реального времени.

Для этого процесса используется политика планирования жёсткого реального времени.
\~english
\brief A real time flag.

This flag enables real time process scheduling policy.
*/
#define BGRT_PROC_FLG_RT         ((bgrt_flag_t)0x80)
/*!
\~russian
\brief Флаг карусельной многозадачности.

Если выставлен этот флаг, то используется карусельная многозадачность, если нет - ФИФО.
\~english
\brief A round-robin flag.

If this flag is set, then round-robin scheduling is used, else FIFO a process is scheduled in fifo manner.
*/
#define BGRT_PROC_FLG_RR   ((bgrt_flag_t)0x40)
/*!
\~russian
\brief Флаг блокировки останова процесса.

В данный момент процесс нельзя останавливать.
\~english
\brief A process stop lock flag.

A process can not be stopped at this moment.
*/
#define BGRT_PROC_FLG_LOCK      ((bgrt_flag_t)0x20)
/*!
\~russian
\brief Флаг запроса останова.

Произошёл запрос на останов процесса. Процесс будет остановлен при первой же возможности.
\~english
\brief A process stop preparation flag.

A process must be stopped, but it can't be stopped now. It'll be stopped when possible.
*/
#define BGRT_PROC_FLG_PRE_STOP    ((bgrt_flag_t)0x10)

/*!
\~russian
\brief Маска #BGRT_PROC_FLG_LOCK.

Нужна, чтобы определить, удерживает ли процесс общие ресурсы.
\~english
\brief A #BGRT_PROC_FLG_LOCK.

Used to test if a process has locked some resources.
*/
#define BGRT_PROC_FLG_LOCK_MASK ((bgrt_flag_t)(BGRT_PROC_FLG_LOCK))

/*!
\~russian
\brief Маска очистки состояния исполнения процесса.

Нужна, чтобы очистить биты состояния выполнения процесса в поле proc->flags.
\~english
\brief An execution state clear mask.

Used clear execution state bits in proc->flags.
*/
#define BGRT_PROC_STATE_CLEAR_MASK ((bgrt_flag_t)0xF0)

/*!
\~russian
\brief Маска очистки состояния исполнения процесса.

Нужна, чтобы очистить младшие биты состояния выполнения процесса в поле proc->flags.
\~english
\brief An execution state clear mask.

Used clear execution three LSBs state bits in proc->flags.
*/
#define BGRT_PROC_STATE_CLEAR_RUN_MASK ((bgrt_flag_t)0xFC)

/*!
\~russian
\brief Маска состояния исполнения процесса.

\~english
\brief An execution state mask.
*/
#define BGRT_PROC_STATE_MASK ((bgrt_flag_t)0x0F)
/*!
\~russian
\brief Маска проверки состояния процесса.

Используется функцией #bgrt_priv_proc_restart, для проверки возможности перезапуска.

\~english
\brief A process execution state check mask.

Used by #bgrt_priv_proc_restart to check for restart possibility.
*/
#define BGRT_PROC_STATE_RESTART_MASK ((bgrt_flag_t)0x8)

/*!
\~russian
\brief Маска проверки состояния процесса.

Используется для того, чтобы проверить, запущен ли процесс.

\~english
\brief A process execution state check mask.

Used to check if the process has been run.
*/
#define BGRT_PROC_STATE_RUN_MASK ((bgrt_flag_t)0x3)

/*!
\~russian
\brief Маска проверки состояния процесса.

Используется для того, чтобы проверить, ожидает ли процесс синхронизации.

\~english
\brief A process execution state check mask.

Used to check if the process is waiting for synchronization.
*/
#define BGRT_PROC_STATE_WAIT_MASK ((bgrt_flag_t)0x8)

/*process states*/
#define BGRT_PROC_STATE_STOPED           ((bgrt_flag_t)0x0)   /*!< \~russian \brief Начальное состояние, остановлен. \~english \brief Initial state, stopped. */
#define BGRT_PROC_STATE_END              ((bgrt_flag_t)0x1)   /*!< \~russian \brief Завершен. \~english \brief Normal process termination. */
#define BGRT_PROC_STATE_READY            ((bgrt_flag_t)0x2)   /*!< \~russian \brief Готов к выполнению. \~english \brief Is ready to run. */
#define BGRT_PROC_STATE_RUNNING          ((bgrt_flag_t)0x3)   /*!< \~russian \brief Выполняется. \~english \brief Is running. */

#define BGRT_PROC_STATE_WD_STOPED        ((bgrt_flag_t)0x4)   /*!< \~russian \brief Остановлен по вачдог. \~english \brief Watchdog termination. */
#define BGRT_PROC_STATE_DEAD             ((bgrt_flag_t)0x5)   /*!< \~russian \brief Завершен до завершения ipc-транзакций. \~english \brief Abnormal termination, terminated with waiting ipc transactions. */
#define BGRT_PROC_STATE_TO_READY         ((bgrt_flag_t)0x6)   /*!< \~russian \brief Готов к выполнению. \~english \brief Is ready to run. */
#define BGRT_PROC_STATE_TO_RUNNING       ((bgrt_flag_t)0x7)   /*!< \~russian \brief Выполняется. \~english \brief Is running. */

#define BGRT_PROC_STATE_SYNC_WAIT        ((bgrt_flag_t)0x8)   /*!< \~russian \brief Ожидает приема спящих процессов. \~english \brief Is waiting for sleaping processes.*/
#define BGRT_PROC_STATE_SYNC_SLEEP       ((bgrt_flag_t)0x9)   /*!< \~russian \brief Ожидает пробуждения. \~english \brief Is waiting for wakeup. */
#define BGRT_PROC_STATE_SYNC_READY       ((bgrt_flag_t)0xA)   /*!< \~russian \brief Готов к выполнению. \~english \brief Is ready to run. */
#define BGRT_PROC_STATE_SYNC_RUNNING     ((bgrt_flag_t)0xB)   /*!< \~russian \brief Выполняется. \~english \brief Is running. */

#define BGRT_PROC_STATE_PI_PEND          ((bgrt_flag_t)0xC)   /*!< \~russian \brief Ожидает смены приоритета \~english \brief A process is waiting for priority change */
#define BGRT_PROC_STATE_PI_DONE          ((bgrt_flag_t)0xD)   /*!< \~russian \brief Запущен при смене приоритета \~english \brief A process has been run during priority change */
#define BGRT_PROC_STATE_PI_READY         ((bgrt_flag_t)0xE)   /*!< \~russian \brief Готов к выполнению. \~english \brief Is ready to run. */
#define BGRT_PROC_STATE_PI_RUNNING       ((bgrt_flag_t)0xF)   /*!< \~russian \brief Выполняется. \~english \brief Is running. */

/*!
\~russian
\brief Макрос проверки условий останова по флагу #BGRT_PROC_FLG_PRE_STOP.

Используется для проверки процессов на возможность останова по флагу #BGRT_PROC_FLG_PRE_STOP.
Процесс не должен удерживать общие ресурсы в момент останова по флагу.

\warning Для внутреннего использования.

\~english
\brief A #BGRT_PROC_FLG_PRE_STOP condition test macro.

Used to test if a process can be stopped on #BGRT_PROC_FLG_PRE_STOP flag.
A process should not have locked resources at a moment of a flag stop.

\warning For internal usage.

*/
#define BGRT_PROC_PRE_STOP_TEST(a) ((((a)->flags) & BGRT_PROC_FLG_PRE_STOP) && (!(((a)->flags) & BGRT_PROC_FLG_LOCK_MASK)))
/*!
\~russian
\brief Проверяет, запущен ли процесс.

\warning Для внутреннего использования.

\~english
\brief Check if process is ready or running

\warning For internal usage.
*/
#define BGRT_PROC_RUN_TEST(a) (((a)->flags & BGRT_PROC_STATE_RUN_MASK)>= BGRT_PROC_STATE_READY)
/*!
\~russian
\brief Читает состояние процесса.

\warning Для внутреннего использования.

\~english
\brief Reads a process state.

\warning For internal usage.
*/
#define BGRT_PROC_GET_STATE(a) ((a)->flags & BGRT_PROC_STATE_MASK)
/*!
\~russian
\brief Устанавливает состояние процесса.

\warning Для внутреннего использования.

\~english
\brief Sets a process state.

\warning For internal usage.

*/
#define BGRT_PROC_SET_STATE(a,b) ((a)->flags &= BGRT_PROC_STATE_CLEAR_MASK, (a)->flags |= b)
/* Методы*/
/* Управление счётчиком захваченных ресурсов, для внутреннего использования*/
/*!
\~russian
\brief Управление приоритетом процесса.

Инкрементирует счётчик proc->lres, устанавливает флаг #BGRT_PROC_FLG_LOCK.

\warning Для внутреннего использования.

\param proc - Указатель на процесс.
\param prio - Новое значение приоритета.

\~english
\brief Process priority control.

Increments proc->lres counter, sets #BGRT_PROC_FLG_LOCK flag.

\warning For internal usage.

\param proc - A pointer to a process.
\param prio - New process priority value.
*/
void bgrt_priv_proc_lres_inc(bgrt_proc_t * proc ,bgrt_prio_t prio);
/*!
\~russian
\brief Управление приоритетом процесса.

Декрементирует счётчик proc->lres, сбрасывает флаг #BGRT_PROC_FLG_LOCK при необходимости.

\warning Для внутреннего использования.

\param proc - Указатель на процесс.
\param prio - Новое значение приоритета.

\~english
\brief Process priority control.

Decrements proc->lres counter, clears #BGRT_PROC_FLG_LOCK flag if needed.

\warning For internal usage.

\param proc - A pointer to a process.
\param prio - New process priority value.
*/
void bgrt_priv_proc_lres_dec(bgrt_proc_t * proc ,bgrt_prio_t prio);
/*!
\~russian
\brief Останов процесса.

Гарантированно останавливает процесс.

\warning Для внутреннего использования.

\param proc - Указатель на процесс.
\param state - Новое состояние процесса.

\~english
\brief Stops a process.

Stops a process for sure.

\warning For internal usage.

\param proc - A pointer to a process.
\param state - A new process state.
*/
void bgrt_priv_proc_stop_ensure(bgrt_proc_t * proc, bgrt_flag_t state);
/*!
\brief \~russian Инициализация процесса из обработчика прерывания, либо из критической секции. \~english A process initialization. Must be used in critical sections and interrupt service routines.
*/
bgrt_st_t bgrt_priv_proc_init(
    bgrt_proc_t * proc,      /*!< \~russian Указатель на инициируемый процесс. \~english A pointer to a initialized process.*/
    bgrt_code_t pmain,       /*!< \~russian Указатель на главную функцию процесса. \~english A pointer to a process "main" routine.*/
    bgrt_code_t sv_hook,     /*!< \~russian Указатель на хук proc->sv_hook. \~english A context save hook pointer.*/
    bgrt_code_t rs_hook,     /*!< \~russian Указатель на хук proc->rs_hook. \~english A context save hook pointer.*/
    void * arg,         /*!< \~russian Указатель на аргумент. \~english An argument pointer.*/
    bgrt_stack_t *sstart,    /*!< \~russian Указатель на дно стека процесса. \~english A process stack bottom pointer.*/
    bgrt_prio_t prio,        /*!< \~russian Приоритет. \~english A process priority.*/
    bgrt_tmr_t time_quant, /*!< \~russian Квант времени. \~english A process time slice.*/
    bgrt_bool_t is_rt        /*! \~russian Флаг реального времени, если true, значит процесс будет иметь поведение RT. \~english A real time flag. If true, then a process is scheduled in a real time manner.*/
#ifdef BGRT_CONFIG_MP
    ,bgrt_aff_t affinity/*!< \~russian Аффинность. \~english A process affinity.*/
#endif /*BGRT_CONFIG_MP*/
);
/*!
\brief \~russian Инициализация процесса. \~english A process initialization.
*/
bgrt_st_t bgrt_proc_init(
    bgrt_proc_t * proc,      /*!< \~russian Указатель на инициируемый процесс. \~english A pointer to a initialized process.*/
    bgrt_code_t pmain,       /*!< \~russian Указатель на главную функцию процесса. \~english A pointer to a process "main" routine.*/
    bgrt_code_t sv_hook,     /*!< \~russian Указатель на хук proc->sv_hook. \~english A context save hook pointer.*/
    bgrt_code_t rs_hook,     /*!< \~russian Указатель на хук proc->rs_hook. \~english A context save hook pointer.*/
    void * arg,         /*!< \~russian Указатель на аргумент. \~english An argument pointer.*/
    bgrt_stack_t *sstart,    /*!< \~russian Указатель на дно стека процесса. \~english A process stack bottom pointer.*/
    bgrt_prio_t prio,        /*!< \~russian Приоритет. \~english A process priority.*/
    bgrt_tmr_t time_quant, /*!< \~russian Квант времени. \~english A process time slice.*/
    bgrt_bool_t is_rt        /*! \~russian Флаг реального времени, если true, значит процесс будет иметь поведение RT. \~english A real time flag. If true, then a process is scheduled in a real time manner.*/
#ifdef BGRT_CONFIG_MP
    ,bgrt_aff_t affinity/*!< \~russian Аффинность. \~english A process affinity.*/
#endif /*BGRT_CONFIG_MP*/
);
/*!
\~russian
\brief Завершение работы процесса после возврата из proc->pmain.

\~english
\brief A process termination routine called after proc->pmain return. Internal usage function.
*/
void bgrt_proc_terminate(void);
/*!
\~russian
\brief Завершение работы процесса после возврата из proc->pmain.

\warning Для внутреннего использования.

\~english
\brief A process termination routine called after proc->pmain return. Internal usage function.

\warning For internal usage.
*/
void bgrt_priv_proc_terminate(void);
/*!
\~russian
\brief Запуск процесса из критической секции, либо обработчика прерывания.

Ставит процесс в список готовых к выполнению, если можно (процесс не запущен, ещё не завершил работу, не был "убит"), и производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return BGRT_ST_OK - если процесс был вставлен в список готовых к выполнению, либо код ошибки.

\~english
\brief A process launch routine for usage in interrupt service routines and critical sections.

This function schedules a process if possible.

\param proc - A pointer to a process to launch.
\return BGRT_ST_OK - if a process has been scheduled, error code in other cases.
*/
bgrt_st_t bgrt_priv_proc_run(bgrt_proc_t * proc);
/*!
\~russian
\brief Перезапуск процесса из критической секции или обработчика прерывания.

Если можно (процесс не запущен, завершил работу, не был "убит"), приводит структуру proc в состояние, которое было после вызова #bgrt_proc_init, и ставит процесс в список готовых к выполнению, производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return BGRT_ST_OK - если процесс был вставлен в список готовых к выполнению, либо код ошибки.

\~english
\brief A process restart routine for usage in interrupt service routines and critical sections.

This function reinitializes a process and schedules it if possible.

\param proc - A pointer to a process to launch.
\return BGRT_ST_OK - if a process has been scheduled, error code in other cases.
*/
bgrt_st_t bgrt_priv_proc_restart(bgrt_proc_t * proc);
/*!
\~russian
\brief Останов процесса из критической секции или обработчика прерывания.

Вырезает процесс из списка готовых к выполнению и производит перепланировку.
\param proc - Указатель на останавливаемый процесс.
\return BGRT_ST_OK - если процесс был вырезан из списка готовых к выполнению, либо код ошибки.

\~english
\brief A process stop routine for usage in interrupts service routines and critical sections.

This function stops a process if possible.
\param proc - A pointer to a process to stop.
\return BGRT_ST_OK - if a process has been stopped, error code in other cases.
*/
bgrt_st_t bgrt_priv_proc_stop(bgrt_proc_t * proc);
/*!
\~russian
\brief Самоостанов процесса.

Вырезает вызывающий процесс из списка готовых к выполнению и производит перепланировку.

\warning Для внутреннего использования.

\~english
\brief A process self stop routine.

This function stops caller process.

\warning For internal usage.

*/
void bgrt_priv_proc_self_stop(void);
/*!
\~russian
\brief Сброс watchdog для процесса реального времени из обработчика прерывания.

Если функцию вызывает процесс реального времени, то функция сбрасывает его таймер.
Если процесс завис, и таймер не был вовремя сброшен, то планировщик остановит такой процесс и передаст управление другому.

\warning Для внутреннего использования.

\~english
\brief A watchdog reset routine for real time processes.

If a caller process is real time, then this function resets its timer.
If a real time process failed to reset its watchdog, then the scheduler stops such process and wakes up next ready process.

\warning For internal usage.
*/
void bgrt_priv_proc_reset_watchdog(void);
/*===========================================================*/
/*!
\~russian
\brief Установка флага #BGRT_PROC_FLG_LOCK для вызывающего процесса.

\warning Для внутреннего использования.

\~english
\brief Set #BGRT_PROC_FLG_LOCK for caller process.

\warning For internal usage.
*/
void bgrt_priv_proc_lock(void);
/*!
\~russian
\brief Останов процесса по флагу #BGRT_PROC_FLG_PRE_STOP из критической секции или обработчика прерывания.

\warning Для внутреннего использования.

\~english
\brief A #BGRT_PROC_FLG_PRE_STOP flag processing routine.

\warning For internal usage.
*/
void bgrt_priv_proc_free(void);
/*!
\~russian
\brief Управление приоритетом процесса.

Устанавливает приоритет процесса, находящегося в любом состоянии.

\warning Для внутреннего использования.

\param proc - Указатель на процесс.
\param prio - Новое значение приоритета.

\~english
\brief Set a priority of a process.

It sets a process priority. A process current state doesn't matter.

\warning For internal usage.

\param proc - A pointer to a process.
\param prio - New process priority value.
*/
void bgrt_priv_proc_set_prio(bgrt_proc_t * proc, bgrt_prio_t prio);
/*!
\~russian
\brief Получить приоритет процесса.

\warning Для внутреннего использования.

\param proc - Указатель на процесс.
\return - Значение приоритета процесса.

\~english
\brief Get a priority of a process.

\warning For internal usage.

\param proc - A process pointer.
\return - A process priority value.
*/
bgrt_prio_t bgrt_priv_proc_get_prio(bgrt_proc_t * proc);

BGRT_CDECL_END
#endif /*BGRT_PROC_H*/
