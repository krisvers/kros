#include <arch/x86/hal/gdt.h>
#include <arch/x86/hal/idt.h>
#include <arch/x86/hal/isr.h>
#include <arch/x86/hal/irq.h>
#include <arch/x86/hal/pic.h>
#include <arch/x86/hal/pit.h>
#include <arch/x86/drivers/cpubasics.h>
#include <std/stdio.h>
#include <arch/x86/drivers/tty.h>
#include <arch/x86/drivers/vga.h>
#include <arch/x86/drivers/keyboard.h>
#include <std/stdbool.h>

size_t mseconds = 0;

void timer_handler(Registers * regs) {
	mseconds++;
	putc('.');
}

void key_handler(Registers * regs) {
	char key = poll_key_char();
	putc('k');
}

uint8_t mem[2048];
size_t mem_index = 0;

void * alloc(size_t size) {
	for (size_t i = 0; i < size;)
}

void * free(void * ptr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		ptr[0] = NULL;
	}
	mem_index -= size;
}

void main() {
	printf("Loading GDT\n");
	gdt_init();
	printf("Loading IDT\n");
	idt_init();
	printf("Setting PIT at 1000 hz\n");
	pit_set_freq(1000);
	irq_reg_handler(0, timer_handler);
	irq_reg_handler(1, key_handler);
	printf("Loading ISR\n");
	isr_init();
	printf("Loading IRQ\n");
	irq_init();

	while (1) {
		
	}
}
