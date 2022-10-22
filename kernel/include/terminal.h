#pragma once
#include <video.h>
#include <types.h>

void terminal_init(void);
void terminal_putchar(char c);
void terminal_reset(void);
void terminal_putstr(const char * str);