#ifndef _IO_H
#define _IO_H

#include "../stdint.h"

extern u16 port_byte_in(u16 port);
extern void port_byte_out(u16 port, u8 data);

#endif