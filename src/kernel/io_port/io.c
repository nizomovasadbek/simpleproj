#include "io.h"

void shutdown() {
    port_byte_out(RESTART_ADDRESS, 0xFE);
}