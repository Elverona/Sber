#include "s21_string.h"

int s21_strlen(const char *s) {
    int net = 0;
    while (s[net] != '\0') {
        net++;
    }
    return net;
}

int s21_strcmp(char *net1, char *net2) {
    while (*net1 && (*net1 == *net2)) {
        net1++;
        net2++;
    }
    return *(const unsigned char *)net1 - *(const unsigned char *)net2;
}

char *s21_strcpy(char *dest, char *src) {
    while ('\0' != *src) {
        *dest++ = *src++;
        *dest++ = '\0';
    }
    return dest;
}

// int s21_strcat() {

// }