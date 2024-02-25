#include "state_sort.h"

#include <stdio.h>
#include <string.h>
#define N 256

int main() {
    char file_path[N];
    char file_name[N];
    scanf("%s", file_path);
    strcpy(file_name, "../");
    strcat(file_name, file_path);
    int menu;
    FILE *file = fopen(file_name, "r+");
    int a = get_records_count_in_file(file);
    if (!file) {
        printf("n/a");
        return 1;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size == 0) {
        printf("n/a\n");
        return 1;
    }
    scanf("%d", &menu);
    struct el_struct last_el_struct;
    switch (menu) {
        case 0:
            output_file(file);
            break;
        case 1:
            output_file(file);
            sort(file);
            output_file(file);
            break;
        case 2:
            scanf("%d %d %d %d %d %d %d %d", &last_el_struct.year, &last_el_struct.month, &last_el_struct.day,
                  &last_el_struct.hour, &last_el_struct.min, &last_el_struct.sec, &last_el_struct.status,
                  &last_el_struct.code);
            fseek(file, 0, SEEK_END);
            write_record_in_file(file, &last_el_struct, a);
            sort(file);
            output_file(file);
            break;
        default:
            printf("n/a\n");
            break;
    }

    fclose(file);
    return 0;
}

struct el_struct read_record_from_file(FILE *file, int index) {
    int offset = index * sizeof(struct el_struct);
    fseek(file, offset, SEEK_SET);
    struct el_struct record;
    fread(&record, sizeof(struct el_struct), 1, file);
    rewind(file);
    return record;
}

void write_record_in_file(FILE *file, const struct el_struct *last_el_struct, int index) {
    int offset = index * sizeof(struct el_struct);
    fwrite(last_el_struct, sizeof(struct el_struct), 1, file);
    fflush(file);
    rewind(file);
}

void swap_records_in_file(FILE *file, int record_index1, int record_index2) {
    struct el_struct record1 = read_record_from_file(file, record_index1);
    struct el_struct record2 = read_record_from_file(file, record_index2);
    write_record_in_file(file, &record1, record_index2);
    write_record_in_file(file, &record2, record_index1);
}

int get_file_size_in_bytes(FILE *file) {
    int size = 0;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
    return size;
}

int get_records_count_in_file(FILE *file) { return get_file_size_in_bytes(file) / sizeof(struct el_struct); }

void output_file(FILE *file) {
    int end = get_records_count_in_file(file);
    for (int i = 0; i < end; i++) {
        struct el_struct tmp = read_record_from_file(file, i);
        printf("%d %d %d %d %d %d %d %d\n", tmp.year, tmp.month, tmp.day, tmp.hour, tmp.min, tmp.sec,
               tmp.status, tmp.code);
    }
}

void sort(FILE *file) {
    int end = get_records_count_in_file(file);
    for (int i = 0; i < end - 1; i++) {
        for (int j = 0; j < end - i - 1; j++) {
            struct el_struct cur = read_record_from_file(file, j);
            struct el_struct next = read_record_from_file(file, j + 1);
            long long cur_temp = cur.year * 3.154e+7 + cur.month * 2.628e+6 + cur.day * 86400 +
                                 cur.hour * 3600 + cur.min * 60 + cur.sec;
            long long next_temp = next.year * 3.154e+7 + next.month * 2.628e+6 + next.day * 86400 +
                                  next.hour * 3600 + next.min * 60 + next.sec;
            if (cur_temp > next_temp) {
                swap_records_in_file(file, j, j + 1);
            }
        }
    }
}