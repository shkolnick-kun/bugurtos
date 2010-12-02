;/**************************************************************************
;    BuguRTOS-0.1.x(sguschekka) a small OS 4 microcontrollers.
;    Copyright (C) 2010  anonimous
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

#include "../../../config.h"

.list

;-------------------------------------------------------------------------------
;
#if FLASHEND > 0x1FFF
  #define _call_ call
#else
  #define _call_ rcall
#endif


;-------------------------------------------------------------------------------
.macro	_store_regs_
    push	r0			; store r0 value
    push	r1
    eor	    r1,r1       ; clear zero reg, LOL
    push	r2
    push	r3
    push	r4
    push	r5
    push	r6
    push	r7
    push	r8
    push	r9
    push	r10
    push	r11
    push	r12
    push	r13
    push	r14
    push	r15
    push	r16
    push	r17
    push	r18
    push	r19
    push	r20
    push	r21
    push	r22
    push	r23
    push	r24
    push	r25
    push	r26
    push	r27
    push	r28
    push	r29
    push	r30
    push	r31
#ifdef RAMPZ
	in	    r31,(_SFR_IO_ADDR(RAMPZ))
	push	r31
#endif
.endm
;-------------------------------------------------------------------------------
.macro	_load_regs_
#ifdef RAMPZ
	pop	    r31
	out     (_SFR_IO_ADDR(RAMPZ)),r31
#endif
    pop	    r31
    pop	    r30
    pop	    r29
    pop	    r28
    pop	    r27
    pop	    r26
    pop	    r25
    pop	    r24
    pop	    r23
    pop	    r22
    pop	    r21
    pop	    r20
    pop	    r19
    pop	    r18
    pop	    r17
    pop	    r16
    pop	    r15
    pop	    r14
    pop	    r13
    pop	    r12
    pop	    r11
    pop	    r10
    pop 	r9
    pop	    r8
    pop	    r7
    pop	    r6
    pop	    r5
    pop	    r4
    pop	    r3
    pop	    r2
    pop	    r1
    pop	    r0			; load r0 value
.endm


;-------------------------------------------------------------------------------

.text

;-------------------------------------------------------------------------------

	.extern	system_timer_handler
	.global SYSTEM_TIMER_ISR

SYSTEM_TIMER_ISR:
	;---------------------------------;
	;      Save Context to stack      ;
	;---------------------------------;
    push	r0                          ; store r0
    in	    r0,(_SFR_IO_ADDR(SREG))	    ; load SREG 2 r0
    cli
    _store_regs_                        ; now we store SREG by "push r0", and then store r1...r31
    ;----------------------------------
	in	    r24,(_SFR_IO_ADDR(SPL))	    ; load current stack pointer
	in	    r25,(_SFR_IO_ADDR(SPH))	    ; as argument
	_call_  system_timer_handler        ; SP = system_timer_handler(SP);
	out	    (_SFR_IO_ADDR(SPH)), r25	; set next stack pointer
	out	    (_SFR_IO_ADDR(SPL)), r24	; from return value
	;---------------------------------;
	;        Restore Context          ;
	;---------------------------------;
    _load_regs_                         ; load r31...r1, then load stored SREG value 2 r0
    out	    (_SFR_IO_ADDR(SREG)),r0	    ; load SREG from r0
    pop	    r0			                ; load stored r0 value
	;----------------------------------
    reti
;-------------------------------------------------------------------------------
	.extern	resched_local_context_switch
	.global resched_local

resched_local:
	;---------------------------------;
	;        Save Context             ;
	;---------------------------------;
    push	r0                          ; store r0
    in	    r0,(_SFR_IO_ADDR(SREG))	    ; load SREG 2 r0
    cli
    _store_regs_
    ;----------------------------------
	in	    r24,(_SFR_IO_ADDR(SPL))	    ; load current stack pointer
	in	    r25,(_SFR_IO_ADDR(SPH))	    ; as argument
	_call_  resched_local_context_switch; SP = resched_local_context_switch(SP);
	out	    (_SFR_IO_ADDR(SPH)), r25	; set next stack pointer
	out	    (_SFR_IO_ADDR(SPL)), r24	; from return value
	;---------------------------------;
	;        Restore Context          ;
	;---------------------------------;
    _load_regs_
    out	    (_SFR_IO_ADDR(SREG)),r0	    ; load SREG from r0
    pop	    r0			                ; load stored r0 value
	;----------------------------------
	ret
;-------------------------------------------------------------------------------
.end
;*******************************************************************************
