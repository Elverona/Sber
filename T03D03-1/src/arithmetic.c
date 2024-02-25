#include <stdio.h>

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main() {
    int num1, num2;
    // int a, b;
    if ((scanf("%d %d", &num1, &num2) == 2) && (getchar() == '\n')) {
        if (num2 != 0)
            printf("%d %d %d %d\n", sum(num1, num2), sub(num1, num2), mul(num1, num2), div(num1, num2));
        else
            printf("%d %d %d n/a\n", sum(num1, num2), sub(num1, num2), mul(num1, num2));
    } else
        printf("n/a\n");
}
int sum(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int div(int a, int b) { return a / b; }