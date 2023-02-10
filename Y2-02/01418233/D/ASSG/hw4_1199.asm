TITLE   Potsawat Thinkanwatthana
SUBTTL  6410451199


;; 12 Modules/Procedures used


;; Output file format
; 
; >>>>> PEOPLE.TXT
;                     TODAY'S DATE IS   dd/mm/yyyy
; NAME                                  DATE OF BIRTH   AGE
; ???? ????                             dd/mm/yyyy      ?? YEARS ?? MONTHS ?? DAYS
; ???? ????                             dd/mm/yyyy      ?? YEARS ?? MONTHS ?? DAYS
; ...
; <<<<< PEOPLE.TXT


;; Sample Input
; > hw4_1199.exe
; 3
; 27/01/2566
; One Dee
; 09/12/2500
; Manit Sukjai
; 16/06/2533
; Anong Meesuk
; 28/11/2552
; >


;; Sample Output
; >>>>> PEOPLE.TXT
;                     TODAY'S DATE IS   27/01/2566
; NAME                                  DATE OF BIRTH   AGE                       
; One Dee                               09/12/2500      65 YEARS  1 MONTHS 18 DAYS
; Manit Sukjai                          16/06/2533      32 YEARS  7 MONTHS 11 DAYS
; Anong Meesuk                          28/11/2552      13 YEARS  2 MONTHS 30 DAYS
; 
; <<<<< PEOPLE.TXT


SSEG    SEGMENT STACK                           ; Initialize SS
        dw      64 dup (?)
SSEG    ENDS


;; DS stores printable data
DSEG    SEGMENT

; Switches
YYYY_IN_BC              equ     1                                       ; If is set to 0, use AD for Year, otherwise, use BC
USE_REAL_DATE           equ     0                                       ; If set to 0, use date specified in ES:CUR_YYYY (in AD), ES:CUR_MM, ES:CUR_DD.
BC_AD_DIFF              equ     543                                     ; Difference between BC and AD year, in years

; File metadata
OFILE_HANDLE            dw      ?                                       ; The out file handle
OFILE_NAME              db      "PEOPLE.TXT",0                          ; The out filename, in the current directory

; Table borders
OFILE_TBL_FS            db      ' '                                     ; Out file table field separator -- ASCII TAB
LOFILE_TBL_FS           dw      $ - OFILE_TBL_FS                        ; Out file table field separator length
OFILE_TBL_RS            db      13,10                                   ; Out file table record separator -- ASCII CRLF + LF
LOFILE_TBL_RS           dw      $ - OFILE_TBL_RS                        ; Out file table record separator length

; Date formatter
OFILE_DATE_FS           db      '/'                                     ; Out file date separator
LOFILE_DATE_FS          dw      $ - OFILE_DATE_FS                       ; Out file date separator length

; Boilerplates
OFILE_HEADER            db      "TODAY'S DATE IS"                       ; Out file line #1
LOFILE_HEADER           dw      $-OFILE_HEADER                          ; Length of OFILE_HEADER
OFILE_TBL_HEADER_C1     db      "NAME"                                  ; Out file line #3 -- table header col #1
LOFILE_TBL_HEADER_C1    dw      $-OFILE_TBL_HEADER_C1                   ; Length of OFILE_TBL_HEADER_C1
OFILE_TBL_HEADER_C2     db      "DATE OF BIRTH"                         ; Out file line #3 -- table header col #2
LOFILE_TBL_HEADER_C2    dw      $-OFILE_TBL_HEADER_C2                   ; Length of OFILE_TBL_HEADER_C2
OFILE_TBL_HEADER_C3     db      "AGE"                                   ; Out file line #3 -- table header col #3
LOFILE_TBL_HEADER_C3    dw      $-OFILE_TBL_HEADER_C3                   ; Length of OFILE_TBL_HEADER_C3
OFILE_U_YEAR            db      "YEARS"                                 ; Year unit
LOFILE_U_YEAR           dw      $ - OFILE_U_YEAR                        ; Length of Year unit
OFILE_U_MNTH            db      "MONTHS"                                ; Month unit
LOFILE_U_MNTH           dw      $ - OFILE_U_MNTH                        ; Length of Month unit
OFILE_U_DAY             db      "DAYS"                                  ; Day unit
LOFILE_U_DAY            dw      $ - OFILE_U_DAY                         ; Length of Day unit
STRING_START            db      36                                      ; \
STRING_CHARS_GOT        db      ?                                       ;  * String buffer -- 35 chars + CR = 36
STRING                  db      36 dup (' ')                            ; /     Byte 1: Sets to max length of the buffer, including CR
                                                                        ;       Byte 2: The function sets to input chars, not counting CR
                                                                        ;       Byte 3--n: The buffer
LSTRING                 dw      $ - STRING                              ; Length of STRING
STRING_TERM             db      '$',0                                   ; Prevent any kind of buffer overflow -- dollar-terminated or ASCIIZ strings
BUFF_NUM                dw      ?                                       ; Number buffer
BUFF_CHR                db      ?                                       ; Buffered character
BUFF_YYYY               dw      ?
BUFF_MM                 dw      ?
BUFF_DD                 dw      ?
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
DAYS_IN_YEAR            dw      365                                     ; Number of days in a year
DAYS_IN_MNTH            dw      30                                      ; Number of days in a year
CUR_YYYY                dw      2023                                    ; Current year in AD [1980, 2099]
CUR_MM                  dw      1                                       ; Current month [1, 12]
CUR_DD                  dw      27                                      ; Current day [1, 31]
ESEG    ENDS


CSEG    SEGMENT 'CODE'                          ; CS is of 'CODE' class
        assume  cs:CSEG, ds:DSEG, es:ESEG, ss:SSEG

;; Procedure #1
_start  PROC                                    ; Start of the main procedure _start
        mov     ax, DSEG                        ; Initialize DS
        mov     ds, ax
        mov     ax, ESEG                        ; Initialize ES
        mov     es, ax

        mov     ax, USE_REAL_DATE               ; Whether to use the real date get from DOS
        cmp     ax, 0
        je      NO_GET_DATE

        mov     ah, 2Ah                         ; DOS Get Date
        int     21h                             ;       CX: Year (1980-2099)
                                                ;       DH: Month (1-12)
                                                ;       DL: Day (1-31)
                                                ;       AL: Day of the week (0=Sun., 6=Sat.)

        mov     CUR_YYYY, cx                    ; Store current Year to DS:[CUR_YYYY]
        mov     al, dh                          ; Store current Month to DS:[CUR_MM]
        cbw
        mov     CUR_MM, ax
        mov     al, dl                          ; Store current Day to DS:[CUR_DAY]
        cbw
        mov     CUR_DD, ax

NO_GET_DATE:
; AD or BC
        push    ax                              ; Save AX

        mov     al, YYYY_IN_BC                  ; AD or BC switch
        cmp     al, 0

        pop     ax                              ; Restore AX

        je      END_CUR_YEAR_CONVERT            ; AD

        mov     ax, CUR_YYYY                    ; Convert from AD to BC
        add     ax, BC_AD_DIFF                  ; Add BC - AD = 543
        mov     CUR_YYYY, ax

END_CUR_YEAR_CONVERT:
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

; Get num people
        lea     ax, STRING_START                ; Get number of people
        push    ax
        call    get_string

        lea     si, STRING                      ; To check the input char
        cmp     BYTE PTR [si], '0'              ; Did the user input blank string?
        jle     EOP                             ; Yes, they did.

        lea     ax, STRING                      ; Convert input string to number
        push    ax
        mov     al, STRING_CHARS_GOT            ; Length of input
        cbw
        push    ax
        lea     ax, BUFF_NUM                    ; Store number to DS:[BUFF_NUM]
        push    ax
        call    atob

        mov     cx, BUFF_NUM                    ; Loop over the people
        cmp     cx, 0                           ; Invalid input
        jle     EOP

; Write line 1
        lea     ax, ASCII_SPC                   ; Newline
        push    ax
        mov     ax, 20                          ; Separate with double-whitespace
        push    ax
        mov     ax, OFILE_HANDLE
        push    ax
        call    fprint_dup_chars

        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        lea     ax, OFILE_HEADER                ; "TODAY'S DATE IS"
        push    ax
        mov     ax, LOFILE_HEADER               ; Length of "TODAY'S DATE IS"
        push    ax
        call    fprint

        lea     ax, ASCII_SPC                   ; ASCII SPACE
        push    ax
        mov     ax, 3                           ; Separate with triple-whitespace
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

; Get current date
        lea     ax, STRING_START                ; Get number of people
        push    ax
        call    get_string

        lea     ax, BUFF_YYYY                   ; Where to store Years
        push    ax
        lea     ax, BUFF_MM                     ; Where to store Months
        push    ax
        lea     ax, BUFF_DD                     ; Where to store Days
        push    ax
        lea     ax, STRING                      ; The source string
        push    ax
        call    from_date_string

; Convert current date to string
        lea     ax, STRING                      ; Destination string
        push    ax
        mov     ax, CUR_YYYY                    ; Current Year
        push    ax
        mov     ax, CUR_MM                      ; Current Month
        push    ax
        mov     ax, CUR_DD                      ; Current Day
        push    ax
        call    to_date_string

; Write current date
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        lea     ax, STRING                      ; Source string representing current date
        push    ax
        mov     ax, 10                          ; Date is 10 chars long
        push    ax
        call    fprint

; Record sep
        lea     ax, OFILE_TBL_RS                ; Table record separator (RS)
        push    ax
        mov     ax, 1                           ; Write RS once
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

; Write line 2
        push    cx                              ; Save CX

        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     cx, LOFILE_TBL_HEADER_C1        ; Length of "NAME"
        lea     dx, OFILE_TBL_HEADER_C1         ; "NAME"
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

        pop     cx                              ; Restore CX

; Header padding
        lea     ax, ASCII_SPC                   ; Pad with ASCII SPACE
        push    ax
        mov     ax, 31                          ; Padding; names can be up to 35 chars long, not counting "NAME" header
                                                ;       35 - length("NAME")
                                                ;       = 35 - 4
                                                ;       = 31 #
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

; Field sep
        lea     ax, OFILE_TBL_FS                ; Table field separator (FS)
        push    ax
        mov     ax, 3                           ; Separate with triple-FS
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

        push    cx

        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     cx, LOFILE_TBL_HEADER_C2        ; Length of "DATE OF BIRTH"
        lea     dx, OFILE_TBL_HEADER_C2         ; "DATE OF BIRTH"
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

        pop     cx

; Field sep
        lea     ax, OFILE_TBL_FS                ; Table field separator (FS)
        push    ax
        mov     ax, 3                           ; Separate with triple-FS
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

        push    cx                              ; Save CX

        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     cx, LOFILE_TBL_HEADER_C3        ; Length of "AGE"
        lea     dx, OFILE_TBL_HEADER_C3         ; "AGE"
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

        pop     cx                              ; Restore CX

; Header padding
        lea     ax, ASCII_SPC                   ; Pad with ASCII SPACE
        push    ax
        mov     ax, 23                          ; Padding;
                                                ;       length("XX YEARS XX MONTHS XX DAYS") - length("AGE")
                                                ;       = 26 - 3
                                                ;       = 23 #
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

; Write line n >= 3
; Newline
        lea     ax, OFILE_TBL_RS                ; Table record separator (RS)
        push    ax
        mov     ax, 1                           ; Separate with RS once
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

; Header written
NEXT_PERSON:
        push    cx                              ; Save CX -- loop counter

; Get name
        lea     ax, STRING_START
        push    ax
        call    get_string

; Write name directly to out file
        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     al, STRING_CHARS_GOT            ; Character read from input
        cbw
        mov     cx, ax
        lea     dx, STRING                      ; The input string
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

; Write name padding
        lea     ax, ASCII_SPC                   ; Padding with ASCII SPACE
        push    ax
        mov     ax, 35                          ; Calculate padding size
        mov     bx, cx                          ; Character read from input
        sub     ax, bx                          ; 35 - the person's name length
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

; Field sep
        lea     ax, OFILE_TBL_FS                ; Table field separator (FS)
        push    ax
        mov     ax, 3                           ; Separate with triple-FS
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

; Get Birthdate
        lea     ax, STRING_START
        push    ax
        call    get_string

; Write Birthdate directly to out file
        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     al, STRING_CHARS_GOT            ; Character read from input
        cbw
        mov     cx, ax
        lea     dx, STRING                      ; The input string
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

; Birthdate padding
        lea     ax, ASCII_SPC                   ; Newline
        push    ax
        mov     ax, 3                           ; Separate with triple-whitespace
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

; Convert input date string to numeric
        lea     ax, BUFF_YYYY                   ; Where to store Year
        push    ax
        lea     ax, BUFF_MM                     ; Where to store Month
        push    ax
        lea     ax, BUFF_DD                     ; Where to store Day
        push    ax
        lea     ax, STRING                      ; The source string
        push    ax
        call    from_date_string

; Field sep
        lea     ax, OFILE_TBL_FS                ; Table field separator (FS)
        push    ax
        mov     ax, 3                           ; Separate with triple-FS
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

; Age
; Diff Year
        mov     ax, CUR_YYYY                    ; The current Year
        mov     bx, BUFF_YYYY                   ; The input Year
        sub     ax, bx                          ; Diff
        mov     BUFF_YYYY, ax                   ; Save Diff to DS:BUFF_YYYY

; Diff Month
DIFF_MM:
        mov     ax, CUR_MM                      ; The current Month
        mov     bx, BUFF_MM                     ; The input Month
        sub     ax, bx                          ; Diff
        mov     BUFF_MM, ax                     ; Save Diff to DS:BUFF_MM

; Full Year correction
        jns     END_DIFF_MM                     ; Jump on Sign; Diff is negative -- which means that the input Month is behind the current Month

        add     ax, 12                          ; MOD 12
        mov     BUFF_MM, ax                     ; Store Month

        mov     ax, BUFF_YYYY                   ; Load the calculated Year
        dec     ax                              ; We are not calculating a full Year, then subtract Year by 1
        mov     BUFF_YYYY, ax                   ; Store the correct Year back

END_DIFF_MM:

; Diff Day
DIFF_DD:
        mov     ax, CUR_DD                      ; The current Day
        mov     bx, BUFF_DD                     ; The input Day
        sub     ax, bx                          ; Diff
        mov     BUFF_DD, ax                     ; Save Diff to DS:BUFF_DD

; Full Year correction
        jns     END_DIFF                        ; Jump on Sign; Diff is negative -- which means that the input Day is behind the current Day

        add     ax, 31                          ; MOD 31
        mov     BUFF_DD, ax                     ; Store the Day

        mov     ax, BUFF_MM                     ; Load Month
        cmp     ax, 0                           ; Check whether Year has already been corrected due to Month position
        jne     END_DIFF                        ; Year had already been corrected

        mov     ax, BUFF_YYYY                   ; Lead the calculated Year
        dec     ax                              ; We are not calculating a full Year, then subtract Year by 1
        mov     BUFF_YYYY, ax                   ; Store the correct Year back

END_DIFF:
; Clear string buffer
        mov     ax, ds                          ; The buffer is in DS
        push    ax
        lea     ax, STRING                      ; The buffer
        push    ax
        mov     ax, LSTRING                     ; Length of the buffer
        push    ax
        lea     ax, ASCII_SPC                   ; Fill with ASCII SPACE
        push    ax
        call    fill_string

; Done with the math
; Clear string buffer
        mov     ax, ds                          ; The buffer is in DS
        push    ax
        lea     ax, STRING                      ; The buffer
        push    ax
        mov     ax, LSTRING                     ; Length of the buffer
        push    ax
        lea     ax, ASCII_SPC                   ; Fill with ASCII SPACE
        push    ax
        call    fill_string

; Convert Year
        mov     ax, BUFF_YYYY                   ; Year
        push    ax
        mov     ax, 2                           ; Convert to double-digit string
        push    ax
        lea     ax, STRING                      ; The string buffer
        push    ax
        call    btoa

; Write Years
        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     cx, 2                           ; Write Year as 2 chars long string
        lea     dx, STRING                      ; The source string
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

        lea     ax, ASCII_SPC                   ; ASCII SPACE
        push    ax
        mov     ax, 1                           ; Write single space
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     cx, LOFILE_U_YEAR               ; Length of "YEARS"
        lea     dx, OFILE_U_YEAR                ; "YEARS"
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

; Clear string buffer
        mov     ax, ds                          ; The buffer is in DS
        push    ax
        lea     ax, STRING                      ; The buffer
        push    ax
        mov     ax, LSTRING                     ; Length of the buffer
        push    ax
        lea     ax, ASCII_SPC                   ; Fill with ASCII SPACE
        push    ax
        call    fill_string

; Convert Month
        mov     ax, BUFF_MM                     ; Month
        push    ax
        mov     ax, 2                           ; Convert to double-digit string
        push    ax
        lea     ax, STRING                      ; The string buffer
        push    ax
        call    btoa

; Write Months
        lea     ax, ASCII_SPC                   ; ASCII SPACE
        push    ax
        mov     ax, 1                           ; Write single space
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     cx, 2                           ; Write Month as 2 chars long string
        lea     dx, STRING                      ; The string buffer storing converted Month
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

        lea     ax, ASCII_SPC                   ; ASCII SPACE
        push    ax
        mov     ax, 1                           ; Write single space
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     cx, LOFILE_U_MNTH               ; Length of "MONTHS"
        lea     dx, OFILE_U_MNTH                ; "MONTHS"
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

; Clear string buffer
        mov     ax, ds                          ; The string buffer is in DS
        push    ax
        lea     ax, STRING                      ; The string buffer
        push    ax
        mov     ax, LSTRING                     ; Length of the string buffer
        push    ax
        lea     ax, ASCII_SPC                   ; Fill with ASCII SPACE
        push    ax
        call    fill_string

; Convert Day
        mov     ax, BUFF_DD                     ; Day
        push    ax
        mov     ax, 2                           ; Convert to double-digit string
        push    ax
        lea     ax, STRING                      ; The string buffer
        push    ax
        call    btoa

        lea     ax, ASCII_SPC                   ; ASCII SPACE
        push    ax
        mov     ax, 1                           ; Write single space
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

; Write Days
        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     cx, 2                           ; Write Day as 2 chars long string
        lea     dx, STRING                      ; The string buffer
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

        lea     ax, ASCII_SPC                   ; ASCII SPACE
        push    ax
        mov     ax, 1                           ; Write single space
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     cx, LOFILE_U_DAY                ; Length of "DAYS"
        lea     dx, OFILE_U_DAY                 ; "DAYS"
        mov     ah, 40h                         ; DOS Write Handle
        int     21h

        lea     ax, OFILE_TBL_RS                ; Table record separator (RS)
        push    ax
        mov     ax, 1                           ; Write single-RS
        push    ax
        mov     ax, OFILE_HANDLE                ; Out file handle
        push    ax
        call    fprint_dup_chars

        pop     cx                              ; \
        dec     cx                              ;  \
        cmp     cx, 0                           ;   \
        jg      JNEXT_PERSON                    ;    | Loop
        jmp     EOP                             ;    | construct
                                                ;   /
JNEXT_PERSON:                                   ;  /
        jmp     NEXT_PERSON                     ; /

        jmp     EOP                             ; Jump to End-of-procedure

ERR_OPEN_FILE:                                  ; File access error
        lea     ax, MSGERR_OPEN_FILE            ; File access error message
        push    ax
        mov     ax, 1                           ; Print with CRLF
        push    ax
        call    print

EOP:                                            ; Very end of _start procedure
; Close file
        mov     bx, OFILE_HANDLE                ; Out file handle
        mov     ah, 3Eh                         ; DOS Close Handle
        int     21h

        mov     al, 0                           ; Exit Code
        mov     ah, 4Ch                         ; DOS End Process
        int     21h
_start  ENDP                                    ; End of the main procedure _start


;; Procedure #2
; Print ASCII 'TAB' character
print_tab       PROC
        push    ax                              ; Save AX
        push    dx                              ; Save DX

        mov     dl, 9                           ; ASCII TAB
        mov     ah, 02h                         ; DOS 'Display Character' function
        int     21h

        pop     dx                              ; Restore DX
        pop     ax                              ; Restore AX
        ret
print_tab       ENDP


;; Procedure #3
; Print ASCII 'CRLF' sequence
print_crlf      PROC
        push    ax                              ; Save AX
        push    dx                              ; Save DX

        mov     dl, 13                          ; ASCII CR
        mov     ah, 02h                         ; DOS 'Display Character' function
        int     21h
        mov     dl, 10                          ; ASCII LF
        mov     ah, 02h                         ; DOS 'Display Character' function
        int     21h

        pop     dx                              ; Restore DX
        pop     ax                              ; Restore AX
        ret
print_crlf      ENDP


;; Procedure #4
;; Filling string in upward direction -- lower to higher address -- with a character
;       push    BYTE PTR []                     ; Pointer to segment containing string
;       push    BYTE PTR []                     ; Pointer to string
;       push    WORD                            ; Length of string
;       push    BYTE PTR []                     ; Pointer to filling char
fill_string     PROC
        push    ax                              ; Save AX
        push    cx                              ; Save CX
        push    si                              ; Save SI
        push    di                              ; Save DI
        push    bp                              ; Save BP
        push    ds                              ; Save DS
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local stack frame

        mov     ds, [bp+20]                     ; Pointer to destination string segment
        mov     di, [bp+18]                     ; Pointer to destination string
        mov     cx, [bp+16]                     ; String length
        mov     si, [bp+14]                     ; Filling character

FILL_STRING_NEXT:
        mov     al, BYTE PTR [si]               ; The filling character
        mov     [di], al                        ; Write character to string
        inc     di                              ; Advance to the next string index

        loop    FILL_STRING_NEXT

        mov     sp, bp                          ; Step out of local stack frame
        pop     ds                              ; Restore DS
        pop     bp                              ; Restore BP
        pop     di                              ; Restore DI
        pop     si                              ; Restore SI
        pop     cx                              ; Restore CX
        pop     ax                              ; Restore AX
        ret     8                               ; This procedure use 4 stack elements -- 2 bytes each
fill_string     ENDP

;; Procedure #5
;; Binary to ASCII String
; ARGUMENTS:
;       push    WORD                            ; Signed number to be converted
;       push    WORD                            ; Length of resulting string
;       push    BYTE PTR []                     ; String PTR for resulting string
btoa    PROC
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
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


;; Procedure #6
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


;; Procedure #7
; Print/Display String (Function 09H wrapper)
; ARGUMENTS:
;       push    BYTE PTR []                     ; [BP+6]  Pointer to string, ending with '$'
;       push    BYTE                            ; [BP+4]  CRLF switch; if set to 1, CRLF is printed at the end of the string,
;                                               ;               otherwise, no CRLF is printed.
print   PROC
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local stack frame

        mov     ah, 09h                         ; DOS 'Display String' function
        mov     dx, [bp+6]                      ; Second argument; String to be printed
        int     21h

        mov     dx, [bp+4]                      ; First argument; CRLF switch
        cmp     dx, 0                           ; If the caller requests CRLF
        je      EO_PROC                         ; No CRLF requested from the caller

        mov     dl, 13                          ; \
        mov     ah, 02h                         ;  \
        int     21h                             ;   \
                                                ;    * Newline
        mov     dl, 10                          ;   /
        mov     ah, 02h                         ;  /
        int     21h                             ; /

EO_PROC:                                        ; End-of-procedure
        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        ret     4                               ; This procedure uses 2 stack elements -- 2 bytes each
print   ENDP


;; Procedure #8
; Write/Display String to File or Console (Function 09H, 40H wrapper)
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
        sub     sp, 2                           ; Step into local stack frame

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
        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        pop     dx                              ; Restore DX
        pop     cx                              ; Restore CX
        pop     bx                              ; Restore BX
        pop     ax                              ; Restore AX
        ret     6                               ; This procedure uses 3 stack elements -- 2 bytes each
fprint  ENDP


;; Procedure #9
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
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local stack frame

        mov     bx, [bp+12]                     ; File handle
        mov     cx, 1                           ; Bytes to write
        mov     dx, [bp+16]                     ; Pointer to char

        mov     ax, [bp+14]                     ; Loop counter

FPRINT_DUP_CHARS_NEXT:
        push    ax                              ; Save AX to local stack

        mov     ah, 40h                         ; DOS Write Handle
        int     21h

        pop     ax                              ; Restore AX from local stack
        dec     ax                              ; Update loop counter
        cmp     ax, 0                           ; Done?
        jg      FPRINT_DUP_CHARS_NEXT           ; No

        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        pop     dx                              ; Restore DX
        pop     cx                              ; Restore CX
        pop     bx                              ; Restore BX
        pop     ax                              ; Restore AX
        ret     6                               ; This procedure use 3 stack elements -- 2 bytes each
fprint_dup_chars   ENDP


;; Procedure #10
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

        mov     dx, [bp+10]                     ; Get the destination string address, store to DX

        mov     ah, 0Ah                         ; DOS Buffered Keyboard Input function
        int     21h

        mov     bx, 0                           ; Clear BX
        mov     si, dx                          ; Use SI for better interpretation -- SI in an index register

        mov     bl, [si+1]                      ; Get number of input chars, not counting CR
        mov     WORD PTR [bx+si+2], '$'         ; Terminate the input string with '$'

        mov     dl, 13                          ; \
        mov     ah, 02h                         ;  \
        int     21h                             ;   \
                                                ;    * New input line
        mov     dl, 10                          ;   /
        mov     ah, 02h                         ;  /
        int     21h                             ; /

        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        pop     si                              ; Restore SI
        pop     dx                              ; Restore DX
        pop     bx                              ; Restore BX
        ret     2                               ; This procedure uses 1 stack element -- 2 bytes each
get_string      ENDP


;; Procedure #11
;; Parse string representation of date
;       push    WORD PTR []                     ; Pointer to a buffer to store Year
;       push    WORD PTR []                     ; Pointer to a buffer to store Month
;       push    WORD PTR []                     ; Pointer to a buffer to store Day
;       push    BYTE PTR []                     ; Pointer to string representing a date in dd/mm/yyyy format
from_date_string        PROC
        push    ax                              ; Save AX
        push    dx                              ; Save DX
        push    si                              ; Save SI
        push    di                              ; Save DI
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local stack frame

        mov     si, [bp+12]                     ; Source string buffer

; Convert Day
        mov     ax, si                          ; The source string
        push    ax
        mov     ax, 2                           ; Day lays on 2 chars long
        push    ax
        mov     ax, [bp+14]                     ; Day buffer
        push    ax
        call    atob

; Convert Month
        mov     ax, si                          ; The source string
        add     ax, 3                           ; "DD/MM/YYYY"
                                                ;     ^
        push    ax
        mov     ax, 2                           ; Month lays on 2 chars long
        push    ax
        mov     ax, [bp+16]                     ; Month buffer
        push    ax
        call    atob

; Convert Year
        mov     ax, si                          ; The source string
        add     ax, 6                           ; "DD/MM/YYYY"
                                                ;        ^
        push    ax
        mov     ax, 4                           ; Year lays on 4 chars long
        push    ax
        mov     ax, [bp+18]                     ; Year buffer
        push    ax
        call    atob

        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        pop     di                              ; Restore DI
        pop     si                              ; Restore SI
        pop     dx                              ; Restore DX
        pop     ax                              ; Restore AX
        ret     8                               ; This procedure use 4 stack elements -- 2 bytes each
from_date_string        ENDP


;; Procedure #12
;; Convert date to string
;       push    BYTE PTR []                     ; Destination string
;       push    WORD                            ; Year
;       push    WORD                            ; Month
;       push    WORD                            ; Day
to_date_string  PROC
        push    ax
        push    bx
        push    cx                              ; Save CX
        push    dx                              ; Save DX
        push    bp                              ; Save BP
        mov     bp, sp                          ; Copy SP to BP
        sub     sp, 2                           ; Step into local stack frame

; DD
        mov     ax, [bp+12]                     ; Day
        push    ax
        mov     ax, 2                           ; Day is printed in 2 digits
        push    ax
        mov     ax, [bp+18]                     ; Destination string
        push    ax
        call    btoa

        mov     ax, [bp+12]                     ; Get numeric Day
        cmp     ax, 10                          ; Does it need padding
        jge     NO_DD_PAD                       ; No, it does not.

        mov     bx, [bp+18]                     ; "?X/??/????"
                                                ;  ^
        mov     BYTE PTR [bx], '0'              ; The destination string now becomes "0X/??/????"

NO_DD_PAD:
        add     bx, 2                           ; "XX????????"
                                                ;    ^
        mov     BYTE PTR [bx], '/'              ; Insert '/'
        add     bx, 1                           ; Alter the passed destination string starting address
        mov     [bp+18], bx                     ; Store the new starting address back to argument stack

; MM
        mov     ax, [bp+14]                     ; Month
        push    ax
        mov     ax, 2                           ; Month is printed in 2 digits
        push    ax
        mov     ax, [bp+18]                     ; Destination string
        push    ax
        call    btoa

        mov     ax, [bp+14]                     ; Get numeric Month
        cmp     ax, 10                          ; Does it need padding
        jge     NO_MM_PAD                       ; No, it does not.

        mov     bx, [bp+18]                     ; "XX/?X/????"
                                                ;     ^
        mov     BYTE PTR [bx], '0'              ; The destination string now becomes "0X/0X/????"

NO_MM_PAD:
        add     bx, 2                           ; "XX/XX?????"
                                                ;       ^
        mov     BYTE PTR [bx], '/'              ; Insert '/'
        add     bx, 1                           ; Alter the passed destination string starting address
        mov     [bp+18], bx                     ; Store the new starting address back to argument stack

; YYYY
        mov     ax, [bp+16]                     ; Year
        push    ax
        mov     ax, 4                           ; Year is printed in 4 digits
        push    ax
        mov     ax, [bp+18]                     ; Destination string
        push    ax
        call    btoa

EOP_TO_DATE_STRING:                             ; End-of-procedure
        mov     sp, bp                          ; Step out of local stack frame
        pop     bp                              ; Restore BP
        pop     dx                              ; Restore DX
        pop     cx                              ; Restore CX
        pop     bx                              ; Restore BX
        pop     ax                              ; Restore AX
        ret     6                               ; This procedure uses 3 stack elements -- 2 bytes each
to_date_string  ENDP
CSEG    ENDS
        END     _start                          ; Initialize CS and IP
