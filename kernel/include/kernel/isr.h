#pragma once
#include <types.h>
#include <kernel/idt.h>
#include <kernel/gdt.h>

typedef struct {
    uint32_t ds;
    uint32_t edi, esi, ebp, kern_esp, ebx, edx, eax;
    uint32_t interrupt, error;
    uint32_t eip, cs, cflags, esp, ss;
} __attribute__((packed)) Registers;