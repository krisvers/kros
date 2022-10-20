#include <video.h>

extern char _BSS_START;
extern char _BSS_END;

void __attribute__((section(".entry"))) _kentry() {
    for (char *addr = &_BSS_START; addr < &_BSS_END; addr++) {
        *addr = 0;
    }

    for(int y = 0; y < 25; y++) {
        char c = '0';
        for(int x = 0; x < 80; x++) {
            putc_vidmem(x, y, c++);
        }
    }

    while (1) {}
}
