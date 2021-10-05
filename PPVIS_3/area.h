#ifndef ARREA_H
#define ARREA_H
#include "cell.h"
#include <fstream>
#include <vector>

class Area
{
private:
    int length;

    int width;

    std::vector<std::vector<Cell>> area;

    void display_area();

    void animal_moving(Animal* animal);

    void find_eat(Animal* animal);

    void find_partner(Cell* cell_with_animal);

    void find

public:
    Area(int length, int width, std::vector<std::vector<Cell>> area);

    void fill_cells_from_file(std::string file_directory);

    void print_area_into_matrix_form();

    void next_step();

    
};

#endif 