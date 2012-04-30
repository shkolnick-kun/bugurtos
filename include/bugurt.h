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

#ifndef _BUGURT_H_
#define _BUGURT_H_

/*!
\mainpage

BuguRTOS - ядро операционной системы реального времени.
Написано анонимусом ДЛЯ УДОВОЛЬСТВИЯ.
\warning Распространяется под измененной лицензией GPLv3, смотрите exception.txt.
*/

/*!
\file
\brief Главный заголовочный файл.

В этот файл включены все заголовочные файлы BuguRTOS.
В свою очередь все исходные тексты включают этот файл.
*/
//======================================================
//                ОПРЕДЕЛЕНИЯ ТИПОВ
//======================================================
/*!
\brief
Исполняемый код.

Указатель на функцию типа void, принимающую в качестве аргумента указатель типа void.
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
#include "group.h"
#include "gitem.h"
#include "pitem.h"
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
\brief Макрос-обертка.

Обертка инициализации спин-блокировки arg->lock, на однопроцессорной системе - пустой макрос.

\def SPIN_LOCK(arg)
\brief Макрос-обертка.

Обертка захвата спин-блокировки arg->lock, на однопроцессорной системе - пустой макрос.

\def SPIN_UNLOCK(arg)
\brief Макрос-обертка.

Обертка освобождения спин-блокировки arg->lock, на однопроцессорной системе - пустой макрос.

\def RESCHED_PROC(arg)
\brief Макрос-обертка.

Обертка функции #resched.
*/

#ifdef CONFIG_MP

#define SPIN_INIT(arg) spin_init( &arg->lock )
#define SPIN_LOCK(arg) spin_lock( &arg->lock )
#define SPIN_UNLOCK(arg) spin_unlock( &arg->lock )
#define RESCHED_PROC(proc) resched( proc->core_id )

#else

#define SPIN_INIT(arg)
#define SPIN_LOCK(arg)
#define SPIN_UNLOCK(arg)
#define RESCHED_PROC(proc) resched()

#endif
//======================================================
//   Внешние функции, определяемые пользователем
//======================================================
#ifdef CONFIG_MP

/*!
\brief
Инициализация спин-блокировки на многопроцессорной системе.

Инициализация спин-блокировки на многопроцессорной системе.

\param lock Указатель на спин-блокировку.
*/
extern void spin_init(lock_t * lock);

/*!
\brief
Захват спин-блокировки на многопроцессорной системе.

Захват спин-блокировки на многопроцессорной системе.

\param lock Указатель на спин-блокировку.
*/
extern void spin_lock(lock_t * lock);

/*!
\brief
Освобождение спин-блокировки на многопроцессорной системе.

Освобождение спин-блокировки на многопроцессорной системе.

\param lock Указатель на спин-блокировку.
*/
extern void spin_unlock(lock_t * lock);

/*!
\brief
Возвращает id процессорного ядра, на котором исполняется.

Возвращает id процессорного ядра, на котором исполняется.
*/
extern core_id_t current_core(void);

// Доступ к объектам типа stat_t должен быть атомарным!!!

/*!
\brief
Инициализция статистики

Инициализирует структуру stat_t, в которой хранится статистика.

\param stat Указатель на структуру статистики.
*/
extern void stat_init(stat_t * stat);
/*!
\brief
Обновление статистики при запуске процесса/ всатвки процесса в очередь сигнала.

Обновление статистики при запуске процесса/ всатвки процесса в очередь сигнала.

\param proc Указатель на процесс.
\param stat Указатель на структуру статистики.
*/
extern void stat_inc(proc_t * proc, stat_t * stat);
/*!
\brief
Обновление статистики при останове процесса/ удаления процесса из очереди сигнала.

Обновление статистики при останове процесса/ удаления процесса из очереди сигнала.

\param proc Указатель на процесс.
\param stat Указатель на структуру статистики.
*/
extern void stat_dec(proc_t * proc, stat_t * stat);
/*!
\brief
Перенос статистики.

При передаче процессов из списка ожидающих сигнал в список готовых к выполнению надо обновить статистическую информацию в Ядре.

\param src_stat Указатель на структуру статистики сигнала.
\param dst_stat Указатель на структуру статистики Ядра.
*/
extern void stat_merge(stat_t * src_stat, stat_t * dst_stat);
/*!
\brief
Расчет нагрузки.

Расчет нагрузки на одном процессорном ядре.

\param prio Приоритет процесса, для которого считаем нагрузку.
\param stat Указатель на структуру статистики Ядра.
\return Текущую оценку нагрузки на процессорном ядре, за которое отвечает stat.
*/
extern load_t stat_calc_load(prio_t prio, stat_t * stat);
/*!
\brief
Перепланировка.

Запускает перепланировку на одном из процессорных ядер.

\param core_id ID ядра, на котором надо перепланировать исполнение процессов.
*/
extern void resched(core_id_t core_id);
#else

/*!
\brief
Перепланировка.

Запускает перепланировку, точнее генерирует программное прерывание, боработчик которого перепланирует выполнение процессов.
*/
extern void resched(void);
#endif // CONFIG_MP

/*!
\brief
Запрет прерываний.

Глобальный запрет прерываний на системе.
*/
extern void disable_interrupts(void);
/*!
\brief
Разрешение прерываний.

Глобальное разрешение прерываний на системе.
*/
extern void enable_interrupts(void);

/*!
\brief
Текущий процесс.

Текущий процесс.
\return Указатель на текущий процесс, исполняемый на локальном процессре.
*/
extern proc_t * current_proc(void);

/*!
\brief
Инициализация стека процесса.

Подготовка стека к запуску процесса. Делает так, что после восстановления контекста процесса происходит вызов функции code(arg).
\param sstart Дно стека.
\param code Функция, которая будет вызвана после восстановления контекста.
\param arg Аргумент вызываемой функции.
\return Указатель на вершину подготовленного стека.
*/
extern stack_t * proc_stack_init(stack_t * sstart, code_t code, void * arg);
/*!
\brief
Инициализация Ядра.

Подготовка Ядра к запуску.
*/
extern void init_bugurt(void);
/*!
\brief
Запуск Ядра.

Запуск Ядра. После вызова этой функции можно ничего не писать - всеравно исполняться не будет.
*/
extern void start_bugurt(void);
/*!
\brief
Системный вызов.

Код Ядра всегда выполняется в контексте Ядра. Это нужно для экономии памяти в стеках процессов.
Соответственно, если мы хотим выполнить какие либо операции над процессами, мьютексами, семафорами, сигналами,
то нам нужно "попросить" Ядро стелать эту работу.

Именно для этого существует функция syscall_bugurt, которая передает управление Ядру для выполнения треуемой работы.

\param num номер системного вызова (что именно надо выполнить).
\param arg аргумент системного вызова (над чем это надо выполнить).
*/
extern void syscall_bugurt( syscall_t num, void * arg );

#endif //_BUGURT_H_
