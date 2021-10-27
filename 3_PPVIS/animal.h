#include <string>
#ifndef ANIMAL_H
#define ANIMAL_H

namespace animal_world
{

    enum Sex
    {
        male,
        female
    };

    class Animal
    {
    protected:
        int animal_id;

        int cell_speed;

        Sex animal_sex;

        int food_points;

        bool animal_cannot_move;

        int life_points;

        int max_food_points;

    public:
        Animal() = default;
        /**
         * @brief  get_animal_id method
         * @param accepts no param
         * @return animal id
         */
        int get_animal_id();
        /**
         * @brief get animal cell speed method
         * @param accepts no param
         * @return cell speed
         */
        int get_cell_speed();
        /**
         * @brief set_cannot_animal_propagate method
         * @param accepts bool value
         * @return  no
         */
        void set_cannot_animal_propagate(bool propagating);
        /**
         * @brief    get_cannot_animal_propagate method
         * @param accepts  no
         * @return  cannot_animal_propagate value
         */
        bool get_cannot_animal_propagate();
        /**
         * @brief  get_class_name method
         * @param accepts  no
         * @return  animal class(Herbivore/Preadtor)
         */
        virtual std::string get_class_name() = 0;
        /**
         * @brief    get_animal_sex method
         * @param accepts no
         * @return sex value
         */
        Sex get_animal_sex();
        /**
         * @brief  get_food_points method
         * @param accepts  no param
         * @return  food points
         */
        int get_food_points();
        /**
         * @brief  get_life_points method
         * @param accepts  no param
         * @return  life points
         */
        int get_life_points();
        /**
         * @brief  get_max_food_points method
         * @param accepts  no param
         * @return  max food points
         */
        virtual int get_max_food_points() = 0;
        /**
         * @brief  get_object_info method
         * @param accepts no
         * @return  object information in specialize form
         */
        virtual std::string get_object_info() = 0;
        /**
         * @brief  get_animal_class_name method
         * @param accepts no
         * @return animal class name
         */
        virtual std::string get_animal_class_name() = 0;
        /**
         * @brief set_food_points method
         * @param accepts food points
         * @return no
         */
        void set_food_points(int food_points);
        /**
         * @brief set_animal_id method
         * @param accepts animal_id
         * @return no
         */
        void set_animal_id(int animal_id);
        /**
         * @brief next_step method
         * @details  check life and food points
         * @param accepts no
         * @return true/false(it depend of food and life point characteristics)
         */
        bool next_step();
        /**
         * @brief check_sex_accordance method
         * @param accepts  animals
         * @return true/false
         */
        friend bool check_sex_accordance(Animal *first_animal, Animal *second_animal);
    };

}

#endif