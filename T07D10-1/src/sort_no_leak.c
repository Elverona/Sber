#include <stdio.h>
#include <stdlib.h>

int input(int *a, int *n);
void sort(int *a, int n);
void output(int *a, int n);

int main(void) {
    int n;
    int *data;
    if (((scanf("%d", &n) != 1 || n != 0) && getchar() == '\n')) {
        data = (int *)malloc(n * sizeof(int));
        if (input(data, &n) == 0) {
            sort(data, n);
            output(data, n);
        } else {
            printf("n/a");
        }
        free(data);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    int ban;
    char error;
    // if (scanf("%d", n) != 1 || *n <= 0) {
    //     ban = 1;
    // }   else {
    for (int i = 0; i < *n; i++) {
        if (scanf("%d%c", &a[i], &error) == 1 || error == '\n') {
            ban = 0;
        } else {
            ban = 1;
        }
    }
    // }
    return ban;
}

void sort(int *a, int n) {
    int tmp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int o = 0; o < n - i - 1; o++) {
            if (a[o + 1] < a[o]) {
                tmp = a[o];
                a[o] = a[o + 1];
                a[o + 1] = tmp;
            }
        }
    }
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        printf("%d", *p);
        if (p - a + 1 < n) printf(" ");
    }
}