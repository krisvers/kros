#include "limine.h"
#include <stdint.h>
#include <stddef.h>

struct limine_terminal_response * terminal;

const char * hex = "0123456789ABCDEF";

void puts(const char * str) {
	size_t len;
	for (len = 0; str[len] != '\0'; len++);
	terminal->write(terminal->terminals[0], str, len);
}

void putc(char c) {
	terminal->write(terminal->terminals[0], &c, 1);
}

void puts_num(unsigned long long number, int radix)
{
    char buffer[32];
    int pos = 0;

	if (radix == 16) {
		puts("0x");
	} else if (radix == 8) {
		puts("0o");
	} else if (radix == 2) {
		puts("0b");
	}

    // convert number to ASCII
    do 
    {
        unsigned long long rem = number % radix;
        number /= radix;
        buffer[pos++] = hex[rem];
    } while (number > 0);

    // print number in reverse order
    while (--pos >= 0) {
		putc(buffer[pos]);
	}
}

void main(struct limine_terminal_response * terminal_response) {
	terminal = terminal_response;
	// terminal->terminals[0]->columns = 80;
	// terminal->terminals[0]->rows = 25;
	
	puts("testing!\n");

	puts_num(terminal->terminals[0]->columns, 10);
	putc('\n');
	puts_num(terminal->terminals[0]->rows, 10);
}