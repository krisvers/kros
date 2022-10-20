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

;
;	si: pointer to string
;	bx: address offset
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

;
;	si: pointer to string
prints:
	push si
	push ax
	push bx

	mov ax, CURSOR
	mov di, ax
	mov ax, 0xB800
	mov es, ax
	mov ah, 0x02

	.loop:
		lodsb
		or al, al
		je .done
	
		cmp al, 0x0D
		je .newline
		
		stosw

		inc CURSOR
		inc CURSOR

		jmp .loop

	.newline:
		mov CURSOR, 0x0
		inc LINE

		mov bx, CURSOR
		mov di, bx

	.done:
		pop ax
		pop si

		ret
	

initscreen:
	mov ah, 0x00
	mov al, 0x03
	int 0x10

	ret

section .data
CURSOR: dw 0x0000
LINE: dw 0x0000
