#include "keyboard/keyboard.h"
#include "vga/screen.h"

void kmain(void) {
    clearScreen();
    testPs2Controller();
    testPs2Port();

    while(1);
}