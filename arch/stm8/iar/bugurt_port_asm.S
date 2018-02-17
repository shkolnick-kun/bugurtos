;/**************************************************************************
;    BuguRTOS-4.0.x(Bugurt real time operating system).
;    Copyright (C) 2016  anonimous
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
; IAR assembler routines


  NAME BUGURTASM
  SECTION .near_func.text:code

  #include "vregs.inc"

; stack_t * bugurt_save_context( void );
; Initial conditions are:
; ?b0...?b7 are saved to the stack by the compiler,
; return address is on top of the stack.

  PUBLIC bugurt_save_context
bugurt_save_context:
    ; Save return address to vregs
    popw Y
#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
    pop A
#endif
    ; Save vregs to stack
    push ?b11
    push ?b10
    push ?b9
    push ?b8
    push ?b15
    push ?b14
    push ?b13
    push ?b12
    ldw X, SP    ; Will return stack pointer
#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
    push A
#endif
    pushw Y ; Push return address on the top of the stack
#if (__CODE_MODEL__==__SMALL_CODE_MODEL__)
    ret
#else
    retf
#endif
;-------------------------------------------------------------------------------
; void bugurt_pop_context( void );
  PUBLIC bugurt_pop_context
bugurt_pop_context:
    popw Y
#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
    pop A
#endif
    jra ?pop_context
;-------------------------------------------------------------------------------
; void bugurt_restore_context( void [__near] * new_sp );
; Initial conditions are:
; new_sp is placed in X,
; return address is on top of the stack,
; VREGS are on new stack.
  PUBLIC bugurt_restore_context
bugurt_restore_context:
    popw Y
#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
    pop A
#endif
;stack pointer value is always 16bit, and not dependent on __DATA_MODEL__
    ldw SP,X     ; SP = X
?pop_context:    ; restore vregs
    pop ?b12
    pop ?b13
    pop ?b14
    pop ?b15
    pop ?b8
    pop ?b9
    pop ?b10
    pop ?b11
#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
    push A
#endif
    pushw Y ; push return address on the top of the stack
    ; Return from subroutine
#if (__CODE_MODEL__==__SMALL_CODE_MODEL__)
    ret
#else
    retf
#endif
;-------------------------------------------------------------------------------
; void bugurt_set_stack_pointer( void [__near] * new_sp );
; Initial conditions are:
; new_sp is placed in X,
; return address is on top of the stack.
  PUBLIC bugurt_set_stack_pointer
bugurt_set_stack_pointer:
    popw Y
#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
    pop A
#endif
    ldw SP,X     ; SP = X
#if (__CODE_MODEL__!=__SMALL_CODE_MODEL__)
    push A
#endif
    pushw Y ; push return address on the top of the stack
    ; Return from subroutine
#if (__CODE_MODEL__==__SMALL_CODE_MODEL__)
    ret
#else
    retf
#endif
    end
