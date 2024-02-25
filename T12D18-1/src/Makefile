CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_PATH = ../build

all: build

build: print_module

print_module: main_module_entry_point.o print_module.o
	$(CC) main_module_entry_point.o print_module.o -o $(BUILD_PATH)/Quest_1

main_module_entry_point.o: main_module_entry_point.c
	$(CC) $(CFLAGS) -c main_module_entry_point.c

print_module.o: print_module.c
	$(CC) $(CFLAGS) -c print_module.c

clean:
	rm -rf *.o $(BUILD_PATH)/*

rebuild: clean all