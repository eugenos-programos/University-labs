#include "Region_center.h"
#include <iostream>

using namespace adm_division;

void Region_center::annex_another_city(City *city)
{
    this->population += city->get_population();
    this->territory += city->get_territory();
    this->density = population / territory;
    std::cout << city->get_name() << " city was annexed by " << name << std::endl;
    delete city;
}

void Region_center::get_info()
{
    std::cout << "Region center name - " << this->name << ",territory - " << this->territory << " km^2,population - "
              << this->population << " people,density - " << this->density << "p/km^2\n";
}

Region_center::Region_center(int territory, std::string name, int population) : City(territory, name, population)
{
}
