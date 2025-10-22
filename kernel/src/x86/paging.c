#include <x86/paging.h>

extern void set_page_directory(u32* dir);
extern void enable_paging(void);
extern void disable_paging(void);

u32 page_directory[1024] __attribute__((aligned(4096)));
u32 page_table[1024] __attribute__((aligned(4096)));

void paging_init(void) {
    for (usize i = 0; i < 1024; ++i) {
        page_directory[i] = 0x00000002;
        page_table[i] = (i << 12) | 3;
    }
    page_directory[0] = ((u32) page_table) | 3;

    set_page_directory(page_directory);
    enable_paging();
}

void paging_map(u32 physical, u32 virtual, u32 flags) {
    
}
