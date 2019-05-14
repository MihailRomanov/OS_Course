.model flat

.data
fpu dd 00000001b
sse dd 00000010b
sse2 dd 00000100b
htt dd 00001000b
mpx dd 00010000b

.code
pureasm PROC C

	push ebp
	mov ebp, esp

	mov eax, 1
	cpuid

	mov eax, 0

	bt edx, 0
	jnc sse
	add eax, fpu

sse: 
	bt edx, 25
	jnc  sse2
	add eax, sse

sse2: 
	bt edx, 26
	jnc htt
	add eax, sse2

htt: 
	bt edx, 28
	jnc mpx
	add eax, htt

mpx:
	push eax
	mov eax, 7
	mov ecx, 0
	cpuid
	pop eax
	bt ebx, 14
	jnc endl
	add eax, mpx
	
endl:
	mov esp, ebp
	pop ebp
	ret 

pureasm ENDP
END 