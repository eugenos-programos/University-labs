#include "Lion.h"
using namespace animal_world;

Lion::Lion(Sex sex){
    animal_sex = sex;
    cell_speed = 3;
    life_points = 4;
    food_points = 5;
    animal_cannot_move = false;
}

Lion::Lion(Sex sex, int id_number, bool animal_cannot_move){
    animal_sex = sex;
    animal_id = id_number;
    cell_speed = 3;
    life_points = 5;
    food_points = 6;
    this->animal_cannot_move = animal_cannot_move;
}

std::string Lion::get_object_info(){
    std::string result_string = "L-" + std::to_string(animal_id) + "(";
    this->get_animal_sex() == female ? result_string.append("fem,") : result_string.append("mal,");
    result_string.append(std::to_string(this->food_points) + "," + std::to_string(this->life_points) + ") ");
    return result_string;
}

std::string Lion::get_class_name(){
    return "L-";
}

int Lion::get_max_food_points(){
    return max_food_points;
}
