#include "District_center.h"
#include <iostream>

using namespace adm_division;

void District_center::get_info()
{
    std::cout << "District center " << this->name << " has " << this->population << " people population, " << this->territory << " km^2 territory, " << this->density << " p/km^2 density.\n";
}

District_center::District_center(int territory, std::string name, int population) : City(territory, name, population)
{
}
