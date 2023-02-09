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
OFILE_HANDLE            dw      ?                                       ; The out file handle
OFILE_NAME              db      "PEOPLE.TXT",0                          ; The out filename, in the current directory
OFILE_HEADER            db      "TODAY'S DATE IS"                       ; Out file line #1
LOFILE_HEADER           dw      $-OFILE_HEADER                          ; Length of OFILE_HEADER
OFILE_TBL_HEADER_C1     db      "NAME"                                  ; Out file line #3 -- table header col #1
LOFILE_TBL_HEADER_C1    dw      $-OFILE_TBL_HEADER_C1                   ; Length of OFILE_TBL_HEADER_C1
OFILE_TBL_HEADER_C2     db      "DATE OF BIRTH"                         ; Out file line #3 -- table header col #2
LOFILE_TBL_HEADER_C2    dw      $-OFILE_TBL_HEADER_C2                   ; Length of OFILE_TBL_HEADER_C2
OFILE_TBL_HEADER_C3     db      "AGE"                                   ; Out file line #3 -- table header col #3
LOFILE_TBL_HEADER_C3    dw      $-OFILE_TBL_HEADER_C3                   ; Length of OFILE_TBL_HEADER_C3
OFILE_TBL_RS            db      13,10,'$'                               ; Out file table record separator -- ASCII CRLF + LF
OFILE_TBL_FS            db      9,'$'                                   ; Out file table field separator -- ASCII TAB
STRING_START            db      36                                      ; \
STRING_CHARS_GOT        db      ?                                       ;  * String buffer -- 35 chars + CR = 36
STRING                  db      36 dup (' ')                            ; /     Byte 1: Sets to max length of the buffer, including CR
                                                                        ;       Byte 2: The function sets to input chars, not counting CR
                                                                        ;       Byte 3--n: The buffer
LSTRING                 dw      $ - STRING                              ; Length of STRING
STRING_TERM             db      '$',0                                   ; Prevent any kind of buffer overflow -- dollar-terminated or ASCIIZ strings
BUFF_NUM                dw      ?                                       ; Number buffer
ASCII_SPC               db      ' '                                     ; ASCII TAB
ASCII_TAB               db      9                                       ; ASCII TAB
ASCII_CRLF              db      13,10                                   ; ASCII TAB
ASCII_VRT               db      '|'                                     ; ASCII TAB
MSGERR_OPEN_FILE        db      "ERROR OPENING FILE",'$'                ; File access error message
DSEG    ENDS


;; Person structure stores each person data
PERSON  STRUCT
        SNAME           db      35 dup (?),'$'                          ; <string> The person's name
        SBRTH           db      10 dup (?),'$'                          ; <string> The person's birth date
        DAGE            db      ?                                       ; <number> The person's age in days
PERSON  ENDS


;; ES stores dynamic data and constants
ESEG    SEGMENT
BC_AD_DIFF              dw      543                                     ; Difference between BC and AD year, in years
DAYS_IN_YEAR            dw      365                                     ; Number of days in a year
DAYS_IN_MNTH            dw      30                                      ; Number of days in a year
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

        ; mov     ax, 0
        ; push    ax
        ; lea     ax, STRING
        ; push    ax
        ; mov     ax, LSTRING
        ; push    ax
        ; call    fprint

        mov     ah, 2Ah                         ; DOS Get Date
        int     21h                             ;       CX: Year (1980-2099)
                                                ;       DH: Month (1-12)
                                                ;       DL: Day (1-31)
                                                ;       AL: Day of the week (0=Sun., 6=Sat.)

        mov     CUR_YYYY, cx                    ; Store current Year to DS:[CUR_YYYY]
        mov     CUR_MM, dh                      ; Store current Month to DS:[CUR_MM]
        mov     CUR_DD, dl                      ; Store current Day to DS:[CUR_DAY]

; Check if out file already exists
        mov     ah, 3Ch                         ; DOS Create Handle
        lea     dx, OFILE_NAME                  ; Out filename
        mov     cx, 0h                          ; As a normal file
        int     21h

        jc      J_ERR_OPEN_FILE                 ; Error occurs
        jmp     FILE_READY                      ; The file is ready to be written

J_ERR_OPEN_FILE:
        jmp     ERR_OPEN_FILE

; Every resource is ready
FILE_READY:
        mov     OFILE_HANDLE, ax                ; Save file handle

; Print line 1
        mov     ax, OFILE_HANDLE
        push    ax
        lea     ax, ASCII_TAB
        push    ax
        mov     ax, 1
        push    ax
        call    fprint

        mov     ax, OFILE_HANDLE                ; "TODAY'S DATE IS"
        push    ax
        lea     ax, OFILE_HEADER
        push    ax
        mov     ax, LOFILE_HEADER
        push    ax
        call    fprint

        mov     ax, OFILE_HANDLE                ; TAB
        push    ax
        lea     ax, ASCII_TAB
        push    ax
        mov     ax, 1
        push    ax
        call    fprint

; Print current date
        lea     ax, STRING
        push    ax
        mov     ax, CUR_YYYY
        push    ax
        mov     al, CUR_MM
        cbw
        push    ax
        mov     al, CUR_DD
        cbw
        push    ax
        call    date_string

        mov     ax, OFILE_HANDLE                ; "TODAY'S DATE IS"
        push    ax
        lea     ax, STRING
        push    ax
        mov     ax, 10                          ; Date is 10 chars long
        push    ax
        call    fprint

        mov     ax, OFILE_HANDLE                ; TAB
        push    ax
        lea     ax, ASCII_CRLF
        push    ax
        mov     ax, 2
        push    ax
        call    fprint

; Line 2
        mov     ax, OFILE_HANDLE                ; "NAME"
        push    ax
        lea     ax, OFILE_TBL_HEADER_C1
        push    ax
        mov     ax, LOFILE_TBL_HEADER_C1
        push    ax
        call    fprint

        lea     ax, ASCII_SPC                   ; Header padding
        push    ax
        mov     ax, 31                          ; Padding; names can be up to 35 chars long, not counting "NAME" header
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars

; Field sep
        lea     ax, ASCII_VRT                   ; Field separator
        push    ax
        mov     ax, 2                           ; Separate with double-whitespace
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars
;;;

        mov     bx, OFILE_HANDLE                ; "DATE OF BIRTH"
        mov     cx, LOFILE_TBL_HEADER_C2
        lea     dx, OFILE_TBL_HEADER_C2
        mov     ah, 40h
        int     21h

; Field sep
        lea     ax, ASCII_VRT                   ; Field separator
        push    ax
        mov     ax, 2                           ; Separate with double-whitespace
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars

        mov     bx, OFILE_HANDLE                ; "AGE"
        mov     cx, LOFILE_TBL_HEADER_C3
        lea     dx, OFILE_TBL_HEADER_C3
        mov     ah, 40h
        int     21h

        lea     ax, ASCII_SPC                   ; Header padding
        push    ax
        mov     ax, 20                          ; Padding; names can be up to 35 chars long, not counting "NAME" header
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars

; Field sep
        lea     ax, ASCII_VRT                   ; Field separator
        push    ax
        mov     ax, 2                           ; Separate with double-whitespace
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars

; Newline
        lea     ax, ASCII_CRLF                  ; Field separator
        push    ax
        mov     ax, 1                           ; Separate with double-whitespace
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars

; Header written
        lea     ax, STRING_START                ; Get number of people
        push    ax
        call    get_string

        lea     ax, STRING                      ; Convert input string to number
        push    ax
        mov     al, STRING_CHARS_GOT
        cbw
        push    ax
        lea     ax, BUFF_NUM
        push    ax
        call    atob

        mov     cx, BUFF_NUM                    ; Loop over the people

NEXT_PERSON:
        push    cx
        ; lea     dx, [STRING+2]                  ; As required for 0Ah to work,
        ;                                         ;       starting byte of the string buffer is located at the end of the 2nd byte
        ; mov     ah, 09h                         ; DOS Display String function
        ; int     21h
        lea     ax, STRING_START                ; Get each ones name
        push    ax
        call    get_string

; Write name
        mov     bx, OFILE_HANDLE
        mov     al, STRING_CHARS_GOT
        cbw
        mov     cx, ax
        lea     dx, STRING
        mov     ah, 40h
        int     21h

; Write name padding
        lea     ax, ASCII_SPC                   ; Field separator
        push    ax
; Calculate padding amount
        mov     ax, 35
        mov     bx, cx
        sub     ax, bx
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars

; Field sep
        lea     ax, ASCII_VRT                   ; Field separator
        push    ax
        mov     ax, 2                           ; Separate with double-whitespace
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars


; Get Birthdate
        lea     ax, STRING_START                ; Get number of people
        push    ax
        call    get_string

        mov     bx, OFILE_HANDLE
        mov     al, STRING_CHARS_GOT
        cbw
        mov     cx, ax
        lea     dx, STRING
        mov     ah, 40h
        int     21h

; Birthdate padding
        lea     ax, ASCII_SPC                   ; Newline
        push    ax
        mov     ax, 3                           ; Separate with double-whitespace
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars

        lea     ax, ASCII_VRT                   ; Newline
        push    ax
        mov     ax, 2                           ; Separate with double-whitespace
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars

;;;
        lea     ax, ASCII_CRLF                  ; Newline
        push    ax
        mov     ax, 1                           ; Separate with double-whitespace
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars

        pop     cx
        dec     cx
        cmp     cx, 0
        jg      JNEXT_PERSON
        jmp     EOP

JNEXT_PERSON:
        jmp     NEXT_PERSON

        jmp     EOP                             ; Skip the error tracing

ERR_OPEN_FILE:                                  ; File access error
        lea     ax, MSGERR_OPEN_FILE
        push    ax
        mov     ax, 1
        push    ax
        call    print

EOP:                                            ; Very end of _start procedure
; Close file
        mov     bx, OFILE_HANDLE
        mov     ah, 3Eh
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
; Print/Display String (Function 09H wrapper)
; ARGUMENTS:
;       push    BYTE PTR []                     ; [BP+6]  Pointer to string, ending with '$'
;       push    BYTE                            ; [BP+4]  CRLF switch; if set to 1, CRLF is printed at the end of the string,
;                                               ;               otherwise, no CRLF is printed.
print   PROC
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local scope

        mov     ah, 09h                         ; DOS 'Display String' function
        mov     dx, [bp+6]                      ; Second argument; String to be printed
        int     21h

        mov     dx, [bp+4]                      ; First argument; CRLF switch
        cmp     dx, 0                           ; If the caller requests CRLF
        je      EO_PROC                         ; No CRLF requested from the caller

        call    print_crlf

EO_PROC:                                        ; End-of-procedure
        mov     sp, bp                          ; Step out of local scope
        pop     bp                              ; Restore BP
        ret     4                               ; This procedure uses 2 stack elements -- 2 bytes each
print   ENDP


; Print/Display String to File of Console (Function 09H, 40h wrapper)
; ARGUMENTS:
;       push    WORD                            ; [BP+8]  Set to 0 for Console only, otherwise, this procedure assumes that as a file handle.
;       push    BYTE PTR []                     ; [BP+6]  Pointer to string, ending with '$'
;       push    WORD                            ; [BP+4]  Length of string to be printed
fprint  PROC
        push    ax                              ; Save AX
        push    bx                              ; Save BX
        push    cx                              ; Save CX
        push    dx                              ; Save DX
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local scope

        mov     bx, [bp+16]                     ; Third argument; File to be printed
        mov     dx, [bp+14]                     ; Second argument; String to be printed

        cmp     bx, 0
        jne     FPRINT_TO_FILE                  ; BX != 0, it's a file handle

        mov     ah, 09h                         ; DOS Display String
        int     21h

        jmp     EOP_FPRINT

FPRINT_TO_FILE:
        mov     cx, [bp+12]                     ; First argument; String length
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

EOP_FPRINT:                                     ; End-of-procedure
        mov     sp, bp                          ; Step out of local scope
        pop     bp                              ; Restore BP
        pop     dx                              ; Restore DX
        pop     cx                              ; Restore CX
        pop     bx                              ; Restore BX
        pop     ax                              ; Restore AX
        ret     6                               ; This procedure uses 3 stack elements -- 2 bytes each
fprint  ENDP


;; Convert date to string
;       push    BYTE PTR []                     ; Destination string
;       push    WORD                            ; Year
;       push    WORD                            ; Month
;       push    WORD                            ; Day
date_string     PROC
        push    ax
        push    bx
        push    cx                              ; Save CX
        push    dx                              ; Save DX
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local scope

; DD
        mov     ax, [bp+12]                     ; Day
        push    ax
        mov     ax, 2                           ; Day is printed in 2 digits
        push    ax
        mov     ax, [bp+18]
        push    ax
        call    btoa

        mov     ax, [bp+12]
        cmp     ax, 10
        jge     NO_DD_PAD

        mov     bx, [bp+18]
        mov     BYTE PTR [bx], '0'

NO_DD_PAD:
        add     bx, 2                           ; To insert '/'
        mov     BYTE PTR [bx], '/'
        add     bx, 1
        mov     [bp+18], bx

; MM
        mov     ax, [bp+14]                     ; Month
        push    ax
        mov     ax, 2                           ; Month is printed in 2 digits
        push    ax
        mov     ax, [bp+18]
        push    ax
        call    btoa

        mov     ax, [bp+14]
        cmp     ax, 10
        jge     NO_MM_PAD

        mov     bx, [bp+18]
        mov     BYTE PTR [bx], '0'

NO_MM_PAD:
        add     bx, 2                           ; To insert '/'
        mov     BYTE PTR [bx], '/'
        add     bx, 1
        mov     [bp+18], bx

; YYYY
        mov     ax, [bp+16]                     ; Year
        push    ax
        mov     ax, 4                           ; Year is printed in 4 digits
        push    ax
        mov     ax, [bp+18]
        push    ax
        call    btoa

EOP_DATE_STRING:                                ; End-of-procedure
        mov     sp, bp                          ; Step out of local scope
        pop     bp                              ; Restore BP
        pop     dx                              ; Restore DX
        pop     cx                              ; Restore CX
        pop     bx                              ; Restore BX
        pop     ax                              ; Restore AX
        ret     6                               ; This procedure uses 3 stack elements -- 2 bytes each
date_string     ENDP


;; Write a char to file n <= 255 times
;       push    BYTE PTR []                     ; Pointer to a character buffer in DS
;       push    WORD                            ; Number of times to be printed
;       push    WORD                            ; File handle
fprint_dup_chars   PROC
        push    ax                              ; Save AX
        push    bx                              ; Save BX
        push    cx                              ; Save CX
        push    dx                              ; Save DX
        push    bp                              ; Save BP
        mov     bp, sp
        sub     sp, 2

        mov     bx, [bp+12]                     ; File handle
        mov     cx, 1                           ; Bytes to write
        mov     dx, [bp+16]                     ; Pointer to char

        mov     ax, [bp+14]                     ; Loop counter

FPRINT_DUP_CHARS_NEXT:
        push    ax

        mov     ah, 40h                         ; DOS Write Handle
        int     21h

        pop     ax
        dec     ax
        cmp     ax, 0
        jg      FPRINT_DUP_CHARS_NEXT

        mov     sp, bp
        pop     bp                              ; Restore BP
        pop     dx                              ; Restore DX
        pop     cx                              ; Restore CX
        pop     bx                              ; Restore BX
        pop     ax                              ; Restore AX
        ret     6
fprint_dup_chars   ENDP


;; Procedure #5
;; Get String
; ARGUMENTS:
;       push    BYTE PTR []                     ; Where to store the input string
get_string      PROC
        push    bx                              ; Save BX
        push    dx                              ; Save DX
        push    si                              ; Save SI
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local stack frame

        mov     dx, [bp+10]                     ; Get the destination string address, store to DI

        mov     ah, 0Ah                         ; DOS Buffered Keyboard Input function
        int     21h

        mov     bx, 0                           ; Clear BX
        mov     si, dx

        mov     bl, [si+1]                      ; Get number of input chars, not counting CR
        mov     WORD PTR [bx+si+2], '$'

; CRLF according to input line
        mov     dl, 13
        mov     ah, 02h
        int     21h

        mov     dl, 10
        mov     ah, 02h
        int     21h

        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        pop     si                              ; Restore SI
        pop     dx                              ; Restore DX
        pop     bx                              ; Restore BX
        ret     2                               ; This procedure uses 1 stack element -- 2 bytes each
get_string      ENDP


;; Procedure #6
; Print ASCII 'TAB' character
print_tab       PROC
        mov     ah, 02h                         ; DOS 'Display Character' function
        mov     dl, 9                           ; ASCII TAB
        int     21h

        ret
print_tab       ENDP


;; Procedure #7
; Print ASCII 'CRLF' sequence
print_crlf      PROC
        mov     ah, 02h                         ; DOS 'Display Character' function
        mov     dl, 13                          ; ASCII CR
        int     21h
        mov     ah, 02h                         ; DOS 'Display Character' function
        mov     dl, 10                          ; ASCII LF
        int     21h

        ret
print_crlf      ENDP
CSEG    ENDS
        END     _start                          ; Initialize CS and IP
