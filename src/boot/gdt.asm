GDT_START:
    null_descriptor:
        dd 0
        dd 0
    code_descriptor:
        dw 0xFFFF
        dw 0
        db 0
        db 0b10011010
        db 0b11001111
        db 0
    data_descriptor:
        dw 0xffff
        dw 0
        db 0
        db 0b10010010
        db 0b11001111
        db 0
GDT_END:

GDT_DESCRIPTOR:
    dw GDT_END - GDT_START - 1
    dd GDT_START

CODE_SEG equ code_descriptor - GDT_START
DATA_SEG equ data_descriptor - GDT_START