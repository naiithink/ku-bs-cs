TITLE POTSAWAT THINKANWATTHANA
SUBTTL 6410451199
STACK   SEGMENT    STACK
        DW      64 DUP(0)
STACK   ENDS

DATA    SEGMENT
NUM     DB      10,25
SUM     DB      0
DATA    ENDS

CODE    SEGMENT
        ASUME   CS:CODE, DS:DATA,SS:STACK
FIRST   PROC
        MOV AX,DATA     ;initialize DS
        MOV DS,AX        
        MOV AL,NUM      ;copy first number into AL
        MOV BL,NUM+1    ;copy second number into BL
        ADD AL,BL       ;add two numbers
        MOV SUM,AL      ;put result in data segment
        MOV AH,4CH      ;return to DOS
        INT 21H
FIRST   ENDP
CODE    ENDS
        END FIRST
