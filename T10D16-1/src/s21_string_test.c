#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(void);
void s21_strcmp_test(void);
void s21_strcpy_test(void);

int main(void) {
#ifdef STRLEN
    s21_strlen_test();
#endif
#ifdef STRCMP
    s21_strcmp_test();
#endif
#ifdef STRCPY
    s21_strcpy_test();
#endif
}

void s21_strlen_test(void) {
    char *words[] = {"make", "your", "dream"};
    const int vivod[] = {4, 4, 6};
    int calculation = sizeof(vivod) / sizeof(int);
    for (int i = 0; i < calculation; i++) {
        printf("%s\n", words[i]);
        int net = s21_strlen(words[i]);
        printf("%d\n", net);
        if (net == vivod[i]) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }
        if (i != calculation - 1) {
            printf("\n\n");
        }
    }
}

void s21_strcmp_test(void) {
    char *words[][2] = {{"make", "makE"}, {"your", "yours"}, {"dream", "dream"}};
    const int vivod[] = {1, 1, 0};
    int calculation = sizeof(vivod) / sizeof(int);
    for (int i = 0; i < calculation; i++) {
        printf("%s | %s\n", words[i][0], words[i][1]);
        int net = s21_strcmp(words[i][0], words[i][0]);
        printf("%d\n", net);
        if (net == vivod[i]) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }
        if (i != calculation - 1) {
            printf("\n\n");
        }
    }
}

void s21_strcpy_test(void) {
    char *words[] = {"make", "your", "dream"};
    char *vivod[] = {"maKE", "youR", "dre am"};
    int calculation = sizeof(vivod) / sizeof(char *);
    for (int i = 0; i < calculation; i++) {
        char test[100] = "n/a";
        printf("%s\n", words[i]);
        printf("%s\n", test);
        if (s21_strcpy(test, vivod[i]) == 0) {
            printf("SUCCESS");
        } else {
            printf("FAIL");
        }
        if (i != calculation - 1) {
            printf("\n\n");
        }
    }
}

// void s21_strcat_test(void) {

// }