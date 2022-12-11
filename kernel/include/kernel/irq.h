#pragma once
#include <cpubasics.h>
#include <kernel/isr.h>
#include <kernel/pic.h>
#include <stdio.h>

typedef void (*IRQHandler)(Registers * regs);

void irq_init();
void irq_reghandler(int irq, IRQHandler handler);