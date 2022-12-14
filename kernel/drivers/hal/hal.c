#include <drivers/hal/hal.h>

void hal_init() {
	GDT g_GDT = gdt_gdt(
		gdt_entry(0x0000, 0, 0, 0x00, 0x0, 0x0, 0),		//	NULL
		gdt_entry(0xFFFF, 0, 0, 0x9A, 0xA, 0xF, 0),		//	Kernel Code
		gdt_entry(0xFFFF, 0, 0, 0x92, 0xC, 0xF, 0),		//	Kernel Data
		gdt_entry(0xFFFF, 0, 0, 0xFA, 0xA, 0xF, 0),		//	User Code
		gdt_entry(0xFFFF, 0, 0, 0xF2, 0xC, 0xF, 0)			//	User Data
	);
	printf("GDT Addr: %x\n", &g_GDT);
	GDTDesc g_GDTR = gdt_gdtr(&g_GDT);
	printf("GDTR Addr: %x\n", &g_GDTR);
	//gdt_load(&g_GDTDesc);
}