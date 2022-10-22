#include <stdio.h>
#include <string.h>

extern char _BSS_START;
extern char _BSS_END;

void __attribute__((section(".entry"))) _kernelentry() {
	for (char * addr = &_BSS_START; addr < &_BSS_END; addr++) {
		* addr = 0;
	}

	terminal_init();

	printf("Test \n\n\n%s", "Woah this is an argument!");

	while (1);
}
