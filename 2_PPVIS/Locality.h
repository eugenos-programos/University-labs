#ifndef LOCALITY_H_INCLUDED
#define LOCALITY_H_INCLUDED

#include <string>

/*!
	\brief Namespace,which realize adminstration division
	\author Znenya Samchuk
	\version 1.0
*/
namespace adm_division
{

	class Locality
	{
	protected:
		int territory;

		int population;

		int density;

		std::string name;

		/**
	 * @brief virtual destructor
	 * @param accepts no parametrs
	 * @return no return
	 */
		virtual ~Locality();

	public:
		/**
	 * @brief get info method
	 * @param accepts no parametrs
	 * @return object characteristics values
	*/
		virtual void get_info() = 0;
		/**
	 * @brief set the territory characteristic
	 * @param accepts new territory value
	 * @return nothing
	*/
		void set_territory(int territory);
		/**
	 * @brief set the population characterstic
	 * @param accepts new population value
	 * @return nothing
	*/
		void set_population(int population);
		/**
	 * @brief set the name characteristic
	 * @param accepts new name value
	 * @return nothing
	*/
		void set_name(std::string name);
		/**
	 * @brief get the territory characteristic
	 * @param accepts no parametrs
	 * @return territory value
	*/
		int get_territory() const;
		/**
	 * @brief get the population characteristic
	 * @param accepts no parametrs
	 * @return population value
	*/
		int get_population() const;
		/**
	 * @brief get the density characteristic
	 * @param accepts no parametrs
	 * @return density value
	*/
		int get_density() const;
		/**
	 * @brief get the name characteristic
	 * @param accepts no parametrs
	 * @return name value
	*/
		std::string get_name();
	};

}

#endif
