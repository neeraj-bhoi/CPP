#include "Functionalities.h"

int main()
{
    TouristContainer Tdata;
    PermitContainer Pdata;
    CreateObject(Pdata, Tdata);
    std::cout << "first n instance of touristVehicle with conditions: " << *Find_n_instances(Tdata, 4) << std::endl;
    std::cout << "average per hour booking charge: " << Avg_BookingCharge(Tdata, 1) << std::endl;
    std::cout << "tourist Veichle which has maximum per hour booking charge: " << Max_PerHour_BookingCharge(Tdata) << std::endl;
    print_n_instanecs(Tdata, 3);
    DeleteObject(Tdata, Pdata);
}