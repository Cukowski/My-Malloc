CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
DEBUG_FLAGS = -DDEBUG
LIB_NAME = libmymalloc.a
OBJ = my_malloc.o linked_list.o
TEST = test_program

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	@echo "Creating static library..."
	ar rcs $(LIB_NAME) $(OBJ)

$(OBJ): my_malloc.c my_malloc.h linked_list.c linked_list.h
	@echo "Compiling source files..."
	$(CC) $(CFLAGS) -c my_malloc.c -o my_malloc.o
	$(CC) $(CFLAGS) -c linked_list.c -o linked_list.o

$(TEST): main.o $(LIB_NAME)
	@echo "Compiling test program..."
	$(CC) $(CFLAGS) main.o -L. -lmymalloc -o $(TEST)

main.o: main.c my_malloc.h
	@echo "Compiling main.c..."
	$(CC) $(CFLAGS) -c main.c -o main.o

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all

re: clean all

clean:
	@echo "Cleaning up..."
	rm -f *.o $(LIB_NAME) $(TEST)

test: $(TEST)
	./$(TEST)

.PHONY: all clean debug re test
