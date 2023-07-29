#ifndef _KHEAP_H
#define _KHEAP_H

#include <string.h>
#define HEAP_MEMORY_START_POINT 0x100000
#define HEAP_MEMORY_END_POINT 0x5FFFFF

typedef struct Heap Heap;

struct Heap {
    u64 id;
    bool allocated;
    u32 startPoint;
    u32 endPoint;
    u32 size;
};

#define HEAP_COUNT 200
#define MEMTABLE_SIZE sizeof(Heap) * HEAP_COUNT

#define FREE_SUCCESS            0x01
#define MEMORY_BLOCK_NOT_FOUND  0x02

void* malloc(size_t size);
i32 free(void *restrict ptr);

#endif