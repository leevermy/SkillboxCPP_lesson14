#include <iostream>

int main() {
    int cutlery[2][6] = {
        {3, 3, 3, 3, 3, 4}, 
        {3, 3, 3, 3, 3, 4} 
    };
    
    int plates[2][6] = {
        {2, 2, 2, 2, 2, 3},
        {2, 2, 2, 2, 2, 3}  
    };
    
    int chairs[2][6] = {
        {1, 1, 1, 1, 1, 1}, 
        {1, 1, 1, 1, 1, 1}  
    };
    
    // дама с ребенком на пятое место первого ряда - добавляем ещё один стул
    chairs[0][4] += 1;
    
    // с третьего места во втором ряду украли ложку
    cutlery[1][2] -= 1;
    
    // один из випов поделился ложкой сетм, у кого украли
    cutlery[0][3] -= 1; 
    cutlery[1][2] += 1; 
    
    // официант забирает у того же випа десертную тарелку
    plates[0][3] -= 1;
    
    // провывод ниего не написано, но я сделал
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            std::cout << "Row " << i+1 << " Position " << j+1 << ":\n";
            std::cout << "  Cutlery: " << cutlery[i][j] << std::endl;
            std::cout << "  Plates: " << plates[i][j] << std::endl;
            std::cout << "  Chairs: " << chairs[i][j] << std::endl;
            std::cout << std::endl;
        }
    }
    
    return 0;
}