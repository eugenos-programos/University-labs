#include "cell.h"
using namespace animal_world;

Cell::Cell(int raw_index, int column_index, Plant* plant_on_cell, std::vector<Animal*> animals){
    this->column_index = column_index;
    this->raw_index = raw_index;
    this->plant = plant_on_cell;
    animals_in_cell = animals;
}


bool Cell::add_animal_on_cell(Animal* animal){
    if(animals_in_cell.size() == 3 && this->get_plant_on_cell() || animals_in_cell.size() == 4) return false;
    else {
        animals_in_cell.push_back(animal);
        return true;
    }
}

Animal* Cell::find_animal_with_another_sex(Animal* animal){
    for(Animal* animal_in_cell : animals_in_cell){
        if(animal->get_class_name() == animal_in_cell->get_class_name() && animal->get_animal_sex() != animal_in_cell->get_animal_sex()
                                                                            && get_number_of_cell_inhabitans() <= 2 && !animal_in_cell->get_cannot_animal_propagate()){
            return animal_in_cell;
        }
    }

    return NULL;
}

Animal* Cell::find_herbivore(){
    for(Animal* animal : animals_in_cell){
        if(animal->get_animal_class_name() == "Herbivore")return animal;
    }
    return NULL;
}

int Cell::get_column_index() {
    return column_index;
}

int Cell::get_raw_index(){
    return raw_index;
}

Plant* Cell::get_plant_on_cell(){
    return plant;
}

void Cell::delete_animal_from_cell(Animal* animal){

    for(int animal_index = 0; animal_index < this->animals_in_cell.size(); animal_index++)
    {
        if(animals_in_cell[animal_index] == animal) {
             animals_in_cell.erase(animals_in_cell.begin() + animal_index);
         }
    }
}

std::vector<std::string> Cell::get_info_about_cell_object(){
    std::vector<std::string> result;
    if(this->get_plant_on_cell()){
     result.push_back(this->get_plant_on_cell()->get_plant_info());
    }
    for(Animal* animal : animals_in_cell){
        result.push_back(animal->get_object_info());
    }
    if(result.size() < 4){
        while(result.size() != 4){
            result.push_back("      -       ");
        }
    }
    return result;
}

std::vector<Animal*> Cell::get_animals_in_cell(){
    return animals_in_cell;
}

void Cell::delete_plant_in_cell(){
    delete plant;
    plant = NULL;
}

void Cell::next_step(){
    if(get_plant_on_cell() && !(get_plant_on_cell()->next_step())){
        delete_plant_in_cell();
    }
    for(int animal_index = 0; animal_index < animals_in_cell.size(); animal_index++){
        if(!animals_in_cell[animal_index]->next_step()){
            delete_animal_from_cell(animals_in_cell[animal_index]);
            animal_index = -1;
        }
    }
}

void Cell::add_plant_on_cell(int new_id){
    plant = new Plant(new_id);
}

void Cell::add_plant_on_cell(){
    plant = new Plant();
}

int Cell::get_number_of_cell_inhabitans(){
    int result = 0;
    if(get_plant_on_cell()) result++;
    result += animals_in_cell.size();
    return result;
}