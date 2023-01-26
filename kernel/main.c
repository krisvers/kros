#include <arch/x86/hal/gdt.h>
#include <arch/x86/hal/idt.h>
#include <arch/x86/hal/isr.h>
#include <arch/x86/hal/irq.h>
#include <arch/x86/hal/pic.h>
#include <arch/x86/hal/pit.h>
#include <arch/x86/drivers/cpubasics.h>
#include <std/stdlib.h>
#include <arch/x86/drivers/vga.h>
#include <arch/x86/drivers/keyboard.h>
#include <std/stdbool.h>


void render() {
	vga_clear();
	vga_putc(0, 0, keysdown['w'] ? GREEN : RED);
	vga_putc(1, 0, (keydown == 'w') ? GREEN : RED);
	for (int i = 0; i < 128; i++) {
		vga_putc(i, 2, keysdown[i] ? GREEN : RED);
	}
}

void main() {
    gdt_init();
	idt_init();
	isr_init();
	irq_init();
    pit_init();
    keyboard_init();

	while (1) {

	}
}