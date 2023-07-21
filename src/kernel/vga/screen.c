#include "screen.h"
#include "cursor.h"

static u16* cursor = (u16*) VIDMEM;
static u16 line = 0;

void clearScreen() {
    i16* startAddr = (i16*) VIDMEM;
    for(u32 i = 0; i < SCREENSIZE; i++, startAddr++) {
        *startAddr = 0;
    }

    cursor = (u16*) VIDMEM;
    line = 0;
}

void printChar(char c, i8 attr) {
    if(c == '\n') {
        line++;
        cursor = (u16*) VIDMEM;
        cursor += line * 80;
        return;
    }
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

void printlnInfo(char* str) {
    while(*str) {
        printChar(*str, 0x03);
        str++;
    }
}

void printAt(char *message, u32 col, u32 row) {
    u16* currentCursor = cursor;
    cursor = (u16*) VIDMEM;
    u32 offset = 0;
    offset += col;
    offset += 80 * row;
    cursor += offset;
    println(message);
    cursor = currentCursor;
}