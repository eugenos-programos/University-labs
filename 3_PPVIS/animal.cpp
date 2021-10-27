#include "animal.h"
using namespace animal_world;

int Animal::get_cell_speed(){
    return cell_speed;
}

int Animal::get_animal_id(){
    return animal_id;
}

void Animal::set_animal_id(int animal_id){
    this->animal_id = animal_id;
}

void Animal::set_cannot_animal_propagate(bool propagating){
    animal_cannot_move = propagating;
}

bool Animal::get_cannot_animal_propagate(){
    return animal_cannot_move;
}

Sex Animal::get_animal_sex(){
    return animal_sex;
}

int Animal::get_food_points(){
    return food_points;
}

int Animal::get_life_points(){
    return life_points;
}

void Animal::set_food_points(int food_points){
    this->food_points = food_points;
}

int Animal::get_max_food_points(){
    return this->get_max_food_points();
}

bool Animal::next_step(){
    if(this->food_points == 1 || this->life_points == 1 || this->food_points == 0 || this->life_points == 0) return false;
    food_points--;
    life_points--;    
    return true;
}

