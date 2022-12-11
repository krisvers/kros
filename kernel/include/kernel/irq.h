#pragma once
#include <kernel/pic.h>
#include <kernel/isr.h>
#include <cpubasics.h>

typedef void (*IRQHandler)(Registers * regs);

void irq_init();
void irq_reg_handler(int irq, IRQHandler handler);