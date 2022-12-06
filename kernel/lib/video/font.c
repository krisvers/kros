#include <video/font.h>

static const char font[] = {
0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 

// Above is 0-31 (Unprintable chars)

// Printable chars:

// ' ' to '/':

0b00000000, 0b00000000, 0b00000010, 0b00100010, 0b00000010, 0b01010101, 0b00000000, 0b00000101, 0b11110101, 0b11111010, 0b01101000, 0b11000001, 0b01101001, 0b00100100, 0b01001001, 0b01101000, 0b01011001, 0b01100000, 0b00000000, 0b00000000, 0b00100100, 0b01000100, 0b00100100, 0b00100010, 0b00100100, 0b00011111, 0b01001111, 0b10000010, 0b00100111, 0b00100010, 0b00000000, 0b00000010, 0b01100000, 0b00000110, 0b00000000, 0b00000000, 0b00000000, 0b00101000, 0b01000100, 0b00100001,

// '0' to '?':

0b01101001, 0b10011001, 0b01100110, 0b00100010, 0b00100111, 0b01101001, 0b00010100, 0b11111110, 0b00010010, 0b00011110, 0b10001001, 0b11110001, 0b00011111, 0b10000110, 0b00011110, 0b11111000, 0b11111001, 0b11111111, 0b00010010, 0b00100010, 0b01101001, 0b01101001, 0b01101111, 0b10011111, 0b00010001, 0b00000100, 0b00000100, 0b00000000, 0b00100000, 0b00100110, 0b00010110, 0b10000110, 0b00010000, 0b11100000, 0b11100000, 0b10000110, 0b00010110, 0b10000110, 0b10010010, 0b00000010,

// '@', 'A' to 'Z', '[':

0b01101011, 0b11011011, 0b01100110, 0b10011111, 0b10011001, 0b11101001, 0b11101001, 0b11100111, 0b10001000, 0b10000111, 0b11101001, 0b10011001, 0b11101111, 0b10001110, 0b10001111, 0b11111000, 0b11101000, 0b10000111, 0b10001011, 0b10010111, 0b10011001, 0b11111001, 0b10011111, 0b01100110, 0b01101111, 0b11110010, 0b00101010, 0b01101001, 0b10101100, 0b10101001, 0b10001000, 0b10001000, 0b11111111, 0b11111001, 0b10011001, 0b10011101, 0b10111001, 0b10011111, 0b10011001, 0b10011111, 0b11101001, 0b11101000, 0b10000110, 0b10011001, 0b10010111, 0b11101001, 0b11101010, 0b10010111, 0b10000110, 0b00011110, 0b11110110, 0b01100110, 0b01101001, 0b10011001, 0b10010110, 0b10011001, 0b10010110, 0b01101001, 0b10011001, 0b11111001, 0b10011001, 0b01101001, 0b10011001, 0b10010110, 0b01100110, 0b11110001, 0b01101000, 0b11110110, 0b01000100, 0b01000110, 

// '|' to '_':

0b01000100, 0b01000100, 0b01000110, 0b00100010, 0b00100110, 0b01001010, 0b00000000, 0b00000000, 0b00000000, 0b00001111, 

// '`', 'a' to 'z', '}':

0b01000010, 0b00000000, 0b00000000, 0b01111001, 0b10010111, 0b10001000, 0b11100001, 0b11110000, 0b01111000, 0b10000111, 0b00010001, 0b01111001, 0b01110000, 0b11111001, 0b11101111, 0b00000010, 0b01001110, 0b01000000, 0b01101001, 0b01111111, 0b10001000, 0b11101001, 0b10010010, 0b00000010, 0b00100010, 0b00100000, 0b00100010, 0b01001000, 0b10001010, 0b11001010, 0b01000100, 0b01000100, 0b00100000, 0b00001111, 0b11011001, 0b00000000, 0b11101001, 0b10010000, 0b01101001, 0b10010110, 0b00001110, 0b00011110, 0b10000000, 0b01111001, 0b01110001, 0b00000000, 0b11101001, 0b10000000, 0b01111100, 0b00111110, 0b00000100, 0b11100100, 0b00100000, 0b00001001, 0b10010111, 0b00000000, 0b10010110, 0b01100000, 0b10011001, 0b11111001, 0b00000000, 0b10010110, 0b10010000, 0b10010111, 0b00010011, 0b00001111, 0b00111100, 0b11110100, 0b00100100, 0b00100100, 

// '|' to DEL:

0b00100010, 0b00100010, 0b00100100, 0b00100100, 0b00100100, 0b00000000, 0b01011010, 0b00000000, 0b00000000, 0b00000000, 

};

// 65

void text_putc(int x, int y, char c, enum vga_color color) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            vga_putpixel(x - i + 4, y - j + 5, color * bitget(font[c*5/2 + ((j * 4) + i)/8], (((j * 4) + i) % 8)));
        }
    }
}