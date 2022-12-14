#include <stdio.h>

static char const g_hexchars[16] = "0123456789ABCDEF";

static bool print(const char * data, size_t length) {
	const unsigned char * bytes = (const unsigned char *) data;
	for (size_t i = 0; i < length; i++)
		if (putc(bytes[i]) == EOF)
			return false;
	return true;
}

int putc(int ic) {
    tty_putc((char) ic);

    return ic;
}
 
int printf(const char * restrict format, ...) {
	va_list parameters;
	va_start(parameters, format);
 
	int written = 0;
 
	while (*format != '\0') {
		size_t maxrem = INT_MAX - written;
 
		if (format[0] != '%' || format[1] == '%') {
			if (format[0] == '%')
				format++;
			size_t amount = 1;
			while (format[amount] && format[amount] != '%')
				amount++;
			if (maxrem < amount) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, amount))
				return -1;
			format += amount;
			written += amount;
			continue;
		}
 
		const char* format_begun_at = format++;
 
		if (*format == 'c') {
			format++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(&c, sizeof(c)))
				return -1;
			written++;
		} else if (*format == 's') {
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else if (*format == 'i' || *format == 'd') {
			format++;
			int num = va_arg(parameters, int);
			char buffer[32];
			int pos = 0;

			do {
				unsigned long long rem = num % 10;
				num /= 10;
				buffer[pos++] = g_hexchars[rem];
			} while (num > 0);

			while (--pos >= 0) {
				putc(buffer[pos]);
			}
		} else if (*format == 'x') {
			putc('0'); putc('x');

			format++;
			int num = va_arg(parameters, int);
			char buffer[32];
			int pos = 0;

			do {
				unsigned long long rem = num % 16;
				num /= 16;
				buffer[pos++] = g_hexchars[rem];
			} while (num > 0);

			while (--pos >= 0) {
				putc(buffer[pos]);
			}
		} else {
			format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, len))
				return -1;
			written += len;
			format += len;
		}
	}
 
	va_end(parameters);
	return written;
}

int puts(const char * str) {
    return printf("%s\n", str);
}