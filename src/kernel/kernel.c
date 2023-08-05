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

    while(1);
}
