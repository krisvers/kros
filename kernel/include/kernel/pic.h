#pragma once
#include <cpubasics.h>
#include <types.h>

void pic_config(uint8_t offset_pic1, uint8_t offset_pic2);
void pic_mask(int irq);
void pic_unmask(int irq);
void pic_disable();
void pic_sendeoi(int irq);
uint16_t pic_readirqreg();
uint16_t pic_readisrreg();