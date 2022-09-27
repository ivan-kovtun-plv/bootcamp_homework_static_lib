#include <stdlib.h>
#include <stddef.h>
#include "SimpleMemoryControl.h"

#define ALLOCATIONS_MAX_QUANTITY 64

/* TO UPGRATE:
    typedef struct { allocatedMemory[...]; q-tity;
    } block;
    func(args) -> func(args, *blok)
*/


static void *allocatedMemory[ALLOCATIONS_MAX_QUANTITY];
static int allocationsQuantity = 0;

void *allocateMemory(size_t size) {
    if (allocationsQuantity >= ALLOCATIONS_MAX_QUANTITY) {
        return NULL;
    }
    void *ptr = malloc(size);
    allocatedMemory[allocationsQuantity++] = ptr;
    return ptr;
}

void deallocateAll(void) {
    for(int i = 0; i < allocationsQuantity; i++) {
        free(allocatedMemory[i]);
    }
}
