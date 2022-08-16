#include "Village.h"
#include <iostream>

using namespace adm_division;

Village::Village(int territory, std::string name, int population)
{
    this->name = std::move(name);
    this->territory = territory;
    this->population = population;
    this->density = this->population / this->territory;
}

void Village::get_info()
{
    std::cout << "Village " << this->name << ", has territory - " << this->territory << " km^2,population - " << this->population << " people,density - " << this->density << "p/km^2\n";
}
