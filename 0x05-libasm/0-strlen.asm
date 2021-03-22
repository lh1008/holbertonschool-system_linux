BITS 64
	global asm_strlen

	section .text

asm_strlen:
	push rbp		; push rbp to stack
	mov rbp, rsp		; move what's in rsp to rbp
	mov rax, 0
	jmp check

body:
	inc rax
	inc rdi

check:
	cmp byte [rdi], 0
	jne body
	mov rsp, rbp
	pop rbp
	ret
