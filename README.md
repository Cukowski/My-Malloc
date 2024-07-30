# Welcome to My Malloc
***
Welcome to My Malloc Project!

## Task
This project implements a custom memory allocation library in C, providing functionalities similar to malloc, free, calloc, and realloc but with custom memory management strategies. 
It uses mmap for large allocations and a custom heap management scheme for smaller allocations.

## Description
My own implementation of the malloc families functions in order to allocate memory are listed:
- my_malloc: Allocates a block of memory.
- my_free: Frees a previously allocated block of memory.
- my_calloc: Allocates memory for an array and initializes it to zero.
- my_realloc: Changes the size of the memory block.

### File Structure
- `my_malloc.h`: Header file containing function declarations and type definitions.
- `my_malloc.c`: Source file implementing the memory allocation functions and linked list operations.
- `main.c`: Test file demonstrating the usage of the custom memory allocation functions.
- `linked_list.h` : Header file containing linked list functions.
- `linked_list.c` : Source file for linked list functions.
- `Makefile`: Makefile to automate the build process.

## Installation
Use the terminal to run commands given in usage section or compile provided Makefile described as in the usage section alternativ.

## Usage
To compile the library and the test program, follow these steps:
<br/>
Compile the library:
```
gcc -c my_malloc.c -o my_malloc.o
gcc -c linked_list.c -o linked_list.o
ar rcs libmymalloc.a my_malloc.o
```
Compile the test program:
```
gcc main.c -L. -lmymalloc -o test_program
```
Run the test program:
```
./test_program
```

### Alternative usage by Makefile
To build the project, run:
```
make
```
This will create the static library my_malloc.a.
<br/>
To build the project with the test executable test_program, run:
```
make test
./test_program
```
To build the project with debug information, run:
```
make debug
```
To clean up the build files, run:
```
make clean
```
Rebuild Everything:
```
make re
```
Example usage of the custom memory allocation functions in a C program has given in the main.c file.

### The Core Team
Selcuk Aksoy

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
