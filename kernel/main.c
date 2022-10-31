#include <stdio.h>

extern char _BSS_START;
extern char _BSS_END;

void __attribute__((section(".entry"))) _kernelentry() {
	for (char * addr = &_BSS_START; addr < &_BSS_END; addr++) {
		* addr = 0;
	}

	printf("Kernel moment?\n\n");
	printf("Wow!\nMan that's crazy...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAMOGUS!");

	while(1);
}
