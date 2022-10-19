[bits 16]
jmp short kernel

%include 'vid.asm'

kernel:
	call initscreen

	call clear
	mov ax, 'a'
	mov bx, 0x00
	call putc
	mov ax, 'b'
	mov bx, 0x04
	call putc
	
	jmp $

msg: db "Hello, World!", 0x0A, 0x0D, 0
times 1024-($-$$) db 0
