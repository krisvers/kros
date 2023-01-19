#pragma once
#include <arch/x86/drivers/tty.h>
#include <limits.h>
#include <std/stdbool.h>
#include <stdarg.h>
#include <std/string.h>

#define EOF (-1)

int printf(const char * restrict fmt, ...);
int putc(int ic);
int puts(const char * string);
