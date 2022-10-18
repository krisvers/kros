[bits 16]
jmp short kernel

%include 'vid.asm'

kernel:
	call initscreen

	call clear
	mov si, msg
	call print
	
	jmp $

msg db "Hello, World!", 0x3
times 1024-($-$$) db 0
