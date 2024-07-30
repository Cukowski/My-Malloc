#include "my_malloc.h"

int main() {
    char* ptr1 = (char*)my_malloc(100);
    strcpy(ptr1, "Hello World!");
    printf("ptr1: %s\n", ptr1);

    char* ptr2 = (char*)my_malloc(200);
    if (!ptr2) printf("Failed to allocate memory for ptr2\n");

    char* ptr3 = (char*)my_malloc(300);
    if (!ptr3) printf("Failed to allocate memory for ptr3\n");

    my_free(ptr1);
    my_free(ptr2);
    my_free(ptr3);

    char* ptr4 = (char*)my_calloc(1, 50);
    strcpy(ptr4, "Calloc test");
    printf("ptr4: %s\n", ptr4);

    char* ptr5 = (char*)my_malloc(50);
    strcpy(ptr5, "Test");
    printf("ptr5 before realloc: %s\n", ptr5);
    
    ptr5 = (char*)my_realloc(ptr5, 100);
    strcat(ptr5, " realloc");
    printf("ptr5 after realloc: %s\n", ptr5);

    my_free(ptr4);
    my_free(ptr5);

    return 0;
}
