.model flat

.code

pureasm PROC C

	push ebp
	mov ebp, esp

	mov eax, 7
	mov ecx, 0
	cpuid

	mov eax, 0

	bt ebx, 14
	rcl eax, 1

	push eax
	mov eax, 1
	cpuid
	pop eax

	bt edx, 28
	rcl eax, 1

	bt edx, 26
	rcl eax, 1

	bt edx, 25
	rcl eax, 1

	bt edx, 0
	rcl eax, 1

	mov esp, ebp
	pop ebp

	ret

pureasm ENDP

END
