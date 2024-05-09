#include <iostream>
#include <iomanip>

void InputAndValidation(int& x, int& y);
void InitializeField(char field[][10]);
//void SetupField(char field[][10]);
void PrintField(const char field[][10]);
bool ShipAttack(char field[][10], int& hit_count);
bool IsValidShip(const int& x1, const int& y1, const int& x2, const int& y2);

int main() {
    char field_1[10][10];
    InitializeField(field_1);

    char field_2[10][10];
    InitializeField(field_2);

    //SetupField(field_1);
    //SetupField(field_2);

    bool game_over = false;
    int current_player = 1;
    bool is_hit = false;

    int hit_count_1 = 0;
    int hit_count_2 = 0;


    while (!game_over) {
        if(current_player == 1) {
            std::cout << "Player 1, enter coordinates to attack (x, y): ";
            is_hit = ShipAttack(field_2, hit_count_1);
            PrintField(field_2);
        } else {
            std::cout << "Player 2, enter coordinates to attack (x, y): ";
            is_hit = ShipAttack(field_1, hit_count_2);
            PrintField(field_1);
        }

        if (!is_hit) {
            current_player = 3 - current_player;
        }
        
        if (hit_count_1 > 19 || hit_count_2 > 19) {
            game_over = true;
            std::cout << "Player " << current_player << " won" << std::endl;
        }
    }
    return 0;
}

void InitializeField(char field[][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            field[i][j] = ' ';
        }
    }
}

void InputAndValidation(int& x, int& y) {
    std::cin >> x;
    while (std::cin.fail() || x > 10 || x < 1) {
        std::cout << "The X-coordinate must be between 1 and 10. ";
        std::cout << "Try again: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> x;
    }
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    std::cin >> y;
    while (std::cin.fail() || y > 10 || y < 1) {
        std::cout << "The Y-coordinate must be between 1 and 10. ";
        std::cout << "Try again: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cin >> y;
    }
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    --x; --y;
}

void PrintField(const char field[][10]) {
    std::cout << "   ";
    for (int i = 0; i < 10; ++i) {
        std::cout << ' ' << i+1; 
    }
    std::cout << std::endl;
    std::cout << "   ";
    for (int i = 1; i <= 10; ++i) {
        std::cout << " -"; 
    }

    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << std::setw(2) << i+1 << "|";
        for (int j = 0; j < 10; ++j) {
            std::cout << ' ' << field[i][j];
        }
        std::cout << '|' << std::endl;
    }
    std::cout << "   ";
    for (int i = 0; i < 10; ++i) {
        std::cout << " -"; 
    }
    std::cout << std::endl;
}

bool ShipAttack(char field[][10], int& hit_count) {
    int x, y;
    InputAndValidation(x, y);
    
    bool hit = true;
    if (field[x][y] == '#') {
        field[x][y] = 'X';
        ++hit_count;
        std:: cout << "Hit!" << std::endl;
    } else if (field[x][y] == ' ') {
        field[x][y] = '.';
        std::cout << "Miss" << std::endl;
        hit = false;
    } else {
        std::cout << "Miss" << std::endl;
        hit = false;
    }
    return hit;
}





