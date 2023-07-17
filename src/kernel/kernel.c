#include "stdint.h"
#include "vga/screen.h"

void kmain(void) {
    clearScreen();
    i16 attribute = (i16) 'Q';
    attribute |= (0x0F << 8);
    *(i16*) 0xB8000 = attribute;
    while(1);
}