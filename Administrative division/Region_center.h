
#include "City.h"

namespace adm_division
{

	class Region_center : virtual public City
	{
	public:
		/**
	 * @brief Region center constructor
	 * @param accepts characteristic values
	 * @return nothing
	*/
		Region_center(int territory, std::string name, int population);
		/**
	 * @brief empty default constructor
	 * @param accepts no param
	 * @return nothing
	*/
		Region_center() = default;
		/**
		 * @brief method which annex another city object
		 * @param accepts city object
		 * @return nothing 
	 */
		void annex_another_city(City *city);
		/**
	 * @brief get information method
	 * @param accepts no param
	 * @return information about characteristic values
	*/
		virtual void get_info() override;
	};

}