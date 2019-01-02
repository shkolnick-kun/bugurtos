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
#ifndef BGRT_SCHED_H
#define BGRT_SCHED_H
BGRT_CDECL_BEGIN
/*!
\file
\~russian
\brief
Заголовок планировщика

\warning Все функции в этом файле для внутреннего использования!!!

\~english
\brief
A scheduler header.

\warning All functions in this file are internal usage functions!!!
*/
/*Планировщик*/
typedef struct bgrt_priv_sched_t bgrt_sched_t; /*!< \~russian Смотри #bgrt_priv_sched_t; \~english See #bgrt_priv_sched_t; */
/*Свойства*/
/*!
\~russian
\brief
Планировщик.

Планировщик содержит информацию о процессах, запущенных на процессоре (процессорном ядре).

\~english
\brief
A scheduler.

A scheduler object contains an information about processes, running on some CPU core.
*/
struct bgrt_priv_sched_t
{
    bgrt_proc_t * current_proc;      /*!< \~russian Текущий процесс. \~english A currently running process. */
    bgrt_xlist_t * ready;            /*!< \~russian Указатель на список готовых к выполнению процессов. \~english A pointer to a ready process list. */
    bgrt_xlist_t * expired;          /*!< \~russian Указатель на список процессов, исчерпавших свой квант времени. \~english A pointer to an expired process list. */
    bgrt_xlist_t plst[2];            /*!< \~russian Сами списки процессов. \~english A storage for a ready and for an expired process lists. */
    bgrt_cnt_t nested_crit_sec;    /*!< \~russian Счётчик вложенности критических секций. \~english A critical section nesting count. */
#ifdef BGRT_CONFIG_MP
    bgrt_lock_t lock;                /*!< \~russian Спин-блокировка планировщика. \~english A scheduler spin-lock. */
#endif /*BGRT_CONFIG_MP*/
};
/*Методы*/


/*!
\~russian
\brief Инициализация планировщика.

Готовит планировщик к запуску.

\warning Для внутреннего использования.

\param sched - Указатель на планировщик.

\~english
\brief A scheduler initiation routine.

This function prepares a scheduler object for work.

\warning For internal usage.

\param sched - A scheduler pointer.
*/
void bgrt_sched_init(bgrt_sched_t * sched);
/*!
\~russian
\brief
Функция планирования.

\warning Для внутреннего использования.
\param is_periodic - Флаг работы по периодическому прерыванию.
\return #BGRT_ST_OK - если есть новый процесс, #BGRT_ST_EEMPTY - если нет готовых процессов.

\~english
\brief
A scheduler function.

\warning For internal usage.
\param is_periodic - A periodic interrupt flag.
\return #BGRT_ST_OK is new ready process scheduled, #BGRT_ST_EEMPTY if there were no ready processes.
*/
bgrt_st_t bgrt_sched_run(bgrt_bool_t is_periodic);

/*!
\brief \~russian "Низкоуровневый" запуск процесса, для внутреннего использования. \~english A low level process run routine. For internal usage.
*/
void bgrt_sched_proc_run(bgrt_proc_t * proc, bgrt_flag_t state);
/*!
\brief \~russian "Низкоуровневый" останов процесса, для внутреннего использования. \~english A low level process stop routine. For internal usage.
*/
void bgrt_sched_proc_stop(bgrt_proc_t * proc , bgrt_flag_t state);


/*!
\~russian
\brief Передача управления следующему процессу (для внутреннего использования).

Передаёт управление следующему процессу, если такой процесс есть.

\warning Для внутреннего использования.

\return 0 если нет других выполняющихся процессов, не 0 - если есть.

\~english
\brief Pass control to next ready process (for internal usage only!).

If there is another running process, this function passes control to it.

\warning For internal usage.

\return One if power saving mode can be used, zero in other cases.
*/
bgrt_bool_t bgrt_priv_sched_proc_yield(void);
/*!
\~russian
\brief Передача управления следующему процессу.

Передаёт управление следующему процессу, если такой процесс есть.

\return 0 если нет других выполняющихся процессов, не 0 - если есть.

\~english
\brief Pass control to next ready process.

If there is another running process, this function passes control to it.

\return One if power saving mode can be used, zero in other cases.
*/
bgrt_bool_t bgrt_sched_proc_yield(void);

#ifdef BGRT_CONFIG_MP
/*CPU load information*/
typedef struct bgrt_priv_kstat_t bgrt_kstat_t; /*!< \~russian Статистика для балансировки нагрузки, на Hotplug работать не собираемся, все будет статично. \~english A statistic for load balancing, CPU hotplug is not supported. */
struct bgrt_priv_kstat_t
{
    bgrt_ls_t val[BGRT_MAX_CPU];  /*!< \~russian Значения. \~english A values. */
    bgrt_lock_t lock;             /*!< \~russian Спин-блокировка. \~english A spin-lock. */
};

/*Балансировщик нагрузки*/
/*!
\~russian
\brief Балансировщик нагрузки.

Используется для балансировки нагрузки в Ядре, а также для предварительной балансировки нагрузки в сигналах.

\warning Для внутреннего использования.

\param proc Указатель на процесс, который надо перенести на новое процессорное ядро.
\param stat Указатель на массив статистики Ядра, либо сигнала.
\return ID процессорного ядра с наименьшей нагрузкой.

\~english
\brief A load balancer routine.

This function is used for load balancing of the kernel and of signals.

\warning For internal usage.

\param proc A pointer to a process that we want to place on a process list.
\param stat A pointer to a bgrt_ls_t array, that controls corespondent process list.
\return An ID of the least loaded process list.
*/
bgrt_cpuid_t bgrt_sched_load_balancer(bgrt_proc_t * proc, bgrt_ls_t * stat);
/*!
\~russian
\brief Функция поиска процессорного Ядра с максимальной нагрузкой.

Используется в глобальном ленивом балансировщике нагрузки и функции #sig_signal.

\warning Для внутреннего использования.

\param stat Указатель на массив статистики Ядра, либо сигнала.
\return ID процессорного ядра с наибольшей нагрузкой.

\~english
\brief Find most loaded core.

 This function is used in Kernel load balancing and in #sig_signal function.

\warning For internal usage.

\param stat A pointer to a bgrt_ls_t array of the kernel or of a signal.
\return An ID of the most loaded process list.
*/
bgrt_cpuid_t bgrt_sched_highest_load_core(bgrt_ls_t * stat);
/*!
\~russian
\brief Назначить ядро процессора.

 Выбирает и устанавливает ядро, на котором будет выполняться процесс.

\warning Для внутреннего использования.

\param proc Указатель процесс

\~english
\brief Assign a core.

 This assigns a core when a process starts execution.

\warning For internal usage.

\param proc A pointer to a process.
*/
void bgrt_priv_sched_proc_set_core(bgrt_proc_t * proc);
#define BGRT_SCHED_PROC_SET_CORE(proc) bgrt_priv_sched_proc_set_core(proc)
#else  /*BGRT_CONFIG_MP*/
#define BGRT_SCHED_PROC_SET_CORE(proc) do{}while (0)
#endif /*BGRT_CONFIG_MP*/

#if defined(BGRT_CONFIG_MP) && (!defined(BGRT_CONFIG_USE_ALB))
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
\brief Ленивая балансировка нагрузки, локальный балансировщик.

Переносит 1 процесс с ядра, на котором выполняется на самое не нагруженное процессорное ядро в системе.

\~english
\brief A lazy local load balancer routine.

Transfers one process from a current CPU core to the least loaded CPU core on the system.
*/
void bgrt_sched_lazy_local_load_balancer(void);
/*!
\~russian
\brief Ленивая балансировка нагрузки, глобальный балансировщик.

Ищет самое нагруженное процессорное ядро в системе и переносит с него один процесс на самое ненагруженное ядро в системе.

\~english
\brief A lazy global load balancer routine.

Finds the most loaded CPU core on the system and transfers one process from it to the least loaded CPU core.
*/
//void bgrt_sched_lazy_global_load_balancer(void);
#endif /* BGRT_CONFIG_MP BGRT_CONFIG_USE_ALB */

BGRT_CDECL_END
#endif /*BGRT_SCHED_H*/
