#include <arch/x86/hal/pit.h>

uint8_t mseconds = 0;

void render();
void timer_handler(Registers * regs) {
    mseconds++;
    if (mseconds >= 100) {
        mseconds = 0;
		render();
    }
    pic_send_eoi();
}

void pit_set_freq(size_t hz) {
    size_t div = 3579545 / (hz * 3);
    outb(0x43, 0x36);
    outb(0x40, div & 0xFF);
    outb(0x40, div >> 8);
}

void pit_init() {
    pit_set_freq(1666);
    irq_reg_handler(0, timer_handler);
}