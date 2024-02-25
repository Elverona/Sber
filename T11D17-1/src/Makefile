CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_PATH = ../build


all: build

build: door_struct

door_struct: dmanager_module.o
	$(CC) dmanager_module.o -o $(BUILD_PATH)/Quest_1

# stack_test: stack_test.o stack.o
# 	$(CC) stack_test.o stack.o -o $(BUILD_PATH)/Quest_3

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c

 clean:
	rm -rf *.o $(BUILD_PATH)/*

rebuild: clean all