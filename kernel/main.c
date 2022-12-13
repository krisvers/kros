#include "limine.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <drivers/terminal.h>
#include <drivers/hal/hal.h>

void main(struct limine_framebuffer * framebuffer) {
	tty_init(framebuffer, 2);
	puts("Initializing Hardware Abstraction Layer!\n");
	hal_init();
}