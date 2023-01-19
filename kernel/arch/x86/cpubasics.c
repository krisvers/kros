#include <arch/x86/drivers/cpubasics.h>

void io_wait() {
    outb(UNUSED_PORT, 0);
}
