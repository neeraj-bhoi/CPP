#include "TouristVehicle.h"

TouristVehicle::TouristVehicle(std::string number, VehicleType type, int seat_count, float per_hour_booking_charge, std::reference_wrapper<Permit> permit)
    :_number{number}, _type{type}, _seat_count{seat_count}, _per_hour_booking_charge{per_hour_booking_charge}, _permit{permit}
{
}

std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    os << "_number: " << rhs._number
       << " _seat_count: " << rhs._seat_count
       << " _per_hour_booking_charge: " << rhs._per_hour_booking_charge
       << " _permit: " << rhs._permit;
    return os;
}

