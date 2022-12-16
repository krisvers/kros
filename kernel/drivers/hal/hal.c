#include <drivers/hal/hal.h>

void hal_init() {
	GDT g_GDT = {
		{ 0x0000, 0, 0, 0x00, 0x00, 0 },		//    NULL
		{ 0xFFFF, 0, 0, 0x9A, 0xAF, 0 },		//    Kernel Code
    	{ 0xFFFF, 0, 0, 0x92, 0xCF, 0 },		//    Kernel Data
    	{ 0xFFFF, 0, 0, 0xFA, 0xAF, 0 },		//    User Code
    	{ 0xFFFF, 0, 0, 0xF2, 0xCF, 0 }			//    User Data
	};

	GDTDesc g_GDTR = { sizeof(g_GDT) - 1, &g_GDT };

	printf("GDT: %x, GDTR: %x\n", &g_GDT, &g_GDTR);

	gdt_load(&g_GDTR);
	gdt_reload_segments();
}