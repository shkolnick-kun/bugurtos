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

\def PROC_PRIO_CONTROL_RUNNING(a)
\brief Макрос-обертка.

Управление приоритетом запущенного процесса.
В случае использования протокола highest locker приводит
поле proc->group->prio в соответствие с полем proc-lres,
иначе - пустой макрос.

\param a указатель на процесс.

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

\def PROC_PRIO_CONTROL_RUNNING(a)
\brief Wrapper macro.

Running process priority control.
If highest locker protocol is used,
then this macro computes a proc->group->prio using proc->lres field,
else this macro does nothing.

\param a a pointer to a process.

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

#define PROC_PRIO_CONTROL_RUNNING(a) _proc_prio_control_running(a)
#define PROC_PRIO_CONTROL_STOPED(a) _proc_prio_control_stoped(a)

#else

#define PROC_LRES_INIT(a) a->lres = (count_t)0
#define PROC_LRES_INC(a,b) _proc_lres_inc(a)
#define PROC_LRES_DEC(a,b) _proc_lres_dec(a)

#define PROC_PRIO_CONTROL_RUNNING(a)
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

It's possible to use one "main" routine for many processes, as differents processes are independent, but you have to remember one thing aboun static variables in such "main" routine.

\warning
Be carefull with static variables, these variables are common for all processes sharing one routine!
You must access such static variables using process synchronization facilities.
*/
struct _proc_t
{
    gitem_t parent;     /*!<\~russian Родитель - #gitem_t. \~english A parent is #gitem_t.*/
    flag_t flags;       /*!<\~russian  Флаги (для ускорения анализа состояния процесса). \~english Process state flags (to treat process state quickly).*/
#ifdef CONFIG_USE_HIGHEST_LOCKER
    prio_t base_prio;     /*!<\~russian  Базовый приоритет. \~english A base process priority.*/
    pcounter_t lres;     /*!<\~russian  Счетчик захваченных ресурсов. \~english A locked resource counter.*/
#else
    count_t lres;       /*!<\~russian  Счетчик захваченных ресурсов. \~english A locked resource counter.*/
#endif
    timer_t time_quant; /*!<\~russian  Квант времени процесса. \~english A process time slice.*/
    timer_t timer;      /*!<\~russian  Таймер процесса, для процессов жесткого реального времени используется как watchdog. \~english A process timer, it is used as watchdog for real time processes*/

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

    void * ipc;         /*!<\~russian  Указатель на хранилище для передачи данных через IPC. \~english A pointer to process IPC data storage.*/

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
#define PROC_FLG_RT         ((flag_t)1)
/*!
\~russian
\brief Флаг запущен.

Процесс исполняется или готов к исполнению.
\~english
\brief A process launch flag.

A process has been launched.
*/
#define PROC_FLG_RUN        ((flag_t)2)
/*!
\~russian
\brief Флаг захвата мьютексов.

Процесс удерживает мьютекс.
\~english
\brief A mutex lock flag.

A process has locked some mutex controled resources.
*/
#define PROC_FLG_MUTEX       ((flag_t)4)
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
#define PROC_FLG_SEM      ((flag_t)8)
/*!
\~russian
\brief Флаг постановки в список ожидания.

Процесс стоит в списке ожидающих захвата семафора или мьютекса.
\~english
\brief A queue flag.

A process is waiting for semaphore or mutex release.
*/
#define PROC_FLG_QUEUE      ((flag_t)16)
/*!
\~russian
\brief Флаг постановки в список ожидания сигнала.

Процесс стоит в списке ожидающих сигнал.
\~english
\brief A signal wait flag.

A process is waiting for signal.
*/
#define PROC_FLG_WAIT       ((flag_t)32)
/*!
\~russian
\brief Флаг ожидания передачи данных через IPC.

Показывает, что процесс ждет передачи данных через IPC.
\~english
\brief An IPC wait flag.

A process is waiting for data.
*/
#define PROC_FLG_IPCW       ((flag_t)64)

/*!
\~russian
\brief Флаг запроса останова.

Произошел запрос на останов процесса. Процесс будет остановлен при первой же возможности.
\~english
\brief A proces stop preparation flag.

A process must be stoped, but it can't be stoped now. It'll be stoped when possible.
*/
#define PROC_FLG_PRE_STOP    ((flag_t)128)
/*!
\~russian
\brief Окончания работы.

Процесс завершился - произошел возврат из pmain.
\~english
\brief A process end flag.

A process "main" routine returned, a process has been terminated normally.
*/
#define PROC_FLG_END        ((flag_t)256)
/*!
\~russian
\brief Флаг останова по watch_dog.
\~english
\brief A watchdog stop flag.

A real time process failed to reset its watchdog, it has been tertminated.
*/
#define PROC_FLG_WD_STOP    ((flag_t)512)
/*!
\~russian
\brief Флаг "мертвого" процесса.

Процесс выполнил недопустимую операцию и был "убит", раньше надо было думать.
\~english
\brief A "dead" process flag.

A process "main" routine returned, but process hadn't released some mutex controled resources.
A process has been terminated abnormally.
*/
#define PROC_FLG_DEAD       ((flag_t)1024)


// Методы
/*!
\brief Инициализация процесса из обработчика прерывания, либо из критической секции.
*/
void proc_init_isr(
    proc_t * proc,      /*!<Указатель на инициируемый процесс.*/
    code_t pmain,       /*!<Указатель на главную функцию процесса.*/
    code_t sv_hook,     /*!<Указатель на хук proc->sv_hook.*/
    code_t rs_hook,     /*!<Указатель на хук proc->rs_hook.*/
    void * arg,         /*!<Указатель на аргумент.*/
    stack_t *sstart,    /*!<Указатель на дно стека процесса.*/
    prio_t prio,        /*!<Приоритет.*/
    timer_t time_quant, /*!<Квант времени.*/
    bool_t is_rt        /*!Флаг реального времени, если true, значит процесс будет иметь поведение RT.*/
#ifdef CONFIG_MP
    ,affinity_t affinity/*!<Афинность.*/
#endif // CONFIG_MP
);
/*!
\brief Инициализация процесса.
*/
void proc_init(
    proc_t * proc,      /*!<Указатель на инициируемый процесс.*/
    code_t pmain,       /*!<Указатель на главную функцию процесса.*/
    code_t sv_hook,     /*!<Указатель на хук proc->sv_hook.*/
    code_t rs_hook,     /*!<Указатель на хук proc->rs_hook.*/
    void * arg,         /*!<Указатель на аргумент.*/
    stack_t *sstart,    /*!<Указатель на дно стека процесса.*/
    prio_t prio,        /*!<Приоритет.*/
    timer_t time_quant, /*!<Квант времени.*/
    bool_t is_rt        /*!Флаг реального времени, если true, значит процесс будет иметь поведение RT.*/
#ifdef CONFIG_MP
    ,affinity_t affinity/*!<Афинность.*/
#endif // CONFIG_MP
);
/*!
\brief Обертка для запуска процессов.

Эта функция  вызывает proc->pmain(proc->arg), и если происходит возврат из pmain, то #proc_run_wrapper корректно завершает процесс.
\param proc - Указатель на запускаемый процесс.
*/
void proc_run_wrapper(proc_t * proc);
/*!
\brief Завершение работы процесса после возврата из proc->pmain. Для внутреннего использования.

\param proc - Указатель на запускаемый процесс.
*/
void _proc_terminate(proc_t * proc);
/*!
\brief Запуск процесса.

Ставит процесс в список готовых к выполнению, если можно (процесс не запущен, еще не завершил работу, не был "убит"), и производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return 1 - если процесс был вставлен в список готовых к выполнению, 0 во всех остальных случаях.
*/
bool_t proc_run(proc_t * proc);
/*!
\brief Запуск процесса из критической секции, либо обработчика прерывания.

Ставит процесс в список готовых к выполнению, если можно (процесс не запущен, еще не завершил работу, не был "убит"), и производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return 1 - если процесс был вставлен в список готовых к выполнению, 0 во всех остальных случаях.
*/
bool_t proc_run_isr(proc_t * proc);

/*!
\brief Перезапуск процесса.

Если можно (процесс не запущен, завершил работу, не был "убит"), приводит структуру proc в состояние, которое было после вызова #proc_init, и ставит процесс в список готовых к выполнению, и производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return 1 - если процесс был вставлен в список готовых к выполнению, 0 во всех остальных случаях.
*/
bool_t proc_restart(proc_t * proc);
/*!
\brief Перезапуск процесса из критической секции или обработчика прерывания.

Если можно (процесс не запущен, завершил работу, не был "убит"), приводит структуру proc в состояние, которое было после вызова #proc_init, и ставит процесс в список готовых к выполнению, производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return 1 - если процесс был вставлен в список готовых к выполнению, 0 во всех остальных случаях.
*/
bool_t proc_restart_isr(proc_t * proc);
/*!
\brief Останов процесса.

Вырезает процесс из списка готовых к выполнению и производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return 1 - если процесс был вставлен в список готовых к выполнению, 0 во всех остальных случаях.
*/
bool_t proc_stop(proc_t * proc);
/*!
\brief Останов процесса из критической секции или обработчика прерывания.

Вырезает процесс из списка готовых к выполнению и производит перепланировку.
\param proc - Указатель на запускаемый процесс.
\return 1 - если процесс был вставлен в список готовых к выполнению, 0 во всех остальных случаях.
*/
bool_t proc_stop_isr(proc_t * proc);
/*!
\brief Самоостанов процесса.

Вырезает вызывающий процесс из списка готовых к выполнению и производит перепланировку.
*/
void proc_self_stop(void);
/*!
\brief Сброс watchdog для процесса реального времени.

Если функцию вызывает процесс реального времени, то функция сбрасывает его таймер.
Если процесс завис, и таймер не был вовремя сброшен, то планировщик остановит такой процесс и передаст управление другому.
*/
void proc_reset_watchdog(void);
/*!
\brief Сброс watchdog для процесса реального времени из обработчика прерывания (для внутреннего использования).

Если функцию вызывает процесс реального времени, то функция сбрасывает его таймер.
Если процесс завис, и таймер не был вовремя сброшен, то планировщик остановит такой процесс и передаст управление другому.
*/
void _proc_reset_watchdog(void);

//  Функция для внутреннего использования - собственно запуск процесса
#ifdef CONFIG_MP
/*!
\brief Вставка процесса в список готовых к выполнению, для внутреннего использования.
*/
void _proc_run_( proc_t * proc );
#else
/*!
\brief Вставка процесса в список готовых к выполнению, для внутреннего использования.
*/
#define _proc_run_(proc) gitem_insert( (gitem_t *)proc, kernel.sched.ready )
#endif
/*!
\brief "Низкоуровневый" запуск процесса, для внутреннего использования.
*/
void _proc_run( proc_t * proc );

#ifdef CONFIG_MP
/*!
\brief Вырезка процесса из списка готовых к выполнению с обновлением статистики, для внутреннего использования.
*/
void _proc_stop_(proc_t * proc);
#else
/*!
\brief Вырезка процесса из списка готовых к выполнению, для внутреннего использования.
*/
#define _proc_stop_(proc) gitem_cut((gitem_t *)proc)
#endif
/*!
\brief "Низкоуровневый" останов процесса, для внутреннего использования.
*/
void _proc_stop(proc_t * proc);

/*!
\brief Останов процесса по флагу #PROC_FLG_PRE_STOP из критической секции или обработчика прерывания, для внутреннего использования.
*/
void _proc_flag_stop( flag_t mask );
/*!
\brief Останов процесса по флагу #PROC_FLG_PRE_STOP.
*/
void proc_flag_stop( flag_t mask );
// Упраление счетчиком захваченных ресурсов, для внутреннего использования
/*!
\brief Инкремент счетчика захваченных ресурсов, для внутреннего использования.
*/
void _proc_lres_inc(
    proc_t * proc /*!< Указатель на процесс, захвативший ресурс. */
#ifdef CONFIG_USE_HIGHEST_LOCKER
    ,prio_t prio /*!< Приоритет захваченного ресурса, используется совместно с опцией CONFIG_USE_HIGHEST_LOCKER. */
#endif
);
/*!
\brief Декремент счетчика захваченных ресурсов, для внутреннего использования.
*/
void _proc_lres_dec(
    proc_t * proc /*!< Указатель на процесс, захвативший ресурс. */
#ifdef CONFIG_USE_HIGHEST_LOCKER
    ,prio_t prio /*!< Приоритет захваченного ресурса, используется совместно с опцией CONFIG_USE_HIGHEST_LOCKER. */
#endif
);
#ifdef CONFIG_USE_HIGHEST_LOCKER
/*!
\brief Управление приоритетом процесса, для внутреннего использования.

Используется совместно с опцией CONFIG_USE_HIGHEST_LOCKER. Процесс должен быть остановлен на момент вызова.
\param proc - Указатель на процесс.
*/
void _proc_prio_control_stoped( proc_t * proc );
/*!
\brief Управление приоритетом процесса, для внутреннего использования.

Используется совместно с опцией CONFIG_USE_HIGHEST_LOCKER. Процесс должен быть запущен на момент вызова.
\param proc - Указатель на процесс.
*/
void _proc_prio_control_running( proc_t * proc );
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
\brief Ленивая балансировка нагрузки, для внутренненго использования.

Переносит 1 процесс на самое не нагруженное процессорное ядро в системе.
\param object_core - процессорное ядро, с которого будем снимать нагрузку.
*/
void _proc_lazy_load_balancer(core_id_t object_core);
/*!
\brief Ленивая балансировка нагрузки, для внутреннего использования.

Ищет самое нагруженное процессорное ядро в системе и переносит с него один процесс на самое ненагруженное ядро в системе.
*/
void _proc_global_lazy_load_balancer(void);

/*!
\brief Ленивая балансировка нагрузки, локальный балансировщик.

Переносит 1 процесс с ядра, на котором выполняется на самое не нагруженное процессорное ядро в системе.
*/
void proc_lazy_local_load_balancer(void);
/*!
\brief Ленивая балансировка нагрузки, глобальный балансировщик.

Ищет самое нагруженное процессорное ядро в системе и переносит с него один процесс на самое ненагруженное ядро в системе.
*/
void proc_lazy_global_load_balancer(void);

#endif // CONFIG_MP CONFIG_USE_ALB

#endif // _PROC_H_
