.model flat
.code

fpur dd 00000001b
sser dd 00000010b
sse2r dd 00000100b
httr dd 00001000b
mpxr dd 00010000b
pureasm PROC C

	push ebp
	mov ebp, esp

	mov eax, 1
	cpuid
	mov eax, 0
FPU:
	bt edx, 0
	setc cl
	cmp cl,1
	jnz SSE
	add eax, fpur
SSE:
	bt edx, 25
	setc cl
	cmp cl,1
	jnz SSE2
	add eax, sser
SSE2:
	bt edx, 26
	setc cl
	cmp cl,1
	jnz HTT
	add eax, sse2r
HTT:
	bt edx, 28
	setc cl
	cmp cl,1
	jnz MPX
	add eax, httr
MPX:	
	push eax

	mov eax, 7
	mov ecx, 0
	cpuid

	pop eax

	bt ebx, 15
	setc cl
	cmp cl,1
	jnz endl
	add eax, mpxr
	
endl:
	mov esp, ebp
	pop ebp
	ret 

pureasm ENDP

END

