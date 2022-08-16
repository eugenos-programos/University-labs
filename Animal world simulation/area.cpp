#include "area.h"
#include "stdlib.h"
#include "stdio.h"
#include "Rabbit.h"
#include "zebra.h"
#include "Tiger.h"
#include "Lion.h"
#include <time.h>
#include <fstream>
using namespace animal_world;


Sex Area::generate_animal_sex()
{
    srand(time(NULL));
    if(rand() % 2) return male;
    return female;
}

Area::Area(std::vector<std::vector<Cell *>> area, int length, int width)
{
    this->area = area;
    this->length = length;
    this->width = width;
    int inhabitant_id = 0;
    for (std::vector<Cell *> cell_raw : area)
    {
        for (Cell *cell : cell_raw)
        {
            for (Animal *animal_in_cell : cell->get_animals_in_cell())
            {
                animal_in_cell->set_animal_id(inhabitant_id);
                inhabitant_id++;
            }
            if (cell->get_plant_on_cell())
            {
                cell->get_plant_on_cell()->set_plant_id(inhabitant_id++);
            }
        }
    }
    last_inhabitant_id = inhabitant_id;
}

int Area::get_length()
{
    return length;
}

int Area::get_width()
{
    return width;
}

int Area::get_last_inhabitant_id()
{
    return last_inhabitant_id;
}

void Area::increase_last_inhabitant_id()
{
    last_inhabitant_id++;
}

bool Area::move_animal_between_cells(Cell *first_cell, Cell *second_cell, Animal *animal)
{
    if (!second_cell->add_animal_on_cell(animal))
        return false;
    inhabitant_log.append(animal->get_class_name() + std::to_string(animal->get_animal_id()) + "->" + "[" + std::to_string(second_cell->get_raw_index()) + "," +
                          std::to_string(second_cell->get_column_index()) + "] |");
    first_cell->delete_animal_from_cell(animal);
    return true;
}

void Area::display_area()
{
    for (int raw_index = 0; raw_index < length; raw_index++)
    {
        for (int str_index = 0; str_index < 4; str_index++)
        {
            std::string str = "";
            for (int column_index = 0; column_index < width; column_index++)
            {
                str.append(area[raw_index][column_index]->get_info_about_cell_object()[str_index] + "       ");
            }
            std::cout << str << '\n';
        }
        std::cout << std::endl
                  << std::endl;
    }
    std::cout << "___________LOG___________\n"
              << inhabitant_log << std::endl;
}

std::vector<Cell *> Area::get_neighbor_cells(Cell *cell, int level)
{
    int raw_index = cell->get_raw_index();
    int column_index = cell->get_column_index();
    std::vector<Cell *> result;
    if (column_index - level >= 0)
    {
        result.push_back(area[raw_index][column_index - level]);
        if (raw_index - level >= 0)
            result.push_back(area[raw_index - level][column_index - level]);
        if (raw_index + level < this->get_length())
            result.push_back(area[raw_index + level][column_index - level]);
    }
    if (raw_index - level >= 0)
    {
        result.push_back(area[raw_index - level][column_index]);
    }
    if (column_index + level < this->get_width())
    {
        result.push_back(area[raw_index][column_index + level]);
        if (raw_index + level < this->get_length())
            result.push_back(area[raw_index + level][column_index + level]);
        if (raw_index - level >= 0)
            result.push_back(area[raw_index - level][column_index + level]);
    }
    if (raw_index + level < this->get_length())
    {
        result.push_back(area[raw_index + level][column_index]);
    }
    return result;
}

Cell *Area::get_random_neighbor_cell(std::vector<Cell *> neighbor_cell)
{
    srand(time(NULL));
    if (neighbor_cell.size() == 1)
        return neighbor_cell[0];
    return neighbor_cell[rand() % neighbor_cell.size()];
}

void Area::propagate_the_animals(Cell *cell_with_animals, Animal *first_animal, Animal *second_animal)
{
    if (first_animal->get_class_name() == "R-")
    {
        increase_last_inhabitant_id();
        Rabbit* new_rabbit = new Rabbit(generate_animal_sex(),get_last_inhabitant_id(),true);
        first_animal->set_cannot_animal_propagate(true);  
        second_animal->set_cannot_animal_propagate(true);
        cell_with_animals->add_animal_on_cell(new_rabbit);
    }
    else if(first_animal->get_class_name() == "Z-"){
        increase_last_inhabitant_id();
        Zebra* new_zebra = new Zebra(generate_animal_sex(), get_last_inhabitant_id(), true);
        first_animal->set_cannot_animal_propagate(true);
        second_animal->set_cannot_animal_propagate(true);
        cell_with_animals->add_animal_on_cell(new_zebra);
    }
    else if(first_animal->get_class_name() == "T-"){
        increase_last_inhabitant_id();
        Tiger* new_tiger = new Tiger(generate_animal_sex(), get_last_inhabitant_id(), true);
        first_animal->set_cannot_animal_propagate(true);
        second_animal->set_cannot_animal_propagate(true);
        cell_with_animals->add_animal_on_cell(new_tiger);
    }
    else if(first_animal->get_class_name() == "L-"){
        increase_last_inhabitant_id();
        Lion* new_lion = new Lion(generate_animal_sex(), get_last_inhabitant_id(), true);
        first_animal->set_cannot_animal_propagate(true);
        second_animal->set_cannot_animal_propagate(true);
        cell_with_animals->add_animal_on_cell(new_lion);
    }
}


bool Area::find_partner(Cell *cell_with_this_animal, Animal *animal)
{
    if(animal->get_cannot_animal_propagate()){
        return false;
    }
    for (int index = 1; index <= animal->get_cell_speed(); ++index)
    {
        for (Cell *neighbor_cell : get_neighbor_cells(cell_with_this_animal, index))
        {
            if (neighbor_cell->find_animal_with_another_sex(animal))
            {
                Animal* partner_animal = neighbor_cell->find_animal_with_another_sex(animal);
                move_animal_between_cells(cell_with_this_animal, neighbor_cell, animal);
                propagate_the_animals(neighbor_cell, animal, partner_animal);
                inhabitant_log.append(animal->get_class_name() + std::to_string(animal->get_animal_id()) + "+" +
                                    partner_animal->get_class_name() + std::to_string(partner_animal->get_animal_id()) + "=" +
                                    animal->get_class_name() + std::to_string(last_inhabitant_id) + "| ");
                return true;
            }
        }
    }
    return false;
}

void Area::eat_plant(Animal *animal, Cell *cell_with_animal, Cell *cell_with_plant)
{
    if (animal->get_max_food_points() - animal->get_food_points() <= cell_with_plant->get_plant_on_cell()->get_life_points())
    {
        // herbivore has eatten a part of the plant
        animal->set_food_points(animal->get_max_food_points());
        cell_with_plant->get_plant_on_cell()->set_life_points(cell_with_plant->get_plant_on_cell()->get_life_points() - animal->get_max_food_points() + animal->get_food_points());
        inhabitant_log.append(animal->get_class_name() + std::to_string(animal->get_animal_id()) + " eat P-" + std::to_string(cell_with_plant->get_plant_on_cell()->get_plant_id()) + " |");
        return;
    }
    if (animal->get_max_food_points() - animal->get_food_points() > cell_with_plant->get_plant_on_cell()->get_life_points())
        // herbivore has eatten all plant
    {
        animal->set_food_points(animal->get_food_points() + cell_with_plant->get_plant_on_cell()->get_life_points());
        inhabitant_log.append(animal->get_class_name() + std::to_string(animal->get_animal_id()) + " eatten P-" + std::to_string(cell_with_plant->get_plant_on_cell()->get_plant_id()) + " |");
        cell_with_plant->delete_plant_in_cell();
        return;
    }
}

void Area::eat_herbivore(Animal* animal, Cell* cell_with_animal, Cell* cell_with_herbivore, Animal* herbivore){
    srand(time(NULL));
    if(animal->get_cell_speed() <= herbivore->get_cell_speed() && rand() % 2 == 1){
        inhabitant_log.append(animal->get_class_name() + std::to_string(animal->get_animal_id()) + " dsnt catch " + herbivore->get_class_name() + 
                                                    std::to_string(herbivore->get_animal_id()) + " |");
        move_animal_between_cells(cell_with_herbivore, get_random_neighbor_cell(get_neighbor_cells(cell_with_herbivore,1)),herbivore);
        herbivore->set_cannot_animal_propagate(true);
        return;
    }
    
    if (animal->get_max_food_points() - animal->get_food_points() > herbivore->get_life_points()){
        animal->set_food_points(animal->get_food_points() + herbivore->get_life_points());
        inhabitant_log.append(animal->get_class_name() + std::to_string(animal->get_animal_id()) + " eat " + herbivore->get_class_name() + 
                                                    std::to_string(herbivore->get_animal_id()) + " |");
        cell_with_herbivore->delete_animal_from_cell(herbivore);
        return;
    }
    if (animal->get_max_food_points() - animal->get_food_points() <= herbivore->get_life_points()){
        animal->set_food_points(animal->get_max_food_points());
        inhabitant_log.append(animal->get_class_name() + std::to_string(animal->get_animal_id()) + " eat " + herbivore->get_class_name() + 
                                                    std::to_string(herbivore->get_animal_id()) + " |");
        cell_with_herbivore->delete_animal_from_cell(herbivore);
    }
}

void Area::find_eat_for_herivore(Cell *cell_with_herbivore, Animal *animal)
{

    if (cell_with_herbivore->get_plant_on_cell())
    {
        eat_plant(animal, cell_with_herbivore, cell_with_herbivore);
        return;
    }
    else
    {
        for (int cell_level = 1; cell_level <= animal->get_cell_speed(); cell_level++)
        {
            // check all neighbor cells
            for (Cell *neighbor_cell : get_neighbor_cells(cell_with_herbivore, cell_level))
            {
                if (neighbor_cell->get_plant_on_cell() && move_animal_between_cells(cell_with_herbivore, neighbor_cell, animal))
                {
                    animal->set_cannot_animal_propagate(true);
                    eat_plant(animal, cell_with_herbivore, neighbor_cell);
                    return;
                }
            }
        }
    }
    for (int cell_level = animal->get_cell_speed(); cell_level > 0; cell_level--)
    {
        for (Cell *neighbor_cell : get_neighbor_cells(cell_with_herbivore, cell_level))
        {
            if (move_animal_between_cells(cell_with_herbivore, neighbor_cell, animal))
            {
                animal->set_cannot_animal_propagate(true);
                return;
            }
        }
    }
}

void Area::find_eat_for_predator(Cell* cell_with_predator, Animal* animal){
    if(cell_with_predator->find_herbivore()){
        eat_herbivore(animal, cell_with_predator , cell_with_predator, cell_with_predator->find_herbivore());
        return;
    }
    for(int cell_level = 1; cell_level <= animal->get_cell_speed(); cell_level++){
        for(Cell* neighbor_cell : get_neighbor_cells(cell_with_predator, cell_level)){
            if(neighbor_cell->find_herbivore() && move_animal_between_cells(cell_with_predator, neighbor_cell, animal)){
                animal->set_cannot_animal_propagate(true);
                eat_herbivore(animal, cell_with_predator, neighbor_cell, neighbor_cell->find_herbivore());
                return;
            }
        }
    }
    for (int cell_level = animal->get_cell_speed(); cell_level > 0; cell_level--)
    {
        for (Cell *neighbor_cell : get_neighbor_cells(cell_with_predator, cell_level))
        {
            if (move_animal_between_cells(cell_with_predator, neighbor_cell, animal))
            {
                animal->set_cannot_animal_propagate(true);
                return;
            }
        }
    }
}

void Area::propagate_the_plant(Cell *cell_with_plant)
{
    if (!cell_with_plant->get_plant_on_cell() || cell_with_plant->get_plant_on_cell()->get_it_is_new_plant())
    {
        return;
    }
    for (int numb_of_neigh_cells = 0; numb_of_neigh_cells < this->get_neighbor_cells(cell_with_plant, 1).size(); numb_of_neigh_cells++)
    {
        Cell *random_neighbor_cell = get_neighbor_cells(cell_with_plant, 1)[numb_of_neigh_cells];
        // if neighbor cell has a plant 
        if (random_neighbor_cell->get_plant_on_cell())
        {
            random_neighbor_cell->get_plant_on_cell()->set_life_points(MAX_PLANT_LIFE_POINTS);
            inhabitant_log.append("P-" + std::to_string(cell_with_plant->get_plant_on_cell()->get_plant_id()) + "+->P-" +
                                  std::to_string(random_neighbor_cell->get_plant_on_cell()->get_plant_id()) + " |");
            return;
        }
        // if on neighbor cell there is no plants
        else if (random_neighbor_cell->get_number_of_cell_inhabitans() < 4)
        {
            increase_last_inhabitant_id();                                         // making new id for new plant
            random_neighbor_cell->add_plant_on_cell(last_inhabitant_id);
            inhabitant_log.append("P-" + std::to_string(cell_with_plant->get_plant_on_cell()->get_plant_id()) + "*->P-" +
                                  std::to_string(last_inhabitant_id) + "|");
            return;
        }
    }
}

void Area::check_life_and_food_points_in_all_cells()
{
    for (std::vector<Cell *> cell_raw : area)
    {
        for (Cell *cell : cell_raw)
            cell->next_step();
    }
}

void Area::check_propagating_in_all_cells()
{
    for (std::vector<Cell *> cell_raw : area)
    {
        for (Cell *cell : cell_raw)
            propagate_the_plant(cell);
    }
    for (std::vector<Cell *> cell_raw : area)
    {
        for (Cell *cell : cell_raw)
            if (cell->get_plant_on_cell())
                cell->get_plant_on_cell()->set_it_is_new_plant(false);
    }
}

void Area::find_eat(Cell* cell_with_animal, Animal* animal){
    if(animal->get_animal_class_name() == "Herbivore"){
        find_eat_for_herivore(cell_with_animal, animal);
    }
    if(animal->get_animal_class_name() == "Predator"){
        find_eat_for_predator(cell_with_animal, animal);   
    }
}

void Area::all_animal_can_propagate(){
    for(std::vector<Cell*> cell_raw : area){
        for(Cell *cell : cell_raw){
            for(Animal* animal_in_cell : cell->get_animals_in_cell()){
                animal_in_cell->set_cannot_animal_propagate(false);
            }
        }
    }
}

//
void Area::animal_moving()
{
    for (std::vector<Cell *> cell_raw : area)
    {
        for (Cell *cell : cell_raw)
        {
            for (Animal *animal_in_cell : cell->get_animals_in_cell())    // FOR ALL ANIMALS INTO AREA
            {
                if(animal_in_cell->get_cannot_animal_propagate()) continue;
                if(animal_in_cell->get_life_points() == 1){
                    if(!find_partner(cell, animal_in_cell)) find_eat(cell, animal_in_cell);
                }
                if (animal_in_cell->get_food_points() <= 2)
                {
                    find_eat(cell, animal_in_cell);
                }
                if(animal_in_cell->get_food_points() >= 3){
                    if(!find_partner(cell, animal_in_cell)){
                         if(animal_in_cell->get_food_points() == animal_in_cell->get_max_food_points()){
                            move_animal_between_cells(cell, get_random_neighbor_cell(get_neighbor_cells(cell,animal_in_cell->get_cell_speed())),animal_in_cell);
                            animal_in_cell->set_cannot_animal_propagate(true);
                        }
                        else find_eat(cell, animal_in_cell);
                    }
                }
            }
        }
    }
    all_animal_can_propagate();
}

void Area::next_step()
{
    inhabitant_log.clear(); // Clear log
    animal_moving();
    check_propagating_in_all_cells();
    check_life_and_food_points_in_all_cells(); // delete inhabitans with zero or one life point
    display_area();
}



Area* Area::fill_cells_from_file(std::string directory){
    int length,width;
    std::ifstream read(directory);
    read >> length >> width;
    std::vector<std::vector <Cell*>> area(length);
    for(std::vector<Cell*> cell_raw : area){
        cell_raw.resize(width);
    }
    for(int raw_index = 0; raw_index < length; raw_index++){
        for(int column_index = 0; column_index < width; column_index++){
            area[raw_index].push_back(new Cell(raw_index, column_index, NULL , std::vector<Animal*> {}));
        }
    }
    
    int raw_index, column_index;
    std::string animal_type;
    std::string animal_sex;
    while(read >> animal_type && read >> raw_index && read >> column_index &&  read >> animal_sex){
        if(animal_type == "T-"){
            animal_sex == "fem" ? area[raw_index][column_index]->add_animal_on_cell(new Tiger(female)) : area[raw_index][column_index]->add_animal_on_cell(new Tiger(male));
        }
        else if(animal_type == "R-"){
            animal_sex == "fem" ? area[raw_index][column_index]->add_animal_on_cell(new Rabbit(female)) : area[raw_index][column_index]->add_animal_on_cell(new Rabbit(male));
        }
        else if(animal_type == "Z-"){
            animal_sex == "fem" ? area[raw_index][column_index]->add_animal_on_cell(new Zebra(female)) : area[raw_index][column_index]->add_animal_on_cell(new Zebra(male));
        }
        else if(animal_type == "P-"){
            area[raw_index][column_index]->add_plant_on_cell();
        }
        else if(animal_type == "L-"){
            animal_sex == "fem" ? area[raw_index][column_index]->add_animal_on_cell(new Lion(female)) : area[raw_index][column_index]->add_animal_on_cell(new Lion(male));
        }
    }
    Area* res_area = new Area(area, length, width);
    return res_area;
}