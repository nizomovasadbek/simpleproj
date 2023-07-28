#ifndef _STRING_H
#define _STRING_H

#include "stdint.h"

i8 tolower(i8 c);
i8 toupper(i8 c);
void memcpy(void *restrict dst, const void *restrict src, const size_t size);

#endif