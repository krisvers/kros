ENTRY(_kernelentry)

KERNEL_BASE = 0x502;

MEMORY
{
	ram (rwx) : org = KERNEL_BASE, l = 25600
}

SECTIONS {
	. = KERNEL_BASE;

	.entry (KERNEL_BASE) : {
		*(.entry)
	} > ram

	.text : {
		*(.text)
	} > ram

	.rodata : {
		*(.rodata)
	} > ram

	.data : {
		*(.data)
	} > ram

	.bss : {
		_BSS_START = ABSOLUTE(.);
		*(.bss)
		_BSS_END = ABSOLUTE(.);
	} > ram
}
