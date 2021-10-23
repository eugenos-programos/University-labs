#include <iostream>
#include <utility>
#include <cstdio>
#include "Locality.h"

using namespace adm_division;

int Locality::get_territory() const
{
    return this->territory;
}

int Locality::get_population() const
{
    return this->population;
}

int Locality::get_density() const
{
    return this->density;
}

std::string Locality::get_name()
{
    return this->name;
}

void Locality::set_territory(int territory)
{
    this->territory = territory;
    this->density = this->population / this->territory;
}

void Locality::set_name(std::string name)
{
    this->name = std::move(name);
}

void Locality::set_population(int population)
{
    this->population = population;
    this->density = this->population / this->territory;
}

Locality::~Locality() noexcept {}
