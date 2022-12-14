#include <drivers/hal/gdt.h>

GDTEntry gdt_entry(uint16_t limit, uint16_t baseLow, uint16_t baseMiddle, uint8_t access, uint8_t flags, uint8_t baseHigh) {
    GDTEntry gdt_ent = {limit, baseLow, baseMiddle, access, flags, baseHigh};
    return gdt_ent;
}

GDT * gdt_gdt(GDTEntry null, GDTEntry kernelCode, GDTEntry kernelData, GDTEntry userNull, GDTEntry userCode, GDTEntry userData) {
    GDT gdt = {null, kernelCode, kernelData, userNull, userCode, userData};
    return &gdt;
}

GDTDesc * gdt_gdtr(GDT * gdt) {
    GDTDesc gdt_desc = {(sizeof(GDT) - 1), ((uint64_t) gdt)};
    return &gdt_desc;
}