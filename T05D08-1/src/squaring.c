#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main(void) {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        squaring(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char error;

    if (scanf("%d", n) != 1 && *n <= 0 && *n > NMAX) {
        return 1;
    } else {
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d%c", p, &error) != 1 && p - a + 1 == *n && error != '\n') return 1;
        }
    }
    return 0;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a + 1 < n) printf(" ");
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        (*p) *= (*p);
    }
}