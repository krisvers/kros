#include <kernel/pic.h>

#define PIC1_COMMAND_PORT		0x20
#define PIC1_DATA_PORT			0x21
#define PIC2_COMMAND_PORT		0xA0
#define PIC2_DATA_PORT			0xA1

enum {
	PIC_ICW1_ICW4		= 0x01,
	PIC_ICW1_SINGLE		= 0x02,
	PIC_ICW1_INTERVAL4	= 0x04,
	PIC_ICW1_LEVEL		= 0x08,
	PIC_ICW1_INIT		= 0x10,
} PIC_ICW1;

enum {
	PIC_ICW4_8086			= 0x01,
	PIC_ICW4_AUTO_EOI		= 0x02,
	PIC_ICW4_BUFFER_MASTER	= 0x04,
	PIC_ICW4_BUFFER_SLAVE	= 0x00,
	PIC_ICW4_BUFFERED		= 0x08,
	PIC_ICW4_SFNM			= 0x10,
} PIC_ICW4;

void pic_config(uint8_t offset_pic1, uint8_t offset_pic2) {
	outb(PIC1_COMMAND_PORT, PIC_ICW1_ICW4 | PIC_ICW1_INIT);
	io_wait();
	outb(PIC2_COMMAND_PORT, PIC_ICW1_ICW4 | PIC_ICW1_INIT);
	io_wait();

	outb(PIC1_DATA_PORT, offset_pic1);
	io_wait();
	outb(PIC2_DATA_PORT, offset_pic2);
	io_wait();

	outb(PIC1_DATA_PORT, 0x04);
	io_wait();
	outb(PIC2_DATA_PORT, 0x02);
	io_wait();

	outb(PIC1_DATA_PORT, PIC_ICW4_8086);
	io_wait();
	outb(PIC2_DATA_PORT, PIC_ICW4_8086);
	io_wait();

	outb(PIC1_DATA_PORT, 0);
	io_wait();
	outb(PIC2_DATA_PORT, 0);
	io_wait();
}

void pic_mask(int irq) {
	if (irq < 8) {
		
	} else {
		irq -= 8;
		outb(PIC2_DATA_PORT, irq)
	}
}