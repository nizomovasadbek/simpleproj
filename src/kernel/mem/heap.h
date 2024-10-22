#ifndef _KHEAP_H
#define _KHEAP_H

#include <string.h>
#define HEAP_MEMORY_START_POINT 0x100000
#define HEAP_MEMORY_END_POINT 0x5FFFFF

typedef struct Heap Heap;

struct Heap {
    u64 id;
    bool is_allocated;
    u64 size;
    Heap* next;
    Heap* prev;
};

void* malloc(size_t size);
void free(void *restrict ptr);

#endif