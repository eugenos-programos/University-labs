
#include "Region_center.h"
#include "District_center.h"
#include <string>

namespace adm_division
{

	class Capital : protected Region_center, public District_center
	{
	public:
		/**
	 * @brief Capital constructor
	 * @param accepts characteristic values
	 * @return nothing
	*/
		Capital(int territory, std::string name, int population);
		/**
	 * @brief get information method
	 * @param accepts no parametrs
	 * @return information about object
	*/
		virtual void get_info() override;
	};

}