BITS 64

	global asm_strcasecmp	; global function

	section .text

asm_strcasecmp:
	push rbp		; push rbp to stack
	mov rbp, rsp		; copy rsp to rbp
	push rcx
	push r8
	push r9
	xor rcx, rcx
	xor r8, r8
	xor r9, r9
	xor eax, eax

strcasecmp_loop:
	mov r8b, [rdi + rcx]
	mov r9b, [rsi + rcx]
	cmp r8b, 65
	jl check_9
	cmp r8b, 90
	jg check_9
	add r8b, 32

check_9:
	cmp r9b, 65
	jl counter
	cmp r9b, 90
	jg counter
	add r9b, 32

counter:
	mov eax, r8d
	sub eax, r9d
	test eax, eax
	jnz end
	test r8b, r8b
	jz end
	inc rcx
	jmp strcasecmp_loop

end:
	pop r9
	pop r8
	pop rcx
	mov rsp, rbp
	pop rbp
	ret
