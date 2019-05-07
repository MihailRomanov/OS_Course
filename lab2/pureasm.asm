.model flat
.data

	FPU EQU 1b
	SSE EQU 10b
	SSE2 EQU 100b
	HTT EQU 1000b
	MPX EQU 10000b

.code

pureasm PROC C

	push ebp
	mov ebp, esp

	mov eax, 1
	cpuid

	mov eax, 0

	bt edx, 0
	jnc m1
	add eax, FPU

	m1: 
	bt edx, 25
	jnc m2
	add eax, SSE

	m2: 
	bt edx, 26
	jnc m3
	add eax, SSE2

	m3: 
	bt edx, 28
	jnc m4
	add eax, HTT

	m4:
	push eax
	mov eax, 7
	mov ecx, 0
	cpuid

	pop eax
	bt ebx, 14
	jnc exit
	add eax, MPX
	
	exit:

	mov esp, ebp
	pop ebp

	ret 

pureasm ENDP

END