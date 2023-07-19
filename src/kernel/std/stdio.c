#include "stdio.h"

#define WHITE_ON_BLACK 0x0F

void printHex(i32 num);
void printDec(i32 num);

void printf(i8* str, ...) {
    void* argp = &str;
    argp += 4;
    i8 character = 0;

    while(*str) {
        if(*str == '%') {
            switch(str[1]) {
                case 0:
                    str++;
                    break;
                case '%':
                    printChar('%', WHITE_ON_BLACK);
                    str += 2;
                    break;
                case 'c':
                    character = *(i8*) argp;
                    printChar(character, WHITE_ON_BLACK);
                    str += 2;
                    argp += sizeof(i8);
                    break;

                case 'd':
                    printDec(*(i32*) argp);
                    argp += sizeof(i32);
                    str += 2;
                    break;

                case 'X':
                case 'x':
                    printHex(*(i32*) argp);
                    argp += sizeof(i32);
                    str += 2;
                    break;

                default:
                    str += 2;
                    break;
            }
        } else {
            printChar(*str, 0x0F);
            str++;
        }
    }
}

void printHex(i32 num) {
    if(!num) {
        printChar('0', WHITE_ON_BLACK);
        return;
    }

    i8 digit[] = { '0', '1', '2', '3', '4', '5', '6',
    '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    i8 hex[10];
    u16 rem = 0;
    u32 n = 0;
    while(num) {
        rem = num % 16;
        num /= 16;
        hex[n++] = digit[rem];
    }

    for(i32 i = n-1; i >= 0; i--) {
        printChar(hex[i], WHITE_ON_BLACK);
    }
}

void printDec(i32 num) {
    if(!num) {
        printChar('0', WHITE_ON_BLACK);
        return;
    }
    i8 digit[10];
    u32 n = 0;
    while(num) {
        digit[n] = num % 10;
        num /= 10;
        n++;
    }

    for(i32 i = n-1; i >= 0; i--) {
        printChar(digit[i] + 48, WHITE_ON_BLACK);
    }
}