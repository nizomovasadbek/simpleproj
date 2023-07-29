#include <cursor.h>
#include <keyboard.h>
#include <stdio.h>
#include <screen.h>
#include <heap.h>
#include <stdint.h>

void kmain(void) {
    clearScreen();
    testPs2Controller();
    testPs2Port();
    i8* empty_str = (i8*) malloc(10);
    empty_str[0] = 'F';

    printf("stack allocated variables address is 0x%X('%c')\n", &empty_str, empty_str);
    // printf("Hello, simple OS written %s\n", "in C");
    
    free(empty_str);
    while(1);
}