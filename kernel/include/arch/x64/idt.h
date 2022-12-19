#pragma once
#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint16_t baseLow;
    uint16_t segmentSelector;
    uint8_t reserved;
    uint8_t flags;
    uint16_t baseHigh;
} __attribute__((packed)) IDTEntry;

typedef struct {
	uint16_t Size;
	IDTEntry * Offset;
} __attribute__((packed)) IDTDesc;

void idt_setgate(int interrupt, void * base, uint16_t segmentDesc, uint8_t flags);
void idt_enablegate(int interrupt);
void idt_disablegate(int interrupt);
void idt_init();
void idt_load(IDTDesc * idtDesc);