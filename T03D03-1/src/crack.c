#include <stdio.h>

int krug(float x, float y) { return ((x * x) + (y * y)); }

int main() {
    float x, y;
    if (scanf("%f %f", &x, &y) != 2) {
        printf("n/a\n");
        return 0;
    }
    if (krug(x, y) <= 25) {
        printf("GOTCHA\n");
    } else {
        printf("MISS\n");
    }
}
