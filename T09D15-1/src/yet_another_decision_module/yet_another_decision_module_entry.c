#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "decision.h"

int main(void) {
    double *data;
    int n;

    scanf("%d", &n);
    data = (double *)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("n/a");
        exit(EXIT_FAILURE);
    }
    input(data, n);
    if (make_decision(data, n)) {
        printf("YES");
    } else {
        printf("NO");
    }
    free(data);
    return 0;
}
