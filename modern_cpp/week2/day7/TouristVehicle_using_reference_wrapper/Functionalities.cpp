#include "Functionalities.h"

void CreateObject(Container &data)
{
    Permit p(
                "202",
                PermitType::LEASE,
                5
            );
    Permit & p1 = p;

    
    data.push_back(
        std::make_shared<TouristVehicle>(
            "5678", 
            VehicleType::BUS,
            35,
            5000,
            p1
        )
    );

    // data.push_back(
    //     std::make_shared<TouristVehicle>(
    //         "9101",
    //         VehicleType::CAR,
    //         5,
    //         2000,
    //         new Permit(
    //             "303",
    //             PermitType::OWNED,
    //             5
    //         )
    //     )
    // );

    // data.push_back(
    //     std::make_shared<TouristVehicle>(
    //         "1234",
    //         VehicleType::BIKE,
    //         2,
    //         500,
    //         new Permit(
    //             "101",
    //             PermitType::OWNED,
    //             5
    //         )
    //     )
    // );
}