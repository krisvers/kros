#include <video/vga.h>

static char *const vidmem = (char*)0xA0000;

void vga_putpixel(int x, int y, char c) {
	vidmem[((y * 320) + x)] = c;
}

void vga_clear() {
	for (int i = 0; i < 320*200; i++) {
		vidmem[i + 0] = 0x00;
	}
}

char vga_getpixel(int x, int y) {
	return vidmem[((y * 320) + x)];
}