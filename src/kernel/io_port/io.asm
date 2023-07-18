[bits 32]

global port_byte_in

port_byte_in:

    push ebp
    mov ebp, esp
    add esp, 4

    xor eax, eax

    mov dx, word [esp]
    in al, dx

    mov esp, ebp
    pop ebp
    ret

global port_byte_out

port_byte_out:
    push ebp
    mov ebp, esp
    add esp, 4

    mov dx, word [esp]
    add esp, 2
    mov al, [esp]
    
    out dx, al

    mov esp, ebp
    pop ebp
    ret

global port_word_in
port_word_in:

    xor eax, eax

    mov dx, word [esp]
    in ax, dx

    ret

global port_word_out
port_word_out:
    push eax
    push edx

    push ebp
    mov ebp, esp
    add esp, 4

    mov dx, word [esp]
    add esp, 2
    mov ax, word [esp]

    out dx, ax

    mov esp, ebp
    pop ebp

    pop edx
    pop eax

    ret