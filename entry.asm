[bits 16]
org 0x1000
jmp short entry

%include 'stdio.asm'

entry:
	call initscreen
	call clear

	mov si, msg
	xor bx, bx
	call puts

	cli
	hlt

msg: db "We are in 16-bit kernel land.", 0
times 512-($-$$) db 0
