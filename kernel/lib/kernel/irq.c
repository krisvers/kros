#include <kernel/irq.h>

#define PIC_REMAP_OFFSET			0x20

IRQHandler irq_handlers[16];

void irq_handler(Registers * regs) {
	int irq = regs->interrupt - PIC_REMAP_OFFSET;

	if (irq_handlers[irq] != NULL) {
		irq_handlers[irq](regs);
	} else {
		printf("Unhandled IRQ %i\n", irq);
	}

	pic_sendeoi(irq);
}

void irq_init() {
	pic_config(PIC_REMAP_OFFSET, PIC_REMAP_OFFSET + 8);

	for (int i = 0; i < 16; i++) {
		isr_reghandler(PIC_REMAP_OFFSET + i, irq_handler);
	}

	enable_interrupts();
}

void irq_reghandler(int irq, IRQHandler handler) {
	irq_handlers[irq] = handler;
}