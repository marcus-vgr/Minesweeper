#include <vector>

class Minesweeper{

    //std::vector<std::vector<char>> table_info;

    public:
        void print_table();
        char table_info[9+1][9+1];
        char char_prints[9+1][9+1];
        Minesweeper();
        
        
};