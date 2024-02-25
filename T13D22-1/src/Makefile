CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_PATH = ../build


all: build

build: cipher
	
cipher: cipher.o
	$(CC) cipher.o -o $(BUILD_PATH)/cipher

cipher.o: cipher.c
	$(CC) $(CFLAGS) -c cipher.c

clean:
	rm -rf *.o $(BUILD_PATH)/*

rebuild: clean all