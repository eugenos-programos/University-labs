#ifndef PREDATOR_H_INCLUDED
#define PREDATOR_H_INCLUDED
#include "animal.h"

namespace animal_world{

class Predator:public Animal{
    public:

    virtual int get_max_food_points() = 0;

    virtual std::string get_animal_class_name() override;

    virtual std::string get_class_name() = 0;
};

}

#endif 