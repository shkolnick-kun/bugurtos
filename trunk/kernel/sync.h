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
#ifndef _SYNC_H_
#define _SYNC_H_
/*!
\file
\brief \~russian Заголовок мьютекса. \~english A sync header.
*/

#define SYNC_ST_OK   0 /*!< \~russian Удачное завершение. \~english Success. */
#define SYNC_ST_FAIL 1 /*!< \~russian Завершение с ошибкой. \~english Fail. */
#define SYNC_ST_ROLL 2 /*!< \~russian Нужна следующая иттерация. \~english Next itteration needed. */

//          Мьютекс
typedef struct _sync_t sync_t; /*!< \~russian Смотри #_sync_t; \~english See #_sync_t; */
// Свойства
/*!
\~russian
\brief
Базовый примитив синхронизации.

Базовый тип, отвечающий за влокирующую синхронизацию процессов.
Путем "обертывания" данного типа можно получить привычные примитивы синхронизации
(мьютексы, семафоры, условные переменные, FIFO-буферы, блокироующий IPC, и т.д.).

Поддерживает протокол наследования приоритетов (Basic Priority Inheritance).

\~english
\brief
Basic synchronization primitive

A basic type that handles blocking process synchronization.
By wrapping this type one can get traditional synchronization primitives
(mutexes, semaphores, conditional variables, message-FIFOs, IPC-ednpoints, etc.).

Basic priority inheritanse protocol is supported.

*/
struct _sync_t
{
    xlist_t sleep;  /*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
    proc_t * owner;/*!< \~russian Указатель на процесс, удерживающий мьютекс. \~english A pointer to a process, that holds a sync. */
    count_t dirty; /*!< \~russian Счетчик незавершенных транзакций наследования приоритетов. \~english Dirty priority inheritanse transaction counter. */
    prio_t prio; /*!< \~russian Приоритет. \~english Priority. */
#ifdef CONFIG_MP
    lock_t lock;/*!< \~russian Спин-блокировка. \~english A sync spin-lock. */
#endif // CONFIG_MP
};
// Методы
prio_t _sync_prio( sync_t * sync );
#define SYNC_PRIO(s) _sync_prio(s) /*!< \~russian Считает приоритет щбъекта типа #sync_t. \~english Calculates a #sync_r object priority */
/*!
\~russian
\brief
Инициализация мьютекса из критической секции, или обработчика прерываний.

Да, инициировать из обработчика прерывания можно!
\~english
\brief
A sync initiation for usage in ISRs or in critical sections.
*/
void sync_init(
    sync_t * sync, /*!< \~russian Указатель на объект типа #sync_t. \~english A sync pointer. */
    prio_t prio    /*!< \~russian Приоритет. \~english A priority. */
);

#define SYNC_INIT(s,p) sync_init((sync_t *)s, (prio_t)p) /*!< \~russian Смотри #sync_init. \~english Watch #sync_init. */

/*!
\~russian
\brief
Инициализация базового примитива синхронизации.

\~english
\brief
A basic synchronization promitive initiation.
*/
void sync_init_isr(
    sync_t * sync, /*!< \~russian Указатель на базвоый примитив синхронизации. \~english A sync pointer. */
    prio_t prio    /*!< \~russian Приоритет. \~english A priority. */
);

#define SYNC_INIT_ISR(s,p) sync_init_isr((sync_t *)s, (prio_t)p) /*!< \~russian Смотри #sync_init_isr. \~english Watch #sync_init_isr. */

/*!
\~russian
\brief
Получить хозяина примитива.

\param sync Указатель на интересующий объект типа #sync_t.
\return Указатель на процесс-хозяин объекта типа #sync_t.

\~english
\brief
Get current #sync_t object owner.

\param sync A pointer to the object of interest.
\return A pointer to #sync_t opbject owner.
*/
proc_t * sync_get_owner( sync_t * sync );

#define SYNC_GET_OWNER(s) sync_get_owner((sync_t *)s) /*!< \~russian Смотри #sync_get_owner. \~english Watch #sync_get_owner. */

/*!
\~russian
\brief
Назначить хозяина объекта типа #sync_t.

\param sync Указатель на объект типа #sync_t.
\param proc Указатель на новый процесс-хозяин объекта типа #sync_t.

\~english
\brief
Set #sync_t object owner.

\param sync A pointer to the object of interest.
\param proc A pointer to new #sync_t opbject owner.
*/
void sync_set_owner( sync_t * sync, proc_t * proc );

#define SYNC_SET_OWNER(s,p) sync_set_owner((sync_t *)s, (proc_t *)p) /*!< \~russian Смотри #sync_set_owner. \~english Watch #sync_set_owner. */

/*!
\~russian
\brief
Сбросить хозяина объекта типа #sync_t.

\param sync Указатель на объект типа #sync_t.

\~english
\brief
Clear #sync_t object owner.

\param sync A pointer to the object of interest.
*/
void sync_clear_owner( sync_t * sync );

#define SYNC_CLEAR_OWNER(s) sync_clear_owner((sync_t *)s) /*!< \~russian Смотри #sync_clear_owner. \~english Watch #sync_clear_owner. */

/*!
\~russian
\brief
"Уснуть" в ожидании синхронизации #sync_t.

Блокирует вызывающий процесс.

\param sync Указатель на объект типа #sync_t.
\return #SYNC_ST_OK в случае успеха, иначе - #SYNC_ST_FAIL.

\~english
\brief
Sleep to wait for synchronization.

Blocks caller process.

\param sync A pointer to the object of interest.
\return #SYNC_ST_OK on success, or #SYNC_ST_FAIL.
*/
flag_t sync_sleep( sync_t * sync );

typedef struct
{
    sync_t * sync;
    flag_t status;
}
sync_sleep_t; /*!< \~russian Для внутреннего пользования. \~english For internal usage. */

#define SYNC_SLEEP(s) sync_sleep((sync_t *)s) /*!< \~russian Смотри #sync_sleep. \~english Watch #sync_sleep. */

/*!
\~russian
\brief
"Разбудить" ожидающий процесс.

Запускает ожидающий процесс. Может запустить "голову" списка ожидающих процессов,
или какой-то конкретный прооцесс, в случае, если он заблокирован на целевом примитиве синхронизации.

\param sync Указатель на объект типа #sync_t.
\param proc Указатель на процес, который надо запустить, если 0, то пытается запустить "голову" списка ожидающих.
\param chown Флаг смены хозяина, если не 0, то запускаемый процесс станет новым хозяином примитива синхронизации.
\return #SYNC_ST_OK в случае если удалось запустить процесс, иначе - #SYNC_ST_FAIL.

\~english
\brief
Sleep to wait for synchronization.

Unblock some waiting process. A process should be blocked on target #sync_t object.

\param sync A #sync_t object pointer.
\param proc A pointer to a process, that is supposed to wake up. If 0, then try to wake up wait list head.
\param chown A change owner flag. If non 0, then ownership is given to wake up process.
\return #SYNC_ST_OK on process wakeup, or #SYNC_ST_FAIL.
*/
flag_t sync_wake( sync_t * sync, proc_t * proc, flag_t chown );

typedef struct
{
    sync_t * sync;
    proc_t * proc;
    flag_t chown;
    flag_t status;
}
sync_wake_t; /*!< \~russian Для внутреннего пользования. \~english For internal usage. */

#define SYNC_WAKE(s,p,c,st) \
do                                                              \
{                                                               \
    volatile sync_wake_t scarg;                                 \
    scarg.status = SYNC_ST_ROLL;                                \
    scarg.sync = (sync_t *)(s);                                 \
    scarg.proc = (proc_t *)(p);                                 \
    scarg.chown = (flag_t)(c);                                  \
    do                                                          \
    {                                                           \
        syscall_bugurt( SYSCALL_SYNC_WAKE, (void *)&scarg );    \
    }                                                           \
    while( scarg.status >= SYNC_ST_ROLL );                      \
    (st) = scarg.status;                                        \
}                                                               \
while(0) /*!< \~russian Смотри #sync_wake. \~english Watch #sync_wake. */

/*!
\~russian
\brief
"Ожидать", блокировки процесса.

Подождать того момента, как целевой процесс будет заблокирован на целевом примимтиве синхронизации.

\param sync Указатель на объект типа #sync_t.
\param proc Двойной указатель на процес, который надо подождать, если *proc==0, то вызывающий процесс будет ждать первой блокировки процесса на объекте типа #sync_t.
\param block Флаг блокировки вызывающего процесса, если не 0 и нужно ждать, вызывающий процесс будет заблокирован.
\return #SYNC_ST_OK в случае если дождался блокировки целевого процесса, #SYNC_ST_ROLL, если нужна следующая иттерация, иначе - #SYNC_ST_FAIL.

\~english
\brief
Sleep to wait for synchronization.

Wait until target process is blocked on target #sync_t object.

\param sync A #sync_t object pointer.
\param proc A double pointer to a process, that is supposed to block. If *proc is zero, then caller may wait for first process to block on #sync_t object.
\param block Block flag. If non 0 and caller process must wait, then caller is blocked until terget process is blocked on #sync_t object.
\return #SYNC_ST_OK if target process has blocked on target #sync_t object, #SYNC_ST_ROLL if caller must wait for target procerr to block, or #SYNC_ST_FAIL.
*/
flag_t sync_wait( sync_t * sync, proc_t ** proc, flag_t block );

typedef struct
{
    sync_t * sync;
    proc_t ** proc;
    flag_t block;
    flag_t status;
}
sync_wait_t; /*!< \~russian Для внутреннего пользования. \~english For internal usage. */

#define SYNC_WAIT(s,p,b,st)                                     \
do                                                              \
{                                                               \
    volatile sync_wait_t scarg;                                 \
    scarg.status = SYNC_ST_ROLL;                                \
    scarg.sync = (sync_t *)(s);                                 \
    scarg.proc = (proc_t **)(p);                                \
    scarg.block = (flag_t)(b);                                  \
    do                                                          \
    {                                                           \
        syscall_bugurt( SYSCALL_SYNC_WAIT, (void *)&scarg );    \
    }                                                           \
    while( scarg.status >= SYNC_ST_ROLL );                      \
    (st) = scarg.status;                                        \
}                                                               \
while(0) /*!< \~russian Смотри #sync_wait. \~english Watch #sync_wait. */

/*!
\~russian
\brief
Смотри #sync_wake и #sync_sleep.

Смотри #sync_wake и #sync_sleep.

\~english
\brief
Watch #sync_wake and #sync_sleep.

Watch #sync_wake and #sync_sleep.
*/
flag_t sync_wake_and_sleep( sync_t * wake, proc_t * proc, flag_t chown, sync_t * sleep );

typedef struct
{
    sync_sleep_t sleep;
    sync_t * wake;
    proc_t * proc;
    flag_t chown;
    flag_t stage;
}
sync_wake_and_sleep_t; /*!< \~russian Для внутреннего пользования. \~english For internal usage. */

#define SYNC_WAKE_AND_SLEEP(w,p,c,s,st)                                 \
do                                                                      \
{                                                                       \
    volatile sync_wake_and_sleep_t scarg;                               \
    scarg.sleep.sync = (sync_t *)(s);                                   \
    scarg.sleep.status = SYNC_ST_ROLL;                                  \
    scarg.chown = (flag_t)(c);                                          \
    scarg.wake = (sync_t *)(w);                                         \
    scarg.proc = (proc_t *)(p);                                         \
    scarg.stage = (flag_t)0;                                            \
    do                                                                  \
    {                                                                   \
        syscall_bugurt( SYSCALL_SYNC_WAKE_AND_SLEEP, (void *)&scarg );  \
    }                                                                   \
    while( scarg.sleep.status >= SYNC_ST_ROLL );                        \
    (st) = scarg.sleep.status;                                          \
}                                                                       \
while(0) /*!< \~russian Смотри #sync_wake_and_sleep. \~english Watch #sync_wake_and_sleep. */


/*!
\~russian
\brief
Смотри #sync_wake и #sync_wait.

Смотри #sync_wake и #sync_wait.

\~english
\brief
Watch #sync_wake and #sync_wait.

Watch #sync_wake and #sync_wait.
*/
flag_t sync_wake_and_wait( sync_t * wake, proc_t * proc_wake, flag_t chown, sync_t * wait, proc_t ** proc_wait, flag_t block );

typedef struct
{
    sync_wait_t wait;
    sync_t * wake;
    proc_t * proc;
    flag_t chown;
    flag_t stage;
}
sync_wake_and_wait_t; /*!< \~russian Для внутреннего пользования. \~english For internal usage. */

#define SYNC_WAKE_AND_WAIT(wk,pwk,c,wt,pwt,b,st)                        \
do                                                                      \
{                                                                       \
    volatile sync_wake_and_wait_t scarg;                                \
    scarg.wait.sync   = (sync_t *)(wt);                                 \
    scarg.wait.proc   = (proc_t **)(pwt);                               \
    scarg.wait.block  = (flag_t)(b);                                    \
    scarg.wait.status = SYNC_ST_ROLL;                                   \
    scarg.wake      = (sync_t *)(wk);                                   \
    scarg.proc      = (proc_t *)(pwk);                                  \
    scarg.chown     = (flag_t)(c);                                      \
    scarg.stage     = (flag_t)0;                                        \
    do                                                                  \
    {                                                                   \
        syscall_bugurt( SYSCALL_SYNC_WAKE_AND_WAIT, (void *)&scarg );   \
    }                                                                   \
    while( scarg.wait.status >= SYSCALL_SYNC_WAKE_AND_WAIT );           \
    (st) = scarg.wait.status;                                           \
}                                                                       \
while(0) /*!< \~russian Смотри #sync_wake_and_wait. \~english Watch #sync_wake_and_wait. */

/*!
\~russian
\brief
Для внутреннего использования. Смотри #sync_set_owner.

Для внутреннего использования. Смотри #sync_set_owner.

\~english
\brief
For internal usage. Watch #sync_set_owner.

For internal usage. Watch #sync_set_owner.
*/
void _sync_set_owner( sync_t * sync, proc_t * proc );
/*!
\~russian
\brief
Для внутреннего использования. Смотри #sync_clear_owner.

Для внутреннего использования. Смотри #sync_clear_owner.

\~english
\brief
For internal usage. Watch #sync_clear_owner.

For internal usage. Watch #sync_clear_owner.
*/
void _sync_clear_owner( sync_t * sync );
/*!
\~russian
\brief
Для внутреннего использования. Смотри #sync_wake.

Для внутреннего использования. Смотри #sync_wake.

\~english
\brief
For internal usage. Watch #sync_wake.

For internal usage. Watch #sync_wake.
*/
flag_t _sync_wake( sync_t * sync, proc_t * proc, flag_t chown, code_t hook, void * arg );
/*!
\~russian
\brief
Для внутреннего использования. Смотри #sync_sleep.

Для внутреннего использования. Смотри #sync_sleep.

\~english
\brief
For internal usage. Watch #sync_sleep.

For internal usage. Watch #sync_sleep.
*/
flag_t _sync_sleep( sync_t * sync );
/*!
\~russian
\brief
Для внутреннего использования. Смотри #sync_wait.

Для внутреннего использования. Смотри #sync_wait.

\~english
\brief
For internal usage. Watch #sync_wait.

For internal usage. Watch #sync_wait.
*/
flag_t _sync_wait( sync_t * sync, proc_t ** proc, flag_t block );
#endif // _SYNC_H_
