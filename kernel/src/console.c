#include <console.h>
#include <mem.h>

typedef struct console_struct_t {
    console_t id;
    char path[CONSOLE_MAX_PATH];

    console_open_t open_func;
    console_write_t write_func;
    console_read_t read_func;
    console_close_t close_func;
} console_struct_t;

#define CONSOLE_COUNT_MAX 32

static console_struct_t consoles[32] = { 0 };
static usize console_count = 0;

console_t console_open(const char* path) {
    for (usize i = 0; i < console_count; ++i) {
        if (strcmp(path, consoles[i].path) == 0) {
            if (consoles[i].open_func()) {
                return consoles[i].id;
            }

            return CONSOLE_INVALID;
        }
    }

    return CONSOLE_INVALID;
}

s8 console_write(console_t id, const char* string, usize length) {
    for (usize i = 0; i < console_count; ++i) {
        if (id == consoles[i].id) {
            return consoles[i].write_func(string, length);
        }
    }

    return 0;
}

s8 console_read(console_t id, char* buffer, usize length) {
    for (usize i = 0; i < console_count; ++i) {
        if (id == consoles[i].id) {
            return consoles[i].read_func(buffer, length);
        }
    }

    return 0;
}

void console_close(console_t id) {
    for (usize i = 0; i < console_count; ++i) {
        if (id == consoles[i].id) {
            consoles[i].close_func();
            return;
        }
    }
}

s8 console_register(console_t id, const char* path,
        console_open_t open_func, console_write_t write_func,
        console_read_t read_func, console_close_t close_func)
{
    if (console_count >= CONSOLE_COUNT_MAX) {
        return 0;
    }

    for (usize i = 0; i < console_count; ++i) {
        if (id == consoles[i].id) {
            return 0;
        }
    }

    console_struct_t console;
    console.id = id;
    console.open_func = open_func;
    console.write_func = write_func;
    console.read_func = read_func;
    console.close_func = close_func;
    strncpy(console.path, (char*) path, 256);

    consoles[console_count++] = console;
    return 1;
}
