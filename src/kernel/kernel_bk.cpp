// unused file...
#include <stdint.h>

extern "C" void kmain(void) {
    i16 attr = (i16) 'C';
    attr |= (0x0F << 8);
    *(i16*) 0xB8000 = attr;
    attr = (i16) '+';
    attr |= (0x0F << 8);
    *(i16*) 0xB8002 = attr;
    *(i16*) 0xB8004 = attr;
    while(1);
}