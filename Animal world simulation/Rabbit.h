#ifndef RABBIT_H
#define RABBIT_H
#include "Herbivore.h"
#include <string>


namespace animal_world{

class Rabbit: public Herbivore{

    private:
        static const int max_food_points = 3;

    public:

        Rabbit(Sex sex);

        Rabbit(Sex sex,int id_number,bool animal_cannot_propagate);

        virtual std::string get_object_info() override;

        virtual std::string get_class_name() override;

        virtual int get_max_food_points() override;
};

}

#endif