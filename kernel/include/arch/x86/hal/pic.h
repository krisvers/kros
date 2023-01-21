#pragma once
#include <arch/x86/drivers/cpubasics.h>

void pic_config(uint8_t offset_pic1, uint8_t offset_pic2);
void pic_mask(int irq);
void pic_unmask(int irq);
void pic_disable();
uint8_t pic_read_irr();
uint8_t pic_read_isr();
void pic_send_eoi();
