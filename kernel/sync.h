/**************************************************************************
    BuguRTOS-0.8.x (Bugurt real time operating system)
    Copyright (C) 2015 anonimous

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
#ifndef _BGRT_SYNC_H_
#define _BGRT_SYNC_H_
/*!
\file
\brief \~russian Заголовок базового примитива синхронизации. \~english A sync header.
*/

typedef struct _bgrt_sync_t bgrt_sync_t; /*!< \~russian Смотри #_bgrt_sync_t; \~english See #_bgrt_sync_t; */
// Свойства
/*!
\~russian
\brief
Базовый примитив синхронизации.

Базовый тип, отвечающий за блокирующую синхронизацию процессов.
Путем "обертывания" данного типа можно получить привычные примитивы синхронизации
(мьютексы, семафоры, условные переменные, FIFO-буферы, блокирующий IPC, и т.д.).

Поддерживает протокол наследования приоритетов (Basic Priority Inheritance).

\~english
\brief
Basic synchronization primitive

A basic type that handles blocking process synchronization.
By wrapping this type one can get traditional synchronization primitives
(mutexes, semaphores, conditional variables, message-FIFOs, IPC-endpoints, etc.).

Basic priority inheritance protocol is supported.

*/
struct _bgrt_sync_t
{
    bgrt_xlist_t sleep;  /*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
    bgrt_proc_t * owner;/*!< \~russian Указатель на процесc-хозяин. \~english A pointer to a process, that holds a sync. */
    bgrt_cnt_t dirty; /*!< \~russian Счетчик незавершенных транзакций наследования приоритетов. \~english Dirty priority inheritance transaction counter. */
    bgrt_cnt_t snum; /*!< \~russian Счетчик спящих процессов. \~english Sleeping process counter. */
    bgrt_cnt_t pwake; /*!< \~russian Счетчик отложенных пробуждений. \~english Pending wakeup counter. */
    bgrt_prio_t prio; /*!< \~russian Приоритет. \~english Priority. */
#ifdef BGRT_CONFIG_MP
    bgrt_lock_t lock;/*!< \~russian Спин-блокировка. \~english A sync spin-lock. */
#endif // BGRT_CONFIG_MP
};
// Методы
/*!
\~russian
\brief
Возвращает текущий приоритет объекта типа #bgrt_sync_t.
\warning Для внутреннего использования.

\~english
\brief
Returns current #bgrt_sync_t object priority.
\warning For internal usage.
*/
bgrt_prio_t _bgrt_sync_prio( bgrt_sync_t * sync );
#define BGRT_SYNC_PRIO(s) _bgrt_sync_prio(s) /*!< \~russian \brief Считает приоритет щбъекта типа #bgrt_sync_t. \~english \brief Calculates a #bgrt_sync_t object priority */
/*!
\~russian
\brief
Инициализация базового примитива синхронизации.

\~english
\brief
A basic synchronization primitive initiation.
*/
bgrt_st_t bgrt_sync_init(
    bgrt_sync_t * sync, /*!< \~russian Указатель на объект типа #bgrt_sync_t. \~english A sync pointer. */
    bgrt_prio_t prio    /*!< \~russian Приоритет. \~english A priority. */
);
/*!
\~russian
\brief
Инициализация из критической секции, или обработчика прерываний.

Да, инициировать из обработчика прерывания можно!
\~english
\brief
A sync initiation for usage in ISRs or in critical sections.
*/
bgrt_st_t _bgrt_sync_init(
    bgrt_sync_t * sync, /*!< \~russian Указатель на базовый примитив синхронизации. \~english A sync pointer. */
    bgrt_prio_t prio    /*!< \~russian Приоритет. \~english A priority. */
);
/*!
\~russian
\brief
Получить хозяина примитива.

\param sync Указатель на интересующий объект типа #bgrt_sync_t.
\return Указатель на процесс-хозяин объекта типа #bgrt_sync_t.

\~english
\brief
Get current #bgrt_sync_t object owner.

\param sync A pointer to the object of interest.
\return A pointer to #bgrt_sync_t object owner.
*/
BGRT_PID_T bgrt_sync_get_owner( bgrt_sync_t * sync );
/*!
\~russian
\brief
Назначить хозяина объекта типа #bgrt_sync_t.

\param sync Указатель на объект типа #bgrt_sync_t.
\param proc Указатель на новый процесс-хозяин объекта типа #bgrt_sync_t.
\return #BGRT_ST_OK в случае успеха, либо код ошибки.

\~english
\brief
Set #bgrt_sync_t object owner.

\param sync A pointer to the object of interest.
\param proc A pointer to new #bgrt_sync_t object owner.
\return #BGRT_ST_OK on sucess, or error code.
*/
bgrt_st_t bgrt_sync_set_owner( bgrt_sync_t * sync, BGRT_PID_T pid );
/*!
\~russian
\brief
Завладеть объектом типа #bgrt_sync_t.

\param sync Указатель на объект типа #bgrt_sync_t.
\return #BGRT_ST_OK в случае успеха, либо код ошибки.

\~english
\brief
Own #bgrt_sync_t object.

\param sync A pointer to the object of interest.
\return #BGRT_ST_OK if on success, or error code.
*/
bgrt_st_t bgrt_sync_own( bgrt_sync_t * sync, bgrt_flag_t touch );
/*!
\~russian
\brief
Пометить объект #bgrt_sync_t, как грязный.

\param sync Указатель на объект типа #bgrt_sync_t.
\return #BGRT_ST_OK в случае успеха, либо код ошибки.

\~english
\brief
Touch #bgrt_sync_t object.

\param sync A pointer to the object of interest.
\return #BGRT_ST_OK if on success, or error code.
*/
bgrt_st_t bgrt_sync_touch( bgrt_sync_t * sync );
/*!
\~russian
\brief
"Уснуть" в ожидании синхронизации #bgrt_sync_t.

Блокирует вызывающий процесс.

\param sync Указатель на объект типа #bgrt_sync_t.
\return #BGRT_ST_OK в случае успеха, иначе - код ошибки.

\~english
\brief
Sleep to wait for synchronization.

Blocks caller process.

\param sync A pointer to the object of interest.
\param touch A touch flag, must be 1 if we've touched a sync before call.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_sync_sleep( bgrt_sync_t * sync, bgrt_flag_t touch );
/*!
\~russian
\brief
"Ожидать", блокировки процесса.

Подождать того момента, как целевой процесс будет заблокирован на целевом примитиве синхронизации.

\param sync Указатель на объект типа #bgrt_sync_t.
\param proc Двойной указатель на процесс, который надо подождать, если *proc==0, то вызывающий процесс будет ждать первой блокировки процесса на объекте типа #bgrt_sync_t.
\param block Флаг блокировки вызывающего процесса, если не 0 и нужно ждать, вызывающий процесс будет заблокирован.
\return #BGRT_ST_OK в случае если дождался блокировки целевого процесса, #BGRT_ST_ROLL, если нужна следующая итерация, иначе - код ошибки.

\~english
\brief
Sleep to wait for synchronization.

Wait until target process is blocked on target #bgrt_sync_t object.

\param sync A #bgrt_sync_t object pointer.
\param pid A double pointer to a process, that is supposed to block. If *pid is zero, then caller may wait for first process to block on #bgrt_sync_t object.
\param block Block flag. If non 0 and caller process must wait, then caller is blocked until target process is blocked on #bgrt_sync_t object.
\return #BGRT_ST_OK if target process has blocked on target #bgrt_sync_t object, #BGRT_ST_ROLL if caller must wait for target process to block, or error code.
*/
bgrt_st_t bgrt_sync_wait( bgrt_sync_t * sync, BGRT_PID_T * pid, bgrt_flag_t block );
/*!
\~russian
\brief
"Разбудить" ожидающий процесс.

Запускает ожидающий процесс. Может запустить "голову" списка ожидающих процессов,
или какой-то конкретный процесс, в случае, если он заблокирован на целевом примитиве синхронизации.

\param sync Указатель на объект типа #bgrt_sync_t.
\param pid Указатель на процесс, который надо запустить, если 0, то пытается запустить "голову" списка ожидающих.
\param chown Флаг смены хозяина, если не 0, то запускаемый процесс станет новым хозяином примитива синхронизации.
\return #BGRT_ST_OK в случае если удалось запустить процесс, иначе - код ошибки.

\~english
\brief
Sleep to wait for synchronization.

Unblock some waiting process. A process should be blocked on target #bgrt_sync_t object.

\param sync A #bgrt_sync_t object pointer.
\param pid A pointer to a process, that is supposed to wake up. If 0, then try to wake up wait list head.
\param chown A change owner flag. If non 0, then ownership is given to wake up process.
\return #BGRT_ST_OK on process wakeup, or error code.
*/
bgrt_st_t bgrt_sync_wake( bgrt_sync_t * sync, BGRT_PID_T pid, bgrt_flag_t chown );
/*!
\~russian
\brief
"Разбудить", процесс по таймауту.

\param pid Указатель на процесс, который надо подождать, если *pid==0, то вызывающий процесс будет ждать первой блокировки процесса на объекте типа #bgrt_sync_t.
\return #BGRT_ST_OK в случае, если дождался разбудил целевой процесс, #BGRT_ST_ROLL, если нужна следующая итерация, иначе - код ошибки.

\~english
\brief
Wake a process on timeout.

\param pid A pointer to a process, that is supposed to wake up.
\return #BGRT_ST_OK if target process has been woken up, #BGRT_ST_ROLL if caller must do next iteration, or error code.
*/
bgrt_st_t bgrt_sync_proc_timeout( BGRT_PID_T pid );

/*!
\~russian
\brief
Смотри #bgrt_sync_set_owner.

\warning Для внутреннего использования.
\~english
\brief
Watch #bgrt_sync_set_owner.

\warning For internal usage.
*/
bgrt_st_t _bgrt_sync_set_owner( bgrt_sync_t * sync, bgrt_proc_t * proc );
/*!
\~russian
\brief
Смотри #bgrt_sync_get_owner.

\warning Для внутреннего использования.
\~english
\brief
Watch #bgrt_sync_get_owner.

\warning For internal usage.
*/
bgrt_proc_t * _bgrt_sync_get_owner( bgrt_sync_t * sync );
/*!
\~russian
\brief
Смотри #bgrt_sync_own.

\warning Для внутреннего использования.

\~english
\brief
Watch #bgrt_sync_own.

\warning For internal usage.
*/
bgrt_st_t _bgrt_sync_own( bgrt_sync_t * sync, bgrt_flag_t touch );
/*!
\~russian
\brief
Смотри #bgrt_sync_touch.

\warning Для внутреннего использования.

\~english
\brief
Watch #bgrt_sync_touch.

\warning For internal usage.
*/
bgrt_st_t _bgrt_sync_touch( bgrt_sync_t * sync );
/*!
\~russian
\brief
Смотри #bgrt_sync_wake.

\warning Для внутреннего использования.

\~english
\brief
Watch #bgrt_sync_wake.

\warning For internal usage.
*/
bgrt_st_t _bgrt_sync_wake( bgrt_sync_t * sync, bgrt_proc_t * proc, bgrt_flag_t chown );
/*!
\~russian
\brief
Смотри #bgrt_sync_sleep.

\warning Для внутреннего использования.

\~english
\brief
Watch #bgrt_sync_sleep.

\warning For internal usage.
*/
bgrt_st_t _bgrt_sync_sleep( bgrt_sync_t * sync, bgrt_flag_t * touch );
/*!
\~russian
\brief
Смотри #bgrt_sync_wait.

\warning Для внутреннего использования.
\~english
\brief
Watch #bgrt_sync_wait.

\warning For internal usage.
*/
bgrt_st_t _bgrt_sync_wait( bgrt_sync_t * sync, bgrt_proc_t ** proc, bgrt_flag_t block );
/*!
\~russian
\brief
Смотри #bgrt_sync_proc_timeout.

\warning Для внутреннего использования.
\~english
\brief
Watch #bgrt_sync_proc_timeout.

\warning For internal usage.
*/
bgrt_st_t _bgrt_sync_proc_timeout( bgrt_proc_t * proc );
#endif // _BGRT_SYNC_H_
