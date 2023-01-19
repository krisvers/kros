#include <std/string.h>

int strlen(const char * str) {
	int len;
	for (len = 0; str[len] != 0; len++);

	return len;
}
