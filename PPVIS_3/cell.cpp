#include "cell.h"


Cell::Cell(int column_index, int raw_index, bool is_plant_on_cell, std::vector<Animal*> animals){
    this->column_index = column_index;
    this->raw_index = raw_index;
    this->is_plant_on_cell = is_plant_on_cell;
    animals_in_cell = animals;
}


bool Cell::add_animal_on_cell(Animal* animal){
    if(animals_in_cell.size() == 3 && is_plant_on_cell) return false;
    else {
        animals_in_cell.push_back(animal);
        return true;
    }
}



void Cell::find_animal_with_another_sex(Animal* animal){
    for(Animal* animal_in_cell : this->animals_in_cell){

    }
    /*if(animals_on_cell.size() + is_plant_on_cell == 4  || animals_on_cell.size() == 1) return;
    else {
        if(typeid(*animals_on_cell[0]).name() != typeid(*animals_on_cell[1]).name()) return;
        else {
            if(animals_on_cell[0]->get_animal_sex() == animals_on_cell[1]->get_animal_sex()) return;
            animals_on_cell.push_back(new Animal (0,female)); // change type
        }
    }*/
}


