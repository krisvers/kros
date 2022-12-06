#include <video/vga.h>

static char *const vidmem = (char*)0xA0000;

void vga_putpixel(int x, int y, enum vga_color color) {
	vidmem[((y * 320) + x)] = color;
}

void vga_clear() {
	for (int i = 0; i < 320*200; i++) {
		vidmem[i + 0] = 0x00;
	}
}

char vga_getpixel(int x, int y) {
	return vidmem[((y * 320) + x)];
}