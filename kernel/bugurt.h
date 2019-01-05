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
#ifndef BGRT_H
#define BGRT_H

#ifdef __cplusplus
#   define BGRT_CDECL_BEGIN extern "C" {
#   define BGRT_CDECL_END   }
#else
#   define BGRT_CDECL_BEGIN
#   define BGRT_CDECL_END
#endif // __cplusplus
BGRT_CDECL_BEGIN
/*!
\mainpage

\~russian
BuguRTOS - ядро операционной системы реального времени. Написано анонимусом ДЛЯ УДОВОЛЬСТВИЯ.
\warning Распространяется под изменённой лицензией GPLv3, смотрите exception.txt.

\~english
The BuguRTOS is a RTOS bgrt_kernel. It is written by anonymous JUST FOR FUN.
\warning BuguRTOS license is modified GPLv3, look at exception.txt for more info.

*/

/*!
\file
\~russian
\brief Главный заголовочный файл.

В этот файл включены все заголовочные файлы BuguRTOS.
В свою очередь все исходные тексты включают этот файл.
\~english
\brief The top header file.

All other BuguRTOS headers are included here.
On the other hand all BuguRTOS source files include this file.
*/
#define BGRT_CONCAT(a,b) a##b
#define BGRT_CONCAT2(a,b) BGRT_CONCAT(a,b)
#define BGRT_CONCAT3(a,b) BGRT_CONCAT2(a,b)
/*
======================================================
                ОПРЕДЕЛЕНИЯ ТИПОВ
                     TYPEDEFS
======================================================
*/
/*!
\~russian
\brief
Исполняемый код.

Указатель на функцию типа void, принимающую в качестве аргумента указатель типа void.

\~english
\brief
Executable code.

A pointer to a void function, that takes void pointer as argument.
*/
typedef void (* bgrt_code_t)(void *);
/*
======================================================
                     ИНКЛЮДЫ
======================================================
BuguRTOS config (must be included first)
*/
#include <bugurt_config.h>

#ifndef BGRT_ASSERT
#define BGRT_ASSERT(c,msg) do{}while(0)
#endif // BGRT_ASSERT

/*Basic types*/
#include "index.h"  /* ADLINT:SL:[W0073] No include guard! */
#include "item.h"   /* ADLINT:SL:[W0073] No include guard! */
#include "pcounter.h"
#include "xlist.h"
#include "pitem.h" /*Depends on xlist.h*/

/*Kernel services (use basic types)*/
#include "crit_sec.h"
#include "proc.h"
#include "sched.h"
#include "sync.h"
#include "syscall.h"
#include "timer.h"

#include <bugurt_port.h>
/*bgrt_map_t, depends on BGRT_INT_LOCK/FREE*/
#include "vint.h"
/*Kernel (kernel services, must be included after syscall.h and vint.h)*/
#include "kernel.h"

#define BGRT_ST_OK          ((bgrt_st_t)0)  /*!< \~russian \brief Удачное завершение. \~english \brief Success.*/
#define BGRT_ST_ENULL       ((bgrt_st_t)1)  /*!< \~russian \brief Передан нулевой указатель. \~english \brief Null pointer argument. */
#define BGRT_ST_EOWN        ((bgrt_st_t)2)  /*!< \~russian \brief Ошибка владения. \~english \brief Ownership error. */
#define BGRT_ST_EEMPTY      ((bgrt_st_t)3)  /*!< \~russian \brief Список процессов пуст. \~english \brief The process list is empty. */
#define BGRT_ST_ESYNC       ((bgrt_st_t)4)  /*!< \~russian \brief Не тот объект типа #bgrt_sync_t. \~english \brief Wrong #bgrt_sync_t object. */
#define BGRT_ST_ETIMEOUT    ((bgrt_st_t)5)  /*!< \~russian \brief Иcтек таймаут #bgrt_sync_t. \~english \brief Timeout expired. */
#define BGRT_ST_ESTAT       ((bgrt_st_t)6)  /*!< \~russian \brief Ошибка состояния процесса. \~english \brief Process state error. */
#define BGRT_ST_EAGAIN      ((bgrt_st_t)7)  /*!< \~russian \brief Попробуйте ещё раз. \~english \brief Try again. */
#define BGRT_ST_SCALL       ((bgrt_st_t)8)  /*!< \~russian \brief Неправильный системный вызов. \~english \brief Wrong system call. */
#define BGRT_ST_ROLL        ((bgrt_st_t)9)  /*!< \~russian \brief Нужна следующая иттерация. \~english \brief Next itteration needed. */
#define BGRT_ST_IDLE        ((bgrt_st_t)10) /*!< \~russian \brief Простой системы. \~english \brief The system is IDLE. */

/*!
\~russian
\brief Низший приоритет.

\~english
\brief Lowest priority level.
*/
#define BGRT_PRIO_LOWEST ((bgrt_prio_t)BGRT_BITS_IN_INDEX_T - (bgrt_prio_t)1)

/*!
\def BGRT_SPIN_INIT(arg)
\~russian
\brief Макрос-обёртка.

Обёртка инициализации спин-блокировки arg->lock, на однопроцессорной системе - пустой макрос.
\~english
\brief Wrapper macro.

Initialization wrapper for arg->lock spinlock. Empty macro in single core system.
*/
/*!
\def BGRT_SPIN_LOCK(arg)
\~russian
\brief Макрос-обёртка.

Обёртка захвата спин-блокировки arg->lock, на однопроцессорной системе - пустой макрос.
\~english
\brief Wrapper macro.

Lock wrapper for arg->lock spinlock. Empty macro in single core system.
*/
/*!
\def BGRT_SPIN_FREE(arg)
\~russian
\brief Макрос-обёртка.

Обёртка освобождения спин-блокировки arg->lock, на однопроцессорной системе - пустой макрос.
\~english
\brief Wrapper macro.

Lock wrapper for arg->lock spinlock. Empty macro in single core system.
*/
/*!
\def BGRT_RESCHED_PROC(arg)
\~russian
\brief Макрос-обёртка.

Обёртка функции #bgrt_resched.
\~english
\brief Wrapper macro.

A wrapper for #bgrt_resched function.
*/

#ifdef BGRT_CONFIG_MP
#   define BGRT_SPIN_INIT(arg) bgrt_spin_init(&((arg)->lock))
#   define BGRT_SPIN_LOCK(arg) bgrt_spin_lock(&((arg)->lock))
#   define BGRT_SPIN_FREE(arg) bgrt_spin_free(&((arg)->lock))
#   define BGRT_RESCHED_PROC(proc) bgrt_resched(proc->core_id)
#   ifndef BGRT_KERNEL_PREEMPT
#       define BGRT_KERNEL_PREEMPT() bgrt_kblock_do_work(&bgrt_kernel.kblock[bgrt_curr_cpu()])
#   endif
#else /*BGRT_CONFIG_MP*/
#   define BGRT_SPIN_INIT(arg) do{}while (0)
#   define BGRT_SPIN_LOCK(arg) do{}while (0)
#   define BGRT_SPIN_FREE(arg) do{}while (0)
#   define BGRT_RESCHED_PROC(proc) bgrt_resched()
#   ifndef BGRT_KERNEL_PREEMPT
#       define BGRT_KERNEL_PREEMPT() bgrt_kblock_do_work(&bgrt_kernel.kblock)
#   endif
#endif /*BGRT_CONFIG_MP*/
/*
======================================================
   Внешние функции, определяемые пользователем
        User defined external functions
======================================================
*/
#ifdef BGRT_CONFIG_MP

/*!
\~russian
\brief
Инициализация спин-блокировки на многопроцессорной системе.

Инициализация спин-блокировки на многопроцессорной системе.

\warning Для внутреннего использования.

\param lock Указатель на спин-блокировку.
\~english
\brief
Spin-lock initialization for MP system.

\warning Internal usage function.

\param lock a pointer to a spin-lock
*/
extern void bgrt_spin_init(bgrt_lock_t * lock);

/*!
\~russian
\brief
Захват спин-блокировки на многопроцессорной системе.

Захват спин-блокировки на многопроцессорной системе.

\warning Для внутреннего использования.

\param lock Указатель на спин-блокировку.
\~english
\brief
Lock spin-lock on MP system.

\warning Internal usage function.

\param lock a pointer to a spin-lock
*/
extern void bgrt_spin_lock(bgrt_lock_t * lock);

/*!
\~russian
\brief
Освобождение спин-блокировки на многопроцессорной системе.

\param lock Указатель на спин-блокировку.

\warning Для внутреннего использования.

\~english
\brief
Unlock spin-lock on MP system.

\warning Internal usage function.

\param lock a pointer to a spin-lock
*/
extern void bgrt_spin_free(bgrt_lock_t * lock);

/*!
\~russian
\brief
Возвращает id процессорного ядра.

Возвращает id процессорного ядра, на котором исполняется.

\warning Для внутреннего использования.

\~english
\brief
Returns processor core id.

This function returns an id of a processor core on which it is run.

\warning Internal usage function.
*/
extern bgrt_cpuid_t bgrt_curr_cpu(void);

/* Доступ к объектам типа bgrt_ls_t должен быть атомарным!!!*/
/* A bgrt_ls_t access must be atomic!!! */
/*!
\~russian
\brief
Инициализация статистики

Инициализирует структуру bgrt_ls_t, в которой хранится статистика.

\warning Для внутреннего использования.

\param stat Указатель на структуру статистики.
\~english
\brief
Statistic initialization.

Initiates a bgrt_ls_t structure, in which processor core load information is stored.

\warning Internal usage function.

\param stat a pointer to a bgrt_ls_t structure.
*/
extern void bgrt_stat_init(bgrt_ls_t * stat);
/*!
\~russian
\brief
Обновление статистики при запуске процесса/ вставки процесса в очередь сигнала.

Обновление статистики при запуске процесса/ вставки процесса в очередь сигнала.

\warning Для внутреннего использования.

\param proc Указатель на процесс.
\param stat Указатель на структуру статистики.
\~english
\brief
Statistic update on load increase.

Statistic increase on a process run or a process insert to a signal wait list.

\warning Internal usage function.

\param proc a pointer to a process.
\param stat a pointer to a bgrt_ls_t structure.
*/
extern void bgrt_stat_inc(bgrt_proc_t * proc, bgrt_ls_t * stat);
/*!
\~russian
\brief
Обновление статистики при останове процесса/ удаления процесса из очереди сигнала.

Обновление статистики при останове процесса/ удаления процесса из очереди сигнала.

\warning Для внутреннего использования.

\param proc Указатель на процесс.
\param stat Указатель на структуру статистики.
\~english
\brief
Statistic update on load decrease.

Statistic update on a process stop or a process cut from a signal wait list.

\warning Internal usage function.

\param proc a pointer to a process.
\param stat a pointer to a bgrt_ls_t structure.
*/
extern void bgrt_stat_dec(bgrt_proc_t * proc, bgrt_ls_t * stat);
/*!
\~russian
\brief
Перенос статистики.

При передаче процессов из списка ожидающих сигнал в список готовых к выполнению надо обновить статистическую информацию в Ядре.

\warning Для внутреннего использования.

\param src_stat Указатель на структуру статистики сигнала.
\param dst_stat Указатель на структуру статистики Ядра.
\~english
\brief
Statistic merge.

Updates Kernel and a signal statistic when signal wait list is merged with scheduler ready process list.

\warning Internal usage function.

\param src_stat a pointer to a signal statistic structure.
\param dst_stat a pointer to a Kernel statistic structure.
*/
extern void bgrt_stat_merge(bgrt_ls_t * src_stat, bgrt_ls_t * dst_stat);
/*!
\~russian
\brief
Расчёт нагрузки.

Расчёт нагрузки на одном процессорном ядре.

\warning Для внутреннего использования.

\param prio Приоритет процесса, для которого считаем нагрузку.
\param stat Указатель на структуру статистики Ядра.
\return Текущую оценку нагрузки на процессорном ядре, за которое отвечает stat.
\~english
Load calculation.

Processor core load calculation.

\warning Internal usage function.

\param prio a priority of a process for which we want to compute a load.
\param stat a pointer to a Kernel statistic structure.
\return current estimation of the core load.
*/
extern bgrt_load_t bgrt_stat_calc_load(bgrt_prio_t prio, bgrt_ls_t * stat);
/*!
\~russian
\brief
Перепланировка.

Запускает перепланировку на одном из процессорных ядер.

\warning Для внутреннего использования.

\param core_id ID ядра, на котором надо перепланировать исполнение процессов.
\~english
\brief
Rescheduling.

Launches a reschedule sequence on one of the processor cores of the system.

\warning Internal usage function.

\param core_id a processor core id.
*/
extern void bgrt_resched(bgrt_cpuid_t core_id);
#else /* #ifdef BGRT_CONFIG_SAVE_POWER */

/*!
\~russian
\brief
Перепланировка.

Запускает перепланировку.

\warning Для внутреннего использования.

\~english
\brief
Rescheduling.

Launches a reschedule sequence.

\warning Internal usage function.
*/
extern void bgrt_resched(void);
#endif /*BGRT_CONFIG_MP*/

/*!
\~russian
\brief
Текущий процесс.

\warning Для внутреннего использования.

\return Указатель на текущий процесс, исполняемый на локальном процессоре.
\~english
\brief
Current process.

\warning Internal usage function.

\return a pointer to a current process on a local processor core.
*/
extern bgrt_proc_t * bgrt_curr_proc(void);

/*!
\~russian
\brief
Инициализация стека процесса.

Подготовка стека к запуску процесса. Делает так, что после восстановления контекста процесса происходит вызов функции pmain(arg).

\warning Для внутреннего использования.

\param sstart Дно стека.
\param pmain Функция, которая будет вызвана после восстановления контекста.
\param arg Аргумент вызываемой функции.
\param return_address адрес возврата из pmain.
\return Указатель на вершину подготовленного стека.
\~english
\brief
A process stack initialization.

This function prepares a process stack for running a process.
It treats a process stack in such a way that pmain(arg) is called when a process context is restored from a process stack.

\warning Internal usage function.

\param sstart a process stack bottom.
\param pmain a pointer to a function to call.
\param arg an argument to a function to call.
\param return_address an address to return from pmain.
\return a pointer to a prepared process stack top.
*/
extern bgrt_stack_t * bgrt_proc_stack_init(bgrt_stack_t * sstart, bgrt_code_t pmain, void * arg, void (*return_address)(void));
/*!
\~russian
\brief
Инициализация Ядра.

Подготовка Ядра к запуску.
\~english
\brief
The Kernel initiation.

Initiates the Kernel before the OS start.
*/
extern void bgrt_init(void);
/*!
\~russian
\brief
Запуск Ядра.

Запуск Ядра. После вызова этой функции можно ничего не писать - все равно исполняться не будет.
\~english
\brief
The OS start.

The OS start. It is not necessary to write any code after call of this function, because such a code won't be run normally.
*/
extern void bgrt_start(void);
/*!
\~russian
\brief
Системный вызов.

Код Ядра всегда выполняется в контексте Ядра. Это нужно для экономии памяти в стеках процессов.
Соответственно, если мы хотим выполнить какие либо операции над процессами, мьютексами, семафорами, сигналами,
то нам нужно "попросить" Ядро сделать эту работу.

Именно для этого существует функция bgrt_syscall, которая передаёт управление Ядру для выполнения требуемой работы.

\warning Для внутреннего использования.

\param num номер системного вызова (что именно надо выполнить).
\param arg аргумент системного вызова (над чем это надо выполнить).
\~english
\brief
A system call.

This function switches a processor core from a process context to the kernel context.
The kernel code is always run in the kernel context. This is done to save memory in process stacks.
A system calls are done on every operations with processes, mutexes, semaphores and signals.
The Kernel does all of this job.

\warning Internal usage function.

\param num a number of a system call (what is going to be done).
\param arg a system call argument (a pointer to an object to be processed).
*/
extern bgrt_st_t bgrt_syscall(bgrt_syscall_t num, void * arg);

/*!
\~russian
\brief
Переключение из контекста Ядра в контекст текущего процесса.

\~english
\brief
Kernel to process context switch.
*/
extern void bgrt_switch_to_proc(void);

BGRT_CDECL_END
#endif /*BGRT_H*/
