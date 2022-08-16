#ifndef CELL_H
#define CELL_H
#include "animal.h"
#include "plant.h"
#include <vector>
#include <iostream>

namespace animal_world
{

    class Cell
    {
    private:
        int column_index;

        int raw_index;

        Plant *plant;

        std::vector<Animal *> animals_in_cell;

    public:
        /**
         * @brief delete plant on cell method
         * @param accepts no
         * @return no
         */
        void delete_plant_in_cell();
        /**
         * @brief cell constructor
         * @param accepts  column index, raw index, plant, animals
         * @return no
         */
        Cell(int column_index, int raw_index, Plant *plant_on_cell, std::vector<Animal *> animals);
        /**
         * @brief get_number_of_the_cell_inhibitans method
         * @param accepts no
         * @return number
         */
        int get_number_of_cell_inhabitans();
        /**
         * @brief  get_plant_on_cell method
         * @param accepts no
         * @return plant on cell
         */
        Plant *get_plant_on_cell();
        /**
         * @brief add_animal_on_cell method
         * @param accepts animal
         * @return no
         */
        bool add_animal_on_cell(Animal *animal);
        /**
         * @brief add_plant_on_cell method
         * @param accepts plant id
         * @return no
         */
        void add_plant_on_cell(int new_id);
        /**
         * @brief find_animal_with_another_sex method
         * @param accepts animal with same type
         * @return same animal with another sex
         */

        Animal *find_animal_with_another_sex(Animal *animal);
        /**
         * @brief  next_step method
         * @details call next_step methods into all animals and plant
         * @param accepts no
         * @return no
         */

        void next_step();
        /**
         * @brief get_column_index methdo
         * @param accepts no
         * @return column index
         */

        int get_column_index();
        /**
         * @brief get_raw_index method
         * @param accepts no
         * @return  raw_index
         */

        int get_raw_index();
        /**
         * @brief get_animals_in_cell mathod
         * @param accepts no
         * @return  animals in cell
         */

        std::vector<Animal *> get_animals_in_cell();
        /**
         * @brief delete animal from cell method
         * @param accepts animal
         * @return no
         */
        void delete_animal_from_cell(Animal *animal);
        /**
         * @brief get_info_about_cell_object method
         * @param accepts no
         * @return inforamtion
         */
        std::vector<std::string> get_info_about_cell_object();
        /**
         * @brief find_herbivore method
         * @param accepts no
         * @return herbivore
         */
        Animal *find_herbivore();
        /**
         * @brief add_plant_on_cell method
         * @param accepts no
         * @return no
         */
        void add_plant_on_cell();
    };

}
#endif