#ifndef _STRING_H
#define _STRING_H

#include <stdint.h>

i8 tolower(i8 c);
i8 toupper(i8 c);
void memcpy(void *restrict dst, const void *restrict src, const size_t size);
size_t strlen(const char *restrict str);
void strcpy(char* restrict dst, const char* restrict src, const size_t size);

#endif
