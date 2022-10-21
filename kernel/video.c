#include <video.h>

static char *const vidmem = (char*)0xB8000;
static unsigned char cursor = 0;

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

void printf_vidmem(char * string, ...) {
	for (int i = 0; string[i] != 0; i++) {
		if (string[i] == '\n') {
			putc_vidmem(cursor, 0, '!');
		}

		putc_vidmem(cursor, 0, string[i]);
		cursor++;
	}
}
