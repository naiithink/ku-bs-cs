TITLE   Potsawat Thinkanwatthana
SUBTTL  6410451199


SSEG    SEGMENT STACK                           ; Initialize SS
        DW      64 DUP (?)
SSEG    ENDS


; DS stores printable data
DSEG    SEGMENT
DSEG    ENDS


; ES stores dynamic data
ESEG    SEGMENT
CUR_YYYY                DW      ?                       ; Current year in AD [1980, 2099]
CUR_MM                  DB      ?                       ; Current month [1, 12]
CUR_DD                  DB      ?                       ; Current day [1, 31]
ESEG    ENDS


CSEG    SEGMENT 'CODE'                          ; CS is of 'CODE' class
        ASSUME  cs:CSEG,
                ds:DSEG, es:ESEG,
                ss:SSEG

_start  PROC                                    ; Start of the main procedure _start
        mov     ax, DSEG                        ; Initialize DS
        mov     ds, ax
        mov     ax, ESEG                        ; Initialize ES
        mov     es, ax

        

        mov     al, 0
        mov     ah, 4Ch
        int     21h
_start  ENDP                                    ; End of the main procedure _start


CSEG    ENDS
        END     _start                          ; Initialize CS and IP
