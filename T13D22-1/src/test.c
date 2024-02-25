#include <stdio.h>

void file_read(void);

int main(void) {
    int vibor;
    // printf("___Console main menu:___\n");
    // printf("Enter 1 if you need open text file:\n");
    // printf("Or enter -1 if you need exit:\n");
    // printf("Or enter 2 if need write text");
    while (vibor != -1) {
        if ((scanf("%d", &vibor) != 1) || vibor > 1 || vibor == 0 || vibor < -1) {
            while (getchar() != '\n')
                ;
            printf("n/a\n");
        } else if (vibor == 1) {
            file_read();
        } else if (vibor == 2) {
        }
    }
    // printf("Exit");
    return 0;
}

void file_read(void) {
    FILE *file;
    char path[256];

    if (scanf("%s", path) == 1) {
        file = fopen(path, "r");
        if (file == NULL) {
            printf("n/a\n");
            return;
        }
    }

    char text[256];
    while (fgets(text, sizeof(text), file) != NULL) {
        // printf("\33[0d\33[2J");
        printf("%s\n", text);
    }
    fclose(file);
}