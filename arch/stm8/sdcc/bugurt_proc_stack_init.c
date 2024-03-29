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

#include"../../../kernel/bugurt.h"

#ifdef __SDCC_MODEL_LARGE
#   define BGRT_INT_PTR unsigned long
#else /*__SDCC_MODEL_LARGE*/
#   define BGRT_INT_PTR unsigned short
#endif/*__SDCC_MODEL_LARGE*/

bgrt_stack_t * bgrt_proc_stack_init(
    bgrt_stack_t * bgrt_stack_top,
    bgrt_code_t pmain,
    void * arg,
    void (*return_address)(void)
)
{
    /*Will need main arg halfs*/
#define _ARGL ((unsigned short)arg & 0xFF)
#define _ARGH (((unsigned short)arg>>8)& 0xFF)

#if __SDCCCALL == 0
    /* main arg is on the stack*/
    *bgrt_stack_top-- = (bgrt_stack_t)_ARGL;
    *bgrt_stack_top-- = (bgrt_stack_t)_ARGH;
#   define _XL 0xAD
#   define _XH 0xDE
#else /*__SDCCCALL == 1*/
#   define _XL _ARGL
#   define _XH _ARGH
#endif/*__SDCCCALL*/

    /* return address (func) */
    *bgrt_stack_top-- = (bgrt_stack_t)(((BGRT_INT_PTR)return_address) & 0xFF);
    *bgrt_stack_top-- = (bgrt_stack_t)(((BGRT_INT_PTR)return_address>>8)& 0xFF);
#ifdef __SDCC_MODEL_LARGE
    *bgrt_stack_top-- = (bgrt_stack_t)(((BGRT_INT_PTR)return_address>>16)& 0xFF);
#endif/*__SDCC_MODEL_LARGE*/
    // process main
    *bgrt_stack_top-- = (bgrt_stack_t)(((BGRT_INT_PTR)pmain) & 0xFF);
    *bgrt_stack_top-- = (bgrt_stack_t)(((BGRT_INT_PTR)pmain>>8)& 0xFF);
#ifdef __SDCC_MODEL_LARGE
    *bgrt_stack_top-- = (bgrt_stack_t)(((BGRT_INT_PTR)pmain>>16)& 0xFF);
#else /*__SDCC_MODEL_LARGE*/
    *bgrt_stack_top-- = (bgrt_stack_t)0;
#endif/*__SDCC_MODEL_LARGE*/
    /* Y */
    *bgrt_stack_top-- = 0xAF;
    *bgrt_stack_top-- = 0xBE;
    /* X */
    *bgrt_stack_top-- = _XL;
    *bgrt_stack_top-- = _XH;
#undef _XL
#undef _XH
#undef _ARGL
#undef _ARGH
    /* A */
    *bgrt_stack_top-- = 0xAA;
    /* CCR */
    *bgrt_stack_top-- = 0x20; /* Interrupts are enabled */
    /* Dummy bytes, as after bgrt_isr_epilogue [addw sp, #2] is done */
    //*bgrt_stack_top-- = 0xFF;
    //*bgrt_stack_top-- = 0xFF;
    return bgrt_stack_top;
}
