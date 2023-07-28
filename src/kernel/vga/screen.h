#ifndef _SCREEN_H
#define _SCREEN_H

#include "../std/stdint.h"

#define SCREENSIZE (80*25)
#define VIDMEM 0xB8000
#define SCREEN_CTRL 0x3D4
#define SCREEN_DATA 0x3D5

void clearScreen();
void println(char*);
void printChar(char, i8);
void printlnInfo(char* str);
void printAt(char* message, u32 col, u32 row);

#endif