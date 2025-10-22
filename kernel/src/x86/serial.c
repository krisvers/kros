#include <x86/serial.h>
#include <x86/common.h>

u16 serial_com[8] = {
    0x3F8,
    0x2F8,
    0x3E8,
    0x2E8,
    0x5F8,
    0x4F8,
    0x5E8,
    0x4E8,
};

s8 serial_init(u8 com, x86_serial_baud_t baud) {
    if (com == 0 || com > 8 || baud == 0) {
        return 0;
    }

    u16 b = (u16) baud;
    u16 port = serial_com[com - 1];
    outb(port + 1, 0x00);
    outb(port + 3, 0x80);
    outb(port + 0, b & 0xFF);
    outb(port + 1, b >> 8);
    outb(port + 3, 0x03);
    outb(port + 2, 0xC7);
    outb(port + 4, 0x0B);
    outb(port + 4, 0x1E);
    outb(port + 0, 0xAE);

    if (inb(port + 0) != 0xAE) {
        return 0;
    }

    outb(port + 4, 0x0F);
    return 1;
}

s8 serial_is_writable(u8 com) {
    if (com == 0 || com > 8) {
        return 0;
    }

    u16 port = serial_com[com - 1];
    return (inb(port + 5) & 0x20);
}

s8 serial_is_readable(u8 com) {
    if (com == 0 || com > 8) {
        return 0;
    }

    u16 port = serial_com[com - 1];
    return (inb(port + 5) & 0x01);
}

void serial_write(u8 com, char c) {
    if (com == 0 || com > 8) {
        return;
    }

    while (!serial_is_writable(com)) {}

    u16 port = serial_com[com - 1];
    outb(port, c);
}

char serial_read(u8 com) {
    if (com == 0 || com > 8) {
        return '\0';
    }

    while (!serial_is_readable(com)) {}

    u16 port = serial_com[com - 1];
    return inb(port);
}
