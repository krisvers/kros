#include <kernel/kernel.h>

void kernel_init() {
    gdt_init();
    idt_init();
    isr_init();
    irq_init();
}