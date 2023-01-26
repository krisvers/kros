#pragma once
#include <arch/x86/drivers/cpubasics.h>
#include <arch/x86/hal/isr.h>
#include <arch/x86/hal/irq.h>
#include <std/stdbool.h>

char keydown;
bool keysdown[256];

void keyboard_init();
bool keyboard_getkey(char c);