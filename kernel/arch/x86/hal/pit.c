#include <arch/x86/hal/pit.h>

void pit_set_freq(size_t hz) {
	size_t div = 3579545 / (hz * 3);
	outb(0x43, 0x36);
	outb(0x40, div & 0xFF);
	outb(0x40, div >> 8);
}
