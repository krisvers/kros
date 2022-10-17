[bits 16]
jmp short kernel

kernel:
	mov ah, 0x03
	mov al, 0x00
	int 0x10

	call print
	
	jmp $

print:
	xor ax, ax
	mov di, ax
	mov ax, 0xB800
	mov es, ax
	mov ch, 0x02
	mov cl, 0x01
	
	.loop:
		mov [es:di], cx
		cmp cl, 0x00
		je .done

		inc di
		inc cl

		jmp .loop

	.done:
		ret

times 512-($-$$) db 0
