#ifndef KROS_X86_SERIAL_H
#define KROS_X86_SERIAL_H

#include <types.h>

typedef enum x86_serial_baud_t {
    X86_SERIAL_BAUD_115200 = 1,
    X86_SERIAL_BAUD_57600 = 2,
    X86_SERIAL_BAUD_38400 = 3,
    X86_SERIAL_BAUD_19200 = 6,
    X86_SERIAL_BAUD_9600 = 12,
    X86_SERIAL_BAUD_4800 = 24,
} x86_serial_baud_t;

s8 serial_init(u8 com, x86_serial_baud_t baud);

s8 serial_is_writable(u8 com);
s8 serial_is_readable(u8 com);

void serial_write(u8 com, char c);
char serial_read(u8 com);

#endif
