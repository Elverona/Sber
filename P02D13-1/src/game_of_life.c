#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25

void create_field(int matrix[WIDTH][HEIGHT]);
void read_field(int matrix[WIDTH][HEIGHT]);
void print_field(int matrix[WIDTH][HEIGHT]);
int count_neighbours(int matrix[WIDTH][HEIGHT], int i, int j);
void update_field(int matrix[WIDTH][HEIGHT]);
void button_settings();

int main() {
    int matrix[WIDTH][HEIGHT];
    create_field(matrix);
    read_field(matrix);
    if (freopen("/dev/tty", "r", stdin) != NULL) {
        int speed = 100000;
        button_settings();

        while (1) {
            int button;
            clear();
            print_field(matrix);
            update_field(matrix);
            button = getch();
            if (button == '-') {
                speed += 50000;
            }
            if (button == '+') {
                speed -= 50000;
            }

            usleep(speed);
        }
    }
    endwin();
}

// Создание поля с мертвыми клетками
void create_field(int matrix[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            matrix[i][j] = 0;
        }
    }
}

// Инициализация ncurses
void button_settings() {
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    noecho();
}

// Чтение поля из файла (используется перенаправление ввода)
void read_field(int matrix[WIDTH][HEIGHT]) {
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            if (scanf("%d", &matrix[i][j]) == 1) {
                getchar();
            }
        }
    }
}

// Вывод текущего состояния поля
void print_field(int matrix[WIDTH][HEIGHT]) {
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            if (matrix[i][j] == 0)
                printw("%c", ' ');
            else if (matrix[i][j] == 1)
                printw("%c", 'o');
        }

        printw("\n");
    }

    refresh();
}

// Подсчет количества живых соседей у клетки
int count_neighbours(int matrix[WIDTH][HEIGHT], int i, int j) {
    int count = 0;

    for (int m = -1; m <= 1; m++) {
        for (int l = -1; l <= 1; l++) {
            if (m || l) {
                if (matrix[(i + m + WIDTH) % WIDTH][(j + l + HEIGHT) % HEIGHT] == 1) {
                    count++;
                }
            }
        }
    }

    return count;
}

// Обновление состояния поля
void update_field(int matrix[WIDTH][HEIGHT]) {
    int new_matrix[WIDTH][HEIGHT];

    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            int neighbours_count = count_neighbours(matrix, i, j);

            if (neighbours_count == 2) {
                new_matrix[i][j] = matrix[i][j];
            } else if (neighbours_count == 3) {
                new_matrix[i][j] = 1;
            } else {
                new_matrix[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            matrix[i][j] = new_matrix[i][j];
        }
    }
}
