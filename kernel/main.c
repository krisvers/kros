#include <arch/x86/hal/gdt.h>
#include <arch/x86/hal/idt.h>
#include <arch/x86/hal/isr.h>
#include <arch/x86/hal/irq.h>
#include <arch/x86/hal/pic.h>
#include <arch/x86/drivers/cpubasics.h>
#include <std/stdio.h>
#include <arch/x86/drivers/keyboard.h>
#include <std/stdbool.h>

void timer_handler(Registers * regs) {
	printf(".");
}

void key_handler(Registers * regs) {
	char key = inb(0x60);
	putc(key);
}

void main() {
	gdt_init();
	idt_init();
	isr_init();
	irq_init();
	printf("Hello\n");
	printf("Test %x\n", 50);
	irq_reg_handler(0, timer_handler);
	irq_reg_handler(1, key_handler);
}
