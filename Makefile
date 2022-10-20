DIR = $(shell pwd)
ASM := nasm

.PHONY: all build clean image disk qemu proper dump

all: clean qemu

build:
	$(ASM) $(DIR)/boot/boot.asm -f bin -o $(DIR)/build/boot.bin
	$(ASM) $(DIR)/entry.asm -f bin -o $(DIR)/build/entry.bin

image: build
	dd if=build/boot.bin of=build/disk.img
	dd if=build/entry.bin of=build/disk.img conv=notrunc seek=512 bs=1

qemu: image
	qemu-system-x86_64 -fda build/disk.img

dump:
	hexcat build/disk.img

proper:
	mkdir build

clean:
	rm -rf build
	mkdir build
