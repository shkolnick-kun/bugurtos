/**************************************************************************
    BuguRTOS-0.7.x(Bugurt real time operating system)
    Copyright (C) 2014  anonimous

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

#ifndef _BUGURT_H_
#define _BUGURT_H_

/*!
\mainpage

\~russian
BuguRTOS - ядро операционной системы реального времени. Написано анонимусом ДЛЯ УДОВОЛЬСТВИЯ.
\warning Распространяется под измененной лицензией GPLv3, смотрите exception.txt.

\~english
The BuguRTOS is a RTOS kernel. It is written by anonimous JUST FOR FUN.
\warning BuguRTOS license is modifyed GPLv3, look at exception.txt for more info.

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
//======================================================
//                ОПРЕДЕЛЕНИЯ ТИПОВ
//                     TYPEDEFS
//======================================================
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
typedef void (* code_t)(void *);

//======================================================
//                     ИНКЛЮДЫ
//======================================================

#ifndef _CONFIG_H_
#error  "You must include config.h to your project!!!"
#endif //_CONFIG_H_

#include "index.h"
#include "item.h"
#include "xlist.h"
#include "gitem.h"
#include "pcounter.h"
#include "crit_sec.h"
#include "proc.h"
#include "sched.h"
#include "kernel.h"
#include "sig.h"
#include "sem.h"
#include "mutex.h"
#include "ipc.h"
#include "timer.h"
#include "syscall.h"

/*!
\def SPIN_INIT(arg)
\~russian
\brief Макрос-обертка.

Обертка инициализации спин-блокировки arg->lock, на однопроцессорной системе - пустой макрос.
\~english
\brief Wrapper macro.

Initialization wrapper for arg->lock spinlock. Emty macro in single core system.
*/
/*!
\def SPIN_LOCK(arg)
\~russian
\brief Макрос-обертка.

Обертка захвата спин-блокировки arg->lock, на однопроцессорной системе - пустой макрос.
\~english
\brief Wrapper macro.

Lock wrapper for arg->lock spinlock. Emty macro in single core system.
*/
/*!
\def SPIN_FREE(arg)
\~russian
\brief Макрос-обертка.

Обертка освобождения спин-блокировки arg->lock, на однопроцессорной системе - пустой макрос.
\~english
\brief Wrapper macro.

Lock wrapper for arg->lock spinlock. Emty macro in single core system.
*/
/*!
\def RESCHED_PROC(arg)
\~russian
\brief Макрос-обертка.

Обертка функции #resched.
\~english
\brief Wrapper macro.

A wrapper for #resched function.
*/

#ifdef CONFIG_MP

#define SPIN_INIT(arg) spin_init( &arg->lock )
#define SPIN_LOCK(arg) spin_lock( &arg->lock )
#define SPIN_FREE(arg) spin_free( &arg->lock )
#define RESCHED_PROC(proc) resched( proc->core_id )

#else

#define SPIN_INIT(arg)
#define SPIN_LOCK(arg)
#define SPIN_FREE(arg)
#define RESCHED_PROC(proc) resched()

#endif
//======================================================
//   Внешние функции, определяемые пользователем
//        User defined external functions
//======================================================
#ifdef CONFIG_MP

/*!
\~russian
\brief
Инициализация спин-блокировки на многопроцессорной системе.

Инициализация спин-блокировки на многопроцессорной системе.

\param lock Указатель на спин-блокировку.
\~english
\brief
Spin-lock initialization for MP system.

Spin-lock initialization for MP system.
\param lock a pointer to a spin-lock
*/
extern void spin_init(lock_t * lock);

/*!
\~russian
\brief
Захват спин-блокировки на многопроцессорной системе.

Захват спин-блокировки на многопроцессорной системе.

\param lock Указатель на спин-блокировку.
\~english
\brief
Lock spin-lock on MP system.

Lock spin-lock on MP system.
\param lock a pointer to a spin-lock
*/
extern void spin_lock(lock_t * lock);

/*!
\~russian
\brief
Освобождение спин-блокировки на многопроцессорной системе.

Освобождение спин-блокировки на многопроцессорной системе.

\param lock Указатель на спин-блокировку.
\~english
\brief
Unlock spin-lock on MP system.

Unlock spin-lock on MP system.
\param lock a pointer to a spin-lock
*/
extern void spin_free(lock_t * lock);

/*!
\~russian
\brief
Возвращает id процессорного ядра.

Возвращает id процессорного ядра, на котором исполняется.
\~english
\brief
Returns processor core id.

This function returns an id of a processor core on which it is run.
*/
extern core_id_t current_core(void);

// Доступ к объектам типа stat_t должен быть атомарным!!!
// A stat_t access must be atomic!!!
/*!
\~russian
\brief
Инициализция статистики

Инициализирует структуру stat_t, в которой хранится статистика.

\param stat Указатель на структуру статистики.
\~english
\brief
Statistic initialization.

Initiates a stat_t structure, in whitch processor core load information is stored.
\param stat a pointer to a stat_t structure.
*/
extern void stat_init(stat_t * stat);
/*!
\~russian
\brief
Обновление статистики при запуске процесса/ всатвки процесса в очередь сигнала.

Обновление статистики при запуске процесса/ всатвки процесса в очередь сигнала.

\param proc Указатель на процесс.
\param stat Указатель на структуру статистики.
\~english
\brief
Statistic update on load increase.

Statistic increase on a process run or a process insert to a signal wait list.
\param proc a pointer to a process.
\param stat a pointer to a stat_t structure.
*/
extern void stat_inc(proc_t * proc, stat_t * stat);
/*!
\~russian
\brief
Обновление статистики при останове процесса/ удаления процесса из очереди сигнала.

Обновление статистики при останове процесса/ удаления процесса из очереди сигнала.

\param proc Указатель на процесс.
\param stat Указатель на структуру статистики.
\~english
\brief
Statistic update on load decrease.

Statistic update on a process stop or a process cut from a signal wait list.
\param proc a pointer to a process.
\param stat a pointer to a stat_t structure.
*/
extern void stat_dec(proc_t * proc, stat_t * stat);
/*!
\~russian
\brief
Перенос статистики.

При передаче процессов из списка ожидающих сигнал в список готовых к выполнению надо обновить статистическую информацию в Ядре.

\param src_stat Указатель на структуру статистики сигнала.
\param dst_stat Указатель на структуру статистики Ядра.
\~english
\brief
Statistic merge.

Updates Kernel and a signal statistic when signal wait list is merged with scheduler ready process list.

\param src_stat a pointer to a signal statistic structure.
\param dst_stat a pointer to a Kernel statistic structure.
*/
extern void stat_merge(stat_t * src_stat, stat_t * dst_stat);
/*!
\~russian
\brief
Расчет нагрузки.

Расчет нагрузки на одном процессорном ядре.

\param prio Приоритет процесса, для которого считаем нагрузку.
\param stat Указатель на структуру статистики Ядра.
\return Текущую оценку нагрузки на процессорном ядре, за которое отвечает stat.
\~english
Load calculation.

Processor core load calculation.

\param prio a priority of a process for which we want to compute a load.
\param stat a pointer to a Kernel statistic structure.
\return current estimation of the core load.
*/
extern load_t stat_calc_load(prio_t prio, stat_t * stat);
/*!
\~russian
\brief
Перепланировка.

Запускает перепланировку на одном из процессорных ядер.

\param core_id ID ядра, на котором надо перепланировать исполнение процессов.
\~english
\brief
Rescheduling.

Launces a reschedule sequence on one of the processor cores of the system.

\param core_id a processor core id.
*/
extern void resched(core_id_t core_id);
#else

/*!
\~russian
\brief
Перепланировка.

Запускает перепланировку.
\~english
\brief
Rescheduling.

Launces a reschedule sequence.
*/
extern void resched(void);
#endif // CONFIG_MP

/*!
\~russian
\brief
Запрет прерываний.

Глобальный запрет прерываний на системе.
\~english
\brief
Interrupt disable.

Disables interrupts globally.
*/
extern void disable_interrupts(void);
/*!
\~russian
\brief
Разрешение прерываний.

Глобальное разрешение прерываний на системе.
\~english
\brief
Interrupt enable.

Enables interrupts globally.
*/
extern void enable_interrupts(void);

/*!
\~russian
\brief
Текущий процесс.

Текущий процесс.
\return Указатель на текущий процесс, исполняемый на локальном процессре.
\~english
\brief
Current process.

Current process.
\return a pointer to a current process on a local processor core.
*/
extern proc_t * current_proc(void);

/*!
\~russian
\brief
Инициализация стека процесса.

Подготовка стека к запуску процесса. Делает так, что после восстановления контекста процесса происходит вызов функции code(arg).
\param sstart Дно стека.
\param code Функция, которая будет вызвана после восстановления контекста.
\param arg Аргумент вызываемой функции.
\param return_address адрес возврата из pmain.
\return Указатель на вершину подготовленного стека.
\~english
\brief
A process stack initialization.

This function prepares a process stack for running a process.
It treats a pocess stack in such a way that pmain(arg) is called when a process context is restored from a process stack.

\param sstart a process stack bottom.
\param pmain a poiter to a function to call.
\param arg an argument to a function to call.
\param return_address an adress to return from pmain.
\return a pointer to a prepared process stack top.
*/
extern stack_t * proc_stack_init(stack_t * sstart, code_t pmain, void * arg, void (*return_address)(void));
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
extern void init_bugurt(void);
/*!
\~russian
\brief
Запуск Ядра.

Запуск Ядра. После вызова этой функции можно ничего не писать - всеравно исполняться не будет.
\~english
\brief
The OS start.

The OS start. It is not necessary to write any code after call of this function, because such a code won't be run normally.
*/
extern void start_bugurt(void);
/*!
\~russian
\brief
Системный вызов.

Код Ядра всегда выполняется в контексте Ядра. Это нужно для экономии памяти в стеках процессов.
Соответственно, если мы хотим выполнить какие либо операции над процессами, мьютексами, семафорами, сигналами,
то нам нужно "попросить" Ядро стелать эту работу.

Именно для этого существует функция syscall_bugurt, которая передает управление Ядру для выполнения треуемой работы.

\param num номер системного вызова (что именно надо выполнить).
\param arg аргумент системного вызова (над чем это надо выполнить).
\~english
\brief
A system call.

This function switches a processor core from a process context to the kernel context.
The kernel code is allways run in the kernel context. This is done to save memory in process stacks.
A system calls are done on every operations with processes, mutexes, semaphores and signals.
The Kernel does all of this job.


\param num a number of a system call (what is going to be done).
\param arg a system call argument (a pointer to an object to be processed).
*/
extern void syscall_bugurt( syscall_t num, void * arg );

#endif //_BUGURT_H_
