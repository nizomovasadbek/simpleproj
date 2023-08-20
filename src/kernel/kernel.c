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

    printf("Lower Hexadecimal %x\nUpper hexadecimal %X\n", 0xFAC0, 0xFAC0);

    while(1);
}
