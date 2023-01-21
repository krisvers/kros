#include <std/string.h>

int strlen(const char * str) {
	int len;
	for (len = 0; str[len] != 0; len++);

	return len;
}

void memcpy(void * p1, void * p2, size_t size) {
    for (size_t i = 0; i < size; i++) {
        ((uint8_t *) p2)[i] = ((uint8_t *) p1)[i];
    }
}

void memset(size_t num, void * p1, size_t size) {
    for (size_t i = 0; i < size; i++) {
        ((uint8_t *) p1)[i] = num;
    }
}

size_t strcmp(const char * str1, char * str2) {
    size_t diff = 0;
    for (size_t i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            diff++;
        }
    }
    return diff;
}