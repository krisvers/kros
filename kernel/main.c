#include <stdio.h>
#include <kernel/kernel.h>
#include <keyboard.h>
#include <stdbool.h>

void key(Registers * regs) {
    
}

void main() {
	kernel_init();
	printf("Hello\n");
	irq_reg_handler(0, key);
	printf("Test %x\n\n\n\n", 50);
}