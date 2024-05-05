#include "TouristVehicle.h"
std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs)
{
    os << "_number: " << rhs._number
       << " _seat_count: " << rhs._seat_count
       << " _per_hour_booking_charge: " << rhs._per_hour_booking_charge
       << " _permit: " << rhs._permit.get();
    os << "Tourist vehicle type: \n";
    switch (rhs._type)
    {
    case TouristVehicleType::BIKE:
        os << "BIKE \n";
        break;

    case TouristVehicleType::BUS:
        os << "BUS \n";
        break;

    case TouristVehicleType::CAR:
        os << "CAR\n";
        break;

    default:
        break;
    }
    return os;
}

TouristVehicle::TouristVehicle(std::string number, TouristVehicleType type, int seat_count, float per_hour_booking, std::reference_wrapper<Permit> pr)
    : _number{number}, _type{type}, _seat_count{seat_count}, _per_hour_booking_charge{per_hour_booking}, _permit{pr}
{
}