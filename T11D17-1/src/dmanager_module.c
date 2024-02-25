#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(struct door* doors);
void door_output(struct door* doors);

int main(void) {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    door_output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        for (int o = i + 1; o < DOORS_COUNT; o++) {
            if (doors[i].id > doors[o].id) {
                struct door tmp = doors[i];
                doors[i] = doors[o];
                doors[o] = tmp;
            }
        }
    }
}


void door_output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i != DOORS_COUNT - 1) {
            printf("\n");
        }
    }
}