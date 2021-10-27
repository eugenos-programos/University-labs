#ifndef HERBIVORE_H
#define HERBIVORE_H
#include "animal.h"

namespace animal_world
{

    class Herbivore : public Animal
    {

    public:
        virtual int get_max_food_points() = 0;

        virtual std::string get_animal_class_name() override;

        virtual std::string get_class_name() = 0;
    };

}

#endif