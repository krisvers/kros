[bits 16]
org 0x7C00

start:
; reset disk
	mov ah, 0x00
	mov dl, 0x00	; floppy 1
	int 0x13

	xor ax, ax
	mov ds, ax
	
; read next sector and run it (not good practice)
	mov ah, 0x02
	mov al, 0x01
	mov ch, 0x00
	mov cl, 0x02
	mov dh, 0x00
	mov dl, 0x00
	xor bx, bx
	mov es, bx
	mov bx, 0x7E00
	int 0x13

; jump to kernel land
	jmp 0x7E00

	jmp $

times 510-($-$$) db 0
dw 0xAA55
