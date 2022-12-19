#include <arch/x64/isr.h>

ISRHandler g_ISRHandlers[256];

static const char * const g_Exceptions = {
    "Divide by zero",
    "Debug",
    "Non-maskable INT",
    "Breakpoint",
    "Overflow",
    "Bound Range Exceeded",
    "Invalid Opcode",
    "Device Not Available",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Invalid TSS",
    "Segment Not Present",
    "Stack-Segment Fault",
    "General Protection Fault",
    "Page Fault",
    "",
    "x87 Floating-Point Exception",
    "Alignment Check",
    "Machine Check",
    "SIMD Floating-Point Exception",
    "Virtualization Exception",
    "Control Protection Exception",
    "",
    "",
    "",
    "",
    "",
    "",
    "Hypervisor Injection Exception",
    "VMM Communication Exception",
    "Security Exception",
    ""
};

void isr_initgates();

void isr_init() {
    isr_initgates();

    idt_enablegate(0);

    for (uint8_t i = 1; i > 0; i++) {
        idt_enablegate(i);
    }

    idt_disablegate(0x80);
}

void __attribute__((cdecl)) isr_handler() {

}