#include <stdio.h>
#include "shell.c"

extern char _BSS_START;
extern char _BSS_END;

void __attribute__((section(".entry"))) _kernelentry() {
	for (char * addr = &_BSS_START; addr < &_BSS_END; addr++) {
		* addr = 0;
	}

	printf("Starting shell.");

	shell_init();
	shell_run();

	

	while(1);
}
