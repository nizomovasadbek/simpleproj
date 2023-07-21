#include "cursor.h"
#include "../io_port/io.h"

i32 getCursorPosition(void) {
    outb(0x3D4, 14);
    i32 pos =  inb(0x3D5);
    pos <<= 8;
    
    outb(0x3D4, 15);
    pos += inb(0x3D5);

    return pos;
}