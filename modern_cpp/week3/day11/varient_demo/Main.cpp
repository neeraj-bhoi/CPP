#include"Functionalities.h"

int main() {
    Container data {
        std::make_shared<ElectricCar>("tesla", 50, 150, 3000000, 40, 2.5, 250, 350, 350),
        std::make_shared<DieselCar>("tata", 60, 200, 600000, 30, 20, 350),
        std::make_shared<ElectricCar>("MG Hector", 40, 180, 2500000, 50, 3.5, 300, 400, 400),
        std::make_shared<DieselCar>("Hyundai", 70, 250, 1200000, 35, 18, 400)
    };

    std::cout<<"\n\ndetails of all cars\n";
    ShowDetails(data);

    std::cout<<"\n\nnames of all cars\n";
    GetName(data);

    std::cout<<"\n\nnames of all cars above price 700000\n";
    PrintNamesOfPriceAbove700000(data);
}