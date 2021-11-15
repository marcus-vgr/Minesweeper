#include <vector>

class Minesweeper{

    
    std::vector<std::vector<char>> char_prints; // All the information of the table
    void create_bombs(std::vector<std::vector<char>> &v);
    void bombs_quantity(std::vector<std::vector<char>> &v);
    int verify_position(int x, int y, std::vector<std::vector<char>> v);
    

    public:
        void print_table(bool complete);
        std::vector<std::vector<char>> table_info; // Collects the info that will be printed
        Minesweeper();
        
        
};

int random_number_generator();
