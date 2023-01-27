TITLE   Potsawat Thinkanwatthana
SUBTTL  6410451199


SSEG    SEGMENT STACK                           ; Auto initialize SS
        DW      64 DUP (?)
SSEG    ENDS


; DS stores printable data since DOS function 09h assumes DS:DX as the source string
DSEG    SEGMENT
TABLE1                  DW      2150, 525                               ; 1st table
                        DB      'D'
TABLE2                  DW      3020, 225                               ; 2nd table
                        DB      'C'
TABLE3                  DW      1450, 370                               ; 3rd table
                        DB      'C'
LBL_TABL                DB      "TABLE#",'$'                            ; Table label
LBL_METH                DB      "METHOD  ",'$'                          ; Method label
LBL_FOOD                DB      "FOOD    ",'$'                          ; Food label
LBL_DRNK                DB      "DRINK   ",'$'                          ; Drink label
LBL_DISC                DB      "DISCOUNT",'$'                          ; Discount label
LBL_TOTL                DB      "TOTAL   ",'$'                          ; Total label
CUR_BAHT                DB      "BAHT",'$'                              ; Currency (BAHT)
METH_CASH               DB      "CASH",'$'                              ; Cash method
METH_CRED               DB      "CREDIT CARD",'$'                       ; Credit Card method
METH_NA                 DB      "UNKNOWN PAYMENT METHOD, SKIP.",'$'     ; Unknown Payment method message
LINE                    DB      6 DUP (?),'$'                           ; String buffer
LLINE                   EQU     $ - LINE - 1                            ; Length of LINE aside '$'
                                                                        ;       The $ (w/o `'`) representing current address;
                                                                        ;       $ - LINE is effectively means
                                                                        ;       "the displacement between current address and LINE",
                                                                        ;       subtract that by 1 to get the true length of string LINE.
DSEG    ENDS


; ES stores dynamic data and constants
ESEG    SEGMENT
NUM_TABLE               DW      3                                       ; Number of tables
ELEM_SIZE               DW      5                                       ; Size of each element in TABLE# array in DS -- TABLE1 is the 0th element
DISP_CASH               DW      10                                      ; 10% discount
DISP_CRED               DW      7                                       ;  7% discount
INDX                    DB      ?                                       ; Current table index tracker -- zero-based
METH                    DW      ?                                       ; Pointer to string pointer
FOOD                    DW      ?                                       ; Current table Food
DRNK                    DW      ?                                       ; Current table Drink
DISC                    DW      ?                                       ; Current table Discount
TOTL                    DW      ?                                       ; Current table Total
PAY_CASH                EQU     'C'                                     ; - * Equates -- constant -- as its name "EQUATE"
PAY_CRED                EQU     'D'                                     ; _/
ESEG    ENDS


; CS stores instructions
CSEG    SEGMENT 'CODE'                          ; CSEG is of 'CODE' class
        ASSUME  cs:CSEG,
                ds:DSEG, es:ESEG,
                ss:SSEG

_start  PROC                                    ; Start of the main procedure _start
        mov     ax, DSEG                        ; Initialize DS
        mov     ds, ax
        mov     ax, ESEG                        ; Initialize ES
        mov     es, ax

        mov     cx, es:NUM_TABLE                ; Loop counter -- number of tables
        push    cx                              ; Save CX

NEXT_TABLE:                                     ; Entry point of the repetition
        mov     ax, es:NUM_TABLE
        sub     ax, cx                          ; TABLE# array is zero-based
        mov     es:INDX, al                     ; Save current TABLE# index
        mov     bx, es:ELEM_SIZE
        mul     bx                              ; Scaling the base with the size of each element in TABLE# -- 5 bytes
        mov     bx, ax
        mov     di, 0                           ; Food is at the start of the first WORD -- 0th byte
        mov     dx, TABLE1[bx][di]              ; Get Food from current TABLE# element
        mov     es:FOOD, dx
        mov     di, 2                           ; Drink is at the start of the second WORD -- 2nd byte
        mov     dx, TABLE1[bx][di]              ; Get Drink from current TABLE# element
        mov     es:DRNK, dx
        mov     di, 4                           ; Payment Method is at the end of the second WORD -- 4th byte
        mov     dx, TABLE1[bx][di]              ; Get Payment Method from current TABLE# element

        cmp     dl, PAY_CASH                    ; If paying by Cash
        je      CASH_DIS

        cmp     dl, PAY_CRED                    ; If paying by Credit Card
        je      CRED_DIS

; Payment method other than C or D
; No billing is issued, continues to the next table.
UNKNOWN_METH:
        ; mov     dl, '?'                       ; For debugging
        ; mov     ah, 02h
        ; int     21h

        lea     ax, METH_NA                     ; Print "UNKNOWN METHOD, SKIP."
        push    ax
        mov     ax, 1                           ; CRLF
        push    ax
        call    print

        jmp     BILLED                          ; Next table available

CASH_DIS:
        ; mov     ah, 02h                       ; For debugging
        ; mov     dl, '1'
        ; int     21h

        lea     ax, METH_CASH                   ; Pointer to string "CASH"
        mov     es:METH, ax                     ; es:METH now points to METH_CASH -- will be used later in the printing process

        mov     ax, es:FOOD
        mov     bx, DISP_CASH                   ; The discounting percentage
        mul     bx
        mov     bx, 100                         ; Per Cent
        div     bx
        mov     es:DISC, ax                     ; Store the integral discount to es:DISC

        jmp     DONE_DIS

CRED_DIS:
        ; mov     ah, 02h                       ; For debugging
        ; mov     dl, '2'
        ; int     21h

        lea     ax, METH_CRED                   ; Pointer to string "CREDIT CARD"
        mov     es:METH, ax                     ; es:METH now points to METH_CASH -- will be used later in the printing process

        mov     ax, es:FOOD
        mov     bx, DISP_CRED                   ; The discounting percentage
        mul     bx
        mov     bx, 100                         ; Per Cent
        div     bx
        mov     es:DISC, ax                     ; Store the integral discount to es:DISC

; Done discounting
DONE_DIS:
        mov     ax, es:FOOD                     ; Food
        mov     bx, es:DRNK                     ; Drink
        add     ax, bx                          ; Subtotal <- Food + Drink
        mov     bx, es:DISC                     ; Discount
        sub     ax, bx                          ; Total <- Subtotal - Discount
        mov     es:TOTL, ax                     ; Store Total to es:TOTL

; Done with the math, now print
; Print
; Line 1
        lea     ax, LBL_TABL                    ; Pointer to "TABLE#"
        push    ax
        mov     ax, 0
        push    ax
        call    print

        mov     dl, es:INDX                     ; Load zero-based table index from es:INDX
        add     dl, 1                           ; Add 1 to get the 1-based table number
        add     dl, 30h                         ; Convert to ASCII
        mov     ah, 02h                         ; DOS Display Character function
        int     21h

        call    print_crlf                      ; Print CRLF

; Line 2
        call    print_tab                       ; Print TAB

        lea     ax, LBL_METH                    ; Pointer to string "METHOD"
        push    ax
        mov     ax, 0                           ; No CRLF
        push    ax
        call    print

        call    print_tab                       ; Print TAB

        mov     ax, es:METH                     ; Indirectly load address of method string from es:METH
        push    ax
        mov     ax, 1                           ; CRLF
        push    ax
        call    print

; Line 3
        call    print_tab                       ; Print TAB

        lea     ax, LBL_FOOD                    ; Pointer to string "FOOD"
        push    ax
        mov     ax, 0                           ; No CRLF
        push    ax
        call    print

        call    print_tab                       ; Print TAB

        mov     ax, es:FOOD                     ; Load Food
        push    ax
        call    print_num                       ; Print Food

        call    print_crlf                      ; Print CRLF

; Line 4
        call    print_tab                       ; Print TAB

        lea     ax, LBL_DRNK                    ; Pointer to string "DRINK"
        push    ax
        mov     ax, 0                           ; No CRLF
        push    ax
        call    print

        call    print_tab                       ; Print TAB

        mov     ax, es:DRNK                     ; Load Drink
        push    ax
        call    print_num                       ; Print Drink

        call    print_crlf                      ; Print CRLF

; Line 5
        call    print_tab                       ; Print TAB

        lea     ax, LBL_DISC                    ; Pointer to string "DISCOUNT"
        push    ax
        mov     ax, 0                           ; No CRLF
        push    ax
        call    print

        call    print_tab                       ; Print TAB

        mov     ax, es:DISC                     ; Load Discount
        push    ax
        call    print_num                       ; Print Discount

        call    print_crlf                      ; Print CRLF

; Line 6
        call    print_tab                       ; Print TAB

        lea     ax, LBL_TOTL                    ; Pointer to string "TOTAL"
        push    ax
        mov     ax, 0                           ; No CRLF
        push    ax
        call    print

        call    print_tab                       ; Print TAB

        mov     ax, es:TOTL                     ; Load Total
        push    ax
        call    print_num                       ; Print Total

        call    print_tab                       ; Print TAB

        lea     ax, CUR_BAHT                    ; Pointer to string "BAHT"
        push    ax
        mov     ax, 1                           ; CRLF
        push    ax
        call    print

; Done with a certain table
BILLED:
        pop     cx                              ; \
        dec     cx                              ;  |
        cmp     cx, 0                           ;  * Loop construct
        push    cx                              ;  |
        jg      NEXT_TABLE                      ; /

EOP__START:                                     ; Very end of _start procedure
        mov     ah, 4Ch
        mov     al, 0
        int     21h
_start  ENDP


; Binary to ASCII String
; ARGUMENTS:
;       push    WORD                            ; Signed number to be converted
;       push    WORD                            ; Length of resulting string
;       push    BYTE PTR []                     ; String PTR for resulting string
btoa    PROC
        push    bp                              ; Save BP
        mov     bp, sp                          ; Set BP to SP
        sub     sp, 2                           ; Step into local scope

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
        mov     sp, bp                          ; Step out of local scope
        pop     bp                              ; Restore BP
        ret     6                               ; This procedure uses 3 stack elements -- 2 bytes each
btoa    ENDP


; Print ASCII 'TAB' character
print_tab       PROC
        mov     ah, 02h                         ; DOS 'Display Character' function
        mov     dl, 9                           ; ASCII TAB
        int     21h

        ret
print_tab       ENDP


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


; Print number ::= btoa + print
; ARGUMENTS:
;       push    WORD                            ; Number to be printed
print_num   PROC
        push    bp                              ; Save BP
        mov     bp, sp                          ; Set BP to SP
        sub     sp, 2                           ; Step into local scope

; Convert binary to ASCII string
        mov     ax, [bp+4]                      ; Argument #1: The number
        push    ax
        mov     ax, LLINE                       ; Length of string buffer LINE
        push    ax
        lea     ax, LINE                        ; Pointer to string buffer LINE
        push    ax
        call    btoa

; Print the number
        lea     dx, LINE                        ; Pointer to string buffer LINE
        mov     ah, 09h
        int     21h

        mov     sp, bp                          ; Step out of local scope
        pop     bp                              ; Restore BP
        ret     2                               ; This procedure uses 1 stack element -- 2 bytes each
print_num   ENDP


CSEG    ENDS                                    ; End of _start procedure
        END     _start                          ; Initialize CS and IP
