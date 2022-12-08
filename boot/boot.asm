[bits 16]
org 0x7C00

start:
	jmp .skip_bpb ; Workaround for some BIOSes that require this stub
    nop

    ; Some BIOSes will do a funny and decide to overwrite bytes of code in
    ; the section where a FAT BPB would be, potentially overwriting
    ; bootsector code.
    ; Avoid that by filling the BPB area with dummy values.
    ; Some of the values have to be set to certain values in order
    ; to boot on even quirkier machines.
    ; Source: https://github.com/freebsd/freebsd-src/blob/82a21151cf1d7a3e9e95b9edbbf74ac10f386d6a/stand/i386/boot2/boot1.S
  .bpb:
    times 3-($-$$) db 0
    .bpb_oem_id:            db "PONG    "
    .bpb_sector_size:       dw 512
    .bpb_sects_per_cluster: db 0
    .bpb_reserved_sects:    dw 0
    .bpb_fat_count:         db 0
    .bpb_root_dir_entries:  dw 0
    .bpb_sector_count:      dw 0
    .bpb_media_type:        db 0
    .bpb_sects_per_fat:     dw 0
    .bpb_sects_per_track:   dw 18
    .bpb_heads_count:       dw 2
    .bpb_hidden_sects:      dd 0
    .bpb_sector_count_big:  dd 0
    .bpb_drive_num:         db 0
    .bpb_reserved:          db 0
    .bpb_signature:         db 0
    .bpb_volume_id:         dd 0
    .bpb_volume_label:      db "PONG       "
    .bpb_filesystem_type:   times 8 db 0\

	.skip_bpb:
		cli
		cld
		jmp .init

	.init:
; setup stack
	cli
	mov bp, 0x7C00
	mov sp, bp
	xor ax, ax
	mov ss, ax
	sti

; reset disk
	mov ah, 0x00
	mov dl, 0x80	; floppy 1
	int 0x13

	xor ax, ax
	mov ds, ax

; this bootloader tries reading and running from multiple disks until they don't return error
	
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
	jnc .vid
	clc

	mov ah, 0x02	; read mode for int 0x13
	mov al, 0x24	; sectors to read (sector = 512 bytes)
	mov ch, 0x00	; cylinder #
	mov cl, 0x02	; sector #
	mov dh, 0x00	; head #
	mov dl, 0x01	; drive #
	xor bx, bx
	mov es, bx		; 
	mov bx, 0x1000	; [es:bx] = [0x0:0x1000]; where we load the kernel
	int 0x13
	jnc .vid
	clc

	mov ah, 0x02	; read mode for int 0x13
	mov al, 0x24	; sectors to read (sector = 512 bytes)
	mov ch, 0x00	; cylinder #
	mov cl, 0x02	; sector #
	mov dh, 0x00	; head #
	mov dl, 0x02	; drive #
	xor bx, bx
	mov es, bx		; 
	mov bx, 0x1000	; [es:bx] = [0x0:0x1000]; where we load the kernel
	int 0x13
	jnc .vid
	clc

	mov ah, 0x02	; read mode for int 0x13
	mov al, 0x24	; sectors to read (sector = 512 bytes)
	mov ch, 0x00	; cylinder #
	mov cl, 0x02	; sector #
	mov dh, 0x00	; head #
	mov dl, 0x80	; drive #
	xor bx, bx
	mov es, bx		; 
	mov bx, 0x1000	; [es:bx] = [0x0:0x1000]; where we load the kernel
	int 0x13
	jnc .vid
	clc

	mov ah, 0x02	; read mode for int 0x13
	mov al, 0x24	; sectors to read (sector = 512 bytes)
	mov ch, 0x00	; cylinder #
	mov cl, 0x02	; sector #
	mov dh, 0x00	; head #
	mov dl, 0x81	; drive #
	xor bx, bx
	mov es, bx		; 
	mov bx, 0x1000	; [es:bx] = [0x0:0x1000]; where we load the kernel
	int 0x13
	jnc .vid
	clc

	mov ah, 0x02	; read mode for int 0x13
	mov al, 0x24	; sectors to read (sector = 512 bytes)
	mov ch, 0x00	; cylinder #
	mov cl, 0x02	; sector #
	mov dh, 0x00	; head #
	mov dl, 0x82	; drive #
	xor bx, bx
	mov es, bx		; 
	mov bx, 0x1000	; [es:bx] = [0x0:0x1000]; where we load the kernel
	int 0x13
	jnc .vid
	clc

	mov ah, 0x02	; read mode for int 0x13
	mov al, 0x24	; sectors to read (sector = 512 bytes)
	mov ch, 0x00	; cylinder #
	mov cl, 0x02	; sector #
	mov dh, 0x00	; head #
	mov dl, 0x83	; drive #
	xor bx, bx
	mov es, bx		; 
	mov bx, 0x1000	; [es:bx] = [0x0:0x1000]; where we load the kernel
	int 0x13
	jnc .vid
	clc

	mov ah, 0x02	; read mode for int 0x13
	mov al, 0x24	; sectors to read (sector = 512 bytes)
	mov ch, 0x00	; cylinder #
	mov cl, 0x02	; sector #
	mov dh, 0x00	; head #
	mov dl, 0xE0	; drive #
	xor bx, bx
	mov es, bx		; 
	mov bx, 0x1000	; [es:bx] = [0x0:0x1000]; where we load the kernel
	int 0x13
	jnc .vid
	clc
	
	.vid:
; setup video mode
	;	0x03
	mov ah, 0x00
	mov al, 0x03
	int 0x10

; A20
	;	compute A20 line (i just used the BIOS)
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

;	pack with zeroes
times 510-($-$$) db 0
;	magic number
dw 0xAA55
