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

/* ADLINT:SF:[W0073,W0553] No include guard!,func pointers */

BGRT_SC_TBL_ENTRY(PROC_RUN           , void*       )/* \~russian \brief Запуск процесса.                                              \~english \brief A process launch.                                 */
BGRT_SC_TBL_ENTRY(PROC_RESTART       , void*       )/* \~russian \brief Перезапуск процесса.                                          \~english \brief A Process restart.                                */
BGRT_SC_TBL_ENTRY(PROC_STOP          , void*       )/* \~russian \brief Останов процесса.                                             \~english \brief A process stop.                                   */
BGRT_SC_TBL_ENTRY(PROC_SELF_STOP     , void*       )/* \~russian \brief Самоостанов процесса.                                         \~english \brief A process self stop.                              */
BGRT_SC_TBL_ENTRY(PROC_TERMINATE     , void*       )/* \~russian \brief Завершение работы процесса.                                   \~english \brief A process termination.                            */
BGRT_SC_TBL_ENTRY(PROC_LOCK          , void*       )/* \~russian \brief Установить флаг #BGRT_PROC_FLG_LOCK для вызывающего процесса. \~english \brief #BGRT_PROC_FLG_LOCK for caller process.           */
BGRT_SC_TBL_ENTRY(PROC_FREE          , void*       )/* \~russian \brief Останов процесса по флагу #BGRT_PROC_FLG_PRE_STOP.            \~english \brief #BGRT_PROC_FLG_PRE_STOP flag processing.          */
BGRT_SC_TBL_ENTRY(PROC_RESET_WATCHDOG, void*       )/* \~russian \brief Сброс watchdog процесса реального времени.                    \~english \brief A real time process watchdog reset.               */
BGRT_SC_TBL_ENTRY(PROC_SET_PRIO      , bgrt_va_wr_t*)/* \~russian \brief Установить приоритет процесса                                 \~english \brief Set a process priority.                           */
BGRT_SC_TBL_ENTRY(PROC_GET_PRIO      , bgrt_va_wr_t*)/* \~russian \brief Получить приоритет процесса                                   \~english \brief Get a process priority.                           */
BGRT_SC_TBL_ENTRY(PROC_GET_ID        , void*       )/*\~russian \brief Установить приоритет процесса                                 \~english \brief Set a process priority.                           */

BGRT_SC_TBL_ENTRY(SCHED_PROC_YIELD   , void*       )/* \~russian \brief Передача управления другому процессу.                         \~english \brief Transfer control to another process.              */

BGRT_SC_TBL_ENTRY(SYNC_SET_OWNER     , bgrt_va_wr_t*)/* \~russian \brief Установить нового хозяина объекта типа #bgrt_sync_t.          \~english \brief Set new #bgrt_sync_t object owner.                */
BGRT_SC_TBL_ENTRY(SYNC_GET_OWNER     , bgrt_va_wr_t*)/* \~russian \brief Узнать принадлежность объекта типа #bgrt_sync_t.              \~english \brief Get #bgrt_sync_t object owner.                    */
BGRT_SC_TBL_ENTRY(SYNC_OWN           , bgrt_va_wr_t*)/* \~russian \brief Завладеть объектом типа #bgrt_sync_t.                         \~english \brief Own #bgrt_sync_t object.                          */
BGRT_SC_TBL_ENTRY(SYNC_TOUCH         , void*       )/* \~russian \brief Заблокировать пробуждение процессов.                          \~english \brief Block process wake.                               */
BGRT_SC_TBL_ENTRY(SYNC_SLEEP         , bgrt_va_wr_t*)/* \~russian \brief Заблокировать процесс в ожидании синхронизации.               \~english \brief Block process for synchronization.                */
BGRT_SC_TBL_ENTRY(SYNC_WAKE          , bgrt_va_wr_t*)/* \~russian \brief Запустить процесс, ожидающий синхронизации.                   \~english \brief Run a process waiting for synchronization.        */
BGRT_SC_TBL_ENTRY(SYNC_WAIT          , bgrt_va_wr_t*)/* \~russian \brief Подождать блокировки процесса на объекте типа #bgrt_sync_t.   \~english \brief Wait for process to block on #bgrt_sync_t object. */
BGRT_SC_TBL_ENTRY(SYNC_PROC_TIMEOUT  , void*       )/* \~russian \brief Разбудить процесс по таймауту.                                \~english \brief Wake a process on timeout.                        */

BGRT_SC_TBL_ENTRY(USER               , bgrt_va_wr_t*)/* \~russian \brief Пользовательский системный вызов.                             \~english \brief User system call.                                 */
