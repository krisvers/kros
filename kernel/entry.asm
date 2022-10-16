[bits 16]
org 0x1000

entry:
	call initscreen
	call clear

	mov si, msg
	xor bx, bx
	call puts

	cli
	hlt

clear:
	xor ax, ax			;
	mov di, ax			; will write to [es:di]
	mov ax, 0xB800			; so we set it as [0xB800:0x0] because the flat address is out of our 64kb
	mov es, ax			;
	xor cx, cx
	xor ax, ax

	.loop:
		cmp ax, 80*25
		je .done
		mov di, ax
		mov [es:di], cx
		inc ax

		jmp .loop

	.done:
		ret

;
;	ax: char
;	bx: address
;

putc:
	push ax
	push bx
	
	mov di, bx
	mov bx, 0xB800
	mov es, bx
	mov ah, 0x02

	mov word [es:di], ax

	pop bx
	pop ax
	ret

puts:
	push si
	push ax
	push bx

	mov di, bx
	mov bx, 0xB800
	mov es, bx

	mov ah, 0x02

	.loop:
		lodsb
		or al, al
		je .done
		
		stosw

		jmp .loop

	.done:
		pop bx
		pop ax
		pop si
		ret

initscreen:
	mov ah, 0x00
	mov al, 0x03
	int 0x10

	ret

msg: db "We are in 16-bit kernel land.", 0
times 2048-($-$$) db 0
