// safe_memory.h
#ifndef SAFE_MEMORY_H
#define SAFE_MEMORY_H

#include <stddef.h>

void *safe_malloc(size_t size);
void *safe_calloc(size_t num, size_t size);
void *safe_realloc(void *ptr, size_t new_size);
void safe_free(void *ptr);
void safe_free_all_allocations();

#endif // SAFE_MEMORY_H
