#include <vector>

class Minesweeper{

    
    std::vector<std::vector<char>> char_prints; // All the information of the table
    void create_bombs(std::vector<std::vector<char>> &v);
    void bombs_quantity(std::vector<std::vector<char>> &v);
    int verify_position(int x, int y, std::vector<std::vector<char>> v);
    void open_cells(int x, int y, std::vector<std::vector<char>> &v);
    bool isValid(int x, int y);
    

    public:
        void print_table(bool complete);
        std::vector<std::vector<char>> table_info; // Collects the info that will be printed
        bool round();
        int count_openings;
        Minesweeper();
        void run_game();
        
        
};

int random_number_generator();
