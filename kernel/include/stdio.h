#pragma once
#include <drivers/terminal.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

#define EOF -1
#define INT_MAX 2147483647

int printf(const char * restrict format, ...);
int putc(int ic);
int puts(const char * str);