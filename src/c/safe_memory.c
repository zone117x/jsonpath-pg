// safe_memory.c
#include "safe_memory.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct AllocationNode
{
    void *ptr;
    struct AllocationNode *next;
} AllocationNode;

static AllocationNode *allocations_head = NULL;

void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr)
    {
        return NULL;
    }

    AllocationNode *new_node = (AllocationNode *)malloc(sizeof(AllocationNode));
    if (!new_node)
    {
        free(ptr);
        return NULL;
    }

    new_node->ptr = ptr;
    new_node->next = allocations_head;
    allocations_head = new_node;

    return ptr;
}

void *safe_calloc(size_t num, size_t size)
{
    void *ptr = calloc(num, size);
    if (!ptr)
    {
        return NULL;
    }

    AllocationNode *new_node = (AllocationNode *)malloc(sizeof(AllocationNode));
    if (!new_node)
    {
        free(ptr);
        return NULL;
    }

    new_node->ptr = ptr;
    new_node->next = allocations_head;
    allocations_head = new_node;

    return ptr;
}

void *safe_realloc(void *ptr, size_t new_size)
{
    if (!ptr)
    {
        return safe_malloc(new_size);
    }

    AllocationNode *current = allocations_head;

    while (current)
    {
        if (current->ptr == ptr)
        {
            void *new_ptr = realloc(ptr, new_size);
            if (!new_ptr)
            {
                return NULL;
            }
            current->ptr = new_ptr;
            return new_ptr;
        }
        current = current->next;
    }

    // If ptr is not found in the allocations list, return NULL
    return NULL;
}

void safe_free(void *ptr)
{
    if (!ptr)
    {
        return;
    }

    AllocationNode *prev = NULL;
    AllocationNode *current = allocations_head;

    while (current)
    {
        if (current->ptr == ptr)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                allocations_head = current->next;
            }
            free(ptr);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void free_all_allocations()
{
    AllocationNode *current = allocations_head;
    AllocationNode *temp;

    while (current)
    {
        temp = current;
        current = current->next;

        free(temp->ptr);
        free(temp);
    }

    allocations_head = NULL;
}
