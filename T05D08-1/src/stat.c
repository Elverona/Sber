#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_chis, int min_chis, double mean, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *a, int *n) {
    char error;

    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
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

int max(int *a, int n) {
    int max_chis = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p > max_chis) {
            max_chis = *p;
        }
    }
    return max_chis;
}

int min(int *a, int n) {
    int min_chis = *a;
    for (int *p = a; p - a < n; p++) {
        if (*p < min_chis) {
            min_chis = *p;
        }
    }
    return min_chis;
}

double mean(int *a, int n) {
    double sum = 0;
    for (int *p = a; p - a < n; p++) {
        sum += *p;
    }
    return sum / n;
}

double variance(int *a, int n) {
    double vizov = mean(a, n);
    double sum;
    for (int *p = a; p - a < n; p++) {
        // sum += pow(a[*p] - vizov, 2);
        sum += (*p) * (*p) - vizov * vizov;
    }
    return sum / n;
}

void output_result(int max_chis, int min_chis, double mean, double variance_v) {
    printf("\n%d %d %.6f %.6f", max_chis, min_chis, mean, variance_v);
}