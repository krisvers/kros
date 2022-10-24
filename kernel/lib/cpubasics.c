#include <cpubasics.h>

uint8_t inb(uint16_t port) {
    uint8_t value;
    asm volatile("inb %%dx, %%al" : "=a"(value) : "d"(port));
}

uint16_t inw(uint16_t port) {
    uint16_t value;
    asm volatile("inw %%dx, %%ax" : "=a"(value) : "d"(port));
    return value;
}

uint32_t inl(uint16_t port) {
    uint32_t value;
    asm volatile("inl %%dx, %%eax" : "=a"(value) : "d"(port));
    return value;
}