#include <iostream>
#include "Functionalities.h"
#include "IdNotFoundException.h"
#include "EmptyContainerException.h"

int main() {
    Container data;

    CreateObjects(data);
    try {
        int ans = TotalHorsepower(data);
        std::cout<< "Total horsepower is :" <<ans<<"\n";
        float result = AverageEngineTorque(data);
        std::cout<<"Average value is : "<<result<<"\n";
        std::string model = FindCarModelById(data, "c101");
        std::cout<<"Model for given id found "<< model <<"\n";
        bool flag = IsContainerAllCarAbove700000(data);
        if(flag) {
            std::cout<<"All vehicles have price above 7 lakh.\n";
        } else {
            std::cout<<"Some vehicles have price below 7 lakh.\n";
        }
        Engine* e = EnginePointerToMinPriceCar(data);
        std::cout<<"Engine found : "<<*e<<"\n";

        DeleteObjects(data);
    } catch(const EmptyContainerException& ex) {
        std::cout<<ex.what()<<"\n";
    } catch(const IdNotFoundException& ex) {
        std::cout<<ex.what()<<"\n";
    }
}