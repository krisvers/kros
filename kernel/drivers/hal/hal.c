#include <drivers/hal/hal.h>

void hal_init() {
	GDT * g_GDT = gdt_gdt(
		gdt_entry(0x0000, 0, 0, 0x00, 0x00, 0x0, 0),		//	NULL
		gdt_entry(0xFFFF, 0, 0, 0x9A, 0x0A, 0xF, 0),		//	Kernel Code
		gdt_entry(0xFFFF, 0, 0, 0x92, 0x0C, 0xF, 0),		//	Kernel Data
		gdt_entry(0xFFFF, 0, 0, 0xFA, 0x0A, 0xF, 0),		//	User Code
		gdt_entry(0xFFFF, 0, 0, 0xF2, 0x0C, 0xF, 0)			//	User Data
	);
	GDTDesc * g_GDTDesc = gdt_gdtr(g_GDT);
	gdt_load(g_GDTDesc);
}