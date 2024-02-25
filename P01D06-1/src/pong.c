#include <stdio.h>

int shirina = 80;
int visota = 25;
int ballx = 20;
int bally = 20;
int locationX = 0;
int locationY = 0;
int racket1 = 12;
int racket2 = 12;
char simbol;
int a, b;
int player;
char direction;

void pole() {
    for (a = 0; a <= visota; a++) {
        for (b = 0; b <= shirina; b++) {
            if (a == 0 || a == 25) {
                printf("%c", '_');
            } else if (a == ballx && b == bally) {
                printf("%c", '*');
            } else if (b == 0 || b == 40 || b == 80) {
                printf("%c", '|');
            } else if (b == 78) {
                if (a == racket2 - 1 || a == racket2 || a == racket2 + 1) {
                    printf("%c", '|');
                } else {
                    printf("%c", ' ');
                }
            } else if (b == 2) {
                if (a == racket1 - 1 || a == racket1 || a == racket1 + 1) {
                    printf("%c", '|');
                } else {
                    printf("%c", ' ');
                }
            } else {
                printf("%c", ' ');
            }
        }
        printf("\n");
    }

    printf("\t\tPlayer 1:");
    printf("\t\t\t\tPlayer 2:");
}

void ball_pos() {
    ballx += locationX;
    bally += locationY;
    if (ballx == 24 || ballx == 1) {
        locationX = -locationX;
    }
    if (bally == 80 || bally == 1) {
        bally = 40, ballx = 13;
    }
    if ((bally == 3) && (ballx == racket1 - 1)) {
        locationY = -locationY, locationX = -1;
    } else if ((bally == 3) && (ballx == racket1)) {
        locationX = 0, locationY = +1;
    } else if ((bally == 3) && (ballx == racket1 + 1)) {
        locationY = -locationY, locationX = 1;
    }
    if ((bally == 77) && (ballx == racket2)) {
        locationX = 0, locationY = -1;
    } else if ((bally == 77) && (ballx == racket2 - 1)) {
        locationY = -locationY, locationX = -1;
    } else if ((bally == 77) && (ballx == racket2 + 1)) {
        locationY = -locationY, locationX = 1;
    }
}

int main() {
    pole();
    ball_pos();
}

void clearScreen(void) { printf("\33[0d\33[2J"); }

/*
void racketkaMoove() {
    if (simbol == 'A' || simbol == 'a') {
        racket1=racket1-1;
    }
    if (simbol == 'Z' || simbol == 'z') {
        racket1=racket1+1;
    }
    if (simbol == 'K' || simbol == 'k') {
        racket1=racket2-1;
    } else if (simbol == 'M' || simbol == 'm') {
        racket2=racket2+1;
    }
    if (racket1 == 0) {
        racket1=racket1+1;
    } else if (racket1 == 25) {
        racket1=racket1-1;
    }
    if (racket2 == 0) {
        racket2=racket2+1;
    } else if (racket2 == 25) {
        racket2=racket2-1;
    }
}
*/