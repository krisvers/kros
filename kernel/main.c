#include "limine.h"
#include <io.h>
#include <arch/x64/kfunc.h>
#include <stdio.h>
#include <stdbool.h>
#include <drivers/terminal.h>
#include <drivers/hal/hal.h>

void main(struct limine_framebuffer * framebuffer) {
	tty_init(framebuffer, 2);
	printf("Terminal initialized 2x...\nInitializing HAL...\n");
	hal_init();
	abort("Kernel exiting!");
}