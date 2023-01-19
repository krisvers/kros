#include <arch/x86/drivers/tty.h>

static size_t tty_row;
static size_t tty_column;

void tty_init() {
    vga_setbg(BLACK);
    tty_column = 0;
    tty_row = 0;
}

void tty_putc(char c, enum vga_color fg) {
    vga_putc(tty_column, tty_row, c, fg, BLACK);
    if (tty_column++ >= 80) {
        tty_linefeed();
    }
}

void tty_linefeed() {
    tty_column = 0;
    tty_row++;
}

void tty_tab() {
    tty_column += 4;
    if (tty_column >= 80) {
        tty_linefeed();
    }
}

void tty_reset() {
    vga_setbg(BLACK);
    tty_column = 0;
    tty_row = 0;
}

void tty_setcursor(int x, int y) {
    tty_column = x;
    tty_row = y;
}

void tty_puts(const char * str, enum vga_color fg) {
    for (unsigned char cp = 0; str[cp] != 0; cp++) {
        tty_putc(str[cp], fg);
    }
}
