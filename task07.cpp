#include <iostream>

void FillLandscape(int landscape[][5][10]);
int InputFromUser();

int main() {
    std::cout << "Task about slicing landscape\n" << std::endl;
    int landscape[5][5][10]= {0};
    FillLandscape(landscape);
    

    while (true) {
        std::cout << "\nInput slice: ";
        int number = InputFromUser();
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                std:: cout << landscape[i][j][number-1] << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

void FillLandscape(int landscape[][5][10]) {
    std::cout << "Filling landscape..." << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << "What height block will you place in the cell [" << i+1 << "][" << j+1 << "]? ";
            int number = InputFromUser();
            for (int k = 0; k < number; ++k) {
                landscape[i][j][k] = 1;
            }
        }
    }
}

int InputFromUser() {
    int number;
    std::cin >> number;
    while (std::cin.fail() || number > 10 || number < 1) {
        std::cout << "The height must be between 1 and 10 in height. ";
        std::cout << "Try again: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> number;
    }
    return number;
}