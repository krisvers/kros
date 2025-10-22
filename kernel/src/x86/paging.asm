[bits 32]

global set_page_directory
set_page_directory:
    push ebp
    mov ebp, esp

    mov eax, [esp + 8]
    mov cr3, eax

    pop ebp
    ret

global enable_paging
enable_paging:
    mov eax, cr0
    or eax, 0x80000000
    mov cr0, eax

    ret

global disable_paging
disable_paging:
    mov eax, cr0
    and eax, 0x7FFFFFFF
    mov cr0, eax

    ret
