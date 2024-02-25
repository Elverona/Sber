#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *a);
void output(int *a);

int main(void) {
    int data[NMAX];
    if (input(data) == 0) {
        sort(data);
        output(data);

    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a) {
    int ban;
    char error;
    for (int i = 0; i < NMAX; i++) {
        if (scanf("%d%c", &a[i], &error) == 1 || error == '\n') {
            ban = 0;
        } else {
            ban = 1;
        }
    }
    return ban;
}

void sort(int *a) {
    int tmp = 0;
    for (int i = 0; i < NMAX; i++) {
        for (int o = 0; o < NMAX; o++) {
            if (a[o + 1] < a[o]) {
                tmp = a[o];
                a[o] = a[o + 1];
                a[o + 1] = tmp;
            }
        }
    }
}

void output(int *a) {
    for (int *p = a; p - a < NMAX; p++) {
        printf("%d", *p);
        if (p - a + 1 < NMAX) printf(" ");
    }
}