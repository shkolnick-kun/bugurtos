;/**************************************************************************
;   BuguRTOS-4.0.x (Bugurt real time operating system)
;   Copyright (C) 2018 anonimous
;
;    This program is free software: you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation, either version 3 of the License, or
;    (at your option) any later version.
;
;    This program is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with this program.  If not, see <http://www.gnu.org/licenses/>.
;
;    Please contact with me by E-mail: shkolnick.kun@gmail.com
;
;    A special exception to the GPL can be applied should you wish to distribute
;    a combined work that includes BuguRTOS, without being obliged to provide
;    the source code for any proprietary components. See the file exception.txt
;    for full details of how and when the exception can be applied.
;**************************************************************************/

;/*****************************************************************************************
;```````````````````````````````..:+oyhdmNNMMMMMMNmmdhyo+:..```````````````````````````````
;``````````````````````````.:oydNMMMMMMMMMNNNNNNNNMMMMMMMMMNdy+:.``````````````````````````
;```````````````````````:sdNMMMMMNdys+/::----------::/osydNMMMMMNds:```````````````````````
;```````````````````.+hNMMMMmho/-..........................-/shmMMMMNh/.```````````````````
;````````````````./hNMMMNho:...................................-:ohNMMMNh/`````````````````
;``````````````.smMMMNy/-.......:////ss++/+-.......................-+yNMMMmo.``````````````
;````````````-sNMMMd+-.....:////:-...-/s::..............+o/-..........-odMMMNs.````````````
;``````````.sNMMNh/....................................-o:--............./hMMMNo.``````````
;`````````+mMMMh:-........................................-...............-/dMMMm/`````````
;```````.yMMMm/...................-::--..................:-........--........+mMMMy.```````
;``````:mMMMy-.......................-::-...............-:.........-::........-yMMMd:``````
;`````/NMMN+-..................::-.....-:-............../--.........-:/-.......-+NMMN:`````
;````+NMMm::o/-..--/+o+o+++++o+osys+//::-::.............:/....-:-::-..-++-.......:NMMN/````
;```/NMMm:.-++-+yhs/-``       `dMMMMMmho+:-..............:-/+yho/:/+oyo//o-......./mMMN:```
;``-NMMm/....-/--::/o+o+oo+oo++oosyss+smyo/.............:yyho-`     smMMddh-......./NMMN.``
;`.hMMM/......-++:-.-:oooooooooosyyhhys/...............-+osyyyyysssssooo+ohhs-......+MMMh.`
;`+MMMy.......-::/++:-.....-:/++++o+o/--................--/oooo+o++o+++////-y/.......hMMM/`
;.mMMN:.........--:---...-::/+//::--.......................--//+//-...-.....+/......./NMMd`
;/MMMy............-::----------....----/+-.....................-++/:---....-o-........hMMN:
;yMMM/.............--:://///oo+++/+++oo+-.......................-://+/:--::::.........+MMMs
;mMMN:................----:/h:::/:/::---.........................--/osss+++:..........:NMMd
;MMMd-....................:mNs:-....................................--:odo:-..........:mMMN
;MMMd-....................yoshyoso:--................................../mm/...........:mMMM
;MMMm:..................../-o/h.y-:+dooo+/:--....................-/osydddmh...........:mMMN
;mMMN:........................+mNs `h.  -d/:/+h++ooooy+++s++y+++mo+y` yh.do...........:NMMh
;sMMM+........................-hmMo/ds  oMo`.-o     :h   s:`h` `Nysd.-Ny-h:...........+MMMo
;/MMMh........................./smMMMMd+NMMNNMh`    sN: .mNNMddNMMMMNmN+..............hMMN:
;.dMMN/........................./+hMMMMMMMMMMMMmhyyyNMNNMMMMMMMMMMMNsoo-............./NMMd`
;`+MMMh.........................-/+omMMMMMMMMMMMMMMMMMMMMMMMMMMMMms-/+...............hMMM/`
;`.hMMM+..........................:/-omMMMMMMMMMMMMMMMdmMdhMMMds/-..-...............oMMMy``
;``.NMMN/............................--/hNN/h.`ys:dmsd:-syos+--+.................../NMMN.``
;```/NMMm:...........................:+/--:+s++oo+osoo+/:-..-/+::-................/mMMN:```
;````/NMMN:............................-/++/:-..........-//+/-..:+.--............/NMMN/````
;`````:NMMN+-.............../+-.............-://////////:-.......+s+::.........-oNMMN:`````
;``````:mMMMy-..............:/o-.................................:yo//........-hMMMd-``````
;```````.yMMMm+.............:o:++-...............................+y+o-......-+mMMMs.```````
;`````````/mMMMd/-...........-++:+/-.---........................-ho+/.....-/dMMMm/`````````
;``````````.oNMMMh/............-++:++/////:....................-yo:o-...-+hMMMNo.``````````
;````````````.sNMMMdo-...........-++::++:-:/+//:..............:o:/o-..-omMMMNo.````````````
;``````````````.omMMMNy+-..........-/+-.:/+/:--:+++/++//:/::/+/-+/.-+hMMMMmo```````````````
;`````````````````/hNMMMNho:-...............-:/:-....--::::--..-/ohNMMMNy:`````````````````
;```````````````````./hNMMMMmhs/-..........................-/shNMMMMNy/.```````````````````
;```````````````````````:sdNMMMMMNdhso+/:----------:/+oshdNMMMMMNho:```````````````````````
;``````````````````````````.:+ydNMMMMMMMMMMNNNNNNMMMMMMMMMMmds+:```````````````````````````
;````````````````````````````````.:/osyhdmNNMMMMNNmdhyso/:.````````````````````````````````
;******************************************************************************************
;*                                                                                        *
;*                   This logo was graciously delivered by 10003-kun ITT:                 *
;*                                                                                        *
;*                           http://www.0chan.ru/r/res/9996.html                          *
;*                                                                                        *
;*****************************************************************************************/
.nolist

#include <avr/io.h>

.list

;-------------------------------------------------------------------------------

.text

;-------------------------------------------------------------------------------
	.global bugurt_save_context
bugurt_save_context:
    push    r2                          ; store r2
    in      r2,(_SFR_IO_ADDR(SREG))     ; load SREG 2 r2
    push    r2
    push    r3
    push    r4
    push    r5
    push    r6
    push    r7
    push    r8
    push    r9
    push    r10
    push    r11
    push    r12
    push    r13
    push    r14
    push    r15
    push    r16
    push    r17
    push    r18
    push    r19
    push    r20
    push    r21
    push    r22
    push    r23
    push    r24
    push    r25
    push    r26
    push    r27
    push    r28
    push    r29
    push    r30
    push    r31
    ;---------------------------------------------------------------
    in      r30,(_SFR_IO_ADDR(SPL))     ; load current stack pointer 2 Z
    in      r31,(_SFR_IO_ADDR(SPH))
    ldd     r18,Z+33                    ; load return address 2 Y
    ldd     r19,Z+32
    std     Z+33,r0                     ;
    std     Z+32,r1
    clr     r1
#ifdef RAMPZ
    in      r31,(_SFR_IO_ADDR(RAMPZ))
    push    r31
#endif
    in      r24,(_SFR_IO_ADDR(SPL))
    in      r25,(_SFR_IO_ADDR(SPH))
    push    r18
    push    r19
    ret
;-------------------------------------------------------------------------------
    .global bugurt_pop_context
	.global bugurt_restore_context
bugurt_pop_context:
    pop     r19                         ; pop return address from the current stack
    pop     r18
    rjmp _bugurt_pop_context

bugurt_restore_context:
    pop     r19                         ; pop return address from the current stack
    pop     r18
    out     (_SFR_IO_ADDR(SPH)), r25    ;switch 2 new stack
    out     (_SFR_IO_ADDR(SPL)), r24

_bugurt_pop_context:
#ifdef RAMPZ
    pop     r31                         ; pop RAMPZ from the stack
    out     (_SFR_IO_ADDR(RAMPZ)),r31
#endif
    in      r31,(_SFR_IO_ADDR(SPH))     ; load sp 2 Z
    in      r30,(_SFR_IO_ADDR(SPL))
    ldd     r1,Z+32                     ; load r0 & r1 from the stack
    ldd     r0,Z+33
    std     Z+32,r19                    ; replace r0 and r1 on the stack with return address
    std     Z+33,r18
    ;---------------------------------------------------------------
    pop     r31
    pop     r30
    pop     r29
    pop     r28
    pop     r27
    pop     r26
    pop     r25
    pop     r24
    pop     r23
    pop     r22
    pop     r21
    pop     r20
    pop     r19
    pop     r18
    pop     r17
    pop     r16
    pop     r15
    pop     r14
    pop     r13
    pop     r12
    pop     r11
    pop     r10
    pop     r9
    pop     r8
    pop     r7
    pop     r6
    pop     r5
    pop     r4
    pop     r3
    pop     r2
    out     (_SFR_IO_ADDR(SREG)),r2     ; load SREG from r2
    pop     r2                          ; load stored r2 value
    ret
;-------------------------------------------------------------------------------
	.global bugurt_set_stack_pointer
bugurt_set_stack_pointer:
    pop     r1
    pop     r0
    out     (_SFR_IO_ADDR(SPH)), r25    ;switch 2 new stack
    out     (_SFR_IO_ADDR(SPL)), r24
    push    r0
    push    r1
    clr     r1                          ;zero register,lol
    ret
;-------------------------------------------------------------------------------
	.global bugurt_push_pointer
bugurt_push_pointer:
    pop     r1
    pop     r0
    push    r24
    push    r25
    push    r0
    push    r1
    clr     r1                          ;zero register,lol
    ret
;-------------------------------------------------------------------------------
	.global bugurt_reverse_byte_order
bugurt_reverse_byte_order:
    mov     r0,  r24
    mov     r24, r25
    mov     r25, r0
    ret
;-------------------------------------------------------------------------------
.end
;*******************************************************************************
