#include "data_stat.h"

double max(double *data, int n) {
    int max_chis = *data;
    for (int i = 0; i < n; i++) {
        if (data[i] > max_chis) {
            max_chis = data[i];
        }
    }
    return max_chis;
}

double min(double *data, int n) {
    int min_chis = *data;
    for (int i = 0; i < n; i++) {
        if (data[i] < min_chis) {
            min_chis = data[i];
        }
    }
    return min_chis;
}

double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double variance(double *data, int n) {
    double vizov = mean(data, n);
    double sum;
    for (int i = 0; i < n; i++) {
        sum += (data[i]) * (data[i]) - vizov * vizov;
    }
    return sum / n;
}
