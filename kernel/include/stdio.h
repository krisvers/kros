#pragma once
#include <tty.h>
#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

#define EOF (-1)

int printf(const char * restrict fmt, ...);
int putchar(int ic);
int puts(const char * string);