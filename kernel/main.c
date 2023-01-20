#include <arch/x86/hal/gdt.h>
#include <arch/x86/hal/idt.h>
#include <arch/x86/hal/isr.h>
#include <arch/x86/hal/irq.h>
#include <arch/x86/hal/pic.h>
#include <arch/x86/hal/pit.h>
#include <arch/x86/drivers/cpubasics.h>
#include <std/stdio.h>
#include <std/stdlib.h>
#include <arch/x86/drivers/tty.h>
#include <arch/x86/drivers/vga.h>
#include <arch/x86/drivers/keyboard.h>
#include <std/stdbool.h>

size_t mseconds = 0;

void timer_handler(Registers * regs) {
	mseconds++;
	//putc('.');
}

void key_handler(Registers * regs) {
	char key = poll_key_char();
	putc('k');
}

int sqr(int num, int power) {
    int ret = num;

    for (uint8_t i = 0; i < power - 1; i++) {
        ret *= num;
    }

    return ret;
}

void * alloc(size_t size) {
    // TODO: plan the allocator
}

void free(void * ptr, size_t size) {
    // TODO: plan the freer
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
    printf("2^8 == %d\n", sqr(2, 8));

    // TODO: run some allocator and free tests

	while (1) {
		
	}
}
