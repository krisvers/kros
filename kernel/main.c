#include <video.h>

extern char _BSS_START;
extern char _BSS_END;

void __attribute__((section(".entry"))) _kentry() {
    for (char *addr = &_BSS_START; addr < &_BSS_END; addr++) {
        *addr = 0;
    }

	printf_vidmem("Woah ngl thats kinda sus");

    while (1);
}
