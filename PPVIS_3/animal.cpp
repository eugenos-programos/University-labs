#include "animal.h"

int Animal::get_cell_speed(){
    return this->cell_speed;
}

Sex Animal::get_animal_sex(){
    return animal_sex;
}

int Animal::get_food_score(){
    return this->food_points;
}
