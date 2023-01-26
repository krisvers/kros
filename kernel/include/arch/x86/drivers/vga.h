#pragma once
#include <std/types.h>
#include <std/string.h>

enum vga_color {
    BLACK = 0x00,
    GREY = 0x05,
    LIGHT_GREY = 0x0A,
    WHITE = 0x0F,
    RED = 0x40,
    ORANGE = 0x42,
    YELLOW = 0x43,
    GREEN = 0x49,
    CYAN = 0x4D,
    BLUE = 0x4F,
    PURPLE = 0x51,
};

void vga_clear();
void vga_fill(enum vga_color color);
void vga_putc(int x, int y, enum vga_color color);