#include <stdint.h>
#include <stddef.h>
#include "limine.h"

struct limine_framebuffer_request framebuffer_request = {
	LIMINE_FRAMEBUFFER_REQUEST,
	0
};

void main();

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent.

static void done(void) {
	for (;;) {
		__asm__("hlt");
	}
}

struct limine_framebuffer_response * framebuffer_response;

// The following will be our kernel's entry point.
void _start(void) {
	if (framebuffer_request.response == NULL) {
		done();
	}

	framebuffer_response = framebuffer_request.response;

	if (!(framebuffer_response->framebuffer_count > 0)) {
		done();
	}

	main(framebuffer_response->framebuffers[0]);

	// We're done, just hang...
	done();
}
