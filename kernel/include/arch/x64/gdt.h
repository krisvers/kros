#pragma once
#include <stddef.h>
#include <stdint.h>

typedef struct {
	uint16_t limit;
	uint16_t baseLow;
	uint8_t baseMiddle;
	uint8_t access;
	uint8_t limitHighFlags;
	uint8_t baseHigh;
} __attribute__((packed)) GDTEntry;

typedef struct {
	GDTEntry null;
	GDTEntry kernelCode;
	GDTEntry kernelData;
	GDTEntry userCode;
	GDTEntry userData;
} __attribute__((packed)) GDT;

typedef struct {
	uint16_t Size;
	GDT * Offset;
} __attribute__((packed)) GDTDesc;

void idt_init();
void gdt_load(GDTDesc * gdtDesc);
void gdt_reload_segments();