#ifndef CELL_H
#define CELL_H
#include "animal.h"
#include "plant.h"
#include <vector>
#include <iostream>

class Cell
{
private:
    int column_index;

    int raw_index;

    bool is_plant_on_cell;

    Plant* plant;

    std::vector<Animal*> animals_in_cell;
    
public:
    Cell(int column_index, int raw_index, bool is_plant_on_cell, std::vector<Animal*> animals);

    int get_number_of_animals();

    bool get_is_plant_on_cell();

    bool add_animal_on_cell(Animal* animal);
        
    void set_the_status_of_the_plant_on_the_cell(bool status);

    bool find_animal_with_another_sex(Animal* animal);    

    void next_step();
};

#endif 