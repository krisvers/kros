DIR = $(shell pwd)/..
CC := gcc
CFLAGS := -I include -O3 -nostdlib -m32 -march=i386 -fno-pie -fno-stack-protector -ffreestanding -Wall
LD := ld
LDFLAGS := -m elf_i386 -T $(DIR)/linker.ld -nostdlib

all: $(DIR)/build/kernel/main.o $(DIR)/build/kernel/lib/video.o $(DIR)/build/kernel/lib/string.o $(DIR)/build/kernel/lib/stdlib.o $(DIR)/build/kernel/lib/keyboard.o $(DIR)/build/kernel/lib/stdio.o $(DIR)/build/kernel/lib/tty.o

$(DIR)/build/kernel/main.o: $(DIR)/kernel/main.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/main.c -o $(DIR)/build/kernel/main.o

$(DIR)/build/kernel/lib/video.o: $(DIR)/kernel/lib/video.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/lib/video.c -o $(DIR)/build/kernel/lib/video.o

$(DIR)/build/kernel/lib/string.o: $(DIR)/kernel/lib/string.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/lib/string.c -o $(DIR)/build/kernel/lib/string.o

$(DIR)/build/kernel/lib/stdlib.o: $(DIR)/kernel/lib/stdlib.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/lib/stdlib.c -o $(DIR)/build/kernel/lib/stdlib.o

$(DIR)/build/kernel/lib/keyboard.o: $(DIR)/kernel/lib/keyboard.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/lib/keyboard.c -o $(DIR)/build/kernel/lib/keyboard.o

$(DIR)/build/kernel/lib/stdio.o: $(DIR)/kernel/lib/stdio.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/lib/stdio.c -o $(DIR)/build/kernel/lib/stdio.o

$(DIR)/build/kernel/lib/tty.o: $(DIR)/kernel/lib/tty.c
	$(CC) $(CFLAGS) -c $(DIR)/kernel/lib/tty.c -o $(DIR)/build/kernel/lib/tty.o
