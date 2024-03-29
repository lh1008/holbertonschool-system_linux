BITS 64

	global asm_strstr

	section .text

asm_strstr:
	push rbp
	mov rbp, rsp
	push r8
	push r9
	push rcx
	xor rax, rax
	xor rcx, rcx
	xor r8, r8
	xor r9, r9
	test rsi, rsi
	jz compare
	mov r9b, BYTE [rsi]
	test r9b, r9b
	jz compare
	test rdi, rdi
	jz end

loop_strstr:
	mov r8b, BYTE [rdi + rcx]
	mov r9b, BYTE [rsi + rcx]
	test r8b, r8b
	jz compare
	test r9b, r9b
	jz compare
	cmp r8b, r9b
	je equal
	inc rdi
	xor rcx, rcx
	jmp loop_strstr

equal:
	inc rcx
	jmp loop_strstr

compare:
	test r9b, r9b
	jnz end
	mov rax, rdi
end:
	pop rcx
	pop r9
	pop r8
	mov rsp, rbp
	pop rbp
	ret
