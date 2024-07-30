#include "my_malloc.h"
#include "linked_list.h"

void* init_mmap(size_t size) {
    void* ptr = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }
    return ptr;
}

void* request_more_memory(size_t size) {
    size_t total_size = size + sizeof(elem_t);
    void* ptr = init_mmap(total_size);
    if (!ptr) {
        DEBUG_PRINT("Memory allocation failed\n");
        return NULL;
    }

    elem_t* block = (elem_t*)ptr;
    block->size = size;
    block->is_used = true;
    block->ptr_for_the_user = (void*)((char*)ptr + sizeof(elem_t));
    block->next = NULL;

    append_to_list(block);

    DEBUG_PRINT("Memory allocated at: %p\n", block->ptr_for_the_user);
    return block->ptr_for_the_user;
}

void* my_malloc(size_t size) {
    if (size <= 0) return NULL;

    elem_t* block = find_free_block(size);
    if (block) {
        block->is_used = true;
        return block->ptr_for_the_user;
    }

    return request_more_memory(size);
}

void my_free(void* ptr) {
    if (!ptr) {
        DEBUG_PRINT("Error: Trying to free an invalid pointer\n");
        return;
    }

    elem_t* block = (elem_t*)((char*)ptr - sizeof(elem_t));
    block->is_used = false;

    coalesce_free_blocks();
}

void* my_calloc(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;
    void* ptr = my_malloc(total_size);
    if (ptr) {
        memset(ptr, 0, total_size);
    }
    return ptr;
}

void* my_realloc(void* ptr, size_t size) {
    if (!ptr) return my_malloc(size);
    if (size == 0) {
        my_free(ptr);
        return NULL;
    }

    elem_t* block = (elem_t*)((char*)ptr - sizeof(elem_t));
    if (block->size >= size) {
        return ptr;
    }

    void* new_ptr = my_malloc(size);
    if (new_ptr) {
        memcpy(new_ptr, ptr, block->size);
        my_free(ptr);
    }
    return new_ptr;
}
