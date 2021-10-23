#include "Capital.h"
#include <iostream>

using namespace adm_division;

Capital::Capital(int territory, std::string name, int population)
{
    this->territory = territory;
    this->name = name;
    this->population = population;
    this->density = this->population / this->territory;
}

void Capital::get_info()
{
    std::cout << "Capital " << this->name << " has " << this->territory << " km^2 territory, " << this->population << " population, " << this->density << " p/km^2 density\n";
}
