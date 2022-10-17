ASM := nasm

.PHONY: all build image disk qemu

all: disk

build:
	$(ASM) boot.asm -f bin -o build/boot.bin
	$(ASM) kernel.asm -f bin -o build/kernel.bin

image: build
	dd if=build/boot.bin of=build/disk.img
	dd if=build/kernel.bin of=build/disk.img conv=notrunc seek=512 bs=1

disk: image
	dd if=build/disk.img of=/dev/fd0

qemu: image
	qemu-system-i386 -fda build/disk.img --nographic

dump:
	hexcat build/disk.img

