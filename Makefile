DIR = $(shell pwd)
CC := gcc
CFLAGS := -I kernel/include -O3 -nostdlib -m32 -march=i386 -fno-pie -fno-stack-protector -ffreestanding -Wall
LD := ld
LDFLAGS := -m elf_i386 -T $(DIR)/linker.ld -nostdlib
ASM := nasm

.PHONY: all build clean image disk qemu proper dump

all: clean qemu

build:
	$(ASM) $(DIR)/boot/boot.asm -f bin -o $(DIR)/build/boot.bin
	$(CC) $(CFLAGS) -c kernel/main.c -o $(DIR)/build/main.o
	$(CC) $(CFLAGS) -c kernel/video.c -o $(DIR)/build/video.o
	$(LD) $(LDFLAGS) --oformat binary $(DIR)/build/main.o $(DIR)/build/video.o -o build/kernel.bin

image: build
	dd if=build/boot.bin of=build/disk.img
	dd if=build/kernel.bin of=build/disk.img conv=notrunc seek=512 bs=1

qemu: image
	qemu-system-x86_64 -fda build/disk.img

dump:
	hexcat build/disk.img

proper:
	mkdir build

clean:
	rm -rf build
	mkdir build
