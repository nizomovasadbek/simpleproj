%define ENDL 0x0a, 0x0d

print:
    push bx
    push ax
    mov ah, 0x0E

print_loop:
    mov al, [bx]
    cmp al, 0
    je print_done
    int 0x10
    inc bx
    jmp print_loop

print_done:
    pop ax
    pop bx
    ret