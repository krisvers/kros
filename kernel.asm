[bits 16]
org 0x1000
jmp short kernel

%include 'vid.asm'

kernel:
	call initscreen
	call clear

	mov si, msg
	xor bx, bx
	call puts
	
	jmp $

msg: db "Kernel moment!", 0
times 1024-($-$$) db 0
