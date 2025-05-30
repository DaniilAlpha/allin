#include "allin.h"

#if (!defined NO_STD_ALLOCATOR)

#  include <stdlib.h>

#  include <assert.h>

static void *std_allocator_alloc(void *const self, size_t const size) {
    assert(!self);
    return malloc(size);
}
static void *
std_allocator_realloc(void *const self, void *const ptr, size_t const size) {
    assert(!self);
    return realloc(ptr, size);
}
static void std_allocator_free(void *const self, void *const ptr) {
    assert(!self);
    free(ptr);
}

Allocator std_allocator() {
    void *const self = NULL;
    WRAP_BODY(
        Allocator,
        ALLOCATOR_INTERFACE(void),
        {
            .alloc = std_allocator_alloc,
            .realloc = std_allocator_realloc,
            .free = std_allocator_free,
        }
    );
}

#endif
