#include "Small_town.h"
#include <iostream>

using namespace adm_division;

Small_town::Small_town(int territory, std::string name, int population) : Village(territory, name, population)
{
}

void Small_town::get_info()
{
    std::cout << "Small town name - " << this->name << ", territory - " << this->territory << ", population - " << this->population << ", density - " << this->density << '\n';
}
