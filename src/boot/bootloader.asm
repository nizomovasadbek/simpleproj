[bits 16]
[org 0x7C00]
KERNEL_OFFSET equ 0x1000

bootloader_entry:
    mov sp, 0x9000
    mov bp, sp
    jmp bootloader_main

%include "src/boot/gdt.asm"
%include "src/boot/print.asm"
%include "src/boot/disk.asm"

bootloader_main:
    mov bx, bootloader_hello_message
    call print

    mov bx, kernel_loading_from_disk
    call print

    xor bx, bx
    mov es, bx
    mov bx, KERNEL_OFFSET
    call kernel_load

    mov bx, bootloader_switch_protected_mode
    call print

switch_protected_mode:
    cli
    lgdt [GDT_DESCRIPTOR]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp CODE_SEG:start_protected_mode

[bits 32]
start_protected_mode:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov fs, ax
    mov gs, ax

    mov esp, 0x900000
    mov ebp, esp

    mov ah, 0x0F
    mov al, 'A'
    mov [0xB8000], ax

    call KERNEL_OFFSET

return_value:
    jmp return_value

;[bits 16]
bootloader_hello_message:
    db "Booting OS...", ENDL, 0

bootloader_switch_protected_mode:
    db "System is switching to 32-bit protected mode", ENDL, 0

kernel_loading_from_disk:
    db "Kernel is loading from disk...", ENDL, 0

times 510-($-$$) db 0
dw 0xaa55