#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m);
/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);

void main() {
    int **matrix, **result;
    int n, m;

    input(&matrix, &n, &m);

    sort_vertical(matrix, n, m);
    output(matrix, n, m);
    printf("\n");

    sort_horizontal(matrix, n, m);
    output(matrix, n, m);
}

void input(int **matrix, int *n, int *m) {
    scanf("%d %d", n, m);
    *matrix = (int **)malloc(*n * sizeof(int *));
    if (*matrix == NULL) {
        printf("n/a");
    }
    for (int i = 0; i < *n; i++) {
        *((*matrix) + i) = (int *)malloc(*m * sizeof(int *));
        if (*((*matrix) + i) == NULL) {
            printf("n/a");
        }
        for (int o = 0; o < *m; o++) {
            scanf("%d", &((*((*matrix) + i))[o]));
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int o = 0; o < m; o++) {
            printf("%d", matrix[i][o]);
        }
    }
}

void sort_vertical(int **matrix, int n, int m) {
    // for (int i = 0; i < n; i++) {
    //     int *line = *(matrix + i);
    //     for (int j = 0; j < m / 2; j++) {
    //         int temp = line[j];
    //         line[j] = line[m - j - 1];
    //         line[m - j - 1] = temp;
    //     }
    // } ХРЕНОВЫЙ ПИТОН!!!!
}