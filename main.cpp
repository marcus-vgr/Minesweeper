#include "minesweeper.h"
#include <iostream>
#include <vector>


int main(){
    
    Minesweeper game;
    bool continue_game = true;
    do{
      game.print_table(false);
      continue_game = game.round();  
    }while(continue_game);

    game.print_table(true);
    
    
}