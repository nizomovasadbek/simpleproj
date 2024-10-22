#include "string.h"

i8 tolower(i8 c) {
    return (c >= 'A' && c <= 'Z')?c+32:c;
}

i8 toupper(i8 c) {
    return (c >= 'a' && c <= 'z')?c-32:c;
}

void memcpy(void *restrict dst, const void *restrict src, size_t size) {
    if(!dst || !src) return;
    i8* d = (i8*) dst;
    i8* s = (i8*) src;
    u64 n = 0;
    while(n != size) {
        d[n] = s[n];
        n++;
    }
}

size_t strlen(const char *restrict str) {
    size_t len = 0;
    while(*str) {
        len++;
        str++;
    }

    return len;
}

void strcpy(char* restrict dst, const char* restrict src, const size_t size) {
    size_t dst_len = strlen(dst);
    size_t src_len = strlen(src);
    if(src_len > size || dst_len > size) {
        return;
    }

    memcpy(dst, src, size);
}