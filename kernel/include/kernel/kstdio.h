#pragma once
#include <tty.h>
#include <video/vga.h>
#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

#define EOF (-1)

int kprintf(const char * restrict fmt, ...);
int kputc(int ic);
int kputs(const char * string);