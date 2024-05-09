#include <iostream>
#include <cassert>

int main() {
    std::cout << "Task about comparing matrices\n" << std::endl;
    int A_matrix[4][4];
    int B_matrix[4][4];

    std::cout << "Enter matrix A (4x4):\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> A_matrix[i][j];
        } 
    }

    std::cout << "\nEnter matrix B (4x4):\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> B_matrix[i][j];
            assert(B_matrix[i][j] == A_matrix[i][j]);
        } 
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(i != j) {
                A_matrix[i][j] = 0;
            }
        } 
    }

    std::cout << "Matrices are equal. Transforming matrix A into a diagonal matrix:\n";
    for (int i = 0; i < 4; ++i) {
        bool is_space = false;
        for (int j = 0; j < 4; ++j) {
            if (is_space) {
                std:: cout << " ";
            }
            std::cout << A_matrix[i][j];
            is_space = true;
        }
        std::cout << std::endl;
    }
    
    return 0;
}