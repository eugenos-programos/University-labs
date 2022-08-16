#include "plant.h"
using namespace animal_world;

Plant::Plant(){
    life_points = MAX_PLANT_LIFE_POINTS;
    it_is_new_plant = false;
}

Plant::Plant(int id_number){
    life_points = MAX_PLANT_LIFE_POINTS + 1;
    it_is_new_plant = true;
    plant_id = id_number;
}


void Plant::set_life_points(int points){
    if(points < 0) {
        life_points = 0;
        return;
    }
    else life_points = points;
}

int Plant::get_life_points(){
    return life_points;
}

bool Plant::next_step(){
    if(this->get_life_points() == 1 || get_life_points() == 0) return false;
    this->set_life_points(this->get_life_points() - 1);
    return true;
}

std::string Plant::get_plant_info(){
    std::string result = "P-" + std::to_string(plant_id) + "(" + std::to_string(this->life_points) + ")" +"        ";
    return result;
}

bool Plant::get_it_is_new_plant(){
    return this->it_is_new_plant;
}

void Plant::set_it_is_new_plant(bool param){
    it_is_new_plant = param;
}

void Plant::set_plant_id(int id){
    plant_id = id;
}

int Plant::get_plant_id(){
    return plant_id;
}