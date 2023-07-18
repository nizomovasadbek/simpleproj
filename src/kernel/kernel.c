#include "keyboard/keyboard.h"
#include "std/stdio.h"

void kmain(void) {
    clearScreen();
    testPs2Controller();
    testPs2Port();

    printf("Hello SimpleOS written in C\n");

    while(1);
}