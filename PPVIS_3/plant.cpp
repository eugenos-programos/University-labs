#include "plant.h"

Plant::Plant(){
    life_points = MAX_LIFE_POINTS;
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
    if(this->get_life_points() == 0) return false;
    return true;
}