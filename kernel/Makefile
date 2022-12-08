DIR = $(shell cd .. && pwd && cd kernel)
ASM := nasm
ASMFLAGS := -f elf
CC := gcc
CFLAGS := -I include -O3 -nostdlib -m32 -march=i386 -fno-pie -fno-stack-protector -ffreestanding -Wall
LD := ld
LDFLAGS := -m elf_i386 -T $(DIR)/linker.ld -nostdlib

SRC_FILES = $(shell find . -type f -name "*.c")
SRC_ASM = $(shell find . -type f -name "*.asm")
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_ASM = $(SRC_ASM:.asm=.oasm)

all: $(OBJ_FILES) $(OBJ_ASM)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(DIR)/kernel/$< -o $(DIR)/build/kernel/$@

%.oasm: %.asm
	@$(ASM) $(ASMFLAGS) $(DIR)/kernel/$< -o $(DIR)/build/kernel/$@