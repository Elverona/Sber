#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print)(char), char* message) {
    struct tm* timenow;
    time_t now;
    char str[20];

    time(&now);
    timenow = localtime(&now);
    strftime(str, sizeof(str), "%T", timenow);
    printf("%s ", Log_prefix);
    int i = 0;
    while (str[i]) {
        print(str[i]);
        i++;
    }
    print(' ');
    i = 0;
    while (message[i]) {
        print(message[i]);
        i++;
    }
}

//    printf("%s %02d:%02d:%02d ", Log_prefix, t->tm_hour, t->tm_min, t->tm_sec);
//     int i =  0;
//     while (message[i]) {
//         print(message[i]);
//         i++;
//     }
// }