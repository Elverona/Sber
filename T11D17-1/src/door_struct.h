#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H

struct door {
    int id;
    int status;
} door;

void initialize_doors(struct door* doors);
void sort(struct door* doors);
void door_output(struct door* doors);

#endif