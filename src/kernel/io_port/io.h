#ifndef _IO_H
#define _IO_H

#include "../stdint.h"

#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5
#define RESTART_ADDRESS 0x64

extern u8 port_byte_in(u16 port);
extern void port_byte_out(u16 port, u8 data);
extern u16 port_word_in(u16 port);
extern void port_word_out(u16 port, i16 data);
void shutdown(void);

#endif