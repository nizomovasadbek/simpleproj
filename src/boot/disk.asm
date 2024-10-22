kernel_load:

    push ax
    push bx
    push dx
    push cx
    push si
    mov si, 3

    mov ch, 0
    mov cl, 2
    mov dh, 0
    mov dl, 0

kernel_load_loop:
    clc
    cmp si, 0
    je kernel_load_done_error
    mov ah, 0x02
    mov al, 20
    dec si
    int 0x13
    jc kernel_load_loop
    jmp kernel_load_done

kernel_load_done_error:
    pop si
    pop cx
    pop dx
    pop bx
    pop ax
    
    push bx
    mov bx, error_disk_read
    call print
    pop bx
    ret

kernel_load_done:
    pop si
    pop cx
    pop dx
    pop bx
    pop ax

    push bx
    mov bx, disk_successfully_read
    call print
    pop bx
    ret

error_disk_read:
    db "Error reading from disk!", 0x0a, 0x0d, 0

disk_successfully_read:
    db "Successfully read the kernel", 0x0a, 0x0d, 0