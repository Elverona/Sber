#ifndef STATE_SORT_H
#define STATE_SORT_H

#include <stdio.h>

struct el_struct {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int status;
    int code;
};

struct el_struct read_record_from_file(FILE *file, int index);
void write_record_in_file(FILE *file, const struct el_struct *last_el_struct, int index);
void swap_records_in_file(FILE *file, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *file);
int get_records_count_in_file(FILE *file);
void output_file(FILE *file);
void sort(FILE *file);

#endif