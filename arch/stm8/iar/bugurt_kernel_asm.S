
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
;stack pointer value is allways 16bit, and not dependent on __DATA_MODEL__
    ldw SP,X     ; SP = X 
    ; restore vregs 
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
  PUBLIC syscall
syscall:
    trap
#if (__CODE_MODEL__==__SMALL_CODE_MODEL__)
    ret
#else
    retf
#endif
    end