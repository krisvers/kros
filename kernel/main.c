#include "limine.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <drivers/terminal.h>

void main(struct limine_framebuffer * framebuffer) {
	tty_init(framebuffer, 2);
	puts("Test:\n");
	for (int i = 0; i < 96; i++) {
		putc(i);
	}
}