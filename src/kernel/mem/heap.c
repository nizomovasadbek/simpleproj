#include "heap.h"

static u64 data_ptr = HEAP_MEMORY_START_POINT + MEMTABLE_SIZE;
static u64 heap_ptr = HEAP_MEMORY_START_POINT;
static u64 id = 0;

void* malloc(size_t size) {
    if((data_ptr + size) >= HEAP_MEMORY_END_POINT) {
        return NULL;
    }

    Heap h;
    h.id = id;
    id++;
    h.allocated = true;
    h.size = size;
    h.startPoint = data_ptr;
    h.endPoint = data_ptr + size;
    data_ptr += size;

    memcpy((void*) (u32) heap_ptr, (void*) &h, sizeof(Heap));
    heap_ptr += sizeof(Heap);

    void* ret_ptr = (void*) h.startPoint;
    return ret_ptr;
}

void free(void *restrict ptr) {
    u64 startPtr = HEAP_MEMORY_START_POINT;
    Heap h;
    for(u32 i = 0; i < HEAP_COUNT; i++) {
        memcpy(&h, (void*) (u32) startPtr, sizeof(Heap));
        startPtr += sizeof(Heap);
        if(((void*) h.startPoint) == ptr) {
            h.allocated = false;
            break;
        }
    }
}