#ifndef PLANT_H
#define PLANT_H
#include <string>

namespace animal_world{

const int MAX_PLANT_LIFE_POINTS = 4;

class Plant{
private:
    int life_points;

    int plant_id;

    bool it_is_new_plant;

public:
/**
* @brief empty plant constructor
* @param accepts no
* @return no
*/
    Plant();
/**
* @brief first plant constructor
* @param accepts id_number
* @return no
*/
    Plant(int id_number);
/**
* @brief next_step mthod
* @param accepts no
* @return is plant have life points(true/false)
*/
    bool next_step();
/**
* @brief set_it_is_new_plant method
* @param accepts it_is_new_plant value
* @return no
*/
    void set_it_is_new_plant(bool param);
/**
* @brief  st_plant_id method
* @param accepts id 
* @return no
*/
    void set_plant_id(int id);
/**
* @brief get_plant_id method
* @param accepts no
* @return id
*/
    int get_plant_id();
/**
* @brief get_it_is_new_plant method
* @param accepts no
* @return value
*/
    bool get_it_is_new_plant();
/**
* @brief set_life_points method
* @param accepts points
* @return no
*/
    void set_life_points(int points);
/**
* @brief get_life_points method
* @param accepts no
* @return life points
*/
    int get_life_points();
/**
* @brief get_plant_info method
* @param accepts no
* @return plant inforamtion
*/
    std::string get_plant_info();
};

}

#endif  