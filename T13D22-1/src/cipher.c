#include "cipher.h"

#include <stdio.h>

int main(void) {
    int vibor;
    char path[256];
    // printf("___Console main menu:___\n");
    // printf("Enter 1 if you need open text file:\n");
    // printf("Or enter -1 if you need exit:\n");
    // printf("Or enter 2 if need write text");
    while (vibor != -1) {
        if ((scanf("%d", &vibor) != 1) || vibor > 2 || vibor == 0 || vibor < -1) {
            while (getchar() != '\n')
                ;
            printf("n/a\n");
        } else if (vibor == 1) {
            if (scanf("%s", path) == 1) file_read(path);
        } else if (vibor == 2) {
            file_write(path);
        }
    }
    // printf("Exit");
    return 0;
}

void file_read(char *path) {
    FILE *file;
    char text[256];

    file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }

    while (fgets(text, sizeof(text), file) != NULL) {
        // printf("\33[0d\33[2J");
        printf("%s\n", text);
    }
    fclose(file);
}

void file_write(char *path) {
    FILE *file;
    char text[256];
    fflush(stdin);
    fgets(text, sizeof(text), stdin);

    file = fopen(path, "a");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }
    fputs(text, file);
    // fprintf(file, "%s\n", text);

    fclose(file);
}
// void file_write(void) {
//     FILE *file;
//     char text[256];

//     if (scanf("%s", path) == 1) {
//         file = fopen(path, "w+t");
//     //     if (file == NULL) {
//     //         printf("n/a\n");
//              return;
//     // }
// }
//     while (scanf("%s", text) != EOF) {
//         fprintf(file, text);
//     }
// // while (scanf("%s", text) != EOF) {
// //     fputs(text, file);
// //     } while (fgets(text, sizeof(text), file) != NULL) {
// //     // printf("\33[0d\33[2J");
// //         printf("%s\n", file);
// //         }
// fclose(file);
// }