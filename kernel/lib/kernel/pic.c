#include <kernel/pic.h>

#define PIC1_COMMAND_PORT			0x20
#define PIC1_DATA_PORT				0x21
#define PIC2_COMMAND_PORT			0xA0
#define PIC2_DATA_PORT				0xA1

/*	ICW 1

0	ICW4	the pic expects to receive ICW4 during initialization
1	SGNL	only 1 pic in the system; otherwise, uses cascaded pics and ICW3 must be sent
2	ADI		ignored on x86, set to 0
3	LTIM	if set, operate in level triggered mode; otherwise, operate in triggered mode
4	INIT	set to 1 to init pic
5-6			ignored on x86, set to 0

*/

enum {
	PIC_ICW1_ICW4		= 0x01,
	PIC_ICW1_SINGLE		= 0x02,
	PIC_ICW1_INTERVAL4	= 0x04,
	PIC_ICW1_LEVEL		= 0x08,
	PIC_ICW1_INIT		= 0x10,
} PIC_ICW1;

/* ICW4

0	uPM		if set, PIC is 8086; otherwise, is MCS-80/85
1	AEOI	if set, automatically sends EOI after INT
2	M/S		only use if BUF is set; if set, selects buffer master; otherwise selects buffer slave
3	BUF		if set, uses buffered mode
4	SFNM	specially fully nested mode; used in systems with many cascades PICs
5-7			reservered, set to 0

*/

enum {
	PIC_ICW4_8086			= 0x01,
	PIC_ICW4_AUTO_EOI		= 0x02,
	PIC_ICW4_BUFFER_MASTER	= 0x04,
	PIC_ICW4_BUFFER_SLAVE	= 0x00,
	PIC_ICW4_BUFFERED		= 0x08,
	PIC_ICW4_SFNM			= 0x10
} PIC_ICW4;

enum {
	PIC_CMD_EOI				= 0x20,
	PIC_CMD_READ_IRR		= 0x0A,
	PIC_CMD_READ_ISR		= 0x0B
} PIC_CMD;

void pic_config(uint8_t offset_pic1, uint8_t offset_pic2) {
	// initialization of ICW1
	outb(PIC1_COMMAND_PORT, PIC_ICW1_ICW4 | PIC_ICW1_INIT);
	io_wait();
	outb(PIC2_COMMAND_PORT, PIC_ICW1_ICW4 | PIC_ICW1_INIT);
	io_wait();

	// initialization of ICW2 - offsets
	outb(PIC1_DATA_PORT, offset_pic1);
	io_wait();
	outb(PIC2_DATA_PORT, offset_pic2);
	io_wait();

	// initialization of ICW3
	outb(PIC1_DATA_PORT, 0x4);		// tell PIC1 that the slave PIC is at 0000 0100
	io_wait();
	outb(PIC2_DATA_PORT, 0x4);		// tell PIC2 that the slave PIC is at 0000 0100
	io_wait();

	// initialization of ICW4
	outb(PIC1_DATA_PORT, PIC_ICW4_8086 | PIC_ICW4_AUTO_EOI);
	io_wait();
	outb(PIC2_DATA_PORT, PIC_ICW4_8086 | PIC_ICW4_AUTO_EOI);
	io_wait();

	// clear data regs
	outb(PIC1_DATA_PORT, 0x00);
	io_wait();
	outb(PIC2_DATA_PORT, 0x00);
	io_wait();
}

void pic_mask(int irq) {
	uint8_t port;

	if (irq < 8) {
		port = PIC1_DATA_PORT;
	} else {
		irq -= 8;
		port = PIC1_DATA_PORT;
	}

	uint8_t mask = inb(PIC1_DATA_PORT);
	outb(PIC1_DATA_PORT, mask | (1 << irq));
}

void pic_unmask(int irq) {
	uint8_t port;

	if (irq < 8) {
		port = PIC1_DATA_PORT;
	} else {
		irq -= 8;
		port = PIC1_DATA_PORT;
	}

	uint8_t mask = inb(PIC1_DATA_PORT);
	outb(PIC1_DATA_PORT, mask & ~(1 << irq));
}

void pic_disable() {
	outb(PIC1_DATA_PORT, 0xFF);
	io_wait();
	outb(PIC2_DATA_PORT, 0xFF);
	io_wait();
}

uint8_t pic_read_irr() {
	outb(PIC1_COMMAND_PORT, PIC_CMD_READ_IRR);
	outb(PIC2_COMMAND_PORT, PIC_CMD_READ_IRR);
	return (uint16_t) (inb(PIC1_COMMAND_PORT) | (inb(PIC2_COMMAND_PORT) << 8));
}

uint8_t pic_read_isr() {
	outb(PIC1_COMMAND_PORT, PIC_CMD_READ_ISR);
	outb(PIC2_COMMAND_PORT, PIC_CMD_READ_ISR);
	return (uint16_t) (inb(PIC1_COMMAND_PORT) | (inb(PIC2_COMMAND_PORT) << 8));
}