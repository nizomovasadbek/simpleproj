#include "vga/cursor.h"
#include "keyboard/keyboard.h"
#include "std/stdio.h"
#include "vga/screen.h"

void kmain(void) {
    clearScreen();
    testPs2Controller();
    testPs2Port();

    printf("Hello, SimpleOS written in C\n");
    clearScreen();

    i32 pos = getCursorPosition();    

    printf("Cursor position: %d\n", pos);
    while(1);
}