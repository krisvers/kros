#pragma once

enum vga_color {
    BLACK = 0,
    DARK_GREY = 20,
    GREY = 23,
    LIGHT_GREY = 7,
    WHITE = 15,
    RED = 39,
    ORANGE = 41,
    YELLOW = 43,
    GREEN = 45,
};

void vga_putpixel(int x, int y, enum vga_color color);
void vga_clear();
char vga_getpixel(int x, int y);