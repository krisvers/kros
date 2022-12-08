#include <stdio.h>
#include <kernel/kernel.h>
#include <keyboard.h>
#include <stdbool.h>

void main() {
	kernel_init();
	kprintf("Hello from the kernel!!!\n");
}