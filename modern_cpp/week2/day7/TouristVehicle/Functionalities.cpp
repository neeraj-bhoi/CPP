#include "Functionalities.h"

void CreateObject(Container &data)
{
    data.push_back(
        std::make_shared<TouristVehicle>(
            "5678",
            VehicleType::BUS,
            35,
            5000,
            std::make_shared<Permit>(
                "202",
                PermitType::LEASE,
                5
            )
        )
    );

    data.push_back(
        std::make_shared<TouristVehicle>(
            "9101",
            VehicleType::CAR,
            5,
            2000,
            std::make_shared<Permit>(
                "303",
                PermitType::OWNED,
                5
            )
        )
    );

    data.push_back(
        std::make_shared<TouristVehicle>(
            "1234",
            VehicleType::BIKE,
            2,
            500,
            std::make_shared<Permit>(
                "101",
                PermitType::OWNED,
                5
            )
        )
    );
}