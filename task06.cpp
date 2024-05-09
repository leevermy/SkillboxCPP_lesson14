#include <iostream>

void FillSnake(int snake[][5]);
void PrintSnake(int snake[][5]);

int main() {
    std::cout << "Task about filling array in a snake style\n" << std::endl;
    int snake[5][5];
    FillSnake(snake);
    PrintSnake(snake);
    return 0;
}

void FillSnake(int snake[][5]) {
    int number = 0;
    int direction = 1;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int index = j * direction + (5 - 1) * (direction < 0);
            snake[i][index] = number;
            ++number;
        }
        direction *= -1;
    }
}

void PrintSnake(int snake[][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << snake[i][j] << " ";
        }
        std::cout << std::endl;
    }
}