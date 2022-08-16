#include "City.h"
#include "Village.h"

namespace adm_division
{

	class Small_town : private City, public Village
	{
	public:
		/**
	 * @brief Small town constructor
	 * @param accepts characteristic values
	 * @return nothing
	*/
		Small_town(int territory, std::string name, int population);
		/**
	 * @brief get information method
	 * @param accepts no parametrs
	 * @return information about characteristic values
	*/
		virtual void get_info() override;
	};

}
