#include <terminal.h>

extern char _BSS_START;
extern char _BSS_END;

void __attribute__((section(".entry"))) _kernelentry() {
	for (char * addr = &_BSS_START; addr < &_BSS_END; addr++) {
		* addr = 0;
	}

	terminal_init();
	terminal_putstr("Woah! That's crazy.\nIs this new line?");

	while (1);
}
