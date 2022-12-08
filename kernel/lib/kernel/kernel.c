#include <kernel/kernel.h>

void kernel_init() {
    gdt_init();
    idt_init();
}