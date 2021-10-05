#ifndef ANIMAL_H
#define ANIMAL_H

enum Sex{
    male,
    female
};

class Animal{
private:
    int cell_speed;

    Sex animal_sex;

    int food_points;

    int life_points;

public:    
    int get_cell_speed();

    Sex get_animal_sex();

    int get_food_score();

    virtual void eat_dweller() = 0;

    virtual bool next_step() = 0;

};

#endif