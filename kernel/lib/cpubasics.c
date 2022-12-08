#include <cpubasics.h>

void io_wait() {
    outb(UNUSED_PORT, 0);
}