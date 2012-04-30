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
#ifndef _SEM_H_
#define _SEM_H_

//Семафор
/*!
\file
\brief Заголовок счетных семафоров.
*/
typedef struct _sem_t sem_t;
// Свойства
/*!
\brief Счетный семафор.

Счетные семафоры используются для синхронизации процессов. Не рекомендуется их использовать для организации доступа к общим ресурсам, т.к. здесь нет управления приоритетами, да и флаг #PROC_FLG_HOLD не выставляется.
Счетный семафор может быть захвачен 1 процессом, а освобожден другим.
*/
struct _sem_t
{
    xlist_t parent; /*!< Потомок списка, да. */
    count_t counter; /*!< Счетчик семафора. */
#ifdef CONFIG_MP
    lock_t lock; /*!< На многопроцессорной системе семафор защищен спин-блокировкой. */
#endif //CONFIG_MP
};
// Методы
// Инициализация
/*!
\brief Инициализация семафора из обработчика прерывания или критической секции.

\param sem Указатель на семафор.
\param count Начальное значение счетчика.
*/
void sem_init_isr( sem_t * sem, count_t count );
/*!
\brief Инициализация семафора.

\param sem Указатель на семафор.
\param count Начальное значение счетчика.
*/
void sem_init( sem_t * sem, count_t count );
// Захват/освобождение
/*!
\brief Захват семафора.

Если значение счетчика семафора больше 0, то процесс уменьшает счетчик семафора на 1 и продолжает выполняться.
Если значение счетчика семафора равно 0, процесс останавливается и встает в список ожидающих освобождения семафора.

\param sem Указатель на семафор.
\return 1 если удалось захватить семафор без ожидания, 0 если не удалось.
*/
bool_t sem_lock( sem_t * sem );
/*!
\brief Попытка захвата семафора.

Если значение счетчика семафора больше 0, то процесс уменьшает счетчик семафора на 1 и продолжает выполняться.
Если значение счетчика семафора равно 0, процесс просто продолжает выполняться.

\param sem Указатель на семафор.
\return 1 если удалось захватить семафор без ожидания, 0 если не удалось.
*/
bool_t sem_try_lock( sem_t * sem );
/*!
\brief Освобождение семафора.

Если список ожидающих захвата семафора пуст, то счетчик семафора увеличиваем на 1.
Если не пуст - возобновляем работу головы списка.

\param sem Указатель на семафор.
*/
void sem_unlock( sem_t * sem );

/*!
\brief Освобождение семафора.

Для использования в критических секциях и обработчиках прерываний.

Если список ожидающих захвата семафора пуст, то счетчик семафора увеличиваем на 1.
Если не пуст - возобновляем работу головы списка.

\param sem Указатель на семафор.
*/
void sem_unlock_isr( sem_t * sem );
// То же, для внутреннего использования
// Захват/освобождение
/*!
\brief Захват семафора, для внутреннего использования.

Если значение счетчика семафора больше 0, то процесс уменьшает счетчик семафора на 1 и продолжает выполняться.
Если значение счетчика семафора равно 0, процесс останавливается и встает в список ожидающих освобождения семафора.

\param sem Указатель на семафор.
\return 1 если удалось захватить семафор без ожидания, 0 если не удалось.
*/
bool_t _sem_lock( sem_t * sem );
/*!
\brief Попытка захвата семафора, для внутреннего использования.

Если значение счетчика семафора больше 0, то процесс уменьшает счетчик семафора на 1 и продолжает выполняться.
Если значение счетчика семафора равно 0, процесс просто продолжает выполняться.

\param sem Указатель на семафор.
\return 1 если удалось захватить семафор без ожидания, 0 если не удалось.
*/
bool_t _sem_try_lock( sem_t * sem );

#endif // _SEM_H_
