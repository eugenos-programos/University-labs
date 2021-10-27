#ifndef ARREA_H
#define ARREA_H
#include "cell.h"
#include "animal.h"
#include <fstream>
#include <vector>

namespace animal_world
{
    class Area
    {
    private:
        int length;

        int width;

        int last_inhabitant_id;

        std::vector<std::vector<Cell *>> area;
        /**
         * @brief  animal_moving_method
         * @details  select what animal should to do (propagating / finding eat)
         * @param accepts  no parametrs
         * @return no
         */
        void animal_moving();
        /**
         * @brief  find_eat_for_herbivore method
         * @details find plants into all herbivore neighbor cells
         * @param accepts cell with herbivore and herbovire
         * @return no
         */
        void find_eat_for_herivore(Cell *cell_with_herbivore, Animal *animal);
        /**
         * @brief  find eat for predator method
         * @details  find herbibores into all predator neighbor cells
         * @param accepts   cell with predator and predator
         * @return no
         */
        void find_eat_for_predator(Cell *cell_with_predator, Animal *animal);
        /**
         * @brief  find eat method
         * @details  call correspond for type of animal method
         * @param accepts  cell with animal and animal
         * @return  no
         */
        void find_eat(Cell *cell_with_animal, Animal *animal);
        /**
         * @brief  find partner method
         * @details  find animal with another sex value and same type of input animal into all neighbor cells
         * @param accepts  cell with animal and animal
         * @return
         */
        bool find_partner(Cell *cell_with_animal, Animal *animal);
        /**
         * @brief    get_neigbor_cells method
         * @param accepts  cell and cell level
         * @return  all neighbor cells in select cell level
         */
        std::vector<Cell *> get_neighbor_cells(Cell *cell, int level);
        /**
         * @brief  move animal between cells method
         * @param accepts  first cell, cecond cell and animal
         * @return  true / false (is animal can go to this cell or not)
         */
        bool move_animal_between_cells(Cell *first_cell, Cell *second_cell, Animal *animal);
        /**
         * @brief   propagate_the_plant method
         * @details  propagate the plant on random neighbor cell
         * @param accepts  cell with plant
         * @return no
         */
        void propagate_the_plant(Cell *cell);
        /**
         * @brief    propagate the animals method
         * @param accepts  cell with this animals, and animals
         * @return no
         */
        void propagate_the_animals(Cell *cell_with_animals, Animal *first_animal, Animal *second_animal);
        /**
         * @brief    check_propagatind_in_all_cells method
         * @details  call for all plant propagate_the_plant method
         * @param accepts  no
         * @return  no
         */
        void check_propagating_in_all_cells();
        /**
         * @brief  check life and food points method
         * @param accepts no
         * @return no
         */
        void check_life_and_food_points_in_all_cells();
        /**
         * @brief    get_random_neighbor_cell method
         * @param accepts neighbor cells
         * @return   random neighbor cell
         */
        Cell *get_random_neighbor_cell(std::vector<Cell *> neighbor_cell);
        /**
         * @brief    all_animal_can_propagate method
         * @details   change the charachetristic that all animals can move in next step
         * @param accepts  no
         * @return no
         */
        void all_animal_can_propagate();
        /**
         * @brief  eat_plant method
         * @details  animal eat plant
         * @param accepts  animal, cell with animal, cell with plant
         * @return no
         */
        void eat_plant(Animal *animal, Cell *cell_with_animal, Cell *cell_with_plant);
        /**
         * @brief  eat_herbivore method
         * @param accepts predator, cell with predator, cell with herbivore, herbivore
         * @return no
         */
        void eat_herbivore(Animal *animal, Cell *cell_with_animal, Cell *cell_with_herbivore, Animal *herbivore);

        std::string inhabitant_log;

    public:
        /**
         * @brief  get_last_inhabitant_id method
         * @param accepts no
         * @return last empty id
         */
        int get_last_inhabitant_id();
        /**
         * @brief  increase_last_inhabitant_id
         * @param accepts no param
         * @return no
         */
        void increase_last_inhabitant_id();
        /**
         * @brief  area constructor
         * @param accepts  area vector, area length and width
         * @return no
         */
        Area(std::vector<std::vector<Cell *>> area, int length, int width);
        /**
         * @brief  print_area_into_matrix_form method
         * @param accepts no
         * @return no
         */
        void print_area_into_matrix_form();
        /**
         * @brief  display area method
         * @param accepts no
         * @return no
         */
        void display_area();
        /**
         * @brief next_step method
         * @details call all neccesary methods, which create inhabitant behaviour
         * @param accepts  no
         * @return no
         */
        void next_step();
        /**
         * @brief  get_length method
         * @return  length
         */
        int get_length();
        /**
         * @brief  get_width method
         * @return  width
         */
        int get_width();

        /**
         * @brief  generate_animal_sex method
         * @param accepts no
         * @return  sex value(fem/male)
         */
        static Sex generate_animal_sex();
        /**
         * @brief fill_cels_from_file method
         * @param accepts file directory
         * @return Area object
         */
        static Area *fill_cells_from_file(std::string directory);
    };

}

#endif