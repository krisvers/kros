#include <tty.h>

static size_t terminal_row;
static size_t terminal_column;

void terminal_init(void) {
	terminal_row = 0;
	terminal_column = 0;
	clear_vidmem();
}

void terminal_putchar(char c) {
	switch (c) {
		case '\n':
			terminal_row++;
			terminal_column = -1;
			break;

		default:
			putc_vidmem(terminal_column, terminal_row, c);
			break;
	}
	if (++terminal_column == 80) {
		terminal_column = 0;
		if (++terminal_row == 25) {
			terminal_reset();
		}
	}
}

void terminal_reset(void) {
	terminal_column = 0;
	terminal_row = 0;
	clear_vidmem();
}

void terminal_putstr(const char * str) {
	for (int i = 0; str[i] != 0; i++) {
		terminal_putchar(str[i]);
	}
}