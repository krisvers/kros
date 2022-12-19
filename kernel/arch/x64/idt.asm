[bits 64]
global idt_load
idt_load:
    lidt [rdi]
    ret