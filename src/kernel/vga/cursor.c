#include "cursor.h"
#include "../io_port/io.h"
#include "screen.h"

i32 getCursorPosition(void) {
    outb(0x3D4, 14);
    i32 pos =  inb(0x3D5);
    pos <<= 8;
    
    outb(0x3D4, 15);
    pos += inb(0x3D5);

    return pos;
}

void setCursorPosition(u32 pos) {
    pos >>= 1;
    outb(SCREEN_CTRL, 14);
    outb(SCREEN_DATA, (u8)(pos >> 8));
    outb(SCREEN_CTRL, 15);
    outb(SCREEN_DATA, (u8)(pos & 0xFF));
}