// #include "stdint.h"
#include "vga/screen.h"
#include "io_port/io.h"

void kmain(void) {
    clearScreen();
    println("Hello World!");

    port_byte_out(REG_SCREEN_CTRL, 14);

    while(1);
}