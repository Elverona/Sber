CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_PATH = ../build


all: build

build: strlen_tests strcmp_tests strcpy_tests

strlen_tests: s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) -c -DSTRLEN s21_string_test.c -o s21_string_test.o
	$(CC) s21_string_test.o s21_string.o -o $(BUILD_PATH)/Quest_1

strcmp_tests: s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) -c -DSTRCMP s21_string_test.c -o s21_string_test.o
	$(CC) s21_string_test.o s21_string.o -o $(BUILD_PATH)/Quest_2

strcpy_tests: s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) -c -DSTRCPY s21_string_test.c -o s21_string_test.o
	$(CC) s21_string_test.o s21_string.o -o $(BUILD_PATH)/Quest_3

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c

# s21_string_test.o: s21_string_test.c
# 	$(CC) $(CFLAGS) -c -DSTRLEN s21_string_test.c

clean:
	rm -rf *.o $(BUILD_PATH)/*

rebuild: clean all