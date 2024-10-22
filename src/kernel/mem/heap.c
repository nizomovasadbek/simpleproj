#include <heap.h>

void* malloc(size_t size) {
    Heap* heap = (Heap*) HEAP_MEMORY_START_POINT;
    while(heap->next != NULL) {
        heap = heap->next;
    }

    heap->size = size;
    heap->is_allocated = true;

    if(heap->prev == NULL) {
        heap->id = 1;
        return heap + sizeof(Heap);
    } else {
        heap->id = heap->prev->id + 1;
        heap += heap->prev->size + sizeof(Heap);
    }

    return heap;
}

void free(void* restrict ptr) {
    Heap* heap = (Heap*) ptr;
    heap->next = NULL;
    heap->prev = NULL;
    heap->is_allocated = false;
}