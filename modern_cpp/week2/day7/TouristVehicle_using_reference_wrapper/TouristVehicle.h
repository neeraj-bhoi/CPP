#ifndef TouristVehicle_H
#define TouristVehicle_H
#include"Permit.h"
#include"VehicleType.h"
#include<memory>
#include <ostream>


class TouristVehicle
{
private:
    std::string _number;
    VehicleType _type;
    int _seat_count;
    float _per_hour_booking_charge;
    std::reference_wrapper<Permit> _permit;
    
public:
    TouristVehicle() = default;
    TouristVehicle(const TouristVehicle&) = default;
    TouristVehicle& operator=(const TouristVehicle&) = default;
    TouristVehicle(TouristVehicle&&) = default;
    TouristVehicle& operator=(TouristVehicle&&) = default;
    ~TouristVehicle() = default;

    TouristVehicle(std::string number, VehicleType type, int seat_count, float per_hour_booking_charge, std::reference_wrapper<Permit> permit);

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

#endif // TouristVehicle_H
