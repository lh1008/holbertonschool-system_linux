BITS 64

	global asm_memcpy

	section .text

asm_memcpy:
	push rbp
	mov rbp, rsp
	push rbx

loop_mem:
	test rdx, rdx
	jz end
	mov bl, [rsi]
	mov [rdi], bl
	inc rdi
	inc rsi
	dec rdx
	jmp loop_mem

end:
	pop rbx
	mov rsp, rbp
	pop rbp
	ret
