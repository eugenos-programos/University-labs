
#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include "Locality.h"
#include "Village.h"

namespace adm_division
{

	class City : virtual public Locality
	{
	public:
		/**
	 * @brief method which realize annexing village to city object
	 * @param accepts village object
	 * @return nothing
	*/
		virtual void annex_another_village(Village *village);
		/**
	 * @brief City constructor
	 * @param accepts characteristic values
	 * @return nothing
	*/
		City(int territory, std::string name, int population);
		/**
	 * @brief second City empty constructor
	 * @param accepts no parametrs
	 * @return nothing
	*/
		City() = default;
		/**
	 * @brief get information method
	 * @param accepts no parametrs
	 * @return nothing
	*/
		virtual void get_info() override;
	};

}

#endif