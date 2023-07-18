#ifndef _SCREEN_H
#define _SCREEN_H

#include "../stdint.h"

#define SCREENSIZE (80*25)

void clearScreen();
void println(char*);
void printChar(char, i8);
void printlnInfo(char* str);

#endif