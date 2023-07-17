#include "screen.h"
#include "../stdint.h"

void clearScreen() {
    i16* startAddr = (i16*) 0xB8000;
    for(u32 i = 0; i < SCREENSIZE; i++, startAddr++) {
        *startAddr = 0;
    }
}