#include <arch/x64/idt.h>

IDTEntry g_IDT[256];

void idt_setgate(int interrupt, void * base, uint16_t segmentDesc, uint8_t flags) {
    g_IDT[interrupt].baseLow = ((uint32_t) base) & 0xFFFF;
    g_IDT[interrupt].segmentSelector = segmentDesc;
    g_IDT[interrupt].reserved = 0;
    g_IDT[interrupt].flags = flags;
    g_IDT[interrupt].baseHigh = ((uint32_t) base >> 16) & 0xFFFF;
}

void idt_enablegate(int interrupt) {
    g_IDT[interrupt].flags |= 0x80;
}

void idt_disablegate(int interrupt) {
    g_IDT[interrupt].flags &= ~(0x80);
}

void idt_init() {
    idt_setgate(0, 0, 0, 69);
    IDTDesc g_IDTR = { sizeof(g_IDT) - 1, &g_IDT };

    printf("IDT: %x, IDTR: %x\n", g_IDT[0], &g_IDTR);

	idt_load(&g_IDTR);
}

void idt_load(IDTDesc * idtDesc);