#include <std/stdlib.h>

__attribute__((__noreturn__))
void abort(void) {
	// TODO: Add proper kernel panic.
    asm volatile("hlt");

	while (1);
	
	__builtin_unreachable();
}
