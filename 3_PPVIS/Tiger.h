#ifndef TIGER_H_INCLUDED
#define TIGER_H_INCLUDED

#include "predator.h"

namespace animal_world{

class Tiger:public Predator{
    private:

        static const int max_food_points = 4;

    public:

        Tiger(Sex sex);

        Tiger(Sex sex,int id_number,bool animal_cannot_propagate);

        virtual std::string get_object_info() override;

        virtual std::string get_class_name() override;

        virtual int get_max_food_points() override;
};

}

#endif