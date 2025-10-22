#ifndef KROS_CONSOLE_H
#define KROS_CONSOLE_H

#include <types.h>

#define CONSOLE_INVALID 0
#define CONSOLE_MAX_PATH 256
#define CONSOLE_STDIO 1

typedef u32 console_t;

typedef s8 (*console_open_t)(void);
typedef s8 (*console_write_t)(const char*, usize);
typedef s8 (*console_read_t)(char*, usize);
typedef void (*console_close_t)(void);

console_t console_open(const char* path);
s8 console_write(console_t id, const char* string, usize length);
s8 console_read(console_t id, char* buffer, usize length);
void console_close(console_t id);

s8 console_register(console_t id, const char* path,
        console_open_t open_func, console_write_t write_func,
        console_read_t read_func, console_close_t close_func);

#endif
