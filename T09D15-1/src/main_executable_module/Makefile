CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_PATH = ../../build


all: build

build: data_io.o data_stat.o data_process.o decision.o main_executable_module.o
	$(CC) data_io.o data_stat.o data_process.o decision.o main_executable_module.o -o $(BUILD_PATH)/Quest_3

build_with_static: data_io.o data_process.o decision.o main_executable_module.o data_stat.a
	ranlib libdata_stat.a
	$(CC) data_io.o data_process.o decision.o main_executable_module.o -L. -ldata_stat -o $(BUILD_PATH)/Quest_5

build_with_dynamic: data_io.o decision.o main_executable_module.o data_process.so
	$(CC) data_io.o decision.o main_executable_module.o -DUSE_DYNAMIC -L. -ldata_process -o $(BUILD_PATH)/Quest_6
	install_name_tool -change data_process.so ../main_executable_module/data_process.so $(BUILD_PATH)/Quest_6

data_stat.a: data_stat.o
	ar rc libdata_stat.a data_stat.o

data_process.so: ../data_libs/data_stat.c ../data_module/data_process.c
	$(CC) -fPIC -c ../data_module/data_process.c ../data_libs/data_stat.c
	$(CC) -shared -o libdata_process.so data_process.o data_stat.o

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -c ../data_module/data_process.c

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c

main_executable_module.o: ../main_executable_module/main_executable_module.c
	$(CC) $(CFLAGS) -c ../main_executable_module/main_executable_module.c


clean:
	rm -rf *.o *.a *.so ../../build/*

rebuild: clean all
