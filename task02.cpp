#include <iostream>

void PrintField(char field[][3]);
void FillField(char field[][3]);
void InputFromPlayer(char field[][3], const bool is_first_player, int& y, int& x);
void Input(int & coordinate);
bool CheckWinner(char field[][3], const int& y, const int& x);

int main() {
  std::cout << "Task about \"Tic Tac Toe\" game\n" << std::endl;
  char field[3][3];
  FillField(field);

  bool is_game_over = true;
  bool is_first_player = true;
  bool has_winner = false;
  int move_count = 0;
  PrintField(field);

  while (is_game_over) {
    int y, x;

    if (is_first_player) {
        InputFromPlayer(field, is_first_player, y, x);\
    } else {
        InputFromPlayer(field, is_first_player, y, x);
    }

    PrintField(field);

    has_winner = CheckWinner(field, y, x);
    if (has_winner) {
        std::cout << (is_first_player ? "Player 1 " : "Player 2 ");
        std::cout << "won the game" << std::endl;
        is_game_over = false;
    }

    ++move_count;
    if (move_count > 8 && !has_winner) {
        is_game_over = false;
        std::cout << "The game is over. It's a draw" <<std::endl;
    }

    is_first_player = !is_first_player;
  }

  return 0;
}

void PrintField(char field[][3]) {
  bool ver_divider = true;
  for (int i = 0; i < 3; ++i) {
    if (!ver_divider) {
      std::cout << "--+---+--" << std::endl;
    }
    bool hor_divider = true;
    for (int j = 0; j < 3; ++j) {
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

void FillField(char field[][3]) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      field[i][j] = ' ';
    }
  }
}

void InputFromPlayer(char field[][3], const bool is_first_player, int& y, int& x) {
    std::cout << (is_first_player ? "Player 1 (X), " : "Player 2 (O), ")
                  << "enter the coordinates between 1 and 3.\n";
    
    while (true) {
        std::cout << "Enter row and column: ";
        Input(y);
        Input(x);
        --y; --x;
        
        if (field[y][x] == ' ') {
            field[y][x] = (is_first_player ? 'X' : 'O');
            break;
        } else {
            std::cout << "There is already \"" << field[y][x] << "\" at these coordinates.";
            std::cout << "Try again." << std::endl;
        }
    }
    
    
}

void Input(int & coordinate) {
    std::cin >> coordinate;
    while (std::cin.fail() || coordinate > 3 || coordinate < 1) {
    std::cout << "The coordinates must be beetween 1 and 3."
              << std::endl;
    std::cout << "Try again: ";
    std::cin.clear();
    std::cin.ignore(10, '\n');
    std::cin >> coordinate;
  }
}

bool CheckWinner(char field[][3], const int& y, const int& x) {
    char symbol = field[y][x];
    
    bool in_row = true;
    bool in_column = true;
    bool in_diagonal = true;

    for(int i = 0; i < 3; ++i) {
        if (field[i][x] != symbol) {
            in_column = false;
        }
        if (field[y][i] != symbol) {
            in_row = false;
        }
        if (field[i][i] != symbol && field[i][3-1-i] != symbol) {
            in_diagonal = false;
        }
    }

    return in_column || in_row || in_diagonal;
}