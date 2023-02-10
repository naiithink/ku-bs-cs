SSEG    SEGMENT STACK
        DW      64 DUP (?)
SSEG    ENDS


DSEG    SEGMENT
STRING              db      4 dup (' '),'$'
SFROM               db      "hello, world",'$'
NUMS                    db      "09"
NUMN                    dw      ?
DSEG    ENDS

ESEG    SEGMENT
MY_NUM              db      ?
STERM               db      '$'
STO                 db      12 dup (?),'$'
ESEG    ENDS

CSEG    SEGMENT
        assume  cs:CSEG, ds:DSEG, es:ESEG, ss:SSEG
_start  PROC
        mov     ax, DSEG
        mov     ds, ax
        mov     ax, ESEG
        mov     es, ax

        lea     ax, NUMS
        push    ax
        mov     ax, 2
        push    ax
        lea     ax, NUMN
        push    ax
        call    atob

        mov     dx, NUMN
        add     dl, '0'
        mov     ah, 02h
        int     21h

        jmp     EOP

;;;
        xor     dx, dx

        mov     al, 11
        mov     bl, 12
        ; idiv    bl
        sub     al, bl

        mov     dl, al
        neg     dl
        add     dl, '0'
        mov     ah, 02h
        int     21h

        jmp     EOP

;;;
        mov     al, 12 ; CUR_MM
        mov     bl, 1 ; BUFF_MM
        sub     al, bl

        mov     dl, al
        ; neg     dl
        add     dl, '0'
        mov     ah, 02h
        int     21h

        jmp     EOP

;;;
        push    ds
        mov     ax, es
        mov     ds, ax

        mov     bx, ds
        mov     di, offset [MY_NUM]

        mov     BYTE PTR [di], 'A'

        mov     dl, MY_NUM
        mov     ah, 02h
        int     21h

        pop     ds

EOP:
        mov     ah, 4Ch
        mov     al, 0
        int     21h
_start  ENDP

;; Procedure #3
;; ASCII to binary
; This procedure does not validate its argument.
; ARGUMENTS:
;       push    BYTE PTR []                     ; Pointer to string storing ASCII-coded signed integer value;
                                                ;       the string must be in the format required by DOS function 0Ah
;       push    WORD                            ; Source string length, not counting any terminator or CR
;       push    WORD PTR []                     ; Pointer to WORD buffer to store the result
atob    PROC
        push    ax                              ; Save AX
        push    bx                              ; Save BX
        push    cx                              ; Save CX
        push    dx                              ; Save DX
        push    si                              ; Save SI
        push    di                              ; Save DI
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local stack frame

        mov     si, [bp+20]                     ; Get the source string address
        mov     cx, [bp+18]                     ; Get length of source string
        mov     di, [bp+16]                     ; Get the destination address, store to DI

        add     si, cx                          ; SI is now virtually pointing to the least-significant decimal digit of the source string
        dec     si                              ; String is kind of zero-based array

        mov     ax, 0                           ; A* register accumulates the decoded values
        mov     bx, 1                           ; BX yields the place values -- in decimal

NEXT_DIGIT:
        mov     dl, [si]                        ; Get the ASCII-coded number
        sub     dl, 30h                         ; De-ASCII the number

        cmp     dl, '-'                         ; Whether it's a `'-'` indicating negative number
        je      NEG_NUM                         ; Negate the result

        push    ax                              ; >>>1 Save current actual result

        mov     ax, 0                           ; Clear AX

        mov     al, dl                          ; Move the result to AL for multiplication
        cbw                                     ; Will be performing 32-bit multiplication on AX and BX
        mul     bx                              ; Weight the current digit with the corresponding place value

        pop     dx                              ; <<<1 Restore current actual result

        add     ax, dx                          ; Add current digit to the result

        push    ax                              ; >>>1 Save current actual result

        mov     ax, bx                          ; Advance to the next decimal place
        mov     bx, 10
        mul     bx
        mov     bx, ax

        pop     ax                              ; <<<1 Restore current actual result

        dec     si                              ; Decimal-left-shift over the source string

        loop    NEXT_DIGIT

        jmp     DONE                            ; No `'-'` was found, non-negative number

NEG_NUM:
        mov     bx, -1                          ; Negate the number
        mul     bx

DONE:
        mov     [di], ax                        ; Store the result at location pointed to by DI

        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        pop     di                              ; Restore DI
        pop     si                              ; Restore SI
        pop     dx                              ; Restore DX
        pop     cx                              ; Restore CX
        pop     bx                              ; Restore BX
        pop     ax                              ; Restore AX
        ret     4                               ; This procedure uses 2 stack elements -- 2 bytes each
atob    ENDP
CSEG    ENDS
        END     _start
