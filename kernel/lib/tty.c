#include <tty.h>

static size_t tty_row;
static size_t tty_column;

void tty_init() {
	tty_row = 0;
	tty_column = 0;
	vga_clear();
}

void tty_putc(char c) {
	vga_putpixel(tty_column, tty_row, c);
	
	if (++tty_column == 320) {
		tty_column = 0;
		if (++tty_row == 200) {
			tty_reset();
		}
	}
}

void tty_linefeed() {
	tty_column = 0;
	if (++tty_row == 25) {
		tty_reset();
	}
}

void tty_reset() {
	tty_column = 0;
	tty_row = 0;
	vga_clear();
}

void tty_puts(const char * str) {
	for (int i = 0; str[i] != 0; i++) {
		tty_puts(str[i]);
	}
}