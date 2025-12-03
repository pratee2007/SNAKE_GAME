#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int width = 30, height = 20;
int gameOver, paused;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
int dir;
int speed; // game speed based on difficulty

void setup() {
    gameOver = 0;
    paused = 0;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
    dir = 0; // no movement until key pressed
}

void draw() {
    system("cls");

    for (int i = 0; i < width + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) printf("#");

            if (i == y && j == x)
                printf("O");  // Snake head
            else if (i == fruitY && j == fruitX)
                printf("F");  // Fruit
            else {
                int print = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        print = 1;
                    }
                }
                if (!print) printf(" ");
            }

            if (j == width - 1) printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < width + 2; i++) printf("#");
    printf("\n");

printf("Score : %d\n", score);
    printf("Controls: W/A/S/D = Move | P = Pause | R = Resume | X = Exit\n");
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': dir = 1; break;
            case 's': dir = 2; break;
            case 'a': dir = 3; break;
            case 'd': dir = 4; break;
            case 'x': gameOver = 1; break;
            case 'p': paused = 1; break;
            case 'r': paused = 0; break;
        }
    }
}
void logic() {
    if (paused) return; // skip logic when paused

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case 1: y--; break;
        case 2: y++; break;
        case 3: x--; break;
        case 4: x++; break;
    }
    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        if (nTail < 100) nTail++;
    }
}

int main() {
    srand(time(NULL));

    int choice;
    printf("Choose Difficulty:\n1. Easy\n2. Medium\n3. Hard\nEnter choice: ");
    scanf("%d", &choice);
    if (x < 0 || x >= width || y < 0 || y >= height)
        gameOver = 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        if (nTail < 100) nTail++;
    }
}

int main() {
    srand(time(NULL));

    int choice;
    printf("Choose Difficulty:\n1. Easy\n2. Medium\n3. Hard\nEnter choice: ");
    scanf("%d", &choice);
switch (choice) {
        case 1: speed = 150; break;
        case 2: speed = 100; break;
        case 3: speed = 50; break;
        default: speed = 100;
    }

    do {
        setup();

        while (!gameOver) {
            draw();
            input();
            logic();
            Sleep(speed);
        }

        printf("Game Over! Final Score: %d\n", score);
        printf("Play Again? (y/n): ");
        char again = _getch();
        if (again == 'y' || again == 'Y')
gameOver = 0;
        else
            break;

    } while (1);

    return 0;
}
