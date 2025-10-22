#include <x86/pit.h>
#include <x86/common.h>

#define PIT_DATA0 0x40
#define PIT_DATA1 0x41
#define PIT_DATA2 0x42
#define PIT_COMMAND 0x43

void pit_configure(u16 hz) {
    u16 value = 0xFFFF;
    if (hz != 0) {
        value = 3579545 / (hz * 3);
    }

    outb(PIT_COMMAND, 0x36);
    outb(PIT_DATA0, value & 0xFF);
    outb(PIT_DATA1, value >> 8);
}
