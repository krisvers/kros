#include "limine.h"
#include <io.h>
#include <stdio.h>
#include <stdbool.h>
#include <drivers/terminal.h>
#include <drivers/hal/hal.h>

void main(struct limine_framebuffer * framebuffer) {
	tty_init(framebuffer, 2);
	printf("Hello, World!\n");
	hal_init();
}