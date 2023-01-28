.386
.model flat, stdcall

title	Potsawat Thinkanwatthana
subttl	6410451199

.stack 4096
ExitProcess proto,dwExitCode:dword

.data
	RATE	DW		1200
	FRIEND	DB		5
	NET		DW		?
	PAY		DW		?

.code
_start PROC
	mov		ax,		RATE
	mov		bl,		FRIEND
	mul		bx
	mov		NET,	ax
	
	mov		dx,		0
	mov		bx,		0
	mov		bl,		FRIEND
	sub		bl,		1
	div		bx
	mov		PAY,	ax

	invoke	ExitProcess, 0
_start ENDP
END _start
