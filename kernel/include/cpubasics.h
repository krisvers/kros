#pragma once

#include <types.h>

#define outb(port, value) asm volatile("outb %%al, %%dx" ::"d"(port), "a"(value))
#define outw(port, value) asm volatile("outw %%ax, %%dx" ::"d"(port), "a"(value))
#define outl(port, value) asm volatile("outl %%eax, %%dx" ::"d"(port), "a"(value))

uint8_t inb(uint16_t port);
uint16_t inw(uint16_t port);
uint32_t inl(uint16_t port);