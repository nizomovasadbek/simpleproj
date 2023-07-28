#include "keyboard.h"
#include "../io_port/io.h"
#include "../std/stdint.h"
#include "../std/stdio.h"

void testPs2Controller() {
    outb(KEYBOARD_OUT_PORT, 0xAA);
    u16 result = (u16) inb(KEYBOARD_IN_PORT);

    if(result == 0x55) {
        printlnInfo("Successfully tested PS/2 controller\n");
        return;
    }

    printlnInfo("[TEST] Failed to get into connection with PS/2 controller\n");
}

void testPs2Port() {
    outb(KEYBOARD_OUT_PORT, 0xAB);
    u16 result = inb(KEYBOARD_IN_PORT);
    printf("Test result PS/2 PORT: 0x%X\n", result);
}