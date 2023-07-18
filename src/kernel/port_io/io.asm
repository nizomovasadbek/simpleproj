[bits 32]

global port_byte_in

port_byte_in:

    push ebp
    mov ebp, esp
    add esp, 4

    xor eax, eax

    mov dx, word [esp]
    in ax, dx

    mov esp, ebp
    pop ebp
    ret

global port_byte_out

port_byte_out:
    push ebp
    mov ebp, esp

    add esp, 4
    mov al, byte [esp]
    inc esp
    mov dx, word [esp]

    mov esp, ebp
    pop ebp
    ret