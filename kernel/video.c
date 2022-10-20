#include <video.h>

static char *const vidmem = (char*)0xB8000;

void putc_vidmem(int x, int y, char c) {
    vidmem[(((y * 80) + x) * 2) + 0] = c;
    vidmem[(((y * 80) + x) * 2) + 1] = 0x02;
}
