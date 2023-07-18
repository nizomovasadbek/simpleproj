#include "stdio.h"

#define WHITE_ON_BLACK 0x0F

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

void printDec(i32 num) {
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