#ifndef VILLAGE_H_INCLUDED
#define VILLAGE_H_INCLUDED

#include "Locality.h"
#include <string>

namespace adm_division
{

	class Village : virtual public Locality
	{
	public:
		/**
	 * @brief village constructor
	 * @param accepts characteristics values
	 * @return nothing
	*/
		Village(int territory, std::string name, int population);
		/**
	 * @brief get info method
	 * @param accepts no parametrs
	 * @return nothing
	*/
		virtual void get_info() override;
	};

}

#endif