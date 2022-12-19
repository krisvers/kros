#include <arch/x64/kfunc.h>

void abort(const char * message) {
    tty_setfgcolor(KMESG_FG);
    tty_setbgcolor(KMESG_BG);
    printf("Kernel abort!!!\nMessage: \"%s\"", message);
    __asm__ volatile(
        "cli;"
        "hlt;"
    );
}