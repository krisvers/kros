DIR = $(shell pwd)
CC := gcc
CFLAGS := -I kernel/include -O3 -nostdlib -m32 -march=i386 -fno-pie -fno-stack-protector -ffreestanding -Wall
LD := ld
LDFLAGS := -m elf_i386 -T $(DIR)/linker.ld -nostdlib
ASM := nasm
OBJ_FILES = $(shell find $(DIR)/build/kernel/ -type f -name "*.o")

.PHONY: all build clean qemu rebuild

all: clean qemu

build:
	@make --no-print-directory -C ./kernel
	@echo ">  Linking libs and kernel..."
	$(LD) $(LDFLAGS) --oformat binary $(DIR)/build/kernel/$(OBJ_FILES) -o $(DIR)/build/bin/kernel.bin
	@echo ">  Assembling bootloader..."
	@$(ASM) $(DIR)/boot/boot.asm -f bin -o $(DIR)/build/bin/boot.bin
	@echo ">  Creating disk image..."
	@dd if=build/bin/boot.bin of=build/img/disk.img
	@dd if=build/bin/kernel.bin of=build/img/disk.img conv=notrunc seek=512 bs=1

clean:
	rm -rf build
	mkdir -p build/kernel/lib/video
	mkdir -p build/bin/
	mkdir -p build/img/

qemu: build
	@echo "! Starting qemu"
	@qemu-system-x86_64 -fda build/img/disk.img

rebuild: clean build