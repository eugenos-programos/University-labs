#include "zebra.h"
using namespace animal_world;

Zebra::Zebra(Sex sex){
    animal_sex = sex;
    cell_speed = 2;
    life_points = 4;
    food_points = 4;
    animal_cannot_move = false;
}

Zebra::Zebra(Sex sex, int id_number, bool animal_cannot_move){
    animal_sex = sex;
    animal_id = id_number;
    cell_speed = 2;
    life_points = 5;
    food_points = 5;
    this->animal_cannot_move = animal_cannot_move;
}

std::string Zebra::get_object_info(){
    std::string result_string = "Z-" + std::to_string(animal_id) + "(";
    this->get_animal_sex() == female ? result_string.append("fem,") : result_string.append("mal,");
    result_string.append(std::to_string(this->food_points) + "," + std::to_string(this->life_points) + ") ");
    return result_string;
}

std::string Zebra::get_class_name(){
    return "Z-";
}

int Zebra::get_max_food_points(){
    return max_food_points;
}
