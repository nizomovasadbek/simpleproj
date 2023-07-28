#include "vga/cursor.h"
#include "keyboard/keyboard.h"
#include "std/stdio.h"
#include "vga/screen.h"

void kmain(void) {
    clearScreen();
    testPs2Controller();
    testPs2Port();

    printf("Hello, SimpleOS written %s\n", "in C");
    printf("Test ptr!");
    // i32 pos = getCursorPosition();
    // i32 row = pos / 80;
    // i32 col = pos % 80;
    // printf("ROW: %d, COL: %d\n", row, col);

    while(1);
}