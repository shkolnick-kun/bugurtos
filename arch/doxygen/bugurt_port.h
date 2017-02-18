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

#define BGRT_INT_LOCK()
#define BGRT_INT_FREE()

#define BGRT_VINT_PUSH_ISR    bgrt_vint_push_isr
#define BGRT_FIC_PUSH_INT_ISR BGRT_ATM_BSET_ISR

#define BGRT_KBLOCK bgrt_kernel.kblock
#define BGRT_CURR_PROC bgrt_kernel.kblock.sched.current_proc

#define BGRT_ISR(v)

//Виртуальный контроллер прерываний
typedef struct _bgrt_fic_t bgrt_fic_t;
//Свойства
/*!
\~russian
\brief
Виртуальный контроллер "быстрых" прерываний.

\~english
\brief
A virtual fast interrupt controller.
*/

struct _bgrt_fic_t
{
    bgrt_map_t map;      /*!< \~russian Карта векторов "быстрых" прерываний. \~english A fast interrupt vector map.*/
};
/*!
\~russian
\brief
Инициализация виртуального контроллера "быстрых" прерываний.

\warning Для вызова из обработчиков прерываний.кротических секций!

\param fic  Указатель на виртуальный контроллер прерываний.

\~english
\brief
Virtual interrupt controller initialization.

\warning For ISR/crit_sec usage!

\param fic A pointer to a #bgrt_vic_t object.
*/
void BGRT_ATM_INIT_ISR(bgrt_fic_t * fic);
/*!
\~russian
\brief
Инициализация виртуального контроллера "быстрых" прерываний.

\param fic  Указатель на виртуальный контроллер прерываний.

\~english
\brief
Virtual interrupt controller initialization.

\param fic A pointer to a #bgrt_vic_t object.
*/
void bgrt_atm_init(bgrt_fic_t * fic);
/*!
\~russian
\brief
Поставить прерывания на обработку

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.

\~english
\brief
Push vectors to fic.

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
*/
void BGRT_ATM_BSET_ISR(bgrt_fic_t * fic, bgrt_map_t msk);

/*!
\~russian
\brief
Поставить прерывания на обработку.

\warning Для вызова из обработчиков прерываний.кротических секций!

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.

\~english
\brief
Push vectors to fic.

\warning For ISR/crit_sec usage!

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
*/
void bgrt_atm_bset(bgrt_fic_t * fic, bgrt_map_t msk);
/*!
\~russian
\brief
Считать сотояние векторов по маске.

\warning Для вызова из обработчиков прерываний.кротических секций!

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.
\return Состояние векторов прерываний.

\~english
\brief
Read masked vectors state.

\warning For ISR/crit_sec usage!

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
\return Masked vectirs state.
*/
bgrt_map_t BGRT_ATM_BGET_ISR(bgrt_fic_t * fic, bgrt_map_t msk)

/*!
\~russian
\brief
Считать сотояние векторов по маске.

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.
\return Состояние векторов прерываний.

\~english
\brief
Read masked vectors state.

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
\return Masked vectirs state.
*/
bgrt_map_t bgrt_atm_bget(bgrt_fic_t * fic, bgrt_map_t msk);
/*!
\~russian
\brief
Извлечь вектора прерываний для обработки.

\warning Для вызова из обработчиков прерываний.кротических секций!

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.
\return Последнее состояние векторов прерываний.

\~english
\brief
Read masked vectors state.

\warning For ISR/crit_sec usage!

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
\return Last masked vectors state.
*/
bgrt_map_t BGRT_ATM_BCLR_ISR(bgrt_fic_t * fic, bgrt_map_t msk);

/*!
\~russian
\brief
Извлечь вектора прерываний для обработки.

\param fic Указатель на виртуальный контроллер "быстрых" прерываний.
\param msk Маска векторов для обработки.
\return Последнее состояние векторов прерываний.

\~english
\brief
Read masked vectors state.

\param fic A pointer to a #bgrt_fic_t object.
\param msk A vector mask.
\return Last masked vectors state.
*/
bgrt_map_t bgrt_atm_bclr(bgrt_fic_t * fic, bgrt_map_t msk);

#endif // _BGRT_PORT_H_
