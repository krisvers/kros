ASM := nasm

.PHONY: all build clean image disk qemu proper dump

all: clean qemu

build:
	$(ASM) boot.asm -f bin -o build/boot.bin
	$(ASM) kernel.asm -f bin -o build/kernel.bin

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
