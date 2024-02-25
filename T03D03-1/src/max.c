#include <stdio.h>

int max(int num1, int num2) {
    if (num1 >= num2) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    int num1, num2;
    if ((scanf("%d %d", &num1, &num2) == 2) && (getchar() == '\n')) {
        printf("%d\n", max(num1, num2));
    } else
        printf("n/a\n");
}