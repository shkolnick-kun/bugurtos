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
#ifndef SYSCALL_H
#define SYSCALL_H
BGRT_CDECL_BEGIN
#include <stdarg.h>
/*!
\file
\brief \~russian Заголовок системных вызовов.

\warning Все содержимое файла для внутреннего использования!

\~english System call header.

\warning This file content is internal usage!
*/
#define BGRT_SC_ID(syscall) BGRT_CONCAT(BGRT_SC_ENUM_, syscall) /*!< \~russian \brief Получить идентификатор системного вызова по названию. \~english \brief Get system call id. */

typedef enum _bgrt_sc_enum bgrt_sc_enum; /*!< \~russian \brief Идентификаторы системных вызовов. \~english \brief Suystem call IDs. */
enum _bgrt_sc_enum
{
#   define BGRT_SC_TBL_ENTRY(syscall,arg) BGRT_SC_ID(syscall),
#   include <syscall_table.h> /* ADLINT:SF:[W0073] No include guard! */
#   undef  BGRT_SC_TBL_ENTRY
    BGRT_SC_ENUM_END
};


#define BGRT_SC_SR_NAME(syscall) BGRT_CONCAT2(BGRT_SC_, BGRT_CONCAT(syscall, _SR)) /*!< \~russian \brief Имя обработчика системного вызова.         \~english \brief System call service routine name. */
#define BGRT_SC_SR(syscall,arg) bgrt_st_t BGRT_SC_SR_NAME(syscall)(arg)    /*!< \~russian \brief Обработчик системного вызова.              \~english \brief System call service routine. */
typedef bgrt_st_t (* bgrt_scsr_t)(void *);                                         /*!< \~russian \brief Указатель на обработчик системного вызова. \~english \brief System call service routine pointer. */

typedef struct _bgrt_va_wr_t bgrt_va_wr_t; /*!< \~russian \brief Обёртка для va_list. \~english \brief va_list wrapper. */
struct _bgrt_va_wr_t
{
    va_list list;
};
/*!
\~russian
\brief
Обработка системного вызова.

Запускает обработчик системного вызова и передаёт ему аргумент.

\param syscall_num Номер системного вызова.
\param syscall_arg Аргумент системного вызова.
\return Результат выполнения системного вызова.

\~english
\brief
System call processing routine.

This function calls system call handlers and passes arguments to them.

\param syscall_num System call number.
\param syscall_arg System call argument.
\return System call execution status.
*/
bgrt_st_t bgrt_priv_do_syscall(bgrt_syscall_t syscall_num, void * syscall_arg);

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
\~english
\brief
A system call.

This function switches a processor core from a process context to the kernel context.
The kernel code is always run in the kernel context. This is done to save memory in process stacks.
A system calls are done on every operations with processes, mutexes, semaphores and signals.
The Kernel does all of this job.

\warning Internal usage function.

\param num a number of a system call (what is going to be done).
*/
bgrt_st_t bgrt_syscall_var(bgrt_syscall_t num, ...);

/*!
\~russian
\brief
Системный вызов в виде макроса, см. #bgrt_syscall.

\warning Для внутреннего использования.

\param sc_name имя системного вызова (что именно надо выполнить).
\param arg Указатель на аргумент.
\~english
\brief
A system call macro, see #bgrt_syscall.

\warning For internal usage.

\param sc_name A system call name.
\param arg A system call argument pointer.
*/
#define BGRT_SYSCALL_N(sc_name, arg) bgrt_syscall(BGRT_SC_ID(sc_name), arg)

/*!
\~russian
\brief
Системный вызов в виде макроса, см. #bgrt_syscall_var.

\warning Для внутреннего использования.

\param sc_name имя системного вызова (что именно надо выполнить).
\~english
\brief
A system call macro, see #bgrt_syscall_var.

\warning For internal usage.

\param sc_name A system call name.
*/
#define BGRT_SYSCALL_NVAR(sc_name,...) bgrt_syscall_var(BGRT_SC_ID(sc_name), __VA_ARGS__)

/*User may write his own system calls*/
#ifdef BGRT_CONFIG_CUSTOM_SYSCALL
#   include <custom_syscall_api.h>
#else
#   include <default/syscall_api.h> /*Default system call dispatcher*/
#endif/*BGRT_CONFIG_USER_SYSCALL*/

BGRT_CDECL_END
#endif /*SYSCALL_H*/
