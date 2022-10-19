[bits 16]
org 0x7C00

start:
; setup stack
	mov bp, 0x7C00
	mov sp, bp
	xor ax, ax
	mov ss, ax

; reset disk
	mov ah, 0x00
	mov dl, 0x00	; floppy 1
	int 0x13

	xor ax, ax
	mov ds, ax
	
; read next sector and run it (not good practice)
	mov ah, 0x02	; read mode for int 0x13
	mov al, 0x02	; sectors to read (sector = 512 bytes)
	mov ch, 0x00	; cylinder #
	mov cl, 0x02	; sector #
	mov dh, 0x00	; head #
	mov dl, 0x00	; drive #
	xor bx, bx
	mov es, bx		; 
	mov bx, 0x1000	; [es:bx] = [0x0:0x1000]; where we load the kernel
	int 0x13

; jump to kernel land
	jmp 0x1000

	jmp $

times 510-($-$$) db 0
dw 0xAA55
