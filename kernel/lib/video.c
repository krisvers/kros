#include <video.h>

static char *const vidmem = (char*)0xB8000;

void putc_vidmem(int x, int y, char c) {
	vidmem[(((y * 80) + x) * 2) + 0] = c;
	vidmem[(((y * 80) + x) * 2) + 1] = 0x02;
}

void puts_vidmem(int x, int y, char * string) {
	for (int i = 0; string[i] != 0; i++) {
		vidmem[(((y * 80) + x) * 2) + (i * 2) + 0] = string[i];
		vidmem[(((y * 80) + x) * 2) + (i * 2) + 1] = 0x02;
	}
}

void clear_vidmem(void) {
	for (int i = 0; i < 80*25; i++) {
		vidmem[(i * 2) + 0] = 0x00;
		vidmem[(i * 2) + 1] = 0x00;
	}
}

char getc_vidmem(int x, int y) {
	return vidmem[(((y * 80) + x) * 2)];
}