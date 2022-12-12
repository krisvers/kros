#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <../limine.h>

#define BG_COLOR	0x2B2A1F
#define FG_COLOR	0xFBFAB0

void tty_init(struct limine_framebuffer * buffer, short int scale);
void tty_putpix(uint64_t x, uint64_t y, uint32_t argb);
void tty_puts(const char * str);
void tty_putc(uint32_t c);
void tty_fill(uint32_t argb);