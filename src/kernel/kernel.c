#include "keyboard/keyboard.h"
#include "std/stdio.h"
#include "vga/screen.h"

void kmain(void) {
    clearScreen();
    testPs2Controller();
    testPs2Port();

    printf("Hello, SimpleOS written in C\n");
    clearScreen();
    printf("Adjusting volume: %d%%\n", 92);

    while(1);
}