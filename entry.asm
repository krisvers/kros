[bits 32]
org 0x1000

entry:
	mov ah, 0x02
	mov al, 'K'
	mov word [0xB8000], ax

	cli
	hlt

msg: db "We are in 32-bit kernel land.", 0
times 512-($-$$) db 0
