#include <stdio.h>
#include <kernel/kernel.h>
#include <keyboard.h>
#include <stdbool.h>

void main() {
	kernel_init();
	printf("Hello world %x test!\n", 69);
	printf("JEllon\n");
}