#include <drivers/terminal.h>

extern unsigned char zap_vga09_psf[];

struct PSF1Font
{
	uint16_t magic;
	uint8_t  mode;
	uint8_t  charsize;
};

static const uint32_t PSF1_FONT_WIDTH  = 8;
static const uint32_t PSF1_HEADER_SIZE = sizeof(struct PSF1Font);
static const uint32_t PSF1_MODE512     = 0x01;

static bool                     initialized      = false;
static struct limine_framebuffer * framebuffer   = NULL;
static struct PSF1Font *        font             = (struct PSF1Font *) zap_vga09_psf;
static uint32_t                 x                = 1;
static uint32_t                 y                = 1;
static short int                font_scale       = 1;
static uint32_t					fg_color		 = FG_COLOR;
static uint32_t					bg_color		 = BG_COLOR;

void tty_init(struct limine_framebuffer * buffer, short int scale) {
	framebuffer = buffer;
	tty_fill(bg_color);
	font_scale = scale;
	initialized = true;
}

void tty_setfgcolor(uint32_t color) {
	fg_color = color;
}

void tty_setbgcolor(uint32_t color) {
	bg_color = color;
}

void tty_putpix(uint64_t x, uint64_t y, uint32_t argb) {
	((uint32_t *) framebuffer->address)[((framebuffer->width * y) + x)] = argb;
}

void tty_puts(const char * str) {
	for (int i = 0; str[i] != 0; i++) {
		tty_putc(str[i]);
	}
}

void tty_putc(uint32_t c) {
	if (!initialized) return;
	const uint32_t glyphCount  = font->mode == PSF1_MODE512 ? 512 : 256;
	uint32_t charactersPerLine = (framebuffer->width / (PSF1_FONT_WIDTH + 2)) + 30;
	uint32_t charactersPerRow  = (framebuffer->height / (font->charsize + 2)) + 17;

	switch (c)
	{
		case '\a': break;
		case '\b':
			x--;
			tty_putc(' ');
			x--;
			break;
		case '\f': break;
		case '\n': y++; x = 1; goto check_y;
		case '\r': x = 1; break;
		case '\t':
		{
			static const uint8_t tabSize = 4;
			uint8_t toSkip = x % tabSize;
			
			if (toSkip % 4 == 0) {
				x += 4;
			} else {
				x += (tabSize - toSkip) * font_scale;
			}
		}
		break;
		case '\v': y += 4; goto check_y;

		default:
		{
			uint32_t bytesPerLine = (PSF1_FONT_WIDTH + 7) / 8;

			uint8_t* glyph        = (uint8_t*)font + PSF1_HEADER_SIZE
						   + (c > 0 && c < glyphCount ? c : 0) * font->charsize;

			uint32_t ypos = y * font->charsize;
			uint32_t xpos = x * PSF1_FONT_WIDTH + 1;
			for (uint32_t _y = ypos; _y < (font->charsize + ypos); _y++)
			{
				uint32_t mask = 1 << (PSF1_FONT_WIDTH - 1);
				for (uint32_t _x = xpos; _x < (PSF1_FONT_WIDTH + xpos); _x++)
				{
					for (short a = 0; a < font_scale; a++) {
						for (short b = 0; b < font_scale; b++) {
							tty_putpix((_x * font_scale) + a, (_y * font_scale) + b, *((uint32_t*)glyph) & mask ? fg_color : bg_color);
						}
					}
					mask >>= 1;
				}
				glyph += bytesPerLine;
			}
			x++;
		}
		break;
	}
	if (x >= charactersPerLine / font_scale)
	{
		x = 1;
		y++;
	check_y:
		if (y >= charactersPerRow / font_scale)
		{
			x = 1;
			y--;
			for (size_t i = 0; i < font_scale * PSF1_FONT_WIDTH; i++) {
				tty_smoothscroll();
			}
		}
	}
}

void tty_fill(uint32_t argb) {
	for (uint64_t i = 0; i < framebuffer->width * framebuffer->height; i++) {
		((uint32_t *) framebuffer->address)[i] = argb;
	}
}

void tty_smoothscroll() {
	x = 1; y = 1; tty_fill(bg_color);
	/*for (size_t x = 0; x < framebuffer->width; x++) {
		for (size_t y = 0; y < framebuffer->height; y++) {
			((uint32_t *) framebuffer->address)[x + (y * framebuffer->width)] = (size_t) ((uint32_t *) framebuffer->address)[x + ((y + 1) * framebuffer->width)];
		}
	}*/
}

#pragma region font
unsigned char zap_vga09_psf[]
	= {
		#include "PSF_FONT"
	};
#pragma endregion
unsigned int zap_vga09_psf_len = 3520;