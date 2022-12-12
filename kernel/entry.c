#include <stdint.h>
#include <stddef.h>
#include "limine.h"

struct limine_terminal_request terminal_request = {
    LIMINE_TERMINAL_REQUEST,
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

struct limine_terminal_response * terminal_response;

// The following will be our kernel's entry point.
void _start(void) {
    if (terminal_request.response == NULL) {
        done();
    }

    terminal_response = terminal_request.response;

    if (!(terminal_response->terminal_count > 0)) {
        done();
    }

    main(terminal_response);

    // We're done, just hang...
    done();
}
