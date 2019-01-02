/**************************************************************************
    BuguRTOS-2.0.x (Bugurt real time operating system)
    Copyright (C) 2016 anonimous

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
#ifndef _BGRT_PORT_H_
#define _BGRT_PORT_H_

/*!
\~russian
\brief
Запретить прерывания.

\~english
\brief
Disable interrupts.
*/
#define BGRT_INT_LOCK()

/*!
\~russian
\brief
Разрешить прерывания.

\~english
\brief
Enable interrupts.
*/
#define BGRT_INT_FREE()

/*!
\~russian
\brief
Текущий блок ядра.

\~english
\brief
Current kernel block.
*/
#define BGRT_KBLOCK

/*!
\~russian
\brief
Текущий процесс.

\~english
\brief
Current process.
*/
#define BGRT_CURR_PROC

/*!
\~russian
\brief
Шаблон обработчика прерывания.

\param v  Идентификатор обработчика прерывания.

\~english
\brief
Interrupt service routine declaration template.

\param v An interrupt vector id.
*/
#define BGRT_ISR(v)

/*!
\~russian
\brief
Инициализация атомарной карты.

\warning Для вызова из обработчиков прерываний/критических секций!

\param map_ptr  Указатель на атомарную карту.

\~english
\brief
Atomic map initialization.

\warning For ISR/crit_sec usage!

\param map_ptr A pointer to atomic map.
*/
#define BGRT_ATM_INIT_ISR(map_ptr)

/*!
\~russian
\brief
Инициализация атомарной карты.

\param map_ptr  Указатель на атомарную карту.

\~english
\brief
Atomic map initialization.

\param map_ptr A pointer to atomic map.
*/
void bgrt_atm_init(bgrt_map_t * map_ptr);

/*!
\~russian
\brief
Поставить биты в 1 по маске.

\param map_ptr  Указатель на атомарную карту.
\param msk Маска.

\~english
\brief
Set masked bits.

\param map_ptr A pointer to atomic map.
\param msk A mask.
*/
#define BGRT_ATM_BSET_ISR(map_ptr, msk)

/*!
\~russian
\brief
Поставить биты в 1 по маске.

\warning Для вызова из обработчиков прерываний/критических секций!

\param map_ptr  Указатель на атомарную карту.
\param msk Маска.

\~english
\brief
Set bits using mask.

\warning For ISR/crit_sec usage!

\param map_ptr A pointer to atomic map.
\param msk A mask.
*/
void bgrt_atm_bset(bgrt_map_t * map_ptr, bgrt_map_t msk);

/*!
\~russian
\brief
Считать биты по маске.

\warning Для вызова из обработчиков прерываний/критических секций!

\param map_ptr  Указатель на атомарную карту.
\param msk Маска.
\return Состояние векторов прерываний.

\~english
\brief
Read masked bits.

\warning For ISR/crit_sec usage!

\param map_ptr A pointer to atomic map.
\param msk A mask.
\return Masked vectors state.
*/
#define BGRT_ATM_BGET_ISR(map_ptr, msk)

/*!
\~russian
\brief
Считать биты по маске.

\param map_ptr  Указатель на атомарную карту.
\param msk Маска.
\return Состояние векторов прерываний.

\~english
\brief
Read masked bits.

\param map_ptr A pointer to atomic map.
\param msk A mask.
\return Masked vectors state.
*/
bgrt_map_t bgrt_atm_bget(bgrt_map_t * map_ptr, bgrt_map_t msk);
/*!
\~russian
\brief
Сбросить значения битов по маске.

\warning Для вызова из обработчиков прерываний/критических секций!

\param map_ptr  Указатель на атомарную карту.
\param msk Маска.
\return Последнее состояние интересующих битов.

\~english
\brief
Clear masked bits.

\warning For ISR/crit_sec usage!

\param map_ptr A pointer to atomic map.
\param msk A mask.
\return Last masked bits state.
*/
#define BGRT_ATM_BCLR_ISR(map_ptr, msk)


/*!
\~russian
\brief
Сбросить биты по маске.

\param map_ptr  Указатель на атомарную карту.
\param msk Маска.
\return Последнее состояние маскированных битов.

\~english
\brief
Clear masked bits.

\param map_ptr A pointer to atomic map.
\param msk A mask.
\return Last masked bits state.
*/
bgrt_map_t bgrt_atm_bclr(bgrt_map_t * map_ptr, bgrt_map_t msk);

#endif // _BGRT_PORT_H_
