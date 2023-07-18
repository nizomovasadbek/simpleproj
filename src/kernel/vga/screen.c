#include "screen.h"

static u16* cursor = (u16*) 0xB8000;

void clearScreen() {
    i16* startAddr = (i16*) 0xB8000;
    for(u32 i = 0; i < SCREENSIZE; i++, startAddr++) {
        *startAddr = 0;
    }

    cursor = (u16*) 0xB8000;
}

void printChar(char c, i8 attr) {
    i16 sign = (i16) c;
    sign |= (attr << 8);
    *cursor = sign;
    cursor++;
}

void println(char* str) {
    while(*str) {
        printChar(*str, 0x0F);
        str++;
    }
}