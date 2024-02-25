CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_PATH = ../build


all: build

build: state_sort
	
state_sort: state_sort.o
	$(CC) state_sort.o -o $(BUILD_PATH)/Quest_1

state_sort.o: state_sort.c
	$(CC) $(CFLAGS) -c state_sort.c

clean:
	rm -rf *.o $(BUILD_PATH)/*

rebuild: clean all