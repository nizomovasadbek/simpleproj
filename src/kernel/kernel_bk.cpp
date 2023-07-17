#include "stdint.h"

extern "C" void kmain(void) {
    i16 attr = (i16) 'Q';
    attr |= (0x0F << 8);
    *(i16*) 0xB8000 = attr;
    while(1);
}