#ifndef ZEBRA_H_INCLUDED
#define ZEBRA_H_INCLUDED
#include "Herbivore.h"

namespace animal_world{

class Zebra:public Herbivore{
    private:

        static const int max_food_points = 4;

    public:

        Zebra(Sex sex);

        Zebra(Sex sex, int id_number, bool animal_cannot_propagate);

        virtual std::string get_object_info() override;

        virtual std::string get_class_name() override;

        virtual int get_max_food_points() override;

};

}


#endif