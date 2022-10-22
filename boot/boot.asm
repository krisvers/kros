[bits 16]
org 0x7C00

start:
; setup stack
	cli
	mov bp, 0x7C00
	mov sp, bp
	xor ax, ax
	mov ss, ax
	sti

; reset disk
	mov ah, 0x00
	mov dl, 0x00	; floppy 1
	int 0x13

	xor ax, ax
	mov ds, ax
	
; read next sector and run it (not good practice)
	mov ah, 0x02	; read mode for int 0x13
	mov al, 0x24	; sectors to read (sector = 512 bytes)
	mov ch, 0x00	; cylinder #
	mov cl, 0x02	; sector #
	mov dh, 0x00	; head #
	mov dl, 0x00	; drive #
	xor bx, bx
	mov es, bx		; 
	mov bx, 0x1000	; [es:bx] = [0x0:0x1000]; where we load the kernel
	int 0x13

; setup video mode
	mov ah, 0x00
	mov al, 0x03
	int 0x10

; A20
	mov ax, 0x2403
	int 0x15

; compute gdtr
	xor eax, eax
	mov ax, ds ; segment
	shl eax, 4 ; multiply by 16
	add eax, GDT ; add offset
	mov [gdtr + 2], eax ; base
	mov eax, GDT_end ; compute limit
	sub eax, GDT
	sub eax, 1
	mov [gdtr], ax

; load GDT
	cli
	lgdt [gdtr]
	mov eax, cr0
	or ax, 1 ; set protection enable bit
	mov cr0, eax

; set up segment registers
	mov ax, 0x10
	mov ds, ax
	mov fs, ax
	mov gs, ax
	mov es, ax
	mov ss, ax
	mov esp, 0x7FFFF ; stack pointer at ~511KiB

	jmp dword 0x8:0x1000

GDT:
    db 0, 0, 0, 0, 0, 0, 0, 0 ; null
    db 0xFF, 0xFF, 0x0, 0x0, 0x0, 10011010b, 11001111b, 0x0 ; Code segment
    db 0xFF, 0xFF, 0x0, 0x0, 0x0, 10010011b, 11001111b, 0x0 ; Data segment
GDT_end:

gdtr:
    dw 0 ; limit
    dd 0 ; base

times 510-($-$$) db 0
dw 0xAA55
