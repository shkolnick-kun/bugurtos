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
#ifndef SEM_H
#define SEM_H
/*!
\file
\brief \~russian Заголовок счётных семафоров. \~english A counting semaphores header.
*/
#include <bugurt.h>
BGRT_CDECL_BEGIN
/*Семафор*/
typedef struct bgrt_priv_sem_t bgrt_sem_t;/*!< \~russian Смотри #bgrt_priv_sem_t; \~english See #bgrt_priv_sem_t; */
/*Свойства*/
/*!
\~russian
\brief
Счётный семафор.

Счётные семафоры используются для синхронизации процессов. Не рекомендуется их использовать для организации доступа к общим ресурсам, т.к. здесь нет управления приоритетами.
Счётный семафор может быть захвачен 1 процессом, а освобождён другим.

\~english
\brief
A counting semaphore.

Counting semaphores are used for process synchronization.
It is not recommended to use them in common data access control, because priority inversion is possible.
A counting semaphore can be locked by one process and freed by another.
*/
struct bgrt_priv_sem_t
{
    bgrt_sync_t wait;/*!< \~russian Список ожидающих процессов. \~english A list of waiting processes. */
    bgrt_cnt_t counter;/*!< \~russian Счётчик ресурсов. \~english A resource counter. */
#ifdef BGRT_CONFIG_MP
    bgrt_lock_t lock;/*!< \~russian Спин-блокировка. \~english A sync spin-lock. */
#endif /* BGRT_CONFIG_MP */
};
/*Методы*/
/*Инициализация*/
/*!
\~russian
\brief
Инициализация семафора из обработчика прерывания или критической секции.

\param sem Указатель на семафор.
\param count Начальное значение счётчика.

\~english
\brief
Semaphore initiation from ISR.

\param sem A #bgrt_sem_t pointer.
\param count A counter start value.
*/
bgrt_st_t bgrt_sem_init_cs(bgrt_sem_t * sem, bgrt_cnt_t count);
/*!
\~russian
\brief
Инициализация семафора.

\param sem Указатель на семафор.
\param count Начальное значение счётчика.

\~english
\brief
Semaphore initiation.

\param sem A #bgrt_sem_t pointer.
\param count A counter start value.
*/
bgrt_st_t bgrt_sem_init(bgrt_sem_t * sem, bgrt_cnt_t count);
/*!
\~russian
\brief
Захват семафора.

Если значение счётчика семафора больше 0, то процесс уменьшает счётчик семафора на 1 и продолжает выполняться.
Если значение счётчика семафора равно 0, процесс останавливается и встаёт в список ожидающих освобождения семафора.

\param sem Указатель на семафор.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
A semaphore lock.

If semaphore counter greater than zero, then it will be decreased and caller process will continue,
else  caller process will stop and wait until semaphore get free.

\param sem A #bgrt_sem_t pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_sem_lock(bgrt_sem_t * sem);
/*!
\~russian
\brief
Попытка захвата семафора.

Если значение счётчика семафора больше 0, то процесс уменьшает счётчик семафора на 1 и продолжает выполняться.
Если значение счётчика семафора равно 0, процесс просто продолжает выполняться.

\param sem Указатель на семафор.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Try to lock a semaphore.

If semaphore counter greater than zero, then it will be decreased and caller process will continue,
else caller process will just continue.

\param sem A #bgrt_sem_t pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_sem_try_lock(bgrt_sem_t * sem);
/*!
\~russian
\brief
Освобождение семафора.

Если список ожидающих захвата семафора пуст, то счётчик семафора увеличиваем на 1.
Если не пуст - возобновляем работу головы списка.

\param sem Указатель на семафор.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Semaphore free.

If semaphore wait list is empty, then counter will be increased,
else semaphore wait list head will be launched.

\param sem A #bgrt_sem_t pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_sem_free(bgrt_sem_t * sem);

/*!
\~russian
\brief
Освобождение семафора из обработчика прерывания.

\warning У семафора не должно быть хозяина!!!

Если список ожидающих захвата семафора пуст, то счётчик семафора увеличиваем на 1.
Если не пуст - возобновляем работу головы списка.

\param sem Указатель на семафор.
\return #BGRT_ST_OK в случае успеха, или номер ошибки.

\~english
\brief
Semaphore free. For ISR usage.

\warning A semaphore must not have an owner

If semaphore wait list is empty, then counter will be increased,
else semaphore wait list head will be launched.

\param sem A #bgrt_sem_t pointer.
\return #BGRT_ST_OK on success, or error number.
*/
bgrt_st_t bgrt_sem_free_cs(bgrt_sem_t * sem);

BGRT_CDECL_END
#endif /*SEM_H*/
