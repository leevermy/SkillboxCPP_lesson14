#include <iostream>

void FillPackage(bool package[][12]);
void PrintPackage(bool package[][12]);
void InputAndValidation(int& y, int& x);
void BurstAndCount(bool package[][12], const int& y1, const int& x1, const int& y2, const int& x2, int& bursted_cnt);

int main() {
    std::cout << "Task about bursting package\n" << std::endl;
    bool package[12][12];
    FillPackage(package);

    int bursted_cnt = 0;

    while (bursted_cnt < 12 * 12) {
        PrintPackage(package);

        std::cout << "Input first coordinates (row and column): ";
        int y1, x1;
        InputAndValidation(y1, x1);

        std::cout << "Input second coordinates (row and column): ";
        int y2, x2;
        InputAndValidation(y2, x2);

        BurstAndCount(package, y1, x1, y2, x2, bursted_cnt);
    }
    std::cout << "Package is totally bursted" << std::endl;

    return 0;
}

void FillPackage(bool package[][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            package[i][j] = true;
        }
    }
}

void PrintPackage(bool package[][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if(package[i][j]) {
                std::cout << 'O' << " ";
            } else {
                std::cout << 'X' << " ";
            }
        }
        std::cout << std::endl;
    }
}

void InputAndValidation(int& y, int& x) {
    std::cin >> y;
    while (std::cin.fail() || y < 1 || y > 12) {
        std::cout << "Invalid number. Enter number between 1 and 12: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> y;
    }
    std::cin >> x;
    while (std::cin.fail() || x < 1 || x > 12) {
        std::cout << "Invalid number. Enter number between 1 and 12: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> x;
    }
    --y; --x;
}

void BurstAndCount(bool package[][12], const int& y1, const int& x1, const int& y2, const int& x2, int& bursted_cnt) {
    for (int i = y1; i <= y2; ++i) {
        for (int j = x1; j <= x2; ++j) {
            if (package[i][j]) {
                package[i][j] = false;
                std::cout << "Pop!" << std::endl;
                ++bursted_cnt;
            }
        }
    }
}