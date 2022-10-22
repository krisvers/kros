DIR = $(shell pwd)
CC := gcc
CFLAGS := -I kernel/include -O3 -nostdlib -m32 -march=i386 -fno-pie -fno-stack-protector -ffreestanding -Wall
LD := ld
LDFLAGS := -m elf_i386 -T $(DIR)/linker.ld -nostdlib
ASM := nasm

.PHONY: all build clean image disk qemu proper dump

all: clean qemu

build:
	$(ASM) $(DIR)/boot/boot.asm -f bin -o $(DIR)/build/bin/boot.bin
	$(CC) $(CFLAGS) -c kernel/main.c -o $(DIR)/build/kernel/main.o
	$(CC) $(CFLAGS) -c kernel/video.c -o $(DIR)/build/kernel/video.o
	$(CC) $(CFLAGS) -c kernel/terminal.c -o $(DIR)/build/kernel/terminal.o
	$(LD) $(LDFLAGS) --oformat binary $(DIR)/build/kernel/* -o build/bin/kernel.bin

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
