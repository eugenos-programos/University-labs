#include "City.h"

namespace adm_division
{

	class District_center : virtual public City
	{
	public:
		/**
	 * @brief default empty constructor
	 * @param accepts no param
	 * @return nothing
	*/
		District_center() = default;
		/**
	 * @brief second constructor
	 * @param accepts characteristic values
	 * @return nothing
	*/
		District_center(int territory, std::string name, int population);
		/**
	 * @brief get information method
	 * @param accepts no param
	 * @return information about object characteristic values
	*/
		virtual void get_info() override;
	};

}
