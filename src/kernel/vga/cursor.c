#include "cursor.h"
#include <io.h>
#include "screen.h"
#include <stdio.h>

Cursor getCursorPosition(void) {
    outb(0x3D4, 14);
    i32 pos = inb(0x3D5);
    pos <<= 8;
    
    outb(0x3D4, 15);
    pos += inb(0x3D5);
    __attribute__((unused)) Cursor c;
    c.row = pos / 80;
    c.col = pos % 80;

    return c;
}

void setCursorPosition(u32 pos) {
    if(pos >= SCREENSIZE) {
        return;
    }
    outb(SCREEN_CTRL, 14);
    outb(SCREEN_DATA, (u8)(pos >> 8));
    outb(SCREEN_CTRL, 15);
    outb(SCREEN_DATA, (u8)(pos & 0xFF));
}