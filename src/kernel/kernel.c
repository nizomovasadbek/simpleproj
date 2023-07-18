// #include "stdint.h"
#include "vga/screen.h"
// #include "io_port/io.h"

void kmain(void) {
    clearScreen();
    println("Hello World!");

    while(1);
}