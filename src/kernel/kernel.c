#include <cursor.h>
#include <keyboard.h>
#include <stdio.h>
#include <screen.h>

void kmain(void) {
    clearScreen();
    testPs2Controller();
    testPs2Port();
    u32 point = 32;

    printf("stack allocated variables address is 0x%X(%d)\n", &point, point);
    // printf("Hello, simple OS written %s\n", "in C");
    

    while(1);
}