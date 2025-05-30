#ifndef ALLIN_H
#define ALLIN_H

#include <stddef.h>

#include <woodi.h>

#define ALLOCATOR_INTERFACE(Self)                                              \
  {                                                                            \
    void *(*const alloc)(Self *const self, size_t const size);                 \
    void *(*const realloc                                                      \
    )(Self *const self, void *const ptr, size_t const new_size);               \
    void (*const free)(Self *const self, void *const ptr);                     \
  }
WRAPPER(Allocator, ALLOCATOR_INTERFACE);

static inline void *allocator_alloc(Allocator *const self, size_t const size) {
    return WRAPPER_CALL(alloc, self, size);
}
static inline void *
allocator_realloc(Allocator *const self, void *const ptr, size_t const size) {
    return WRAPPER_CALL(realloc, self, ptr, size);
}
static inline void allocator_free(Allocator *const self, void *const ptr) {
    WRAPPER_CALL(free, self, ptr);
}

#if (!defined NO_STD_ALLOCATOR)
Allocator std_allocator();
#endif

#endif
