#ifndef LION_H_INCLUDED
#define LION_H_INCLUDED

#include "predator.h"

namespace animal_world
{

    class Lion : public Predator
    {
    private:
        static const int max_food_points = 5;

    public:
        Lion(Sex sex);

        Lion(Sex sex, int id_number, bool animal_cannot_propagate);

        virtual std::string get_object_info() override;

        virtual std::string get_class_name() override;

        virtual int get_max_food_points() override;
    };

}

#endif