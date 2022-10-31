DIR = $(shell cd .. && pwd && cd kernel)
CC := gcc
CFLAGS := -I include -O3 -nostdlib -m32 -march=i386 -fno-pie -fno-stack-protector -ffreestanding -Wall
LD := ld
LDFLAGS := -m elf_i386 -T $(DIR)/linker.ld -nostdlib

SRC_FILES = $(shell find . -type f -name "*.c")
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(OBJ_FILES)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(DIR)/kernel/$< -o $(DIR)/build/kernel/$@
