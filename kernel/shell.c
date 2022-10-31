#include <stdio.h>
#include <stdbool.h>
#include <keyboard.h>
#include <string.h>
#include <tty.h>
#include <video.h>

static char input;
static char previn;

void shell_init() {
	terminal_init();
}

void shell_run() {
	while (input = read_key_char()) {
		if (input != previn && input > 0) {
			putchar(input);
		}

		previn = input;
	}
}

static void shell_prompt() {
	printf("kros -> ");
}

void program_exec(const char * prgm) {
	if (strcmp(prgm, "help") == 0) {
		printf("Woah did it work?\n");
	}
	if (strcmp(prgm, "exit") == 0) {
		printf("Exit?\n");
	}
}
