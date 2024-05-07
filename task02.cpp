#include <iostream>

void PrintField(char field[][3], const int& field_size);
void FillField(char field[][3], const int& field_size);

int main() {
  char field[3][3];
  FillField(field, 3);

  bool is_game_over = true;
  bool is_first_player = true;

  while (is_game_over) {
    PrintField(field, 3);

    if (is_first_player) }

  return 0;
}

void PrintField(char field[][3], const int& field_size) {
  bool ver_divider = true;
  for (int i = 0; i < field_size; ++i) {
    if (!ver_divider) {
      std::cout << "-   -   -" << std::endl;
    }
    bool hor_divider = true;
    for (int j = 0; j < field_size; ++j) {
      if (!hor_divider) {
        std::cout << "| ";
      }
      std::cout << field[i][j] << " ";
      hor_divider = false;
    }
    std::cout << std::endl;
    ver_divider = false;
  }
}

void FillField(char field[][3], const int& field_size) {
  for (int i = 0; i < field_size; ++i) {
    for (int j = 0; j < field_size; ++j) {
      field[i][j] = ' ';
    }
  }
}

void Input(char field[][3], const bool is_first_player) {
  std::cout << (is_first_player ? "Player 1 " : "Player 2 ")
            << " enter the coordinates of x and y between 1 and 3: ";
  int x, y;
  std::cin >> x;
  while (std::cin.fail()) {
    std::cout << "Wrong number. The coordinates must be beetween 1 and 3"
              << std::endl;
    std::cout << "Enter the " std::cin.clear();
    std::cin.ignore(10, '\n');
    std::cin >> x;
  }
}