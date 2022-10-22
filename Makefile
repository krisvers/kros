DIR = $(shell pwd)
CC := gcc
CFLAGS := -I kernel/include -O3 -nostdlib -m32 -march=i386 -fno-pie -fno-stack-protector -ffreestanding -Wall
LD := ld
LDFLAGS := -m elf_i386 -T $(DIR)/linker.ld -nostdlib
ASM := nasm

.PHONY: all build clean image disk qemu proper dump

all: qemu

build: $(DIR)/build/kernel/main.o $(DIR)/build/kernel/tty.o $(DIR)/build/kernel/video.o $(DIR)/build/kernel/string.o $(DIR)/build/kernel/stdlib.o $(DIR)/build/kernel/keyboard.o $(DIR)/build/kernel/stdio.o $(DIR)/build/bin/boot.bin $(DIR)/build/bin/kernel.bin

#	bootloader
	
$(DIR)/build/bin/boot.bin: $(DIR)/boot/boot.asm
	$(ASM) $(DIR)/boot/boot.asm -f bin -o $(DIR)/build/bin/boot.bin

#	kernel

$(DIR)/build/kernel/main.o: $(DIR)/kernel/main.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/main.c -o $(DIR)/build/kernel/main.o

#	libs	

$(DIR)/build/kernel/video.o: $(DIR)/kernel/video.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/video.c -o $(DIR)/build/kernel/video.o

$(DIR)/build/kernel/string.o: $(DIR)/kernel/string.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/string.c -o $(DIR)/build/kernel/string.o

$(DIR)/build/kernel/stdlib.o: $(DIR)/kernel/stdlib.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/stdlib.c -o $(DIR)/build/kernel/stdlib.o

$(DIR)/build/kernel/keyboard.o: $(DIR)/kernel/keyboard.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/keyboard.c -o $(DIR)/build/kernel/keyboard.o

$(DIR)/build/kernel/stdio.o: $(DIR)/kernel/stdio.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/stdio.c -o $(DIR)/build/kernel/stdio.o

$(DIR)/build/kernel/tty.o: $(DIR)/kernel/tty.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/tty.c -o $(DIR)/build/kernel/tty.o

$(DIR)/build/bin/kernel.bin: $(DIR)/build/kernel/*
	$(LD) $(LDFLAGS) --oformat binary $(DIR)/build/kernel/* -o $(DIR)/build/bin/kernel.bin

image: build
	dd if=build/bin/boot.bin of=build/img/disk.img
	dd if=build/bin/kernel.bin of=build/img/disk.img conv=notrunc seek=512 bs=1

qemu: image
	qemu-system-x86_64 -fda build/img/disk.img

dump:
	hexcat build/img/disk.img

proper:
	mkdir -p build/kernel/
	mkdir -p build/bin/
	mkdir -p build/img/

clean:
	rm -rf build
	mkdir -p build/kernel/
	mkdir -p build/bin/
	mkdir -p build/img/
