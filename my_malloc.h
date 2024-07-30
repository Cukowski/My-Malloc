#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#ifdef DEBUG
    #define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
    #define DEBUG_PRINT(...)
#endif

typedef struct s_elem {
    struct s_elem* next;
    size_t size;
    bool is_used;
    void* ptr_for_the_user;
} elem_t;

void* my_malloc(size_t size);
void my_free(void* ptr);
void* my_calloc(size_t nmemb, size_t size);
void* my_realloc(void* ptr, size_t size);

#endif
