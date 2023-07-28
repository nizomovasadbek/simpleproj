#ifndef _CURSOR_H
#define _CURSOR_H

#include "../std/stdint.h"

typedef struct {
    u16 row;
    u16 col;
} Cursor;

Cursor getCursorPosition(void);
void setCursorPosition(u32 pos);

#endif