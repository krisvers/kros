#pragma once
#include <stddef.h>
#include <stdint.h>

#define UNUSED_IO_PORT  0x80

#define outb(port, value) __asm__ volatile("outb %%al, %%dx" ::"d"(port), "a"(value));
#define outw(port, value) __asm__ volatile("outw %%ax, %%dx" ::"d"(port), "a"(value));
#define outl(port, value) __asm__ volatile("outl %%eax, %%dx" ::"d"(port), "a"(value));

inline uint8_t inb(uint16_t port) {
	uint8_t value;
	__asm__ volatile("inb %%dx, %%al" : "=a"(value) : "d"(port));
	return value;
}

inline uint16_t inw(uint16_t port) {
	uint16_t value;
	__asm__ volatile("inw %%dx, %%ax" : "=a"(value) : "d"(port));
	return value;
}

inline uint32_t inl(uint16_t port) {
	uint32_t value;
	__asm__ volatile("inl %%dx, %%eax" : "=a"(value) : "d"(port));
	return value;
}

inline uint8_t bitget(uint32_t input, uint8_t bit) {
	return (input & (0x1 << bit)) >> bit;
}

inline uint8_t io_wait() {
	__asm__ volatile("outb $0, $UNUSED_IO_PORT");
}