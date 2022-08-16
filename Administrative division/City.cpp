#include "City.h"
#include <iostream>

using namespace adm_division;

City::City(int territory, std::string name, int population)
{
    this->territory = territory;
    this->name = name;
    this->population = population;
    this->density = this->population / this->territory;
}

void City::annex_another_village(Village *village)
{
    this->territory += village->get_territory();
    this->population += village->get_population();
    this->density = this->population / this->territory;
    std::cout << "Village " << village->get_name() << " was annexed by " << this->name << std::endl;
    delete village;
}

void City::get_info()
{
    std::cout << "City name - " << this->name << ",territory - " << this->territory << " km^2,population - " << this->population << " people,density - " << this->density << "p/km^2\n";
}
