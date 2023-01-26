#include <arch/x86/drivers/vga.h>

static char * const vga_addr = (char*)0xA0000;

void vga_clear() {
	for (int i = 0; i < 320*200; i++) {
		vga_addr[i] = 0x00;
	}
}

void vga_fill(enum vga_color color) {
	for (int i = 0; i < 320*200; i++) {
		vga_addr[i] = color;
	} 
}

void vga_putc(int x, int y, enum vga_color color) {
    vga_addr[((y * 320) + x)] = color;
}