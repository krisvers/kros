#pragma once
#include <video/vga.h>
#include <types.h>

void tty_init();
void tty_putc(char c);
void tty_linefeed();
void tty_reset();
void tty_puts(const char * str);