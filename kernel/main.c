#include <stdio.h>
#include <string.h>
#include <keyboard.h>

extern char _BSS_START;
extern char _BSS_END;

void __attribute__((section(".entry"))) _kernelentry() {
	for (char * addr = &_BSS_START; addr < &_BSS_END; addr++) {
		* addr = 0;
	}

	terminal_init();

	printf("Test \n\n");

	char c;
	char prev = 0;

	while((c = read_key_char()) != 'q') {
		//if (c != prev && c != 101) {
		//	printf("%i", c);
		//}

		if (c != prev && c > 0) {
			putchar(c);
		}

		prev = c;
	}

	printf("Quit!\n");

	while(1);
}
