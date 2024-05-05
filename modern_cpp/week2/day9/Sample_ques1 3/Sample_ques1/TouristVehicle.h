#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H
#include <iostream>
#include "TouristVehilceType.h"
#include <functional>
#include "Permit.h"

class TouristVehicle
{
private:
    std::string _number;
    TouristVehicleType _type;
    int _seat_count;
    float _per_hour_booking_charge;
    std::reference_wrapper<Permit> _permit;
    /* data */
public:
    TouristVehicle(/* args */) = default;
    TouristVehicle(const TouristVehicle &) = delete;
    TouristVehicle(TouristVehicle &&) = delete;
    TouristVehicle &operator=(const TouristVehicle &) = delete;
    TouristVehicle &operator=(TouristVehicle &&) = delete;
    ~TouristVehicle() = default;

    TouristVehicle(std::string number, TouristVehicleType type, int seat_count, float per_hour_booking, std::reference_wrapper<Permit> pr);

    std::string number() const { return _number; }

    TouristVehicleType type() const { return _type; }

    int seatCount() const { return _seat_count; }

    float perHourBookingCharge() const { return _per_hour_booking_charge; }

    std::reference_wrapper<Permit> permit() const { return _permit; }
    void setPermit(const std::reference_wrapper<Permit> &permit) { _permit = permit; }

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

#endif // TOURISTVEHICLE_H
