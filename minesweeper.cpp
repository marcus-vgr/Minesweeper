#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> 
#include "minesweeper.h"

int random_number_generator(){ 
    return rand() % 10; // return a number between 0 and 9
}


void Minesweeper::create_bombs(std::vector<std::vector<char>> &v){ // Functions to create bombs
    int num_bombs = 0;
    while(num_bombs != 10){
        int x = random_number_generator(), y = random_number_generator();
        if(v[x][y] != '*'){
            v[x][y] = '*';
            num_bombs++;
        } 
    }
} 

bool Minesweeper::isValid(int x, int y){
    if(x >= 0 && x <= 9 && y >= 0 && y <= 9){
        return true;
    }
    return false;
}

int Minesweeper::verify_position(int x, int y, std::vector<std::vector<char>> v){ 
    // Check if position is valid and if there is a bomb.
        if(isValid(x, y)){
            if(v[x][y] == '*'){
                return +1;
            }
        }
        return 0;
}

void Minesweeper::bombs_quantity(std::vector<std::vector<char>> &v){
    /*
    Converting num (between 0 and 9) to char is "(char) (num+48)" according to ascii table
    */
    for(int i = 0; i<=9; i++){
        for(int j = 0; j<=9; j++){
            int num_bombs = 0;
            if(v[i][j] != '*'){
                
                num_bombs += verify_position(i-1,j-1,v);
                num_bombs += verify_position(i-1,j,v);
                num_bombs += verify_position(i-1,j+1,v);
                num_bombs += verify_position(i,j-1,v);
                num_bombs += verify_position(i,j+1,v);
                num_bombs += verify_position(i+1,j-1,v);
                num_bombs += verify_position(i+1,j,v);
                num_bombs += verify_position(i+1,j+1,v);
                
                v[i][j] = (char) (num_bombs+48);
            }          
        }
    }
}



Minesweeper::Minesweeper(){ // Constructor
    srand(time(NULL));
    
    for(int i = 0; i <= 9; i++){
        std::vector<char> row;
        for(int j = 0; j <= 9; j++){
            row.push_back('_');
        }
        table_info.push_back(row); // Initialize table_infos and char_prints
        char_prints.push_back(row);
    }

    create_bombs(char_prints); // Put bombs in char_prints
    bombs_quantity(char_prints); // Put the info about bombs quantity in each coordinate


}

bool Minesweeper::round(){

    int x, y;
    char action;
    bool valid = false;
    do{
        std::cout << "Type Vertical, Horizontal and Action ('o' for open or 'b' for bomb): ";
        std::cin >> x >> y >> action;
        
        if(isValid(x,y)){
            if(action == 'o' || action == 'b'){
                valid = true;
            }
        }

    }while(!valid);

    if(action == 'b'){
        if(table_info[x][y] != 'B'){
            table_info[x][y] = 'B';
        }
        else{
            table_info[x][y] = '_';
        }
        
    }
    else{
        if(char_prints[x][y] == '*'){
            std::cout << "YOU LOOOOSE!!!! \n";
            return false;
        }
        open_cells(x, y, table_info);
        
    }
    return true;
}

int Minesweeper::verify_position_opening(int x, int y){
    if(x >= 0 && x <= 9 && y >= 0 && y <= 9){
            if(char_prints[x][y] == '*'){
                return -1;
            }
            else if(char_prints[x][y] == '0'){
                return 0;
            }
            else{
                return +1;
            }
            
    }
    return -1;

}

void Minesweeper::open_cells(int x, int y, std::vector<std::vector<char>> &v){

    if(v[x][y] == '_' || v[x][y] == 'B'){ // Check if cell inst already open
    
        v[x][y] = char_prints[x][y];

        if(v[x][y] == '0'){
            
            
            if(isValid(x-1,y-1)){
                if(char_prints[x-1][y-1] != '*'){
                    open_cells(x-1,y-1, v);
                }
            }

            if(isValid(x-1,y)){
                if(char_prints[x-1][y] != '*'){
                    open_cells(x-1,y, v);
                }
            }

            if(isValid(x-1,y+1)){
                if(char_prints[x-1][y+1] != '*'){
                    open_cells(x-1,y+1, v);
                }
            }

            
            if(isValid(x,y-1)){
                if(char_prints[x][y-1] != '*'){
                    open_cells(x,y-1, v);
                }
            }

            
            if(isValid(x,y+1)){
                if(char_prints[x][y+1] != '*'){
                    open_cells(x,y+1, v);
                }
            }
            
            
            if(isValid(x+1,y-1)){
                if(char_prints[x+1][y-1] != '*'){
                    open_cells(x+1,y-1, v);
                }
            }

            if(isValid(x+1,y)){
                if(char_prints[x+1][y] != '*'){
                    open_cells(x+1,y, v);
                }
            }

            if(isValid(x+1,y+1)){
                if(char_prints[x+1][y+1] != '*'){
                    open_cells(x+1,y+1, v);
                }
            }
            

        }
    }    
}


void Minesweeper::print_table(bool complete = false){ // Function to print the table given the information from table_info

    std::string spaces = "    ";
    std::cout << spaces;
    for(int i = 0; i <= 9; i++){
        std::cout << i << spaces;
    }
    std::cout << '\n';

    for(int i = 0; i<= 9; i++){
        std::cout << i << " ";
        for(int j = 0; j<= 9; j++){
            if(complete){
                std::cout << "|_" << char_prints[i][j] << "_|";
            }
            else{
                std::cout << "|_" << table_info[i][j] << "_|";
            }
            
        }
        std::cout << '\n';

    }
}