#pragma once
#include <video/vga.h>
#include <types.h>

void tty_init();
void tty_putc(char c, enum vga_color fg);
void tty_linefeed();
void tty_reset();
void tty_setcursor(int x, int y);
void tty_puts(const char * str, enum vga_color fg);