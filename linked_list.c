#include "linked_list.h"

elem_t* head = NULL;

elem_t* find_free_block(size_t size) {
    elem_t* current = head;
    while (current) {
        if (!current->is_used && current->size >= size) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void append_to_list(elem_t* block) {
    if (!head) {
        head = block;
    } else {
        elem_t* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = block;
    }
}

void coalesce_free_blocks() {
    elem_t* block = head;
    while (block) {
        if (!block->is_used) {
            elem_t* next_block = block->next;
            while (next_block && !next_block->is_used) {
                block->size += next_block->size + sizeof(elem_t);
                block->next = next_block->next;
                next_block = next_block->next;
            }
        }
        block = block->next;
    }
}
