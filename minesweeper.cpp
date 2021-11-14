#include <iostream>
#include "minesweeper.h"


Minesweeper::Minesweeper(){ // Constructor
    
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            table_info[i][j] = '_';
        }
    }

}



void Minesweeper::print_table(){ // Function to print the table given the information from table_info

    std::string spaces = "    ";
    std::cout << spaces;
    for(int i = 0; i <= 9; i++){
        std::cout << i << spaces;
    }
    std::cout << '\n';

    for(int i = 0; i<= 9; i++){
        std::cout << i << " ";
        for(int j = 0; j<= 9; j++){
            std::cout << "|_" << table_info[i][j] << "_|";
        }
        std::cout << '\n';

    }
}