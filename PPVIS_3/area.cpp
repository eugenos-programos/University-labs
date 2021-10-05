#include "area.h"

Area::Area(int length, int width, std::vector<std::vector<Cell>> area){
    this->length = length;
    this->width = width;
    this->area = area;
}

void Area::find_partner(Animal* animal){
    
}

void Area::animal_moving(Animal* animal){
    if(animal->get_food_score() < 3) this->find_eat(animal);
    else this->find_partner(animal);
}