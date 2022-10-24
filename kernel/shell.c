#include <stdio.h>
#include <stdbool.h>
#include <keyboard.h>
#include <string.h>
#include <tty.h>
#include <video.h>

static unsigned char cursor = 0;
static char input;
static char previn;
static char argv[100];
static unsigned char argc;
static buffer[100];

void shell_init() {
	terminal_init();
}

void shell_run() {
	while (input = read_key_char() && strcmp(argv, "exit") != 0) {
		if (input != previn && input > 0) {
			putchar(input);
			memcpy(input, argv[strlen(argv)], 1);
			putchar(argv[strlen(argv)]);
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