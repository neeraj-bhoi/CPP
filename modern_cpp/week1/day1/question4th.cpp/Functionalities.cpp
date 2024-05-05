#include "Functionalities.h"
#include "ElectricCar.h"

void CreateObjects(std::vector<Car *> &data)
{
    data.push_back(
        new ElectricCar("NexonEV", 80, 150, 1870000.90f, 33, 2, 300, 600, 320)
    );

    data.push_back(
        new ElectricCar("XUV400", 70, 140, 1670000.90f, 31, 2, 280, 600, 320)
    );
}

void DeleteObjects(std::vector<Car *> &data)
{
    // for(int i = 0; i < data.size(); i++) {
    //     delete data[i];
    // }

    //modern
    for(Car* p : data) {
        delete p;
    }
}
