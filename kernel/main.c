#include <video/font.h>

void main() {
	text_putc(0, 0, '!', RED);
	text_putc(5, 0, '!'+1, ORANGE);
	text_putc(10, 0, '!'+2, YELLOW);
	text_putc(15, 0, '!'+3, GREEN);
}