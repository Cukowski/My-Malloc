#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "my_malloc.h"

extern elem_t* head;

elem_t* find_free_block(size_t size);
void append_to_list(elem_t* block);
void coalesce_free_blocks();

#endif 
