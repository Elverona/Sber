/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length, int *sum);
// int find_numbers(int* buffer, int length, int number, int* numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int a, z, data[NMAX];
    if (input(data, &a) == 0) {
        int sum = sum_numbers(data, a, &z);
        output(data, a);
        printf("%d\n", sum);
    } else {
        printf("n/a");
    }
    return 0;
}

int input(int *buffer, int *length) {
    char error;
    int ban = 0;
    if (scanf("%d", length) != 1 || *length <= 0 || *length > NMAX) {
        // ban = 1;
    } else {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d%c", p, &error) != 1 || p - buffer + 1 == *length || error != '\n') ban = 0;
        }
    }
    return ban;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length, int *sum) {
    // int sum = 0;

    for (int i = 1; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            *sum += buffer[i];
        }
    }

    return *sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
// int find_numbers(int* buffer, int length, int number, int* numbers) {

// }

void output(int *buffer, int length) {
    for (int *p = buffer; p - buffer < length; p++) {
        printf("%d", *p);
        if (p - buffer + 1 < length) printf(" ");
    }
}

// int sum_numbers(int *buffer, int length, int *sum) {
//     int flag = 0;
//     for (int i = 0; i < length; ++i) {
//         if (buffer[i] % 2 == 0) {
//             *sum += buffer[i];
//             ++flag;
//         }
//     }
//     return flag;
// }

// int find_numbers(int *buffer, int length, int number, int *numbers) {
//     int i = 0;
//     for (int j = 0; j < length; ++j) {
//         if (buffer[j] != 0 && number % buffer[j] == 0) {
//             numbers[i] = buffer[j];
//             ++i;
//         }
//     }
//     return i;
// }