#include <video/vga.h>

void main() {
	for (int i = 0; i < sizeof(enum vga_color); i++) {
		vga_putpixel(i, 0, 15);
	}
}