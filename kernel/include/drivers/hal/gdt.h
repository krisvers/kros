#pragma once
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint16_t limit;
    uint16_t baseLow;
    uint16_t baseMiddle;
    uint8_t access;
    uint8_t flags;
    uint8_t baseHigh;
} __attribute__((packed)) GDTEntry;

typedef struct {
    GDTEntry null;
    GDTEntry kernelCode;
    GDTEntry kernelData;
    GDTEntry userNull;
    GDTEntry userCode;
    GDTEntry userData;
} __attribute__((packed)) __attribute__((aligned(0x1000))) GDT;

typedef struct {
    uint16_t Size;
    uint64_t Offset;
} __attribute__((packed)) GDTDesc;

GDTEntry gdt_entry(uint16_t limit, uint16_t baseLow, uint16_t baseMiddle, uint8_t access, uint8_t flags, uint8_t baseHigh);
GDT * gdt_gdt(GDTEntry null, GDTEntry kernelCode, GDTEntry kernelData, GDTEntry userNull, GDTEntry userCode, GDTEntry userData);
GDTDesc * gdt_gdtr(GDT * gdt);

void gdt_load(GDTDesc * gdtDesc);