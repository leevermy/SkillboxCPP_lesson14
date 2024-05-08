#include <iostream>
#include <vector>

int main() {
    float A_matrix[4][4];

    std::cout << "Enter matrix A(4x4):\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> A_matrix[i][j];
        }
    }
    std::cin.ignore(1000, '\n');


    std::vector<float> B_vector(4);
    std::cout << "\nEnter vector B(4):\n";
    for (int i = 0; i < 4; ++i) {
        std::cin >> B_vector[i];
    }


    std::vector<float> C_vector(4, 0.f);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            C_vector[i] += A_matrix[i][j] * B_vector[j];
        }
        std::cout << std::endl;
    }


    std::cout << "\nAfter multiplying matrix A with vector B we get vector C:\n";
    for (float num : C_vector) {
        std::cout << num << " ";
    }

    return 0;
}