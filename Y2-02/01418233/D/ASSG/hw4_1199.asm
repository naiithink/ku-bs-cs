TITLE   Potsawat Thinkanwatthana
SUBTTL  6410451199

;; Output file format
; 
; >>>>> PEOPLE.TXT
;       TODAY'S DATE IS         dd/mm/yyyy
; 
; NAME          DATE OF BIRTH           AGE
; 
; ???? ????     dd/mm/yyyy              ?? YEARS ?? MONTHS ?? DAYS
; 
; ???? ????     dd/mm/yyyy              ?? YEARS ?? MONTHS ?? DAYS
; 
; ...
; <<<<< PEOPLE.TXT


SSEG    SEGMENT STACK                           ; Initialize SS
        dw      64 dup (?)
SSEG    ENDS


;; DS stores printable data
DSEG    SEGMENT
OFILE_HEADER            db      "TODAY'S DATE IS",'$'                   ; Out file line #1
OFILE_TBL_HEADER_C1     db      "NAME",'$'                              ; Out file line #3 -- table header col #1
OFILE_TBL_HEADER_C2     db      "DATE OF BIRTH",'$'                     ; Out file line #3 -- table header col #2
OFILE_TBL_HEADER_C3     db      "AGE",'$'                               ; Out file line #3 -- table header col #3
OFILE_TBL_RS            db      13,10,10,'$'                            ; Out file table record separator -- ASCII CRLF + LF
OFILE_TBL_FS            db      9,'$'                                   ; Out file table field separator -- ASCII TAB
STRING                  db      36,?,6 dup (' ')                        ; String buffer -- 35 chars + CR = 36
                                                                        ;       Byte 1: Sets to max length of the buffer, including CR
                                                                        ;       Byte 2: The function sets to input chars, not counting CR
                                                                        ;       Byte 3--n: The buffer
STRING_TERM             db      '$',0                                   ; Prevent any kind of buffer overflow -- dollar-terminated or ASCIIZ strings
DSEG    ENDS


;; ES stores dynamic data and constants
ESEG    SEGMENT
OFILE_NAME              db      "PEOPLE.TXT",0                          ; The out file name, in the current directory
CUR_YYYY                dw      ?                                       ; Current year in AD [1980, 2099]
CUR_MM                  db      ?                                       ; Current month [1, 12]
CUR_DD                  db      ?                                       ; Current day [1, 31]
ESEG    ENDS


CSEG    SEGMENT 'CODE'                          ; CS is of 'CODE' class
        assume  cs:CSEG, ds:DSEG, es:ESEG, ss:SSEG

;; Procedure #1
_start  PROC                                    ; Start of the main procedure _start
        mov     ax, DSEG                        ; Initialize DS
        mov     ds, ax
        mov     ax, ESEG                        ; Initialize ES
        mov     es, ax

        lea     dx, STRING                      ; Load the formed buffer to DS:DX
        mov     ah, 0Ah                         ; DOS Buffered Keyboard Input function
        int     21h

        mov     bx, 0                           ; Clear BX
        mov     bl, STRING[1]                   ; Get the number of input chars from the buffer;
                                                ;       set by DOS function 0Ah
        mov     STRING[bx+2], '$'               ; Insert '$' into the string buffer;
                                                ;       the string terminator for DOS function 09h to work properly.

        mov     dl, 10
        mov     ah, 02h
        int     21h

        lea     dx, [STRING+2]                  ; As required for 0Ah to work,
                                                ;       starting byte of the string buffer is located at the end of the 2nd byte
        mov     ah, 09h                         ; DOS Display String function
        int     21h

        mov     al, 0
        mov     ah, 4Ch
        int     21h
_start  ENDP                                    ; End of the main procedure _start


;; Procedure #2
;; Binary to ASCII String
; ARGUMENTS:
;       push    WORD                            ; Signed number to be converted
;       push    WORD                            ; Length of resulting string
;       push    BYTE PTR []                     ; String PTR for resulting string
btoa    PROC
        push    bp                              ; Save BP
        mov     bp, sp                          ; Set BP to SP
        sub     sp, 2                           ; Step into local stack frame

        mov     bx, [bp+4]                      ; Resulting string address
        mov     cx, [bp+6]                      ; Loop over the resulting string

FILL:                                           ; Fill the resulting string with spaces
        mov     BYTE PTR [bx], ' '              ; Assign to each string element a space char
        inc     bx                              ; Next character
        loop    FILL

        mov     ax, [bp+8]                      ; The number
        push    ax

        cmp     ax, 0                           ; Compare the number with 0d
        jge     NEXT                            ; The number is non-negative
        neg     ax                              ; If the number is negative, complement out.

NEXT:
        mov     di, 10                          ; 10d as divisor
        cwd                                     ; Sign-extend from WORD AX to DWORD DX:AX
        div     di                              ; AX <- AX / 10
                                                ; 32-bit division:
                                                ;  - quotient goes to AX,
                                                ;  - remainder goes to DX
        add     dx, '0'                         ; Add the ASCII number encoding '0' -- 30h -- to DS, to get ASCII code of the remainder
        dec     bx                              ; Points to the next character in the resulting string
        mov     [bx], dl                        ; Store the ASCII-coded number at location pointed to by BX;
                                                ;       current digit in the resulting string

        cmp     ax, 0                           ; Done?
        jne     NEXT                            ; Continue to the next digit

; Done conversion
        pop     ax                              ; Get the number, store to AX for sign comparision
        cmp     ax, 0                           ; Whether the number is non-negative
        jge     DONE                            ; The number is non-negative, then return to the caller

        dec     bx                              ; Move to the left-most position in the resulting string to set the sign
        mov     BYTE PTR [bx], '-'              ; Store the character '-' to the string

; All done
DONE:
        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        ret     6                               ; This procedure uses 3 stack elements -- 2 bytes each
btoa    ENDP


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


;; Procedure #4
;; Print String -- DOS function 09h wrapper
; ARGUMENTS:
;       push    BYTE PTR []                     ; Offset from DS to a string, the string must have trailing `'$'`
print   PROC
        push    dx                              ; Save DX
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 4                           ; Step into local stack frame

        mov     dx, [bp+6]                      ; Get the string offset
        mov     ah, 09h                         ; DOS Display Character function
        int     21h

        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        pop     dx                              ; Restore DX
        ret     2                               ; This procedure uses 1 stack element -- 2 bytes each
print   ENDP


;; Procedure #5
;; Get String
; ARGUMENTS:
;       push    BYTE PTR []                     ; Where to store the input string
get_string      PROC
        push    ax                              ; Save AX
        push    bx                              ; Save BX
        push    dx                              ; Save DX
        push    di                              ; Save DI
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local stack frame

        mov     dx, [bp+6]                      ; Get the destination string address, store to DI

        mov     ah, 0Ah                         ; DOS Buffered Keyboard Input function
        int     21h

        mov     ax, 0                           ; Clear AX
        mov     bx, 0                           ; Clear BX
        mov     bx, dx

        mov     al, [bx+1]                      ; Get number of input chars, not counting CR


        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        pop     di                              ; Restore DI
        pop     dx                              ; Restore DX
        pop     bx                              ; Restore BX
        pop     ax                              ; Restore AX
        ret     2                               ; This procedure uses 1 stack element -- 2 bytes each
get_string      ENDP


CSEG    ENDS
        END     _start                          ; Initialize CS and IP
