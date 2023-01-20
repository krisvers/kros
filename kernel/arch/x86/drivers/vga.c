#include <arch/x86/drivers/vga.h>

static char * const vga_addr = (char*)0xB8000;

void vga_clear() {
	for (int i = 0; i < 80*25; i++) {
		vga_addr[i*2] = 0x00;
		vga_addr[(i*2)+1] = WHITE;
	}
}

void vga_fill(enum vga_color color) {
	for (int i = 0; i < 80*25; i++) {
		vga_addr[(i*2)+1] = color << 4 & color;
	} 
}

void vga_setbg(enum vga_color bg) {
	for (int x = 0; x < 80; x++) {
		for (int y = 0; y < 25; y++) {
			vga_putc(x, y, ' ', bg, bg);
		}
	}
}

char vga_getc(int x, int y) {
	return vga_addr[((y * 80) + x) * 2];
}

void vga_putc(int x, int y, char c, enum vga_color fg_color, enum vga_color bg_color) {
    vga_addr[((y * 80) + x) * 2] = c;
    vga_addr[((y * 80) + x) * 2 + 1] = fg_color + (bg_color * 16);
}

void vga_scroll() {
	for (uint16_t i = 0; i < 80 * 25 - 80; i++) {
		((uint16_t *) 0xB8000)[i] = ((uint16_t *) 0xB8000)[(i + 80)];
	}
}
