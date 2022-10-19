[bits 16]
clear:
	xor ax, ax			;
	mov di, ax			; will write to [es:di]
	mov ax, 0xB800		; so we set it as [0xB800:0x0] because the flat address is out of our 64kb
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

print: 
	push si
	push ax
	push bx
	
	xor bx, bx
	mov di, bx			; es = 0xB800, di = ax
	mov bx, 0xB800		; [0xB800:0x0] video memory address
	mov es, bx			;
	mov ah, 0x02		; color
	
	.loop:
		lodsb
		or al, al
		je .done
		mov word [es:di], ax

		inc di
		inc di

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
