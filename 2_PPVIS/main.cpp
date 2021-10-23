#include <iostream>
#include <vector>
#include "Small_town.h"
#include "Capital.h"

int main()
{
    std::vector<adm_division::Locality *> localities{new adm_division::Village(2, "Skolkovo", 100), new adm_division::City(20, "Baranovichi", 10000),
                                                     new adm_division::Small_town(10, "Kletsk", 5000), new adm_division::District_center(25, "Orsha", 9000),
                                                     new adm_division::Region_center(100, "Brest", 100000), new adm_division::Capital(100, "Minsk", 50000)};

    for (adm_division::Locality *locality : localities)
    {
        locality->get_info();
    }
    localities[3]->set_population(10000);
    std::cout << "New population - " << localities[3]->get_population() << std::endl;
    adm_division::City *city = dynamic_cast<adm_division::City *>(localities[1]);
    /**
     * dynamic_cast<Small_town*>(localities[0])->annex_another_village(dynamic_cast<Village*(localities[0]));
     * dynamic_cast<Capital*>(localities[5])->annex_another_city(city);
     * dynamic_cast<Capital*>(localities[5])->annex_another_village(dynamic_cast<Village*>(localities[0]));
     */
}
