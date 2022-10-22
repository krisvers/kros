#include <terminal.h>

extern char _BSS_START;
extern char _BSS_END;

void __attribute__((section(".entry"))) _kernelentry() {
	for (char * addr = &_BSS_START; addr < &_BSS_END; addr++) {
		* addr = 0;
	}

	terminal_init();
	for (unsigned char i = 1; i <= 30; i++) {
		for (unsigned char j = 1; j <= 80; j++) {
			terminal_putchar(i+64);
		}
	}

	while (1);
}
