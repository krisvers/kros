[bits 32]

; void __attribute__((cdecl)) i686_IDT_Load(IDTDescriptor* idtDescriptor);
global idt_load
idt_load:

    ; make new call frame
    push ebp             ; save old call frame
    mov ebp, esp         ; initialize new call frame
    
    ; load idt
    mov eax, [ebp + 8]
    lidt [eax]

    ; restore old call frame
    mov esp, ebp
    pop ebp
    ret