#ifndef _IO_H
#define _IO_H

#include "../stdint.h"

#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5
#define RESTART_ADDRESS 0x64

u8 inb(u16 port);
void outb(u16 port, u8 data);
u16 inw(u16 port);
void outw(u16 port, u16 data);
void shutdown(void);

#endif