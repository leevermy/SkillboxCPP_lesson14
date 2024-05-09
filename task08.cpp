#include <iomanip>
#include <iostream>

void InputAndValidation(int& x, int& y);
void InitializeField(char field[][10]);
void SetupField(char field[][10]);
void PrintField(const char field[][10]);
bool ShipAttack(char field[][10], int& hit_count);
bool IsValidShip(const int& x1, const int& y1, const int& x2, const int& y2, const int& size);
bool isValidPlace(const char field[][10], const int& x, const int& y);


int main() {
  char field_1[10][10];
  InitializeField(field_1);

  char field_2[10][10];
  InitializeField(field_2);

  std::cout << "*** Welcome to the game \"Sea battle\" ***\n" << std:: endl;

  std::cout << "=== Set up field for Player 1 ===" << std:: endl;
  SetupField(field_1);
  std::cout << "\n=== Set up field for Player 2 ===" << std:: endl;
  SetupField(field_2);

  std::cout << "\n=== Fields are set. Game is start! ===\n" << std:: endl;
  bool game_over = false;
  int current_player = 1;
  bool is_hit = false;

  int hit_count_1 = 0;
  int hit_count_2 = 0;

  while (!game_over) {
    if (current_player == 1) {
      std::cout << "\nPlayer 1, enter coordinates to attack (x, y): ";
      is_hit = ShipAttack(field_2, hit_count_1);
      PrintField(field_2);
    } else {
      std::cout << "\nPlayer 2, enter coordinates to attack (x, y): ";
      is_hit = ShipAttack(field_1, hit_count_2);
      PrintField(field_1);
    }

    if (!is_hit) {
      current_player = 3 - current_player;
    }

    if (hit_count_1 > 19 || hit_count_2 > 19) {
      game_over = true;
      std::cout << "\n=== Player " << current_player << " won the game ===\n" << std::endl;
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
    std::cout << "   ! The X-coordinate must be between 1 and 10. ";
    std::cout << "Try again: ";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cin >> x;
  }

  std::cin >> y;
  while (std::cin.fail() || y > 10 || y < 1) {
    std::cout << "   ! The Y-coordinate must be between 1 and 10. ";
    std::cout << "Try again: ";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cin >> y;
  }
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  --x;
  --y;
}

void PrintField(const char field[][10]) {
  std::cout << "   ";
  for (int i = 0; i < 10; ++i) {
    std::cout << ' ' << i + 1;
  }
  std::cout << std::endl;
  std::cout << "   ";
  for (int i = 1; i <= 10; ++i) {
    std::cout << " -";
  }

  std::cout << std::endl;
  for (int i = 0; i < 10; ++i) {
    std::cout << std::setw(2) << i + 1 << "|";
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
    std::cout << "** Hit! **" << std::endl;
  } else if (field[x][y] == ' ') {
    field[x][y] = '.';
    std::cout << ".. Miss .." << std::endl;
    hit = false;
  } else {
    std::cout << ".. Miss .." << std::endl;
    hit = false;
  }
  return hit;
}

void SetupField(char field[][10]) {
  std::cout << "1) Set up 4 #-shape ships"  << std:: endl;
  for (int i = 1; i < 5;) {
    std::cout << "   Enter coordinates (x, y) for " << i << " ship: ";
    int x, y;
    InputAndValidation(x, y);
    if (isValidPlace(field, x, y)) {
      field[x][y] = '#';
      PrintField(field);
      ++i;
    } else {
      std::cout << "   ! Error. It's wrong place to set up a ship"  << std:: endl;
    }
  }

  std::cout << "\n\n2) Set up 3 ##-shape ships"  << std:: endl;
  for (int i = 1; i < 4;) {
    std::cout << "   Enter the coordinates (x, y) of the beginning of the " << i << " ship: ";
    int x1, y1;
    InputAndValidation(x1, y1);

    std::cout << "   Enter the coordinates (x, y) of the ending of the " << i << " ship: ";
    int x2, y2;
    InputAndValidation(x2, y2);

    if (!IsValidShip(x1, y1, x2, y2, 2)) {
        continue;
    }

    bool ok = true;
    for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
        if (!isValidPlace(field, i, j)) {
          std::cout << "   ! Error. It's wrong place to set up a ship"  << std:: endl;
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
          field[i][j] = '#';
        }
      }
      PrintField(field);
      ++i;
    }
  }

  std::cout << "\n\n3) Set up 2 ###-shape ships"  << std:: endl;
  for (int i = 1; i < 3;) {
    std::cout << "   Enter the coordinates (x, y) of the beginning of the " << i << " ship: ";
    int x1, y1;
    InputAndValidation(x1, y1);

    std::cout << "   Enter the coordinates (x, y) of the ending of the " << i << " ship: ";
    int x2, y2;
    InputAndValidation(x2, y2);

    if (!IsValidShip(x1, y1, x2, y2, 3)) {
      continue;
    }

    bool ok = true;
    for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
        if (!isValidPlace(field, i, j)) {
          std::cout << "   ! Error. It's wrong place to set up a ship" << std:: endl;
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
          field[i][j] = '#';
        }
      }
      PrintField(field);
      ++i;
    }
  }

  std::cout << "\n\n4) Set up 1 ####-shape ship" << std:: endl;
  for (int i = 1; i < 2;) {
    std::cout << "   Enter the coordinates (x, y) of the beginning of the ship: ";
    int x1, y1;
    InputAndValidation(x1, y1);

    std::cout << "   Enter the coordinates (x, y) of the ending of the ship: ";
    int x2, y2;
    InputAndValidation(x2, y2);

    if (!IsValidShip(x1, y1, x2, y2, 4)) {
      continue;
    }

    bool ok = true;
    for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
        if (!isValidPlace(field, i, j)) {
          std::cout << "   ! Error. It's wrong place to set up a ship" << std:: endl;
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      for (int i = x1; i <= x2; ++i) {
        for (int j = y1; j <= y2; ++j) {
          field[i][j] = '#';
        }
      }
      PrintField(field);
      ++i;
    }
  }
}

bool isValidPlace(const char field[][10], const int& x, const int& y) {
    if (field[x][y] != ' ') {
        return false;
    }
    for (int i = (x > 0 ? x - 1 : x); i < (x < 9 ? x + 1 : x); ++i) {
       for (int j = (y > 0 ? y - 1 : y); j < (y < 9 ? y + 1 : y); ++j) {
            if (field[i][j] != ' ') {
                return false;
            }
       }
    }
    return true;
}

bool IsValidShip(const int& x1, const int& y1, const int& x2, const int& y2, const int& size) {
    if (x1 != x2 && y1 != y2) {
        std::cout << "   ! Ship must be positioned vertically or horizontally" << std:: endl;
        return false;
    }
    if (x1 == x2 && (y2 < y1 || y2 - y1 != size - 1)) {
        std::cout << "   ! Ship has wrong size" << std:: endl;
        return false;
    }
    if (y1 == y2 && (x2 < x1 || x2 - x1 != size - 1 )) {
        std::cout << "   ! Ship has wrong size" << std:: endl;
        return false;
    }
    return true;
}
