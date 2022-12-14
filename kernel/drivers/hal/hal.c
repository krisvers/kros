#include <drivers/hal/hal.h>

void hal_init() {
    GDTDesc gdt_desc = *gdt_gdtr(gdt_gdt(gdt_entry(0, 0, 0, 0, 0, 0), gdt_entry(0, 0, 0, 0x9A, 0xA, 0), gdt_entry(0, 0, 0, 0x92, 0xC, 0), gdt_entry(0, 0, 0, 0, 0, 0), gdt_entry(0, 0, 0, 0xFA, 0xA, 0), gdt_entry(0, 0, 0, 0xF2, 0xC, 0)));
    gdt_load(&gdt_desc);
}