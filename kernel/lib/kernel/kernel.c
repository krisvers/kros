#include <kernel/kernel.h>

void kernel_init() {
    disable_interrupts();
    gdt_init();
    idt_init();
    isr_init();
    irq_init();
    enable_interrupts();
}