#include <drivers/hal/hal.h>

void hal_init() {
	GDT g_GDT = {
		{ 0x0000, 0, 0, 0x00, 0x00, 0 },        //    NULL
		{ 0xFFFF, 0, 0, 0x9A, 0xAF, 0 },        //    Kernel Code
    	{ 0xFFFF, 0, 0, 0x92, 0xCF, 0 },        //    Kernel Data
    	{ 0xFFFF, 0, 0, 0xFA, 0xAF, 0 },        //    User Code
    	{ 0xFFFF, 0, 0, 0xF2, 0xCF, 0 }        //    User Data
	};

	printf("GDT Addr: %x\n", &g_GDT);
	// printf("GDT Entry Addresses {\n\tNULL: %x\n\tKernel Code: %x\n\tKernel Data: %x\n\tUser Code: %x\n\tUser Data: %x\n}\n", &g_GDT.null, &g_GDT.kernelCode, &g_GDT.kernelData, &g_GDT.userCode, &g_GDT.userData);
	// printf("GDT Entries {\n\tNULL {\n\t\t%x, %x, %x, %x, %x, %x, %x\n\t}\n\tKernel Code {\n\t\t%x, %x, %x, %x, %x, %x, %x\n\t}\n\tKernel Data {\n\t\t%x, %x, %x, %x, %x, %x, %x\n\t}\n\tUser Code {\n\t\t%x, %x, %x, %x, %x, %x, %x\n\t}\n\tUser Data {\n\t\t%x, %x, %x, %x, %x, %x, %x\n\t}\n}\n", g_GDT.null.limit, g_GDT.null.baseLow, g_GDT.null.baseMiddle, g_GDT.null.access, (g_GDT.null.limitHighFlags & 0xF0) >> 4, g_GDT.null.limitHighFlags & 0x0F, g_GDT.null.baseHigh, g_GDT.kernelCode.limit, g_GDT.kernelCode.baseLow, g_GDT.kernelCode.baseMiddle, g_GDT.kernelCode.access, (g_GDT.kernelCode.limitHighFlags & 0xF0) >> 4, g_GDT.kernelCode.limitHighFlags & 0x0F, g_GDT.kernelCode.baseHigh, g_GDT.kernelData.limit, g_GDT.kernelData.baseLow, g_GDT.kernelData.baseMiddle, g_GDT.kernelData.access, (g_GDT.kernelData.limitHighFlags & 0xF0) >> 4, g_GDT.kernelData.limitHighFlags & 0x0F, g_GDT.kernelData.baseHigh, g_GDT.userCode.limit, g_GDT.userCode.baseLow, g_GDT.userCode.baseMiddle, g_GDT.userCode.access, (g_GDT.userCode.limitHighFlags & 0xF0) >> 4, g_GDT.userCode.limitHighFlags & 0x0F, g_GDT.userCode.baseHigh, g_GDT.userData.limit, g_GDT.userData.baseLow, g_GDT.userData.baseMiddle, g_GDT.userData.access, (g_GDT.userData.limitHighFlags & 0xF0) >> 4, g_GDT.userData.limitHighFlags & 0x0F, g_GDT.userData.baseHigh);
	GDTDesc g_GDTR = { sizeof(g_GDT) - 1, &g_GDT };
	printf("GDTR Addr: %x\n", &g_GDTR);
	printf("GDTR Values: size: %i, ptr: %x\n", g_GDTR.Size, g_GDTR.Offset);
	gdt_load(&g_GDTR);
	gdt_reload_segments();
}