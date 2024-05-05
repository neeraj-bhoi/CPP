#include"DieselCar.h"
#include"ElectricCar.h"
#include<variant>
#include<vector>
#include<memory>

using ElectricCarPointer = std::shared_ptr<ElectricCar>;
using DieselCarPointer = std::shared_ptr<DieselCar>;
using VarientType = std::variant<ElectricCarPointer, DieselCarPointer>;
using Container = std::vector<VarientType>;

void ShowDetails(Container& data) {                                    //uncommon function
    for(VarientType v : data) {
        if(std::holds_alternative<ElectricCarPointer> (v)) {
            ElectricCarPointer eptr = std::get<0> (v);
            eptr -> ShowElectriCarDetails();
        } else if(std::holds_alternative<DieselCarPointer> (v)) {
            DieselCarPointer dptr = std::get<1> (v);
            dptr -> ShowDieselCarDetails();
        }
    }
}

void GetName(Container& data) {                                         //common function
    for(VarientType v : data) {
        std::visit(
            [](auto&& val) { std::cout<<*val<<"\n"; },
            v
        );
    }
}

void PrintNamesOfPriceAbove700000(Container& data) {                    //uncommon function
    for(VarientType v : data) {
        if(std::holds_alternative<ElectricCarPointer> (v)) {
            ElectricCarPointer eptr = std::get<0> (v);
            if(eptr -> exShowroomPrice() > 700000) {
                std::cout<< eptr -> name() <<"\n";
            }
        } else if(std::holds_alternative<DieselCarPointer> (v)) {
            DieselCarPointer dptr = std::get<1> (v);
            if(dptr -> exShowroomPrice() > 700000) {
                std::cout<< dptr -> name() <<"\n";
            }
        }
    }
}